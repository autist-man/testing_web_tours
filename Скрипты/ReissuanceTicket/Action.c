Action()
{
	/*Скрипт "2. Переоформление авиабилета" согласно МТН*/
	
	//Флаг определяющий будет ли билет в одну сторону или "туда и обратно"
	//имеет два значения 0 и 1 - значения берутся из параметра {random_roundtrip_nember}
	int random_roundtrip;
	
	//Фиксированный массив для хранения номеров удаленных билетов
	//Размерность массива фиксирована, чтобы динамически не выделять память под количество билетов (до 3 шт) для удаления
	#define NUMBER_OF_TICKET 3
	//Певый столбец массива предназначен для хранения удаленного номера билета в массиве параметров {arrayFlightID}
	//Второй столбец служит счетчиком для определения кол-ва совпадающих билетов по первым номерам "arrayFlightID_2" =  "    ->382141149<-   -2208620-LD"
	#define COLUMNS 2
	int deletedTicketsID[NUMBER_OF_TICKET][COLUMNS];
	
	//numberTickets - какое количесвто билетов удалить (по заданию от 1 до 3 билетов за раз)
	int numberTickets;
	
	srand(time(NULL));
	
	//Назначаем города отправления и назначения из файла
	//если города совпадают, смещаем город на другое значение
	if(strcmp(lr_eval_string("{departCity}"),lr_eval_string("{arriveCity}")) == 0){
		lr_advance_param("arriveCity");
	}
	
	lr_start_transaction("UC_02_ReissuanceTicket");
	
	
// Заргузка сайта

	go_to_site_request();
		
// 1. Авторизация

	login_request();

//2. Заполнение полей для поиска

	//Нажатие кнопки "Flights"
	
	click_flight_request();

	//Заполнение полей поиска рейса и нажатие кнопки "Continue"
	
	lr_start_transaction("fill_find_flight");
	
	lr_think_time(5);
			
			//В параметр "departTimeAnyFlight" записываются все время вылета любого рейса\
			//независимо от типа билета, в ответе запроса время написано попорядку, следовательно
			//в случае билета туда-обратно в массив запишется первые 4 времени "туда"
			//следующие 4 времени "обратно"
			web_reg_save_param_regexp(
				"ParamName=departTimeAnyFlight",
				"RegExp=[0-9]+(am|pm)",
				"Group=0",
				"Ordinal=All",
				SEARCH_FILTERS,
				"Scope=BODY",
				"RequestUrl=http://localhost:1080/cgi-bin/reservations.pl",
				LAST);

			//Точно также как время вылета отлавливаем номер рейса и записываем в общий массив
			web_reg_save_param_ex(
					"ParamName=flightNumber",
					"LB=>Blue Sky Air ",
					"RB=<td",
					"NotFound=error",
					"Ordinal=All",
					SEARCH_FILTERS,
					"Scope=BODY",
					"RequestUrl=http://localhost:1080/cgi-bin/reservations.pl",
					LAST);
			
			//Если правда выполняется запрос с покупкой билета "туда и обратно",
			//если ложь выполняется запрос с покупкой билета только в одну сторону,
			//random_roundtrip - имеет два значения 0 и 1.
			random_roundtrip = atoi(lr_eval_string("{random_roundtrip_number}"));

			if(random_roundtrip){
				//Отлавливает ID обратных рейсов "returnFlight"
				web_reg_save_param_ex(
					"ParamName=returnFlight",
					"LB=name=\"returnFlight\" value=\"",
					"RB=\"",
					"NotFound=error",
					"Ordinal=All",
					SEARCH_FILTERS,
					"Scope=BODY",
					"RequestUrl=http://localhost:1080/cgi-bin/reservations.pl",
					LAST);
			}
			//Параметризация выбора рейса - ловим значения "outboundFlight"
			//при любом запросе ниже
			web_reg_save_param_ex(
					"ParamName=outboundFlight",
					"LB=name=\"outboundFlight\" value=\"",
					"RB=\"",
					"NotFound=error",
					"Ordinal=All",
					SEARCH_FILTERS,
					"Scope=BODY",
					"RequestUrl=http://localhost:1080/cgi-bin/reservations.pl",
					LAST);		
			
			//Проверка по названию городов отправления ("departCity") и прибытия ("arriveCity"), и времени отправления ("departDate")
			web_reg_find("Fail=NotFound",
					"Text=Flight departing from <B>{departCity}</B> to <B>{arriveCity}</B> on <B>{departDate}</B>",
					LAST);
			if(random_roundtrip){
				//Проверка по названию городов обратного рейса отправления ("arriveCity") и прибытия ("departCity"), и времени отправления ("returnDate")
				web_reg_find("Fail=NotFound",
						"Text=Flight departing from <B>{arriveCity}</B> to <B>{departCity}</B> on <B>{returnDate}</B>",
						LAST);
				web_submit_data("reservations.pl", 
						"Action=http://localhost:1080/cgi-bin/reservations.pl", 
						"Method=POST", 
						"TargetFrame=", 
						"RecContentType=text/html", 
						"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
						"Snapshot=t61.inf", 
						"Mode=HTML", 
						ITEMDATA, 
						"Name=advanceDiscount", "Value=0", ENDITEM, 
						"Name=depart", "Value={departCity}", ENDITEM, 
						"Name=departDate", "Value={departDate}", ENDITEM, 
						"Name=arrive", "Value={arriveCity}", ENDITEM, 
						"Name=returnDate", "Value={returnDate}", ENDITEM, 
						"Name=numPassengers", "Value={numPassengers}", ENDITEM, 
						"Name=roundtrip", "Value=on", ENDITEM, 
						"Name=seatPref", "Value={seatPref}", ENDITEM, 
						"Name=seatType", "Value={seatType}", ENDITEM, 
						"Name=.cgifields", "Value=roundtrip", ENDITEM, 
						"Name=.cgifields", "Value=seatType", ENDITEM, 
						"Name=.cgifields", "Value=seatPref", ENDITEM, 
						"Name=findFlights.x", "Value=33", ENDITEM, 
						"Name=findFlights.y", "Value=8", ENDITEM, 
						LAST);
				//Параметризация выбора рейса - из запроса ловим значения "returnFlight", после случайным образом выбираем одно из пойманных
				//и кладем в параметры с именем "rundomReturnFlight"
				lr_save_string (lr_paramarr_idx("returnFlight", atoi(lr_eval_string("{return_flight_id}"))), "randomReturnFlight");
			} else {
				web_submit_data("reservations.pl", 
						"Action=http://localhost:1080/cgi-bin/reservations.pl", 
						"Method=POST", 
						"TargetFrame=", 
						"RecContentType=text/html", 
						"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
						"Snapshot=t53.inf", 
						"Mode=HTML", 
						ITEMDATA, 
						"Name=advanceDiscount", "Value=0", ENDITEM, 
						"Name=depart", "Value={departCity}", ENDITEM, 
						"Name=departDate", "Value={departDate}", ENDITEM, 
						"Name=arrive", "Value={arriveCity}", ENDITEM, 
						"Name=returnDate", "Value={returnDate}", ENDITEM, 
						"Name=numPassengers", "Value={numPassengers}", ENDITEM, 
						"Name=seatPref", "Value={seatPref}", ENDITEM, 
						"Name=seatType", "Value={seatType}", ENDITEM, 
						"Name=.cgifields", "Value=roundtrip", ENDITEM, 
						"Name=.cgifields", "Value=seatType", ENDITEM, 
						"Name=.cgifields", "Value=seatPref", ENDITEM, 
						"Name=findFlights.x", "Value=69", ENDITEM, 
						"Name=findFlights.y", "Value=10", ENDITEM, 
						LAST);
			}
			
			//Параметризация выбора рейса - из запроса ловим значения "outboundFlight", после случайным образом выбираем одно из пойманных
			//и кладем в параметры с именем "rundomOutboundFlight"
			lr_save_string (lr_paramarr_idx("outboundFlight", atoi(lr_eval_string("{outbound_flight_id}"))), "randomOutboundFlight");

	lr_end_transaction("fill_find_flight",LR_AUTO);
	
	
	
//3. Выбор рейса в найденых



	lr_start_transaction("choose_flight");
    
	lr_think_time(5);
			
			//Проверка по номеру выбранного случайным образом авиарейса "rundomOutboundFlight"
			web_reg_find("Fail=NotFound",
				"Text=name=\"outboundFlight\" value=\"{randomOutboundFlight}\"  />",
				LAST);
			
			//Выбираем авиарейс в зависимости от типа билета (туда или туда-обратно)
			if(random_roundtrip){
				//Проверка по номеру выбранного случайным образом авиарейса "rundomReturnFlight"
				web_reg_find("Fail=NotFound",
					"Text=name=\"returnFlight\" value=\"{randomReturnFlight}\"  />",
					LAST);
				
				web_submit_form("reservations.pl_2", 
						"Snapshot=t15.inf", 
						ITEMDATA, 
						"Name=outboundFlight", "Value={randomOutboundFlight}", ENDITEM, 
						"Name=returnFlight", "Value={randomReturnFlight}", ENDITEM, 
						"Name=reserveFlights.x", "Value=79", ENDITEM, 
						"Name=reserveFlights.y", "Value=11", ENDITEM, 
						EXTRARES,
						"URL=http://localhost:1080/cgi-bin/reservations.pl", 
						"Referer=http://localhost:1080/cgi-bin/reservations.pl", ENDITEM,
						LAST);
			} else {
				web_submit_form("reservations.pl_2", 
						"Snapshot=t22.inf", 
						ITEMDATA, 
						"Name=outboundFlight", "Value={randomOutboundFlight}", ENDITEM, 
						"Name=reserveFlights.x", "Value=56", ENDITEM, 
						"Name=reserveFlights.y", "Value=16", ENDITEM,
						EXTRARES,
						"URL=http://localhost:1080/cgi-bin/reservations.pl", 
						"Referer=http://localhost:1080/cgi-bin/reservations.pl", ENDITEM,
						LAST);
			}

	lr_end_transaction("choose_flight",LR_AUTO);
	
	
	
//4. Оплата билета

			//Сохраняем в параметр время отправления                                      
			lr_save_string (lr_paramarr_idx("departTimeAnyFlight", atoi(lr_eval_string("{outbound_flight_id}"))), "departFlightTime");
			//Сохраняем в параметр номер рейса
			lr_save_string (lr_paramarr_idx("flightNumber", atoi(lr_eval_string("{outbound_flight_id}"))), "departFlightNumber");
			
			//Генерация тела запроса на покупку билетов посредсвом записи тела в файл
			//независимо от типа билета (туда или "туда-обратно")
			//и количества пассажиров, имена пассажирвов беруться рандомно из страндартных параметров
			//за 25 итерации транзакия "pay" = 00:00.040 c
			//lr_start_transaction("pay");
			{

				//numPassengers - количество пассажиров
				int numPassengers = atoi(lr_eval_string("{numPassengers}"));
				//count - счетчик для цикла
				int count;
				FILE * buyRequestFile;

				if((buyRequestFile = fopen("buyRequestFile.txt", "w")) == NULL){
			       lr_output_message("Error: %s", "Не удалось открыть файл для записи запроса на удаление билетов");
			       return 0;
			    }
				//Формируем тело запроса из известных параметров
				fprintf(buyRequestFile,
				        "firstName=%s&"                          //1
				        "lastName=%s&"                           //2
				        "address1=%s&"                           //3
				        "address2=%s&"                           //4
				        "creditCard=%s&"                         //5
				        "numPassengers=%s&"                      //6
				        "seetType=%s&"                           //7
				        "seatPref=%s&"                           //8
				        "JSFormSubmit=off&" 
				        "buyFlights.x=28&" 
				        "buyFlights.y=0&" 
				        ".cgifields=saveCC&"
				        "oldCCOption=&"
				        "advanceDiscount=0&"
				        "pass1=%s+%s&",                          //9-10         
				        lr_eval_string("{firstName}"),           //1
				       	lr_eval_string("{lastName}"),            //2
				     	lr_eval_string("{homeAddress}"),         //3
				     	lr_eval_string("{homeCity}"),            //4
				    	lr_eval_string("{creditCard}"),          //5
				   		lr_eval_string("{numPassengers}"),       //6
				  		lr_eval_string("{seatType}"),            //7
				  		lr_eval_string("{seatPref}"),            //8
				  		lr_eval_string("{firstName}"),           //9
				  		lr_eval_string("{lastName}"));           //10
				//добавляем имена оставшихся пассажиров
				for(count = 2; count <= numPassengers; count++){
					fprintf(buyRequestFile,
					        "pass%d=%s+%s&",
					        count,
					        lr_eval_string("{firstNameAnotherPassenger}"),
					        lr_eval_string("{lastNameAnotherPassenger}"));
				}
				
				
				//Соединяем значения параметров в один параметр, чтобы разбить из на группы чисел
				//в теле запроса значения передаются следующей строкой
				//   expDate=04%2F25&outboundFlight=923%3B221%3B09%2F17%2F2020
				//символ ; заменяется символами %3B
				//символ / заменяется символами %2F
				lr_param_sprintf("concatExpDateOutboundFlight", "%s:%s",
				                lr_eval_string("{randomOutboundFlight}"),
				                lr_eval_string("{expDate}"));
					
				lr_save_param_regexp(lr_eval_string("{concatExpDateOutboundFlight}"),
					            strlen(lr_eval_string("{concatExpDateOutboundFlight}")),
					            "RegExp=([0-9]+)",
					            "Ordinal=All",
					            "ResultParam=concatStringExpDateOutboundFlight",
					            LAST);
				
				//outboundFlight=923  %3B  221  %3B  09  %2F  17  %2F  2020 & expDate=04  %2F  25
				fprintf(buyRequestFile,
				     "outboundFlight=%s%%3B%s%%3B%s%%2F%s%%2F%s&"
				     "expDate=%s%%2F%s",
				     lr_eval_string("{concatStringExpDateOutboundFlight_1}"),
				     lr_eval_string("{concatStringExpDateOutboundFlight_2}"),
					 lr_eval_string("{concatStringExpDateOutboundFlight_3}"),
					 lr_eval_string("{concatStringExpDateOutboundFlight_4}"),
					 lr_eval_string("{concatStringExpDateOutboundFlight_5}"),
					 lr_eval_string("{concatStringExpDateOutboundFlight_6}"),
					 lr_eval_string("{concatStringExpDateOutboundFlight_7}"));
				
				//Если билет "туда-обратно" добавляется ID обратного рейса "randomReturnFlight"
				if(random_roundtrip){
					 lr_save_param_regexp(lr_eval_string("{randomReturnFlight}"),
				              strlen(lr_eval_string("{randomReturnFlight}")),
				              "RegExp=([0-9]+)",
				              "Ordinal=All",
				              "ResultParam=stringRandomReturnFlight",
				              LAST);
					
				//&returnFlight=923  %3B  221  %3B  09  %2F  17  %2F  2020
				fprintf(buyRequestFile,
				     "&returnFlight=%s%%3B%s%%3B%s%%2F%s%%2F%s",
				     lr_eval_string("{stringRandomReturnFlight_1}"),
				     lr_eval_string("{stringRandomReturnFlight_2}"),
					 lr_eval_string("{stringRandomReturnFlight_3}"),
					 lr_eval_string("{stringRandomReturnFlight_4}"),
					 lr_eval_string("{stringRandomReturnFlight_5}"));
				}
				
				fclose(buyRequestFile);
				//Читаем из файла тело запроса сгенерированное случайным образом
				//записываем тело в параметр "bodyPOSTRequest"
				{
					int res = lr_read_file("buyRequestFile.txt", "bodyPOSTRequest", 0);
					if(res == -1){
						lr_output_message("Error: Не удалось считать тело запроса из файла");
						return 0;
					}
				}
			
			}
			//lr_end_transaction("pay", LR_AUTO);
	
/*			//Генерация тела запроса на покупку билетов независимо от типа билета (туда или "туда-обратно")
			//и количества пассажиров, имена пассажирвов беруться рандомно из страндартных параметров
			//За 25 итераций транзакия "pay_args" = 00:00.095 c
			lr_start_transaction("pay_args");
			{
				//numPassengers - количество пассажиров
				int numPassengers = atoi(lr_eval_string("{numPassengers}"));
				//count - счетчик для цикла
				int count;

				form_args_add("Snapshot=t47.inf");
				form_args_add(ITEMDATA);
				form_args_add("Name=firstName"); form_args_add("Value={firstName}"); form_args_add(ENDITEM);
				form_args_add("Name=lastName"); form_args_add("Value={lastName}"); form_args_add(ENDITEM);
				form_args_add("Name=address1"); form_args_add("Value={homeAddress}"); form_args_add(ENDITEM);
				form_args_add("Name=address2"); form_args_add("Value={homeCity}"); form_args_add(ENDITEM);
				form_args_add("Name=pass1"); form_args_add("Value={firstName} {lastName}"); form_args_add(ENDITEM);
				
				//добавляем имена других пассажиров, если они есть
				for(count = 2; count <= numPassengers; count++){
					form_args_add_paramarr("Name=pass", count);
					form_args_add("Value={firstNameAnotherPassenger} {lastNameAnotherPassenger}");
					form_args_add(ENDITEM);
				}
				
				form_args_add("Name=creditCard"); form_args_add("Value={creditCard}"); form_args_add(ENDITEM);
				form_args_add("Name=expDate"); form_args_add("Value={expDate}"); form_args_add(ENDITEM);	
				form_args_add("Name=saveCC"); form_args_add("Value=<OFF>"); form_args_add(ENDITEM);
				form_args_add("Name=buyFlights.x"); form_args_add("Value=27"); form_args_add(ENDITEM);
				form_args_add("Name=buyFlights.y"); form_args_add("Value=8"); form_args_add(ENDITEM);
				form_args_add(EXTRARES); 
				form_args_add("URL=http://localhost:1080/cgi-bin/reservations.pl");
				form_args_add("Referer=http://localhost:1080/cgi-bin/reservations.pl");form_args_add(ENDITEM);
				form_args_add(LAST);				
			}
			lr_end_transaction("pay_args",LR_AUTO);
			//Запрос на покупку билета через генерацию 	web_submit_form_custom	
			web_submit_form("itinerare.pl", FORM_ARGS);
			//Освобаждаем память "FORM_ARGS"
			form_args_reset();
*/

	lr_start_transaction("insert_payment_info");
	
	lr_think_time(5);
		
			web_add_auto_header("Sec-Fetch-Dest", 
				"empty");
		
			web_add_auto_header("Sec-Fetch-Site", 
				"none");
		
			web_add_auto_header("Sec-Fetch-Mode", 
				"navigate");
		
			web_add_auto_header("Sec-Fetch-Dest", 
				"frame");
		
			web_add_header("Origin", 
				"http://localhost:1080");
		
			web_add_auto_header("Sec-Fetch-Site", 
				"same-origin");
		
			web_add_header("Sec-Fetch-User", 
				"?1");
		
			web_add_header("Upgrade-Insecure-Requests", 
				"1");	
			
			//Проверка купленного билета на время и дату отправления, город отправления и прибытия, и номер авиарейса
				web_reg_find("Fail=NotFound",
					"Text={departDate} :  {departFlightTime} : Flight {departFlightNumber} leaves {departCity}  for {arriveCity}",
					LAST);
				
				//Проверка купленного билета на время и дату отправления, город отправления и прибытия, и номер авиарейса
				//при типе билета "туда-обратно"
				if(random_roundtrip){
					//Длина массива параметрова времени отправления
					int lenght_departTimeAnyFlight = atoi(lr_eval_string("{departTimeAnyFlight_count}"));
					//Время обратноего отправления рейса
					lr_save_string (lr_paramarr_idx("departTimeAnyFlight", lenght_departTimeAnyFlight/2 + atoi(lr_eval_string("{return_flight_id}"))), "arriveFlightTime");
					//Номер обратного рейса
					lr_save_string (lr_paramarr_idx("flightNumber", lenght_departTimeAnyFlight/2 + atoi(lr_eval_string("{return_flight_id}"))), "arriveFlightNumber");
					
					web_reg_find("Fail=NotFound",
							"Text={returnDate} :  {arriveFlightTime} : Flight {arriveFlightNumber} leaves {arriveCity}  for {departCity}",
							LAST);
				}
				
			//Запрос на покупку через генерацию тела запроса посредствои записью в файл
			//с последующим считыванием из него и записью в параметр {bodyPOSTRequest}
			web_custom_request("itinerare.pl",
	            "Method=POST", 
				"TargetFrame=",
				"URL=http://localhost:1080/cgi-bin/reservations.pl",
				"Referer=http://localhost:1080/cgi-bin/reservations.pl",
				"Body={bodyPOSTRequest}",
				LAST);
			
	lr_end_transaction("insert_payment_info",LR_AUTO);


//5. Просмотр квитанций
	
	lr_start_transaction("viewing_receipts");
	
	lr_think_time(5);
	
	//Отлавливаем количество имеющихся билетов у пользователя
	//Итересующие поля:
	//			"Name=flightID", "Value=368096418-793-SC" (1)
	//			"Name=.cgifields", "Value=6"              (2)

	//Регистрируем поля (1)
			web_reg_save_param_ex(
				"ParamName=arrayFlightID",
				"LB=name=\"flightID\" value=\"",
				"RB=\"  />",
				"NotFound=error",
				"Ordinal=All",
				SEARCH_FILTERS,
				"Scope=BODY",
				"RequestUrl=http://localhost:1080/cgi-bin/itinerary.pl",
				LAST);
	//Регистрируем поля (2)
			web_reg_save_param_ex(
				"ParamName=array_cgifields",
				"LB=name=\".cgifields\" value=\"",
				"RB=\"  />",
				"NotFound=error",
				"Ordinal=All",
				SEARCH_FILTERS,
				"Scope=BODY",
				"RequestUrl=http://localhost:1080/cgi-bin/itinerary.pl",
				LAST);
	
			web_add_auto_header("Sec-Fetch-Site", 
				"none");
		
			web_add_auto_header("Sec-Fetch-Mode", 
				"cors");
		
			web_add_auto_header("Sec-Fetch-Dest", 
				"empty");
		
			web_add_header("Origin", 
				"null");
		
			web_add_auto_header("Sec-Fetch-Mode", 
				"no-cors");
		
			web_add_auto_header("Sec-Fetch-Mode", 
				"navigate");
		
			web_add_auto_header("Sec-Fetch-Dest", 
				"frame");
		
			web_add_auto_header("Sec-Fetch-Site", 
				"same-origin");
		
			web_add_auto_header("Sec-Fetch-User", 
				"?1");
		
			web_add_auto_header("Upgrade-Insecure-Requests", 
				"1");
			
			web_reg_find("Fail=NotFound",
				"Text=<B>{firstName} {lastName}\n 's Flight Transaction Summary</B>",
				LAST);
		
			web_url("welcome.pl", 
				"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
				"TargetFrame=", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
				"Snapshot=t15.inf", 
				"Mode=HTML", 
				LAST);
	
	lr_end_transaction("viewing_receipts", LR_AUTO);
	
			//Генерация тела запроса на удаление билетов посредством записи тела запроса в файл
			// с последующим считываниеи из него
			//работает быстрее, чем через запись посредством контакенации
			//за 25 итерации транзакия "file" = 00:00.975 (условия: у всех пользователей в среднем куплено 20-30 билетов)
			//lr_start_transaction("file");
			{	
				//FlightID - поле купленного билета "arrayFlightID_2" =  "382141149-2208620-LD"
				//partFlightID - первые цифры в "arrayFlightID_2" =  " ->382141149<-   -2208620-LD"
				char * FlightID, * partFlightID;
				//lenghtArrayFlightID - количество билетов у пользователья
				int lenghtArrayFlightID = atoi(lr_eval_string("{arrayFlightID_count}"));
				//count - счетчик для цикла
				//ord - счетчик для массива в котором хранятся номера удаленных билетов в массиве параметров {arrayFlightID}
				//result - хранит результат стравнения билетов, которые совпадают по первым цифрам номера
				int count, ord, result; 
				FILE * deleteRequestFile;
				
				numberTickets = atoi(lr_eval_string("{numberTickets}"));
				
				//Инициализируем массив номерами билетов
				//Алгоритм Кнута для генерации уникальных случайных чисел в массиве
				//от ord = 0 до lenghtArrayFlightID - перебераем номер чекбокса по списку в ответе запроса
				//<label><input type="checkbox" name="  ->1<-  " value="on" /></label></font></b>
				//<input type="hidden" name="flightID" value="36810199-120782-SC"  />
				//от count=0 до numberTickets -сколько чисел еще нужно найти
				//гарантируется, что если numberTickets <= lenghtArrayFlightID числа в массиве будут уникальными
				for(count = 0, ord = 0; count < numberTickets && ord < lenghtArrayFlightID; ord++){
					int rn = lenghtArrayFlightID - ord;
					int rm = numberTickets - count;
					if(rand()%rn < rm){
						deletedTicketsID[count][0] = ord + 1; //+1 чтобы номер чекбокса начинался с 1
						//количество совпадающих билетов по первым цифрам
						//в последствии стравниваются билеты с удаленными билетами
						//на совпадение этих цифр, если совпадает увеличиваем счетчик
						deletedTicketsID[count++][1] = 1;
					}
				}
				
								
				if((deleteRequestFile = fopen("deleteRequestFile.txt", "w")) == NULL){
			       lr_output_message("Error: %s", "Не удалось открыть файл для записи запроса на удаление билетов");
			       return 0;
			    }
				
				for(count = 1; count <= lenghtArrayFlightID; count++)
				{
					FlightID = lr_paramarr_idx("arrayFlightID", count);
					//сравнение удаляющихся билетов с другими билетами по первым цифрам номера билета
					for(ord = 0; ord < numberTickets; ord++){
						//вытягиваем первые цифры билета удаления
						partFlightID = strtok(lr_eval_string(lr_paramarr_idx("arrayFlightID",deletedTicketsID[ord][0])), "-");
						//сравниваем с другим билетом
						result = strncmp(lr_eval_string(lr_paramarr_idx("arrayFlightID",count)),
						                partFlightID,
						                strlen(partFlightID));
						//если совпадают и номер билета не равен самому себе
						//увеличиваем счетчик
						if(result==0 & deletedTicketsID[ord][0] != count){
							deletedTicketsID[ord][1]+=1;
						}
					}
					//записываем тело запроса в файл
					//порядок билетов в теле запроса не важен
					//значения разделяются амперсандом
					if(count <= numberTickets){
        				fprintf(deleteRequestFile,
						       "%d=on&flightID=%s&.cgifields=%s&",
						      	deletedTicketsID[count-1][0], FlightID, FlightID);
					} else{
        				fprintf(deleteRequestFile,
						       "flightID=%s&.cgifields=%s&",
						      	FlightID, FlightID);
					}
				}   
				fprintf(deleteRequestFile, "removeFlights.x=48&removeFlights.y=6");
				
				fclose(deleteRequestFile);
				//Читаем из файла тело запроса сгенерированное случайным образом
				//записываем тело в параметр "bodyPOSTRequest"
				{
					int res = lr_read_file("deleteRequestFile.txt", "bodyPOSTRequest", 0);
					if(res == -1){
						lr_output_message("Error: Не удалось считать тело запроса из файла");
						return 0;
					}
				}
			}
			//lr_end_transaction("file", LR_AUTO);
			
/*		//Генерация запроса на удаление билетов через web_submit_form_custom
		//за 25 итерации транзакия "array" = 00:00.920 (условия: у всех пользователей в среднем куплено 20-30 билетов)
		//lr_start_transaction("array");
	{
				//FlightID - поле купленного билета "arrayFlightID_2" =  "382141149-2208620-LD"
				//partFlightID - первые цифры в "arrayFlightID_2" =  " ->382141149<-   -2208620-LD"				
				char * FlightID, * partFlightID;
				//lenghtArrayFlightID - количество билетов у пользователья
				int lenghtArrayFlightID = atoi(lr_eval_string("{arrayFlightID_count}"));
				//count - счетчик для цикла
				//ord - счетчик для массива в котором хранятся номера удаленных билетов в массиве параметров {arrayFlightID}
				//result - хранит результат стравнения билетов, которые совпадают по первым цифрам номера
				int count, ord, result; 
				
				numberTickets = atoi(lr_eval_string("{numberTickets}"));
				
				//Инициализируем массив номерами билетов
				//Алгоритм Кнута для генерации уникальных случайных чисел в массиве
				//от ord = 0 до lenghtArrayFlightID - перебераем номер чекбокса по списку в ответе запроса
				//<label><input type="checkbox" name="  ->1<-  " value="on" /></label></font></b>
				//<input type="hidden" name="flightID" value="36810199-120782-SC"  />
				//от count=0 до numberTickets -сколько чисел еще нужно найти
				//гарантируется, что если numberTickets <= lenghtArrayFlightID числа в массиве будут уникальными
				for(count = 0, ord = 0; count < numberTickets && ord < lenghtArrayFlightID; ord++){
					int rn = lenghtArrayFlightID - ord;
					int rm = numberTickets - count;
					if(rand()%rn < rm){
						deletedTicketsID[count][0] = ord + 1; //+1 чтобы номер чекбокса начинался с 1
						//количество совпадающих билетов по первым цифрам
						//в последствии стравниваются билеты с удаленными билетами
						//на совпадение этих цифр, если совпадает увеличиваем счетчик
						deletedTicketsID[count++][1] = 1;
					}
				}
				     form_args_add("Snapshot=t57.inf");
        			 form_args_add(ITEMDATA);
					
				for(count = 1; count <= lenghtArrayFlightID; count++)
				{
					FlightID = lr_paramarr_idx("arrayFlightID", count);
					//сравнение удаляющихся билетов с другими билетами по первым цифрам номера билета
					for(ord = 0; ord < numberTickets; ord++){
						//вытягиваем первые цифры билета удаления
						partFlightID = strtok(lr_eval_string(lr_paramarr_idx("arrayFlightID",deletedTicketsID[ord][0])), "-");
						//сравниваем с другим билетом
						result = strncmp(lr_eval_string(lr_paramarr_idx("arrayFlightID",count)),
						                partFlightID,
						                strlen(partFlightID));
						//если совпадают и номер билета не равен самому себе
						//увеличиваем счетчик
						if(result==0 & deletedTicketsID[ord][0] != count){
							deletedTicketsID[ord][1]+=1;
						}
					}
					if(count <= numberTickets){
		                form_args_add_paramarr("Name=", deletedTicketsID[count-1][0]);
		                form_args_add("Value=on");
		                form_args_add(ENDITEM);
					}
				}

				form_args_add("Name=removeFlights.x"); form_args_add("Value=47"); form_args_add(ENDITEM);
				form_args_add("Name=removeFlights.y"); form_args_add("Value=7"); form_args_add(ENDITEM);
				form_args_add(EXTRARES);
				form_args_add("URL=http://localhost:1080/cgi-bin/reservations.pl");
				form_args_add("Referer=http://localhost:1080/cgi-bin/reservations.pl");
			    form_args_add(ENDITEM);
				form_args_add(LAST);
				
	}
				//lr_end_transaction("array", LR_AUTO);
	
	//Запрос
	web_submit_form("itinerary.pl", FORM_ARGS);
	//Освобождаем память
	form_args_reset();
*/	
	
//6. Отмена бронирования
	
	
	
	lr_start_transaction("сancel_reservation");
	
	lr_think_time(5);

			web_add_header("Origin", 
				"http://localhost:1080");
	
			//вылавливаем первые цифры номера билета
			//для сравнения с удаленными билетами
			web_reg_save_param_ex(
				"ParamName=ticketsPartID",
				"LB=name=\"flightID\" value=\"",
				"RB=-",
				"NotFound=error",
				"Ordinal=All",
				SEARCH_FILTERS,
				"Scope=BODY",
				"RequestUrl=http://localhost:1080/cgi-bin/itinerary.pl",
				LAST);
			
			web_reg_find("Fail=NotFound",
				"Text=<B>{firstName} {lastName}\n 's Flight Transaction Summary</B>",
				LAST);
	
			web_custom_request("itinerare.pl",
	            "Method=POST", 
				"TargetFrame=",
				"Snapshot=t23.inf",
				"URL=http://localhost:1080/cgi-bin/itinerary.pl",
				"Referer=http://localhost:1080/cgi-bin/itinerary.pl",
				"Body={bodyPOSTRequest}",
				LAST);

	
			//Проверка удаления билетов
			{
				int lenghtTicketsPartID = atoi(lr_eval_string("{ticketsPartID_count}"));
				//identicalTicketsNum - хранит количество совпавших билетов по первым цифрам номера
				int count, ord, result, identicalTicketsNum;
				//Итерация по каждому удаленному билету
				for(ord = 0; ord < numberTickets; ord++){
					identicalTicketsNum = 0;
					//итерация по каждому билету после удаления
					for(count = 1; count <= lenghtTicketsPartID; count++){
						//проверяем совпадают ли первые цифры удаленного билета с билетами после удаления
						result = strncmp(lr_eval_string(lr_paramarr_idx("arrayFlightID",deletedTicketsID[ord][0])),
						                 lr_eval_string(lr_paramarr_idx("ticketsPartID",count)),
						                 strlen(lr_eval_string(lr_paramarr_idx("ticketsPartID",count))));
						//если совпадение есть
						//увеличиваем счетчик на 1
						//если счетчик будет больше чем изначально для удаленного билета deletedTicketsID[ord][1]
						//выдаем ошибку
						// !!! не учитывает если при проведении теста после удаления, другой скрипт купил билет идентичный
						// !!! удаленному билету в этом скрипте
						if(result==0){
							identicalTicketsNum +=1;
							if(identicalTicketsNum >= deletedTicketsID[ord][1])
								lr_end_transaction("сancel_reservation", LR_FAIL);
						}
					}
				}
			}

	lr_end_transaction("сancel_reservation", LR_AUTO);	
	
	
	
//7. Выход из системы

	click_sing_off_request();
	
	lr_end_transaction("UC_02_ReissuanceTicket", LR_AUTO);


	return 0;
}
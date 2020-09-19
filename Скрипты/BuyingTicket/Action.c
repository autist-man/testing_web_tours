Action()
{
	/*Скрипт "1. Покупка авиабилета" согласно МТН*/

	//Флаг определяющий будет ли билет в одну сторону или "туда и обратно"
	//имеет два значения 0 и 1 - значения берутся из параметра {random_roundtrip_nember}
	int random_roundtrip;
	
	//Назначаем города отправления и назначения из файла
	//если города совпадают, смещаем город на другое значение
	if(strcmp(lr_eval_string("{departCity}"),lr_eval_string("{arriveCity}")) == 0){
		lr_advance_param("arriveCity");
	}
	
	lr_start_transaction("UC_01_BuyingTicket");

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
			
/*Почему-то данное решение не всегда отправляет запросы основная ошибка "Requested form not found", не разобрался в причине!
//			Используется форма, параметр {random_roundtrip} должен иметь два значени "on" или <OFF>
//			при создании параметра random_roundtrip, создать совмествно параметр random_roundtrip = 0(<OFF>) или 1(on) для конструкций if()
//          Решение помогает избегажать if в этом запросе заполенения полей для поиска, так как для любых параметров запрос использует одну форму,
			web_submit_form("reservations.pl", 
					"Snapshot=t21.inf", 
					ITEMDATA, 
					"Name=depart", "Value={departCity}", ENDITEM, 
					"Name=departDate", "Value={departDate}", ENDITEM, 
					"Name=arrive", "Value={arriveCity}", ENDITEM, 
					"Name=returnDate", "Value={returnDate}", ENDITEM, 
					"Name=numPassengers", "Value={numPassengers}", ENDITEM, 
					"Name=roundtrip", "Value=", ENDITEM,
					"Name=seatPref", "Value={seatPref}", ENDITEM, 
					"Name=seatType", "Value={seatType}", ENDITEM, 
					"Name=findFlights.x", "Value=58", ENDITEM, 
					"Name=findFlights.y", "Value=7", ENDITEM,
					EXTRARES,
					"URL=http://localhost:1080/cgi-bin/reservations.pl", 
					//"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
					ENDITEM,
					LAST);
*/          
			
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
				
			//Генерация тела запроса на покупку билетов независимо от типа билета (туда или "туда-обратно")
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
			
			//Сохраняем в параметр время отправления                                      
			lr_save_string (lr_paramarr_idx("departTimeAnyFlight", atoi(lr_eval_string("{outbound_flight_id}"))), "departFlightTime");
			//Сохраняем в параметр номер рейса
			lr_save_string (lr_paramarr_idx("flightNumber", atoi(lr_eval_string("{outbound_flight_id}"))), "departFlightNumber");			
			
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
			
			web_custom_request("itinerare.pl",
	            "Method=POST", 
				"TargetFrame=",
				"URL=http://localhost:1080/cgi-bin/reservations.pl",
				"Referer=http://localhost:1080/cgi-bin/reservations.pl",
				"Body={bodyPOSTRequest}",
				LAST);			

	lr_end_transaction("insert_payment_info",LR_AUTO);

	
	
// 5. Выход из системы

	click_sing_off_request();

	lr_end_transaction("UC_01_BuyingTicket", LR_AUTO);

	return 0;
}
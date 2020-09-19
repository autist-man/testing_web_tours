Action()
{
	/*Скрипт "3. Поиск авиарейсов без оплаты" согласно МТН*/
	//Флаг определяющий будет ли билет в одну сторону или "туда и обратно"
	//имеет два значения 0 и 1 - значения берутся из параметра {random_roundtrip_nember}
	int random_roundtrip;
	
	//Назначаем города отправления и назначения из файла
	//если города совпадают, смещаем город на другое значение
	if(strcmp(lr_eval_string("{departCity}"),lr_eval_string("{arriveCity}")) == 0){
		lr_advance_param("arriveCity");
	}

	lr_start_transaction("UC_03_SearchTicketWithoutPayment");

	
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
						"Name=reserveFlights.x", "Value=79", ENDITEM, 
						"Name=reserveFlights.y", "Value=11", ENDITEM,
						EXTRARES,
						"URL=http://localhost:1080/cgi-bin/reservations.pl", 
						"Referer=http://localhost:1080/cgi-bin/reservations.pl", ENDITEM,
						LAST);
			}

	lr_end_transaction("choose_flight",LR_AUTO);
	

// 4. Выход из системы

	click_sing_off_request();
	
	lr_end_transaction("UC_03_SearchTicketWithoutPayment", LR_AUTO);

	

	return 0;
}
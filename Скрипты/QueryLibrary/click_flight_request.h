#ifndef CLICK_FLIGHT_REQUEST_H
#define CLICK_FLIGHT_REQUEST_H

//Функция нажатия кнопки для заполения полей для поиска авиарейсов
void click_flight_request(){
	lr_start_transaction("click_flight");
	
	lr_think_time(5);
	
			web_revert_auto_header("Sec-Fetch-User");
		
			web_revert_auto_header("Upgrade-Insecure-Requests");	
			
			//Простая проверка на наличие указанной сторки  в ответе запроса (динамически проверять нечего)
			web_reg_find("Fail=NotFound",
				"Text=No. of Passengers :",
				LAST);
		
			web_url("Search Flights Button", 
				"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
				"TargetFrame=body", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
				"Snapshot=t9.inf", 
				"Mode=HTML", 
				LAST);

	lr_end_transaction("click_flight",LR_AUTO);
}

#endif CLICK_FLIGHT_REQUEST_H
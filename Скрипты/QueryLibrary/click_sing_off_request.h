#ifndef CLICK_SING_OFF_REQUEST_H
#define CLICK_SING_OFF_REQUEST_H

//Функция выхода из аккаунта
void click_sing_off_request(){
	lr_start_transaction("click_sing_off");
	
	lr_think_time(5);
	
			web_add_auto_header("Sec-Fetch-Site", 
				"none");
		
			web_add_auto_header("Sec-Fetch-Mode", 
				"no-cors");
		
			web_add_auto_header("Sec-Fetch-Dest", 
				"empty");
		
			web_add_header("Origin", 
				"null");
			
			web_add_auto_header("Sec-Fetch-Site", 
				"same-origin");
		
			web_add_auto_header("Sec-Fetch-Mode", 
				"navigate");
		
			web_add_auto_header("Sec-Fetch-Dest", 
				"frame");
		
			web_add_header("Sec-Fetch-User", 
				"?1");
		
			web_add_header("Upgrade-Insecure-Requests", 
				"1");
			
			web_reg_find("Fail=NotFound",
				"Text=Welcome to the Web Tours site.",
				LAST);
			
			web_url("welcome.pl", 
				"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
				"TargetFrame=", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
				"Snapshot=t16.inf", 
				"Mode=HTML", 
				LAST);
		
			web_add_auto_header("Sec-Fetch-Site", 
				"none");
		
			web_add_auto_header("Sec-Fetch-Mode", 
				"no-cors");
		
			web_add_auto_header("Sec-Fetch-Dest", 
				"empty");
	
	lr_end_transaction("click_sing_off",LR_AUTO);
}


#endif //CLICK_SING_OFF_REQUEST_H
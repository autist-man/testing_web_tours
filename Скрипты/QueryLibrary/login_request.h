#ifndef LOGIN_REQUEST_H
#define LOGIN_REQUEST_H

//Функция авторизации
void login_request(){
	lr_start_transaction("login");
	
	lr_think_time(5);

			web_revert_auto_header("Origin");
		
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
			
			//Проверка строки включающей в себя имя пользователя ("username")
			web_reg_find("Fail=NotFound",
				"Text=Welcome, <b>{username}</b>, to the Web Tours reservation pages.",
				LAST);
			
			web_submit_data("login.pl",
				"Action=http://localhost:1080/cgi-bin/login.pl",
				"Method=POST",
				"TargetFrame=",
				"RecContentType=text/html",
				"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
				"Snapshot=t8.inf",
				"Mode=HTML",
				ITEMDATA,
				"Name=userSession", "Value={userSession}", ENDITEM,
				"Name=username", "Value={username}", ENDITEM,
				"Name=password", "Value={password}", ENDITEM,
				"Name=login.x", "Value=51", ENDITEM,
				"Name=login.y", "Value=6", ENDITEM,
				"Name=JSFormSubmit", "Value=off", ENDITEM,
				LAST);

	lr_end_transaction("login",LR_AUTO);
}

#endif //LOGIN_REQUEST_H
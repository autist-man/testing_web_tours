Action()
{
	char * username;
	char * password = (char*)generate_password(atoi(lr_eval_string("{length_login_and_pass}")), atoi(lr_eval_string("{first_letter_login}")));
	
	lr_save_string(password, "password");
	lr_output_message("password %s",lr_eval_string("{password}"));
	free(password);
	
	srand(time(NULL));
	
	web_set_sockets_option("SSL_VERSION", "2&3");
	
	lr_start_transaction("UC_00_registration");
	
	lr_start_transaction("go_to_site");

		//Простая проверка на наличие указанной сторки  в ответе запроса (динамически проверять нечего)
		web_reg_find("Fail=NotFound",
			"Text=Welcome to the Web Tours site.",
			LAST);
	
		web_url("WebTours", 
				"URL=http://localhost:1080/WebTours", 
				"TargetFrame=", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=", 
				"Snapshot=t1.inf", 
				"Mode=HTML", 
				LAST);

	lr_end_transaction("go_to_site", LR_AUTO);
	
		lr_start_transaction("click_sign_up_now");
		lr_think_time(5);
		
			//Простая проверка на наличие указанной сторки  в ответе запроса (динамически проверять нечего)
			web_reg_find("Fail=NotFound",
				"Text=First time registering? Please complete the form below.",
				LAST);
		
			web_url("sign_up_now", 
				"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
				"TargetFrame=body", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/WebTours/home.html", 
				"Snapshot=t7.inf", 
				"Mode=HTML", 
				LAST);
		
		lr_end_transaction("click_sign_up_now", LR_AUTO);
		
		lr_start_transaction("click_registration");
		lr_think_time(5);
		
	//Регистрация с повторными попытками, если пользователь с таким логином уже существует
	{	
		//счетчик, не более 3 попыток
		int count = 1;
		
		do{	
			username = (char*)generate_login(atoi(lr_eval_string("{length_login_and_pass}")), atoi(lr_eval_string("{first_letter_login}")));
			lr_save_string(username, "username");
			free(username);
			
			if(count > 3){
				lr_save_datetime("%m%d%Y%H%M%S", DATE_NOW, "currDateTime"); 
				lr_param_sprintf("username", "%s%s", lr_eval_string("{username}"), lr_eval_string("{currDateTime}"));
			}
			web_reg_save_param_ex(
				"ParamName=username_pass",
				"LB=Thank you, <b>",
				"RB=</b>, for registering",
				"NotFound=warning",
				SEARCH_FILTERS,
				"Scope=BODY",
				LAST);	
			
			web_submit_data("login.pl", 
				"Action=http://localhost:1080/cgi-bin/login.pl", 
				"Method=POST", 
				"TargetFrame=info", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
				"Snapshot=t14.inf", 
				"Mode=HTML", 
				ITEMDATA, 
				"Name=username", "Value={username}", ENDITEM, 
				"Name=password", "Value={password}", ENDITEM, 
				"Name=passwordConfirm", "Value={password}", ENDITEM, 
				"Name=firstName", "Value={firstName}", ENDITEM, 
				"Name=lastName", "Value={lastName}", ENDITEM, 
				"Name=address1", "Value={address1}", ENDITEM, 
				"Name=address2", "Value={address2}", ENDITEM, 
				"Name=register.x", "Value=54", ENDITEM, 
				"Name=register.y", "Value=6", ENDITEM, 
				LAST);
			
		}while(strcmp(lr_eval_string("{username}"),lr_eval_string("{username_pass}")) != 0);
	}
	
	
	//Регистрация без повторных попыток, если такой пользователь существует скрипт валиться с ошибкой
//	{	
//		username = (char*)generate_login(atoi(lr_eval_string("{length_login_and_pass}")), atoi(lr_eval_string("{first_letter_login}")));
//		lr_save_string(username, "username");
//		free(username);
//		
//			web_reg_find("Fail=NotFound",
//		             "Text=Thank you, <b>{username}</b>, for registering and welcome",
//					 LAST);	
//	
//			web_submit_data("login.pl", 
//				"Action=http://localhost:1080/cgi-bin/login.pl", 
//				"Method=POST", 
//				"TargetFrame=info", 
//				"RecContentType=text/html", 
//				"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
//				"Snapshot=t14.inf", 
//				"Mode=HTML", 
//				ITEMDATA, 
//				"Name=username", "Value={username}", ENDITEM, 
//				"Name=password", "Value={password}", ENDITEM, 
//				"Name=passwordConfirm", "Value={password}", ENDITEM, 
//				"Name=firstName", "Value={firstName}", ENDITEM, 
//				"Name=lastName", "Value={lastName}", ENDITEM, 
//				"Name=address1", "Value={address1}", ENDITEM, 
//				"Name=address2", "Value={address2}", ENDITEM, 
//				"Name=register.x", "Value=54", ENDITEM, 
//				"Name=register.y", "Value=6", ENDITEM, 
//				LAST);
//	}
		
		lr_end_transaction("click_registration", LR_AUTO);
		
	lr_end_transaction("UC_00_registration", LR_AUTO);

	return 0;
}
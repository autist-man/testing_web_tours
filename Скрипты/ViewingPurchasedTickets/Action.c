Action()
{
	/*Скрипт "5. Просмотр купленных билетов" согласно МТН*/
	
	lr_start_transaction("UC_05_ViewingPurchasedTickets");
	
	
// Заргузка сайта
	
	go_to_site_request();
	
// 1. Авторизация

	login_request();
	
//2. Просмотр квитанций

	
	lr_start_transaction("viewing_receipts");
	
	lr_think_time(5);

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
	
			//Предпалагается, что билеты должны быть
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


	
//3. Выход из системы

	click_sing_off_request();
	
	lr_end_transaction("UC_05_ViewingPurchasedTickets", LR_AUTO);


	return 0;
}
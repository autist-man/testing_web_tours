#ifndef GO_TO_SITE_REQUEST_H
#define GO_TO_SITE_REQUEST_H

//Функция захода на сайт
void go_to_site_request(){
	lr_start_transaction("go_to_site");

			web_set_sockets_option("SSL_VERSION", "2&3");
		
			web_add_auto_header("Sec-Fetch-Site", 
				"none");
		
			web_add_auto_header("Sec-Fetch-Dest", 
				"document");
		
			web_add_auto_header("Sec-Fetch-Mode", 
				"navigate");
		
			web_add_auto_header("DNT", 
				"1");
		
			web_add_header("Sec-Fetch-User", 
				"?1");
		
			web_add_header("Upgrade-Insecure-Requests", 
				"1");
		
			/*Correlation comment - Do not change!  Original value='129607.167922236zzzzzzipHtAAAApAVcc' Name ='userSession'*/
			web_reg_save_param_ex(
				"ParamName=userSession",
				"LB=name=\"userSession\" value=\"",
				"RB=\"/>",
				"NotFound=error",
				"Ordinal=1",
				SEARCH_FILTERS,
				"Scope=BODY",
				"RequestUrl=http://localhost:1080/cgi-bin/nav.pl?in=home",
				LAST);
			
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
			
			web_add_auto_header("Sec-Fetch-Dest", 
				"empty");
			
			web_add_auto_header("Sec-Fetch-Mode", 
				"cors");
			
			web_add_header("Origin", 
				"null");
			
			web_add_auto_header("Origin", 
				"null");
			
			web_add_auto_header("Sec-Fetch-Mode", 
				"no-cors");

	lr_end_transaction("go_to_site", LR_AUTO);
}

#endif //GO_TO_SITE_REQUEST_H
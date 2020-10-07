Action1()
{

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	web_url("sign up now", 
		"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/home.html", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(10);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=qwer", ENDITEM, 
		"Name=password", "Value=qwer", ENDITEM, 
		"Name=passwordConfirm", "Value=qwer", ENDITEM, 
		"Name=firstName", "Value=qwer", ENDITEM, 
		"Name=lastName", "Value=qwer", ENDITEM, 
		"Name=address1", "Value=qwer", ENDITEM, 
		"Name=address2", "Value=qwer", ENDITEM, 
		"Name=register.x", "Value=54", ENDITEM, 
		"Name=register.y", "Value=6", ENDITEM, 
		LAST);

	return 0;
}
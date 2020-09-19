Action2()
{

	lr_think_time(16);

	web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value=Los Angeles", ENDITEM, 
		"Name=departDate", "Value=09/19/2020", ENDITEM, 
		"Name=arrive", "Value=Portland", ENDITEM, 
		"Name=returnDate", "Value=09/20/2020", ENDITEM, 
		"Name=numPassengers", "Value=4", ENDITEM, 
		"Name=seatPref", "Value=Aisle", ENDITEM, 
		"Name=seatType", "Value=First", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=32", ENDITEM, 
		"Name=findFlights.y", "Value=9", ENDITEM, 
		LAST);

	web_submit_form("reservations.pl_2", 
		"Snapshot=t28.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=352;351;09/19/2020", ENDITEM, 
		"Name=reserveFlights.x", "Value=48", ENDITEM, 
		"Name=reserveFlights.y", "Value=3", ENDITEM, 
		LAST);

	return 0;
}
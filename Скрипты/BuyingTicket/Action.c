Action()
{
	/*������ "1. ������� ����������" �������� ���*/

	//���� ������������ ����� �� ����� � ���� ������� ��� "���� � �������"
	//����� ��� �������� 0 � 1 - �������� ������� �� ��������� {random_roundtrip_nember}
	int random_roundtrip;
	
	//��������� ������ ����������� � ���������� �� �����
	//���� ������ ���������, ������� ����� �� ������ ��������
	if(strcmp(lr_eval_string("{departCity}"),lr_eval_string("{arriveCity}")) == 0){
		lr_advance_param("arriveCity");
	}
	
	lr_start_transaction("UC_01_BuyingTicket");

// �������� �����

	go_to_site_request();
	
// 1. �����������

	login_request();
	
//2. ���������� ����� ��� ������

	//������� ������ "Flights"
	
	click_flight_request();
	
	//���������� ����� ������ ����� � ������� ������ "Continue"
	
	lr_start_transaction("fill_find_flight");
	
	lr_think_time(5);
			
			//� �������� "departTimeAnyFlight" ������������ ��� ����� ������ ������ �����\
			//���������� �� ���� ������, � ������ ������� ����� �������� ���������, �������������
			//� ������ ������ ����-������� � ������ ��������� ������ 4 ������� "����"
			//��������� 4 ������� "�������"
			web_reg_save_param_regexp(
				"ParamName=departTimeAnyFlight",
				"RegExp=[0-9]+(am|pm)",
				"Group=0",
				"Ordinal=All",
				SEARCH_FILTERS,
				"Scope=BODY",
				"RequestUrl=http://localhost:1080/cgi-bin/reservations.pl",
				LAST);

			//����� ����� ��� ����� ������ ����������� ����� ����� � ���������� � ����� ������
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
			
			//���� ������ ����������� ������ � �������� ������ "���� � �������",
			//���� ���� ����������� ������ � �������� ������ ������ � ���� �������,
			//random_roundtrip - ����� ��� �������� 0 � 1.
			random_roundtrip = atoi(lr_eval_string("{random_roundtrip_number}"));

			if(random_roundtrip){
				//����������� ID �������� ������ "returnFlight"
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
			//�������������� ������ ����� - ����� �������� "outboundFlight"
			//��� ����� ������� ����
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
			
/*������-�� ������ ������� �� ������ ���������� ������� �������� ������ "Requested form not found", �� ���������� � �������!
//			������������ �����, �������� {random_roundtrip} ������ ����� ��� ������� "on" ��� <OFF>
//			��� �������� ��������� random_roundtrip, ������� ���������� �������� random_roundtrip = 0(<OFF>) ��� 1(on) ��� ����������� if()
//          ������� �������� ���������� if � ���� ������� ����������� ����� ��� ������, ��� ��� ��� ����� ���������� ������ ���������� ���� �����,
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
			
			//�������� �� �������� ������� ����������� ("departCity") � �������� ("arriveCity"), � ������� ����������� ("departDate")
			web_reg_find("Fail=NotFound",
					"Text=Flight departing from <B>{departCity}</B> to <B>{arriveCity}</B> on <B>{departDate}</B>",
					LAST);
			if(random_roundtrip){
				//�������� �� �������� ������� ��������� ����� ����������� ("arriveCity") � �������� ("departCity"), � ������� ����������� ("returnDate")
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
				//�������������� ������ ����� - �� ������� ����� �������� "returnFlight", ����� ��������� ������� �������� ���� �� ���������
				//� ������ � ��������� � ������ "rundomReturnFlight"
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
			
			//�������������� ������ ����� - �� ������� ����� �������� "outboundFlight", ����� ��������� ������� �������� ���� �� ���������
			//� ������ � ��������� � ������ "rundomOutboundFlight"
			lr_save_string (lr_paramarr_idx("outboundFlight", atoi(lr_eval_string("{outbound_flight_id}"))), "randomOutboundFlight");

	lr_end_transaction("fill_find_flight",LR_AUTO);
			
			
	
//3. ����� ����� � ��������



	lr_start_transaction("choose_flight");
    
	lr_think_time(5);
			
			//�������� �� ������ ���������� ��������� ������� ��������� "rundomOutboundFlight"
			web_reg_find("Fail=NotFound",
				"Text=name=\"outboundFlight\" value=\"{randomOutboundFlight}\"  />",
				LAST);
			
			//�������� �������� � ����������� �� ���� ������ (���� ��� ����-�������)
			if(random_roundtrip){
				//�������� �� ������ ���������� ��������� ������� ��������� "rundomReturnFlight"
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
	
	
	
//4. ������ ������



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
				
			//��������� ���� ������� �� ������� ������� ���������� �� ���� ������ (���� ��� "����-�������")
			//� ���������� ����������, ����� ����������� �������� �������� �� ������������ ����������
			//�� 25 �������� ��������� "pay" = 00:00.040 c
			//lr_start_transaction("pay");
			{
				//numPassengers - ���������� ����������
				int numPassengers = atoi(lr_eval_string("{numPassengers}"));
				//count - ������� ��� �����
				int count;
				FILE * buyRequestFile;

				if((buyRequestFile = fopen("buyRequestFile.txt", "w")) == NULL){
			       lr_output_message("Error: %s", "�� ������� ������� ���� ��� ������ ������� �� �������� �������");
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
				
				
				//��������� �������� ���������� � ���� ��������, ����� ������� �� �� ������ �����
				//� ���� ������� �������� ���������� ��������� �������
				//   expDate=04%2F25&outboundFlight=923%3B221%3B09%2F17%2F2020
				//������ ; ���������� ��������� %3B
				//������ / ���������� ��������� %2F
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
				
				//���� ����� "����-�������" ����������� ID ��������� ����� "randomReturnFlight"
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
				//������ �� ����� ���� ������� ��������������� ��������� �������
				//���������� ���� � �������� "bodyPOSTRequest"
				{
					int res = lr_read_file("buyRequestFile.txt", "bodyPOSTRequest", 0);
					if(res == -1){
						lr_output_message("Error: �� ������� ������� ���� ������� �� �����");
						return 0;
					}
				}
			
			}
			//lr_end_transaction("pay", LR_AUTO);
			
			//��������� � �������� ����� �����������                                      
			lr_save_string (lr_paramarr_idx("departTimeAnyFlight", atoi(lr_eval_string("{outbound_flight_id}"))), "departFlightTime");
			//��������� � �������� ����� �����
			lr_save_string (lr_paramarr_idx("flightNumber", atoi(lr_eval_string("{outbound_flight_id}"))), "departFlightNumber");			
			
			//�������� ���������� ������ �� ����� � ���� �����������, ����� ����������� � ��������, � ����� ���������
				web_reg_find("Fail=NotFound",
					"Text={departDate} :  {departFlightTime} : Flight {departFlightNumber} leaves {departCity}  for {arriveCity}",
					LAST);
				
				//�������� ���������� ������ �� ����� � ���� �����������, ����� ����������� � ��������, � ����� ���������
				//��� ���� ������ "����-�������"
				if(random_roundtrip){
					//����� ������� ����������� ������� �����������
					int lenght_departTimeAnyFlight = atoi(lr_eval_string("{departTimeAnyFlight_count}"));
					//����� ���������� ����������� �����
					lr_save_string (lr_paramarr_idx("departTimeAnyFlight", lenght_departTimeAnyFlight/2 + atoi(lr_eval_string("{return_flight_id}"))), "arriveFlightTime");
					//����� ��������� �����
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

	
	
// 5. ����� �� �������

	click_sing_off_request();

	lr_end_transaction("UC_01_BuyingTicket", LR_AUTO);

	return 0;
}
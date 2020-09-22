Action()
{
	/*������ "2. �������������� ����������" �������� ���*/
	
	//���� ������������ ����� �� ����� � ���� ������� ��� "���� � �������"
	//����� ��� �������� 0 � 1 - �������� ������� �� ��������� {random_roundtrip_nember}
	int random_roundtrip;
	
	//������������� ������ ��� �������� ������� ��������� �������
	//����������� ������� �����������, ����� ����������� �� �������� ������ ��� ���������� ������� (�� 3 ��) ��� ��������
	#define NUMBER_OF_TICKET 3
	//����� ������� ������� ������������ ��� �������� ���������� ������ ������ � ������� ���������� {arrayFlightID}
	//������ ������� ������ ��������� ��� ����������� ���-�� ����������� ������� �� ������ ������� "arrayFlightID_2" =  "    ->382141149<-   -2208620-LD"
	#define COLUMNS 2
	int deletedTicketsID[NUMBER_OF_TICKET][COLUMNS];
	
	//numberTickets - ����� ���������� ������� ������� (�� ������� �� 1 �� 3 ������� �� ���)
	int numberTickets;
	
	srand(time(NULL));
	
	//��������� ������ ����������� � ���������� �� �����
	//���� ������ ���������, ������� ����� �� ������ ��������
	if(strcmp(lr_eval_string("{departCity}"),lr_eval_string("{arriveCity}")) == 0){
		lr_advance_param("arriveCity");
	}
	
	lr_start_transaction("UC_02_ReissuanceTicket");
	
	
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

			//��������� � �������� ����� �����������                                      
			lr_save_string (lr_paramarr_idx("departTimeAnyFlight", atoi(lr_eval_string("{outbound_flight_id}"))), "departFlightTime");
			//��������� � �������� ����� �����
			lr_save_string (lr_paramarr_idx("flightNumber", atoi(lr_eval_string("{outbound_flight_id}"))), "departFlightNumber");
			
			//��������� ���� ������� �� ������� ������� ���������� ������ ���� � ����
			//���������� �� ���� ������ (���� ��� "����-�������")
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
				//��������� ���� ������� �� ��������� ����������
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
				//��������� ����� ���������� ����������
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
	
/*			//��������� ���� ������� �� ������� ������� ���������� �� ���� ������ (���� ��� "����-�������")
			//� ���������� ����������, ����� ����������� �������� �������� �� ������������ ����������
			//�� 25 �������� ��������� "pay_args" = 00:00.095 c
			lr_start_transaction("pay_args");
			{
				//numPassengers - ���������� ����������
				int numPassengers = atoi(lr_eval_string("{numPassengers}"));
				//count - ������� ��� �����
				int count;

				form_args_add("Snapshot=t47.inf");
				form_args_add(ITEMDATA);
				form_args_add("Name=firstName"); form_args_add("Value={firstName}"); form_args_add(ENDITEM);
				form_args_add("Name=lastName"); form_args_add("Value={lastName}"); form_args_add(ENDITEM);
				form_args_add("Name=address1"); form_args_add("Value={homeAddress}"); form_args_add(ENDITEM);
				form_args_add("Name=address2"); form_args_add("Value={homeCity}"); form_args_add(ENDITEM);
				form_args_add("Name=pass1"); form_args_add("Value={firstName} {lastName}"); form_args_add(ENDITEM);
				
				//��������� ����� ������ ����������, ���� ��� ����
				for(count = 2; count <= numPassengers; count++){
					form_args_add_paramarr("Name=pass", count);
					form_args_add("Value={firstNameAnotherPassenger} {lastNameAnotherPassenger}");
					form_args_add(ENDITEM);
				}
				
				form_args_add("Name=creditCard"); form_args_add("Value={creditCard}"); form_args_add(ENDITEM);
				form_args_add("Name=expDate"); form_args_add("Value={expDate}"); form_args_add(ENDITEM);	
				form_args_add("Name=saveCC"); form_args_add("Value=<OFF>"); form_args_add(ENDITEM);
				form_args_add("Name=buyFlights.x"); form_args_add("Value=27"); form_args_add(ENDITEM);
				form_args_add("Name=buyFlights.y"); form_args_add("Value=8"); form_args_add(ENDITEM);
				form_args_add(EXTRARES); 
				form_args_add("URL=http://localhost:1080/cgi-bin/reservations.pl");
				form_args_add("Referer=http://localhost:1080/cgi-bin/reservations.pl");form_args_add(ENDITEM);
				form_args_add(LAST);				
			}
			lr_end_transaction("pay_args",LR_AUTO);
			//������ �� ������� ������ ����� ��������� 	web_submit_form_custom	
			web_submit_form("itinerare.pl", FORM_ARGS);
			//����������� ������ "FORM_ARGS"
			form_args_reset();
*/

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
				
			//������ �� ������� ����� ��������� ���� ������� ����������� ������� � ����
			//� ����������� ����������� �� ���� � ������� � �������� {bodyPOSTRequest}
			web_custom_request("itinerare.pl",
	            "Method=POST", 
				"TargetFrame=",
				"URL=http://localhost:1080/cgi-bin/reservations.pl",
				"Referer=http://localhost:1080/cgi-bin/reservations.pl",
				"Body={bodyPOSTRequest}",
				LAST);
			
	lr_end_transaction("insert_payment_info",LR_AUTO);


//5. �������� ���������
	
	lr_start_transaction("viewing_receipts");
	
	lr_think_time(5);
	
	//����������� ���������� ��������� ������� � ������������
	//����������� ����:
	//			"Name=flightID", "Value=368096418-793-SC" (1)
	//			"Name=.cgifields", "Value=6"              (2)

	//������������ ���� (1)
			web_reg_save_param_ex(
				"ParamName=arrayFlightID",
				"LB=name=\"flightID\" value=\"",
				"RB=\"  />",
				"NotFound=error",
				"Ordinal=All",
				SEARCH_FILTERS,
				"Scope=BODY",
				"RequestUrl=http://localhost:1080/cgi-bin/itinerary.pl",
				LAST);
	//������������ ���� (2)
			web_reg_save_param_ex(
				"ParamName=array_cgifields",
				"LB=name=\".cgifields\" value=\"",
				"RB=\"  />",
				"NotFound=error",
				"Ordinal=All",
				SEARCH_FILTERS,
				"Scope=BODY",
				"RequestUrl=http://localhost:1080/cgi-bin/itinerary.pl",
				LAST);
	
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
	
			//��������� ���� ������� �� �������� ������� ����������� ������ ���� ������� � ����
			// � ����������� ����������� �� ����
			//�������� �������, ��� ����� ������ ����������� ������������
			//�� 25 �������� ��������� "file" = 00:00.975 (�������: � ���� ������������� � ������� ������� 20-30 �������)
			//lr_start_transaction("file");
			{	
				//FlightID - ���� ���������� ������ "arrayFlightID_2" =  "382141149-2208620-LD"
				//partFlightID - ������ ����� � "arrayFlightID_2" =  " ->382141149<-   -2208620-LD"
				char * FlightID, * partFlightID;
				//lenghtArrayFlightID - ���������� ������� � �������������
				int lenghtArrayFlightID = atoi(lr_eval_string("{arrayFlightID_count}"));
				//count - ������� ��� �����
				//ord - ������� ��� ������� � ������� �������� ������ ��������� ������� � ������� ���������� {arrayFlightID}
				//result - ������ ��������� ���������� �������, ������� ��������� �� ������ ������ ������
				int count, ord, result; 
				FILE * deleteRequestFile;
				
				numberTickets = atoi(lr_eval_string("{numberTickets}"));
				
				//�������������� ������ �������� �������
				//�������� ����� ��� ��������� ���������� ��������� ����� � �������
				//�� ord = 0 �� lenghtArrayFlightID - ���������� ����� �������� �� ������ � ������ �������
				//<label><input type="checkbox" name="  ->1<-  " value="on" /></label></font></b>
				//<input type="hidden" name="flightID" value="36810199-120782-SC"  />
				//�� count=0 �� numberTickets -������� ����� ��� ����� �����
				//�������������, ��� ���� numberTickets <= lenghtArrayFlightID ����� � ������� ����� �����������
				for(count = 0, ord = 0; count < numberTickets && ord < lenghtArrayFlightID; ord++){
					int rn = lenghtArrayFlightID - ord;
					int rm = numberTickets - count;
					if(rand()%rn < rm){
						deletedTicketsID[count][0] = ord + 1; //+1 ����� ����� �������� ��������� � 1
						//���������� ����������� ������� �� ������ ������
						//� ����������� ������������� ������ � ���������� ��������
						//�� ���������� ���� ����, ���� ��������� ����������� �������
						deletedTicketsID[count++][1] = 1;
					}
				}
				
								
				if((deleteRequestFile = fopen("deleteRequestFile.txt", "w")) == NULL){
			       lr_output_message("Error: %s", "�� ������� ������� ���� ��� ������ ������� �� �������� �������");
			       return 0;
			    }
				
				for(count = 1; count <= lenghtArrayFlightID; count++)
				{
					FlightID = lr_paramarr_idx("arrayFlightID", count);
					//��������� ����������� ������� � ������� �������� �� ������ ������ ������ ������
					for(ord = 0; ord < numberTickets; ord++){
						//���������� ������ ����� ������ ��������
						partFlightID = strtok(lr_eval_string(lr_paramarr_idx("arrayFlightID",deletedTicketsID[ord][0])), "-");
						//���������� � ������ �������
						result = strncmp(lr_eval_string(lr_paramarr_idx("arrayFlightID",count)),
						                partFlightID,
						                strlen(partFlightID));
						//���� ��������� � ����� ������ �� ����� ������ ����
						//����������� �������
						if(result==0 & deletedTicketsID[ord][0] != count){
							deletedTicketsID[ord][1]+=1;
						}
					}
					//���������� ���� ������� � ����
					//������� ������� � ���� ������� �� �����
					//�������� ����������� �����������
					if(count <= numberTickets){
        				fprintf(deleteRequestFile,
						       "%d=on&flightID=%s&.cgifields=%s&",
						      	deletedTicketsID[count-1][0], FlightID, FlightID);
					} else{
        				fprintf(deleteRequestFile,
						       "flightID=%s&.cgifields=%s&",
						      	FlightID, FlightID);
					}
				}   
				fprintf(deleteRequestFile, "removeFlights.x=48&removeFlights.y=6");
				
				fclose(deleteRequestFile);
				//������ �� ����� ���� ������� ��������������� ��������� �������
				//���������� ���� � �������� "bodyPOSTRequest"
				{
					int res = lr_read_file("deleteRequestFile.txt", "bodyPOSTRequest", 0);
					if(res == -1){
						lr_output_message("Error: �� ������� ������� ���� ������� �� �����");
						return 0;
					}
				}
			}
			//lr_end_transaction("file", LR_AUTO);
			
/*		//��������� ������� �� �������� ������� ����� web_submit_form_custom
		//�� 25 �������� ��������� "array" = 00:00.920 (�������: � ���� ������������� � ������� ������� 20-30 �������)
		//lr_start_transaction("array");
	{
				//FlightID - ���� ���������� ������ "arrayFlightID_2" =  "382141149-2208620-LD"
				//partFlightID - ������ ����� � "arrayFlightID_2" =  " ->382141149<-   -2208620-LD"				
				char * FlightID, * partFlightID;
				//lenghtArrayFlightID - ���������� ������� � �������������
				int lenghtArrayFlightID = atoi(lr_eval_string("{arrayFlightID_count}"));
				//count - ������� ��� �����
				//ord - ������� ��� ������� � ������� �������� ������ ��������� ������� � ������� ���������� {arrayFlightID}
				//result - ������ ��������� ���������� �������, ������� ��������� �� ������ ������ ������
				int count, ord, result; 
				
				numberTickets = atoi(lr_eval_string("{numberTickets}"));
				
				//�������������� ������ �������� �������
				//�������� ����� ��� ��������� ���������� ��������� ����� � �������
				//�� ord = 0 �� lenghtArrayFlightID - ���������� ����� �������� �� ������ � ������ �������
				//<label><input type="checkbox" name="  ->1<-  " value="on" /></label></font></b>
				//<input type="hidden" name="flightID" value="36810199-120782-SC"  />
				//�� count=0 �� numberTickets -������� ����� ��� ����� �����
				//�������������, ��� ���� numberTickets <= lenghtArrayFlightID ����� � ������� ����� �����������
				for(count = 0, ord = 0; count < numberTickets && ord < lenghtArrayFlightID; ord++){
					int rn = lenghtArrayFlightID - ord;
					int rm = numberTickets - count;
					if(rand()%rn < rm){
						deletedTicketsID[count][0] = ord + 1; //+1 ����� ����� �������� ��������� � 1
						//���������� ����������� ������� �� ������ ������
						//� ����������� ������������� ������ � ���������� ��������
						//�� ���������� ���� ����, ���� ��������� ����������� �������
						deletedTicketsID[count++][1] = 1;
					}
				}
				     form_args_add("Snapshot=t57.inf");
        			 form_args_add(ITEMDATA);
					
				for(count = 1; count <= lenghtArrayFlightID; count++)
				{
					FlightID = lr_paramarr_idx("arrayFlightID", count);
					//��������� ����������� ������� � ������� �������� �� ������ ������ ������ ������
					for(ord = 0; ord < numberTickets; ord++){
						//���������� ������ ����� ������ ��������
						partFlightID = strtok(lr_eval_string(lr_paramarr_idx("arrayFlightID",deletedTicketsID[ord][0])), "-");
						//���������� � ������ �������
						result = strncmp(lr_eval_string(lr_paramarr_idx("arrayFlightID",count)),
						                partFlightID,
						                strlen(partFlightID));
						//���� ��������� � ����� ������ �� ����� ������ ����
						//����������� �������
						if(result==0 & deletedTicketsID[ord][0] != count){
							deletedTicketsID[ord][1]+=1;
						}
					}
					if(count <= numberTickets){
		                form_args_add_paramarr("Name=", deletedTicketsID[count-1][0]);
		                form_args_add("Value=on");
		                form_args_add(ENDITEM);
					}
				}

				form_args_add("Name=removeFlights.x"); form_args_add("Value=47"); form_args_add(ENDITEM);
				form_args_add("Name=removeFlights.y"); form_args_add("Value=7"); form_args_add(ENDITEM);
				form_args_add(EXTRARES);
				form_args_add("URL=http://localhost:1080/cgi-bin/reservations.pl");
				form_args_add("Referer=http://localhost:1080/cgi-bin/reservations.pl");
			    form_args_add(ENDITEM);
				form_args_add(LAST);
				
	}
				//lr_end_transaction("array", LR_AUTO);
	
	//������
	web_submit_form("itinerary.pl", FORM_ARGS);
	//����������� ������
	form_args_reset();
*/	
	
//6. ������ ������������
	
	
	
	lr_start_transaction("�ancel_reservation");
	
	lr_think_time(5);

			web_add_header("Origin", 
				"http://localhost:1080");
	
			//����������� ������ ����� ������ ������
			//��� ��������� � ���������� ��������
			web_reg_save_param_ex(
				"ParamName=ticketsPartID",
				"LB=name=\"flightID\" value=\"",
				"RB=-",
				"NotFound=error",
				"Ordinal=All",
				SEARCH_FILTERS,
				"Scope=BODY",
				"RequestUrl=http://localhost:1080/cgi-bin/itinerary.pl",
				LAST);
			
			web_reg_find("Fail=NotFound",
				"Text=<B>{firstName} {lastName}\n 's Flight Transaction Summary</B>",
				LAST);
	
			web_custom_request("itinerare.pl",
	            "Method=POST", 
				"TargetFrame=",
				"Snapshot=t23.inf",
				"URL=http://localhost:1080/cgi-bin/itinerary.pl",
				"Referer=http://localhost:1080/cgi-bin/itinerary.pl",
				"Body={bodyPOSTRequest}",
				LAST);

	
			//�������� �������� �������
			{
				int lenghtTicketsPartID = atoi(lr_eval_string("{ticketsPartID_count}"));
				//identicalTicketsNum - ������ ���������� ��������� ������� �� ������ ������ ������
				int count, ord, result, identicalTicketsNum;
				//�������� �� ������� ���������� ������
				for(ord = 0; ord < numberTickets; ord++){
					identicalTicketsNum = 0;
					//�������� �� ������� ������ ����� ��������
					for(count = 1; count <= lenghtTicketsPartID; count++){
						//��������� ��������� �� ������ ����� ���������� ������ � �������� ����� ��������
						result = strncmp(lr_eval_string(lr_paramarr_idx("arrayFlightID",deletedTicketsID[ord][0])),
						                 lr_eval_string(lr_paramarr_idx("ticketsPartID",count)),
						                 strlen(lr_eval_string(lr_paramarr_idx("ticketsPartID",count))));
						//���� ���������� ����
						//����������� ������� �� 1
						//���� ������� ����� ������ ��� ���������� ��� ���������� ������ deletedTicketsID[ord][1]
						//������ ������
						// !!! �� ��������� ���� ��� ���������� ����� ����� ��������, ������ ������ ����� ����� ����������
						// !!! ���������� ������ � ���� �������
						if(result==0){
							identicalTicketsNum +=1;
							if(identicalTicketsNum >= deletedTicketsID[ord][1])
								lr_end_transaction("�ancel_reservation", LR_FAIL);
						}
					}
				}
			}

	lr_end_transaction("�ancel_reservation", LR_AUTO);	
	
	
	
//7. ����� �� �������

	click_sing_off_request();
	
	lr_end_transaction("UC_02_ReissuanceTicket", LR_AUTO);


	return 0;
}
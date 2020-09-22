Action()
{
	/*������ "4. ����� ����������" �������� ���*/
	
	
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
	
	lr_start_transaction("UC_4_DeletingTickets");
	
// �������� �����

	go_to_site_request();
	
// 1. �����������

	login_request();

//2. �������� ���������
	
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
			//�� 25 �������� ��������� "file" = 00:00.084 c
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
			

//3. ������ ������������
	
	
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
				char * partFlightID;
				//�������� �� ������� ���������� ������
				for(ord = 0; ord < numberTickets; ord++){
					identicalTicketsNum = 0;
					//�������� �� ������� ������ ����� ��������
					for(count = 1; count <= lenghtTicketsPartID; count++){
						//���������� ������ ����� ������
						partFlightID = strtok(lr_eval_string(lr_paramarr_idx("arrayFlightID",deletedTicketsID[ord][0])), "-");
						//��������� ��������� �� ������ ����� ���������� ������ � �������� ����� ��������
						result = strcmp(partFlightID,
						                 lr_eval_string(lr_paramarr_idx("ticketsPartID",count)));
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
	
	
	
//4. ����� �� �������

	click_sing_off_request();

	lr_end_transaction("UC_4_DeletingTickets", LR_AUTO);
	
	return 0;
}

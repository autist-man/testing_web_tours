Action()
{
	/*Скрипт "4. Сдача авиабилета" согласно МТН*/
	
	
	//Фиксированный массив для хранения номеров удаленных билетов
	//Размерность массива фиксирована, чтобы динамически не выделять память под количество билетов (до 3 шт) для удаления
	#define NUMBER_OF_TICKET 3
	//Певый столбец массива предназначен для хранения удаленного номера билета в массиве параметров {arrayFlightID}
	//Второй столбец служит счетчиком для определения кол-ва совпадающих билетов по первым номерам "arrayFlightID_2" =  "    ->382141149<-   -2208620-LD"
	#define COLUMNS 2
	int deletedTicketsID[NUMBER_OF_TICKET][COLUMNS];
	
	//numberTickets - какое количесвто билетов удалить (по заданию от 1 до 3 билетов за раз)
	int numberTickets;
	
	srand(time(NULL));
	
	lr_start_transaction("UC_4_DeletingTickets");
	
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
	
	//Отлавливаем количество имеющихся билетов у пользователя
	//Итересующие поля:
	//			"Name=flightID", "Value=368096418-793-SC" (1)
	//			"Name=.cgifields", "Value=6"              (2)

	//Регистрируем поля (1)
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
	//Регистрируем поля (2)
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
	
			//Генерация тела запроса на удаление билетов посредством записи тела запроса в файл
			// с последующим считываниеи из него
			//работает быстрее, чем через запись посредством контакенации
			//за 25 итерации транзакия "file" = 00:00.084 c
			//lr_start_transaction("file");
			{	
				//FlightID - поле купленного билета "arrayFlightID_2" =  "382141149-2208620-LD"
				//partFlightID - первые цифры в "arrayFlightID_2" =  " ->382141149<-   -2208620-LD"
				char * FlightID, * partFlightID;
				//lenghtArrayFlightID - количество билетов у пользователья
				int lenghtArrayFlightID = atoi(lr_eval_string("{arrayFlightID_count}"));
				//count - счетчик для цикла
				//ord - счетчик для массива в котором хранятся номера удаленных билетов в массиве параметров {arrayFlightID}
				//result - хранит результат стравнения билетов, которые совпадают по первым цифрам номера
				int count, ord, result; 
				FILE * deleteRequestFile;
				
				numberTickets = atoi(lr_eval_string("{numberTickets}"));
				
				//Инициализируем массив номерами билетов
				//Инициализируем массив номерами билетов
				//Алгоритм Кнута для генерации уникальных случайных чисел в массиве
				//от ord = 0 до lenghtArrayFlightID - перебераем номер чекбокса по списку в ответе запроса
				//<label><input type="checkbox" name="  ->1<-  " value="on" /></label></font></b>
				//<input type="hidden" name="flightID" value="36810199-120782-SC"  />
				//от count=0 до numberTickets -сколько чисел еще нужно найти
				//гарантируется, что если numberTickets <= lenghtArrayFlightID числа в массиве будут уникальными
				for(count = 0, ord = 0; count < numberTickets && ord < lenghtArrayFlightID; ord++){
					int rn = lenghtArrayFlightID - ord;
					int rm = numberTickets - count;
					if(rand()%rn < rm){
						deletedTicketsID[count][0] = ord + 1; //+1 чтобы номер чекбокса начинался с 1
						//количество совпадающих билетов по первым цифрам
						//в последствии стравниваются билеты с удаленными билетами
						//на совпадение этих цифр, если совпадает увеличиваем счетчик
						deletedTicketsID[count++][1] = 1;
					}
				}
				
								
				if((deleteRequestFile = fopen("deleteRequestFile.txt", "w")) == NULL){
			       lr_output_message("Error: %s", "Не удалось открыть файл для записи запроса на удаление билетов");
			       return 0;
			    }
				
				for(count = 1; count <= lenghtArrayFlightID; count++)
				{
					FlightID = lr_paramarr_idx("arrayFlightID", count);
					//сравнение удаляющихся билетов с другими билетами по первым цифрам номера билета
					for(ord = 0; ord < numberTickets; ord++){
						//вытягиваем первые цифры билета удаления
						partFlightID = strtok(lr_eval_string(lr_paramarr_idx("arrayFlightID",deletedTicketsID[ord][0])), "-");
						//сравниваем с другим билетом
						result = strncmp(lr_eval_string(lr_paramarr_idx("arrayFlightID",count)),
						                partFlightID,
						                strlen(partFlightID));
						//если совпадают и номер билета не равен самому себе
						//увеличиваем счетчик
						if(result==0 & deletedTicketsID[ord][0] != count){
							deletedTicketsID[ord][1]+=1;
						}
					}
					//записываем тело запроса в файл
					//порядок билетов в теле запроса не важен
					//значения разделяются амперсандом
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
				//Читаем из файла тело запроса сгенерированное случайным образом
				//записываем тело в параметр "bodyPOSTRequest"
				{
					int res = lr_read_file("deleteRequestFile.txt", "bodyPOSTRequest", 0);
					if(res == -1){
						lr_output_message("Error: Не удалось считать тело запроса из файла");
						return 0;
					}
				}
			}
			//lr_end_transaction("file", LR_AUTO);
			

//3. Отмена бронирования
	
	
	lr_start_transaction("сancel_reservation");
	
	lr_think_time(5);

			web_add_header("Origin", 
				"http://localhost:1080");
	
			//вылавливаем первые цифры номера билета
			//для сравнения с удаленными билетами
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
	
			//Проверка удаления билетов
			{
				int lenghtTicketsPartID = atoi(lr_eval_string("{ticketsPartID_count}"));
				//identicalTicketsNum - хранит количество совпавших билетов по первым цифрам номера
				int count, ord, result, identicalTicketsNum;
				char * partFlightID;
				//Итерация по каждому удаленному билету
				for(ord = 0; ord < numberTickets; ord++){
					identicalTicketsNum = 0;
					//итерация по каждому билету после удаления
					for(count = 1; count <= lenghtTicketsPartID; count++){
						//Вытягиваем первые цифры билета
						partFlightID = strtok(lr_eval_string(lr_paramarr_idx("arrayFlightID",deletedTicketsID[ord][0])), "-");
						//проверяем совпадают ли первые цифры удаленного билета с билетами после удаления
						result = strcmp(partFlightID,
						                 lr_eval_string(lr_paramarr_idx("ticketsPartID",count)));
						//если совпадение есть
						//увеличиваем счетчик на 1
						//если счетчик будет больше чем изначально для удаленного билета deletedTicketsID[ord][1]
						//выдаем ошибку
						// !!! не учитывает если при проведении теста после удаления, другой скрипт купил билет идентичный
						// !!! удаленному билету в этом скрипте
						if(result==0){
							identicalTicketsNum +=1;
							if(identicalTicketsNum >= deletedTicketsID[ord][1])
								lr_end_transaction("сancel_reservation", LR_FAIL);
						}
					}
				}
			}

	lr_end_transaction("сancel_reservation", LR_AUTO);	
	
	
	
//4. Выход из системы

	click_sing_off_request();

	lr_end_transaction("UC_4_DeletingTickets", LR_AUTO);
	
	return 0;
}

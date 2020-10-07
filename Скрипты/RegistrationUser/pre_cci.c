# 1 "c:\\user\\github\\testing_web_tours\\\361\352\360\350\357\362\373\\registrationuser\\\\combined_RegistrationUser.c"
# 1 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h" 1
 
 












 











# 103 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"





















































		


		typedef unsigned size_t;
	
	
        
	

















	

 



















 
 
 
 
 


 
 
 
 
 
 














int     lr_start_transaction   (char * transaction_name);
int lr_start_sub_transaction          (char * transaction_name, char * trans_parent);
long lr_start_transaction_instance    (char * transaction_name, long parent_handle);
int   lr_start_cross_vuser_transaction		(char * transaction_name, char * trans_id_param); 



int     lr_end_transaction     (char * transaction_name, int status);
int lr_end_sub_transaction            (char * transaction_name, int status);
int lr_end_transaction_instance       (long transaction, int status);
int   lr_end_cross_vuser_transaction	(char * transaction_name, char * trans_id_param, int status);


 
typedef char* lr_uuid_t;
 



lr_uuid_t lr_generate_uuid();

 


int lr_generate_uuid_free(lr_uuid_t uuid);

 



int lr_generate_uuid_on_buf(lr_uuid_t buf);

   
# 273 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
int lr_start_distributed_transaction  (char * transaction_name, lr_uuid_t correlator, long timeout  );

   







int lr_end_distributed_transaction  (lr_uuid_t correlator, int status);


double lr_stop_transaction            (char * transaction_name);
double lr_stop_transaction_instance   (long parent_handle);


void lr_resume_transaction           (char * trans_name);
void lr_resume_transaction_instance  (long trans_handle);


int lr_update_transaction            (const char *trans_name);


 
void lr_wasted_time(long time);


 
int lr_set_transaction(const char *name, double duration, int status);
 
long lr_set_transaction_instance(const char *name, double duration, int status, long parent_handle);


int   lr_user_data_point                      (char *, double);
long lr_user_data_point_instance                   (char *, double, long);
 



int lr_user_data_point_ex(const char *dp_name, double value, int log_flag);
long lr_user_data_point_instance_ex(const char *dp_name, double value, long parent_handle, int log_flag);


int lr_transaction_add_info      (const char *trans_name, char *info);
int lr_transaction_instance_add_info   (long trans_handle, char *info);
int lr_dpoint_add_info           (const char *dpoint_name, char *info);
int lr_dpoint_instance_add_info        (long dpoint_handle, char *info);


double lr_get_transaction_duration       (char * trans_name);
double lr_get_trans_instance_duration    (long trans_handle);
double lr_get_transaction_think_time     (char * trans_name);
double lr_get_trans_instance_think_time  (long trans_handle);
double lr_get_transaction_wasted_time    (char * trans_name);
double lr_get_trans_instance_wasted_time (long trans_handle);
int    lr_get_transaction_status		 (char * trans_name);
int	   lr_get_trans_instance_status		 (long trans_handle);

 



int lr_set_transaction_status(int status);

 



int lr_set_transaction_status_by_name(int status, const char *trans_name);
int lr_set_transaction_instance_status(int status, long trans_handle);


typedef void* merc_timer_handle_t;
 

merc_timer_handle_t lr_start_timer();
double lr_end_timer(merc_timer_handle_t timer_handle);


 
 
 
 
 
 











 



int   lr_rendezvous  (char * rendezvous_name);
 




int   lr_rendezvous_ex (char * rendezvous_name);



 
 
 
 
 
char *lr_get_vuser_ip (void);
void   lr_whoami (int *vuser_id, char ** sgroup, int *scid);
char *	  lr_get_host_name (void);
char *	  lr_get_master_host_name (void);

 
long     lr_get_attrib_long	(char * attr_name);
char *   lr_get_attrib_string	(char * attr_name);
double   lr_get_attrib_double      (char * attr_name);

char * lr_paramarr_idx(const char * paramArrayName, unsigned int index);
char * lr_paramarr_random(const char * paramArrayName);
int    lr_paramarr_len(const char * paramArrayName);

int	lr_param_unique(const char * paramName);
int lr_param_sprintf(const char * paramName, const char * format, ...);


 
 
static void *ci_this_context = 0;






 








void lr_continue_on_error (int lr_continue);
char *   lr_unmask (const char *EncodedString);
char *   lr_decrypt (const char *EncodedString);


 
 
 
 
 
 



 







 















void   lr_abort (void);
void lr_exit(int exit_option, int exit_status);
void lr_abort_ex (unsigned long flags);

void   lr_peek_events (void);


 
 
 
 
 


void   lr_think_time (double secs);

 


void lr_force_think_time (double secs);


 
 
 
 
 



















int   lr_msg (char * fmt, ...);
int   lr_debug_message (unsigned int msg_class,
									    char * format,
										...);
# 513 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
void   lr_new_prefix (int type,
                                 char * filename,
                                 int line);
# 516 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
int   lr_log_message (char * fmt, ...);
int   lr_message (char * fmt, ...);
int   lr_error_message (char * fmt, ...);
int   lr_output_message (char * fmt, ...);
int   lr_vuser_status_message (char * fmt, ...);
int   lr_error_message_without_fileline (char * fmt, ...);
int   lr_fail_trans_with_error (char * fmt, ...);

 
 
 
 
 
# 540 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"

 
 
 
 
 





int   lr_next_row ( char * table);
int lr_advance_param ( char * param);



														  
														  

														  
														  

													      
 


char *   lr_eval_string (char * str);
int   lr_eval_string_ext (const char *in_str,
                                     unsigned long const in_len,
                                     char ** const out_str,
                                     unsigned long * const out_len,
                                     unsigned long const options,
                                     const char *file,
								     long const line);
# 574 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
void   lr_eval_string_ext_free (char * * pstr);

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
int lr_param_increment (char * dst_name,
                              char * src_name);
# 597 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"













											  
											  

											  
											  
											  

int	  lr_save_var (char *              param_val,
							  unsigned long const param_val_len,
							  unsigned long const options,
							  char *			  param_name);
# 621 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
int   lr_save_string (const char * param_val, const char * param_name);



int   lr_set_custom_error_message (const char * param_val, ...);

int   lr_remove_custom_error_message ();


int   lr_free_parameter (const char * param_name);
int   lr_save_int (const int param_val, const char * param_name);
int   lr_save_timestamp (const char * tmstampParam, ...);
int   lr_save_param_regexp (const char *bufferToScan, unsigned int bufSize, ...);

int   lr_convert_double_to_integer (const char *source_param_name, const char * target_param_name);
int   lr_convert_double_to_double (const char *source_param_name, const char *format_string, const char * target_param_name);

 
 
 
 
 
 
# 700 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
void   lr_save_datetime (const char *format, int offset, const char *name);









 











 
 
 
 
 






 



char * lr_error_context_get_entry (char * key);

 



long   lr_error_context_get_error_id (void);


 
 
 

int lr_table_get_rows_num (char * param_name);

int lr_table_get_cols_num (char * param_name);

char * lr_table_get_cell_by_col_index (char * param_name, int row, int col);

char * lr_table_get_cell_by_col_name (char * param_name, int row, const char* col_name);

int lr_table_get_column_name_by_index (char * param_name, int col, 
											char * * const col_name,
											size_t * col_name_len);
# 761 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"

int lr_table_get_column_name_by_index_free (char * col_name);

 
 
 
 
# 776 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
int   lr_zip (const char* param1, const char* param2);
int   lr_unzip (const char* param1, const char* param2);

 
 
 
 
 
 
 
 

 
 
 
 
 
 
int   lr_param_substit (char * file,
                                   int const line,
                                   char * in_str,
                                   size_t const in_len,
                                   char * * const out_str,
                                   size_t * const out_len);
# 800 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
void   lr_param_substit_free (char * * pstr);


 
# 812 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"





char *   lrfnc_eval_string (char * str,
                                      char * file_name,
                                      long const line_num);
# 820 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"


int   lrfnc_save_string ( const char * param_val,
                                     const char * param_name,
                                     const char * file_name,
                                     long const line_num);
# 826 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"

int   lrfnc_free_parameter (const char * param_name );







typedef struct _lr_timestamp_param
{
	int iDigits;
}lr_timestamp_param;

extern const lr_timestamp_param default_timestamp_param;

int   lrfnc_save_timestamp (const char * param_name, const lr_timestamp_param* time_param);

int lr_save_searched_string(char * buffer, long buf_size, unsigned int occurrence,
			    char * search_string, int offset, unsigned int param_val_len, 
			    char * param_name);

 
char *   lr_string (char * str);

 
# 929 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"

int   lr_save_value (char * param_val,
                                unsigned long const param_val_len,
                                unsigned long const options,
                                char * param_name,
                                char * file_name,
                                long const line_num);
# 936 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"


 
 
 
 
 











int   lr_printf (char * fmt, ...);
 
int   lr_set_debug_message (unsigned int msg_class,
                                       unsigned int swtch);
# 958 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
unsigned int   lr_get_debug_message (void);


 
 
 
 
 

void   lr_double_think_time ( double secs);
void   lr_usleep (long);


 
 
 
 
 
 




int *   lr_localtime (long offset);


int   lr_send_port (long port);


# 1034 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"



struct _lr_declare_identifier{
	char signature[24];
	char value[128];
};

int   lr_pt_abort (void);

void vuser_declaration (void);






# 1063 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"


# 1075 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/lrun.h"
















 
 
 
 
 







int    _lr_declare_transaction   (char * transaction_name);


 
 
 
 
 







int   _lr_declare_rendezvous  (char * rendezvous_name);

 
 
 
 
 


typedef int PVCI;






typedef int VTCERR;









PVCI   vtc_connect(char * servername, int portnum, int options);
VTCERR   vtc_disconnect(PVCI pvci);
VTCERR   vtc_get_last_error(PVCI pvci);
VTCERR   vtc_query_column(PVCI pvci, char * columnName, int columnIndex, char * *outvalue);
VTCERR   vtc_query_row(PVCI pvci, int rowIndex, char * **outcolumns, char * **outvalues);
VTCERR   vtc_send_message(PVCI pvci, char * column, char * message, unsigned short *outRc);
VTCERR   vtc_send_if_unique(PVCI pvci, char * column, char * message, unsigned short *outRc);
VTCERR   vtc_send_row1(PVCI pvci, char * columnNames, char * messages, char * delimiter, unsigned char sendflag, unsigned short *outUpdates);
VTCERR   vtc_update_message(PVCI pvci, char * column, int index , char * message, unsigned short *outRc);
VTCERR   vtc_update_message_ifequals(PVCI pvci, char * columnName, int index,	char * message, char * ifmessage, unsigned short 	*outRc);
VTCERR   vtc_update_row1(PVCI pvci, char * columnNames, int index , char * messages, char * delimiter, unsigned short *outUpdates);
VTCERR   vtc_retrieve_message(PVCI pvci, char * column, char * *outvalue);
VTCERR   vtc_retrieve_messages1(PVCI pvci, char * columnNames, char * delimiter, char * **outvalues);
VTCERR   vtc_retrieve_row(PVCI pvci, char * **outcolumns, char * **outvalues);
VTCERR   vtc_rotate_message(PVCI pvci, char * column, char * *outvalue, unsigned char sendflag);
VTCERR   vtc_rotate_messages1(PVCI pvci, char * columnNames, char * delimiter, char * **outvalues, unsigned char sendflag);
VTCERR   vtc_rotate_row(PVCI pvci, char * **outcolumns, char * **outvalues, unsigned char sendflag);
VTCERR   vtc_increment(PVCI pvci, char * column, int index , int incrValue, int *outValue);
VTCERR   vtc_clear_message(PVCI pvci, char * column, int index , unsigned short *outRc);
VTCERR   vtc_clear_column(PVCI pvci, char * column, unsigned short *outRc);
VTCERR   vtc_ensure_index(PVCI pvci, char * column, unsigned short *outRc);
VTCERR   vtc_drop_index(PVCI pvci, char * column, unsigned short *outRc);
VTCERR   vtc_clear_row(PVCI pvci, int rowIndex, unsigned short *outRc);
VTCERR   vtc_create_column(PVCI pvci, char * column,unsigned short *outRc);
VTCERR   vtc_column_size(PVCI pvci, char * column, int *size);
void   vtc_free(char * msg);
void   vtc_free_list(char * *msglist);

VTCERR   lrvtc_connect(char * servername, int portnum, int options);
VTCERR   lrvtc_disconnect();
VTCERR   lrvtc_query_column(char * columnName, int columnIndex);
VTCERR   lrvtc_query_row(int columnIndex);
VTCERR   lrvtc_send_message(char * columnName, char * message);
VTCERR   lrvtc_send_if_unique(char * columnName, char * message);
VTCERR   lrvtc_send_row1(char * columnNames, char * messages, char * delimiter, unsigned char sendflag);
VTCERR   lrvtc_update_message(char * columnName, int index , char * message);
VTCERR   lrvtc_update_message_ifequals(char * columnName, int index, char * message, char * ifmessage);
VTCERR   lrvtc_update_row1(char * columnNames, int index , char * messages, char * delimiter);
VTCERR   lrvtc_retrieve_message(char * columnName);
VTCERR   lrvtc_retrieve_messages1(char * columnNames, char * delimiter);
VTCERR   lrvtc_retrieve_row();
VTCERR   lrvtc_rotate_message(char * columnName, unsigned char sendflag);
VTCERR   lrvtc_rotate_messages1(char * columnNames, char * delimiter, unsigned char sendflag);
VTCERR   lrvtc_rotate_row(unsigned char sendflag);
VTCERR   lrvtc_increment(char * columnName, int index , int incrValue);
VTCERR   lrvtc_noop();
VTCERR   lrvtc_clear_message(char * columnName, int index);
VTCERR   lrvtc_clear_column(char * columnName); 
VTCERR   lrvtc_ensure_index(char * columnName); 
VTCERR   lrvtc_drop_index(char * columnName); 
VTCERR   lrvtc_clear_row(int rowIndex);
VTCERR   lrvtc_create_column(char * columnName);
VTCERR   lrvtc_column_size(char * columnName);



 
 
 
 
 

 
int lr_enable_ip_spoofing();
int lr_disable_ip_spoofing();


 




int lr_convert_string_encoding(char * sourceString, char * fromEncoding, char * toEncoding, char * paramName);
int lr_read_file(const char *filename, const char *outputParam, int continueOnError);

int lr_get_char_count(const char * string);


 
int lr_db_connect (char * pFirstArg, ...);
int lr_db_disconnect (char * pFirstArg,	...);
int lr_db_executeSQLStatement (char * pFirstArg, ...);
int lr_db_dataset_action(char * pFirstArg, ...);
int lr_checkpoint(char * pFirstArg,	...);
int lr_db_getvalue(char * pFirstArg, ...);







 
 



















# 1 "c:\\user\\github\\testing_web_tours\\\361\352\360\350\357\362\373\\registrationuser\\\\combined_RegistrationUser.c" 2

# 1 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/SharedParameter.h" 1



 
 
 
 
# 100 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/SharedParameter.h"






typedef int PVCI2;






typedef int VTCERR2;


 
 
 

 
extern PVCI2    vtc_connect(char *servername, int portnum, int options);
extern VTCERR2  vtc_disconnect(PVCI2 pvci);
extern VTCERR2  vtc_get_last_error(PVCI2 pvci);

 
extern VTCERR2  vtc_query_column(PVCI2 pvci, char *columnName, int columnIndex, char **outvalue);
extern VTCERR2  vtc_query_row(PVCI2 pvci, int columnIndex, char ***outcolumns, char ***outvalues);
extern VTCERR2  vtc_send_message(PVCI2 pvci, char *column, char *message, unsigned short *outRc);
extern VTCERR2  vtc_send_if_unique(PVCI2 pvci, char *column, char *message, unsigned short *outRc);
extern VTCERR2  vtc_send_row1(PVCI2 pvci, char *columnNames, char *messages, char *delimiter,  unsigned char sendflag, unsigned short *outUpdates);
extern VTCERR2  vtc_update_message(PVCI2 pvci, char *column, int index , char *message, unsigned short *outRc);
extern VTCERR2  vtc_update_message_ifequals(PVCI2 pvci, char	*columnName, int index,	char *message, char	*ifmessage,	unsigned short 	*outRc);
extern VTCERR2  vtc_update_row1(PVCI2 pvci, char *columnNames, int index , char *messages, char *delimiter, unsigned short *outUpdates);
extern VTCERR2  vtc_retrieve_message(PVCI2 pvci, char *column, char **outvalue);
extern VTCERR2  vtc_retrieve_messages1(PVCI2 pvci, char *columnNames, char *delimiter, char ***outvalues);
extern VTCERR2  vtc_retrieve_row(PVCI2 pvci, char ***outcolumns, char ***outvalues);
extern VTCERR2  vtc_rotate_message(PVCI2 pvci, char *column, char **outvalue, unsigned char sendflag);
extern VTCERR2  vtc_rotate_messages1(PVCI2 pvci, char *columnNames, char *delimiter, char ***outvalues, unsigned char sendflag);
extern VTCERR2  vtc_rotate_row(PVCI2 pvci, char ***outcolumns, char ***outvalues, unsigned char sendflag);
extern VTCERR2	vtc_increment(PVCI2 pvci, char *column, int index , int incrValue, int *outValue);
extern VTCERR2  vtc_clear_message(PVCI2 pvci, char *column, int index , unsigned short *outRc);
extern VTCERR2  vtc_clear_column(PVCI2 pvci, char *column, unsigned short *outRc);

extern VTCERR2  vtc_clear_row(PVCI2 pvci, int rowIndex, unsigned short *outRc);

extern VTCERR2  vtc_create_column(PVCI2 pvci, char *column,unsigned short *outRc);
extern VTCERR2  vtc_column_size(PVCI2 pvci, char *column, int *size);
extern VTCERR2  vtc_ensure_index(PVCI2 pvci, char *column, unsigned short *outRc);
extern VTCERR2  vtc_drop_index(PVCI2 pvci, char *column, unsigned short *outRc);

extern VTCERR2  vtc_noop(PVCI2 pvci);

 
extern void vtc_free(char *msg);
extern void vtc_free_list(char **msglist);

 


 




 




















 




 
 
 

extern VTCERR2  lrvtc_connect(char *servername, int portnum, int options);
extern VTCERR2  lrvtc_disconnect();
extern VTCERR2  lrvtc_query_column(char *columnName, int columnIndex);
extern VTCERR2  lrvtc_query_row(int columnIndex);
extern VTCERR2  lrvtc_send_message(char *columnName, char *message);
extern VTCERR2  lrvtc_send_if_unique(char *columnName, char *message);
extern VTCERR2  lrvtc_send_row1(char *columnNames, char *messages, char *delimiter,  unsigned char sendflag);
extern VTCERR2  lrvtc_update_message(char *columnName, int index , char *message);
extern VTCERR2  lrvtc_update_message_ifequals(char *columnName, int index, char 	*message, char *ifmessage);
extern VTCERR2  lrvtc_update_row1(char *columnNames, int index , char *messages, char *delimiter);
extern VTCERR2  lrvtc_retrieve_message(char *columnName);
extern VTCERR2  lrvtc_retrieve_messages1(char *columnNames, char *delimiter);
extern VTCERR2  lrvtc_retrieve_row();
extern VTCERR2  lrvtc_rotate_message(char *columnName, unsigned char sendflag);
extern VTCERR2  lrvtc_rotate_messages1(char *columnNames, char *delimiter, unsigned char sendflag);
extern VTCERR2  lrvtc_rotate_row(unsigned char sendflag);
extern VTCERR2  lrvtc_increment(char *columnName, int index , int incrValue);
extern VTCERR2  lrvtc_clear_message(char *columnName, int index);
extern VTCERR2  lrvtc_clear_column(char *columnName);
extern VTCERR2  lrvtc_clear_row(int rowIndex);
extern VTCERR2  lrvtc_create_column(char *columnName);
extern VTCERR2  lrvtc_column_size(char *columnName);
extern VTCERR2  lrvtc_ensure_index(char *columnName);
extern VTCERR2  lrvtc_drop_index(char *columnName);

extern VTCERR2  lrvtc_noop();

 
 
 

                               


 
 
 





















# 2 "c:\\user\\github\\testing_web_tours\\\361\352\360\350\357\362\373\\registrationuser\\\\combined_RegistrationUser.c" 2

# 1 "globals.h" 1



 
 

# 1 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/web_api.h" 1







# 1 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/as_web.h" 1



























































 




 



 











 





















 
 
 

  int
	web_add_filter(
		const char *		mpszArg,
		...
	);									 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_add_auto_filter(
		const char *		mpszArg,
		...
	);									 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
	
  int
	web_add_auto_header(
		const char *		mpszHeader,
		const char *		mpszValue);

  int
	web_add_header(
		const char *		mpszHeader,
		const char *		mpszValue);
  int
	web_add_cookie(
		const char *		mpszCookie);
  int
	web_cleanup_auto_headers(void);
  int
	web_cleanup_cookies(void);
  int
	web_concurrent_end(
		const char * const	mpszReserved,
										 
		...								 
	);
  int
	web_concurrent_start(
		const char * const	mpszConcurrentGroupName,
										 
										 
		...								 
										 
	);
  int
	web_create_html_param(
		const char *		mpszParamName,
		const char *		mpszLeftDelim,
		const char *		mpszRightDelim);
  int
	web_create_html_param_ex(
		const char *		mpszParamName,
		const char *		mpszLeftDelim,
		const char *		mpszRightDelim,
		const char *		mpszNum);
  int
	web_custom_request(
		const char *		mpszReqestName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	spdy_custom_request(
		const char *		mpszReqestName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_disable_keep_alive(void);
  int
	web_enable_keep_alive(void);
  int
	web_find(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_get_int_property(
		const int			miHttpInfoType);
  int
	web_image(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_image_check(
		const char *		mpszName,
		...);
  int
	web_java_check(
		const char *		mpszName,
		...);
  int
	web_link(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

	
  int
	web_global_verification(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
  int
	web_reg_find(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										 
										 
				
  int
	web_reg_save_param(
		const char *		mpszParamName,
		...);							 
										 
										 
										 
										 
										 
										 

  int
	web_convert_param(
		const char * 		mpszParamName, 
										 
		...);							 
										 
										 


										 

										 
  int
	web_remove_auto_filter(
		const char *		mpszArg,
		...
	);									 
										 
				
  int
	web_remove_auto_header(
		const char *		mpszHeaderName,
		...);							 
										 



  int
	web_remove_cookie(
		const char *		mpszCookie);

  int
	web_save_header(
		const char *		mpszType,	 
		const char *		mpszName);	 
  int
	web_set_certificate(
		const char *		mpszIndex);
  int
	web_set_certificate_ex(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_set_connections_limit(
		const char *		mpszLimit);
  int
	web_set_max_html_param_len(
		const char *		mpszLen);
  int
	web_set_max_retries(
		const char *		mpszMaxRetries);
  int
	web_set_proxy(
		const char *		mpszProxyHost);
  int
	web_set_pac(
		const char *		mpszPacUrl);
  int
	web_set_proxy_bypass(
		const char *		mpszBypass);
  int
	web_set_secure_proxy(
		const char *		mpszProxyHost);
  int
	web_set_sockets_option(
		const char *		mpszOptionID,
		const char *		mpszOptionValue
	);
  int
	web_set_option(
		const char *		mpszOptionID,
		const char *		mpszOptionValue,
		...								 
	);
  int
	web_set_timeout(
		const char *		mpszWhat,
		const char *		mpszTimeout);
  int
	web_set_user(
		const char *		mpszUserName,
		const char *		mpszPwd,
		const char *		mpszHost);

  int
	web_sjis_to_euc_param(
		const char *		mpszParamName,
										 
		const char *		mpszParamValSjis);
										 

  int
	web_submit_data(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	spdy_submit_data(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_submit_form(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_url(
		const char *		mpszUrlName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	spdy_url(
		const char *		mpszUrlName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int 
	web_set_proxy_bypass_local(
		const char * mpszNoLocal
		);

  int 
	web_cache_cleanup(void);

  int
	web_create_html_query(
		const char* mpszStartQuery,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int 
	web_create_radio_button_param(
		const char *NameFiled,
		const char *NameAndVal,
		const char *ParamName
		);

  int
	web_convert_from_formatted(
		const char * mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										
  int
	web_convert_to_formatted(
		const char * mpszArg1,
		...);							 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_ex(
		const char * mpszParamName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_xpath(
		const char * mpszParamName,
		...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_json(
		const char * mpszParamName,
		...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_regexp(
		 const char * mpszParamName,
		 ...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_attrib(
		const char * mpszParamName,
		...);
										 
										 
										 
										 
										 
										 
										 		
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_js_run(
		const char * mpszCode,
		...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_js_reset(void);

  int
	web_convert_date_param(
		const char * 		mpszParamName,
		...);










# 789 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/as_web.h"


# 802 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/as_web.h"



























# 840 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/as_web.h"

 
 
 


  int
	FormSubmit(
		const char *		mpszFormName,
		...);
  int
	InitWebVuser(void);
  int
	SetUser(
		const char *		mpszUserName,
		const char *		mpszPwd,
		const char *		mpszHost);
  int
	TerminateWebVuser(void);
  int
	URL(
		const char *		mpszUrlName);
























# 908 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/as_web.h"


  int
	web_rest(
		const char *		mpszReqestName,
		...);							 
										 
										 
										 
										 

  int
web_stream_open(
	const char *		mpszArg1,
	...
);
  int
	web_stream_wait(
		const char *		mpszArg1,
		...
	);

  int
	web_stream_close(
		const char *		mpszArg1,
		...
	);

  int
web_stream_play(
	const char *		mpszArg1,
	...
	);

  int
web_stream_pause(
	const char *		mpszArg1,
	...
	);

  int
web_stream_seek(
	const char *		mpszArg1,
	...
	);

  int
web_stream_get_param_int(
	const char*			mpszStreamID,
	const int			miStateType
	);

  double
web_stream_get_param_double(
	const char*			mpszStreamID,
	const int			miStateType
	);

  int
web_stream_get_param_string(
	const char*			mpszStreamID,
	const int			miStateType,
	const char*			mpszParameterName
	);

  int
web_stream_set_param_int(
	const char*			mpszStreamID,
	const int			miStateType,
	const int			miStateValue
	);

  int
web_stream_set_param_double(
	const char*			mpszStreamID,
	const int			miStateType,
	const double		mdfStateValue
	);

  int
web_stream_set_custom_mpd(
	const char*			mpszStreamID,
	const char*			aMpdBuf
	);

 
 
 






# 9 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/web_api.h" 2

















 







 















  int
	web_reg_add_cookie(
		const char *		mpszCookie,
		...);							 
										 

  int
	web_report_data_point(
		const char *		mpszEventType,
		const char *		mpszEventName,
		const char *		mpszDataPointName,
		const char *		mpszLAST);	 
										 
										 
										 

  int
	web_text_link(
		const char *		mpszStepName,
		...);

  int
	web_element(
		const char *		mpszStepName,
		...);

  int
	web_image_link(
		const char *		mpszStepName,
		...);

  int
	web_static_image(
		const char *		mpszStepName,
		...);

  int
	web_image_submit(
		const char *		mpszStepName,
		...);

  int
	web_button(
		const char *		mpszStepName,
		...);

  int
	web_edit_field(
		const char *		mpszStepName,
		...);

  int
	web_radio_group(
		const char *		mpszStepName,
		...);

  int
	web_check_box(
		const char *		mpszStepName,
		...);

  int
	web_list(
		const char *		mpszStepName,
		...);

  int
	web_text_area(
		const char *		mpszStepName,
		...);

  int
	web_map_area(
		const char *		mpszStepName,
		...);

  int
	web_eval_java_script(
		const char *		mpszStepName,
		...);

  int
	web_reg_dialog(
		const char *		mpszArg1,
		...);

  int
	web_reg_cross_step_download(
		const char *		mpszArg1,
		...);

  int
	web_browser(
		const char *		mpszStepName,
		...);

  int
	web_control(
		const char *		mpszStepName,
		...);

  int
	web_set_rts_key(
		const char *		mpszArg1,
		...);

  int
	web_save_param_length(
		const char * 		mpszParamName,
		...);

  int
	web_save_timestamp_param(
		const char * 		mpszParamName,
		...);

  int
	web_load_cache(
		const char *		mpszStepName,
		...);							 
										 

  int
	web_dump_cache(
		const char *		mpszStepName,
		...);							 
										 
										 

  int
	web_reg_find_in_log(
		const char *		mpszArg1,
		...);							 
										 
										 

  int
	web_get_sockets_info(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 

  int
	web_add_cookie_ex(
		const char *		mpszArg1,
		...);							 
										 
										 
										 

  int
	web_hook_java_script(
		const char *		mpszArg1,
		...);							 
										 
										 
										 

 
 
 
 
 
 
 
 
 
 
 
 
  int
	web_reg_async_attributes(
		const char *		mpszArg,
		...
	);

 
 
 
 
 
 
  int
	web_sync(
		 const char *		mpszArg1,
		 ...
	);

 
 
 
 
  int
	web_stop_async(
		const char *		mpszArg1,
		...
	);

 
 
 
 
 

 
 
 

typedef enum WEB_ASYNC_CB_RC_ENUM_T
{
	WEB_ASYNC_CB_RC_OK,				 

	WEB_ASYNC_CB_RC_ABORT_ASYNC_NOT_ERROR,
	WEB_ASYNC_CB_RC_ABORT_ASYNC_ERROR,
										 
										 
										 
										 
	WEB_ASYNC_CB_RC_ENUM_COUNT
} WEB_ASYNC_CB_RC_ENUM;

 
 
 

typedef enum WEB_CONVERS_CB_CALL_REASON_ENUM_T
{
	WEB_CONVERS_CB_CALL_REASON_BUFFER_RECEIVED,
	WEB_CONVERS_CB_CALL_REASON_END_OF_TASK,

	WEB_CONVERS_CB_CALL_REASON_ENUM_COUNT
} WEB_CONVERS_CB_CALL_REASON_ENUM;

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

typedef
int														 
	(*RequestCB_t)();

typedef
int														 
	(*ResponseBodyBufferCB_t)(
		  const char *		aLastBufferStr,
		  int				aLastBufferLen,
		  const char *		aAccumulatedStr,
		  int				aAccumulatedLen,
		  int				aHttpStatusCode);

typedef
int														 
	(*ResponseCB_t)(
		  const char *		aResponseHeadersStr,
		  int				aResponseHeadersLen,
		  const char *		aResponseBodyStr,
		  int				aResponseBodyLen,
		  int				aHttpStatusCode);

typedef
int														 
	(*ResponseHeadersCB_t)(
		  int				aHttpStatusCode,
		  const char *		aAccumulatedHeadersStr,
		  int				aAccumulatedHeadersLen);



 
 
 

typedef enum WEB_CONVERS_UTIL_RC_ENUM_T
{
	WEB_CONVERS_UTIL_RC_OK,
	WEB_CONVERS_UTIL_RC_CONVERS_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_TASK_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_INFO_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_INFO_UNAVIALABLE,
	WEB_CONVERS_UTIL_RC_INVALID_ARGUMENT,

	WEB_CONVERS_UTIL_RC_ENUM_COUNT
} WEB_CONVERS_UTIL_RC_ENUM;

 
 
 

  int					 
	web_util_set_request_url(
		  const char *		aUrlStr);

  int					 
	web_util_set_request_body(
		  const char *		aRequestBodyStr);

  int					 
	web_util_set_formatted_request_body(
		  const char *		aRequestBodyStr);


 
 
 
 
 

 
 
 
 
 

 
 
 
 
 
 
 
 

 
 
  int
web_websocket_connect(
		 const char *	mpszArg1,
		 ...
		 );


 
 
 
 
 																						
  int
web_websocket_send(
	   const char *		mpszArg1,
		...
	   );

 
 
 
 
 
 
  int
web_websocket_close(
		const char *	mpszArg1,
		...
		);

 
typedef
void														
(*OnOpen_t)(
			  const char* connectionID,  
			  const char * responseHeader,  
			  int length  
);

typedef
void														
(*OnMessage_t)(
	  const char* connectionID,  
	  int isbinary,  
	  const char * data,  
	  int length  
	);

typedef
void														
(*OnError_t)(
	  const char* connectionID,  
	  const char * message,  
	  int length  
	);

typedef
void														
(*OnClose_t)(
	  const char* connectionID,  
	  int isClosedByClient,  
	  int code,  
	  const char* reason,  
	  int length  
	 );
 
 
 
 
 





# 7 "globals.h" 2

# 1 "lrw_custom_body.h" 1
 




# 8 "globals.h" 2

# 1 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/string.h" 1
 








# 1 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/stddef.h" 1













typedef unsigned int uintptr_t;








typedef int intptr_t;








typedef int ptrdiff_t;





typedef unsigned short wchar_t;




typedef long time_t;




typedef long clock_t;




typedef wchar_t wint_t;
typedef wchar_t wctype_t;




typedef char *	va_list;



 





# 10 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/string.h" 2










void *	 memchr(const void *, int, size_t);
int 	 memcmp(const void *, const void *, size_t);
void * 	 memcpy(void *, const void *, size_t);
void *	 memmove(void *, const void *, size_t);
void *	 memset(void *, int, size_t);

char 	*strcat(char *, const char *);
char 	*strchr(const char *, int);
int	 strcmp(const char *, const char *);
int	 strcoll(const char *, const char *);
char 	*strcpy(char *, const char *);
size_t	 strcspn(const char *, const char *);
char 	*strerror(int);
size_t	 strlen(const char *);
char 	*strncat(char *, const char *, size_t);
int	 strncmp(const char *, const char *, size_t);
char 	*strncpy(char *, const char *, size_t);
char 	*strpbrk(const char *, const char *);
char 	*strrchr(const char *, int);
size_t	 strspn(const char *, const char *);
char 	*strstr(const char *, const char *);
char 	*strtok(char *, const char *);

void *	 memccpy(void *, const void *, int, size_t);
int	 strcmpi(const char *, const char *);
char 	*strdup(const char *);
int	 strnicmp(const char *, const char *, size_t);
void	 swab(const char *, char *, size_t);

# 9 "globals.h" 2

# 1 "..\\QueryLibrary\\generate_login_pass.h" 1



# 1 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/time.h" 1

 








# 1 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/stddef.h" 1






























































 





# 11 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/time.h" 2




struct tm
{
  int	tm_sec;
  int	tm_min;
  int	tm_hour;
  int	tm_mday;
  int	tm_mon;
  int	tm_year;
  int	tm_wday;
  int	tm_yday;
  int	tm_isdst;
};








char	  *_asctime_r(struct tm *_tblock, void *_p);


clock_t clock(void);
double	  _difftime32(time_t _time2, time_t _time1);
time_t _mktime32(struct tm *_timeptr);
time_t _time32(time_t *_timer);
char	  *asctime(const struct tm *_tblock);
char	  *_ctime32(const time_t *_time);
struct tm *_gmtime32(const time_t *_timer);
struct tm *_localtime32(const time_t *_timer);
unsigned int   strftime(char *_s, size_t _maxsize, char *_fmt, struct tm *_t);



# 4 "..\\QueryLibrary\\generate_login_pass.h" 2

# 1 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/assert.h" 1
 










int _assertfail(char *__msg, char *__cond, char *__file, int __line);


# 5 "..\\QueryLibrary\\generate_login_pass.h" 2

# 1 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/stdlib.h" 1
 





# 1 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/stddef.h" 1






























































 





# 7 "C:\\Program Files (x86)\\HPE\\LoadRunner\\include/stdlib.h" 2

typedef struct
{
  int quot;  
  int rem;  
} div_t;

typedef struct
{
  long quot;  
  long rem;  
} ldiv_t;
















void	abort(void);
int	abs(int);
double	atof(const char *_nptr);
int	atoi(const char *_nptr);
long	atol(const char *_nptr);
void *	bsearch(const void * _key,
		       const void * _base,
		       size_t _nmemb,
		       size_t _size,
		       int (*_compar)(const void *, const void *));
void *	calloc(size_t _nmemb, size_t _size);
div_t	div(int _numer, int _denom);
void	exit(int _status);
void	free(void *);
char *  getenv(const char *_string);
long	labs(long);
ldiv_t	ldiv(long _numer, long _denom);
void *	malloc(size_t _size);
void	qsort(void * _base, size_t _nmemb, size_t _size, int(*_compar)(const void *, const void *));
int	rand(void);
void *	realloc(void * _r, size_t _size);
void	srand(unsigned _seed);
double	strtod(const char *_n, char **_endvoid);
long	strtol(const char *_n, char **_endvoid, int _base);
unsigned long strtoul(const char *_n, char **_end, int _base);
int	system(const char *_string);

int	putenv(const char *_string);

char *	_gcvt(double,int,char *);
char *	_fcvt(double,int,int *,int *);
char *	_ecvt(double,int,int *,int *);


# 6 "..\\QueryLibrary\\generate_login_pass.h" 2


 

 
 
 

 



 
 
int stochasticMatrix[52][52 + 1] = {
    # 1 "..\\Parameters\\stochastic_matrix.txt" 1
{733,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,22,5,53,3,4,17,3,24,4,7,144,53,185,0,8,0,85,27,16,42,14,0,1,5,7},{420,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,64,0,2,0,143,0,0,6,33,1,0,22,0,3,27,0,1,92,1,0,23,1,0,0,1,0},{685,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,198,0,0,0,36,0,0,186,17,0,0,69,0,0,127,0,0,25,0,1,6,0,0,0,19,1},{493,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,132,0,0,1,128,0,0,5,55,2,0,0,0,3,103,3,0,17,0,0,27,2,4,0,9,1},{379,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,6,2,36,0,2,0,2,6,0,1,113,50,16,3,1,0,44,23,14,11,29,1,1,3,2},{251,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,71,0,0,0,37,0,0,0,30,0,0,33,0,0,10,0,1,57,1,0,8,0,3,0,0,0},{362,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,57,0,0,0,86,0,0,5,61,0,0,24,0,1,24,0,0,40,0,0,43,0,18,0,2,1},{312,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,97,0,0,0,92,0,0,0,26,0,0,0,0,0,51,1,2,3,3,1,27,0,1,0,8,0},{146,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,10,0,1,3,1,0,1,2,16,7,27,6,0,0,15,24,4,0,11,3,0,1,5},{480,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,141,0,0,1,102,0,0,0,23,0,0,0,0,0,147,0,0,2,1,0,60,0,0,0,1,0},{453,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,195,0,0,0,72,0,0,9,75,1,0,8,0,1,28,0,0,30,0,1,14,0,8,0,11,0},{539,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,103,0,0,0,118,0,0,0,119,2,0,1,0,0,99,1,0,1,2,0,53,0,0,0,39,0},{821,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,445,0,2,0,129,1,0,0,138,0,1,0,0,0,64,0,0,1,0,0,21,0,0,0,19,0},{296,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,102,0,0,0,57,0,6,3,59,1,0,0,0,0,60,0,0,0,0,0,6,0,0,0,2,0},{109,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,11,0,3,1,1,0,0,3,22,3,5,2,9,0,25,5,12,1,1,1,0,0,2},{276,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,95,0,1,1,56,0,0,34,34,0,0,0,0,0,13,0,0,35,0,0,7,0,0,0,0,0},{23,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,20,0,0,0,0,0},{462,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,110,0,3,0,71,0,0,15,51,0,0,0,0,0,172,0,0,0,0,0,34,0,0,0,5,0},{652,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,118,0,14,0,54,0,0,185,69,0,5,1,2,2,40,5,0,4,0,67,59,3,4,0,20,0},{379,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,92,0,2,1,58,0,0,56,47,0,0,0,0,0,46,0,0,47,4,0,13,0,4,1,7,1},{32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,7,3,3,0,1,0,7,4,4,1,0,0,0,0,0},{195,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,49,0,0,0,37,0,0,0,87,0,0,3,4,0,5,0,0,4,0,0,4,0,0,0,2,0},{153,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,42,0,0,0,26,0,0,3,62,0,0,1,0,0,10,0,0,3,0,0,0,0,0,0,6,0},{13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,2,0},{105,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,0,0,0,11,0,0,0,9,0,0,1,0,2,28,0,0,0,1,0,29,8,0,0,0,0},{77,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,23,2,0,3,13,0,0,5,6,0,0,0,0,0,17,0,0,0,2,0,4,0,0,0,2,0},{313576,209,82,150,110,108,66,96,48,38,77,80,148,193,68,46,54,5,110,140,94,15,57,18,4,13,36,2176,13837,20619,10922,6663,2705,9660,2321,7632,484,3837,41537,13806,43458,879,12808,428,34698,19870,44168,5968,4121,2347,1529,3199,1839},{67651,1,8,1,3,2,0,1,6,0,1,0,2,5,4,0,2,0,3,5,2,0,0,0,0,0,2,9526,1939,415,492,9549,157,104,212,9334,272,54,12228,261,183,7793,201,10,6560,1706,504,5109,137,114,0,731,12},{157077,4,0,1,5,2,2,1,1,3,2,1,4,3,1,0,6,1,2,0,6,0,3,0,0,0,0,24423,446,3291,571,16505,177,367,21401,12047,37,7835,5747,1004,725,25357,2102,235,8945,2420,11194,8126,138,27,49,3716,144},{119158,13,15,10,4,14,15,9,8,3,9,3,6,27,5,2,3,0,26,18,8,1,5,7,0,0,2,10676,2388,2566,3559,24039,1465,2020,1492,20346,487,250,3971,2124,2073,9894,2401,127,7239,7350,1461,8850,706,1266,20,2066,109},{398684,185,106,166,121,95,47,69,49,27,136,78,132,187,57,26,38,1,82,113,54,3,38,27,0,15,6,20597,6060,18537,34477,10392,5731,5974,3367,6842,768,1260,22173,15537,40540,7459,14201,1214,73333,62346,22408,7287,4457,3578,5326,2259,703},{41610,5,0,1,1,0,0,1,0,1,4,1,1,0,0,0,0,0,5,0,1,1,1,1,0,4,0,3908,123,97,86,5389,3345,62,102,7354,21,38,4417,93,70,5838,106,10,3029,645,1529,4209,15,119,1,968,8},{86637,3,3,21,5,4,5,6,14,7,6,10,11,13,3,0,11,3,2,12,10,2,2,12,4,11,2,8835,1441,1493,1329,13327,886,2875,3709,9288,187,196,6323,1714,3391,6001,1378,76,9409,4720,1067,5568,205,769,3,2210,55},{97587,14,7,3,9,8,6,9,18,1,12,14,15,22,7,0,10,1,17,29,16,3,1,5,0,4,2,15202,874,569,406,20001,514,320,425,15701,85,218,2051,1328,1303,15981,702,56,4531,1932,2964,3297,93,661,4,8091,45},{325737,27,28,31,35,11,14,20,31,3,25,42,29,46,28,0,14,0,27,49,44,1,14,11,1,14,2,21149,4759,35692,15468,14814,6434,7527,521,599,205,2963,17334,8831,63827,23325,7651,546,8018,37374,26048,2452,7677,200,873,153,10750},{5845,2,0,0,2,0,0,0,0,1,0,0,0,3,2,0,1,0,2,2,1,0,0,0,0,0,0,1485,4,2,6,1148,1,2,13,477,9,8,2,6,13,1119,2,0,15,11,2,1495,0,0,0,9,0},{30433,5,6,7,9,4,7,0,8,1,10,5,3,10,3,0,6,0,6,11,3,0,3,4,0,4,2,2722,709,398,263,8800,421,169,729,5191,67,258,1486,437,934,1228,416,19,616,2854,506,668,53,510,1,838,23},{202571,36,12,38,21,12,5,18,7,9,15,19,13,44,24,4,11,0,28,37,4,0,4,6,0,2,2,27989,1671,2835,3390,37398,1502,1384,984,35744,129,1175,19095,2529,1775,20619,3839,139,832,5891,5027,8037,1502,567,34,17987,126},{110958,6,8,5,1,5,1,4,6,6,3,13,2,12,7,0,5,1,2,13,8,0,3,2,1,1,0,21607,5065,1158,527,20280,536,357,595,18814,96,109,724,4298,1320,13351,8486,65,458,4198,689,4485,269,245,24,3014,73},{253770,64,34,101,56,42,26,42,31,13,89,84,55,83,29,7,26,5,51,80,19,2,17,24,1,18,8,20815,2581,15321,16949,34872,3859,30927,2337,24049,744,2905,2536,2882,5407,17874,4394,582,2942,19518,30794,4164,1997,1405,163,2073,673},{261930,27,6,21,10,12,5,9,14,3,6,15,14,31,10,6,6,2,23,19,17,2,7,2,0,5,4,4484,5207,11676,8415,2945,2533,11244,1179,6212,237,2118,19529,17874,46534,8659,15643,345,31304,16737,13897,19103,6287,5192,2221,1210,869},{117746,3,1,3,3,1,1,1,0,0,2,7,1,1,0,0,7,1,0,3,3,0,1,0,0,0,0,13319,408,452,199,17745,290,205,16895,11046,59,133,7982,368,560,13330,3945,16,14683,4721,4770,4212,43,333,1,1981,11},{6008,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,27,1,2,0,6,0,1,0,24,0,0,0,1,2,4,1,3,3,10,1,5915,0,2,0,0,0},{260778,24,14,14,16,12,8,18,12,5,15,7,11,12,11,8,19,0,9,31,13,1,6,6,1,4,6,37797,4715,7804,7516,42236,2507,4217,2892,37894,400,2597,3715,8134,5081,32941,5418,259,6992,17800,10343,7225,2093,1646,18,8064,191},{282461,35,17,25,26,9,12,14,4,9,19,8,17,22,8,1,22,0,12,14,16,0,9,7,0,3,0,16475,5894,19185,5550,27337,4103,3485,16452,21469,831,3018,6622,13664,4881,12576,17919,1495,5113,32425,41199,13324,1778,3466,127,3408,356},{241736,14,25,14,10,16,5,12,17,4,12,11,11,33,7,2,12,0,8,18,3,0,6,3,0,1,0,23560,1805,3881,1413,47127,1600,919,17838,51294,230,251,3972,1995,1447,23191,2449,123,22095,10483,7449,8412,352,1703,9,7373,521},{132273,5,2,4,3,0,2,0,5,2,0,2,7,8,3,0,2,2,5,10,6,0,2,1,0,2,1,4430,5181,4821,3748,3661,1066,2593,130,4248,118,640,14586,9296,25310,1015,5187,43,14777,19809,10031,84,457,50,405,176,337},{33212,1,2,1,2,1,0,0,0,1,1,0,1,3,0,1,0,0,3,3,1,0,1,0,0,0,0,5364,0,10,10,16890,1,10,3,7319,1,16,34,12,24,2643,6,0,95,46,7,489,51,2,3,150,4},{25465,1,0,0,1,0,0,0,1,0,0,2,1,2,1,0,0,0,1,4,0,0,0,5,0,0,2,5533,403,155,330,4023,210,73,1677,4010,21,207,715,219,1223,3845,179,6,872,987,199,185,9,147,1,196,19},{11095,6,1,1,1,2,1,0,0,0,0,0,2,4,0,0,1,0,1,1,2,0,1,0,0,0,0,1160,95,719,57,1289,87,39,240,2353,11,18,113,104,39,866,1072,17,57,239,1266,314,38,52,22,799,5},{71412,38,41,66,39,19,15,31,29,6,34,49,48,55,17,5,18,1,29,38,44,1,14,12,1,2,0,4433,1949,5314,3334,3104,1448,2047,1514,3217,323,274,4908,4281,3385,3066,7177,182,3607,8199,4058,2613,647,985,258,73,364},{17910,3,2,1,0,0,6,1,2,3,1,2,4,2,1,1,2,0,6,1,3,0,0,0,0,2,0,3711,63,29,22,7813,21,29,40,2196,11,36,306,38,17,1994,34,8,18,72,35,167,18,32,0,504,653}
# 22 "..\\QueryLibrary\\generate_login_pass.h" 2
};

 
char letters[52] = {
    # 1 "..\\Parameters\\letters.txt" 1
'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'
# 27 "..\\QueryLibrary\\generate_login_pass.h" 2
};

 
int nextLetter(int sum, int (*c)[52 + 1], int next){
    int n = 0;
    int i = 1;
    int num = rand()%sum;
    for(; i < 52 + 1; i++){
        n+=c[next][i];
        if(n >= num)
        {
            return i;
        }
    }
    return  -1;
}

char * generate_login(int length_login, int next_letter_idx){
     
     
    char * login = (char*)malloc(length_login + 1);
    int i = 1;

    login[0] = letters[next_letter_idx - 1];
    for(; i < length_login; i++){
        next_letter_idx = nextLetter(stochasticMatrix[next_letter_idx][0],stochasticMatrix, next_letter_idx);
        ((next_letter_idx !=  -1) ? (void)0 : (void) _assertfail(         			"Assertion failed: ",     	    		"p", "..\\QueryLibrary\\generate_login_pass.h", 53 ) );
        login[i] = letters[next_letter_idx - 1];
    }
    login[length_login] = '\0';
    return login;
}

 
char * generate_password(int length_password, int next_letter_idx){
     
     
    char * password = (char*)malloc(length_password + 1);
    int i = 1;

    password[0] = letters[next_letter_idx - 1];

    for(; i < length_password; i++){
        if(next_letter_idx < 52/2){
            password[i] = letters[rand()%52];
        } else {
             
            password[i] = (char)rand()%10 + 48;
        }
        next_letter_idx = rand()%52;
    }
    password[length_password] = '\0';
    return password;
}







# 10 "globals.h" 2



 
 




# 3 "c:\\user\\github\\testing_web_tours\\\361\352\360\350\357\362\373\\registrationuser\\\\combined_RegistrationUser.c" 2

# 1 "vuser_init.c" 1
vuser_init()
{
	return 0;
}
# 4 "c:\\user\\github\\testing_web_tours\\\361\352\360\350\357\362\373\\registrationuser\\\\combined_RegistrationUser.c" 2

# 1 "Action.c" 1
Action()
{
	char * username;
	char * password = (char*)generate_password(atoi(lr_eval_string("{length_login_and_pass}")), atoi(lr_eval_string("{first_letter_login}")));
	
	lr_save_string(password, "password");
	lr_output_message("password %s",lr_eval_string("{password}"));
	free(password);
	
	srand(_time32(0));
	
	web_set_sockets_option("SSL_VERSION", "2&3");
	
	lr_start_transaction("UC_00_registration");
	
	lr_start_transaction("go_to_site");

		 
		web_reg_find("Fail=NotFound",
			"Text=Welcome to the Web Tours site.",
			"LAST");
	
		web_url("WebTours", 
				"URL=http://localhost:1080/WebTours", 
				"TargetFrame=", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=", 
				"Snapshot=t1.inf", 
				"Mode=HTML", 
				"LAST");

	lr_end_transaction("go_to_site", 2);
	
		lr_start_transaction("click_sign_up_now");
		lr_think_time(5);
		
			 
			web_reg_find("Fail=NotFound",
				"Text=First time registering? Please complete the form below.",
				"LAST");
		
			web_url("sign_up_now", 
				"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
				"TargetFrame=body", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/WebTours/home.html", 
				"Snapshot=t7.inf", 
				"Mode=HTML", 
				"LAST");
		
		lr_end_transaction("click_sign_up_now", 2);
		
		lr_start_transaction("click_registration");
		lr_think_time(5);
		
	 
	{	
		 
		int count = 1;
				lr_save_datetime("%m%d%Y%H%M", 0, "currDateTime"); 
				lr_param_sprintf("username", "%s%s", lr_eval_string("{username}"), lr_eval_string("{currDateTime}"));

		lr_output_message("usernameqqqqqqqqqqqqqqqqqqqqqqqqq:   %s",  lr_eval_string("{username}"));
		
		do{	
			username = (char*)generate_login(atoi(lr_eval_string("{length_login_and_pass}")), atoi(lr_eval_string("{first_letter_login}")));
			lr_save_string(username, "username");
			free(username);
			
			if(count > 3){
				lr_save_datetime("%m%d%Y%H%M", 0, "currDateTime"); 
				lr_param_sprintf("username", "%s%s", lr_eval_string("{username}"), lr_eval_string("{currDateTime}"));
			}
			web_reg_save_param_ex(
				"ParamName=username_pass",
				"LB=Thank you, <b>",
				"RB=</b>, for registering",
				"NotFound=warning",
				"SEARCH_FILTERS",
				"Scope=BODY",
				"LAST");	
			
			web_submit_data("login.pl", 
				"Action=http://localhost:1080/cgi-bin/login.pl", 
				"Method=POST", 
				"TargetFrame=info", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
				"Snapshot=t14.inf", 
				"Mode=HTML", 
				"ITEMDATA", 
				"Name=username", "Value={username}", "ENDITEM", 
				"Name=password", "Value={password}", "ENDITEM", 
				"Name=passwordConfirm", "Value={password}", "ENDITEM", 
				"Name=firstName", "Value={firstName}", "ENDITEM", 
				"Name=lastName", "Value={lastName}", "ENDITEM", 
				"Name=address1", "Value={address1}", "ENDITEM", 
				"Name=address2", "Value={address2}", "ENDITEM", 
				"Name=register.x", "Value=54", "ENDITEM", 
				"Name=register.y", "Value=6", "ENDITEM", 
				"LAST");
			
		}while(strcmp(lr_eval_string("{username}"),lr_eval_string("{username_pass}")) != 0);
	}
	
	
	 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
		
		lr_end_transaction("click_registration", 2);
		
	lr_end_transaction("UC_00_registration", 2);

	return 0;
}
# 5 "c:\\user\\github\\testing_web_tours\\\361\352\360\350\357\362\373\\registrationuser\\\\combined_RegistrationUser.c" 2

# 1 "vuser_end.c" 1
vuser_end()
{
	return 0;
}
# 6 "c:\\user\\github\\testing_web_tours\\\361\352\360\350\357\362\373\\registrationuser\\\\combined_RegistrationUser.c" 2


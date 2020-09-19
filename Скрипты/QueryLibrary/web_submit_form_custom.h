#ifndef WEB_SUBMIT_FORM_CUSTOM_H
#define WEB_SUBMIT_FORM_CUSTOM_H

//Максимальное количество параметров которые можно хранить в структуре
#define ARGS_MAX 150

//Структура для сохранения параметров
//можно записывать все параметры необходимые для
//"web_submit_from", при раскрытии параметров в "web_submit_from"
//используется принцип последовательности памяти
//поэтому добавлять параметры в экземпляры структуры "web_submit_form_args"
//необходимо в четкой последовательности необходимой для "web_submit_from"
typedef struct {char *arg[ARGS_MAX];} web_submit_form_args;
web_submit_form_args FORM_ARGS;
int arg_i = 0;

//Для добавления в структуру целостного параметра
#define form_args_add(X) FORM_ARGS.arg[arg_i++] = X

//Содержит указатели на выделенную память под параметры,
//которые необходимо объединить
char* form_args_param_list[ARGS_MAX];
//итератор по массиву "form_args_param_list"
int form_args_param_idx = 0;

//Функция объединяет два значения строку и номер
//в один параметр и добавляет в структуру "FORM_ARGS"
void form_args_add_paramarr(char *pattern, int num){
    //Выделяем память для объединения "pattern" и "num"
    //+1 - два символа под двухзначное число "num"
    //+1 - для конца строки '\0'
    char *param = (char*)malloc(strlen(pattern)+1+1);
    sprintf(param, "%s%d", pattern, num);
    //Сохраняем указатель на выделенную память
    //в массив "form_args_param_list"
    form_args_param_list[form_args_param_idx++] = param;
    //Добавляем указатель выделенной памяти в структуру
    // "FORM_ARGS"
    form_args_add(param);
}
//Функция для освобождения памяти
//вызывать после использования структуры параметров FORM_ARGS
void form_args_reset(){
	int i;
        for(i = 0; i < form_args_param_idx; i++){
                //Освобождаем если память выделялась для элемента
                if(form_args_param_list[i]){
                        free(form_args_param_list[i]);
                        form_args_param_list[i] = NULL;
		}
	}
        form_args_param_idx = 0;
        arg_i = 0;
}

#endif // WEB_SUBMIT_FORM_CUSTOM_H

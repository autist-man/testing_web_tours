#ifndef GENERATE_LOGIN_H
#define GENERATE_LOGIN_H

#include <time.h>
#include <assert.h>
#include <stdlib.h>

//Не успешное выполнение
#define ERROR_IDX -1
//Количество используемых букв
//26 букв английского языка в нижнем
//и верхнем регистре
#define NUMBER_LETTERS_ENGLISH 52
//Матрица вероятности перехода от одной буквы в другую
#define FILE_PATH_STOC_MATRIX "..\Parameters\stochastic_matrix.txt"
#define FILE_PATH_LETTERS "..\Parameters\letters.txt"

//Матрица для хранения весов
//Плюс один столбец для хранения общей суммы весов элементов
int stochasticMatrix[NUMBER_LETTERS_ENGLISH][NUMBER_LETTERS_ENGLISH + 1] = {
    #include FILE_PATH_STOC_MATRIX
};

//Массив букв
char letters[NUMBER_LETTERS_ENGLISH] = {
    #include FILE_PATH_LETTERS
};

//Алгоритм случайно выборки с учетом веса элемента
int nextLetter(int sum, int (*c)[NUMBER_LETTERS_ENGLISH + 1], int next){
    int n = 0;
    int i = 1;
    int num = rand()%sum;
    for(; i < NUMBER_LETTERS_ENGLISH + 1; i++){
        n+=c[next][i];
        if(n >= num)
        {
            return i;
        }
    }
    return ERROR_IDX;
}

char * generate_login(int length_login, int next_letter_idx){
    //Выделяем память под логин
    //+1 - для нулевого символа
    char * login = (char*)malloc(length_login + 1);
    int i = 1;

    login[0] = letters[next_letter_idx - 1];
    for(; i < length_login; i++){
        next_letter_idx = nextLetter(stochasticMatrix[next_letter_idx][0],stochasticMatrix, next_letter_idx);
        assert(next_letter_idx != ERROR_IDX);
        login[i] = letters[next_letter_idx - 1];
    }
    login[length_login] = '\0';
    return login;
}

//Генерация пароля
char * generate_password(int length_password, int next_letter_idx){
    //Выделяем память под логин
    //+1 - для нулевого символа
    char * password = (char*)malloc(length_password + 1);
    int i = 1;

    password[0] = letters[next_letter_idx - 1];

    for(; i < length_password; i++){
        if(next_letter_idx < NUMBER_LETTERS_ENGLISH/2){
            password[i] = letters[rand()%NUMBER_LETTERS_ENGLISH];
        } else {
            //Кодировка ASCII
            password[i] = (char)rand()%10 + 48;
        }
        next_letter_idx = rand()%NUMBER_LETTERS_ENGLISH;
    }
    password[length_password] = '\0';
    return password;
}






#endif // GENERATE_LOGIN_H

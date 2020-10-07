#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

//Не успешное выполнение
#define FALSE -1
//Количество используемых букв
//26 букв английского языка в нижнем
//и верхнем регистре
#define NUMBER_LETTERS_ENGLISH 52
//Путь до исходного файла с реальными логинами
//до загрузки в программу, убрать из логинов цифры,
//символы, оставить только буквы
#define FILE_PATH_LOGIN_DATA "real_usernames_datapool.txt"
//Матрица вероятности перехода от одной буквы в другую
#define FILE_PATH_STOC_MATRIX "stochastic_matrix.txt"

//Хранит букву и ее частоту
typedef struct {
    char m_node;
    int m_amount;
} Node;

//Струкура словаря
//size_subDictionary - хранит количество букв идущих
//после буквы m_key
//m_subDictionary - массив(подсловарь) встречающихся после m_key букв
typedef struct {
    int size_subDictionary;
    Node m_key;
    Node * m_subDictionary;
} Dictionary;

//!========================================================================================
//! Управление размером памяти словаря и подсловаря
void* reallocDictionary(void * dictionary, int size){

    void* newDictionaty = NULL;
    newDictionaty = realloc(dictionary, size);

    if(newDictionaty == NULL){
        return NULL;
    }

    return newDictionaty;
}
//!========================================================================================
//! Освобождение памяти словаря
void freeDictionary(Dictionary * dictionary, int size){
    for(int idx = 0; idx < size; idx++){
        free(dictionary[idx].m_subDictionary);
    }
    free(dictionary);

}
//!========================================================================================
//!Проверка буквы в словаре, если буква есть возвращает ее индекс(положение в словаре)
//! и увеличивает ее количество на единицу
//! в противном случае возвращает ЛОЖЬ
int isWordInDictionary(Dictionary * dictionary,char * prev_word, int position){
    for(int idx = 0; idx < position; idx++){
        if(dictionary[idx].m_key.m_node == *prev_word){
            dictionary[idx].m_key.m_amount++;
            return idx;
        }
    }
    return FALSE;
}
//!========================================================================================
//!Проверка буквы в подсловаре, если буква есть возвращает ее индекс(положение в словаре)
//! и увеличивает ее количество на единицу
//! в противном случае возвращает ЛОЖЬ
int isWordInSubDictionary(Node * subDictionary, char * word, int position){

    for(int idx = 0; idx < position; idx++){
        if(subDictionary[idx].m_node == *word){
            subDictionary[idx].m_amount++;
            return idx;
        }
    }
    return FALSE;
}
//!========================================================================================
//!Добавление в словарь буквы и буквы идущей сразу за ней в ее подсловарь
//! подсловарь динамически расширяется
//! логика:
//! сначала идет проверка буквы в словаре, если буквы нет, то добавляем ее в словарь
//! и сразу добавляем следующую букву в ее подсловарь, увеличиваем количество position
//! на единицу (размер словаря)
//! Если буква есть увеличиваем ее количество на единицу,
//! проверяем в ее подсловаре букву идущую за ней, если такой буквы нет добавляем
//! если есть увеличиваем ее количество на единицу
int addWordDictionary(Dictionary * dictionary, char * word_prev, char * word_next,int position){
    int result = isWordInDictionary(dictionary, word_prev, position);
    if(result == FALSE){
        dictionary[position].m_key.m_node = *word_prev;
        dictionary[position].m_key.m_amount = 1;
        dictionary[position].m_subDictionary = NULL;
        dictionary[position].size_subDictionary = 0;

        dictionary[position].size_subDictionary++;
        dictionary[position].m_subDictionary = reallocDictionary(dictionary[position].m_subDictionary,
                                                                 dictionary[position].size_subDictionary *
                                                                 sizeof (Node));
        dictionary[position].m_subDictionary[dictionary[position].size_subDictionary - 1].m_node = *word_next;
        dictionary[position].m_subDictionary[dictionary[position].size_subDictionary - 1].m_amount = 1;

        position++;
    } else {
        int res = isWordInSubDictionary(dictionary[result].m_subDictionary,
                                        word_next,
                                        dictionary[result].size_subDictionary);
        if(res == FALSE){
            dictionary[result].size_subDictionary++;
            dictionary[result].m_subDictionary = reallocDictionary(dictionary[result].m_subDictionary,
                                                                     dictionary[result].size_subDictionary *
                                                                     sizeof (Node));
            dictionary[result].m_subDictionary[dictionary[result].size_subDictionary - 1].m_node =* word_next;
            dictionary[result].m_subDictionary[dictionary[result].size_subDictionary - 1].m_amount = 0;
            dictionary[result].m_subDictionary[dictionary[result].size_subDictionary - 1].m_amount++;
        }
    }
    return position;
}
//!========================================================================================
//! Проверяет наличие буквы в словаре
int compareWordDictionary(const void *a, const void *b){
    Dictionary *_a = (Dictionary *) a;
    Dictionary *_b = (Dictionary *) b;
    return strcmp(&_a->m_key.m_node, &_b->m_key.m_node);
}
//! Проверяет наличие буквы в подсловаре
int compareWordSubDictionary(const void *a, const void *b){
    Node *_a = (Node *) a;
    Node *_b = (Node *) b;
    return strcmp(&_a->m_node,&_b->m_node);
}
//!========================================================================================
//! Алгоритм случаной выборки с учетом веса буквы
int nextLetter(int sum, int (*c)[NUMBER_LETTERS_ENGLISH + 1], int next){
    int n = 0;
    int num = rand()%sum;
    for(int i = 1; i < NUMBER_LETTERS_ENGLISH + 1; i++){
        n+=c[next][i];
        if(n >= num)
        {
            return i;
        }
    }
    return FALSE;
}

int main()
{

//!---------------------ЭТАП 1. ПОДГОТОВКА ДАННЫХ И СТАТИСТИКИ---------------------------------------
    Dictionary * dictionary = NULL;
    int sizeDictionary = 0;
    int maxSizeDictionary = 0;

    //Открываем файл с данными логинами
    FILE * file;
    if((file = fopen(FILE_PATH_LOGIN_DATA, "rb")) == NULL){
        printf("Error: failed to open the file FILE_PATH_LOGIN_DATA \n");
        return EXIT_FAILURE;
    }
    //Узнаем размер файла, чтобы узнать количество символов в файле
    fseek(file, 0, SEEK_END);
    maxSizeDictionary = (int)ftello(file) - 1;
    fclose(file);
//  printf("maxSizeDictionary = %d\n", maxSizeDictionary);
    file = NULL;
    assert(maxSizeDictionary != 0);
    dictionary = (Dictionary*)reallocDictionary(dictionary, NUMBER_LETTERS_ENGLISH * sizeof (Dictionary));
    assert(dictionary != NULL);

    if((file = fopen(FILE_PATH_LOGIN_DATA, "r")) == NULL){
        printf("Error: failed to open the file FILE_PATH_LOGIN_DATA\n");
        return EXIT_FAILURE;
    }

    {
        //Устанавливает позицию следующей буквы в файле
        int streamPositionNext = 1;
        char buffer_prev;
        char buffer_next;
        //Читать буквы из файла пока они не закончаться
        for (; streamPositionNext < maxSizeDictionary; streamPositionNext++) {
            //Читаем первую букву
            if((buffer_prev = fgetc(file)) == '\n'){
                buffer_prev = fgetc(file);
            }
            //Читаем следующую букву, если это перевод строки
            //переводим курсор на первую букву следующего логина
            if((buffer_next = fgetc(file)) == '\n'){
                buffer_next = fgetc(file);
                streamPositionNext+=2;
            }
//          printf("streamPositionNext = %d\n",streamPositionNext);
            //После прочтения возращаем курсор на предыдущую позицию
            fseek(file, streamPositionNext, SEEK_SET);
            //добавить в словарь считанные буквы
            sizeDictionary = addWordDictionary(dictionary, &buffer_prev, &buffer_next, sizeDictionary);
//            printf("buffer_prev = %c\n",buffer_prev);
//            printf("buffer_next = %c\n",buffer_next);
//            printf("sizeDictionary = %d\n",sizeDictionary);
            assert(sizeDictionary <= NUMBER_LETTERS_ENGLISH);
        }
    }

        //Вывести словарь
        for(int i = 0; i < sizeDictionary; i++){
            printf("%d) %c : %d\n",
                   i+1,
                   dictionary[i].m_key.m_node,
                   dictionary[i].m_key.m_amount);
            for(int j = 0; j < dictionary[i].size_subDictionary; j++){
                printf("\t%d) %c : %d\n",
                       j+1,
                       dictionary[i].m_subDictionary[j].m_node,
                       dictionary[i].m_subDictionary[j].m_amount);
            }
        }

        //Проверка: общее количество буквы в словаре
        //должно равняться общему количеству букв идущих после
        int sum = 0;
        for(int i = 0; i < sizeDictionary; i++){
            printf("%d) %c : %d\n",
                   i+1,
                   dictionary[i].m_key.m_node,
                   dictionary[i].m_key.m_amount);
            for(int j = 0; j < dictionary[i].size_subDictionary; j++){
                sum+=dictionary[i].m_subDictionary[j].m_amount;
            }
            assert(sum == dictionary[i].m_key.m_amount);
            printf("\t sum : %d\n",sum);
            sum = 0;
        }
    fclose(file);

//!---------------ЭТАП 2. ПОСТРОЕНИЕ МАТРИЦЫ ВЕРОЯТНОСТЕЙ---------------------------------------

    //Отсортируем словарь и подсловарь по возростанию
     qsort(dictionary, sizeDictionary,
           sizeof (Dictionary),
           compareWordDictionary);
     for(int i = 0; i < sizeDictionary; i++){
         qsort(dictionary[i].m_subDictionary, dictionary[i].size_subDictionary,
               sizeof (Node),
               compareWordSubDictionary);
     }

     //Вывести словарь
     for(int i = 0; i < sizeDictionary; i++){
         printf("%d) %c : %d\n",
                i+1,
                dictionary[i].m_key.m_node,
                dictionary[i].m_key.m_amount);
         for(int j = 0; j < dictionary[i].size_subDictionary; j++){
             printf("\t%d) %c : %d\n",
                    j+1,
                    dictionary[i].m_subDictionary[j].m_node,
                    dictionary[i].m_subDictionary[j].m_amount);
         }
     }

     int stochasticMatrix[sizeDictionary][sizeDictionary + 1];

     for(int i = 0; i < sizeDictionary; i++){
         stochasticMatrix[i][0] = dictionary[i].m_key.m_amount;
         for(int idx = 0, j = 1; j < sizeDictionary + 1; j++){
             if(dictionary[j - 1].m_key.m_node == dictionary[i].m_subDictionary[idx].m_node){
                 stochasticMatrix[i][j] = dictionary[i].m_subDictionary[idx].m_amount;
                idx++;
             }else{
                     stochasticMatrix[i][j] = 0;
             }
         }
     }

     for(int i = 0; i < sizeDictionary; i++){
         for(int j = 0; j < sizeDictionary + 1; j++){
             printf("%d ", stochasticMatrix[i][j]);
         }
         printf("\n");
     }

     FILE * file_stochasticMatrix;
     if((file_stochasticMatrix = fopen(FILE_PATH_STOC_MATRIX,"w")) == NULL){
         assert(file_stochasticMatrix == NULL);
     }

     for(int i = 0; i < sizeDictionary; i++){
        fprintf(file_stochasticMatrix,"{");
        for(int j = 0; j < sizeDictionary + 1; j++){
            if(j < sizeDictionary)
                fprintf(file_stochasticMatrix,"%d,", stochasticMatrix[i][j]);
            else
                fprintf(file_stochasticMatrix,"%d", stochasticMatrix[i][j]);
        }
        if(i < sizeDictionary - 1)
            fprintf(file_stochasticMatrix,"},");
        else
            fprintf(file_stochasticMatrix,"}");
     }
     fclose(file_stochasticMatrix);

//         if((file_stochasticMatrix = fopen("letters.txt","w")) == NULL){
//             assert(file_stochasticMatrix == NULL);
//         }

//            for(int i = 0; i < sizeDictionary; i++){
//                if(i < sizeDictionary - 1){
//                    fprintf(file_stochasticMatrix,"'%c',", dictionary[i].m_key.m_node);
//                }
//                else{
//                    fprintf(file_stochasticMatrix,"'%c'", dictionary[i].m_key.m_node);
//                }
//            }
//         fclose(file_stochasticMatrix);

    freeDictionary(dictionary, NUMBER_LETTERS_ENGLISH);


//!----------ЭТАП 3. ГЕНЕРАЦИЯ ЛОГИНА-----------------
/*
 * //Запускать только после генерации стахостической матрицы
//        FILE * file;
//        if((file = fopen("gen_logins.txt", "w")) == NULL){
//            printf("Error");
//        }
        int stochasticMatrix[NUMBER_LETTERS_ENGLISH][NUMBER_LETTERS_ENGLISH+1] = {
            #include FILE_PATH_STOC_MATRIX
        };
        char letters[NUMBER_LETTERS_ENGLISH] = {
            #include "letters.txt"
        };
        srand(time(NULL));
        int ids = 0;
        while(ids < 100){
            int nextLetterIdx = rand()%NUMBER_LETTERS_ENGLISH + 1;
            int lengthUsername = rand()%8 + 4;


            printf("\tlengthUsername = %d\n", (int)lengthUsername);
//            printf("nextLetterIdx = %d\n", nextLetterIdx);

            //char letter = letters[nextLetterIdx];
            char * login = (char*)malloc(lengthUsername+1);
            login[0] = letters[nextLetterIdx];
            for(int i = 1; i < lengthUsername; i++){
                nextLetterIdx = nextLetter(stochasticMatrix[nextLetterIdx][0],stochasticMatrix, nextLetterIdx);
    //            printf("nextLetterIdx = %d\n", nextLetterIdx);
                assert(nextLetterIdx != FALSE);
				//Так как стахостическая матрица в первом столбце содержит сумму весов элементов
				//то необходимо от индекса отнимать 1, чтобы индексы совпадали с индексами букв letters
                login[i] = letters[nextLetterIdx - 1];
            }
            login[lengthUsername] = '\0';
            printf("%d#\tlogin = %s\n", ids, login);
            //fprintf(file,"%d#\tlogin = %s\n", ids + 1, login);


            ids++;

            free(login);
        }
 //       fclose(file);

*/
    return 0;
}

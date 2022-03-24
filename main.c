#include <stdlib.h>
#include <stdio.h>
#include "polynom.h"
#include "PolInfo.h"
#include "tests.h"
#include <stddef.h>
/*
 int max_int(int a1, int a2);
 int min_int(int a1,int a2);
 void* sum_int(void* a1, void* a2);
 void* sum_double(void* a1, void* a2);
 void* mult_double(void* a1,void* a2);
 void* mult_int(void* a1, void* a2);
 void* add_int(void* a1,void* a2);
 void* add_double(void* a1,void* a2);
 struct PolInfo;
 struct polynom;
 void delete_polynom(struct polynom* poly);
 struct PolInfo* create_info(size_t size,void* zero,void* (*sum)(void*, void*),void* (*mult)(void*,void*), void* minus_one,void* add);
 void show_pol(struct polynom* poly);
 struct polynom* create_polynom_zero(struct PolInfo *info, int length);
 struct polynom* create_polynom(struct PolInfo *info,int length,void* numbers);
 int info_equal(struct PolInfo* inf1, struct PolInfo* inf2);
 struct polynom* random_pol(struct PolInfo* info);
 struct polynom* sum_pol(struct polynom* pol1, struct polynom* pol2);
 struct polynom* mult_pol(struct polynom* pol1,struct polynom* pol2);
 struct polynom* mult_const(struct polynom* pol, void* a);
 struct polynom* substr_pol(struct polynom* pol1,struct polynom* pol2);
 void* pol_value(struct polynom* poly, void* value);
 struct polynom* pol_copy(struct polynom* poly);
 struct polynom* composition(struct polynom* pol1,struct polynom* pol2);
 */
/*
int max_int(int a1, int a2){
    if (a1>a2){
        return a1;
    }
    else{
        return a2;
    }
}

int min_int(int a1,int a2){
    if (a1<a2){
        return a1;
    }
    else{
        return a2;
    }
}
void* sum_int(void* a1, void* a2){

    int* res = (int*)malloc(sizeof(int));

    *res = (*(int*)a1)+(*(int*)a2);

    return (void*)res;
}

void* sum_double(void* a1, void* a2){
    double* res = (double*)malloc(sizeof(double));

    *res = *(double*)a1+*(double*)a2;

    return (void*)res;
}

void* mult_double(void* a1,void* a2){
    double* res = (double*)malloc(sizeof(double));

    *res = (*(double*)a1)*(*(double*)a2);

    return (void*)res;
}

void* mult_int(void* a1, void* a2){
    int* res = (int*)malloc(sizeof(int));
    *res = (*(int*)a1)*(*(int*)a2);
    return (void*)res;
}

void* add_int(void* a1,void* a2){
    *(int*)a1 = *(int*)a1+*(int*)a2;
    return (void*)a1;
}
void* add_double(void* a1,void* a2){
    *(double*)a1 = *(double*)a1+*(double*)a2;
    return (void*)a1;
}

struct PolInfo{
    size_t size;
    void* (*sum)( void* , void* );
    void* zero;
    void* (*mult)( void* , void* );
    //void* (*substr)( void*,void*);
    void* minus_one;
    void* (*add)(void* , void*);

};

struct polynom{
    struct PolInfo* info;
    int length;
    void** numbers;
};

void delete_polynom(struct polynom* poly){
    int i;
    for (i =0;i<poly->length;i++){

        free((poly->numbers)[i]);
    }

    free(poly->numbers);

    free(poly);

}

struct PolInfo* create_info(size_t size,void* zero,void* (*sum)(void*, void*),void* (*mult)(void*,void*), void* minus_one,void* add){
    struct PolInfo* new_info = malloc(sizeof(struct PolInfo));
    new_info -> size = size;
    new_info -> zero = zero;
    new_info -> sum = sum;
    new_info -> mult = mult;
    new_info -> minus_one = minus_one;
    new_info -> add = add;
    return new_info;
}
void show_pol(struct polynom* poly){

    int len = poly -> length;
    int i;
    int size = (poly -> info) -> size;
    if (poly != NULL){

        if (size == sizeof(int)){

            printf("%d", *(int*)((poly->numbers)[0]));

            for (i=1;i<len;i++){

                printf(" + %d * x^%d", *(int *) ((poly->numbers)[i]), i);


            }
            printf("\n");
        }
        if (size == sizeof(double)){

            printf("%lf", *(double*)((poly->numbers)[0]));
            for (i=1;i<len;i++){

                printf(" + %lf * x^%d", *(double *)((poly->numbers)[i]), i);

            }
            printf("\n");
        }
    }
}
struct polynom* create_polynom_zero(struct PolInfo *info, int length){
    struct polynom *new_polynom = malloc(sizeof(struct polynom));
    new_polynom ->info = info;
    new_polynom -> length = length;
    new_polynom -> numbers = malloc((sizeof(void*))*length);
    int i;

    for (i = 0;i<length;i++){
        (new_polynom->numbers)[i] = info->sum(info->zero,info->zero);


    }

    return new_polynom;

}
struct polynom* create_polynom(struct PolInfo *info,int length,void* numbers){
    struct polynom *new_polynom = malloc(sizeof(struct polynom));
    int i;
    new_polynom ->info = info;
    new_polynom -> length = length;
    new_polynom -> numbers = malloc((sizeof(void*))*length);

    for (i = 0;i<length;i++){
        (new_polynom->numbers)[i] = info->sum(numbers+i*(info->size),info->zero);

    }
    return new_polynom;
}

int info_equal(struct PolInfo* inf1, struct PolInfo* inf2){
    if ((inf1->mult == inf2->mult)&&(inf1->size == inf2->size)&&(inf1->sum == inf2->sum)){
        return 1;
    }
    return 0;

}
struct polynom* random_pol(struct PolInfo* info){
    if (info == NULL){
        return NULL;
    }

    struct polynom* random_poly = malloc(sizeof(struct polynom));
    random_poly = create_polynom_zero(info,2+rand()%7);


    int i,j;
    void* one = info->mult(info->minus_one,info->minus_one);


    for (i = 0; i < random_poly -> length;i++){




        for(j = 0;j<1+rand()%100;j++){

            (random_poly -> numbers)[i] = info->add((random_poly -> numbers)[i],one);

        }

    }
    free(one);
    return random_poly;
}
struct polynom* sum_pol(struct polynom* pol1, struct polynom* pol2){
    if ((pol1 == NULL) || (pol2 == NULL)){
        return NULL;
    }

    if (!info_equal(pol1->info,pol2->info)){
        return NULL;
    }
    int res_len = max_int(pol1->length,pol2->length);
    struct polynom* pol_res = create_polynom_zero(pol1->info, res_len);


    int i;

    for (i=0;i<res_len;i++){



        if (i<pol1->length){

            (pol_res->numbers)[i] = pol1->info->add((pol_res->numbers)[i],(pol1->numbers)[i]);


        }
        if (i<(pol2->length)){

            (pol_res->numbers)[i] = pol1->info->add((pol_res->numbers)[i], (pol2->numbers)[i]);



        }


    }

    return pol_res;
}
struct polynom* mult_pol(struct polynom* pol1,struct polynom* pol2){
    struct polynom* pol_res;
    if ((pol1 == NULL) || (pol2 == NULL)){
        return NULL;
    }
    if (!info_equal(pol1->info,pol2->info)){
        return NULL;
    }
    int i,j;
    pol_res = create_polynom_zero(pol1->info,pol1->length + pol2->length-1);


    void* multiply;
    for (i = 0;i<pol1->length;i++){
        for (j = 0;j<pol2->length;j++){
            //vivod_pol(pol_res);
            multiply = pol1->info->mult( (pol1->numbers)[i], (pol2->numbers)[j]);
            pol1->info->add(( pol_res->numbers ) [i + j] , multiply);//pol1->info->mult( (pol1->numbers)[i], (pol2->numbers)[j]));
            free(multiply);
        }
    }




    return pol_res;

}
struct polynom* mult_const(struct polynom* pol, void* a){

    int i;
    if ((pol==NULL) || (a == NULL)){
        return NULL;
    }
    struct polynom* pol_res = malloc(sizeof(struct polynom));
    pol_res -> numbers = malloc((sizeof(void*))*(pol->length));
    pol_res -> info = pol -> info;
    pol_res -> length = pol -> length;
    for (i=0;i<pol->length;i++){

        (pol_res->numbers)[i] = (pol->info->mult(((pol->numbers)[i]),a));


    }
    return pol_res;

}
struct polynom* substr_pol(struct polynom* pol1,struct polynom* pol2){
    struct polynom* pol_res;
    struct polynom* pol2additional;
    if ((pol1 == NULL) || (pol2 == NULL)){
        return NULL;
    }
    if (!info_equal(pol1->info,pol2->info)){
        return NULL;
    }


    pol2additional = mult_const(pol2,pol2->info->minus_one);

    pol_res = sum_pol(pol1,pol2additional);
    delete_polynom(pol2additional);
    return pol_res;



}
void* pol_value(struct polynom* poly, void* value){
    if ((poly == NULL)||(value == NULL)){
        return NULL;
    }
    void* multiply;
    int i;
    void* res;
    multiply = poly->info->mult(value,(poly->numbers)[poly->length-1]);

    res = poly->info->sum(multiply,poly->numbers[poly->length-2]);
    free(multiply);

    for (i = poly->length-2;i>0;i = i-1){
        multiply = poly->info->mult(value,res);
        free(res);
        res = poly->info->sum(multiply,(poly->numbers)[i-1]);

        free(multiply);
    }
    return res;
}
struct polynom* pol_copy(struct polynom* poly){
    int i;
    struct polynom* pol_res = malloc(sizeof(struct polynom));
    if (poly == NULL){
        return NULL;
    }
    pol_res->info = poly->info;
    pol_res->length = poly->length;
    pol_res -> numbers = malloc((sizeof(void*))*(pol_res->info->size));

    for (i = 0;i< pol_res->length;i++){
        (pol_res->numbers)[i] = poly->info->sum((poly->numbers)[i],poly->info->zero);
    }
    return pol_res;

}
struct polynom* composition(struct polynom* pol1,struct polynom* pol2){
    if ((pol1 == NULL) || (pol2 == NULL)){
        return NULL;
    }

    if (!info_equal(pol1->info,pol2->info)){
        return NULL;
    }


    struct polynom* pol_res = create_polynom_zero(pol1->info, (pol1->length-1)*(pol2->length-1));
    struct polynom* pol_add;
    struct polynom* pol_add_const;
    int i;


    pol_add= pol_copy(pol2);
    (pol_res->numbers)[0] = (pol1->numbers)[0];
    pol_add_const = mult_const(pol_add, (pol1->numbers [1]));
    pol_res = sum_pol(pol_res, pol_add_const);

    for (i = 2; i < pol1->length; i++) {

        pol_add = mult_pol(pol_add, pol2);



        pol_add_const = mult_const(pol_add, ( pol1->numbers [i]));
        pol_res = sum_pol(pol_res, pol_add_const);
    }
    return pol_res;


}*/
int main(){
    char* insert_polynom_type = malloc(3);
    int insert_polynom_flag = 1;
    char* insert_polynom_len = malloc(3);
    char* insert_action_type = malloc(3);
    int insert_action_flag = 1;
    int insert_action_len = 0;
    struct PolInfo* info;
    double* value;// = (int*)malloc(sizeof(int));
    int* zero_int = malloc(sizeof(int));

    *zero_int = 0;
    double* zero_double = malloc(sizeof(double));
    *zero_double = 0.0;
    double* minus_one_double = malloc(sizeof(double));
    int* minus_one_int = malloc(sizeof(int));
    *minus_one_double = -1.0;
    *minus_one_int = -1;
    info = create_info(sizeof(double),zero_double,&sum_double,&mult_double,minus_one_double,&add_double,&double_to_string);
    double* chislo = malloc(sizeof(double));
    *chislo = 0.0;
    double massive[] = { 1.0 , 2.0 , 3.0};
    /*struct polynom* pol1;
    struct polynom* pol2;
    struct polynom* pol3;
    struct polynom* pol4;
    struct polynom* pol5;
    struct polynom* pol6;
    struct polynom* pol7;
    struct polynom* pol8;
    struct polynom* pol9;
    char* stroke = double_to_string(chislo);

    printf("Пример функционирования\n");
    printf("Полином раз\n");
    pol1 = random_pol(info);
    show_pol(pol1);
    printf("Полином двас\n");
    pol2 = random_pol(info);
    show_pol(pol2);
    printf("Сумма полиномов раз и двас\n");
    pol3 = sum_pol(pol1,pol2);
    show_pol(pol3);
    printf("Умножение на число\n");
    pol4 = mult_const(pol1,chislo);
    show_pol(pol4);
    printf("Нулевой многочлен\n");
    pol5 = create_polynom_zero(info,8);
    show_pol(pol5);
    printf("Полином раз умноженнный на полином двас\n");
    pol6 = mult_pol(pol1,pol2);
    show_pol(pol6);
    printf("Полином раз минус полином двас\n");
    pol7 = substr_pol(pol1,pol2);
    show_pol(pol7);
    *chislo = 1.0;
    printf("Значение полинома раз\n");
    value = (double*)pol_value(pol1, chislo);
    if (value!=NULL) {
        printf("%lf\n", *value);
    }
    printf("Копирование\n");
    pol1 = pol_copy(pol2);
    show_pol(pol1);
    printf("Создание полинома\n");
    pol8 = create_polynom(info,3,massive);
    show_pol(pol8);
    printf("Композиция\n");
    pol9 = composition(pol8,pol8);
    show_pol(pol9);
    free(chislo);
    free(value);
    free(info);
    delete_polynom(pol1);
    delete_polynom(pol2);
    delete_polynom(pol3);
    delete_polynom(pol4);
    delete_polynom(pol5);
    delete_polynom(pol6);
    delete_polynom(pol7);
    delete_polynom(pol8);
    delete_polynom(pol9);

    */
    test_sum();
    test_substraction();
    test_mult();
    test_composition();
    struct polynom* polynom_result = malloc(sizeof(struct polynom));
    struct polynom* polynom_additional = malloc(sizeof(struct polynom));
    struct polynom* polynom_current = malloc(sizeof(struct polynom));
    struct PolInfo* info_current = malloc(sizeof(struct PolInfo));
    char* insert_polynom = malloc(10);
    char* insert_const = malloc(10);
    void* constant;
    double* number_double;
    double* heap_double;
    char* insert_helper = malloc(2);
    *insert_helper = '1';
    insert_helper[1] = '1';
    char** errstr = NULL;
    int pol_len,i1;
    int* heap_int;
    while(insert_polynom_flag){
        printf("1) Случайный 2 вещественных многочленов\n2) Ввод 2 вещественных многочленов с клавиатуры\n3)2 случайных целочисленных многочленов\n4) Ввод 2 целочисленных многочленов с клавиатуры\n5) Выход из программы\n");
        fgets(insert_polynom_type, 3, stdin);
        free(polynom_current);
        free(polynom_additional);
        free(polynom_result);
        free(info_current);
        if (insert_polynom_type[1] != '\n') {
            insert_polynom_type[0] = '0';
            if (insert_polynom_type[0] != '\n') {
            while ((insert_helper[0] != '\n') && (insert_helper[1] != '\n')) {
                fgets(insert_helper, 2, stdin);
                //printf("%s\n",insert_helper);
            }
            *insert_helper = '1';
            insert_helper[1] = '1';
            }
        }
        switch(*insert_polynom_type) {
            case 49:
                info_current = create_info(sizeof(double), zero_double, &sum_double, &mult_double, minus_one_double,&add_double,&double_to_string);
                polynom_current = random_pol(info_current);
                polynom_additional = random_pol(info_current);
                show_pol(polynom_current);
                show_pol(polynom_additional);
                break;
            case 50:
                info_current = create_info(sizeof(double), zero_double, &sum_double, &mult_double, minus_one_double,&add_double,&double_to_string);
                //polynom_current = random_pol(info_current);
                printf("Вводите размер 1 многочлена\n");
                fgets(insert_polynom_len,3,stdin);

                pol_len = (int)strtol(insert_polynom_len,errstr,0);
                if ((insert_polynom_len[2] !='\n')&&(insert_polynom_len[1] !='\n')){
                    pol_len =0;
                }
                if (pol_len<2){
                    printf("Некорректный ввод\n");
                    break;
                }
                printf("Вводите числа по одному в строке для 1 многочлена, ввод некорректного значения будет считаться за 0\n");
                heap_double = (double*)malloc(pol_len*sizeof(double));
                for (i1= 0;i1<pol_len;i1++){

                    fgets(insert_polynom,10,stdin);
                    //printf("%s\n",insert_polynom);
                    if ((insert_polynom[1]!='\n')&&(insert_polynom[2]!='\n')&&(insert_polynom[3]!='\n')&&(insert_polynom[4]!='\n')&&(insert_polynom[5]!='\n')&&(insert_polynom[6]!='\n')&&(insert_polynom[7]!='\n')&&(insert_polynom[8]!='\n')&&(insert_polynom[9]!='\n')){
                        heap_double[i1] = 0.0;
                        if (insert_polynom[0] == '\n'){continue;}
                        printf("Слишком большое значение\n");
                        while ((insert_helper[0]!='\n')&&(insert_helper[1]!='\n')){
                            fgets(insert_helper,2,stdin);
                            //printf("%s\n",insert_helper);
                        }
                        *insert_helper = '1';
                        insert_helper[1] = '1';
                        //break;
                    }else{
                        heap_double[i1] = strtod(insert_polynom,errstr);
                    }
                }
                polynom_current = create_polynom(info_current,pol_len,heap_double);
                printf("Вводите размер 2 многочлена\n");
                fgets(insert_polynom_len,3,stdin);
                free(heap_double);
                pol_len = (int)strtol(insert_polynom_len,errstr,0);
                if ((insert_polynom_len[2] !='\n')&&(insert_polynom_len[1] !='\n')){
                    pol_len =0;
                }
                if (pol_len<2){
                    printf("Некорректный ввод\n");
                    break;
                }
                printf("Вводите числа по одному в строке для 2 многочлена, ввод некорректного значения будет считаться за 0\n");
                heap_double = (double*)malloc(pol_len*sizeof(double));
                for (i1= 0;i1<pol_len;i1++){

                    fgets(insert_polynom,10,stdin);
                    //printf("%s\n",insert_polynom);
                    if ((insert_polynom[1]!='\n')&&(insert_polynom[2]!='\n')&&(insert_polynom[3]!='\n')&&(insert_polynom[4]!='\n')&&(insert_polynom[5]!='\n')&&(insert_polynom[6]!='\n')&&(insert_polynom[7]!='\n')&&(insert_polynom[8]!='\n')&&(insert_polynom[9]!='\n')){
                        heap_double[i1] = 0.0;
                        if (insert_polynom[0] == '\n'){continue;}
                        printf("Слишком большое значение\n");
                        while ((insert_helper[0]!='\n')&&(insert_helper[1]!='\n')){
                            fgets(insert_helper,2,stdin);
                            //printf("%s\n",insert_helper);
                        }
                        *insert_helper = '1';
                        insert_helper[1] = '1';
                        //break;
                    }else{
                        heap_double[i1] = strtod(insert_polynom,errstr);
                    }
                }
                polynom_additional = create_polynom(info_current,pol_len,heap_double);
                free(heap_double);
                show_pol(polynom_current);
                show_pol(polynom_additional);
                break;
            case 51:
                info_current = create_info(sizeof(int), zero_int, &sum_int, &mult_int, minus_one_int,&add_int,&int_to_string);
                polynom_current = random_pol(info_current);
                polynom_additional = random_pol(info_current);
                show_pol(polynom_current);
                show_pol(polynom_additional);
                break;
            case 52:
                info_current = create_info(sizeof(int), zero_int, &sum_int, &mult_int, minus_one_int,&add_int,&int_to_string);
                printf("Вводите размер 1 многочлена\n");
                fgets(insert_polynom_len,3,stdin);

                pol_len = (int)strtol(insert_polynom_len,errstr,0);
                if ((insert_polynom_len[2] !='\n')&&(insert_polynom_len[1] !='\n')){
                    pol_len =0;
                }
                if (pol_len<2){
                    printf("Некорректный ввод\n");
                    break;
                }
                printf("Вводите числа по одному в строке\n");
                heap_int = (int*)malloc(pol_len*sizeof(int));
                for (i1= 0;i1<pol_len;i1++){

                    fgets(insert_polynom,10,stdin);
                    if ((insert_polynom[1]!='\n')&&(insert_polynom[2]!='\n')&&(insert_polynom[3]!='\n')&&(insert_polynom[4]!='\n')&&(insert_polynom[5]!='\n')&&(insert_polynom[6]!='\n')&&(insert_polynom[7]!='\n')&&(insert_polynom[8]!='\n')&&(insert_polynom[9]!='\n')){
                        heap_int[i1] = 0;
                        if (insert_polynom[0] == '\n'){continue;}
                        printf("Слишком большое значение\n");
                        while ((insert_helper[0]!='\n')&&(insert_helper[1]!='\n')){
                            fgets(insert_helper,2,stdin);
                            //printf("%s\n",insert_helper);
                        }
                        *insert_helper = '1';
                        insert_helper[1] = '1';
                    }else{
                        heap_int[i1] = (int)strtol(insert_polynom,errstr,0);
                    }
                }
                polynom_current = create_polynom(info_current,pol_len,heap_int);
                printf("Вводите размер 2 многочлена\n");
                fgets(insert_polynom_len,3,stdin);
                free(heap_int);
                pol_len = (int)strtol(insert_polynom_len,errstr,0);
                if ((insert_polynom_len[2] !='\n')&&(insert_polynom_len[1] !='\n')){
                    pol_len =0;
                }
                if (pol_len<2){
                    printf("Некорректный ввод\n");
                    break;
                }
                printf("Вводите числа по одному в строке\n");
                heap_int = (int*)malloc(pol_len*sizeof(int));
                for (i1= 0;i1<pol_len;i1++){

                    fgets(insert_polynom,10,stdin);
                    if ((insert_polynom[1]!='\n')&&(insert_polynom[2]!='\n')&&(insert_polynom[3]!='\n')&&(insert_polynom[4]!='\n')&&(insert_polynom[5]!='\n')&&(insert_polynom[6]!='\n')&&(insert_polynom[7]!='\n')&&(insert_polynom[8]!='\n')&&(insert_polynom[9]!='\n')){
                        heap_int[i1] = 0;
                        if (insert_polynom[0] == '\n'){continue;}
                        printf("Слишком большое значение\n");
                        while ((insert_helper[0]!='\n')&&(insert_helper[1]!='\n')){
                            fgets(insert_helper,2,stdin);
                            //printf("%s\n",insert_helper);
                        }
                        *insert_helper = '1';
                        insert_helper[1] = '1';
                    }else{
                        heap_int[i1] = (int)strtol(insert_polynom,errstr,0);
                    }
                }
                polynom_additional = create_polynom(info_current,pol_len,heap_int);
                free(heap_int);
                show_pol(polynom_current);
                show_pol(polynom_additional);
                break;

            case 53:
                insert_polynom_flag = 0;
                insert_action_flag = 0;
                break;
            default:
                printf("Некорректное значение\n");

                break;
        }
        while(insert_action_flag){
            printf("1) Сложить многочлены\n2) Вычесть из первого второй многочлен\n3)Умножить многочлены \n4) Умножить на число первый многочлен\n5) Умножить на число второй многочлен\n6) Композиция первого от второго\n7) Композиция второго от первого\n8) Вычисление значения двух многочленов\n9) Выход из программы\n");
            fgets(insert_action_type, 3, stdin);

            if (insert_polynom_type[1] != '\n') {
                insert_polynom_type[0] = '0';
                if (insert_polynom_type[0] != '\n') {
                    while ((insert_helper[0] != '\n') && (insert_helper[1] != '\n')) {
                        fgets(insert_helper, 2, stdin);
                        //printf("%s\n",insert_helper);
                    }
                    *insert_helper = '1';
                    insert_helper[1] = '1';
                }
            }
            switch(*insert_action_type){
                case 49:
                    polynom_result = sum_pol(polynom_current,polynom_additional);
                    show_pol(polynom_result);
                    delete_polynom(polynom_result);
                    break;
                case 50:
                    polynom_result = substr_pol(polynom_current,polynom_additional);
                    show_pol(polynom_result);
                    delete_polynom(polynom_result);
                    break;
                case 51:
                    polynom_result = mult_pol(polynom_current,polynom_additional);
                    show_pol(polynom_result);
                    delete_polynom(polynom_result);
                    break;
                case 52:
                    if (info_current->size == sizeof(int)){
                        fgets(insert_const,10,stdin);
                        if ((insert_const[1]!='\n')&&(insert_const[2]!='\n')&&(insert_const[3]!='\n')&&(insert_const[4]!='\n')&&(insert_const[5]!='\n')&&(insert_const[6]!='\n')&&(insert_const[7]!='\n')&&(insert_const[8]!='\n')&&(insert_const[9]!='\n')) {

                            if (insert_const[0] == '\n') {
                                printf("Некорректное значение\n");
                                break;
                            }
                            printf("Слишком большое значение\n");
                            while ((insert_helper[0] != '\n') && (insert_helper[1] != '\n')) {
                                fgets(insert_helper, 2, stdin);

                            }
                            *insert_helper = '1';
                            insert_helper[1] = '1';
                            break;
                        }

                        constant = malloc(sizeof(int));
                        *(int*)constant = (int)strtol(insert_const,errstr,0);
                        polynom_result = mult_const(polynom_current,constant);
                        free(constant);
                        show_pol(polynom_result);
                        free(polynom_result);
                    }
                    if (info_current->size == sizeof(double)){
                        fgets(insert_const,10,stdin);
                        if ((insert_const[1]!='\n')&&(insert_const[2]!='\n')&&(insert_const[3]!='\n')&&(insert_const[4]!='\n')&&(insert_const[5]!='\n')&&(insert_const[6]!='\n')&&(insert_const[7]!='\n')&&(insert_const[8]!='\n')&&(insert_const[9]!='\n')) {

                            if (insert_const[0] == '\n') {
                                printf("Некорректное значение\n");
                                break;
                            }
                            printf("Слишком большое значение\n");
                            while ((insert_helper[0] != '\n') && (insert_helper[1] != '\n')) {
                                fgets(insert_helper, 2, stdin);

                            }
                            *insert_helper = '1';
                            insert_helper[1] = '1';
                            break;
                        }

                        constant = malloc(sizeof(double));
                        *(double*)constant = (double)strtod(insert_const,errstr);
                        polynom_result = mult_const(polynom_current,constant);
                        free(constant);
                        show_pol(polynom_result);
                        free(polynom_result);
                    }
                    break;
                case 53:
                    if (info_current->size == sizeof(int)){
                        fgets(insert_const,10,stdin);
                        if ((insert_const[1]!='\n')&&(insert_const[2]!='\n')&&(insert_const[3]!='\n')&&(insert_const[4]!='\n')&&(insert_const[5]!='\n')&&(insert_const[6]!='\n')&&(insert_const[7]!='\n')&&(insert_const[8]!='\n')&&(insert_const[9]!='\n')) {

                            if (insert_polynom[0] == '\n') {
                                printf("Некорректное значение\n");
                                break;
                            }
                            printf("Слишком большое значение\n");
                            while ((insert_helper[0] != '\n') && (insert_helper[1] != '\n')) {
                                fgets(insert_helper, 2, stdin);

                            }
                            *insert_helper = '1';
                            insert_helper[1] = '1';
                            break;
                        }

                        constant = malloc(sizeof(int));
                        *(int*)constant = (int)strtol(insert_const,errstr,0);
                        polynom_result = mult_const(polynom_additional,constant);
                        free(constant);
                        show_pol(polynom_result);
                        free(polynom_result);
                    }
                    if (info_current->size == sizeof(double)){
                        fgets(insert_const,10,stdin);
                        if ((insert_const[1]!='\n')&&(insert_const[2]!='\n')&&(insert_const[3]!='\n')&&(insert_const[4]!='\n')&&(insert_const[5]!='\n')&&(insert_const[6]!='\n')&&(insert_const[7]!='\n')&&(insert_const[8]!='\n')&&(insert_const[9]!='\n')) {

                            if (insert_const[0] == '\n') {
                                printf("Некорректное значение\n");
                                break;
                            }
                            printf("Слишком большое значение\n");
                            while ((insert_helper[0] != '\n') && (insert_helper[1] != '\n')) {
                                fgets(insert_helper, 2, stdin);

                            }
                            *insert_helper = '1';
                            insert_helper[1] = '1';
                            break;
                        }

                        constant = malloc(sizeof(double));
                        *(double*)constant = (double)strtod(insert_const,errstr);
                        polynom_result = mult_const(polynom_additional,constant);
                        free(constant);
                        show_pol(polynom_result);
                        free(polynom_result);
                    }
                    break;
                case 54:
                    polynom_result = composition(polynom_current,polynom_additional);
                    show_pol(polynom_result);
                    free(polynom_result);
                    break;
                case 55:
                    polynom_result = composition(polynom_additional,polynom_current);
                    show_pol(polynom_result);
                    free(polynom_result);
                    break;
                case 56:
                    if (info_current->size == sizeof(int)){
                        fgets(insert_const,10,stdin);
                        if ((insert_const[1]!='\n')&&(insert_const[2]!='\n')&&(insert_const[3]!='\n')&&(insert_const[4]!='\n')&&(insert_const[5]!='\n')&&(insert_const[6]!='\n')&&(insert_const[7]!='\n')&&(insert_const[8]!='\n')&&(insert_const[9]!='\n')) {

                            if (insert_polynom[0] == '\n') {
                                printf("Некорректное значение\n");
                                break;
                            }
                            printf("Слишком большое значение\n");
                            while ((insert_helper[0] != '\n') && (insert_helper[1] != '\n')) {
                                fgets(insert_helper, 2, stdin);

                            }
                            *insert_helper = '1';
                            insert_helper[1] = '1';
                            break;
                        }

                        constant = malloc(sizeof(int));
                        *(int*)constant = (int)strtol(insert_const,errstr,0);
                        printf("Многочлен раз - %d\n",*(int*)pol_value(polynom_current,constant));
                        printf("Многочлен двас - %d\n",*(int*)pol_value(polynom_additional,constant));
                        free(constant);


                    }
                    if (info_current->size == sizeof(double)){
                        fgets(insert_const,10,stdin);
                        if ((insert_const[1]!='\n')&&(insert_const[2]!='\n')&&(insert_const[3]!='\n')&&(insert_const[4]!='\n')&&(insert_const[5]!='\n')&&(insert_const[6]!='\n')&&(insert_const[7]!='\n')&&(insert_const[8]!='\n')&&(insert_const[9]!='\n')) {

                            if (insert_const[0] == '\n') {
                                printf("Некорректное значение\n");
                                break;
                            }
                            printf("Слишком большое значение\n");
                            while ((insert_helper[0] != '\n') && (insert_helper[1] != '\n')) {
                                fgets(insert_helper, 2, stdin);

                            }
                            *insert_helper = '1';
                            insert_helper[1] = '1';
                            break;
                        }

                        constant = malloc(sizeof(double));
                        *(double*)constant = (double)strtod(insert_const,errstr);
                        printf("Многочлен раз - %lf\n",*(double*)pol_value(polynom_current,constant));
                        printf("Многочлен двас - %lf\n",*(double*)pol_value(polynom_additional,constant));
                        free(constant);


                    }
                    break;
                case 57:
                    insert_polynom_flag = 0;
                    insert_action_flag = 0;
                    break;

                default:
                    printf("Некорректное значение\n");

                    break;

            }
        }


    }



}
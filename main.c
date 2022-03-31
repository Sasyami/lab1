#include <stdlib.h>
#include <stdio.h>
#include "polynom.h"
#include "PolInfo.h"
#include "tests.h"
#include <stddef.h>

int main(){
    char* insert_polynom_type = malloc(3);
    int insert_polynom_flag = 1;
    char* insert_polynom_len = malloc(3);
    char* insert_action_type = malloc(3);
    int insert_action_flag = 1;

    struct PolInfo* info;

    int* zero_int = malloc(sizeof(int));

    *zero_int = 0;
    double* zero_double = malloc(sizeof(double));
    *zero_double = 0.0;
    double* minus_one_double = malloc(sizeof(double));
    int* minus_one_int = malloc(sizeof(int));
    *minus_one_double = -1.0;
    *minus_one_int = -1;

    double* chislo = malloc(sizeof(double));
    *chislo = 0.0;

    test_sum();
    test_substraction();
    test_mult();
    test_composition();
    test_else();
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
                info_current = create_info(sizeof(double), zero_double, &sum_double, &mult_double, minus_one_double,&add_double,&double_to_string,&comparator_double);
                polynom_current = random_pol(info_current);
                polynom_additional = random_pol(info_current);
                show_pol(polynom_current);
                show_pol(polynom_additional);
                break;
            case 50:
                info_current = create_info(sizeof(double), zero_double, &sum_double, &mult_double, minus_one_double,&add_double,&double_to_string,&comparator_double);
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
                info_current = create_info(sizeof(int), zero_int, &sum_int, &mult_int, minus_one_int,&add_int,&int_to_string,&comparator_int);
                polynom_current = random_pol(info_current);
                polynom_additional = random_pol(info_current);
                show_pol(polynom_current);
                show_pol(polynom_additional);
                break;
            case 52:
                info_current = create_info(sizeof(int), zero_int, &sum_int, &mult_int, minus_one_int,&add_int,&int_to_string,&comparator_int);
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

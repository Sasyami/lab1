//
// Created by User on 24.03.2022.
//

#include "polynom.h"
#include "PolInfo.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
void test_sum(){
    double* zero_double = (double*)malloc(sizeof(double));
    *zero_double = 0.0;
    double* minus_one_double = (double*)malloc(sizeof(double));
    *minus_one_double = -1.0;
    double massive[] = {0.0,-1.5,12323.25,-2332.125};
    struct PolInfo* info_double = create_info(sizeof(double),zero_double,&sum_double,&mult_double, minus_one_double,&add_double,&double_to_string,&comparator_double);
    struct polynom* pol1_double = random_pol(info_double);
    struct polynom* pol2_double = create_polynom(info_double,4,massive);
    struct polynom* polynom_double_result = sum_pol(pol1_double,pol2_double);
    printf("Сложение случайного и введенного полиномов\n");
    show_pol(pol1_double);
    show_pol(pol2_double);
    show_pol(polynom_double_result);
    struct polynom* polynom_double_zero = create_polynom_zero(info_double,12);
    printf("Сложение случайного и нулевого полиномов\n");
    delete_polynom(polynom_double_result);
    show_pol(polynom_double_zero);
    show_pol(pol1_double);
    polynom_double_result = sum_pol(pol1_double,polynom_double_zero);
    show_pol(polynom_double_result);
    delete_polynom(polynom_double_result);
    printf("Сложение нулевого и нулевого полиномов\n");
    polynom_double_result = sum_pol(polynom_double_zero,polynom_double_zero);
    show_pol(polynom_double_zero);
    show_pol(polynom_double_zero);
    show_pol(polynom_double_result);
    printf("Некорректное создание информации и многочлена\n");
    struct PolInfo* info_wrong = create_info(-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
    struct polynom* polynom_wrong = random_pol(info_wrong);
    show_pol(polynom_wrong);

    int* zero_int = (int*)malloc(sizeof(int));
    *zero_double = 0;
    int* minus_one_int = (int*)malloc(sizeof(int));
    *minus_one_int = -1;
    int massive_int[] = {0,-1,12323,-2332};
    struct PolInfo* info_int = create_info(sizeof(int),zero_int,&sum_int,&mult_int, minus_one_int,&add_int,&int_to_string,&comparator_int);
    struct polynom* pol1_int = random_pol(info_int);
    struct polynom* pol2_int = create_polynom(info_int,4,massive_int);
    struct polynom* polynom_int_result = sum_pol(pol1_int,pol2_int);
    printf("Сложение случайного и введенного полиномов\n");
    show_pol(pol1_int);
    show_pol(pol2_int);
    show_pol(polynom_int_result);
    struct polynom* polynom_int_zero = create_polynom_zero(info_int,12);
    printf("Сложение случайного и нулевого полиномов\n");
    delete_polynom(polynom_int_result);
    show_pol(polynom_int_zero);
    show_pol(pol1_int);
    polynom_int_result = sum_pol(pol1_int,polynom_int_zero);
    show_pol(polynom_int_result);
    delete_polynom(polynom_int_result);
    printf("Сложение нулевого и нулевого полиномов\n");
    polynom_int_result = sum_pol(polynom_int_zero,polynom_int_zero);
    show_pol(polynom_int_zero);
    show_pol(polynom_int_zero);
    show_pol(polynom_int_result);
}
void test_mult(){
    double* zero_double = (double*)malloc(sizeof(double));
    *zero_double = 0.0;
    double* minus_one_double = (double*)malloc(sizeof(double));
    *minus_one_double = -1.0;
    double massive[] = {0.0,-1.5,12323.25,-2332.125};
    struct PolInfo* info_double = create_info(sizeof(double),zero_double,&sum_double,&mult_double, minus_one_double,&add_double,&double_to_string,&comparator_double);
    struct polynom* pol1_double = random_pol(info_double);
    struct polynom* pol2_double = create_polynom(info_double,4,massive);
    struct polynom* polynom_double_result = mult_pol(pol1_double,pol2_double);
    printf("Умножение случайного и введенного полиномов\n");
    show_pol(pol1_double);
    show_pol(pol2_double);
    show_pol(polynom_double_result);
    struct polynom* polynom_double_zero = create_polynom_zero(info_double,12);
    printf("Умножение случайного и нулевого полиномов\n");
    delete_polynom(polynom_double_result);
    show_pol(polynom_double_zero);
    show_pol(pol1_double);
    polynom_double_result = mult_pol(pol1_double,polynom_double_zero);
    show_pol(polynom_double_result);
    delete_polynom(polynom_double_result);
    printf("Умножение нулевого и нулевого полиномов\n");
    polynom_double_result = mult_pol(polynom_double_zero,polynom_double_zero);
    show_pol(polynom_double_zero);
    show_pol(polynom_double_zero);
    show_pol(polynom_double_result);
    printf("Некорректное создание информации и многочлена\n");
    struct PolInfo* info_wrong = create_info(-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
    struct polynom* polynom_wrong = random_pol(info_wrong);
    show_pol(polynom_wrong);

    int* zero_int = (int*)malloc(sizeof(int));
    *zero_double = 0;
    int* minus_one_int = (int*)malloc(sizeof(int));
    *minus_one_int = -1;
    int massive_int[] = {0,-1,12323,-2332};
    struct PolInfo* info_int = create_info(sizeof(int),zero_int,&sum_int,&mult_int, minus_one_int,&add_int,&int_to_string,&comparator_int);
    struct polynom* pol1_int = random_pol(info_int);
    struct polynom* pol2_int = create_polynom(info_int,4,massive_int);
    struct polynom* polynom_int_result = mult_pol(pol1_int,pol2_int);
    printf("Умножение случайного и введенного полиномов\n");
    show_pol(pol1_int);
    show_pol(pol2_int);
    show_pol(polynom_int_result);
    struct polynom* polynom_int_zero = create_polynom_zero(info_int,12);
    printf("Умножение случайного и нулевого полиномов\n");
    delete_polynom(polynom_int_result);
    show_pol(polynom_int_zero);
    show_pol(pol1_int);
    polynom_int_result = mult_pol(pol1_int,polynom_int_zero);
    show_pol(polynom_int_result);
    delete_polynom(polynom_int_result);
    printf("Умножение нулевого и нулевого полиномов\n");
    polynom_int_result = mult_pol(polynom_int_zero,polynom_int_zero);
    show_pol(polynom_int_zero);
    show_pol(polynom_int_zero);
    show_pol(polynom_int_result);

}
void test_composition(){
    double* zero_double = (double*)malloc(sizeof(double));
    *zero_double = 0.0;
    double* minus_one_double = (double*)malloc(sizeof(double));
    *minus_one_double = -1.0;
    double massive[] = {0.0,-1.5,13.25,-2.125};
    struct PolInfo* info_double = create_info(sizeof(double),zero_double,&sum_double,&mult_double, minus_one_double,&add_double,&double_to_string,&comparator_double);
    struct polynom* pol1_double = random_pol(info_double);
    struct polynom* pol2_double = create_polynom(info_double,4,massive);
    struct polynom* polynom_double_result = composition(pol1_double,pol2_double);
    printf("Композиция случайного и введенного полиномов\n");
    show_pol(pol1_double);
    show_pol(pol2_double);
    show_pol(polynom_double_result);
    struct polynom* polynom_double_zero = create_polynom_zero(info_double,12);
    printf("Композиция случайного и нулевого полиномов\n");
    delete_polynom(polynom_double_result);
    show_pol(polynom_double_zero);
    show_pol(pol1_double);
    polynom_double_result = composition(pol1_double,polynom_double_zero);
    show_pol(polynom_double_result);
    delete_polynom(polynom_double_result);
    printf("Композиция нулевого и нулевого полиномов\n");
    polynom_double_result = composition(polynom_double_zero,polynom_double_zero);
    show_pol(polynom_double_zero);
    show_pol(polynom_double_zero);
    show_pol(polynom_double_result);
    printf("Некорректное создание информации и многочлена\n");
    struct PolInfo* info_wrong = create_info(-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
    struct polynom* polynom_wrong = random_pol(info_wrong);
    show_pol(polynom_wrong);

    int* zero_int = (int*)malloc(sizeof(int));
    *zero_double = 0;
    int* minus_one_int = (int*)malloc(sizeof(int));
    *minus_one_int = -1;
    int massive_int[] = {0,-1,12,-22};
    struct PolInfo* info_int = create_info(sizeof(int),zero_int,&sum_int,&mult_int, minus_one_int,&add_int,&int_to_string,&comparator_int);
    struct polynom* pol1_int = random_pol(info_int);
    struct polynom* pol2_int = create_polynom(info_int,4,massive_int);
    struct polynom* polynom_int_result = composition(pol1_int,pol2_int);
    printf("Композиция случайного и введенного полиномов\n");
    show_pol(pol1_int);
    show_pol(pol2_int);
    show_pol(polynom_int_result);
    struct polynom* polynom_int_zero = create_polynom_zero(info_int,12);
    printf("Композиция случайного и нулевого полиномов\n");
    delete_polynom(polynom_int_result);
    show_pol(pol1_int);
    show_pol(polynom_int_zero);

    polynom_int_result = composition(pol1_int,polynom_int_zero);
    show_pol(polynom_int_result);
    delete_polynom(polynom_int_result);
    printf("Композиция нулевого и нулевого полиномов\n");
    polynom_int_result = composition(polynom_int_zero,polynom_int_zero);
    show_pol(polynom_int_zero);
    show_pol(polynom_int_zero);
    show_pol(polynom_int_result);
}
void test_substraction(){
    double* zero_double = (double*)malloc(sizeof(double));
    *zero_double = 0.0;
    double* minus_one_double = (double*)malloc(sizeof(double));
    *minus_one_double = -1.0;
    double massive[] = {0.0,-1.5,12323.25,-2332.125};
    struct PolInfo* info_double = create_info(sizeof(double),zero_double,&sum_double,&mult_double, minus_one_double,&add_double,&double_to_string,&comparator_double);
    struct polynom* pol1_double = random_pol(info_double);
    struct polynom* pol2_double = create_polynom(info_double,4,massive);
    struct polynom* polynom_double_result = substr_pol(pol1_double,pol2_double);
    printf("Вычитание случайного и введенного полиномов\n");
    show_pol(pol1_double);
    show_pol(pol2_double);
    show_pol(polynom_double_result);
    struct polynom* polynom_double_zero = create_polynom_zero(info_double,12);
    printf("Вычитание случайного и нулевого полиномов\n");
    delete_polynom(polynom_double_result);
    show_pol(pol1_double);
    show_pol(polynom_double_zero);

    polynom_double_result = substr_pol(pol1_double,polynom_double_zero);
    show_pol(polynom_double_result);
    delete_polynom(polynom_double_result);
    printf("Вычитание нулевого и нулевого полиномов\n");
    polynom_double_result = substr_pol(polynom_double_zero,polynom_double_zero);
    show_pol(polynom_double_zero);
    show_pol(polynom_double_zero);
    show_pol(polynom_double_result);
    printf("Некорректное создание информации и многочлена\n");
    struct PolInfo* info_wrong = create_info(-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
    struct polynom* polynom_wrong = random_pol(info_wrong);
    show_pol(polynom_wrong);

    int* zero_int = (int*)malloc(sizeof(int));
    *zero_double = 0;
    int* minus_one_int = (int*)malloc(sizeof(int));
    *minus_one_int = -1;
    int massive_int[] = {0,-1,12323,-2332};
    struct PolInfo* info_int = create_info(sizeof(int),zero_int,&sum_int,&mult_int, minus_one_int,&add_int,&int_to_string,&comparator_int);
    struct polynom* pol1_int = random_pol(info_int);
    struct polynom* pol2_int = create_polynom(info_int,4,massive_int);
    struct polynom* polynom_int_result = substr_pol(pol1_int,pol2_int);
    printf("Вычитание случайного и введенного полиномов\n");
    show_pol(pol1_int);
    show_pol(pol2_int);
    show_pol(polynom_int_result);
    struct polynom* polynom_int_zero = create_polynom_zero(info_int,12);
    printf("Вычитание случайного и нулевого полиномов\n");
    delete_polynom(polynom_int_result);
    show_pol(pol1_int);
    show_pol(polynom_int_zero);

    polynom_int_result = substr_pol(pol1_int,polynom_int_zero);
    show_pol(polynom_int_result);
    delete_polynom(polynom_int_result);
    printf("Вычитание нулевого и нулевого полиномов\n");
    polynom_int_result = substr_pol(polynom_int_zero,polynom_int_zero);
    show_pol(polynom_int_zero);
    show_pol(polynom_int_zero);
    show_pol(polynom_int_result);
}
void test_else(){
    double* zero_double = (double*)malloc(sizeof(double));
    *zero_double = 0.0;
    double* minus_one_double = (double*)malloc(sizeof(double));
    *minus_one_double = -1.0;
    double massive[] = {0.0,-1.5,13.25,-2.125};
    double chislo = -8.5;
    struct PolInfo* info_double = create_info(sizeof(double),zero_double,&sum_double,&mult_double, minus_one_double,&add_double,&double_to_string,&comparator_double);
    struct polynom* pol1_double = random_pol(info_double);
    struct polynom* polynom_double_result = mult_const(pol1_double,&chislo);
    printf("Умножение на число %lf\n",chislo);
    show_pol(pol1_double);
    show_pol(polynom_double_result);
    printf("Умножение на 0\n");
    polynom_double_result = mult_const(pol1_double,zero_double);
    show_pol(pol1_double);
    show_pol(polynom_double_result);
    int* zero_int= (int*)malloc(sizeof(int));
    *zero_int = 0;
    int* minus_one_int = (int*)malloc(sizeof(int));
    *minus_one_int = -1;

    int chislo_int = -8;
    struct PolInfo* info_int = create_info(sizeof(int),zero_int,&sum_int,&mult_int, minus_one_int,&add_int,&int_to_string,&comparator_int);
    struct polynom* pol1_int = random_pol(info_int);
    struct polynom* polynom_int_result = mult_const(pol1_int,&chislo_int);
    printf("Умножение на число %d\n",chislo_int);
    show_pol(pol1_int);
    show_pol(polynom_int_result);
    printf("Умножение на 0\n");
    polynom_int_result = mult_const(pol1_int,zero_int);
    show_pol(pol1_int);
    show_pol(polynom_int_result);


    printf("Подстановка числа %lf\n",chislo);
    show_pol(pol1_double);
    printf("%lf\n",*(double*)pol_value(pol1_double,&chislo));
    printf("Подстановка 0\n");

    show_pol(pol1_double);
    printf("%lf\n",*(double*)pol_value(pol1_double,zero_double));


    printf("Подстановка числа %d\n",chislo_int);
    show_pol(pol1_int);
    printf("%d\n",*(int*)pol_value(pol1_int,&chislo_int));
    printf("Подстановка 0\n");

    show_pol(pol1_int);
    printf("%d\n",*(int*)pol_value(pol1_int,zero_int));
}

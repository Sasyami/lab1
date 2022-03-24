//
// Created by User on 17.03.2022.
//
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "PolInfo.h"
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
char* int_to_string(void* a){
    if (a==NULL){
        return NULL;
    }
    int i = 0;
    int j;
    int k = 0;
    int a1;
    a1 = abs(*(int*)a);

    char* bufer = malloc(sizeof(char));
    char* result = malloc(sizeof(char));
    if (a1 == 0){
        result = realloc(result,sizeof(char));
        *result = '0';
        result[1] = '\0';
        free(bufer);
        return result;
    }
    if (*(int*)a<0){
        result[0] = '-';
        k++;
        i++;
    }
    while((a1)>0){
        result = realloc(result,sizeof(char));
        result[i] = (char)(48+(a1)%10);
        a1 = a1/10;
        i++;
    }

    for(j=k;j<(i+k)/2;j++){
        *bufer = result[j];
        result[j] = result [i-1-(j-k)];
        result[i-1-(j-k)] =*bufer;
    }
    result[i] = '\0';
    free(bufer);
    return result;
}
char* double_to_string(void* a){
    if (a==NULL){
        return NULL;
    }

    int i =0;
    int j,k = 0;
    char* result = malloc(sizeof(char));
    char* bufer = malloc(sizeof(char));
    int a1 = (int)(*(double*)a);
    if(*(double*)a == 0.0){
        result = realloc(result,sizeof(char));
        *result = '0';
        result[1] = '\0';
        free(bufer);
        return result;

    }
    double a2 = *(double*)a- (double)a1;
    if (a2<0){
        a2 = a2*(-1.0);
    }
    a1 = abs(a1);
    if (*(double*)a<0){
        result[0] = '-';
        i++;
        k++;
    }
    if (a1 == 0){
        result[0] = '0';
        i++;
    }
    while (a1>0){
        result = realloc(result,sizeof(char));
        result[i] = (char)(48+(a1)%10);

        a1 = a1/10;
        i++;
    }

    for(j=k;j<(i+k)/2;j++){
        *bufer = result[j];
        result[j] = result [i-1-(j-k)];
        result[i-1-(j-k)] =*bufer;
    }


    result = realloc(result,sizeof(char));
    result[i] = '.';
    i++;
    while (a2>0){
        result = realloc(result,sizeof(char));
        a2 = a2*((double)10);
        result[i] = (char)(48+(int)a2);
        a2 = a2 - (double)((int)a2);
        i++;
    }
    if(result[i-1] == '.'){
        result = realloc(result,2*sizeof(char));
        result[i] = '0';
        result[i+1] = '\0';
        return result;
    }
    result[i] = '\0';

    return result;

}


struct polynom{
    struct PolInfo* info;
    int length;
    void** numbers;
};

void delete_polynom(struct polynom* poly) {
    int i;
    if (poly != NULL){
        for (i = 0; i < poly->length; i++) {
            if((poly->numbers)[i]!=NULL) {
                free((poly->numbers)[i]);
            }
        }
        if (poly->numbers!=NULL) {
            free(poly->numbers);
        }
        free(poly);
    }
}

char** polynom_to_strings(struct polynom* poly){
    if (poly == NULL){
        return NULL;
    }
    int i;
    char** new_strings = (char**)malloc(sizeof(char*)*poly->length);
    for (i = 0;i<poly->length;i++){
        new_strings[i] = poly->info->to_string(poly->numbers[i]);
    }
    return new_strings;
}
void show_pol(struct polynom* poly){
    if (poly!=NULL) {
        int len = poly->length;

        int i;
        //printf("%lf\n",*(double*)poly->numbers[0]);
        printf("%s", poly->info->to_string(poly->numbers[0]));
        for (i = 1; i < len; i++) {
            printf(" + %s*x^%d", poly->info->to_string(poly->numbers[i]), i);
        }
        printf("\n");
    }else{
        printf("NULL\n");
    }

}
struct polynom* create_polynom_zero(struct PolInfo *info, int razmer){
    struct polynom *new_polynom = malloc(sizeof(struct polynom));
    if ((info ==NULL) ||(razmer<0)){
        return NULL;
    }
    new_polynom ->info = info;
    new_polynom -> length = razmer;
    new_polynom -> numbers = malloc((sizeof(void*))*razmer);
    int i;

    for (i = 0;i<razmer;i++){
        (new_polynom->numbers)[i] = info->sum(info->zero,info->zero);


    }

    return new_polynom;

}
struct polynom* create_polynom(struct PolInfo *info,int razmer,void* numbers){
    struct polynom *new_polynom = malloc(sizeof(struct polynom));
    int i;
    if ((info ==NULL) ||(razmer<0)){
        return NULL;
    }
    new_polynom ->info = info;
    new_polynom -> length = razmer;
    new_polynom -> numbers = malloc((sizeof(void*))*razmer);

    for (i = 0;i<razmer;i++){
        (new_polynom->numbers)[i] = info->sum(numbers+i*(info->size),info->zero);

    }
    return new_polynom;
}
struct polynom* random_pol(struct PolInfo* info){
    if (info == NULL){

        return NULL;
    }

    struct polynom* random_poly = malloc(sizeof(struct polynom));
    random_poly = create_polynom_zero(info,2+rand()%7);
    int i,j;
    void* one = info->mult(info->minus_one,info->minus_one);
    for (i = 0; i < random_poly -> length; i++){
        for(j = 0;j<1+rand()%100;j++){

            (random_poly -> numbers)[i] = info->add((random_poly -> numbers)[i],one);

        }

    }
    for (i = 0; i < random_poly -> length; i++){
        for(j = 0;j<1+rand()%100;j++){
            (random_poly -> numbers)[i] = info->add((random_poly -> numbers)[i],info -> minus_one);

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
    int res_len = max_int(pol1->length, pol2->length);
    struct polynom* pol_res = create_polynom_zero(pol1->info, res_len);


    int i;

    for (i=0;i<res_len;i++){



        if (i<pol1->length){

            (pol_res->numbers)[i] = pol1->info->add((pol_res->numbers)[i],(pol1->numbers)[i]);


        }
        if (i<(pol2->length)){

            (pol_res->numbers)[i] = pol1->info->add((pol_res->numbers)[i], (pol2->numbers)[i]);



        }
        //show_pol(pol_res);


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
    pol_res = create_polynom_zero(pol1->info, pol1->length + pol2->length - 1);


    void* multiply;
    for (i = 0;i<pol1->length; i++){
        for (j = 0;j<pol2->length; j++){
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
    for (i=0;i<pol->length; i++){

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
    multiply = poly->info->mult(value,(poly->numbers)[poly->length - 1]);

    res = poly->info->sum(multiply,poly->numbers[poly->length - 2]);
    free(multiply);

    for (i = poly->length - 2; i > 0; i = i - 1){
        multiply = poly->info->mult(value,res);
        free(res);
        res = poly->info->sum(multiply,(poly->numbers)[i-1]);

        free(multiply);
    }
    return res;
}
struct polynom* pol_copy(struct polynom* poly){
    int i;
    if (poly == NULL){
        return NULL;
    }
    struct polynom* pol_res = malloc(sizeof(struct polynom));

    pol_res->info = poly->info;
    pol_res->length = poly->length;
    pol_res -> numbers = malloc((sizeof(void*))*(pol_res->info->size));

    for (i = 0;i< pol_res->length; i++){
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


    struct polynom* pol_res = create_polynom_zero(pol1->info, (pol1->length - 1) * (pol2->length - 1));
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
    //show_pol(pol_res);
    return pol_res;


}
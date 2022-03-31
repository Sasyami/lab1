//
// Created by User on 17.03.2022.
//

#ifndef LAB1_POLYNOM_H
#define LAB1_POLYNOM_H


int max_int(int a1, int a2);
int min_int(int a1,int a2);
void* sum_int(void* a1, void* a2);
void* sum_double(void* a1, void* a2);
void* mult_double(void* a1,void* a2);
void* mult_int(void* a1, void* a2);
void* add_int(void* a1,void* a2);
void* add_double(void* a1,void* a2);
char* int_to_string(void*);
char* double_to_string(void*);
int comparator_int(void*,void*);
int comparator_double(void*,void*);

struct polynom{
    struct PolInfo* info;
    int length;
    void** numbers;
};
void delete_polynom(struct polynom* poly);

void show_pol(struct polynom* poly);
struct polynom* create_polynom_zero(struct PolInfo *info, int length);
struct polynom* create_polynom(struct PolInfo *info,int razmer,void* numbers);

struct polynom* random_pol(struct PolInfo* info);
struct polynom* sum_pol(struct polynom* pol1, struct polynom* pol2);
struct polynom* mult_pol(struct polynom* pol1,struct polynom* pol2);
struct polynom* mult_const(struct polynom* pol, void* a);
struct polynom* substr_pol(struct polynom* pol1,struct polynom* pol2);
void* pol_value(struct polynom* poly, void* value);
struct polynom* pol_copy(struct polynom* poly);
struct polynom* composition(struct polynom* pol1,struct polynom* pol2);
#endif //LAB1_POLYNOM_H

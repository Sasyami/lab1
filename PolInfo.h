//
// Created by User on 24.03.2022.
//

#ifndef LAB1_POLINFO_H
#define LAB1_POLINFO_H
#include <stddef.h>
struct PolInfo{
    size_t size;
    void* (*sum)( void* , void* );
    void* zero;
    void* (*mult)( void* , void* );

    void* minus_one;
    void* (*add)(void* , void*);
    char* (*to_string)(void*);

};
struct PolInfo* create_info(size_t size,void* zero,void* (*sum)(void*, void*),void* (*mult)(void*,void*), void* minus_one,void* add,char* (*to_string)(void*));
int info_equal(struct PolInfo* inf1, struct PolInfo* inf2);
#endif //LAB1_POLINFO_H

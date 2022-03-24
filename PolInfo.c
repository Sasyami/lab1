//
// Created by User on 24.03.2022.
//

#include <limits.h>
#include <stdlib.h>
struct PolInfo{
    size_t size;
    void* (*sum)( void* , void* );
    void* zero;
    void* (*mult)( void* , void* );
    //void* (*substr)( void*,void*);
    void* minus_one;
    void* (*add)(void* , void*);
    char* (*to_string)(void*);

};
struct PolInfo* create_info(size_t size,void* zero,void* (*sum)(void*, void*),void* (*mult)(void*,void*), void* minus_one,void* (*add)(void*,void*),char* (*to_string)(void*) ){
    struct PolInfo* new_info = malloc(sizeof(struct PolInfo));
    if ((zero == NULL) || (sum == NULL)|| (mult == NULL)|| (minus_one == NULL)|| (add == NULL)|| (to_string == NULL)){
        return NULL;
    }
    new_info -> size = (size_t)size;
    new_info -> zero = zero;
    new_info -> sum = sum;
    new_info -> mult = mult;
    new_info -> minus_one = minus_one;
    new_info -> add = add;
    new_info->to_string = to_string;
    return new_info;
}
int info_equal(struct PolInfo* inf1, struct PolInfo* inf2){
    if ((inf1->mult == inf2->mult)&&(inf1->size == inf2->size)&&(inf1->sum == inf2->sum)){
        return 1;
    }
    return 0;

}
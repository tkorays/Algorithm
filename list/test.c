#include "xlist.h"
#include "xlist_arr_impl.h"
#include <stdio.h>

int main(){
    xlist* lst = 0;
    xlist_reg_func(xlist_arr_get_func());
    lst = xlist_create(45);
    printf("Size of lst:%d\n",lst->size);
    xlist_destroy(&lst);
    if(0==lst){
        printf("list has been destroyed\n");
    }
    return 0;
}

#include "xlist.h"
#include <stdio.h>

xadp_list* create_list(int size){
    printf("%d size list has been created!\n",size);
    return 0;
}

int main(){

    xadp_list_func f;
    f.fun_create = create_list;
    xadp_list_reg_func(&f);
    printf("ok\n");
    xadp_list_create(5);
    return 0;
}

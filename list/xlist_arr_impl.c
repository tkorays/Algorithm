#include "xlist_arr_impl.h"
#include "xlist.h"
#include "stdlib.h"

xlist_func g_xlist_arr_func;

xlist* create_list(int size){
    xlist* lst;
    if(size<=0){
        return 0;
    }
    lst = (xlist*)malloc(sizeof(xlist));
    if(lst==0){
        return 0;
    }
    lst->size = size;
    lst->entry=0;
    return lst;
}
void destroy_list(xlist** lst){
    if(0==lst){
        return ;
    }
    if(0==*lst){
        return ;
    }
    free(*lst);
    *lst=0;
}


void* xlist_arr_get_func(){
    g_xlist_arr_func.create = create_list;
    g_xlist_arr_func.destroy =  destroy_list;
    g_xlist_arr_func.set = (xlist_set_func)1;
    g_xlist_arr_func.get= (xlist_get_func)1;
    g_xlist_arr_func.remove = (xlist_remove_func)1;
    g_xlist_arr_func.pop = (xlist_pop_func)1;
    g_xlist_arr_func.valid = 49;
    return &g_xlist_arr_func;
}

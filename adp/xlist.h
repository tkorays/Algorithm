#ifndef __XLIST_H__
#define __XLIST_H__



typedef struct {
    int size;
    
} xadp_list;

typedef xadp_list*(*xlist_create_func)(int);
typedef void(*xlist_destroy_func)(xadp_list**);

typedef struct {
    xlist_create_func fun_create;
    xlist_destroy_func fun_destroy;
} xadp_list_func;

xadp_list_func g_xlist_func;

int xadp_list_reg_func(xadp_list_func* func);

#define xadp_list_create(size) g_xlist_func.fun_create(size)
#define xadp_list_destroy(lst) g_xlist_func.fun_destroy(lst)



#endif // __XLIST_H__

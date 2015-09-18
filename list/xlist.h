#ifndef __XLIST_H__
#define __XLIST_H__

typedef struct {
    int size;
    void* entry;
} xlist;

typedef xlist* (*xlist_create_func)(int);
typedef void   (*xlist_destroy_func)(xlist**);
typedef void*  (*xlist_get_func)(xlist*,int);
typedef void   (*xlist_set_func)(xlist*,int,void*);
typedef void   (*xlist_remove_func)(xlist*,int);
typedef void   (*xlist_pop_func)(xlist*);

typedef struct {
    xlist_create_func create;
    xlist_destroy_func destroy;
    xlist_get_func get;
    xlist_set_func set;
    xlist_remove_func remove;
    xlist_pop_func pop;
    int valid;
} xlist_func;

void xlist_reg_func(xlist_func* f);
int xlist_func_valid();
xlist* xlist_create(int size);
void xlist_destroy(xlist** lst);
void* xlist_get(xlist* lst,int idx);
void xlist_set(xlist* lst,int idx,void* value);


#endif // __XLIST_H__

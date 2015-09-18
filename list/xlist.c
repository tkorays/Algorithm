#include "xlist.h"

xlist_func g_xlist_func;

int xlist_func_valid(){
    return g_xlist_func.valid;
}

void xlist_reg_func(xlist_func* f){
    if(0==f){
        g_xlist_func.valid = 0;
        return;
    }
    g_xlist_func.create = f->create;
    g_xlist_func.destroy = f->destroy;
    g_xlist_func.get = f->get;
    g_xlist_func.set = f->set;
    g_xlist_func.remove = f->remove;
    g_xlist_func.pop = f->pop;
    g_xlist_func.valid = f->valid;
}


xlist* xlist_create(int size){
    return g_xlist_func.create(size);
}

void xlist_destroy(xlist** lst){
    g_xlist_func.destroy(lst);
}

void* xlist_get(xlist* lst,int idx){
    return g_xlist_func.get(lst,idx);
}

void xlist_set(xlist* lst,int idx,void* value){
    g_xlist_func.set(lst,idx,value);
}


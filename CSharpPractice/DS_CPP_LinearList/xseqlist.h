#ifndef XSEQLIST_H
#define XSEQLIST_H

#define MAX_SIZE 100

#include "xobject.h"
template <class T>
class XSeqList:XObject
{
    public:
        /** Default constructor */
        XSeqList();
        /** Default destructor */
        virtual ~XSeqList();
        int Count();
        bool Contains(T k);
        bool Add(T k);
        bool Insert(T k,int index);
        //bool AddRange(XSeqList);
        bool RemoveByIndex(int index);
        //bool RemoveByValue(T k);
        int IndexOf(T k);
        T GetByIndex(int index);
    protected:
    private:
        T items[MAX_SIZE];
        int count;
};

template <class T>
XSeqList<T>::XSeqList()
{
    this->count = 0;
}
template <class T>
XSeqList<T>::~XSeqList()
{
    //dtor
}
template <class T>
int XSeqList<T>::Count(){
    return this->count;
}

template <class T>
bool XSeqList<T>::Contains(T k){
    for(int i=0;i<this->count;i++){
        if (this->items[i]==k){
            return true;
        }
    }
    return false;
}

template <class T>
bool XSeqList<T>::Add(T k){
    if (this->count == MAX_SIZE){
        return false;
    }else{

        items[this->count] = k;
        this->count++;
        return true;
    }
}

template <class T>
bool XSeqList<T>::Insert(T k,int index){
    if (this->count ==  MAX_SIZE){
        return false;
    }else{
        for(int i=this->count;i>index;i--){
            this->items[i] = this->items[i-1];
        }
        this->items[index] = k;
        this->count ++;
        return true;
    }
}

template <class T>
bool XSeqList<T>::RemoveByIndex(int index){
    if (this->count < index+1){
        return false;
    }else{
        for(int i=index;i<this->count;i++){
            this->items[i] = this->items[i+1];
        }
        this->count --;
        return true;
    }
}

template <class T>
int XSeqList<T>::IndexOf(T k){
    for(int i=0;i<this->count;i++){
        if (k==this->items[i]){
            return i;
        }
    }
    return -1;
}

template <class T>
T XSeqList<T>::GetByIndex(int index){
    if(index<0||index>this->Count()){
        return false;
    }else{
        return this->items[index];
    }
}


#endif // XSEQLIST_H

#include <malloc.h>

#define MAX_SIZE_OF_ARRAY
#define TYPE_INT_P malloc(sizeof(int)) 
#define TYPE_FLOAT_P malloc(sizeof(float))
#define TYPE_DOUBLE_P malloc(sizeof(double))
#define TYPE_CHAR_P malloc(sizeof(char))

#define SUCC 0
#define OUT_OF_RANGE 1

typedef struct{
	int capacity;
	int size;
	void** items;
} SeqList;

SeqList* InitSeqList(int c,void* t){
	SeqList* L;
	L = malloc(sizeof(SeqList));	
	L->capacity = c;
        L->items = (__typeof__(t))malloc(sizeof(__typeof__(t))*c);
	L->size = 0;
	return L;
}

int SeqListAdd(SeqList* L,void* t){
	int count;
	int org_capacity;
	if(L->size < L->capacity - 1){
		L->items[L->size] = t;
		L->size ++;
	}else{
		org_capacity = L->capacity;
		L->capacity *=2;
		void** tmp = (__typeof__(t))malloc(sizeof(__typeof__(t))*L->capacity);
		for(count = 0;count < org_capacity;count++){
			tmp[count] = L->items[count];
		}
		L->items = tmp;
		L->items[L->size] = t;
		L->size ++;
	}
	return SUCC;
}





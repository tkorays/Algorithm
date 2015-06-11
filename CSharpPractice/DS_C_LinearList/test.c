#include <stdio.h>
#include "LinearList.c"

int main(int argc, char const* argv[])
{
	int *t;
	*t = 10;
	SeqList* L = InitSeqList(10,TYPE_INT_P);
	printf("%d\n",L->capacity);
	SeqListAdd(L,t);
	//printf("%d\n",(int)L->items[0]);
	free(L->items);
	return 0;
}

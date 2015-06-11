
#include <stdio.h>


int violentMatch(const char* s, int ls, const char* p, int lp){
	int i=0,j=0;
	while(i<ls && j<lp){
		if(s[i]==p[j]){
			i++;
			j++;
		}else{
			i=i-j+1;
			j=0;
		}
	}
	if(j==lp){
		return i-j;
	}else{
		return -1;
	}
}

int main(int argc,char** argv){
	const char* a = "ihavetwoapples";
	const char* b = "apple";
	printf("%d\n",violentMatch(a,strlen(a),b,strlen(b)));
	return 0;
}

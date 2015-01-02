#include <stdio.h>
#include <stdlib.h>

int violentMatch(const char* s, int ls, const char* p, int lp){
	int i,j;
	for(i=0;i<ls;i++){
		for(j=0;j<lp;j++){
			if(s[i]!=p[j]) break;
		}
		if(j>=lp){
			return i;
		}else{
			i=i-(j-1);
		}
	}
	if(i>=ls){
		i=-1;
	}
	return i;
}

int main(int argc,char** argv){
	const char* a = "abcbcbcde";
	const char* b = "cbcbd";
	printf("%d\n",violentMatch(a,strlen(a),b,strlen(b));
	return 0;
}

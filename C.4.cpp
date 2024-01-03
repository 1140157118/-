#include<bits/stdc++.h>
using namespace std;
#define Max 100
void ge(char *p){
	int n=0,j=0,i;
	char q[Max];
	for(i=0;i<strlen(p);i++){
		if(n){
			q[j]=p[i];
			j++;
			if(p[i]==' '||p[i]=='.'||p[i]=='?'||p[i]=='!')
			n=0;
		}else {
			if(p[i]!=' '){
			q[j]=p[i];
			j++;
			n++;
			}
		}
	}
	q[j]='\0';
	strcpy(p,q);
	free(q);
} 
int main(){
	char p[Max];
	gets(p);
	ge(p);
	printf("%s",p);
	return 0;
}

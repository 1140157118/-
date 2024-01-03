#include<bits/stdc++.h>
using namespace std;
#define Max 100
char  *baoli(char *p){
	int n=strlen(p);
	int s,f;
	s=f=0;
	int i,j;
	for(i=0;i<n;i++){
		int l;
		l=i-1;
		int r=i+1;
		while(l>=0&&r<n&&p[l]==p[r]){
			r++;
			l--;
		}
		if(r-l-1>f){
			s=l+1;
			f=r-l-1;
		}
	}
	p[s+f]='\0';
	return p+s;
} 
int main(){
	char p[Max];
	gets(p);
	char *q;
	q=baoli(p);
	printf("%s",q);
	return 0;
}

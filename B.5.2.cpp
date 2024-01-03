#include<bits/stdc++.h>
using namespace std;
#define Max 100
char *ma(char *p){
	int i;
	int s,f;
	int c;
	s=f=0;
	int n=strlen(p);
	for(i=0;i<n;i=i+c){
		c=1;
		int l=i-1;
		int r=i+1;
		while(r<n&&p[i]==p[r]){
			r++;
			c++;
		}
		while(l>=0&&r<n&&p[l]==p[r]){
			l--;
			r++;
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
	q=ma(p);
	printf("%s",q);
	return 0;
}

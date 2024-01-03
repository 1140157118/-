#include<bits/stdc++.h>
using namespace std;
#define Max 100
bool pan(char *p,char *q){
	if(p[0]==0&&q[0]==0)
	return true;
	if(p[0]!=0&&q[0]==0)
	return false;
	if(q[1]=='*'){
		if(p[0]==q[0]||(q[0]=='.'&&p[0]!=0)){
			return pan(p+1,q+2)||pan(p+1,q)||pan(p,q+2); 
		}else{
			return pan(p,q+2);
		}
	}
	if(q[0]==p[0]||(q[0]=='.'&&p[0]!=0))
	return pan(p+1,q+1);
	return false;
}
bool zhen(char *p,char *q){
	if(p==NULL||q==NULL)
	return false;
	return pan(p,q);
}
int main(){
	char p[Max],q[Max];
	gets(p);
	gets(q);
	if(zhen(p,q))
	printf("true");
	else
	printf("false");
	return 0;
}

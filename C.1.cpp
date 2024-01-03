#include<bits/stdc++.h>
using namespace std;
void zhao(int m){
	int f,s,t,min;
    f=s=t=min=0;
	while(m-25>=0){
		f++;
		m=m-25;
	}
	while(m-10>=0){
		s++;
		m=m-10;
	}
	while(m-5>=0){
		t++;
		m=m-5;
	}
	while(m-1>=0){
		min++;
		m--;
	}
	if(f>0)
	printf("%d个25分硬币",f);
	if(s>0)
	printf("%d个10分硬币",s);
	if(t>0)
	printf("%d个5分硬币",t);
	if(min>0)
	printf("%d个1分硬币",min);
}
int main(){
	int m;
	printf("找零多少分钱\n");
	scanf("%d",&m);
	zhao(m);
	return 0;
}

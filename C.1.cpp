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
	printf("%d��25��Ӳ��",f);
	if(s>0)
	printf("%d��10��Ӳ��",s);
	if(t>0)
	printf("%d��5��Ӳ��",t);
	if(min>0)
	printf("%d��1��Ӳ��",min);
}
int main(){
	int m;
	printf("������ٷ�Ǯ\n");
	scanf("%d",&m);
	zhao(m);
	return 0;
}

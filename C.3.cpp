#include<bits/stdc++.h>
using namespace std;
#define Max 100
typedef struct{
	char a[Max];
	int t;
}jinzhi;
void cushi(jinzhi *&p){
	p=(jinzhi*)malloc(sizeof(jinzhi));
	p->t=-1;
}
void er(jinzhi *&p,int n){
	if(n==0)
	return;
	if(n%2==0){
		p->t++;
		p->a[p->t]='0';
	}else{
		p->t++;
		p->a[p->t]='1';
	}
	er(p,n/2);
}
void ba(jinzhi *&p,int n){
	if(n==0)
	return ;
	p->t++;
	if(n%8==0){
		p->a[p->t]='0';
	}else if(n%8==1){
		p->a[p->t]='1';
	}else if(n%8==2){
		p->a[p->t]='2';
	}else if(n%8==3){
		p->a[p->t]='3';
	}else if(n%8==4){
		p->a[p->t]='4';
	}else if(n%8==5){
		p->a[p->t]='5';
	}else if(n%8==6){
		p->a[p->t]='6';
	}else if(n%8==7){
		p->a[p->t]='7';
	}
	ba(p,n/8);
}
void shiliu(jinzhi *&p,int n){
	if(n==0)
	return;
		p->t++;
	if(n%16==0){
		p->a[p->t]='0';
	}else if(n%16==1){
		p->a[p->t]='1';
	}else if(n%16==2){
		p->a[p->t]='2';
	}else if(n%16==3){
		p->a[p->t]='3';
	}else if(n%16==4){
		p->a[p->t]='4';
	}else if(n%16==5){
		p->a[p->t]='5';
	}else if(n%16==6){
		p->a[p->t]='6';
	}else if(n%16==7){
		p->a[p->t]='7';
	}else if(n%16==8){
		p->a[p->t]='8';
	}else if(n%16==9){
		p->a[p->t]='9';
	}else if(n%16==10){
		p->a[p->t]='A';
	}else if(n%16==12){
		p->a[p->t]='C';
	}else if(n%16==13){
		p->a[p->t]='D';
	}else if(n%16==11){
		p->a[p->t]='B';
	}else if(n%16==14){
		p->a[p->t]='E';
	}else{
		p->a[p->t]='F';
	}
	shiliu(p,n/16);
}
void cu(jinzhi *p){
	while(p->t>=0){
	printf("%c",p->a[p->t]);
	p->t--;
}
}
int main(){
	jinzhi *erjin,*bajin,*shiliujin;
	cushi(erjin);
	cushi(bajin);
	cushi(shiliujin);
	int n;
	scanf("%d",&n);
	er(erjin,n);
	ba(bajin,n);
	shiliu(shiliujin,n);
	printf("二进制：");
	cu(erjin);
	printf("\n八进制：");
	cu(bajin);
	printf("\n十六进制：");
	cu(shiliujin);
	return 0; 
}
 

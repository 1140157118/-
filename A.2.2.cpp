#include<bits/stdc++.h>
using namespace std;
#define NULLKEY -1
#define Max 10
struct s{
	int key;
	char name[50];
	char add[50];
	int count;
};
void caH(struct s ha[],int &n,int m,int k,int &f){
	int i=1;
	int j=0;
	int adr;
	int cnt=0;
	char c;
	adr=k%m;
	if(ha[adr].key==NULLKEY){
		ha[adr].key=k;
		printf("姓名:\n");
		scanf("%c",&c);
		gets(ha[adr].name);
		printf("地址:\n");
		gets(ha[adr].add);
		ha[adr].count=1;
	}else{
		cnt=1;
		f++;
		do{
			if(j==0)
			adr=(adr+(int)pow(i,2))%m;
			else
			adr=(adr-(int)pow(i,2))%m;
			cnt++;
			j++;
			if(j==2){
			i++;
			j=0;
		}
		}while(ha[adr].key!=NULLKEY);
		ha[adr].key=k;
		printf("姓名:\n");
		scanf("%c",&c);
		gets(ha[adr].name);
		printf("地址:\n");
		gets(ha[adr].add);
		ha[adr].count=cnt;
	}
	n++;
}
void CHT(struct s ha[],int &n,int m,int p,int total,int &f){
	int k; 
	for(int i=0;i<m;i++){
		ha[i].key=NULLKEY;
		ha[i].count=0;
	}
	n=0;
	for(int i=0;i<total;i++){
		printf("电话\n");
		scanf("%d",&k);
		caH(ha,n,m,k,f); 
	}
}
void ASL(struct s ha[],int n,int p,int m){
	int i;
	int j;
	int s;
	int suc=0;
	int unsuc=0;
	for(i=0;i<m;i++){
		if(ha[i].key!=NULLKEY)
		suc+=ha[i].count;
	}
	printf("成功情况下ASL(%d)=%g\n",n,suc*1.0/n);
	for(i=0;i<p;i++){
		s=1;
		j=1;
		while(ha[j].key!=NULLKEY){
			s++;
			j=(j+1)%m;
		}
		unsuc+=s;
	}
	printf("不成功情况下ASL(%d)=%g\n",n,unsuc*1.0/m);
}
int main(){
	struct s ha[Max];
	int n;
	int f=0;
	CHT(ha,n,Max,Max,5,f);
	ASL(ha,n,Max,Max);
	printf("冲突率=%f",f*1.0/n);
	return 0;
}

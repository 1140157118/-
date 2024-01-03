#include<bits/stdc++.h>
using namespace std;
#define Max 10
typedef struct node{
	int key;
	char name[50];
	char add[50];
	struct node *next;
}Node;
typedef struct{
	Node *fir;
}HT;
void IHT(HT ha[],int &n,int m,int k){
	int adr;
	adr=k%m;
	char c;
	Node *p;
	p=(Node*)malloc(sizeof(Node));
	p->key=k;
	scanf("%c",&c);
	printf("姓名：\n");
	gets(p->name);
	printf("地址：\n");
	gets(p->name);
	p->next=NULL;
	if(ha[adr].fir==NULL)
	ha[adr].fir=p;
	else{
		p->next=ha[adr].fir;
		ha[adr].fir=p;
	}
	n++;
}
void CHT(HT ha[],int &n,int m,int total){
	int k,i;
	for(i=0;i<m;i++)
	ha[i].fir=NULL;
	n=0;
	for(i=0;i<total;i++){
	printf("电话:\n");
	scanf("%d",&k);
	IHT(ha,n,m,k);
}
}
void ASL(HT ha[],int n,int m){
	int suc,unsuc,s;
	suc=unsuc=0;
	Node *p;
	for(int i=0;i<m;i++){
		s=0;
		p=ha[i].fir;
		while(p!=NULL){
			p=p->next;
			s++;
			suc+=s;
		}
		unsuc++;
	}
	printf("成功情况下ASL(%d)=%g\n",n,suc*1.0/n);
	printf("不成功情况下ASL(%d)=%g\n",n,unsuc*1.0/m);
}
int main(){
	int n;
	HT ha[Max];
	CHT(ha,n,Max,5);
	ASL(ha,n,Max);
	return 0;
}

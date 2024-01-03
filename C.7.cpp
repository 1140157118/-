#include<bits/stdc++.h>
using namespace std;
#define Max 100
typedef struct s{
	char n;
	struct s *lc;
	struct s *rc;
}node;
void CBT(node *&p,char *c){
	node *st[Max],*q;
	int t=-1,k,j=0;
	char b;
	p=NULL;
	b=c[j];
	while(b!='\0'){
		switch(b){
			case '(': t++;st[t]=q;k=1;break;
			case ')': t--;break;
			case ',': k=2;break;
			default:
				q=(node*)malloc(sizeof(node));
				q->n=b;
				q->lc=q->rc=NULL;
				if(p==NULL)
				p=q;
				else{
					switch(k){
						case 1: st[t]->lc=q;break;
						case 2: st[t]->rc=q;break;
					}
				}
		}
		j++;
		b=c[j];
	}
}
int lu(node *p,char c){
	if(p==NULL)
	return 0;
	if(lu(p->lc,c)||lu(p->rc,c)){
		printf("<-%c",p->n);
		return 1;
	}
	if(p->n==c){
		printf("%c",p->n);
		return 1;
	}

	return 0;
}
int main(){
	char a[Max];
	node *p;
	char c;
	printf("输入二叉树的括号表示法:\n");
	gets(a);
	CBT(p,a);
	printf("输入要查找的结点:\n");
	scanf("%c",&c);
	printf("路径为：");
	int i;
	i=lu(p,c);
	if(!i){
		printf("%c不是叶子结点",c);
	}
	return 0;
}

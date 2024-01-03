#include<bits/stdc++.h>
using namespace std;
typedef struct s{
	int n;
	int rn=0;
	int ln=0;
	int w;
	int c;
	struct s *r;
	struct s *l;
	struct s *pre;
}no;
void ca(no *&p,no *q){
	if(p==NULL){
		p=q;
		return ;
	}else{
	if(p->n>q->n){
		if(p->l==NULL)
		q->pre=p;
	ca(p->l,q);
}
	else{
		if(p->r==NULL)
		q->pre=p;
	ca(p->r,q);
}
	return ;
}
}
no *t;
void zhong1(no *&p){
	if(p){
		zhong1(p->l);
		if(!p->l){
			p->ln=1;
			p->l=t;
		}else{
			p->ln=0;
		}
		if(!t->r){
			t->rn=1;
			t->r=p;
		}
		else{
			t->rn=0;
		}
		t=p;
		zhong1(p->r);
	}
}
void zhong(no *&p,no *&s){
	p=new no;
	p->ln=0;
	p->rn=1;
	p->r=p;
	if(!s){
		p->l=p;
	}else{
		p->l=s;
		t=p;
		zhong1(s);
		t->r=p;
		t->rn=1;
		p->r=t;
	}
}
void zhongbian(no *p){
	no *q=p->l;
	while(q!=p){
		while(q->ln==0)
		q=q->l;
		printf("%d %d %d\n",q->n,q->w,q->c);
		while(q->rn==1&&q->r!=p){
			q=q->r;
			printf("%d %d %d\n",q->n,q->w,q->c);
		}
		q=q->r;
	}
}
int main(){
	no *p,*s;
	p=NULL;
	int n;
	scanf("%d",&n);
	while(n!=-1){
		no *q;
		q=(no*)malloc(sizeof(no));
		q->n=n;
		q->pre=q->l=q->r=NULL;
		scanf("%d%d",&(q->w),&(q->c));	
		ca(p,q);
		scanf("%d",&n);
	}
	no *x1,*z1,*h1 ;
	x1=z1=h1=(no*)malloc(sizeof(no));
	no *x,*z,*h;
	x=z=h=p;
	t=NULL;
	//xian(x1,x);
	t=NULL;
	zhong(z1,z);
	t=NULL;
    //hou(h1,z);
//	xianbian(x1);
	zhongbian(z1);
//	houbian(h1);
	return 0;
	
}

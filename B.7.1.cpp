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
void xian1(no *&p){
	if(p){
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
		if(p->ln==0)
		xian1(p->l);
		if(p->rn==0)
		xian1(p->r);
	}
}
void xian(no *&p,no *&s){
	p=new no;
	p->ln=0;
	p->rn=1;
	p->r=p;
	if(!s){
		p->l=p;
	}else{
		p->l=s;
		t=p;
		xian1(s);
		t->r=p;
		t->rn=1;
		p->r=t;
	}
}

void xianbian(no *p){
	no *q=p->l;
	while(q!=p){
		printf("%d %d %d\n",q->n,q->w,q->c);
		if(q->ln==0)
		q=q->l;
		else
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
	xian(x1,x);
	t=NULL;
//	zhong(z1,z);
	t=NULL;
//    hou(h1,z);
	xianbian(x1);
//	zhongbian(z1);
//	houbian(h1);
	return 0;
	
}

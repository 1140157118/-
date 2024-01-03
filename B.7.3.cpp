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
void hou1(no *&p){
	if(p){
		hou1(p->l);
		hou1(p->r);
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
	}
}
void hou(no *&p,no *&s){
	p=new no;
	p->ln=0;
	p->rn=1;
	p->r=s;
	if(!s){
		p->l=p;
	}else{
		p->l=s;
		t=p;
		hou1(s);
	}
}
void houbian(no *p){
	no *ro=p->l;
	no *per=NULL;
	while(ro){
		if(ro->l==ro->r)
		ro=ro->r;
		while(ro->ln==0&&ro->l!=per)
		ro=ro->l;
		while(ro->rn==1){
			printf("%d %d %d\n",ro->n,ro->w,ro->c);
			per=ro;
			ro=ro->r;
		}
		if(ro==p->l){
			printf("%d %d %d\n",ro->n,ro->w,ro->c);
			return ;
		}
		while(ro->r==per){
			printf("%d %d %d\n",ro->n,ro->w,ro->c);
			per=ro;
			ro=ro->pre;
		if(ro==NULL)
		return ;
	}
		if(ro->rn==0)
		ro=ro->r;
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
//	xian(x1,x);
	t=NULL;
//	zhong(z1,z);
	t=NULL;
    hou(h1,z);
//	xianbian(x1);
//	zhongbian(z1);
	houbian(h1);
	return 0;
	
}

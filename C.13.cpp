#include<bits/stdc++.h>
using namespace std;
struct s{
	int n;
	struct s *next;
	struct s *pr;
};
void ca(struct s *&p,int n){
	struct s *q;
	q=(struct s*)malloc(sizeof(struct s));
	q->n=n;
	if(p==NULL){
		p=(struct s*)malloc(sizeof(struct s));
		p->next=q;
		q->pr=p;
		q->next=p;
		p->pr=q;
	}
	else{
		struct s *t=p->pr;
		t->next=q;
		q->pr=t;
		q->next=p;
		p->pr=q;
	}
}
void print(struct s *p){
	if(p==NULL)
	printf("error");
	else{
		struct s *q=p->next;
		do{
			printf("%d ",q->n);
			q=q->next;
		}while(q!=p);
		printf("\n");
	}
}
struct s* jiao(struct s *p,struct s *q){
	struct s *r=NULL;
	struct s *a=p->next;
	do{
		struct s *b=q->next;
		do{
			if(a->n==b->n){
				ca(r,a->n);
				break;
			}
			b=b->next;
		}while(b!=q);
		a=a->next;
	}while(a!=p);
	return r;
}
struct s *bin(struct s *p,struct s *q){
	struct s*r=NULL;
	struct s*a=p->next;
	do{
		ca(r,a->n);
		a=a->next;
	}while(a!=p);
	struct s *b=q->next;
	do{
		struct s *c=r->next;
		int f=0;
		do{
			if(c->n==b->n){
				f=1;
				break;
			}
			c=c->next;
		}while(c!=r);
		if(!f){
			ca(r,b->n);
		}
		b=b->next;
	}while(b!=q);
	return r;
}
int main(){
	int n;
	printf("序列1：\n");
	scanf("%d",&n);
	struct s *p,*q;
	p=q=NULL;
	while(n!=-1){
		ca(p,n);
		scanf("%d",&n);
	}
	printf("序列2:\n");
	scanf("%d",&n);
	while(n!=-1){
		ca(q,n);
		scanf("%d",&n);
	}
	struct s *t,*r;
	t=jiao(p,q);
	r=bin(p,q);
	printf("交集:\n");
	print(t);
	printf("并集:\n");
	print(r);
	return 0;
}

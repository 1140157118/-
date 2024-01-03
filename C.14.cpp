#include<bits/stdc++.h>
using namespace std;
typedef struct s{
	int n;
	struct s *l;
	struct s *r;
}no;
void ca(no *&p,no *q){
	if(p==NULL){
		p=q;
		return;
	}
	if(p->n>q->n)
	ca(p->l,q);
	else
	ca(p->r,q);
	return;
}
no *fin(no *p,int n){
	if(p->n==n){
		return p;
	}else{
		if(n<p->n)
		return fin(p->l,n);
		else
		return fin(p->r,n);
	}
}
no *zu(no *ro,no *p,no *q){
	if(ro==p||ro==q||ro==NULL)
	return ro;
	no *le=zu(ro->l,p,q);
	no *ri=zu(ro->r,p,q);
	if(le!=NULL&&ri!=NULL)
	return ro;
	if(le==NULL)
	return ri;
	else
	return le;
}
int main(){
	int n;
	scanf("%d",&n);
	no *p=NULL;
	while(n!=-1){
		no *q;
		q=(no*)malloc(sizeof(no));
		q->n=n;
		q->l=q->r=NULL;
		ca(p,q);
		scanf("%d",&n);
	}
	int i,j;
	scanf("%d %d",&i,&j);
	no *r;
	r=zu(p,fin(p,i),fin(p,j));
	printf("%d",r->n);
	return 0;
}

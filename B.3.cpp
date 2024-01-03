#include<bits\stdc++.h>
using namespace std;
#define Max 100
typedef struct s{
	int n;
	int rn;
	int ln;
	struct s *r;
	struct s *l;
}no;
typedef struct{
	no *d[Max];
	int t;
	
}zhan;
void cuan(no p[],no *&q,int n){
	int i;
	for(i=1;i<=n;i++){
		if(p[i].rn==-1)
		p[i].r=NULL;
		else{
			p[i].r=&p[p[i].rn];
		}
		if(p[i].ln==-1)
		p[i].l=NULL;
		else
		p[i].l=&p[p[i].ln];
	}
	q=&p[1];
}
void cu(zhan *&p){
	p=(zhan*)malloc(sizeof(zhan));
	p->t=-1;
}
bool pu(zhan *&p,no *q){
	if(p->t==Max-1)
	return false;
	else{	
	p->t++;
	p->d[p->t]=q;
	return true;
}
}
bool get(zhan *p,no *&q){
	if(p->t==-1)
	return false;
	q=p->d[p->t];
	return true;
}
bool pop(zhan *&p,no *&q){
	if(p->t==-1)
	return false;
	q=p->d[p->t];
	p->t--;
	return true;
}
bool pan(zhan *p){
	return (p->t==-1);
}
void xiao(zhan *&p){
	free(p);
}
void qian(no *p){
	no *q;
	zhan *e;
	cu(e);
	if(p!=NULL){
		pu(e,p);
		while(!pan(e)){
			pop(e,q);
			printf("%d",q->n);
			if(q->r!=NULL)
			pu(e,q->r);
			if(q->l!=NULL)
			pu(e,q->l);
		}
		printf("\n");
	} 
	xiao(e);
}
void zhong(no *p){
	no *q;
	zhan *e;
	cu(e);
	q=p;
	while(!pan(e)||q!=NULL){
		while(q!=NULL){
			pu(e,q);
			q=q->l;
		}
		if(!pan(e)){
			pop(e,q);
			printf("%d",q->n);
			q=q->r;
		} 
	}
	printf("\n");
	xiao(e);
}
void hou(no *p){
	no *q,*t;
	bool f;
	zhan *e;
	cu(e);
	q=p;
	do{
		while(q!=NULL){
			pu(e,q);
			q=q->l;
		}
		t=NULL;
		f=true;
		while(!pan(e)&&f){
			get(e,q);
			if(q->r==t){
				printf("%d",q->n);
				pop(e,q);
				t=q;
			}else{
				q=q->r;
				f=false;
			}
		}
	}while(!pan(e));
	printf("\n");
	xiao(e);
}
int main(){
	int n,i,m,rn,ln;
	scanf("%d",&n);
	no p[Max];

	for(i=1;i<=n;i++){
		scanf("%d%d%d",&m,&ln,&rn);
		p[i].n=m;
		p[i].ln=ln;
		p[i].rn=rn; 
	}
	no *q;
	cuan(p,q,n); 
	qian(q);
	zhong(q);
	hou(q);
	return 0;
}


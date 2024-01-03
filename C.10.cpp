#include<bits/stdc++.h>
using namespace std;
typedef struct s{
	int n;
	struct s *next;
	struct s *head;
}DL;
DL *scan(){
	int a;
	DL *q,*head,*p;
	head=q=NULL;
	scanf("%d",&a);
	while(a!=-1){
		p=(DL*)malloc(sizeof(DL));
		p->n=a;
		if(head==NULL){
			p->head=NULL;
			head=p;
		}else{
			q->next=p;
			p->head=q;
		}
		q=p;
		p=p->next;
		scanf("%d",&a);
	}
	if(head)
	q->next=NULL;
	return head;
}
bool zi(DL *p,DL *q){
	if(q==NULL)
	return true;
	else if(p==NULL)
	return false;
	else if(p->n==q->n){
		return zi(p->next,q->next);
	}else{
		return zi(p->next,q);
	}
}
int main(){
	DL *p,*q;
	printf("序列1:\n");
	p=scan();
	printf("序列2:\n");
	q=scan();
	if(zi(p,q))
	printf("序列2是序列1的子序列\n");
	else
	printf("序列2不是序列1的子序列\n");
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct s{
	int n;
	struct s *next;
};
struct s* scan(){
	struct s *head,*p,*q;
	head=q=NULL;
	int n;
	scanf("%d",&n);
	while(n!=-1){
		p=(struct s*)malloc(sizeof(struct s));
		p->n=n;
		if(head==NULL)
		head=p;
		else{
			q->next=p;
		}
		q=p;
		p=p->next;
		scanf("%d",&n);
	}
	if(head)
	q->next=NULL;
	return head;
}
void hua(struct s *p,struct s *&l1,struct s *&l2){
	struct s *q1,*q2;
	q1=q2=NULL;
	while(p){
		if(p->n%2==0){
			if(l2==NULL)
			l2=p;
			else
			q2->next=p;
			q2=p;
			p=p->next;
		}else{
			if(l1==NULL)
			l1=p;
			else
			q1->next=p;
			q1=p;
			p=p->next;
		}
	}
	if(l1)
	q1->next=NULL;
	if(l2)
	q2->next=NULL;
}
int main(){
	struct s *p,*l1,*l2;
	p=scan();
	l1=l2=NULL;
	hua(p,l1,l2);
	printf("L1=%d",l1->n);
	l1=l1->next;
	while(l1){
		printf("->%d",l1->n);
		l1=l1->next;
	}
	printf("\nL2=%d",l2->n);
	l2=l2->next;	
	while(l2){
		printf("->%d",l2->n);
		l2=l2->next;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct s{
	int n;
	int a;
	struct s *next;
};
struct s *scan(int m){
	int i;
	struct s *head,*p,*q;
	head=q=NULL;
	for(i=1;i<=m;i++){
		p=(struct s*)malloc(sizeof(struct s));
		p->n=i;
		p->a=0;
		if(head==NULL)
		head=p;
		else
		q->next=p;
		q=p;
		p=p->next;
	}
	if(head)
	q->next=head;
	return head;
}
void yu(struct s *p,int m,int c){
	int b=0,cou=1;
	printf("被淘汰人的顺序:");
	while(p){
		if(p->a==0){
			if(m-b==1){
				printf("\n最后剩下的人为%d",p->n);
				break;
			}
			if(cou%3==0){
				printf("%d ",p->n);
				p->a=1;
				b++;
			}
			cou++;
		}
		p=p->next;
	}
}
int main(){
	int m,c;
	printf("人数:\n");
	scanf("%d",&m);
	struct s *p;
	p=scan(m);
	printf("间隔:\n");
	scanf("%d",&c);
	yu(p,m,c);
	return 0;
}

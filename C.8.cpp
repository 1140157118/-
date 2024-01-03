#include<bits/stdc++.h>
using namespace std;
#define Max 100
#define INF INT_MAX
typedef struct{
	int e[Max][Max];
	int d;
}mat;
typedef struct s{
	int n;
	struct s *next;
}arc;
typedef struct{
	arc *first;
}vn;
typedef struct{
	vn a[Max];
	int d;
}adj;
mat *matcuan(int d){
	int i;
	mat *p;
	p=(mat*)malloc(sizeof(mat));
	int j;
	p->d=d;
	for(i=0;i<d;i++){
		for(j=0;j<d;j++)
		scanf("%d",&(p->e[i][j]));
	}
	return p;
}
adj *adjcuan(int d){
	int i,j,n;
	adj *p;
	p=(adj*)malloc(sizeof(adj));
	p->d=d;
	arc *t,*q;
	for(i=0;i<d;i++){
		printf("顶点%d的邻接点个数:\n",i);
		scanf("%d",&n);
		p->a[i].first=NULL;
		if(n!=0){
		printf("输入邻接点\n");
		for(j=0;j<n;j++){
			t=(arc*)malloc(sizeof(arc));
			scanf("%d",&(t->n));
			if(p->a[i].first==NULL)
			p->a[i].first=t;
			else
			q->next=t;
			q=t;
			t=t->next;
		}
		q->next=NULL;
	}
	}
	return p;
}
void zhuanbiao(adj *&p,mat *q){
	arc *t;
	p=(adj*)malloc(sizeof(adj));
	p->d=q->d;
	int i,j;
	for(i=0;i<q->d;i++){
		p->a[i].first=NULL;
	}
	for(i=0;i<q->d;i++){
		for(j=q->d-1;j>=0;j--){
			if(q->e[i][j]!=0&&q->e[i][j]!=INF){
				t=(arc*)malloc(sizeof(arc));
				t->n=j;
				t->next=p->a[i].first;
				p->a[i].first=t;
			}
		}
	}
}
void zhuanju(mat *&p,adj *q){
	p=(mat*)malloc(sizeof(mat));
	p->d=q->d;
	int i,j;
	arc *t;
	for(i=0;i<q->d;i++){
		for(j=0;j<q->d;j++)
		p->e[i][j]=0;
	}
	for(i=0;i<q->d;i++){
		t=q->a[i].first;
		while(t){
			p->e[i][t->n]=1;
			t=t->next;
		}
	}
}
void disadj(adj *p){
	int i;
	arc *t;
	for(i=0;i<p->d;i++){
		t=p->a[i].first;
		printf("%d ",i);
		while(t){
			printf("%d->",t->n);
			t=t->next;
		}
		printf("\n");
	}
}
void dismat(mat *p){
	int i,j;
	for(i=0;i<p->d;i++){
		for(j=0;j<p->d;j++)
		printf("%d ",p->e[i][j]);
		printf("\n");
	}
}
int main(){
	int t;
	printf("矩阵转邻接表填1，邻接表转矩阵填2\n");
	scanf("%d",&t);
	if(t==1){
		printf("顶点数:\n");
		int d;
		scanf("%d",&d);
		mat *p;
		p=matcuan(d);
		adj *q;
		zhuanbiao(q,p);
		printf("转换后的邻接表:\n");
		disadj(q);
	}else if(t==2){
		printf("顶点数:\n");
		int d;
		scanf("%d",&d);
		adj *p;
		p=adjcuan(d);
		mat *q;
		zhuanju(q,p);
		printf("转换后的矩阵:\n");
		dismat(q);
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define Max 100
typedef struct s{
	int d;
	struct s *next;
}arc;
typedef struct{
	int n;
	arc *fir;
}vn;
typedef struct{
	vn vz[Max];
	int n;
}adj;
void cu(adj *&p){
	for(int i=0;i<p->n;i++){
		p->vz[i].n=i;
		p->vz[i].fir=NULL;
	}
}
void cuan(adj *&p){
	arc *q,*t;
	int i,j,n;
	for(i=0;i<p->n;i++){
		printf("%d的邻接点个数:\n",i);
		scanf("%d",&n);
		printf("输入邻接点:\n");
		for(j=0;j<n;j++){
			q=(arc*)malloc(sizeof(arc));
			scanf("%d",&(q->d));
			if(p->vz[i].fir==NULL)
			p->vz[i].fir=q;
			else
			t->next=q;
			t=q;
			q=q->next; 
		}
		if(p->vz[i].fir)
		t->next=NULL;
	}
} 
int v[Max]={0};
void dfs(adj *p,int u,int d,int &f){
	arc *a;
	int i,k;
	if(u==d){
		f=1;
		return;
	}
	for( i=0;i<p->n;i++){
		if(p->vz[i].n==u)
		break;
	}
		k=i;
		v[k]=1;
		a=p->vz[k].fir;
		while(a){
			if(v[a->d]==0)
			dfs(p,a->d,d,f);
			a=a->next;
		}
}
void ju(adj *p,int &f){
	for(int i=0;i<p->n;i++){
		for(int j=0;j<p->n;j++){
			f=0;
			dfs(p,i,j,f);
			if(!f)
			return;
			for(int k=0;k<p->n;k++)
			v[k]=0;
		}
	}
}
int main(){
	int i,f;
	int n;
	adj *p;
	p=(adj*)malloc(sizeof(adj));
	printf("顶点个数:\n");
	scanf("%d",&n);
	p->n=n;
	cu(p);
	cuan(p);
	ju(p,f);
	if(f==1)
	printf("Yes");
	else
	printf("No");
	return 0; 
}

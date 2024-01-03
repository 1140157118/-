#include<bits/stdc++.h>
using namespace std;
#define Max 100
int m[Max][Max];
typedef struct{
	int i,j;
	int p;
}bo;
typedef struct{
	bo d[Max];
	int f;
	int r;
}qu;
void in(qu *&p){
	p=(qu*)malloc(sizeof(qu));
	p->f=p->r=-1;
}
bool qe(qu *p){
	return (p->f==p->r);
}
void des(qu *&p){
	free(p);
}
bool en(qu *&p,bo e){
	if(p->f==Max-1)
	return false;
	p->r++;
	p->d[p->r]=e;
	return true;
}
bool de(qu *&p,bo &e){
	if(p->f==p->r)
	return false;
	p->f++;
	e=p->d[p->f];
	return true;
}
void dis(qu *p,int f){
	int q=f;
	int k=0;
	while(q!=-1){
		k++;
		q=p->d[q].p;
	}
	printf("%d",k-1);
	printf("\n");
}
bool mg(int x1,int y1,int x2,int y2){
	bo e;
	int i,j,d,il,jl;
	qu *p;
	in(p);
	e.i=x1;
	e.j=y1;
	e.p=-1;
	en(p,e);
	m[x1][y1]=-1;
	while(!qe(p)){
		de(p,e);
		i=e.i;
		j=e.j;
		if(i==x2&&j==y2){
			dis(p,p->f);
			des(p);
			return true;
		}
		for(d=0;d<4;d++){
			switch(d){
				case 0: il=i-1;jl=j;break;
				case 1: il=i;jl=j+1;break;
				case 2: il=i+1;jl=j;break;
				case 3: il=i;jl=j-1;break;
			}
			if(m[il][jl]==0){
				e.i=il;
				e.j=jl;
				e.p=p->f;
				en(p,e);
				m[il][jl]=-1;
			}
		}
	}
	des(p);
	return false;
}
int main(){
	int M,n,i,j;
	scanf("%d %d",&n,&M);
	for(i=0;i<M+2;i++){
		m[0][i]=1;
		m[n+1][i]=1;
	}
	for(i=0;i<n+2;i++){
		m[i][0]=1;
		m[i][M+1]=1;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=M;j++)
		scanf("%d",&(m[i][j]));
	}
	int x1,x2,y1,y2;
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	if(!mg(x1,y1,x2,y2))
	printf("нч╫Б\n");
	return 0;
}

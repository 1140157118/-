#include<bits/stdc++.h>
using namespace std;
#define Max 100
#define m 4
#define N 4
typedef struct{
	int h;
	int l;
	int d;
}TN;
typedef struct{
	int r;
	int c;
	int n;
	TN d[Max];
}TSM;
void cmat(TSM &t,int a[m][N]){
	int i,j;
	t.r=m;
	t.c=N;
	t.n=0;
	for(i=0;i<m;i++){
		for(j=0;j<N;j++){
			if(a[i][j]!=0){
				t.d[t.n].h=i;
				t.d[t.n].l=j;
				t.d[t.n].d=a[i][j];
				t.n++;
			}
		}
	}
}
void Dis(TSM p){
	int i;
	if(p.n<=0)
	return;
	printf("\t%d\t%d\t%d\n",p.r,p.c,p.n);
	printf("\t------------------\n");
	for(i=0;i<p.n;i++)
	printf("\t%d\t%d\t%d\n",p.d[i].h,p.d[i].l,p.d[i].d);
}
bool Ass(TSM p,int &x,int i,int j){
	int k=0;
	if(i>p.r||j>p.c)
	return false;
	while(k<p.n&&i>p.d[k].h) 
	k++;   //查找i行的非零元素
    while(k<p.n&&i==p.d[k].h&&j>p.d[k].l) 
	k++;
	if(p.d[k].h==i&&p.d[k].l==j)
	x=p.d[k].d;
	else
	x=0;
	return true;
}
void jia(TSM p,TSM q){
	TSM t;
	int i,j;
	int x1,x2;
	x1=x2=0;
	int sum[m][N]={0};
	for(i=0;i<m;i++){
		for(j=0;j<N;j++){
			Ass(p,x1,i,j);
			Ass(q,x2,i,j);
			if(x1&&x2){
				sum[i][j]=x1+x2;
			}else if(x1!=0&&x2==0){
				sum[i][j]=x1;
			}else if(x1==0&&x2!=0)
			sum[i][j]=x2;
		}
	}
	cmat(t,sum);
	printf("相加后:\n");
	Dis(t);
}
void cheng(TSM p,TSM q){
	TSM t;
	int i,j;
	int c;
	int x1=0,x2=0;
	int r[m][N];
	int re=0;
	for(i=0;i<m;i++){
		for(j=0;j<N;j++){
			for(c=0;c<m;c++){
				Ass(p,x1,i,c);
				Ass(q,x2,c,j);
				re+=x1*x2;
			}
			r[i][j]=re;
			re=0;
		}
	}
	cmat(t,r);
	printf("相乘后:\n");
	Dis(t);
}
int main(){
	TSM p,q;
	int a[m][N],b[m][N];
	int i,j;
	printf("矩阵1:\n"); 
	for(i=0;i<m;i++){
		for(j=0;j<N;j++)
		scanf("%d",&a[i][j]);
	}
	printf("矩阵2:\n"); 
	for(i=0;i<m;i++){
		for(j=0;j<N;j++)
		scanf("%d",&b[i][j]);
	}
	cmat(p,a);
	cmat(q,b);
	jia(p,q);
	cheng(p,q);
	return 0;
}

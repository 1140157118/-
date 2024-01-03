#include<bits/stdc++.h>
using namespace std;
#define Max 100
int l=Max;
int m[Max][Max];
void mg(int x1,int y1,int x2,int y2,int lon){
	int d,k,i,j;
	if(x1==x2&&y1==y2){
		
		if(l>lon)
		l=lon;
	}else{
		if(m[x1][y1]==0){
			d=0;
			while(d<4){
				lon++;
				switch(d){
					case 0: i=x1-1;j=y1;break;
					case 1: i=x1;j=y1+1;break;
					case 2: i=x1+1;j=y1;break;
					case 3: i=x1;j=y1-1;break;
				}
				m[x1][y1]=-1;
				mg(i,j,x2,y2,lon);
				m[x1][y1]=0;
				lon--;
				d++;
			}
		}
	}
}
int main(){
	int lon=0;
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
	mg(x1,y1,x2,y2,lon);
	printf("%d",l);
	return 0;
}


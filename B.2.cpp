#include<bits/stdc++.h>
using namespace std;
#define Max 1000
struct s{
	int i;
	int j;
	int w;
};
int dit[Max];
void bell(struct s *p,int n,int m,int s){
	memset(dit,0x3f3f3f3f,sizeof(dit));
	dit[s]=0;
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<m;j++){
			int a=p[j].i,b=p[j].j,w=p[j].w;
			if(dit[a]!= 0x3f3f3f3f&&dit[b]>dit[a]+w)
			dit[b]=dit[a]+w;
		}
	}
}
int main(){
	struct s p[Max];
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&(p[i].i),&(p[i].j),&(p[i].w));
	}
	int s;
	scanf("%d",&s);
	bell(p,n,m,s);
	for(int i=1;i<=n;i++){
		if(dit[i]==0x3f3f3f3f )
		printf("INF\n");
		else
		printf("%d\n",dit[i]);
	}
	return 0;
}

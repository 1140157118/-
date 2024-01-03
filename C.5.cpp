#include<bits/stdc++.h>
using namespace std;
int bai(int *p,int lon){
	int i,n=0;
	if(lon<2)
	n=1;
	else{
	for(i=1;i<lon-1;i++){
	    if((p[i-1]>p[i]&&p[i]>p[i+1])||(p[i-1]<p[i]&&p[i]<p[i+1])||(p[i]==p[i-1])||(p[i]==p[i+1])){
		n=1;		
		break;
}
	}
}
	return n;
}
void pan(int *p,int lon){
	int i,n=0;
	for(i=1;i<lon-1;i++){
		 if((p[i-1]>p[i]&&p[i]>p[i+1])||(p[i-1]<p[i]&&p[i]<p[i+1])||(p[i]==p[i-1])||(p[i]==p[i+1]))
		 n++;
	}
	printf("需要删除%d个数\n",n);
}
int main(){
	int *p;
	int d;
	printf("输入数列长度\n"); 
	scanf("%d",&d);
	p=(int *)malloc(d*sizeof(int));
	for(int i=0;i<d;i++)
	scanf("%d",&p[i]);
	if(bai(p,d)){
		printf("非摆动数列,");
		pan(p,d);
	}else{
		printf("是摆动数列\n");
	}
	return 0;
}

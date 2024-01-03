#include<bits/stdc++.h>
using namespace std;
#define Max 100
void xier(int *p,int d){
	int i,j,n;
	int q;
	n=d/2;
	while(n>0){
		for(i=n;i<d;i++){
			q=p[i];
			j=i-n;
			while(j>=0&&q<p[j]){
				p[j+n]=p[j];
				j=j-n;
			}
			p[j+n]=q;
		}
		n=n/2;
	}
	for(i=0;i<d;i++)
	printf("%d ",p[i]);
	printf("\n");
}
int huafen(int p[],int s,int w){
	int i=s;
	int j=w;
	int b=p[i];
	while(i<j){
		while(j>i&&p[j]>=b)
		j--;
		if(i<j){
			p[i]=p[j];
			i++;
		}
		while(i<j&&p[i]<=b)
		i++;
		if(i<j){
			p[j]=p[i];
			j--;
		}
	}
	p[i]=b;
	return i;
} 
void kuaisu(int p[],int s,int w){
	int i;
	if(s<w){
		i=huafen(p,s,w);
		kuaisu(p,s,i-1);
		kuaisu(p,i+1,w);
	}

}
void saida(int *p,int l,int h){
	int i=l;
	int j=2*i;
	int t=p[i];
	while(j<=h){
		if(j<h&&p[j]<p[j+1])
		j++;
		if(t<p[j]){
			p[i]=p[j];
			i=j;
			j=2*i;
		}
		else
		break;
	}
	p[i]=t;
}
void saixiao(int *p,int l,int h){
	int i=l;
	int j=2*i;
	int t=p[i];
	while(j<=h){
		if(j<h&&p[j]>p[j+1])
		j++;
		if(t>p[j]){
			p[i]=p[j];
			i=j;
			j=2*i;
		}
		else
		break;
	}
	p[i]=t;
}
void duida(int *p,int d){
	int i,n;
	for(i=d/2;i>=0;i--)
	saida(p,i,d);
	for(i=d;i>=1;i--){
		n=p[0];
		p[0]=p[i];
		p[i]=n;
		saida(p,0,i-1);
	}
	for(i=0;i<=d;i++)
	printf("%d ",p[i]);
	printf("\n");
}
void duixiao(int *p,int d){
	int i,n;
	for(i=d/2;i>=0;i--)
	saixiao(p,i,d);
	for(i=d;i>=1;i--){
		n=p[0];
		p[0]=p[i];
		p[i]=n;
		saixiao(p,0,i-1);
	}
	for(i=d;i>=0;i--)
	printf("%d ",p[i]);
	printf("\n");
}
void M(int *p,int l,int m,int h){
	int *p1;
	int i=l;
	int j=m+1;
	int k=0;
	p1=(int *)malloc((h-l+1)*sizeof(int));
	while(i<=m&&j<=h){
		if(p[i]<=p[j]){
			p1[k]=p[i];
			i++;
			k++;
		}else{
			p1[k]=p[j];
			j++;
			k++;
		}
	}
	while(i<=m){
		p1[k]=p[i];
		i++;
		k++;
	}
		while(j<=h){
			p1[k]=p[j];
			j++;
			k++;
		}
		for(k=0,i=l;i<=h;k++,i++)
		p[i]=p1[k];
		free(p1);
	
}
void MP(int *p,int l,int n){
	int i;
	for(i=0;i+2*l-1<n;i=i+2*l)
	M(p,i,i+l-1,i+2*l-1);
	if(i+l-1<n-1)
	M(p,i,i+l-1,n-1);
}
void MS(int *p,int n){
	int l;
	for(l=1;l<n;l=2*l)
	MP(p,l,n);
}
void guibin(int *p,int l,int h){
	int m;
	if(l<h){
		m=(l+h)/2;
		guibin(p,l,m);
		guibin(p,m+1,h);
		M(p,l,m,h);
	}
}
int get(int num,int dec,int order){
	int i,j,n;
	int index;
	int div;
	for(i=dec;i>order;i--){
		n=1;
		for(j=0;j<dec-1;j++){
			n*=10;
		}
		div=num/n;
		num-=div*n;
		dec--;
	}
	n=1;
	for(i=0;i<order-1;i++)
	n*=10;
	index=num/n;
	return index;
}
void jisu(int *p,int l,int dec,int order){
	int i,j;
	int index;
	int t[l];
	int num[10];
	memset(num,0,10*sizeof(int));
	memset(t,0,l*sizeof(int));
	if(dec<order)
	return ;
	for(i=0;i<l;i++){
		index=get(p[i],dec,order);
		num[index]++;
	}
	for(i=1;i<10;i++){
		num[i]+=num[i-1];
	}
	for(i=l-1;i>=0;i--){
		index=get(p[i],dec,order);
		j=--num[index];
		t[j]=p[i];
	}
	for(i=0;i<l;i++)
	p[i]=t[i];
	jisu(p,l,dec,order+1);
	return ;
	}
int main(){
	int p[10]={6, 12, 458, 5, 4, 28, 19, 1230, 9, 47};
    int *q=p;
    printf("Ï£¶ûÅÅÐò:\n");
	xier(q,10);
	q=p;
	printf("¿ìËÙÅÅÐò:\n");
	kuaisu(q,0,9);
	for(int i=0;i<10;i++)
    printf("%d ",q[i]);
	printf("\n");
	q=p;
	printf("¶ÑÅÅÐò(´ó¸ù¶Ñ):\n");
	duida(q,9);
	q=p;
	printf("¶ÑÅÅÐò(Ð¡¸ù¶Ñ):\n");
	duixiao(q,9);
	q=p;
	printf("¹é²¢ÅÅÐò:\n");
    guibin(p,0,9);
	for(int i=0;i<10;i++)
    printf("%d ",q[i]);
	printf("\n");
	jisu(q,10,4,1);
	printf("»ùÊýÅÅÐò:\n");
	for(int i=0;i<10;i++)
    printf("%d ",q[i]);
	printf("\n");
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define Max 100
double zhong(double a[],double b[],int n,int m){
	int i,j,c;
	double d;
	for(i=n,j=0;i<m+n,j<m;i++,j++){
		a[i]=b[j];
	}
	for(i=0;i<m+n-1;i++){
		for(j=0;j<n+m-i;j++){
			if(a[j]>a[j+1]){
				c=a[j];
				a[j]=a[j+1];
				a[j+1]=c;
			}
		}
	}
	if((n+m)%2==0)
	d=(a[(n+m)/2]+a[(n+m)/2+1])/2;
	else
	d=a[(n+m)/2];
	return d;
}
int main(){
	int i,j,n,m;
	scanf("%d",&n);
	double a[Max],b[Max];
	for(i=0;i<n;i++)
	scanf("%lf",&a[i]);
	scanf("%d",&m);
	for(i=0;i<m;i++)
	scanf("%lf",&b[i]);
	double d;
	d=zhong(a,b,n,m);
	printf("%.2f",d);
	return 0;
}

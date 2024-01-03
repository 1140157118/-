#include<bits/stdc++.h>
using namespace std;
void pai(int a[],int &b,int n){
	b=0;
	int c;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i;j++)
		if(a[j]>a[j+1]){
		b++;
		c=a[j];
		a[j]=a[j+1];
		a[j+1]=c;
	}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int b;
	pai(a,b,n);
	printf("%d",b);
	return 0;
}

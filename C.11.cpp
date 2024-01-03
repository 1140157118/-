#include<bits/stdc++.h>
using namespace std;
#define Max 100
void gn(char *p,int ne[]){
	int j;
	int k;
	ne[0]=-1;
	j=0;
	k=-1;
	while(j<(strlen(p))){
		if(k==-1||p[j]==p[k]){
			j++;
			k++;
			ne[j]=k;
		}else
		k=ne[k];
	}
} 
int kmp(char *p,char *q){
	int ne[Max];
	int i,j;
	i=j=0;
	int lon1=strlen(p);
	int lon2=strlen(q);
	gn(q,ne);
	while(i<lon1&&j<lon2){
		if(j==-1||p[i]==q[j]){
			i++;
			j++;
		}else
		j=ne[j];
	}
	if(j>=lon2)
	return (i-lon2);
	else
	return -1;
}
void gnv(char *p,int nev[]){
	int j,k;
	j=0;
	k=-1;
	nev[0]=-1;
	while(j<strlen(p)-1){
		if(k==-1||p[j]==p[k]){
			j++;
			k++;
			if(p[j]!=p[k])
			nev[j]=k;
			else
			nev[j]=nev[k];
		}else
		k=nev[k];
	}
}
int kmpplus(char *p,char *q){
	int nev[Max];
	int i,j;
	i=j=0;
	int lon1=strlen(p);
	int lon2=strlen(q);
	gnv(q,nev);
	while(i<lon1&&j<lon2){
		if(j==-1||p[i]==q[j]){
			i++;
			j++;
		}else
		j=nev[j];
	}
	if(j>=lon2)
	return (i-lon2);
	else
	return -1;
}
int main(){
	char p[Max],q[Max];
	gets(p);
	gets(q);
	int i;
	i=kmpplus(p,q);
	if(i==-1)
	printf("Œﬁ∑®∆•≈‰\n");
	else
	printf("%d\n",i);
	return 0;
}

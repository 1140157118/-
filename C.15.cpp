#include<bits/stdc++.h>
using namespace std;
#define Max 100
typedef struct{
	double b[Max];
	int t;
}st;
void in(st *&p){
	p=(st*)malloc(sizeof(st));
	p->t=-1;
}
int pan(st *p){
	return (p->t==-1);
}
void pu(st *&p,double n){
	if(p->t==Max-1){
		printf("error\n");
		exit(1);
	}
	p->b[++p->t]=n;
}
double pop(st *&p){
	if(p->t==-1){
		printf("error");
		exit(1);
	}
	return p->b[p->t--];
}
double pe(st *p) {
    if (pan(p) ){
        printf("error\n");
        exit(1);
    }
    return p->b[p->t];
}
int Getp(char p){
	 switch(p) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}
double perO(double n,double m,char p){
	switch (p) {
        case '+': return n+m;
        case '-': return n-m;
        case '*': return n*m;
        case '/': return n/m;
        case '^': return pow(n,m);
        default:  return 0;
    }
}
double eva(char *p){
	st *opnds,*opors;
	in(opnds);
	in(opors);
	int i=0;
	int is=0;
	while(p[i]!='\0'){
		if(isdigit(p[i])||p[i]=='.'){
		double opnd=strtod(&p[i],NULL);	
		if (is){
                opnd=-opnd; // ������Ϊ������������ȡ��
                is=0; // ���ø������
            }
            pu(opnds,opnd);
            while (isdigit(p[i])||p[i]=='.'){
                i++;
            }
		}else if(p[i]=='('){
            // ����������
            pu(opors,'(');
            i++;
	}else if(p[i]==')') {
            // ���������ţ�ִ����Ӧ����
            while(!pan(opors)&&pe(opors)!='('){
                double opnd2=pop(opnds);
                double opnd1=pop(opnds);
                char opor1=pop(opors);
                double r=perO(opnd1,opnd2,opor1);
                pu(opnds, r);
            } 
            if(!pan(opors)&&pe(opors)=='(') {
                pop(opors); // ����������
            }
            i++;
        }else if (p[i]=='+'||p[i]=='-'||p[i]=='*'||p[i]=='/'||p[i] =='^'){
            // �����������ִ����Ӧ����
            if (p[i]=='-'&&(i==0||p[i-1]=='(')){
                // ����������ţ����Ҹ���ǰ���������Ż���ʽ�Ŀ�ͷ��������һ������Ϊ����
                is=1;
                i++;
                continue;
            }
            while (!pan(opors)&&Getp(pe(opors))>=Getp(p[i])){
                double opnd2 =pop(opnds);
                double opnd1 =pop(opnds);
                char opor1 =pop(opors);
                double r=perO(opnd1,opnd2,opor1);
                pu(opnds, r);
            }
            pu(opors,p[i]);
            i++;
        }
		else{
            // ���Կո�������Ƿ��ַ�
            i++;
        }
    }
    while (!pan(opors)) {
       double opnd2=pop(opnds);
                double opnd1=pop(opnds);
                char opor1=pop(opors);
                double r=perO(opnd1,opnd2,opor1);
                pu(opnds,r);
    }
    return pop(opnds);
}
int main(){
	char p[Max];
	fgets(p, sizeof(p), stdin);
	int i=0;
	while(p[i]!='\0'){
		if(p[i]=='\n'){
		p[i]='\0';
		break;
	}
		i++;
	}
	double n=eva(p);
	printf("%f",n);
	return 0;
}


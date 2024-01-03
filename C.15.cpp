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
                opnd=-opnd; // 如果标记为负数，则将数字取负
                is=0; // 重置负数标记
            }
            pu(opnds,opnd);
            while (isdigit(p[i])||p[i]=='.'){
                i++;
            }
		}else if(p[i]=='('){
            // 处理左括号
            pu(opors,'(');
            i++;
	}else if(p[i]==')') {
            // 处理右括号，执行相应运算
            while(!pan(opors)&&pe(opors)!='('){
                double opnd2=pop(opnds);
                double opnd1=pop(opnds);
                char opor1=pop(opors);
                double r=perO(opnd1,opnd2,opor1);
                pu(opnds, r);
            } 
            if(!pan(opors)&&pe(opors)=='(') {
                pop(opors); // 弹出左括号
            }
            i++;
        }else if (p[i]=='+'||p[i]=='-'||p[i]=='*'||p[i]=='/'||p[i] =='^'){
            // 处理运算符，执行相应运算
            if (p[i]=='-'&&(i==0||p[i-1]=='(')){
                // 如果遇到负号，并且负号前面是左括号或表达式的开头，则标记下一个数字为负数
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
            // 忽略空格和其他非法字符
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


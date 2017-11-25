#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAXOP 100
#define INFINITY 1e9
//52 31 + 85 12 / *

typedef struct SNode
{
	int *Data;
	int Top;
	int MaxSize;
}*Stack;

Stack CreateStack(int Max)
{
	Stack S;
	S =(Stack)malloc(sizeof(struct SNode));
	S->Data = (int *)malloc(Max*sizeof(int));
	S->Top = -1;
	S->MaxSize =Max;
	return S;
}

int IsEmpty(Stack S)
{
	return (S->Top == -1);
}

int IsFull(Stack S)
{
	return (S->Top == S->MaxSize-1);
}

int Push(Stack S,int x)
{
	if(S->Top == S->MaxSize-1||S->Top>S->MaxSize)//栈满
	{
		printf("堆栈满！");
		return -1;
	}
	else{
		S->Data[++(S->Top)] = x;
		return 1;
	}
}

int pop(Stack S)    //出栈
{
	if(S->Top == -1)
	{
		printf("栈堆为空");
		return -1;
	}
	else 
	return S->Data[(S->Top)--];
}

int GetOp(char *Expr, int *start, char *str)
{
	/*从*star开始读入下一个对象(操作数和运算符),并保存在字符串str中*/
	int i = 0;	
	/*跳过表达式前空格*/
	while((str[0] = Expr[(*start)++])==' ');
	while(str[i]!=' '&&str[i]!='\0')
	{
		str[++i] = Expr[(*start)++];
	}
	if(str[i]=='\0')
		(*start)--;
	str[i]='\0';
	
	if(i==0) return -1;
	else if(isdigit(str[0])||isdigit(str[1]))
		return 1;
	else
		return 0; 
}

float PostfixExp(char *Expr)
{
	//调用GetOp函数读入后缀表达式并求值
	Stack S;
	int T;
	float Op1,Op2;
	char str[MAXOP];
	int start = 0;
	int num = 0;
	
	S = CreateStack(MAXOP);
	
	Op1 = Op2 =0;
	while((T = GetOp(Expr,&start,str))!=-1)
	{
		if(T==1)
		{
			num = atof(str);
			Push(S,num);
		}
		else if(T == 0)
		{
			if(!IsEmpty(S))
			{
				Op2 = pop(S);
			}
			else
			Op2 = INFINITY;
			if(!IsEmpty(S)) Op1 = pop(S);
			else Op2 = INFINITY;
			switch(str[0])
			{
				case '+':Push(S,Op1+Op2);break;
				case '-':Push(S,Op1-Op2);break;
				case '*':Push(S,Op1*Op2);break;
				case '/':if(Op2 != 0.0)Push(S,Op1/Op2);else {printf("输入分母数据有误，分母默认为1\n"),Op2=1;Push(S,Op1/Op2);}break;
				default:
				printf("遇到未知运算符");
				Op2 = INFINITY;
				break;
			}
			if(Op2 >= INFINITY) break;
		}
	 } 
	 if(Op2<INFINITY)
	 {
	 	if(!IsEmpty(S))
	 		Op2 = pop(S);
	 	else 
	 		Op2 = INFINITY;
	 }
	 free(S);
	 return Op2;
}

int main()
{
	char Expr[MAXOP];
	float f;
	printf("请输入后缀表达式：");
	gets(Expr);
	f = PostfixExp(Expr);
	if(f<INFINITY)
		printf("%.4f\n",f);
	else
		printf("表达式错误！\n");
	return 0;
}

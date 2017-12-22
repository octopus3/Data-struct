#include<stdio.h>
#include<stdlib.h>
#define ERROR -1
typedef struct node{
	int data;
	struct node *Next;
}Link;

Link *creat(Link *L)
{
	L = (Link *)malloc(sizeof(Link));
	L->Next=NULL;
	return L;
}

/*��������*/
int Length(Link *L)
{
	int len = 0;
	Link *r;
	r=L;
	while(r)
	{
		r=r->Next;
		len++;
	}
	return len;
}

int FindK(int K,Link * L) //��λ�����
{
	Link *p;
	int n = 1;
	p=L;
	while(p&&n<K)
	{
		p=p->Next;
		n++;
	}
	if(n==K&&p)
		return p->data;
	else
		return ERROR;
} 

void PrintFindData(int data)
{
	if(data!=ERROR)
	{
		printf("���ҵ���������:%d",data);
	}
	else
	{
		printf("����"); 
	}
}

Link *Insert(Link *L,int x,int i)
{
	Link *t,*r;
	t = (Link*) malloc(sizeof(Link));
	t->data = x;
	if(i == 1)
	{
		t->Next = L;
		return t; //����ͷָ�� 
	}
	else
	{
		int cnt = 1;
		r = L;
		while(r && cnt<i-1)
		{
			r = r->Next;
			cnt++;
		}
		if(r==NULL || cnt != i-1 )
		{
			printf("����λ�õĲ�������\n");
			free(t);
			return ERROR;
		}
		else
		{
			t->Next = r->Next;
			r->Next = t;
			return L;
		}
	}
}

int main()
{
	Link *Head;
	int len; 
	int x=0,data=0;
	Head = creat(Head);
	len = Length(Head);
	printf("������Ϊ:%d\n",len);
	scanf("%d",&x);
	data=FindK(x,Head);
    PrintFindData(data);
    
}

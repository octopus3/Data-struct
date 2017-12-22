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

/*求链表长度*/
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

int FindK(int K,Link * L) //按位序查找
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
		printf("查找到的数据是:%d",data);
	}
	else
	{
		printf("错误！"); 
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
		return t; //返回头指针 
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
			printf("插入位置的参数错误\n");
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
	printf("链表长度为:%d\n",len);
	scanf("%d",&x);
	data=FindK(x,Head);
    PrintFindData(data);
    
}

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
//线性表的顺序存储 
//线性表的结构体 
typedef struct LNode{
	int data[MAXSIZE];
	int Last;
}*List;

//线性表的创建函数 
List MakeEmpty()
{
	List L;
	L = (List)malloc(sizeof(struct LNode));
	L->Last  = -1;
	return L;
}

/*线性表的查找函数*/
int Find(List L,int X)
{
	int i = 0;
	while(i<=L->Last && L->data[i]!=X)
	{
		i++;
	}
	if(i>L->Last) return -1;
	else 
	return i;
}

int Insert(List L,int X,int i)
{
	int j;
	if(L->Last==MAXSIZE-1)
	{
		printf("表满");
		return 0;
	}
	if(i<1 || i>L->Last+2)
	{
		//检查插入位序的合法性：是否存在1~n+1。n为当前元素个数，即Last + 1 
		printf("位序不合法！");
		return 0; 
	}
	for(j = L->Last; j>=i-1;j--)
	{
		L->data[j+1] = L->data[j]; //将位序i，及以后元素按顺序向后移动 
	}
	L->data[i-1] = X;
	L->Last++;
	return 1;
} 

int Delete(List L,int i)
{
	int j;
	if(i<1 || i>L->Last+1)
	{
		printf("位序%d不存在元素",i);
		return 0;
	}
	for(j = i;j<=L->Last;j++)
	{
		L->data[j-1]=L->data[j];
	}
	L->Last--;
	return 1; 
 } 
 
 int main()
 {
 	int i = 0;
 	int X = 0;
 	List L=NULL;
 	L = MakeEmpty();
 	for(i=0;i<MAXSIZE;i++)
 	{
 		printf("请为线性表赋值(输入-1时结束):");
 		scanf("%d",&X);
 		if(X==-1)
 		{
 			break;
		}
		else
 		Insert(L,X,i);
	}
	Find(L,3);
	Delete(L,3);
	Find(L,3);
	getch();
	return 0;
 }


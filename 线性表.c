#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
//���Ա��˳��洢 
//���Ա�Ľṹ�� 
typedef struct LNode{
	int data[MAXSIZE];
	int Last;
}*List;

//���Ա�Ĵ������� 
List MakeEmpty()
{
	List L;
	L = (List)malloc(sizeof(struct LNode));
	L->Last  = -1;
	return L;
}

/*���Ա�Ĳ��Һ���*/
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
		printf("����");
		return 0;
	}
	if(i<1 || i>L->Last+2)
	{
		//������λ��ĺϷ��ԣ��Ƿ����1~n+1��nΪ��ǰԪ�ظ�������Last + 1 
		printf("λ�򲻺Ϸ���");
		return 0; 
	}
	for(j = L->Last; j>=i-1;j--)
	{
		L->data[j+1] = L->data[j]; //��λ��i�����Ժ�Ԫ�ذ�˳������ƶ� 
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
		printf("λ��%d������Ԫ��",i);
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
 		printf("��Ϊ���Ա�ֵ(����-1ʱ����):");
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


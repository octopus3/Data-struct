#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *NEXT;
}*Link,link;
/*
@function:���ڴ���һ������Ľڵ� 
@writer������ 
@create time:2017��9��28��23:56:44
@latest modify time:2017��9��28��23:57:13
@return���ɹ�����ͷָ�룬ʧ�ܷ���NULL 
*/
 Link createlist()
 {
 	link *L;                  //L��ʾ��ͷ��l��ʾ��β 
 	L = (Link)malloc(sizeof(link));
 	if(!L)
	{
		printf("\n- - - - - WARNING- - - - - - - -\n");
		printf("\n allocate memory failure!!   \n");
		return 0;
	}
    
 	return L;
 }
 /*
 @function�����ڼ�������
 @writer������
 @create time��2017��9��28��23:58:36
 @latest modify time��2017��9��28��23:58:50
 @return���޷���ֵ 
 */
 void inputdata(Link L)
 {
 	Link l=L,r;	//r��ʾ�½ڵ㣬l��ʾ����ĩβ�Ľڵ� 
	int len=0,i;
	printf("������ڵ㳤�ȣ�");
	scanf("%d",&len);
	scanf("%d",&L->data);
	if(len <= 1){
	L->NEXT=NULL;return;}
	for(i=0;i<len;i++)
	{
		r= (Link)malloc(sizeof(link));
		scanf("%d",&r->data);
		r->NEXT = NULL;
		l->NEXT=r;
		l = r;
	}
 }
 void outputdata(Link L)
 {
 	Link l=L;
    while(l)
    {
    	printf("%d ",l->data);
    	l=l->NEXT;
	}
	
 }
int main()
{
	link *Head;
	Head = createlist();
	inputdata(Head);
	outputdata(Head);
	return 0; 
}


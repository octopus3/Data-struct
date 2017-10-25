#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *NEXT;
}*Link,link;
/*
@function:用于创建一个链表的节点 
@writer：章鱼 
@create time:2017年9月28日23:56:44
@latest modify time:2017年9月28日23:57:13
@return：成功返回头指针，失败返回NULL 
*/
 Link createlist()
 {
 	link *L;                  //L表示表头，l表示表尾 
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
 @function：用于键入数据
 @writer：章鱼
 @create time：2017年9月28日23:58:36
 @latest modify time：2017年9月28日23:58:50
 @return：无返回值 
 */
 void inputdata(Link L)
 {
 	Link l=L,r;	//r表示新节点，l表示链表末尾的节点 
	int len=0,i;
	printf("请输入节点长度：");
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


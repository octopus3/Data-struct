> # **data struct** :smile: :smile: :smile: :smile:
>**C语言描述**
>>  # **链表**
>>> ## 链表的结构体创建
>>>```c
>>>typedef struct node
>>> {
>>>	int data;
>>> 	struct node *NEXT;
>>> }*Link,link;
>>>```
>>> ## 链表的创建函数
>>>```c
>>> Link createlist()
>>> {
>>> 	 link *L;                  //L表示表头，l表示表尾 
>>> 	 L = (Link)malloc(sizeof(link));
>>>	  if(!L)
>>>	  {
>>>	  printf("\n- - - - - WARNING- - - - - - - -\n");
>>>	  printf("\n allocate memory failure!!   \n");
>>>	  return 0;
>>>	  }
>>>   	return L;
>>> }
>>>```
>>> ## 链表的赋值函数
>>>```c
>>> void inputdata(Link L)
>>> {
>>> 	Link l=L,r;	//r表示新节点，l表示链表末尾的节点 
>>>	int len=0,i;
>>>	printf("请输入节点长度：");
>>>	scanf("%d",&len);
>>>	scanf("%d",&L->data);
>>>	if(len <= 1){
>>>	L->NEXT=NULL;return;}
>>>	for(i=0;i<len;i++)
>>>	{
>>>		r= (Link)malloc(sizeof(link));
>>>		scanf("%d",&r->data);
>>>		r->NEXT = NULL;
>>>		l->NEXT=r;
>>>		l = r;
>>>	}
>>> }
>>> ```
>>> ## 链表的遍历函数
>>> ```c
>>> void outputdata(Link L)
>>> {
>>> 	Link l=L;
>>>    while(l)
>>>    {
>>>    	printf("%d ",l->data);
>>>    	l=l->NEXT;
>>>	}
>>> }
>>> ```
>>> [具体代码](/链表1.c)

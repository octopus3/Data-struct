> # **data struct**
  :smile: :smile: :smile: :smile:
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


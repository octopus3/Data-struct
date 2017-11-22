> # **data struct**
  :smile: :smile: :smile: :smile:
>>  # **链表**
>>> ## 链表的结构体创建
>>>typedef struct node<br>
>>> {<br>
>>>	int data;<br>
>>> 	struct node *NEXT;<br>
>>> }*Link,link;<br>
>>> ## 链表的创建函数
>>> Link createlist()<br>
>>> {<br>
>>> 	 link *L;                  //L表示表头，l表示表尾 <br>
>>> 	 L = (Link)malloc(sizeof(link));<br>
>>>	  if(!L)<br>
>>>	  {<br>
>>>	  printf("\n- - - - - WARNING- - - - - - - -\n");<br>
>>>	  printf("\n allocate memory failure!!   \n");<br>
>>>	  return 0;<br>
>>>	  }<br>
>>>   	return L;<br>
>>> }<br>

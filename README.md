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
>> # **栈**
>>> ## 栈的结构体实现
>>> ```c
>>> typedef struct SNode
>>>{
>>>	int *Data;
>>>	int Top;
>>>	int MaxSize;
>>>}*Stack;
>>> ```
>>> ## 栈的创建函数
>>> ```c
>>>Stack CreateStack(int Max)
>>>{
>>>	Stack S;
>>>	S =(Stack)malloc(sizeof(struct SNode));
>>>	S->Data = (int *)malloc(Max*sizeof(int));
>>>	S->Top = -1;
>>>	S->MaxSize =Max;
>>>	return S;
>>>}
>>>```
>>> ## 判断栈是否为空函数
>>> ```c
>>> int IsEmpty(Stack S)
>>>{
>>>	return (S->Top == -1);
>>>}
>>> ```
>>> ##判断栈是否为满的函数
>>> ```c
>>> int IsFull(Stack S)
>>>{
>>>	return (S->Top == S->MaxSize-1);
>>>}
>>> ```
>>> ## 出栈函数
>>> ```c
>>> int Push(Stack S,int x)
>>>{
>>>	if(S->Top == S->MaxSize-1||S->Top>S->MaxSize)//Õ»Âú
>>>	{
>>>		printf("¶ÑÕ»Âú£¡");
>>>		return -1;
>>>	}
>>>	else{
>>>		S->Data[++(S->Top)] = x;
>>>		return 1;
>>>	}
>>>}
>>> ```
>>> ##入栈函数
>>> ```c
>>>int pop(Stack S)    //³öÕ»
>>>{
>>>	if(S->Top == -1)
>>>	{
>>>		printf("Õ»¶ÑÎª¿Õ");
>>>		return -1;
>>>	}
>>>	else 
>>>	return S->Data[(S->Top)--];
>>>}
>>> ```
>>> ## 读取后缀表达式函数
>>> ```c
>>>int GetOp(char *Expr, int *start, char *str)
>>>{
>>>		/*´Ó*star¿ªÊ¼¶ÁÈëÏÂÒ»¸ö¶ÔÏó(²Ù×÷ÊýºÍÔËËã·û),²¢±£´æÔÚ×Ö·û´®strÖÐ*/
>>>	int i = 0;	
>>>	/*Ìø¹ý±í´ïÊ½Ç°¿Õ¸ñ*/
>>>	while((str[0] = Expr[(*start)++])==' ');
>>>	while(str[i]!=' '&&str[i]!='\0')
>>>	{
>>>		str[++i] = Expr[(*start)++];
>>>	}
>>>	if(str[i]=='\0')
>>>		(*start)--;
>>>	str[i]='\0';
>>>	
>>>	if(i==0) return -1;
>>>	else if(isdigit(str[0])||isdigit(str[1]))
>>>		return 1;
>>>	else
>>>		return 0; 
>>>}
>>> ```
>>> ## 计算操作
>>> ```c
>>> float PostfixExp(char *Expr)
>>>{
>>>	//µ÷ÓÃGetOpº¯Êý¶ÁÈëºó×º±í´ïÊ½²¢ÇóÖµ
>>>	Stack S;
>>>	int T;
>>>	float Op1,Op2;
>>>	char str[MAXOP];
>>>	int start = 0;
>>>	int num = 0;
>>>	
>>>	S = CreateStack(MAXOP);
>>>	
>>>	Op1 = Op2 =0;
>>>	while((T = GetOp(Expr,&start,str))!=-1)
>>>	{
>>>		if(T==1)
>>>		{
>>>			num = atof(str);
>>>			Push(S,num);
>>>		}
>>>		else if(T == 0)
>>>		{
>>>			if(!IsEmpty(S))
>>>			{
>>>				Op2 = pop(S);
>>>			}
>>>			else
>>>			Op2 = INFINITY;
>>>			if(!IsEmpty(S)) Op1 = pop(S);
>>>			else Op2 = INFINITY;
>>>			switch(str[0])
>>>			{
>>>				case '+':Push(S,Op1+Op2);break;
>>>				case '-':Push(S,Op1-Op2);break;
>>>				case '*':Push(S,Op1*Op2);break;
>>>				case '/':if(Op2 != 0.0)Push(S,Op1/Op2);else {printf("ÊäÈë·ÖÄ¸Êý¾ÝÓÐÎó£¬·ÖÄ¸Ä¬ÈÏÎª1\n"),Op2=1;Push(S,Op1/Op2);}break;
>>>				default:
>>>				printf("Óöµ½Î´ÖªÔËËã·û");
>>>				Op2 = INFINITY;
>>>				break;
>>>			}
>>>			if(Op2 >= INFINITY) break;
>>>		}
>>>	 } 
>>>	 if(Op2<INFINITY)
>>>	 {
>>>	 	if(!IsEmpty(S))
>>>	 		Op2 = pop(S);
>>>	 	else 
>>>	 		Op2 = INFINITY;
>>>	 }
>>>	 free(S);
>>>	 return Op2;
>>>}
>>> ```
>>> [具体代码](/计算后缀表达式.c)
>># **二叉树**
>>> ## 二叉树的结构体创建
>>> ```c
>>> typedef struct bintreeNode
>>>{
>>>	int data;
>>>	struct bintreeNode *Left;
>>>	struct bintreeNode *Right;
>>>}Tree;
>>> ```
>>> ## 二叉树的构建
>>> ```c
>>> Tree* createBinaryTree()  
>>>{     
>>>	static int i = 0;
>>>   Tree *p;  
>>>    int num;  
>>>    printf("请输入第%d个节点的值：",i); 
>>>    scanf("%d",&num);  
>>>    if(num!=0)
>>>	i++; 
>>>    if(num == 0)     //如果到了叶子节点，接下来左和右分别赋值为0 
>>>    {  
>>>        p = NULL;  
>>>    }  
>>>    else  
>>>    {  
>>>        p = (Tree*)malloc(sizeof(Tree));  
>>>        p->data = num;  
>>>        p->Left  = createBinaryTree();  //创建左子树  
>>>        p->Right = createBinaryTree();  //创建右子树 
>>>    }  
>>>    return p;  
>>>}  
>>> ```
>>> ## 二叉树的前序遍历
>>> ```c
>>> void  firstTraversal(Tree *BT)
>>>{
>>>	if(BT)
>>>	{
>>>		printf("%d ",BT->data);
>>>		firstTraversal (BT->Left);
>>>		firstTraversal(BT->Right);
>>>	}
>>>} 
>>> ```
>>> ## 二叉树的中序遍历
>>> ```c
>>> void  firstTraversal(Tree *BT)
>>>{
>>>	if(BT)
>>>	{
>>>		firstTraversal (BT->Left);
>>>		printf("%d ",BT->data);
>>>		firstTraversal(BT->Right);
>>>	}
>>>} 
>>> ```
>>> ## 二叉树的后序遍历
>>> ```c
>>> void  firstTraversal(Tree *BT)
>>>{
>>>	if(BT)
>>>	{
>>>		firstTraversal (BT->Left);
>>>		firstTraversal(BT->Right);
>>>		printf("%d ",BT->data);
>>>	}
>>>} 
>>> ```
>>> ## 二叉树的节点统计函数
>>> ```c
>>> int Nodenum(Tree* root)  
>>>{  
>>>    if(root == NULL)  
>>>    {  
>>>        return 0;  
>>>    }  
>>>    else  
>>>    {  
>>>        return 1+Nodenum(root->Left)+Nodenum(root->Right);  
>>>    }  
>>>}  
>>> ```
>>> ## 二叉树的深度计算函数
>>> ```c
>>> int DepthOfTree(Tree* root)  
>>>{  
>>>    if(root)  
>>>    {  
>>>        return DepthOfTree(root->Left)>DepthOfTree(root->Right)?DepthOfTree(root->Left)+1:DepthOfTree(root->Right)+1;  
>>>    }  
>>>    if( root == NULL )  
>>>    {  
>>>        return 0;  
>>>    }  
>>>}  
>>> ```
>>> [具体代码](/二叉树.c)

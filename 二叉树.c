#include<stdio.h>
#include<stdlib.h>
typedef struct bintreeNode
{
	int data;
	struct bintreeNode *Left;
	struct bintreeNode *Right;
}Tree;

//前序遍历
void  firstTraversal(Tree *BT)
{
	if(BT)
	{
		printf("%d ",BT->data);
		firstTraversal (BT->Left);
		firstTraversal(BT->Right);
	}
} 

void secondTraversal(Tree *BT)
{
	if(BT)
	{
		secondTraversal(BT->Left);
		printf("%d ",BT->data);
		secondTraversal(BT->Right);
	}
 } 
 
 void thirdTraversal(Tree *BT)
{
	if(BT)
	{
		thirdTraversal(BT->Left);
		thirdTraversal(BT->Right);
		printf("%d ",BT->data);
	}
 } 


Tree* createBinaryTree()  
{     
	static int i = 0;
    Tree *p;  
    int num;  
    printf("请输入第%d个节点的值：",i); 
    scanf("%d",&num);  
    if(num!=0)
	i++; 
    if(num == 0)     //如果到了叶子节点，接下来左和右分别赋值为0 
    {  
        p = NULL;  
    }  
    else  
    {  
        p = (Tree*)malloc(sizeof(Tree));  
        p->data = num;  
        p->Left  = createBinaryTree();  //创建左子树  
        p->Right = createBinaryTree();  //创建右子树 
    }  
    return p;  
}  

int Nodenum(Tree* root)  
{  
    if(root == NULL)  
    {  
        return 0;  
    }  
    else  
    {  
        return 1+Nodenum(root->Left)+Nodenum(root->Right);  
    }  
}  

int DepthOfTree(Tree* root)  
{  
    if(root)  
    {  
        return DepthOfTree(root->Left)>DepthOfTree(root->Right)?DepthOfTree(root->Left)+1:DepthOfTree(root->Right)+1;  
    }  
    if( root == NULL )  
    {  
        return 0;  
    }  
}  

int main()
{
	Tree *head;
	head = createBinaryTree();
	printf("前序遍历二叉树");
	firstTraversal(head);
	printf("中序遍历二叉树");
	secondTraversal(head);
	printf("后序遍历二叉树");
	thirdTraversal(head);
	printf("\n有效节点总数目:%d\n",Nodenum(head)); 
	printf("\n二叉树的深度:%d\n",DepthOfTree(head));
	return 0;
}

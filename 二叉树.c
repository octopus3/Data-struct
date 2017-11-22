#include<stdio.h>
#include<stdlib.h>
typedef struct bintreeNode
{
	int data;
	struct bintreeNode *Left;
	struct bintreeNode *Right;
}Tree;

//ǰ�����
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
    printf("�������%d���ڵ��ֵ��",i); 
    scanf("%d",&num);  
    if(num!=0)
	i++; 
    if(num == 0)     //�������Ҷ�ӽڵ㣬����������ҷֱ�ֵΪ0 
    {  
        p = NULL;  
    }  
    else  
    {  
        p = (Tree*)malloc(sizeof(Tree));  
        p->data = num;  
        p->Left  = createBinaryTree();  //����������  
        p->Right = createBinaryTree();  //���������� 
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
	printf("ǰ�����������");
	firstTraversal(head);
	printf("�������������");
	secondTraversal(head);
	printf("�������������");
	thirdTraversal(head);
	printf("\n��Ч�ڵ�����Ŀ:%d\n",Nodenum(head)); 
	printf("\n�����������:%d\n",DepthOfTree(head));
	return 0;
}

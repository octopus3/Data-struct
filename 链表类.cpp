#include<iostream>
using namespace std;

typedef struct Node{
	int num;
	struct Node * NEXT;
}*Link,link;

class List{
private:
	Link head;
	int length;		//表示链表节点个数 
protected: 
public:
	List(int); 		//构造函数初始化链表  自动初始化链表对象
	int LinkCount();
	~List();
	void sort();
	void addNodeBefore();//列表前面插入节点
	void addNOdeAfter();
	bool isCreat();
	void deleteNode();
	List CreatList(int);
	void initNode(Link);
};

List::List(int n)
{
	head = NULL;
	length = 0;
	head = CreatList(n);
}

List::CreatList(int n)
{
	Link head,ptrl,NewNode;
	for(int i = n;i<n;i++)
	{
		NewNode = new Node;
		initNode(NewNode);
		if(0 == i)
		{
			head = NewNode;			//在一开始，让头指针链接新节点，ptrl指针作为灵活指针 用于在节点之间的'跳跃' 
			ptrl = head;		
		}
		else
		{
			ptrl->NEXT=NewNode;
		}
		NewNode->NEXT=NULL;
		ptrl = NewNode;				//每结束一次循环	ptrl指针跳跃 
	} 
	return head;
}

List::initNode(Link newNode)
{
	cout<<"请输入数据:";
	cin >> newNode->num;
}

bool isCreat()
{
	if(head)
	{
		return true;
	}
	else
	{
		return false;
	}
}

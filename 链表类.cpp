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
	Link Before,After;
protected: 
public:
	List(int); 		//构造函数初始化链表  自动初始化链表对象
	int LinkCount();
	~List();
	void sort();
	void addNodeBefore();//链表前面插入节点
	void addNodeAfter(); // 链表后面插入节点 
	bool isCreat();
	void deleteNode();
	Link CreatList(int);
	void initNode(Link);
	void printList();
	void Search(int);
};

List::List(int n)
{
	head = NULL;
	length = 0;
	head = CreatList(n);
}

Link List::CreatList(int n)
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

void List::initNode(Link newNode)
{
	cout<<"请输入数据:";
	cin >> newNode->num;
	this->length++;
}

bool List::isCreat()
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

void List::sort()
{
	int temp=0;
	After= Before = head;
	for(int i = 0;i<length;i++)
	{
		for(int j = i;j<length;i++)
		{
			After = Before->NEXT;
			if(Before->num > After->num)
			{
				temp = Before->num;
				Before->num = After->num;
				After->num = temp;
			}
		}
		Before = Before->NEXT;
	}
}

void List::printList()
{
	Link temp = this->head;
	if(length == 0||head)
	{
		cout<<"链表为空"<<endl;
	}
	while(temp&&length != 0)
	{
		cout << temp->num<< " " ;
		temp = temp->NEXT;
	}		
}

List::~List()
{
	Link ptr = this->head;
	delete ptr;
}

int List::LinkCount()
{
	cout << "节点数量为："<<this->length<<endl;
}

void List::addNodeAfter()
{
	Before = After = head;
	int num;
	int number;
	Link NewNode() = new Node;
	initNode(NewNode);
	cout<<"你需要按值查找插入节点还是按照链表个数来插入节点？"<<endl<<"1.按值查找插入节点"<<endl<<"2.按长度查找节点插入";
	cin>>num;
	if(1 == num)
	{
		cout<<"请输入你需要查找的值:";
		cin>>number;
		Search(number);
		if(!After)
		{
			cout<<"你找的值不存在"<<endl;
			delete NewNode;
			return;
		}
		else{
			Before = After;
			After->NEXT = NewNode;
			NewNode->NEXT = Before->NEXT;
		}
	}
	else if(2 == num)
	{
		cout<<"请输入你需要查找的节点位置(0~"<<this->length-1<<"):";
		cin>>number;
		for(int i = 0;i<number<<i++)
		{
			
		}
	}
	 
	 
}

void List::Search(int NUM)
{
	After = head->NEXT;
	int i =1;
	char choose;
	while(After)
	{
		Before = After;
		if(After->num == NUM)
		{ 
			cout <<"已查找到第"<<i<<"个节点"<< "值为："<<After->num<<"是否需要继续查找?（Y/N）"; 
			cin>>choose;
			if(choose == 'N'||choose == 'n')
			{
				break;
			}
			else if(choose == 'Y'|| choose == 'y')
			{
				cout<<"继续查找"<<endl;
			}
			else
			{
				cout <<"输入有误"<<endl;
			}
		}
		else if(!After)
		{
			cout<<"已经遍历完毕！"<<endl;
			break;			
		} 
		After = After->NEXT;
	}
}

int main()
{
	return 0;
}

#include<iostream>
using namespace std;

typedef struct Node{
	int num;
	struct Node * NEXT;
}*Link,link;

class List{
private:
	Link head;
	int length;		//��ʾ����ڵ���� 
protected: 
public:
	List(int); 		//���캯����ʼ������  �Զ���ʼ���������
	int LinkCount();
	~List();
	void sort();
	void addNodeBefore();//�б�ǰ�����ڵ�
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
			head = NewNode;			//��һ��ʼ����ͷָ�������½ڵ㣬ptrlָ����Ϊ���ָ�� �����ڽڵ�֮���'��Ծ' 
			ptrl = head;		
		}
		else
		{
			ptrl->NEXT=NewNode;
		}
		NewNode->NEXT=NULL;
		ptrl = NewNode;				//ÿ����һ��ѭ��	ptrlָ����Ծ 
	} 
	return head;
}

List::initNode(Link newNode)
{
	cout<<"����������:";
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

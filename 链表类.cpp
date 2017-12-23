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
	Link Before,After;
protected: 
public:
	List(int); 		//���캯����ʼ������  �Զ���ʼ���������
	int LinkCount();
	~List();
	void sort();
	void addNodeBefore();//����ǰ�����ڵ�
	void addNodeAfter(); // ����������ڵ� 
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

void List::initNode(Link newNode)
{
	cout<<"����������:";
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
		cout<<"����Ϊ��"<<endl;
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
	cout << "�ڵ�����Ϊ��"<<this->length<<endl;
}

void List::addNodeAfter()
{
	Before = After = head;
	int num;
	int number;
	Link NewNode() = new Node;
	initNode(NewNode);
	cout<<"����Ҫ��ֵ���Ҳ���ڵ㻹�ǰ����������������ڵ㣿"<<endl<<"1.��ֵ���Ҳ���ڵ�"<<endl<<"2.�����Ȳ��ҽڵ����";
	cin>>num;
	if(1 == num)
	{
		cout<<"����������Ҫ���ҵ�ֵ:";
		cin>>number;
		Search(number);
		if(!After)
		{
			cout<<"���ҵ�ֵ������"<<endl;
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
		cout<<"����������Ҫ���ҵĽڵ�λ��(0~"<<this->length-1<<"):";
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
			cout <<"�Ѳ��ҵ���"<<i<<"���ڵ�"<< "ֵΪ��"<<After->num<<"�Ƿ���Ҫ��������?��Y/N��"; 
			cin>>choose;
			if(choose == 'N'||choose == 'n')
			{
				break;
			}
			else if(choose == 'Y'|| choose == 'y')
			{
				cout<<"��������"<<endl;
			}
			else
			{
				cout <<"��������"<<endl;
			}
		}
		else if(!After)
		{
			cout<<"�Ѿ�������ϣ�"<<endl;
			break;			
		} 
		After = After->NEXT;
	}
}

int main()
{
	return 0;
}

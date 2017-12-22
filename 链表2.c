#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int e;
    struct NODE *next;
}node, *LinkList;

LinkList build_linklist()
{
    FILE *fp;
    if ((fp=fopen("number.txt","r"))==NULL)
    {
        printf("Can not open the file!");
        exit (1);
    }
    int t;
    LinkList r,p,head=NULL;
    while (fscanf(fp,"%d",&t)>0)
    {
        p=(LinkList)malloc(sizeof(node));
        p->e=t;
        p->next=NULL;
        if (!head)
            head=p;
        else
            r->next=p;
        r=p;
    }
    return head;
}

void search(LinkList head,int toSearch)
{
    int count=0;
    int flag=0;
    LinkList r=head;
    while (r!=NULL)
    {
        count++;
        if (r->e==toSearch)
        {
            printf("已经找到该元素，在第%d个位置\n",count);
            flag=1;
            break;
        }
        r=r->next;
    }
    if (!flag)
        printf("没有找到该元素！\n");
}

void del(LinkList *head,int toDel)
{
    if (!(*head))
    {
        printf("请先创建链表！\n");
        return ;
    }
    LinkList r=*head;
    LinkList p=NULL;
    int flag=0;
    while (r!=NULL)
    {
        if ((r==*head)&&(r->e==toDel))
        {
            (*head)=(*head)->next;
            flag=1;
            break;
        }
        if ((r!=*head)&&(r->e==toDel))
        {
            flag=1;
            for (p=*head;p!=NULL;p=p->next)
            {
                if (p->next==r)
                {
                    break;
                }
            }
            p->next=r->next;
            free(r);
            break;
        }
        r=r->next;
    }
    if (!flag)
        printf("未找到该元素！\n");
}

void insert(LinkList head,int n,int toInsert)
{
    if (!head)
    {
        printf("请先创建链表！");
        return ;
    }
    int count=0;
    LinkList p=head;
    while (p!=NULL)
    {
        if ((count++)==n)
        {
            LinkList r=(LinkList)malloc(sizeof(node));
            r->e=toInsert;
            r->next=p->next;
            p->next=r;
            break;
        }
        p=p->next;
    }
}

int getLengh(LinkList head)
{
    LinkList p=head;
    int i=0;
    while (p!=NULL)
    {
        i++;
        p=p->next;
    }
    return i;
}

void show(LinkList head)
{
    LinkList p=head;
    while (p!=NULL)
    {
        printf("%d  ",p->e);
        p=p->next;
    }
    printf("\n");
}

void rebuild(LinkList *head)
{
    LinkList r,p;
    p=(*head)->next;
    r=p->next;
    (*head)->next=NULL;
    while(p!=NULL)
    {
        p->next=*head;
        *head=p;
        p=r;
        if (r==NULL)
            continue;
        else
            r=r->next;
    }
}

void sort_linklist(LinkList head)
{
    LinkList r,p;
    int temp=0;
    for (r=head;r->next!=NULL;r=r->next)
     for (p=r->next;p!=NULL;p=p->next)
         if ((r->e)>(p->e))
         {
             temp=r->e;
             r->e=p->e;
             p->e=temp;
         }
}

int main()
{
    LinkList head=build_linklist();
    printf("链表已建立！原链表：\n");
    show(head);
    sort_linklist(head);
    printf("链表已经按照从小到大的顺序排好！排序后：\n");
    show(head);
    printf("\n");
    int c=0;
    while (1)
    {
        printf("1.查找指定元素\n");
        printf("2.插入一个给定元素\n");
        printf("3.删除一个指定元素\n");
        printf("4.统计链表的长度\n");
        printf("5.输出线性链表\n");
        printf("6.实现安逆序链表的重建\n");
        printf("请选择：");
        scanf("%d",&c);
        switch (c)
        {
            case 1:
            {
                printf("请输入要查找的元素：");
                int t;
                scanf("%d",&t);
                search(head,t);
                printf("\n");
                break;
            }
            case 2:
            {
                printf("请输入要插入的元素的值：");
                int toi;
                scanf("%d",&toi);
                printf("请输入要插入的位置：");
                int position;
                scanf("%d",&position);
                insert(head,position,toi);
                printf("\n");
                break;
            }
            case 3:
            {
                 printf("请输入要删除的元素的值：");
                 int tod;
                 scanf("%d",&tod);
                 del(&head,tod);
                 printf("\n");
                 break;
            }
            case 4:
            {
                printf("链表的长度是：%d\n",getLengh(head));
                printf("\n");
                break;
            }
            case 5:
            {
                show(head);
                printf("\n");
                break;
            }
            case 6:
            {
                rebuild(&head);
                show(head);
                printf("\n");
                break;
            }
            default:
            {
                exit(0);
            }
        }
    }
    return 0;
}

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
            printf("�Ѿ��ҵ���Ԫ�أ��ڵ�%d��λ��\n",count);
            flag=1;
            break;
        }
        r=r->next;
    }
    if (!flag)
        printf("û���ҵ���Ԫ�أ�\n");
}

void del(LinkList *head,int toDel)
{
    if (!(*head))
    {
        printf("���ȴ�������\n");
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
        printf("δ�ҵ���Ԫ�أ�\n");
}

void insert(LinkList head,int n,int toInsert)
{
    if (!head)
    {
        printf("���ȴ�������");
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
    printf("�����ѽ�����ԭ����\n");
    show(head);
    sort_linklist(head);
    printf("�����Ѿ����մ�С�����˳���źã������\n");
    show(head);
    printf("\n");
    int c=0;
    while (1)
    {
        printf("1.����ָ��Ԫ��\n");
        printf("2.����һ������Ԫ��\n");
        printf("3.ɾ��һ��ָ��Ԫ��\n");
        printf("4.ͳ������ĳ���\n");
        printf("5.�����������\n");
        printf("6.ʵ�ְ�����������ؽ�\n");
        printf("��ѡ��");
        scanf("%d",&c);
        switch (c)
        {
            case 1:
            {
                printf("������Ҫ���ҵ�Ԫ�أ�");
                int t;
                scanf("%d",&t);
                search(head,t);
                printf("\n");
                break;
            }
            case 2:
            {
                printf("������Ҫ�����Ԫ�ص�ֵ��");
                int toi;
                scanf("%d",&toi);
                printf("������Ҫ�����λ�ã�");
                int position;
                scanf("%d",&position);
                insert(head,position,toi);
                printf("\n");
                break;
            }
            case 3:
            {
                 printf("������Ҫɾ����Ԫ�ص�ֵ��");
                 int tod;
                 scanf("%d",&tod);
                 del(&head,tod);
                 printf("\n");
                 break;
            }
            case 4:
            {
                printf("����ĳ����ǣ�%d\n",getLengh(head));
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

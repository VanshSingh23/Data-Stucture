#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coeff;
    int power;
    struct node *next;
};
struct node *start=NULL,*start1=NULL;
struct node *start2head=NULL,*start2tail=NULL;
void create1(int n){
    int c,p,i;
    if(n==0)
    start=NULL;
    else{
        struct node *newnode;
        newnode=malloc(sizeof(struct node));
        printf("enter the coeffecient :");
        scanf("%d",&c);
        printf("enter the power :");
        scanf("%d",&p);
        newnode->coeff = c;
        newnode->power = p;
        newnode->next=NULL;
        start=newnode;
        struct node *p, *temp;
        p=start;
        for(i=2; i<=n; i++)
        {
            temp= malloc(sizeof(struct node));
            if(temp== NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            int co,po;
            printf("enter the coeffecient :");
            scanf("%d",&co);
            printf("enter the power :");
            scanf("%d",&po);
            temp->coeff = co;
            temp->power=po;
            temp->next = NULL;      
            p->next = temp;
            p = p->next;
        }
    }
}
void create2(int m)
{
    int c,p,i;
    if(m==0)
    start1=NULL;
    else{
        struct node *newnode;
        newnode=malloc(sizeof(struct node));
        printf("enter the coeffecient :");
        scanf("%d",&c);
        printf("enter the power :");
        scanf("%d",&p);
        newnode->coeff = c;
        newnode->power = p;
        newnode->next=NULL;
        start1=newnode;
        struct node *p, *temp;
        p=start1;
        for(i=2; i<=m; i++)
        {
            temp= malloc(sizeof(struct node));
            if(temp== NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            int co,po;
            printf("enter the coeffecient :");
            scanf("%d",&co);
            printf("enter the power :");
            scanf("%d",&po);
            temp->coeff = co;
            temp->power=po;
            temp->next = NULL;      
            p->next = temp;
            p = p->next;
        }
    }
}
void sum(int n,int m)
{
    struct node *p,*q;
    if(n>m)
    {
        p=start;
        q=start1;
    }
    else{
        p=start1;
        q=start;
    }
    while(p!=NULL)
    {
        if(start2head==NULL){
            if(p->power==q->power)
            {
                struct node *newnode;
                newnode=malloc(sizeof(struct node));
                newnode->coeff=p->coeff+q->coeff;
                newnode->power=p->power;
                start2head=newnode;
                start2tail=newnode;
                p=p->next;
                q=q->next;
            }
            else
            {
                struct node *newnode;
                newnode=malloc(sizeof(struct node));
                newnode->coeff=p->coeff;
                newnode->power=p->power;
                start2head=newnode;
                start2tail=newnode;
                p=p->next;
            }
        }
        else
        {
            if(p->power==q->power)
            {
                struct node *newnode;
                newnode=malloc(sizeof(struct node));
                newnode->coeff=p->coeff+q->coeff;
                newnode->power=p->power;
                start2tail->next=newnode;
                p=p->next;
                q=q->next;
            }
            else
            {
                struct node *newnode;
                newnode=malloc(sizeof(struct node));
                newnode->coeff=p->coeff;
                newnode->power=p->power;
                start2tail->next=newnode;
                p=p->next;
            }
        }    
    }
}
void display(struct node* startt)
{
    struct node *p=startt;
    if(p == NULL)
    {
        printf("List is empty.");
        return;
    }
    while(p != NULL)
    {
        printf("%d %d   ",p->coeff,p->power);
        p = p->next;                 
    }
}
void main()
{
    int n,m;
    printf("enter the value of n\n");
    scanf("%d",&n);
    printf("enter first polynomial\n");
    create1(n);
    display(start);
    printf("enter the value of m\n");
    scanf("%d",&m);
    printf("enter second polynomial\n");
    create2(m);
    display(start1);
    sum(n,m);
    display(start2head);
}
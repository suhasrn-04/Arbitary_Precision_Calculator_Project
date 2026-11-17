
//*Title			: Addition
//Description		: This function performs addition of two given large numbers and store the result in the resultant list.
//Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
//Input Parameters	: head1: Pointer to the first node of the first double linked list.
//			: tail1: Pointer to the last node of the first double linked list.
//			: head2: Pointer to the first node of the second double linked list.
//			: tail2: Pointer to the last node of the second double linked list.
//			: headR: Pointer to the first node of the resultant double linked list.
//Output			: Status (SUCCESS / FAILURE)

#include "apc.h"

Status validate_number(char *str)
{
    int i;

    if(str[0]=='\0')
        return FAILURE;

    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]<'0'||str[i]>'9')
            return FAILURE;
    }
    return SUCCESS;
}

Status validate_operator(char *str)
{
    if(strlen(str)!=1)
        return FAILURE;

    if(str[0]=='+'||str[0]=='-' || str[0]=='*' || str[0]=='x' || str[0]=='/'|| str[0]=='%')
        return SUCCESS;

    return FAILURE;
}

Status validate_cla(int argc,char *argv[])
{
    if(argc!=4)
    {
        printf("Error: Invalid number of arguments\n");
        return FAILURE;
    }

    if(validate_number(argv[1])==FAILURE)
    {
        printf("Error: Invalid first operand\n");
        return FAILURE;
    }

    if(validate_operator(argv[2])==FAILURE)
    {
        printf("Error: Invalid operator\n");
        return FAILURE;
    }

    if(validate_number(argv[3])==FAILURE)
    {
        printf("Error: Invalid second operand\n");
        return FAILURE;
    }

    return SUCCESS;
}

void insert_last(Node **head,Node **tail,int data)
{
    Node *new=malloc(sizeof(Node));

    if(new==NULL)
        return;

    new->data=data;
    new->prev=*tail;
    new->next=NULL;

    if(*head==NULL)
    {
        *head=new;
        *tail=new;
    }
    else
    {
        (*tail)->next=new;
        *tail=new;
    }
}

void insert_first(Node **head,Node **tail,int data)
{
    Node *new=malloc(sizeof(Node));

    if(new==NULL)
        return;

    new->data=data;
    new->prev=NULL;
    new->next=*head;

    if(*head==NULL)
    {
        *head=new;
        *tail=new;
    }
    else
    {
        (*head)->prev=new;
        *head=new;
    }
}

void store_number(char *str,Node **head,Node **tail)
{
    int i;

    for(i=0;str[i]!='\0';i++)
    {
        insert_last(head,tail,str[i]-'0');
    }
}

void addition(Node *tail1,Node *tail2,Node **head_res,Node **tail_res)
{
    Node *temp1=tail1;
    Node *temp2=tail2;

    int sum,carry=0;

    while(temp1!=NULL && temp2!=NULL)
    {
        sum=temp1->data+temp2->data+carry;

        if(sum>9)
        {
            carry=1;
            insert_first(head_res,tail_res,sum%10);
        }
        else
        {
            carry=0;
            insert_first(head_res,tail_res,sum);
        }

        temp1=temp1->prev;
        temp2=temp2->prev;
    }

    while(temp1!=NULL)
    {
        sum=temp1->data+carry;

        if(sum>9)
        {
            carry=1;
            insert_first(head_res,tail_res,sum%10);
        }
        else
        {
            carry=0;
            insert_first(head_res,tail_res,sum);
        }

        temp1=temp1->prev;
    }

    while(temp2!=NULL)
    {
        sum=temp2->data+carry;

        if(sum>9)
        {
            carry=1;
            insert_first(head_res,tail_res,sum%10);
        }
        else
        {
            carry=0;
            insert_first(head_res,tail_res,sum);
        }

        temp2=temp2->prev;
    }

    if(carry==1)
        insert_first(head_res,tail_res,carry);
}

void free_list(Node **head,Node **tail)
{
    while(*head!=NULL)
    {
        Node *temp=*head;

        *head=(*head)->next;

        if(*head==NULL)
            *tail=NULL;
        else
            (*head)->prev=NULL;

        free(temp);
    }
}


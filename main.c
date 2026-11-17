#include "apc.h"

int main(int argc,char *argv[])
{
    Node *head1=NULL,*tail1=NULL;
    Node *head2=NULL,*tail2=NULL;
    Node *head_res=NULL,*tail_res=NULL;
    int sign=1;

    if(validate_cla(argc,argv)==FAILURE)
    {
        printf("Error-> Validation failed for command line\n");
        return FAILURE;
    }

    store_number(argv[1],&head1,&tail1);
    store_number(argv[3],&head2,&tail2);

    switch(argv[2][0])
    {
        case '+':
            addition(tail1,tail2,&head_res,&tail_res);
            break;

        /* case '-':
            subtraction(head1,tail1,head2,tail2,
                        &head_res,&tail_res,&sign);
            break;
        */
    }

    printf("Result: ");

    Node *temp=head_res;

    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }

    printf("\n");
    free_list(&head1,&tail1);
    free_list(&head2,&tail2);
    free_list(&head_res,&tail_res);
    /* Print result and free lists */
}
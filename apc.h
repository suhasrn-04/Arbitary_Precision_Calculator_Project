#ifndef APC_H
#define APC_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum
{
    FAILURE,
    SUCCESS
} Status;

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} Node;

/* Validation functions */
Status validate_cla(int argc, char *argv[]);
Status validate_number(char *str);
Status validate_operator(char *str);

/* Linked list functions */

void insert_last(Node **head, Node **tail, int data);
void insert_first(Node **head, Node **tail, int data);
//void delete_first(Node **head, Node **tail);
//void remove_leading_zeros(Node **head, Node **tail);
void free_list(Node **head, Node **tail);

/* Operand functions */

void store_number(char *str, Node **head, Node **tail);
//int compare_numbers(Node *tail1, Node *tail2);

/* Arithmetic functions */

void addition(Node *tail1, Node *tail2, Node **head_res, Node **tail_res);

//void subtraction(Node *head1, Node *tail1, Node *head2, Node *tail2, Node **head_res, Node **tail_res);

#endif
//
//  linkedlist.h
//  votersBlock
//
//  Created by Maaz Adil on 7/31/21.
//

#ifndef linkedlist_h
#define linkedlist_h

#include <stdio.h>
#include <stdlib.h>
#include "block.h"

typedef struct
{
    block_t info;
} DATA;

typedef struct node
{
    DATA data;
    struct node* next;
} NODE;

void init(NODE **head);
NODE* add(NODE *node, DATA data);
void add_at(NODE *node, DATA data);
void print_list(NODE *head);
void print_winner();
NODE *reverse(NODE *node);
void get_list_transaction(NODE *head, unsigned char *list_transcations);


#endif /* linkedlist_h */

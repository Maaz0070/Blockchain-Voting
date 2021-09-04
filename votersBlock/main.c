//
//  main.c
//  votersBlock
//
//  Created by Maaz Adil on 7/31/21.
//

#include <stdio.h>
#include <stdio.h>
#include <search.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "block.h"
#include "linkedlist.h"

//#define NVOTES 2

// With extern keyword we declare a global varibale without any memory assigned to it. Can be used accros C files
extern hash string_hash(void *string);

//With typedef we are able to create an additional name for the enum party_code_t data type without creating a new type.
typedef enum party_code_t {GOOD_PARTY, MEDIOCRE_PARTY, EVIL_PARTY, MAX_PARTIES} party_code;
char *party_name[MAX_PARTIES] = {"GOOD PARTY", "MEDIOCRE_PARTY", "EVIL_PARTY"};

//Static allows us to define a function which can be called even when an object of the class is not initialized
//generates random vote
static party_code get_vote()
{
    int r = rand();
    //returns the random int and if it is over the max number of votes it will return the remainder
    return r%MAX_PARTIES;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    srand(time(NULL));
    
    NODE *head;
    DATA genesis_element;
    init(&head);
    
    printf("Welcome to BitCentral!\n");
    printf("\n");
    printf("Vote with confidence!\n");
    
    int NVOTES = 0;
    printf("Please enter number of votes to be casted: ");
    scanf("%d", &NVOTES);
    NVOTES -= 1;
    
    //First block is created manually with hash = 0
    transaction genesis_transactions = {party_name[get_vote()]};
    block_t genesis_block = {0, string_hash(genesis_transactions), genesis_transactions};
    genesis_element.info = genesis_block;
    head = add(head, genesis_element);
    
    //Now, were going to submit n random votes
    int i, previous_hash = genesis_element.info.previous_block_hash;
    transaction trans_list = (transaction) malloc(NVOTES *sizeof(char)*10);
    
   
    
    for(i = 0; i < NVOTES; i++)
    {
        DATA *el = malloc(sizeof(DATA));
        block_t *b = malloc(sizeof(block_t));
        
        transaction t = {party_name[get_vote()]};
        strcat(trans_list, t);
        b->previous_block_hash = previous_hash;
        b->block_hash = string_hash(trans_list);
        b->transactions = t;
        el->info = *b;
        previous_hash = b->block_hash;
        head = add(head, *el);
    }
    
    
    print_list(head);
    print_winner();
    
    
    return 0;
}

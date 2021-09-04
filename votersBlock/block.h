//
//  block.h
//  votersBlock
//
//  Created by Maaz Adil on 7/31/21.
//

#ifndef block_h
#define block_h

//represent ints with hash keywword
typedef int hash;
//represents char pointers with transaction keyword
typedef char *transaction;

typedef struct Block_T
{
    hash previous_block_hash;
    hash block_hash;
    transaction transactions;
}block_t;

#endif /* block_h */

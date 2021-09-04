//
//  hash.c
//  votersBlock
//
//  Created by Maaz Adil on 7/31/21.
//
#include <stdio.h>
#include <ctype.h>

/*
 Generates a hash key from each string
 @param string - the string of interest
 @return - a hash key for the string
 */
int string_hash(void *string)
{
    //djb2 string hash function
    int result = 0;
    printf("Please enter a 4 digit reference number for the vote in the blockchain: ");
    scanf("%d", &result);
    while(result < 1000 || result > 9999)
    {
        printf("Please enter only 4 digits: ");
        scanf("%d", &result);
    }
    //int result = 5381;
    unsigned char *p;
    
  //  convert string to unsigned char pointer
    p = (unsigned char *) string;
    
    while(*p != '\0')
    {
        //shift the result value left by 5 bits and increment result by each value in p
        result = (result << 5) + result + *p;
        ++p;
    }
    
    return result;
}

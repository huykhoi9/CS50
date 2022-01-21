// Implements a dictionary's functionality

#include <stdio.h>
#include <stdbool.h>
#include "dictionary.h"
#include <stdlib.h>
#include <stdint.h>
#include <strings.h>
#include <string.h>
#include <stddef.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 700;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // DID ON MY OWN
    int hash_position =  hash(word);
    node *cursor = table[hash_position];

    //looking for word
    while(cursor != NULL){
        if(strcasecmp(cursor->word,word) == 0){
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // DID ON MY OWN
    //char * is a string so word[0] is the first letter
    char *alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < 26; i++){
        if (word[1] == '\0' ){
            if (strcasecmp(&word[0],&alphabet[i]) == 0){
                return 26 * i;
            }
        }
        int sum = 0;
        for (int j = 0; j < 26; j++){
            if (strcasecmp(&word[0],&alphabet[i]) == 0){
                sum = 26 * i;
            }
            if (strcasecmp(&word[1],&alphabet[j]) == 0){
                return sum + j;
            }
        }
    }

    if (word[0] == '\''){
        return 677;
    }
    return 0;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //DID ON MY OWN EXCEPT the condition of while loop
    FILE *pt = fopen(dictionary,"r");
    if (pt == NULL){
        return false;
    }

    char new_word[LENGTH + 1];

    //fread returns a size_t representing the number of elements read successfully(0), fscanf return the value of the new_word(EOF)
    while (fscanf(pt, "%s", new_word) != EOF){              //LOOP until the file reaches EOF, fscanf returns integer, 

        //Create new node
        node *n = malloc(sizeof(node));

        if (n == NULL){
            return false;
        }

        //copy word from dictionary to hash
        strcpy(n->word, new_word);
        n->next = NULL;
        int h = hash(n->word);

        //insert node into hash table
        // if hashtable is empty at index, insert
        if (table[h] == NULL){
            table[h] = n;
            n->next = NULL;
        }
        else{
        n->next = table[h];
        table[h] = n;
        }
    }
    fclose(pt);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    //DID ON MY OWN
    int count = 0;
    //using loop to read all the elements in the hash table
    for (int i = 0; i <= N; i++){
        for(node *tmp = table[i]; tmp != NULL; tmp = tmp->next ){
            count ++;
        }
    }
    if (count > 0){
        return count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    //USE HINTS FROM INTERNET
    for (int i = 0; i <= N; i++){
        node *cursor = table[i];

        while (cursor != NULL){
        node *tmp = cursor;                         // If write node *tmp = table[i] then later free(tmp) then there's no point
        cursor = cursor->next;
        free(tmp);
        }
        if (cursor == NULL && i == N)               // USE to return the true value, if don't use always return false not good
            {
                return true;
            }
    }

    return false;
}

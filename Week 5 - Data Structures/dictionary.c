// Implements a dictionary's functionality
// Many thanks to the author below for illustrating hash list implementation in C
// https://medium.com/codex/hash-tables-with-singly-linked-lists-in-c-efc3c0166065

#include <stdio.h>
#include <stdbool.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 10000;

// Hash table
node *table[N];
int dict_size = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hash_value = hash(word);
    node* tmp1 = table[hash_value];
    if (tmp1 != NULL)
    {
        while (tmp1 != NULL)
        {
            if (strcasecmp(tmp1->word, word) == 0)
            {
                return true;
            }
            else
            {
                tmp1 = tmp1->next;
            }
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    long hash_value = 0;
    for(int i = 0; word[i] != '\0'; i++)
    {
        hash_value += tolower(word[i]);
    }
    return hash_value % N;
    // TODO: Improve this hash function
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *dict_pointer = fopen(dictionary, "r");
    if (dict_pointer == NULL)
    {
        return false;
    }
    else
    {
        char buffer[LENGTH + 1];
         while (fscanf(dict_pointer, "%s", buffer) != EOF)
        {
            node *n = malloc(sizeof(node));
            if (n==NULL)
            {
                return false;
            }
            strcpy(n->word, buffer);
            n->next = NULL;
            int index = hash(buffer);
            n->next = table[index];
            table[index] = n;
            dict_size += 1;
        }
    }
    fclose(dict_pointer);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return dict_size;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {

        while(table[i] != NULL)
        {
            node *tmp1 = table[i];
            table[i] = table[i]->next;
            free(tmp1);
        }
        if (i == (N - 1) && table[i] == NULL)
        {
            return true;
        }
    }
return false;
}

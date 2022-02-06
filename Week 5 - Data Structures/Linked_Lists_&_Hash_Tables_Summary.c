#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    // Single Linked Lists
    typedef struct node
    {
        int number;
        struct node* next;
    }
    node;
    
    // creating the head
    
    node* head = NULL;
    
    // creating the first node
    
    node* n = malloc(sizeof(node));
    //check if n is NULL
    if (n == NULL)
    {
        return 1;
    }
    n-> number = 1;
    n-> next = NULL;
    
    //Link head to first
    head = n;
    
    //adding second node, reuse n
    
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n-> number = 2;
    n-> next = NULL;
    
    head->next = n;
    
    
    //adding node to beginning
    n = malloc(sizeof(node));
    n->number = 8;
    n->next = head;
    head = n;
    
    //printing linked lists
    for (node* tmp = head; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n",tmp->number);
    }

    
    
    //freeing linked list
    
    while (head != NULL)
    {
        node* tmp1 = head;
        head = head->next; //ensure subject(head in this case) is in while loop condition so as to traverse the list
        free(tmp1);
    }
    
    //creating hash table, hash tables are essentially arrays of linked lists with buckets representing each head of the list.
    
    int N = 10000; //bucket size
    node* hash_table[N];
    
    //head of first bucket
    node *head1 = hash_table[0];
    
    //hash values to be obtained through hash functions
    int hash_value = 1;
    
    //same steps apply to add node to beginning of linked list of a bucket
    // Create a new node 
    //node*n = malloc...;
    
    // Make the new node point to the node that head points to 
    //n->next = hash_table[hash_value];
    
    // Make head point to our new node 
    //hash_table[hash_value] = n;
    
    //to free hash tables
    
    bool clear = false;
    for (int i = 0; i < N; i++)
    {
        //loop through each head bucket afetrwards it is similar to freeing linked list 
        while (hash_table[i] != NULL)
        {
            node* tmp = hash_table[i];
            hash_table[i] = hash_table[i]->next;
            free(tmp);
        }
        //to check and return a value if all heads cleared
        if (i == N - 1 && hash_table[i] == NULL )
        {
            clear = true;
        }
        
    }

    
    return 0;
}

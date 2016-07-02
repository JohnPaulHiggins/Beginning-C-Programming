/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "dictionary.h"

int count = 0;

void free_nodes(node* ptr);

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    node* current = root;
    
    for (int i = 0, j = strlen(word); i < j; i++)
    {
        if (isalpha(word[i]))
        {
            int k = tolower(word[i]);
            k = k % 97;
            
            if (current->children[k] == NULL)
            {
                return false;
            }
            
            current = current->children[k];
        }
        
        if (word[i] == '\'')
        {
            if (current->children[26] == NULL)
            {
                return false;
            }
            
            current = current->children[26];
        }
    }
    
    if (current->is_word == true)
    {
        return true;
    }
    
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    
    //Open dictionary file
    char dict[18];
    sprintf(dict, "%s", dictionary);
    
    FILE* file = fopen(dict, "r");
    
    if (file == NULL)
    {
        return false;
    }
    
    //Build root node
    root = malloc(sizeof(node));
    if (root == NULL)
    {
        return false;
    }
    
    node* current = root;
    
    int c;
    
    while(1)
    {
        c = fgetc(file);
        
        if (isalpha(c))
        {
            //Insert into trie
            int i = c % 97;
            if (current->children[i] == NULL)
            {
                //New node
                current->children[i] = malloc(sizeof(node));
            }
            //Move along to next node
            current = current->children[i];
        }
        
        if (c == '\'')
        {
            //Insert into trie
            if (current->children[26] == NULL)
            {
                //New node
                current->children[26] = malloc(sizeof(node));
            }
            //Move along to next node
            current = current->children[26];
        }
        
        if (c == '\n')
        {
            //Word is done
            current->is_word = true;
            current = root;
            count++;
        }
        
        if (feof(file))
        {
            break;
        }
    }
    
    fclose(file);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return count;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    free_nodes(root);
    return true;
}

//Concept for this came from Stackexchange

void free_nodes(node* ptr)
{
    if (!ptr)
    {
        return;
    }
    
    for (int i = 0; i < 27; i++)
    {
        free_nodes(ptr->children[i]);
    }
    
    free(ptr);
}
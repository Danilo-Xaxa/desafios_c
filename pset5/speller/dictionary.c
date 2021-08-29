// Implements a dictionary's functionality
#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>


#include "dictionary.h"


int palavras_total = 0;


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;


// Number of buckets in hash table
const unsigned int N = (122 * (LENGTH + 1));


// Hash table
node *table[N];


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int indice = hash(word);

    node *cursor = table[indice];

    while(NULL != cursor)
    {
        if (0 == strcasecmp(cursor->word, word))
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}


// Hashes word to a number
unsigned int hash(const char *word)
{
    int soma = 0;

    for (int k = 0; k < strlen(word); k++)
    {
        soma += tolower(word[k]);
    }

    if (0 < soma)
    {
        return (soma % N);
    }

    return 0;
}


// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    int verificador = 0;

    FILE *arquivo = fopen(dictionary, "r");
    if (arquivo == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];

    while(EOF != fscanf(arquivo, "%s", word))
    {
        node *node_atual = malloc(sizeof(node));

        if (NULL == node_atual)
        {
            return false;
        }

        strcpy(node_atual->word, word);

        node_atual->next = NULL;

        int indice = hash(word);

        if (table[indice] == NULL)
        {
            table[indice] = node_atual;
        }

        else
        {
            node_atual->next = table[indice];
            table[indice] = node_atual;
        }

        palavras_total++;
        verificador++;
    }

    fclose(arquivo);
    return true;

    if (verificador == 0)
    {
        return false;
    }

}


// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (palavras_total != 0)
    {
        return palavras_total;
    }
    else
    {
        return 0;
    }
}


// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    int flag = 0;

    for (int o = 0; o < N; o++)
    {
        node *head = table[o];
        node *cursor = head;
        node *temp = head;

        while (NULL != cursor)
        {
            cursor = cursor->next;
            free(temp);
            temp = cursor;
        }

        flag++;
    }

    if (flag == N)
    {
        return true;
    }

    return false;
}

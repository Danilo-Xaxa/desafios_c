#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// My own variables (in portuguese)
int maior = 0;
string vencedor;
bool mais_vencedores = false;
string outros_vencedores[MAX];
int cont_outros_vencedores = 0;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes += 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // criando a lista com todas a qtd de votos de todos os candidatos
    int lista_votos[candidate_count];
    for (int i = 0; i < candidate_count; i++)
    {
        lista_votos[i] = candidates[i].votes;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (lista_votos[i] > maior) // pegando a maior qtd de votos e o nome do vencedor
        {
            maior = lista_votos[i];
            vencedor = candidates[i].name;
        }
        else if (lista_votos[i] == maior) // pegando os outros vencedores
        {
            mais_vencedores = true;
            outros_vencedores[cont_outros_vencedores] = candidates[i].name;
            cont_outros_vencedores++;
        }
    }

    printf("%s\n", vencedor); // printando o vencedor

    if (mais_vencedores)
    {
        for (int i = 0; i < cont_outros_vencedores; i++)
        {
            printf("%s\n", outros_vencedores[i]); // printando os outros vencedores
        }
    }

    return;
}

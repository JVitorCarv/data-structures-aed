#include <stdio.h>
#include <stdlib.h>

// Example 1

struct Node
{
    int valor;
    struct Node *prox;
};
typedef struct Node Node;

// Example 2

struct package
{
    int id;
    struct package *prox;
};
typedef struct package Package;

// Initializes empty list
Package *init()
{
    return NULL;
}

// Inserting always on the first position
void inserir(Node *node, int valor)
{
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    newNode->valor = valor;
    newNode->prox = node;
}

// Inserting on the last position
Package *insert(Package *p, int id)
{
    Package *novo = (Package *)malloc(sizeof(Package));
    novo->id = id;
    novo->prox = NULL;

    if (p == NULL)
    {
        return novo;
    }
    else
    {
        Package *i = p;
        while (i->prox != NULL)
        {
            i = i->prox;
        }
        i->prox = novo;
    }
    return p;
}

int buscar(Node *node, int valor)
{
    // Caso chegue ao final da lista, retorna null
    if (node == NULL)
    {
        return 0;
    }
    // Caso ache o valor procurado
    if (node->valor == valor)
    {
        return 1;
    }
    // Caso nenhum desses dois seja satisfeito, passa para o próximo valor
    return buscar(node->prox, valor);
}

int main()
{
    // Example 1
    Node *a;
    Node *b;

    a = (Node *)malloc(sizeof(Node));
    b = (Node *)malloc(sizeof(Node));

    a->valor = 3;
    b->valor = 5;
    a->prox = b;
    b->prox = NULL;
    printf("%d ", a->valor);
    printf("%d ", a->prox->valor);

    // Example 2
    Package *p = init();
    p = insert(p, 19);
    p = insert(p, 9);
    p = insert(p, 100);

    printf("\nPackages: ");
    for (Package *i = p; i != NULL; i = i->prox)
    {
        printf("%d ", i->id);
    }

    return 0;
}
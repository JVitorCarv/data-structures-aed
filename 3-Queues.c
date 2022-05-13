#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int valor;
    struct Node *prox;
};
typedef struct Node Node;

struct fila
{
    Node *head;
    Node *tail;
};
typedef struct fila Fila;

int main()
{

    return 0;
}
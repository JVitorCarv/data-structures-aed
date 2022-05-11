#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number;
    struct node *prox;
};
typedef struct node Node;

int main()
{
    // Example 1
    int *numbers;
    int size = 4;

    numbers = (int *)malloc(size * sizeof(int));

    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;

    for (int i = 0; i < size; i++)
    {
        printf("Array[%d] = %d\n", i, numbers[i]);
    }
    free(numbers);

    // Example 2
    Node *node = NULL;

    for (int i = 0; i < size; i++)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->number = i;
        newNode->prox = node;
        node = newNode;
    }

    Node *i;
    for (i = node; i != NULL; i = i->prox)
    {
        printf("node[%d]->number == %d\n", i, i->number);
    }
    free(node);

    return 0;

    // In case there is no memory left, malloc will return NULL
    /*
        v = (float*) malloc(n*sizeof(float));
        if (v==NULL)
        {
            printf("Memoria insuficiente.\n”);
            return 1;
        }
        free(v);
    */
}
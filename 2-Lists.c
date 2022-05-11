#include <stdio.h>
#include <stdlib.h>

// Example 1
struct Node
{
    int value;
    struct Node *next;
};
typedef struct Node Node;

// Example 2
struct package
{
    int id;
    struct package *next;
};
typedef struct package Package;

// Initializes empty list
Package *init()
{
    return NULL;
}

// Inserting always on the first position
void first_insert(Node *node, int value)
{
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = node;
}

// Inserting on the last position
Package *insert(Package *p, int id)
{
    Package *new_package = (Package *)malloc(sizeof(Package));
    new_package->id = id;
    new_package->next = NULL;

    // In case the list is empty, inserts it already
    if (p == NULL)
    {
        return new_package;
    }
    else
    {
        Package *i = p;
        // Iterates to last position
        while (i->next != NULL)
        {
            i = i->next;
        }
        // Insertion
        i->next = new_package;
    }
    return p;
}

Package *search(Package *node, int id)
{
    // This represents that the entire list was searched
    if (node == NULL)
    {
        printf("Id %d was not found\n", id);
        return NULL;
    }

    // Returns the node if found
    if (node->id == id)
    {
        printf("Value %d was found\n", node->id);
        return node;
    }

    // Else, search calls itself and checks the next node
    return search(node->next, id);
}

Package *delete (Package *node, int id)
{
    // In case all of the list was searched and element was not found
    if (node->next == NULL)
    {
        printf("Value was not found\n");
        return NULL;
    }

    if (node->next->id == id)
    {
        Package *trash;
        trash = node->next; // stores position in aux variable
        node->next = trash->next;
        free(trash);
        printf("Value was deleted successfully\n");
        return node;
    }
    return delete (node->next, id);
}

int main()
{
    // Example 1
    Node *a;
    Node *b;

    a = (Node *)malloc(sizeof(Node));
    b = (Node *)malloc(sizeof(Node));

    a->value = 3;
    b->value = 5;
    a->next = b;
    b->next = NULL;
    printf("%d ", a->value);
    printf("%d ", a->next->value);

    // Example 2
    Package *p = init();
    p = insert(p, 19);
    p = insert(p, 9);
    p = insert(p, 100);

    // Prints the entire list
    printf("\nPackages: ");
    for (Package *i = p; i != NULL; i = i->next)
    {
        printf("%d ", i->id);
    }
    printf("\n");

    // Search for an element inside the list
    Package *search_num;

    search_num = search(p, 9);
    search_num = search(p, 3);

    // Remove element from linked list
    Package *delete_result;
    delete_result = delete (p, 9);
    delete_result = delete (p, 42);

    // Print
    printf("\nPackages: ");
    for (Package *i = p; i != NULL; i = i->next)
    {
        printf("%d ", i->id);
    }
    printf("\n");

    return 0;
}
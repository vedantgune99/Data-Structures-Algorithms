#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *leftChild, *rightChild;
} node;

// Function Prototypes --->
node *insert(node *root, int x);
void inorder(node *root);

int main()
{
    node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 5);
    printf("Successfully Inserted!\n\n");
    inorder(root);

    return 0;
}

node *insert(node *root, int x)
{
    node *new, *current;
    new = (node *)malloc(sizeof(node));
    new->data = x;
    new->leftChild = new->rightChild = NULL;
    if (root == NULL)
    {
        root = new;
        root->leftChild = root->rightChild = NULL;
        return root;
    }

    if (x <= root->data)
        root->leftChild = insert(root->leftChild, x);
    else
        root->rightChild = insert(root->rightChild, x);

    return root;
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->leftChild);
        printf(" %d ", root->data);
        inorder(root->rightChild);
    }
}
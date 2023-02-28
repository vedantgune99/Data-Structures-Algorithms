#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next, *prev;
} node;

// Function Prototypes --->
node *append(node *head, int x);
node *appendLeft(node *head, int x);
node *insert(node *head, int x, int position);
node *pop(node *head);
node *popLeft(node *head);
node *rm(node *head, int position);
node *remove_all(node *head);
void display(node *head);

int main()
{
    int choice, position, x;
    node *head;
    head = NULL;

    do
    {
        printf("\n\n***** MENU *****\n");
        printf("\n1) Append Operation      : ");
        printf("\n2) Append Left Operation : ");
        printf("\n3) Insert Operation      : ");
        printf("\n4) Pop Operation         : ");
        printf("\n5) Pop Left Operation    : ");
        printf("\n6) Remove Operation      : ");
        printf("\n7) Remove All Operation  : ");
        printf("\n8) Display Linked List   : ");
        printf("\n9) Exit                  : ");
        printf("\n____________________________");
        printf("\n~ Select an option       : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n>>> Enter data : ");
            scanf("%d", &x);
            head = append(head, x);
            break;
        case 2:
            printf("\n>>> Enter data : ");
            scanf("%d", &x);
            head = appendLeft(head, x);
            break;

        case 3:
            printf("\n>>> Enter data : ");
            scanf("%d", &x);
            printf("\n>>> Enter pos : ");
            scanf("%d", &position);
            head = insert(head, x, position);
            break;

        case 4:
            if (head == NULL)
                printf("\n>>>Empty linked list!");

            else
                head = pop(head);
            break;

        case 5:
            if (head == NULL)
                printf("\n>>>Empty linked list!");

            else
                head = popLeft(head);

            break;

        case 6:
            if (head == NULL)
                printf("\n>>>Empty linked list!");

            else
            {
                printf("\n>>> Enter pos : ");
                scanf("%d", &position);
                head = rm(head, position);
            }
            break;

        case 7:
            if (head == NULL)
                printf("\n>>>Empty linked list!");

            else
                head = remove_all(head);

            break;

        case 8:
            if (head == NULL)
                printf("\n>>>Empty linked list!");

            else
            {
                printf("\n>>> Linked List ----> \n");
                display(head);
            }
            break;

        case 9:
            exit(0);
            break;

        default:
            printf("\n>>>Please select valid option!");
        }
    } while (choice != 9);

    return 0;
}

// Function Prototypes --->
node *append(node *head, int x)
{
    node *p, *q;
    p = (node *)malloc(sizeof(node));
    p->data = x;
    if (head == NULL)
    {
        head = p;
        p->next = p->prev = head;
        return head;
    }
    q = head;
    q = q->prev;

    q->next = p;
    p->prev = q;
    p->next = head;
    head->prev = p;
    return head;
}

node *appendLeft(node *head, int x)
{
    node *p, *q;
    p = (node *)malloc(sizeof(node));
    p->data = x;
    if (head == NULL)
    {
        p->next = p->prev = head;
        head = p;
        return head;
    }

    q = head;
    q = q->prev;

    q->next = p;
    p->prev = q;
    p->next = head;
    head->prev = p;
    head = p;
    return p;
}

node *insert(node *head, int x, int position)
{
    node *p, *q;
    p = (node *)malloc(sizeof(node));
    p->data = x;
    if (head == NULL)
    {
        head = p;
        p->next = p->prev = head;
        return head;
    }

    q = head;
    int i = 1;
    while (i++ < position)
        q = q->next;

    p->next = q->next;
    q->next->prev = p;
    q->next = p;
    p->prev = q;
    return head;
}

node *pop(node *head)
{
    node *p, *q;
    p = q = head;
    while (q->next != head)
        q = q->next;

    while (p->next != q)
        p = p->next;

    p->next = head;
    head->prev = p;
    printf("\n>>>%d was removed!", q->data);
    free(q);
    return head;
}

node *popLeft(node *head)
{
    node *p, *q;
    p = q = head;
    while (p->next != head)
        p = p->next;

    head = head->next;
    p->next = head;
    head->prev = p;
    printf("\n>>>%d was removed!", q->data);
    free(q);
    return head;
}

node *rm(node *head, int position)
{
    node *p, *q;
    p = q = head;
    int i = 1;
    while (i++ < position)
        p = p->next;

    q = p->next;
    p->next = q->next;
    q->next->prev = p;
    printf("\n>>>%d was removed!", q->data);
    free(q);
    return head;
}

node *remove_all(node *head)
{
    node *p, *q;
    p = q = head;
    do
    {
        p = p->prev;
        q = p;
        printf("\n Deleting %d...", q->data);
        free(q);
    } while (p != head);
    head = NULL;
    printf("\n>>>Removed all nodes!");
    return head;
}

void display(node *head)
{
    node *p;
    p = head;
    printf("\n>>>Forward Traversal --->");
    do
    {
        printf("%d -> ", p->data);
        p = p->next;
    } while (p != head);

    printf("\n>>>Backward Traversal --->");
    p = head->prev;
    do
    {
        printf("%d -> ", p->data);
        p = p->prev;
    } while (p != head->prev);
}
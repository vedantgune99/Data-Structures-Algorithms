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
int findElement(node *head, int x);
void display(node *head);
void for_back_trav(node *head);

int main()
{
    node *head;
    int choice, x, position;

    head = NULL;
    do
    {
        printf("\n\n***** MENU *****");
        printf("\n1)  AppendRight Elements        : ");
        printf("\n2)  AppendLeft Elements         : ");
        printf("\n3)  Insert Elements             : ");
        printf("\n4)  PopRight Operation          : ");
        printf("\n5)  PopLeft Operation           : ");
        printf("\n6)  Remove Elements             : ");
        printf("\n7)  Remove All Nodes            : ");
        printf("\n8)  Find Element                : ");
        printf("\n9)  Display Linked List         : ");
        printf("\n10) Forward-Backward Traversal  : ");
        printf("\n11) Exit Program                : ");
        printf("\n__________________________________");
        printf("\n~ Select your choice            : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n>>>Enter data : ");
            scanf("%d", &x);
            head = append(head, x);
            break;

        case 2:
            printf("\n>>>Enter data : ");
            scanf("%d", &x);
            head = appendLeft(head, x);
            break;

        case 3:
            printf("\n>>>Enter data : ");
            scanf("%d", &x);
            printf("\n>>>Enter position : ");
            scanf("%d", &position);
            head = insert(head, x, position);
            break;

        case 4:
            head = pop(head);
            break;

        case 5:
            head = popLeft(head);
            break;

        case 6:
            printf("\n>>>Enter pos : ");
            scanf("%d", &position);
            head = rm(head, position);
            break;

        case 7:
            head = remove_all(head);
            printf("\n>>>Removed All Nodes...");
            break;

        case 8:
            printf("\n>>>Enter data : ");
            scanf("%d", &x);
            int res = findElement(head, x);
            if (res < 0)
                printf("\n>>>Element not found!");
            else
                printf("\n>>>Element found at %d!", res);
            break;

        case 9:
            printf("\n>>>Linked List -->\n");
            display(head);
            break;

        case 10:
            printf("\n>>>Both Way Traversal -->\n");
            for_back_trav(head);
            break;

        case 11:
            exit(0);
            break;

        default:
            printf("\n>>>Please enter a valid option!");
        }
    } while (choice != 11);

    return 0;
}

// Function Definitions --->

node *append(node *head, int x)
{
    node *p, *q;
    p = (node *)malloc(sizeof(node));
    p->data = x;
    p->next = p->prev = NULL;
    if (head == NULL)
        head = p;

    else
    {
        q = head;
        while (q->next != NULL)
            q = q->next;
        q->next = p;
        p->prev = q;
    }
    return head;
}

node *appendLeft(node *head, int x)
{
    node *p;
    p = (node *)malloc(sizeof(node));
    p->data = x;
    p->next = p->prev = NULL;
    if (head == NULL)
        head = p;
    else
    {
        p->next = head;
        head->prev = p;
        head = p;
    }
    return head;
}

node *insert(node *head, int x, int position)
{
    node *p, *q;
    int i = 1;
    p = (node *)malloc(sizeof(node));
    p->data = x;
    p->next = p->prev = NULL;
    if (head == NULL)
        head = p;

    else
    {
        q = head;
        while (i <= position)
        {
            q = q->next;
            i++;
        }

        p->next = q->next;
        q->next->prev = p;
        q->next = p;
        p->prev = q;
    }
    return head;
}

node *pop(node *head)
{
    node *p, *q;
    p = q = head;
    while (p->next != NULL)
        p = p->next;
    while (q->next != p)
        q = q->next;

    q->next = NULL;

    printf("\n>>>%d was removed!", p->data);
    free(p);
    return head;
}

node *popLeft(node *head)
{
    node *p;
    p = head;
    head = head->next;
    head->prev = NULL;
    printf("\n>>>%d was removed!", p->data);
    free(p);
    return head;
}

node *rm(node *head, int position)
{
    node *p, *q;
    p = q = head;
    int i = 1;
    while (i <= position)
    {
        q = q->next;
        i++;
    }

    while (p->next != q)
        p = p->next;

    p->next = q->next;
    q->next->prev = p;
    printf("\n>>>%d was removed!", p->data);
    free(q);
    return head;
}

int findElement(node *head, int x)
{
    node *p;
    p = head;
    int index = 0;
    while (p->next != NULL)
    {
        if (p->data == x)
            return index;
        p = p->next;
        index++;
    }
    return (-1);
}

void display(node *head)
{
    node *p;
    p = head;
    while (p != NULL)
    {
        printf(" %d <=> ", p->data);
        p = p->next;
    }
}

node *remove_all(node *head)
{
    node *p, *q;
    p = q = head;
    while (q != NULL)
    {
        q = q->next;
        head = q;
        free(p);
        p = head;
    }
    return head;
}

void for_back_trav(node *head)
{
    node *p, *q;
    p = q = head;
    printf("\nForward Traversal -----> ");
    while (q != NULL)
    {
        printf(" %d ->", q->data);
        p = q;
        q = q->next;
    }

    printf("\nBackward Traversal -----> ");
    while (p != NULL)
    {
        printf(" %d <-", p->data);
        p = p->prev;
    }
}
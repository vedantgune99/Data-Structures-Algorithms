#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct queue
{
    int data[MAX];
    int front, rear;
} queue;

// Functions on queue(Prototypes) --->
void initialize(queue *q);
void enqueue(queue *q, int x);
int dequeue(queue *q);
int search(queue *q, int x);
int isEmpty(queue *q);
int isFull(queue *q);
void display(queue *q);

int main()
{
    queue q;
    int x, choice;
    initialize(&q);

    do
    {
        printf("\n\n***** MENU *****");
        printf("\n 1) Enqueue Operation    : ");
        printf("\n 2) Dequeue Operation    : ");
        printf("\n 3) Search Operation     : ");
        printf("\n 4) Display Queue        : ");
        printf("\n 5) Exit Program         : ");
        printf("\n___________________________");
        printf("\n>>>Enter your choice     : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (isFull(&q))
                printf("\n>>>Queue Overflow !");

            else
            {
                printf(">>>Enter data : ");
                scanf("%d", &x);
                enqueue(&q, x);
                printf("\n>>>Data inserted!");
            }
            break;

        case 2:
            if (isEmpty(&q))
                printf("\n>>>Queue Underflow !");

            else
            {
                int x = dequeue(&q);
                printf("\n>>> %d was removed!", x);
            }
            break;

        case 3:
            if (isEmpty(&q))
                printf("\n>>> Queue Underflow !");

            else
            {
                printf(">>> Enter data : ");
                scanf("%d", &x);
                int res = search(&q, x);
                if (res == -1)
                    printf("\n>>> Element not found!");

                else
                {
                    printf("\n>>> Element found!");
                    printf("\n>>> Position : %d", res);
                }
            }
            break;

        case 4:
            if (isEmpty(&q))
                printf("\n>>>Queue Underflow!");
            else
                display(&q);

            break;

        case 5:
            exit(0);
            break;

        default:
            printf("\nPlease enter a valid choice!");
            break;
        }
    } while (choice != 5);

    return 0;
}

// Function Definitions --->
void initialize(queue *q)
{
    q->front = q->rear = -1;
}

void enqueue(queue *q, int x)
{
    if (isEmpty(q))
    {
        q->rear++;
        q->front++;
    }
    else
        q->rear++;

    q->data[q->rear] = x;
}

int dequeue(queue *q)
{
    int data = q->data[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return data;
}

int search(queue *q, int x)
{
    for (int i = q->front; i <= q->rear; i++)
    {
        if (q->data[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int isEmpty(queue *q)
{
    if ((q->front == -1) && (q->rear == -1))
        return 1;
    else
        return 0;
}

int isFull(queue *q)
{
    if (q->rear == MAX - 1)
        return 1;
    else
        return 0;
}

void display(queue *q)
{
    printf("\n |");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf(" %d ", q->data[i]);
        printf("|");
    }
}
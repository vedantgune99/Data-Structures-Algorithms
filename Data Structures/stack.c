#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct stack
{
    int data[MAX];
    int top;
} stack;

// Functions on stack (Prototypes) --->
void initialize(stack *s);
void push(stack *s, int x);
int pop(stack *s);
int isEmpty(stack *s);
int isFull(stack *s);
int peek(stack *s, int x);
void display(stack *s);

int main()
{
    stack s;
    int x, choice;
    initialize(&s);

    do
    {
        printf("\n\n***** MENU *****");
        printf("\n 1) Push Operation   : ");
        printf("\n 2) Pop Operation    : ");
        printf("\n 3) Peek Operation   : ");
        printf("\n 4) Display Stack    : ");
        printf("\n 5) Exit Program     : ");
        printf("\n_______________________");
        printf("\n>>>Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (isFull(&s))
                printf("\n>>> Stack Overflow !");

            else
            {
                printf(">>> Enter data : ");
                scanf("%d", &x);
                push(&s, x);
            }
            break;

        case 2:
            if (isEmpty(&s))
                printf("\n>>> Stack Underflow !");
            else
            {
                x = pop(&s);
                printf("\n>>> %d was removed!", x);
            }
            break;

        case 3:
            if (isEmpty(&s))
                printf("\n>>> Stack Underflow !");
            else
            {
                printf(">>> Enter data : ");
                scanf("%d", &x);
                int res = peek(&s, x);
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
            display(&s);
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
void initialize(stack *s)
{
    s->top = -1;
}

void push(stack *s, int x)
{
    s->top++;
    s->data[s->top] = x;
}

int pop(stack *s)
{
    int data = s->data[s->top];
    s->top--;
    return data;
}

int isEmpty(stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

int isFull(stack *s)
{
    if (s->top == (MAX - 1))
        return 1;
    else
        return 0;
}

int peek(stack *s, int x)
{
    for (int i = 0; i < MAX; i++)
    {
        if (s->data[i] == x)
            return i;
    }
    return (-1);
}

void display(stack *s)
{
    for (int i = 0; i <= (s->top); i++)
        printf(" %d \n", s->data[i]);
}
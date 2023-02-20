#include <stdio.h>
#define MAX 10

typedef struct stack
{
    int data[MAX];
    int top;
} stack;

// Functions on stack (Prototypes) --->
void push(stack *s, int x);
int pop(stack *s);
int isEmpty(stack *s);
int isFull(stack *s);
int peek(stack *s, int x);
void display(stack *s);

int main()
{
    stack s;
    s.top = -1;

    int emp = isEmpty(&s);
    printf("\nIs Empty : %d", emp);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);

    int ful = isFull(&s);
    printf("\nIsFull : %d", ful);

    display(&s);

    int x = pop(&s);
    printf("Element %d was removed!\n", x);
    int y = pop(&s);
    printf("Element %d was removed!\n", y);
    return 0;
}

// Function Definitions --->
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
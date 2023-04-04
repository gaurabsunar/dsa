#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int top, size;
    int *arr;
};

// isEmpty function
int isEmpty(struct stack *p)
{
    if (p->top <= -1)
    {
        return 1;
    }
    return 0;
}

// isFull function
int isFull(struct stack *p)
{
    if (p->top >= p->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *p, int data)
{
    if (isFull(p))
    {
        printf("Stack is Full\n");
    }
    else
    {
        p->top++;
        p->arr[p->top] = data;
        printf("%d pushed\n", data);
    }
}

void pop(struct stack *p)
{
    if (isEmpty(p))
    {
        printf("Stack is Empty\n");
    }
    else
    {
        int data = p->arr[p->top];
        p->top--;
        printf("%d is popped", data);
    }
}

void print(struct stack *p)
{
    for (int i = 0; i <= p->top; i++)
    {
        printf("Element %d\n", p->arr[i]);
    }
}

int main()
{
    struct stack *s;
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    push(s, 23);
    push(s, 20);
    push(s, 10);
    print(s);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int front, rear, max;
    int *arr;
};

// isEmpty function
int isEmpty(struct Queue *p)
{
    if (p->front > p->rear)
    {
        return 1;
    }
    return 0;
}

// isFull function
int isFull(struct Queue *p)
{
    if (p->rear >= p->max - 1)
    {
        return 1;
    }
    return 0;
}

// push function
void inQueue(struct Queue *p, int data)
{
    if (isFull(p))
    {
        printf("Queue is full\n");
    }
    else
    {
        p->rear++;
        p->arr[p->rear] = data;
        printf("%d inqueue\n", data);
    }
}

void deQueue(struct Queue *p)
{
    if (isEmpty(p))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        int data = p->arr[p->front];
        p->front++;
        printf("%d dequeue\n", data);
    }
}

void print(struct Queue *p)
{
    for (int i = p->front; i <= p->rear; i++)
    {
        printf("Element %d\n", p->arr[i]);
    }
}

int main()
{
    struct Queue *q;
    q->front = 0;
    q->rear = -1;
    q->max = 10;
    q->arr = (int *)malloc(q->max * sizeof(int));

    inQueue(q, 23);
    inQueue(q, 20);
    inQueue(q, 12);

    deQueue(q);

    print(q);

    return 0;
}
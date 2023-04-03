#include <stdio.h>
#include <stdlib.h>
struct cQueue
{
    int front, rear, max;
    int *arr;
};

int isEmpty(struct cQueue *p)
{
    if (p->front == p->rear)
    {
        return 1;
    }
    return 0;
}

int isFull(struct cQueue *p)
{
    if (p->front == (p->rear + 1) % p->max)
    {
        return 1;
    }
    return 0;
}

void inQueue(struct cQueue *p, int data)
{
    if (isFull(p))
    {
        printf("Circular queue is FUll\n");
    }
    else
    {
        p->rear = (p->rear + 1) % p->max;
        p->arr[p->rear] = data;
        printf("%d Inqueue\n", data);
    }
}

void deQueue(struct cQueue *p)
{
    if (isEmpty(p))
    {
        printf("Circular queue is empty\n");
    }
    else
    {
        p->front = (p->front + 1) % p->max;
        int data = p->arr[p->front];
        printf("%d dequeue\n", data);
    }
}

void print(struct cQueue *p)
{
    if (isEmpty(p))
    {
        printf("Circular queue is empty\n");
    }
    else
    {
        for (int i = (p->front + 1) % p->max; i <= p->rear; i = (i + 1) % p->max)
        {
            printf("Element %d\n", p->arr[i]);
        }
    }
}

int main()
{
    struct cQueue *q;
    q->max = 10;
    q->front = q->rear = q->max - 1;
    q->arr = (int *)malloc(q->max * sizeof(int));

    inQueue(q, 23);
    inQueue(q, 21);
    inQueue(q, 20);
    deQueue(q);
    print(q);
    return 0;
}
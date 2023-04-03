#include <stdio.h>
#include <stdlib.h>
struct AssendingPQueue
{
    int front, rear, max;
    int *arr;
};

// 1. isEmpty
// 2. isFull
// 3. insert
// 4. findMax
// 5. remove

// for isEmpty function
int isEmpty(struct AssendingPQueue *a)
{
    if (a->rear <= -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// isFull function
int isFull(struct AssendingPQueue *a)
{
    if (a->front >= a->max - 1)
    {
        return 1;
    }
    return 0;
}

// insert function
void Insert(struct AssendingPQueue *a, int data)
{
    if (isFull(a))
    {
        printf("Stack is FUll");
    }
    else
    {
        a->rear++;
        a->arr[a->rear] = data;
        printf("Data inserted success\n");
    }
}

// dequeue function
void Dequeue(struct AssendingPQueue *a)
{
    if (isEmpty(a))
    {
        printf("Stack is Empty");
    }
    else
    {
        int temp = 0, x;
        x = a->arr[a->front];
        for (int i = a->front + 1; i < a->rear; i++)
        {
            if (x > a->arr[i])
            {
                temp = i;
                x = a->arr[i];
            }
        }
        for (int i = temp; i <= a->rear - 1; i++)
        {
            a->arr[i] = a->arr[i + 1];
            a->rear--;
        }
        printf("\n%d is Dequeue\n", x);
    }
}

// Display Queue
void Display(struct AssendingPQueue *a)
{
    if (isEmpty(a))
    {
        printf("Satck is empty");
    }
    else
    {
        for (int i = a->front; i <= a->rear; i++)
        {
            printf("%d\t", a->arr[i]);
        }
    }
}

int main()
{
    struct AssendingPQueue *A;
    A->front = 0;
    A->rear = -1;
    A->max = 10;
    A->arr = (int *)malloc(A->max * sizeof(int));

    // Dequeue(A);
    Insert(A, 3);
    Insert(A, 4);
    Insert(A, 5);
    Insert(A, 2);
    Insert(A, 10);

    Display(A);
    Dequeue(A);
    Display(A);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
struct QNode
{
    int data;
    struct QNode *next;
};

typedef struct QNode qNode;

qNode *front = 0;
qNode *rear = 0;

// Enqueue operation
void Enqueue(int data)
{
    qNode *newNode = (qNode *)malloc(sizeof(qNode));
    if (rear == 0)
    {
        newNode->data = data;
        newNode->next = NULL;
        front = rear = newNode;
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;
        rear->next = newNode;
        rear = newNode;
    }
}

void Dequeue()
{
    qNode *temp;
    if (front == 0)
    {
        printf("Queue is Empty");
        return;
    }
    else if (front->next == NULL)
    {
        temp = front;
        front = rear = NULL;
        printf("%d is Dequeue\n", temp->data);
        free(temp);
    }
    else{
        temp = front;
        front = front->next;
        printf("%d is Dequeue\n", temp->data);
        free(temp);
    }
}

void display(){
    qNode *temp = front;
    while (temp != NULL)
    {
        printf("Element %d\n",temp->data);
        temp = temp->next;
    }
}

int main()
{   
    Enqueue(10);
    Enqueue(11);
    display();
    Dequeue();
    display();
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node sNode;
sNode *top = 0;

// push operation in Linked litst
void push(int data)
{
    sNode *newNode = (sNode *)malloc(sizeof(sNode));
    if (top == 0)
    {
        newNode->data = data;
        newNode->next = NULL;
        top = newNode;
    }
    else
    {
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }
}

// pop operation in Linked list
void pop(){
    if(top==0){
        printf("Stack is Empty");
        return;
    }
    else{
        sNode *temp = top;
        top = top->next;
        printf("%d popped\n", temp->data);
        free(temp);
    }
}


// print element in stack
void print()
{
    if (top == 0)
    {
        printf("Stack is Empty");
        return;
    }
    else
    {
        sNode *temp = top;
        while (temp != 0)
        {
            printf("Element %d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    push(23);
    push(20);
    pop();
    print();
    return 0;
}
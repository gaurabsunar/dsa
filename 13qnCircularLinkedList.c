#include<stdio.h>
#include<stdlib.h>
struct cNode    
{
    int data;
    struct cNode * next;
};

typedef struct cNode CNode;

// insert element at beginning
void insertBeg(CNode *head,  int data){
    CNode * newNode = (CNode*)malloc(sizeof(CNode));
    if(head==NULL){
        newNode->data = data;
        newNode->next = newNode;
        head = newNode;
    }
    else{
        newNode->data = data;
        newNode->next = head;
        head     = newNode;
    }
}

// print circular linked list
void print(CNode *head){
    CNode *p = head;
    do{
        printf("%d \t", p->data);
        p = p->next;
    } while(p = head);
    
}

int main(){
    CNode * head = (CNode*)malloc(sizeof(CNode));
    head = NULL;
    insertBeg(head, 23);
    insertBeg(head, 21);
    insertBeg(head, 22);

    return 0;
}
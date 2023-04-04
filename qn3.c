#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node sNode;

// isEmpty condition
int isEmpty(sNode *head)
{
    if (head == NULL)
    {
        return 1;
    }
    return 0;
}

// Insert element at first position in linkedlist
sNode *insertAtFirst(sNode *head, int data)
{
    sNode *newNode = (sNode *)malloc(sizeof(sNode));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// Insert element at nth position in likedlist
sNode *insertAtMid(sNode *head, int data, int index)
{
    if (index == 0)
    {
        head = insertAtFirst(head, data);
    }
    else
    {
        sNode *newNode = (sNode *)malloc(sizeof(sNode));
        newNode->data = data;
        sNode *p = head;
        int i = 1;
        while (i == index - 1)
        {
            p = p->next;
            i++;
        }
        newNode->next = p->next;
        p->next = newNode;
    }
    return head;
}

// Insert Element at last in linked list
sNode *insertAtLast(sNode *head, int data)
{
    if (head == NULL)
    {
        head = insertAtFirst(head, data);
    }
    else
    {
        sNode *newNode = (sNode *)malloc(sizeof(sNode));
        newNode->data = data;
        newNode->next = NULL;
        sNode *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = newNode;
    }
    return head;
}

// Traverse linked list
void print(sNode *head)
{
    if (head == NULL)
    {
        printf("Linked list is Empty");
    }
    else
    {
        while (head != NULL)
        {
            printf("Element %d\n", head->data);
            head = head->next;
        }
    }
}

// delete element atFirst in linked list
sNode *deleteElemetFirstPo(sNode *head)
{
    if (isEmpty(head))
    {
        printf("Linked list is Empty");
    }
    else
    {
        sNode *temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

// delete element nth position in linked list
sNode *deleteElmNthPo(sNode *head, int index)
{
    if (isEmpty(head))
    {
        printf("Linked list is Empty");
    }
    else
    {
        sNode *p = head;
        sNode *temp = head;
        int i = 0;
        while (i == index - 1)
        {
            p = p->next;
            i++;
        }
        temp = p->next;
        p->next = p->next->next;
        free(temp);
    }
    return head;
}

// delete element at last postion
void deleteElmLastP(sNode *head)
{
    if (isEmpty(head))
    {
        printf("Linked list is Empty");
    }
    else if (head->next == NULL)
    {
        sNode *temp = head;
        head = NULL;
        free(temp);
    }
    else
    {
        sNode *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        sNode *p = temp->next;
        temp->next = NULL;
        free(p);
    }
}

// search element in linked list
int SearchElm(sNode *head, int data)
{
    if (isEmpty(head))
    {
        printf("Linked list is Empty");
    }
    else
    {
        int i = 0;
        sNode *p = head;
        while (head != NULL)
        {
            if (head->data == data)
            {
                return i;
            }
            head = head->next;
            i++;
        }
        return -1;
    }
}

int main()
{
    sNode *head = (sNode *)malloc(sizeof(sNode));
    sNode *second = (sNode *)malloc(sizeof(sNode));
    sNode *third = (sNode *)malloc(sizeof(sNode));

    head->data = 20;
    head->next = second;

    second->data = 21;
    second->next = third;

    third->data = 22;
    third->next = NULL;

    // Insert elements in linked list
    head = insertAtFirst(head, 10);
    head = insertAtMid(head, 12, 1);
    head = insertAtLast(head, 100);
    print(head);

    printf("======== Delete Function start ========\n");

    // Delete elements in Linked list
    deleteElmLastP(head);
    head = deleteElemetFirstPo(head);
    head = deleteElmNthPo(head, 2);
    print(head);

    // Search Element in linked list
    int index = SearchElm(head, 22);
    index != -1 ? printf("Element found in %d", index) : printf("Element Not Found");
    return 0;
}
#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int data;
    struct node *next;
};

void Insert(struct node **head, int key) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = key;
    new_node->next = *head;
    *head = new_node;
    return;
}

void Delete(struct node **head, int val) {
    struct node *prev = *head;
    struct node *current = prev->next;

    if(prev->data == val) {
        *head = (*head)->next;
        return;
    }

    while(prev != NULL && current != NULL && current->data != val) {
        current = current->next;
        prev = prev->next;
    }
    prev->next = current->next;
    free(current);
    return;
}

void reverseIterative(struct node **head) {
    struct node *prev = NULL;
    struct node *current = *head;
    struct node *next;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    return;
}

void reverseRecursive(struct node **head) {
    struct node *first;
    struct node *rest;

    if(*head == NULL) {
        return;
    }
    first = *head;
    rest = first->next;

    if(rest == NULL) {
        return;
    }
    reverseRecursive(&rest);
    first->next->next = first;

    first->next = NULL;

    *head = rest;
    return;
}

void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}

int main()
{
     struct node *head = NULL;
     Insert(&head, 20);
     Insert(&head, 4);
     Insert(&head, 15);
     Insert(&head, 85);
     Delete(&head, 4);

     cout<<"Given linked list\n";
     printList(head);
     reverseIterative(&head);
     cout<<"\nReversed Linked list \n";
     printList(head);

     reverseRecursive(&head);
     cout<<"\nReversed Linked list \n";
     printList(head);
     return 0;
}


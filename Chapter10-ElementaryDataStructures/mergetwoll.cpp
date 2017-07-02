#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int data;
    struct node *next;
};

void Append(struct node **head, int key) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = key;
    new_node->next = NULL;
    if(*head == NULL) {
        *head = new_node;
        return;
    }
    struct node *temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return;
}

struct node* Merge(struct node **head1, struct node **head2) {
    struct node *head3;
    if(*head2==NULL && *head1!=NULL)   // if second list dosent exist
    {
        head3=*head1;
        return head3;
    }

    else if(*head1==NULL && *head2!=NULL)    // if first list dosent exist
    {
        head3=*head2;
        return head3 ;
    }

    head3 = *head1;
    struct node *temp = *head1;
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next = *head2;
    return head3;
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
     struct node *head1 = NULL;
     struct node *head2 = NULL;
     Append(&head1, 20);
     Append(&head1, 4);
     Append(&head1, 15);
     Append(&head1, 85);

     Append(&head2, 20);
     Append(&head2, 42);
     Append(&head2, 15);
     Append(&head2, 85);


     cout<<"Given linked list\n";
     printList(head1);

     cout<<"Given linked list\n";
     printList(head2);

     struct node *head3 = Merge(&head1, &head2);
     printList(head3);
     return 0;
}

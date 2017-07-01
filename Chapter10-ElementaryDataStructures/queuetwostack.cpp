#include <iostream>
#include <cstdlib>

using namespace std;

struct Stack {
    int data;
    struct Stack *next;
};

struct Queue {
    struct Stack *s1;
    struct Stack *s2;
};

void push(struct Stack **top, int key) {
    struct Stack* new_node = (struct Stack*)malloc(sizeof(struct Stack));
    new_node->data = key;
    new_node->next = *top;
    *top = new_node;
}

int pop(struct Stack **top) {
    if(*top == NULL){
        cout<<"Stack underflow!!\n";
        exit(0);
    }
    else {
    int del;
    struct Stack *temp;
    temp = *top;
    del = temp->data;
    *top = temp->next;
    free(temp);
    return del;
    }
}
void  enQueue(struct Queue *q, int key) {
    push(&q->s1, key);
}

int deQueue(struct Queue *q) {
    int d;
    if(q->s1 == NULL && q->s2 == NULL) {
        cout<<"Queue is empty!!\n";
        exit(0);
    }

    if(q->s2 == NULL) {
        while(q->s1 != NULL) {
            d = pop(&q->s1);
            push(&q->s2, d);
        }
    }

    d = pop(&q->s2);
    return d;
}

int main() {
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->s1 = NULL;
    q->s2 = NULL;
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);

    // Dequeue items
    cout<<deQueue(q)<<"\n";
    cout<<deQueue(q)<<"\n";
    cout<<deQueue(q)<<"\n";
    return 0;
}

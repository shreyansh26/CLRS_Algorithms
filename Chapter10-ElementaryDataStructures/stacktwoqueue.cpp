#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

struct QNode
{
    int data;
    struct QNode *next;
};

struct Queue
{
    struct QNode *front, *rear;
};

struct Stack {
    struct Queue* q1;
    struct Queue* q2;
};

struct Queue *createQueue(){
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct Queue** q, int key) {
    // Create a new LL node
    struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->data = key;
    temp->next = NULL;
    // If queue is empty, then new node is front and rear both
    if ((*q)->rear == NULL){
       (*q)->front = (*q)->rear = temp;
       return;
    }

    // Add the new node at the end of queue and change rear
    (*q)->rear->next = temp;
    (*q)->rear = temp;
}

int deQueue(struct Queue** q)
{
    // If queue is empty, return NULL.
    if ((*q)->front == NULL){
       cout<<"Underflow!!\n";
       return -1;
    }

    // Store previous front and move front one node ahead
    struct QNode *temp = (*q)->front;
    (*q)->front = (*q)->front->next;

    // If front becomes NULL, then change rear also as NULL
    if ((*q)->front == NULL)
       (*q)->rear = NULL;
    return temp->data;
}

void push(struct Stack* s, int key) {
    enQueue(&s->q1, key);
}

int pop(struct Stack* s) {
    int d = INT_MIN;
    if(s->q1 == NULL && s->q2 == NULL){
        cout<<"Stack is empty\n";
        exit(0);
        //return INT_MIN;
    }

    if(s->q2->front == NULL) {
        while(s->q1->front->next) {
            d = deQueue(&s->q1);
            enQueue(&s->q2, d);
        }
    }

    d = deQueue(&s->q1);
    swap(s->q1, s->q2);
    return d;
}

int main() {
    struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
    s->q1 = createQueue();
    s->q2 = createQueue();
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    // Dequeue items
    cout<<pop(s)<<"\n";
    cout<<pop(s)<<"\n";
    cout<<pop(s)<<"\n";
    cout<<pop(s)<<"\n";
    return 0;
}

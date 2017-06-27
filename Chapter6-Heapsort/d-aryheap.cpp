#include <iostream>
#define max_size 10000

using namespace std;

int d = 3;
int heap_size=0;
int dheapar[max_size];

int parent(int i) {
    return (i-1)/d;
}

int child(int k, int i) {
    return (i*d+k);
}


void dmaxHeapify(int i) {
    int largest = i;

    for(int k=1; k<=d; k++) {
        if(child(k, i) < heap_size && dheapar[child(k,i)] > dheapar[i]) {
            if(dheapar[child(k, i)] > dheapar[largest])
                largest = child(k, i);
        }
    }
    if(largest!=i) {
        swap(dheapar[largest], dheapar[i]);
        dmaxHeapify(largest);
    }
}

int dextractMax() {
    if (heap_size <= 0)
        return INT_MIN;
    if (heap_size == 1)
    {
        heap_size--;
        return dheapar[0];
    }

    int root;
    root = dheapar[0];
    dheapar[0] = dheapar[heap_size-1];
    heap_size--;
    dmaxHeapify(0);

    return root;
}

void insertVal(int k) {
    if (heap_size == max_size)
    {
        cout<<"\nOverflow: Could not insert Key\n";
        return;
    }

    heap_size++;
    int i = heap_size-1;
    dheapar[i] = k;

    while(i!=0 && dheapar[parent(i)] < dheapar[i]) {
        swap(dheapar[parent(i)], dheapar[i]);
        i = parent(i);
    }
}

void decreaseKey(int i, int new_val)
{
    dheapar[i] = new_val;
    while (i != 0 && dheapar[parent(i)] < dheapar[i])
    {
       swap(dheapar[i], dheapar[parent(i)]);
       i = parent(i);
    }
}

int getMax(){
    return dheapar[0];
}

void deleteKey(int i)
{
    decreaseKey(i, INT_MAX);
    dextractMax();
}

int main() {
    insertVal(3);
    insertVal(2);
    deleteKey(1);
    insertVal(15);
    insertVal(5);
    insertVal(4);
    insertVal(45);
    cout<<dheapar[0]<<" "<<dheapar[1]<<" "<<dheapar[2]<<" "<<dheapar[3]<<" "<<dheapar[4]<<"\n";
    cout<<dextractMax()<<"\n";
    cout<<dheapar[0]<<" "<<dheapar[1]<<" "<<dheapar[2]<<" "<<dheapar[3]<<"\n";
    cout<<getMax()<<"\n";
    decreaseKey(2, 1);
    cout<<getMax()<<"\n";
    deleteKey(0);
    cout<<getMax()<<"\n";
    return 0;
}


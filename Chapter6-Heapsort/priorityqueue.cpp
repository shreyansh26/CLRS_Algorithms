#include <iostream>
#define max_size 10000

using namespace std;

int heap_size=0;
int heapar[max_size];

int parent(int i) {
    return (i-1)/2;
}

int left(int i) {
    return (2*i+1);
}

int right(int i) {
    return (2*i+2);
}

void maxHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int largest;
    if(l<heap_size && heapar[l]>heapar[i]) {
        largest = l;
    }
    else
        largest = i;
    if(r<heap_size && heapar[r]>heapar[largest]) {
        largest = r;
    }
    if(largest!=i) {
        swap(heapar[largest], heapar[i]);
        maxHeapify(largest);
    }
}

void insertVal(int k)
{
    if (heap_size == max_size)
    {
        cout<<"\nOverflow: Could not insert Key\n";
        return;
    }

    heap_size++;
    int i = heap_size - 1;
    heapar[i] = k;

    while (i != 0 && heapar[parent(i)] < heapar[i])
    {
       swap(heapar[i], heapar[parent(i)]);
       i = parent(i);
    }
}

void decreaseKey(int i, int new_val)
{
    heapar[i] = new_val;
    while (i != 0 && heapar[parent(i)] < heapar[i])
    {
       swap(heapar[i], heapar[parent(i)]);
       i = parent(i);
    }
}

int extractMax()
{
    if (heap_size <= 0)
        return INT_MIN;
    if (heap_size == 1)
    {
        heap_size--;
        return heapar[0];
    }


    int root;
    root = heapar[0];
    heapar[0] = heapar[heap_size-1];
    heap_size--;
    maxHeapify(0);

    return root;
}

int getMax(){
    return heapar[0];
}

void deleteKey(int i)
{
    decreaseKey(i, INT_MAX);
    extractMax();
}

int main()
{
    insertVal(3);
    insertVal(2);
    deleteKey(1);
    insertVal(15);
    insertVal(5);
    insertVal(4);
    insertVal(45);
    cout<<extractMax()<<"\n";
    cout<<getMax()<<"\n";
    decreaseKey(2, 1);
    cout<<getMax()<<"\n";
    deleteKey(0);
    cout<<getMax()<<"\n";
    return 0;
}


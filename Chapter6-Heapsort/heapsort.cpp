#include <iostream>

using namespace std;

int left(int i) {
    return (2*i+1);
}

int right(int i) {
    return (2*i+2);
}

void maxHeapify(int a[], int n, int i) {
    int l = left(i);
    int r = right(i);
    int largest;
    if(l<n && a[l]>a[i]) {
        largest = l;
    }
    else
        largest = i;
    if(r<n && a[r]>a[largest]) {
        largest = r;
    }
    if(largest!=i) {
        swap(a[largest], a[i]);
        maxHeapify(a, n, largest);
    }
}

void buildHeap(int a[], int n) {
    int i = n/2-1;
    while(i>=0) {
        maxHeapify(a, n, i);
        i--;
    }
}

void printArray(int a[], int n)
{
    for (int i=0; i<n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

void heapSort(int a[], int n) {
    buildHeap(a, n);
    int  i = n-1;
    //printArray(a, i);
    for(i=n-1; i>=0; i--) {
        swap(a[0], a[i]);
        maxHeapify(a, i, 0);
    }
}

int main() {
    int a[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(a)/sizeof(a[0]);

    heapSort(a, n);

    printArray(a, n);
}

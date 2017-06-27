#include <iostream>

using namespace std;

int partitionAr(int a[], int p, int r) {
    int x = a[r-1];
    int i = p-1;
    for(int j=p; j<r-1; j++) {
        if(a[j]<x) {
            i = i+1;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[r-1]);
    return i+1;
}

void quicksort(int a[], int p, int r) {
    if(p<r) {
        int q = partitionAr(a, p, r);
        quicksort(a, p, q-1);
        quicksort(a, q+1, r);
    }
}

void printArray(int a[], int n){
    for (int i=0; i<n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

int main() {
    int a[] = {2, 5, 3, 9, 1};
    int n = 5;
    quicksort(a, 0, n);
    printArray(a, n);
    return 0;
}

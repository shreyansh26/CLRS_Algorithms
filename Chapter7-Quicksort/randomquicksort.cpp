#include <iostream>
#include <cstdlib>
#include<time.h>

using namespace std;

int partitionAr(int a[], int p, int r) {
    int x = a[r-1];
    int i = p-1;
    int j = p;
    while(j<r-1) {
        if(a[j]<x) {
            i += 1;
            swap(a[j], a[i]);
            j++;
        }
    }
    swap(a[i+1], a[r-1]);
    return i+1;
}

int randomPartition(int a[], int p, int r) {
    srand(0);
    int i = rand() % (r-p);
    swap(a[i], a[r-1]);
    return partitionAr(a, p, r);
}

void randomquicksort(int a[], int p, int r) {
    if(p<r) {
        int q = randomPartition(a, p, r);
        randomquicksort(a, p, q-1);
        randomPartition(a, q+1, r);
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
    randomquicksort(a, 0, n);
    printArray(a, n);
    return 0;
}

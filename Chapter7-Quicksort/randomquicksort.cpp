#include <iostream>
#include <cstdlib>
#include<time.h>

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

int randomPartition(int a[], int p, int r) {
    int i = rand()%(r-p);
    //cout<<i<<"\n";
    swap(a[i], a[r-1]);
    return partitionAr(a, p, r);
}

void randomquicksort(int a[], int p, int r) {
    if(p<r) {
        int q = randomPartition(a, p, r);
        randomquicksort(a, p, q-1);
        randomquicksort(a, q+1, r);
    }
}

void printArray(int a[], int n){
    for (int i=0; i<n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

int main() {
    srand((unsigned)time(0));
    int a[] = {2, 5, 3, 9, 1};
    int n = 5;
    randomquicksort(a, 0, n);
    printArray(a, n);
    return 0;
}

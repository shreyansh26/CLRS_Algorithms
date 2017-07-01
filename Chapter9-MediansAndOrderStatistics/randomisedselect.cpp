#include <iostream>
#include <cstdlib>
#include <time.h>

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
    int i = p + rand()%(r-p);
    //cout<<i<<"\n";
    swap(a[i], a[r-1]);
    return partitionAr(a, p, r);
}

int randomisedSelect(int a[], int p, int r, int i) {
    if(p==r-1) {
        return a[p];
    }
    int q = randomPartition(a, p, r);
    int k = q-p+1;
    if(i==k) {
        return a[q];
    }
    else if(i<k) {
        return randomisedSelect(a, p, q-1, i);
    }
    else
        return randomisedSelect(a, q+1, r, i-k);
}

int main() {
    srand((unsigned)time(NULL));
    int a[] = {1,5,33,74,22,31};
    int n = 6;
    int num = randomisedSelect(a, 0, n, 4);
    cout<<num<<"\n";
    return 0;
}

#include <iostream>

using namespace std;

void printArr(int a[], int n) {
    for(int i=0; i<n; i++) {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

void countingsort(int a[], int b[], int n, int k) {
    int c[k+1]={0};
    for(int j=0; j<n; j++) {
        c[a[j]] = c[a[j]] + 1;
    }
    for(int i=1; i<k+1; i++) {
        c[i] = c[i] + c[i-1];
    }
    for(int j=n-1; j>=0; j--) {
        b[c[a[j]]-1] = a[j];
        c[a[j]] = c[a[j]] - 1;
    }
    printArr(b, n);
}

int main() {
    int a[8] = {2, 5, 3, 0, 2, 3, 0, 3};
    int b[8] = {0};
    int n = 8;
    int k = 5;
    countingsort(a, b, n, k);
    //printArr(a, sizeof(a)/sizeof(a[0]));
}

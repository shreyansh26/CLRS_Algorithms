#include <iostream>
#include <limits>
using namespace std;

void printAr(int a[]) {
    int sizeAr = sizeof(a)/sizeof(a[0]);
    for(int i=0; i<sizeAr; i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}

void mergeAr(int a[], int p, int q, int r) {
    int n1 = q-p+1;
    int n2 = r-q;
    int i,j;
    int L[n1+1], R[n2+1];

    for(i=0; i<n1; i++) {
        L[i] = a[p+i];
    }
    L[i] = INT_MAX;

    for(j=0; j<n2; j++){
        R[j] = a[q+j+1];
    }
    R[j] = INT_MAX;

    i = 0, j = 0;
    for(int k=p; k<=r; k++) {
        if(L[i]<= R[j]) {
            a[k] = L[i++];
        }
        else {
            a[k] = R[j++];
        }
    }
}

void merge_sort(int a[], int p, int r) {
    int q;
    if(p<r) {
        q = (p+r)/2;
        merge_sort(a, p, q);
        merge_sort(a, q+1, r);
        mergeAr(a, p, q, r);
    }
}

int main() {
    int a[] = {3, 4, 1, 7, 5};
    int n = 5;
    merge_sort(a, 0, n-1);
    for(int i=0;i<n; i++)
        cout<<a[i]<<" ";
    return 0;
}

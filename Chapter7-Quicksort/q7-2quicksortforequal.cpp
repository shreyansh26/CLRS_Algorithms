#include <iostream>
#include <tuple>

using namespace std;

tuple<int, int> partitionDash(int a[], int p, int r) {
    int x = a[r-1];
    int i = p-1;
    int k;
    for(int j=p; j<r-1; j++) {
        if(a[j]<x) {
            i += 1;
            swap(a[j], a[i]);
        }
    }
    i+=1;
    swap(a[i], a[r-1]);
    k = i;
    for(int j=i+1; j<r; j++) {
        if(a[j] == x) {
            k += 1;
            swap(a[k], a[j]);
        }
    }
    return make_tuple(i, k);
}

void quicksortDash(int a[], int p, int r) {
    if(p<r) {
        int q, t;
        tie(q, t) = partitionDash(a, p, r);
        quicksortDash(a, p, q);
        quicksortDash(a, t+1, r);
    }
}

void printArray(int a[], int n){
    for (int i=0; i<n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

int main() {
    int a[] = {2, 5, 3, 9, 9, 1, 10, 8};
    int n = 8;
    quicksortDash(a, 0, n);
    printArray(a, n);
    return 0;
}

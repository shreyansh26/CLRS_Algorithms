#include <iostream>

using namespace std;

int hoarePartition(int a[], int p, int r) {
    int i = p-1;
    int j = r;
    int x = a[p];

    while(1) {
        do{
            j--;
        } while(a[j]>x);
        do {
            i++;
        } while(a[i]<x);

        if(i<j) {
            swap(a[i], a[j]);
        }
        else {
            return j;
        }
    }
}

void quicksort(int a[], int p, int r) {
    if(p<r) {
        int x = a[p];
        int q = hoarePartition(a, p, r);
        int i = 0;
        while(a[i]!=x) {
            i++;
        }
        if(i<=q) {
            swap(a[i], a[q]);
        }
        else {
            swap(a[i], a[q+1]);
            q+=1;
        }
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
    int a[] = {2, 5, 3, 9, 1, 10};
    int n = 6;
    quicksort(a, 0, n);
    printArray(a, n);
    return 0;
}

#include <iostream>

using namespace std;

void insertion_sort(int a[], int n) {
    int key, j;
    for(int i=1; i<n; i++) {
        key = a[i];
        j = i-1;
        while (j>0 && a[j]>key) {
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = key;
    }
}

int main() {
    int a[] = {1, 2, 5, 7, 3};
    int n = 5;
    insertion_sort(a, n);
    for(int i=0;i<n; i++)
        cout<<a[i]<<" ";
    return 0;
}

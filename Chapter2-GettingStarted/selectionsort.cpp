#include <iostream>

using namespace std;

void swap(int *xp, int *yp) {
    int t;
    t = *xp;
    *xp = *yp;
    *yp = t;
}

void selection_sort(int a[], int n) {
    int min_id;
    for(int i=0; i<n-1; i++) {
        min_id = i;
        for(int j=i+1; j<n; j++) {
            if(a[j]<a[min_id])
                min_id = j;
        }
        swap(&a[i], &a[min_id]);
    }
}

int main() {
    int a[] = {1, 2, 5, 7, 3};
    int n = 5;
    selection_sort(a, n);
    for(int i=0;i<n; i++)
        cout<<a[i]<<" ";
    return 0;
}


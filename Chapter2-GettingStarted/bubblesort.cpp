#include <iostream>

using namespace std;

void swap(int *xp, int *yp) {
    int t;
    t = *xp;
    *xp = *yp;
    *yp = t;
}

void bubblesort(int a[], int n) {
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++) {
            if(a[j] > a[j+1]) {
                swap(&a[j], &a[j+1]);
            }
        }
    }
}

int main(){
    int a[] = {1, 2, 5, 7, 3};
    int n = 5;
    bubblesort(a, n);
    for(int i=0;i<n; i++)
        cout<<a[i]<<" ";
    return 0;
}

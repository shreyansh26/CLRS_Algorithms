#include <iostream>

using namespace std;

void insertionSortRecur(int a[], int n) {
    if(n==1)
        return;

    insertionSortRecur(a, n-1);

    int last = a[n-1];
    int j = (n-1)-1;

    while(j>=0 && a[j]>last) {
        a[j+1] = a[j];
        j--;
    }
    a[j+1] = last;
}

int main() {
    int a[] = {1, 2, 5, 7, 3};
    int n = 5;
    insertionSortRecur(a, n);
    for(int i=0;i<n; i++)
        cout<<a[i]<<" ";
    return 0;
}

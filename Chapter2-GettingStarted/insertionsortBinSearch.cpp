#include <iostream>

using namespace std;

// To search for index just less than key so that key can be entered there
int binarySearch(int a[], int low, int high, int key) {
    if(high <= low){
        return (a[low] > key) ? low : low+1;
    }

    int mid = low +(high-low)/2;
    if (a[mid] == key)
        return mid+1;
    else if(a[mid]<key)
        return binarySearch(a,mid+1,high,key);
    else
        return binarySearch(a,low,mid-1,key);
}

void insertionsortBinSearch(int a[], int n) {
    int key, j;
    for(int i=1; i<n; i++) {
        key = a[i];
        j = i-1;
        int ind = binarySearch(a,0,j,key);

        while(j>=ind) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main() {
    int a[] = {1, 2, 5, 7, 3};
    int n = 5;
    insertionsortBinSearch(a, n);
    for(int i=0;i<n; i++)
        cout<<a[i]<<" ";
    return 0;
}

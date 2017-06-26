#include <iostream>
#include <algorithm>
using namespace std;

int p[] = {100, 1, 300, 400, 500};
bool compare(int i, int j) {
    return p[i]<p[j];
}

int main() {
    int a[5] = {1,4,2,5,3};
    int n = 5;
    //int p[5] = {100, 200, 500, 450, 300};
    sort(a, a+n, compare);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}

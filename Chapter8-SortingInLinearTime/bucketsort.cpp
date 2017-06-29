#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void insertionsort(vector<float> a) {
    int j;
    float key = 0.0f;
    for(int i=0; i<a.size(); i++) {
        cout<<a[i]<<" ";
    }
    cout<<"\n";

    for(int i=0; i<a.size(); i++) {
        key = a[i];
        j = i-1;
        while(j>0 && a[j]>key) {
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = key;
    }

    for(int i=0; i<a.size();i++) {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

void bucketsort(float a[], int n) {
    vector< vector<float> > b(n);
    for(int i=0; i<n; i++) {
        b[floor(n*a[i])].push_back(a[i]);
    }

    for(int i=0; i<b.size(); i++) {
        sort(b[i].begin(), b[i].end());
        //insertionsort(b[i]);
    }

    vector<float> c = b[0];
    for(int i=1; i<b.size(); i++) {
        c.insert(c.end(), b[i].begin(), b[i].end());
    }
    for(int i=0; i<c.size(); i++) {
        cout<<c[i]<<" ";
    }
    cout<<"\n";

}

int main() {
    float a[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.23, 0.12, 0.21, 0.68};
    int n = 10;
    bucketsort(a, n);
    return 0;
}


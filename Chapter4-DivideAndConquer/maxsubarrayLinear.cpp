#include <iostream>
#include <tuple>
#include <limits>

using namespace std;

tuple<int, int, int> maxSubArrayLinear(int a[], int n) {
    int maxSum = INT_MIN;
    int sum = 0;
    int leftInd = 0, rightInd = 0;
    int low = 0;

    for(int i=0; i<n; i++) {
        sum += a[i];
        if(sum > maxSum) {
            maxSum = sum;
            leftInd = low;
            rightInd = i;
        }
        if (sum<0) {
            sum = 0;
            low = i+1;
        }
    }
    return make_tuple(leftInd, rightInd, maxSum);
}

int main() {
    int lowInd, highInd, maxSum;
    int a[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int n = 16;
    tie(lowInd, highInd, maxSum) = maxSubArrayLinear(a, n);
    cout<<"Left Index: "<<lowInd<<"\n";
    cout<<"Right Index: "<<highInd<<"\n";
    cout<<"Max Sum: "<<maxSum<<"\n";
    return 0;
}

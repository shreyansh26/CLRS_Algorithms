#include <iostream>
#include <tuple>
#include <limits>

using namespace std;

tuple<int, int, int> findMaxCrossSubAr(int a[], int low, int mid, int high) {
    int left_sum = INT_MIN;
    int sum = 0;
    int max_left;
    for(int i=mid; i>=low; i--) {
        sum += a[i];
        if(sum>left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = INT_MIN;
    sum = 0;
    int max_right;
    for(int i=mid+1; i<=high; i++) {
        sum += a[i];
        if(sum>right_sum) {
            right_sum = sum;
            max_right = i;
        }
    }
    return make_tuple(max_left, max_right, left_sum+right_sum);
}


tuple<int, int, int> findMaxSubAr(int a[], int low, int high) {
    int left_low, left_high, left_sum, right_low, right_high, right_sum, cross_low, cross_high, cross_sum, mid;
    if (low==high) {
        return make_tuple(low, high, a[low]);
    }
    else {
        mid = low + (high-low)/2;
        tie(left_low, left_high, left_sum) = findMaxSubAr(a, low, mid);
        tie(right_low, right_high, right_sum) = findMaxSubAr(a, mid+1, high);
        tie(cross_low, cross_high, cross_sum) = findMaxCrossSubAr(a, low, mid, high);

        if(left_sum >= right_sum && left_sum >= cross_sum) {
            return make_tuple(left_low, left_high, left_sum);
        }
        else if(right_sum >= left_sum && right_sum >= cross_sum) {
            return make_tuple(right_low, right_high, right_sum);
        }
        else
            return make_tuple(cross_low, cross_high, cross_sum);
    }
}

int main() {
    int lowInd, highInd, maxSum;
    int a[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int n = 16;
    tie(lowInd, highInd, maxSum) = findMaxSubAr(a, 0, n-1);
    cout<<"Left Index: "<<lowInd<<"\n";
    cout<<"Right Index: "<<highInd<<"\n";
    cout<<"Max Sum: "<<maxSum<<"\n";
    return 0;
}















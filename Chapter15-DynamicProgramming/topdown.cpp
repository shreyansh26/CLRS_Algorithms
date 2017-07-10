#include <iostream>

using namespace std;

int topdown_rod(int p[], int n, int r[]) {
    int q;
    if(r[n]>=0)
        return r[n];
    if(n==0)
        q = 0;
    else {
        q = INT_MIN;
        for(int i=1; i<=n; i++) {
            q = max(q, p[i]+topdown_rod(p, n-i, r));
        }
    }
    r[n] = q;
    return q;
}

int calltopdown(int p[], int n) {
    int r[n+1] = {0};
    for(int i=0; i<=n; i++)
        r[i] = INT_MIN;
    return topdown_rod(p, n, r);
}

int main() {
	int p[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	int n = 4;
	cout<<calltopdown(p, n);
	return 0;
}

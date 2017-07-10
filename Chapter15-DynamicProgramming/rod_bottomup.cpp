#include <iostream>
#include <limits>

using namespace std;

int bottomup_rod(int p[], int n) {
	int r[n+1];
	r[0] = 0;
	for(int j=1; j<=n; j++) {
		int q = INT_MIN;
		for(int i=1; i<=j; i++) {
			q = max(q, p[i]+r[j-i]);
		}
		r[j] = q;
	}
	return r[n];
}

int main() {
	int p[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	int n = 10;
	cout<<bottomup_rod(p, n);
	return 0;
}

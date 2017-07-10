#include <iostream>
#include <vector>
#include <limits>

using namespace std;

pair<vector<int>, vector<int>> extended_bottumup(int p[], int n) {
	vector<int> r(n+1), s(n+1);
	r[0] = 0;
	for(int j=1; j<=n; j++) {
		int q = INT_MIN;
		for(int i=1; i<=j; i++) {
			if(q < p[i]+r[j-i]) {
				q = p[i]+r[j-i];
				s[j] = i;
			}
		}
		r[j] = q;
	}
	return make_pair(r, s);
}

void print_cutrod_sol(int p[], int n) {
    auto ret = extended_bottumup(p, n);
    vector<int> r = ret.first;
    vector<int> s = ret.second;
    while(n>0) {
        cout<<s[n]<<" ";
        n = n - s[n];
    }
}

int main() {
	int p[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

	auto ret = extended_bottumup(p, 11);
    vector<int> r = ret.first;
    vector<int> s = ret.second;

	for(int i=0; i<11; i++){
		cout<<r[i]<<" ";
	}
	cout<<"\n";
	for(int i=0; i<11; i++){
		cout<<s[i]<<" ";
	}
	cout<<"\n";

	print_cutrod_sol(p, 4);
	return 0;
}

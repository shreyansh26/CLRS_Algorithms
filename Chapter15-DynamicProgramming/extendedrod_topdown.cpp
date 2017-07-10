#include <iostream>

using namespace std;

int r[11] = {0};
int s[11] = {0};

int extended_topdown(int p[], int n) {
	if(r[n] >= 0)
		return r[n];
	int q;
	if(n==0)
		q = 0;
	else {
		q = INT_MIN;
		for(int i=1; i<=n; i++) {
			int val = p[i] + extended_topdown(p, n-i);
			if(q<val) {
				q = val;
				s[n] = i;
			}
		}
	}
	r[n] = q;
    return q;
}

int calltopdown(int p[], int n) {
    for(int i=0; i<=n; i++)
        r[i] = INT_MIN;
    return extended_topdown(p, n);
}

void print_cutrod_sol(int p[], int n) {
    while(n>0) {
        cout<<s[n]<<" ";
        n = n - s[n];
    }
}

int main() {
	int p[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	cout<<calltopdown(p, 10)<<"\n";;
	//print_cutrod_sol(p, 9);

	for(int i=0; i<11; i++){
		cout<<r[i]<<" ";
	}
	cout<<"\n";
	for(int i=0; i<11; i++){
		cout<<s[i]<<" ";
	}
	cout<<"\n";

	print_cutrod_sol(p, 9);
	return 0;
}

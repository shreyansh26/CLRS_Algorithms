#include <iostream>

using namespace std;

/* Iterative Function to calculate (x^y)%p in O(log y) */
int modular_exponentiation(int x, unsigned int y, int p) {
    int res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or equal to p

    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int main() {
	int a = 2, b = 5, p = 3;
	cout<<modular_exponentiation(a, b, p);
	return 0;
}

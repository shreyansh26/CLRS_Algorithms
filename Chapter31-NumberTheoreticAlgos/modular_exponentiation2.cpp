#include <iostream>
#include <cmath>

using namespace std;

int modular_exponentiation(int a, int b, int n) {
    int c = 0;
    int d = 1;
    int s = a;
    int b2 = b;
    int i = 0;
    while(b2) {
        int rem = b2%2;
        if(rem == 1) {
            d = (s*d)%n;
            c = (int)pow(2, i) + c;
        }
        s = (s*s)%n;
        i++;
        b2 = b2>>1;
    }
    return d;
}

int main() {
	int a = 2, b = 5, p = 7;
	cout<<modular_exponentiation(a, b, p);
	return 0;
}

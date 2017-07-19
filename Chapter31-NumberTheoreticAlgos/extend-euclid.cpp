#include <iostream>
#include <tuple>

using namespace std;

tuple<int, int, int> extend_euclid(int a, int b) {
  int d2, x2, y2, d, x, y;
  if(b==0) {
    return make_tuple(a, 1, 0);
  }
  else {
    tie(d2, x2, y2) = extend_euclid(b, a%b);
    d = d2;
    x = y2;
    y = x2 - ((a/b)*y2);
    return make_tuple(d, x, y);
  }
}

int main() {
  int d, x, y;
  int a = 99;
  int b = 78;
  tie(d, x, y) = extend_euclid(a, b);
  cout<<"GCD: "<<d<<"\n"<<"x: "<<x<<"\n"<<"y: "<<y<<"\n";
  return 0;
}

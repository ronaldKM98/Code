#include <cstdio>
using namespace std;
//In this method its guaranteed that a <= b <= c
int process(int n, int a, int b, int c, int i) {
  if (n < a || n <= 0) return i;
  else {
    int moda, modb, modc;
    moda = n % a;
    modb = n % b;
    modc = n % c;
    if(moda > modb && moda > modc && n / a > 0) {
      return process(n - n / a, a, b, c, i + 1);
    } else if(modb > moda && modb > modc && n / b > 0) {
      return process(n - (n / b), a, b, c, i + 1);
    } else if(n / c > 0) {
      return process(n - n / c, a, b, c, i + 1);
    } else {
      return i;
    }
  }
}

int processs(int n, int a, int b, int c, int i) {
  if (n < a || n <= 0) return i;
  else {
    int moda, modb, modc;
    moda = n % a;
    modb = n % b;
    modc = n % c;
    if(moda > modb && moda > modc) {
      return process(n - n / a, a, b, c, i + 1);
    } else if(modb > moda && modb > modc) {
      return process(n - (n / b), a, b, c, i + 1);
    } else if (true) {
      return process(n - n / c, a, b, c, i + 1);
    } else {
      return i;
    }
  }
}

int f() {
  int n, a, b, c;
  scanf("%d %d %d %d", &n, &a, &b, &c);
  if (a > c) {
    int d = a;
    a = c;
    c = d;
  }
  if(a > b) {
    int d = a;
    a = b;
    b = d;
  }
  if(b > c) {
    int d = b;
    b = c;
    c = d;
  }
  printf("%d", processs(n, a, b, c, 0));
  return 0;
}

int main() {
  int n, a, b, c;
  scanf("%d %d %d %d", &n, &a, &b, &c);
  int max = -1000000000;
  for(int x = 0; x*a <= n; x++) {
    for(int y = 0; x*a + y*b <= n; y++) {
      int z = (n - (a * x) - (b * y)) / c;
      if(a*x + b*y + c*z == n && x + y + z > max) {
        max = x + y + z;
      }
    }
  }
  printf("%d", max);
  return 0;
}

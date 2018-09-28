#include <cstdio>
using namespace std;

int main() {
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
  printf("%d", process(n, a, b, c, 0));
  return 0;
}

int process(int n, int a, int b, int c, int i) {
  if (n % a == 0) {
    return process(n / a, a, b, c, i + 1);
  } else if(n % b == 0) {
    return process(n / b, a, b, c, i + 1);
  } else if(n % c == 0) {
    return process(n / c, a, b, c, i + 1);
  } else {
    return i;
  }
}



  

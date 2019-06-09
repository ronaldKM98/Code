#include <cstdio>
#include <iostream>

using namespace std;

int count(int64_t, int);

int
main() {
    int k;
    cin >> k;
    int64_t n;
    while(k--) {
        cin >> n;
        int res = count(n, 0);
        cout << res << endl;
    }

    return 0;
}

int count(int64_t n, int cont) {
    if (n == 0) return -1;
    if (n == 1) return cont;
    if (n % 5 == 0) return count((n * 4) / 5, cont + 1);
    if (n % 3 == 0) return count((n * 2) / 3, cont + 1);
    if (n % 2 == 0) return count((n * 1) / 2, cont + 1);
    else return -1;
}
#include <cstdio>
#include <iostream>
using namespace std;

bool check(int [], int);
void printArr(int a[], int n);

int
main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n];
    for(int i = 0; i < n; i ++) a[i] = 0;

    for(int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        a[x - 1] = a[x - 1] + 1;
        if(check(a, n)) {
            for(int j = 0; j < n; j++) {
                a[j]--;
            }
            cout << 1;
        } else {
            cout << 0;
        }
    }
    return 0;
}

bool check(int a[], int n) {
    //printArr(a, n);
    for(int j = 0; j < n; j++) {
        if(a[j] <= 0) return false;
    }
    return true;
}

void printArr(int a[], int n){
    cout << "Arr = ";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << '\n';
}
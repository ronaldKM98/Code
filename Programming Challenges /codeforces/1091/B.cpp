#include <cstdio>

using namespace std;

int
main() {
    int n;
    scanf("%d", &n);
    int x[n];
    int y[n];
    int i = 0;
    while(i < n) {
        scanf("%d %d", &x[i], &y[i]);
        i++;
    }
    i = 0;
    int a[n];
    int b[n];
    while(i < n) {
        scanf("%d %d", &a[i], &b[i]);
        i++;
    }
    
    return 0;
}
#include <cstdio>

using namespace std;

int
main() {
    int T, N, c;
    int max = 0;
    scanf("%d", &T);
    int i = 1;
    while(T--) {
        scanf("%d", &N);
        while(N--) {
            scanf("%d", &c);
            if(c > max) max = c;
        }
        printf("Case %d: %d\n", i, max);
        max = 0;
        i++;
    }
    return 0;
}
#include <cstdio>

using namespace std;

int
main() {
        int y, b, r;
        scanf("%d %d %d", &y, &b, &r);
        int max = 6;
        for(int i = 1; i <= y; i++) {
            for(int j = 2; j <= b; j++) {
                for(int k = 3; k <= r; k++) {
                    if(i == j-1 && j+1 == k) {
                        if((i + j + k) > max) max = i + j + k;
                    }
                }
            }
        }
        printf("%d", max);
        return 0;
}

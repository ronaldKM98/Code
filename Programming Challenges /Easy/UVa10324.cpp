#include <cstdio>
#include <string>
#include <cmath>
#include <iostream>
#include "string.h"
using namespace std;

int
main() {
    char in [1000000];
    int k = 1;
    while(true) {
        if(scanf("%s", in) == EOF) {
        //if(strcmp(in, "EOF") || strcmp(in, "\n")) {
            break;
        } else {
            if(strcmp(in, "\n") == 0) break;
            printf("Case %d:\n", k);
            int N;
            scanf("%d", &N);
            int i, j;
            while(N--) {
                scanf("%d %d", &i, &j);
                int max, min;
                max = fmax(i, j);
                min = fmin(i, j);

                if(min != max) {
                    int i = min;
                    for(i = min + 1; i <= max; i++) {
                        if(in[i] != in[i-1]) {
                            printf("No\n");
                            break;
                        }
                    }
                    if(i-1 == max) printf("Yes\n");
                } else {
                    printf("Yes\n");
                }
            }
            k++;
        }
    }
    return 0;
}
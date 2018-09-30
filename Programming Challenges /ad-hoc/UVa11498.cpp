#include <cstdio>

using namespace std;

int 
main() {
    int TC, N, M, x, y;
    while(scanf("%d", &TC), TC) {
        scanf("%d %d", &N, &M);
        while(TC--) {
            scanf("%d %d", &x, &y);
            if(x == N || y == M) {
                printf("%s\n", "divisa");
            } else if(x > N && y > M) {
                printf("%s\n", "NE");
            } else if(x > N && y < M){
                printf("%s\n", "SE");
            } else if (x < N && y > M) {
                printf("%s\n", "NO");
            } else {
                printf("%s\n", "SO");
            }
        }
    }
    return 0;
}

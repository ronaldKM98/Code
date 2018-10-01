#include <cstdio>

using namespace std;

int main() {
    int N, budget, H, W;
    int actual = 2147483647;
    while(scanf("%d %d %d %d", &N, &budget, &H, &W) == 4) {
        actual = 2147483647;
        int prices [H];
        int beds[W];
        while(H--) {
            scanf("%d", &prices[H]);
            int i = W;
            while(i--){
                scanf("%d", &beds[i]);
                if(beds[i] >= N && N * prices[H] < actual) {
                    actual = N * prices[H];
                }
            }
        }
        if(actual < budget) {
            printf("%d\n", actual);
        } else {
            printf("%s\n", "stay home");
        }
    }
    return 0;
}
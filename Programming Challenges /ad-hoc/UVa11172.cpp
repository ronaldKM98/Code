#include <cstdio>

using namespace std;
int
main() {
    int TC, a, b;
    scanf("%d", &TC);
    while(TC--) {
        scanf("%d %d", &a, &b);
        a > b ? printf("%s\n", ">") : a < b ? printf("%s\n", "<") : printf("%s\n", "=");
    }
    return 0;
}

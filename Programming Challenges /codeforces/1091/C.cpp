#include<cstdio>
#include<set>
using namespace std;

int
main() {
    int n;
    scanf("%d", &n);
    set<int> funNums;
    for(int k = 1; k <= n; k++) {
        int fun = 0;
        int i = 1;
        do {
            fun += i;
            i = (i + k) % n;
        } while(i != 1);
        funNums.insert(fun);
    }

    for(auto f : funNums) {
        printf("%d ", f);
    } 

    return 0;
}
#include<iostream>
#include<cmath>
#include <bitset>

using namespace std;
/*
 * UVa10038 -- JollyJumpers
*/
int
main() {
    while(true) {
        int n;
        if(scanf("%d", &n) != EOF) {
            int arr[n + 5];
            for (int i = 0; i < n; i++) {
                int x;
                scanf("%d", &x);
                arr[i] = x;
            }
            bitset<3000> found = bitset<3000>().reset(); // found = false

            for(int i = 0; i < n - 1; i++) {
                int a = abs(arr[i] - arr[i + 1]);
                if(a < 1 || a >= n) found[a] = false;
                else found[a] = true;
            }
            bool jolly = true;
            for(int i = 1; i < n; i++) {
                if(!found[i]) {
                    jolly = false;
                    break;
                } else continue;
            }
            if(jolly) cout << "Jolly" << endl;
            else cout << "Not jolly" << endl;
        } else break;
    }
    return 0;
}
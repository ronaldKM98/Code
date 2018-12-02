#include<iostream>
#include<cmath>
#include <bitset>

using namespace std;

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
            bitset<3000> found = bitset<3000>().reset();

            for(int i = 0; i < n - 1; i++) {
                int a = abs(arr[i] - arr[i + 1]);
                if(a < 1 || a >= n) found[a] = false;
                else found[a] = true;
            }
            bool jolly = true;
            for(int i = 0; i < n; i++) {
                if(arr[i] < 0) jolly = false;
                else if(!found[arr[i]]) {
                    //printf("found[arr[%d]] = ", i);
                    cout << found[arr[i]] << endl;
                    jolly = false;
                }
            }
            if(jolly) cout << "Jolly" << endl;
            else cout << "Not jolly" << endl;
        } else break;
    }
    return 0;
}
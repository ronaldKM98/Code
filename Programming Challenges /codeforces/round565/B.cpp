#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

bool obtain();

vector<int> v;

int
main() {
    int n, a;
    cin >> n;
    while(n--) {
        cin >> a;
        v.push_back(a);
    }
    cout << obtain() << endl;

    return 0;
}

bool obtain() {
    int arr [6] = {4, 8, 15, 16, 23, 42};
    bool isPossible = true;
    

    for(vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        for (int i = 0; i < 6; ++i) {
            if (*it == arr[i]) {
                v.erase(it);
                break;;
            }
            isPossible = false;
        }
    }
    return isPossible;
}

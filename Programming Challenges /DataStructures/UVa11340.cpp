#include<iostream>
#include <string>
#include <iomanip>
#include <map>

using namespace std;
/*
 * UVa11340 -- Newspaper
*/
int
main() {
    int N, K, M;

    cin >> N;
    while(N--) {
        map<char, int> paidChars;
        cin >> K;
        while(K--) {
            int k, v;
            scanf("%d %d", &k, &v);
            cout << "Read k = " << k << endl;
            cout << "Read v = " << v << endl;
            paidChars[k] = v;
            printf("char %d = %d\n", k, v);
        }
        cout << "The map was: " << endl;
        for (auto it = paidChars.begin(); it != paidChars.end(); ++it) {
            cout << it->first << " -> " << it->second << '\n';
        }
        cin >> M;
        double pay = 0.00;
        while(M--) {
            string line;
            getline(cin, line);
            for(char& c : line) {
                pay += paidChars[c];
            }
        }
        cout << pay << "$" << endl;
    }
    return 0;
}
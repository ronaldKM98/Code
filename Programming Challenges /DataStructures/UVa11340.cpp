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
            paidChars[k] = v;
        }
        cout << "The map was: " << endl;
        for(int i = 0; i < paidChars.size(); i++) {
            
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
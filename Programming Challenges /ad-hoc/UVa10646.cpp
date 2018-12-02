#include <cstdio>
#include<string>
#include<iostream>
#include<map>
#include <stack>

using namespace std;

map<string, int> cards;

int
main() {
    cards["AD"] = 1;
    cards["2D"] = 2;
    cards["3D"] = 3;
    cards["4D"] = 4;
    cards["5D"] = 5;
    cards["6D"] = 6;
    cards["7D"] = 7;
    cards["8D"] = 8;
    cards["9D"] = 9;
    cards["TD"] = 10;
    cards["JD"] = 10;
    cards["QD"] = 10;
    cards["KD"] = 10;
    cards["AC"] = 10;
    cards["2C"] = 2;
    cards["3C"] = 3;
    cards["4C"] = 4;
    cards["5C"] = 5;
    cards["6C"] = 6;
    cards["7C"] = 7;
    cards["8C"] = 8;
    cards["9C"] = 9;
    cards["TC"] = 10;
    cards["JC"] = 10;
    cards["QC"] = 10;
    cards["KC"] = 10;
    cards["AH"] = 10;
    cards["2H"] = 2;
    cards["3H"] = 3;
    cards["4H"] = 4;
    cards["5H"] = 5;
    cards["6H"] = 6;
    cards["7H"] = 7;
    cards["8H"] = 8;
    cards["9H"] = 9;
    cards["TH"] = 10;
    cards["JH"] = 10;
    cards["QH"] = 10;
    cards["KH"] = 10;
    cards["AS"] = 10;
    cards["2S"] = 2;
    cards["3S"] = 3;
    cards["4S"] = 4;
    cards["5S"] = 5;
    cards["6S"] = 6;
    cards["7S"] = 7;
    cards["8S"] = 8;
    cards["9S"] = 9;
    cards["TS"] = 10;
    cards["JS"] = 10;
    cards["QS"] = 10;
    cards["KS"] = 10;
    int n;
    cin >> n;
    int TC = 1;
    while(n--) {
        stack <string> pile;
        string s;
        for(int i = 0; i < 52; i++) {
            cin >> s;
            pile.push(s);
        }
        string hand [30];
        for (int i = 0; i < 25; i++) {
	        hand[24 - i] = pile.top();
	        pile.pop();
        }
        int y = 0;
        for (int i = 0; i < 3; i++) {
	        int x = cards[pile.top()];
            y = y + x;
            pile.pop();
            for (int j = 0; j < 10 - x; j++) pile.pop();
        }
        for (int i = 0; i < 25; i++) pile.push(hand[i]);
        while(pile.size() > y) pile.pop();
        printf("Case %d: %s\n", TC++, pile.top().c_str());
    }
    return 0;
}

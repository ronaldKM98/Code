#include<cstdio>
#include<map>
#include<string>
#include<iostream>
 
using namespace std;
 
long L;
string dir, wire;
map<string, map<string, string> > bends;
 
int main() {
    bends["+x"]["+y"] = "+y";
    bends["+x"]["-y"] = "-y";
    bends["+x"]["+z"] = "+z";
    bends["+x"]["-z"] = "-z";
    bends["-x"]["+y"] = "-y";
    bends["-x"]["-y"] = "+y";
    bends["-x"]["+z"] = "-z";
    bends["-x"]["-z"] = "+z";
    bends["+y"]["+y"] = "-x";
    bends["+y"]["-y"] = "+x";
    bends["+y"]["+z"] = "+y";
    bends["+y"]["-z"] = "+y";
    bends["-y"]["+y"] = "+x";
    bends["-y"]["-y"] = "-x";
    bends["-y"]["+z"] = "-y";
    bends["-y"]["-z"] = "-y";
    bends["+z"]["+y"] = "+z";
    bends["+z"]["-y"] = "+z";
    bends["+z"]["+z"] = "-x";
    bends["+z"]["-z"] = "+x";
    bends["-z"]["+y"] = "-z";
    bends["-z"]["-y"] = "-z";
    bends["-z"]["+z"] = "+x";
    bends["-z"]["-z"] = "-x";

    while(true) {
        scanf("%lu", &L);
        if(L == 0) break;
        wire = "+x";
        while(L > 1) {
            cin >> dir;
            if(dir != "No") {
                wire = bends[wire][dir];
            }
            L--;
        }
        printf("%s\n", wire.c_str());
    }
}
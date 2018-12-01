#include<cstdio>
#include<map>
#include<string>
#include<iostream>
#include <cmath>
 
using namespace std;
 
map<string, int> cards;
map<int, int> points;

int main() {
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
    cards["JD"] = 11;
    cards["QD"] = 12;
    cards["KD"] = 13;
    cards["AC"] = 14;
    cards["2C"] = 15;
    cards["3C"] = 16;
    cards["4C"] = 17;
    cards["5C"] = 18;
    cards["6C"] = 19;
    cards["7C"] = 20;
    cards["8C"] = 21;
    cards["9C"] = 22;
    cards["TC"] = 23;
    cards["JC"] = 24;
    cards["QC"] = 25;
    cards["KC"] = 26;
    cards["AH"] = 27;
    cards["2H"] = 28;
    cards["3H"] = 29;
    cards["4H"] = 30;
    cards["5H"] = 31;
    cards["6H"] = 32;
    cards["7H"] = 33;
    cards["8H"] = 34;
    cards["9H"] = 35;
    cards["TH"] = 36;
    cards["JH"] = 37;
    cards["QH"] = 38;
    cards["KH"] = 39;
    cards["AS"] = 40;
    cards["2S"] = 41;
    cards["3S"] = 42;
    cards["4S"] = 43;
    cards["5S"] = 44;
    cards["6S"] = 45;
    cards["7S"] = 46;
    cards["8S"] = 47;
    cards["9S"] = 48;
    cards["TS"] = 49;
    cards["JS"] = 50;
    cards["QS"] = 51;
    cards["KS"] = 52;
    
    while(true) {
            char hand [13][4];
            if(scanf("%s %s %s %s %s %s %s %s %s %s %s %s %s", hand[0], hand[1], 
                hand[2], hand[3], hand[4], hand[5], hand[6], hand[7], hand[8], 
                hand[9], hand[10], hand[11], hand[12]) == EOF) {
                    break;
                }
        
        int points = 0;
        int hearts, spades, clubs, diamonds;
        bool stoph, stops, stopc, stopd;
        stoph = false;
        stops = false;
        stopc = false;
        stopd = false;
        hearts = 0;
        spades = 0;
        clubs = 0;
        diamonds = 0;
        for(int i = 0; i < 13; i++) {
            if(cards[hand[i]] < 14) {
                    diamonds = diamonds + 1;
            }else if(cards[hand[i]] < 27) {
                clubs = clubs + 1;
            }else if(cards[hand[i]] < 40) {
                hearts = hearts + 1;
            } else {
                spades = spades + 1;
            }
            //printf("diamonds %d clubs %d hearts %d spades %d\n", diamonds, clubs, hearts, spades);
        }
        for(int i = 0; i < 13; i++) {
            if(cards[hand[i]] == 1 || cards[hand[i]] == 14 || 
                cards[hand[i]] == 27 || cards[hand[i]] == 40) {
                    points += 4;

                if(cards[hand[i]] < 14) {
                    stopd = true;
                }else if(cards[hand[i]] < 27) {
                    stopc = true;
                }else if(cards[hand[i]] < 40) {
                    stoph = true;
                } else {
                    stops = true;
                }
            }
            if(cards[hand[i]] == 13 || cards[hand[i]] == 26 || 
                cards[hand[i]] == 39 || cards[hand[i]] == 52) {
                    points += 3;
                
                if(cards[hand[i]] < 14) {
                    if(diamonds == 0) {
                        --points;
                    }else {
                        stopd = true;
                    }
                }else if(cards[hand[i]] < 27) {
                    if(clubs == 0) {
                        --points;
                    } else {
                        stopc = true;
                    }
                }else if(cards[hand[i]] < 40) {
                    if(hearts == 0) {
                        --points;
                    } else {
                        stoph = true;
                    }
                } else if(spades == 0) {
                    --points;
                } else {
                    stops = true;
                }
            }
            if(cards[hand[i]] == 12 || cards[hand[i]] == 25 || 
                cards[hand[i]] == 38 || cards[hand[i]] == 51) {
                    points += 2;

                if(cards[hand[i]] < 14) {
                    if(diamonds <= 1) {
                        --points;
                    } else {
                        stopd = true;
                    }
                }else if(cards[hand[i]] < 27) {
                    if(clubs <= 1) {
                        --points;
                    } else {
                        stopc = true;
                    }
                }else if(cards[hand[i]] < 40) {
                    if(hearts <= 1) {
                        --points;
                    } else {
                        stoph = true;
                    }
                } else if(spades <= 1) {
                    --points;
                } else {
                    stops = true;
                }
            }
            if(cards[hand[i]] == 11 || cards[hand[i]] == 24 || 
                cards[hand[i]] == 37 || cards[hand[i]] == 50) {
                    points += 1;

                if(cards[hand[i]] < 14 && diamonds <= 2) {
                    --points;
                }else if(cards[hand[i]] < 27 && clubs <= 2) {
                    --points;
                }else if(cards[hand[i]] < 40 && hearts <= 2) {
                    --points;
                } else if(spades <= 2) {
                    --points;
                }
            }
        }        

        //printf("The hand has %d points\n", points);
        if(points >= 16 && stopc && stopd && stoph && stops) {
            printf("BID NO-TRUMP\n");
        } else {
            if(hearts < 2) points += 2;
            if(spades < 2) points += 2;
            if(clubs < 2) points += 2;
            if(diamonds < 2) points += 2;

            if(hearts == 2) points += 1;
            if(spades == 2) points += 1;
            if(clubs == 2) points += 1;
            if(diamonds == 2) points += 1;
            //printf("Now the hand has %d points\n", points);
            if(points < 14) {
                printf("PASS\n");
            } else {
                int max = fmax(clubs, fmax(hearts, fmax(diamonds, spades)));
                string res;
                //printf("stops %d %d %d %d", stopc, stopd, stoph, stops);
                if(max == clubs) res = "C";
                if(max == diamonds) res = "D";
                if(max == hearts) res = "H";
                if(max == spades) res = "S";
                printf("BID %s\n", res.c_str());
            }
        }
    }
    return 0;
}
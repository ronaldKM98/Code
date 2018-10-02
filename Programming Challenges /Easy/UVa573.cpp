#include <cstdio>

using namespace std;

int
main() {
    double H, dailyClimb, down, fatigueFactor;
    
    while(true){
        scanf("%lf %lf %lf %lf", &H, &dailyClimb, &down, &fatigueFactor);
        double fatigue = dailyClimb * (fatigueFactor / 100);
        if(H == 0) break;
        double d = 0;
        int days = 0;
        while(true){
            days++;
            //Day
            d = d + dailyClimb;
            if(d > H) {
                printf("success on day %d\n", days);
                break;
            }
            //Night
            d = d - down;
            if(d < 0) {
                printf("failure on day %d\n", days);
                break;
            }
            dailyClimb = dailyClimb - fatigue;
            if(dailyClimb < 0) {
                dailyClimb = 0;
            }
        }
    }
    return 0;
}
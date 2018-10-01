#include <cstdio>

using namespace std;

int
main() {
    int duration, nEntries, month;
    float downPayment, amount, depreciation;
    while(scanf("%d %f %f %d", &duration, &downPayment, &amount, &nEntries) == 4) {
        if(duration < 0) {
            break;
        } else {
            float carValue = amount + downPayment;
            float owe = amount;
            int months = 1;
            scanf("%d %f", &month, &depreciation);
            carValue = carValue - (carValue * depreciation);
            int lastMonth = 0;
            int lastDepreciation = depreciation;
            while(nEntries--) {
                scanf("%d %f", &month, &depreciation);
                while(month != lastMonth + 1) {
                    owe = owe - downPayment;
                    carValue = carValue - (carValue * lastDepreciation);
                    lastMonth++;
                    months++;
                    if(carValue > owe) break;
                }
                if(carValue > owe) {
                    printf("%s\n", "Salio por 1");
                    printf(lastMonth > 1 ? "%d months" : "1 month", lastMonth);
                    break;
                }
                owe = owe - downPayment;
                carValue = carValue - (carValue * depreciation);
                lastMonth++;
                months++;
                if (month != lastMonth) printf("%s", "NotCool");
                lastDepreciation = depreciation;
                if(carValue > owe) {
                    printf("%s\n", "Salio por 2");
                    printf(months > 1 ? "%d months" : "1 month", months);
                    break;
                }
            }
            if(carValue <= owe) {
                int i;
                for(i = months; i <= duration; i++) {
                    owe = owe - downPayment;
                    carValue = carValue - (carValue * depreciation);
                    months++;
                    if(carValue > owe) {
                        printf("%s\n", "Salio por 3");
                        printf(months > 1 ? "%d months" : "1 month", months);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
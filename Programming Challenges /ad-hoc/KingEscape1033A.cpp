#include <cstdio>

using namespace std;

int 
main() {
	int n, ax, ay, bx, by, cx, cy;
	scanf("%d", &n);
	scanf("%d %d", &ax, &ay);
	scanf("%d %d", &bx, &by);
	scanf("%d %d", &cx, &cy);
	//bx = bx - ax;
	//by = by - ay;
	//cx = cx - ax;
	//cy = cy - ay;
	//ax = 0;
	//ay = 0;
	if((bx > ax && cx > ax) && (by > ay && cy > ay)) {
		printf("YES\n");
	} else if((bx < ax && by > ay) && (cx < ax && cy > ay)) {
		printf("YES\n");
	} else if((bx > ax && by < ay) && (cx > ax && cy < ay)) {
		printf("YES\n");
	} else if((bx < ax && by < ay) && (cx < ax && cy < ay)) {
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	return 0;
}
#include<stdio.h>

int main() {
    int T, x, y, step, len, i = 0, j;
    len = T;
    scanf("%d", &T);
    if ( T < 1 && T > 1000) {
        return 0;
    }
    int res[T];
    
    while(T!=0) {
        scanf("%d %d", &x, &y);
        if(x<-1000 && x>1000 && y<-1000 && y>1000) {
        	return 0;
		}
        step = 0;
        while( x != y) {
            if (x<y) {
                x = x + 2;
                step += 1;
            }
            else if (x>y) {
                x = x - 1;
                step += 1;
            }
        }
        res[i] = step;
        i = i + 1;
    	T = T - 1;
    }
    
    for (j = 0; j<i; j++) {
    	printf("%d\n", res[j]);
	}
	
	return 0;
}

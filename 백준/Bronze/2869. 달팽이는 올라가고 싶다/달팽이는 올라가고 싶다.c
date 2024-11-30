#include <stdio.h>

int main() {

    int A, B, V = 0;
    scanf("%d %d %d",&A, &B, &V);

    int day = 0;
    V = V - A;
    
    day += V /(A - B);
    if ( V % (A -B) > 0){
        day++;
    }

    day++;
    printf("%d", day);
    
    return 0;
}
    
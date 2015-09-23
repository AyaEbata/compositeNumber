#include <stdio.h>
#include <stdlib.h>

void multiplication(int x);
int a = 2, b = 2, c = 2, count = 0;

int main(void){
    char str[1024];

    while(fgets(str, sizeof(str), stdin) != NULL){
        multiplication(atoi(str));
        printf("STDOUT: %d\n", count);
        a = 2;
        b = 2;
        c = 2;
        count = 0;
    }
    
    return 0;
}

void multiplication(int x) {
    int i, mVal;
    
    if (a * b * c > x) {
        return;
    }
    
    for (c = c; c <= 9; c++) {
        mVal = a * b * c;
        count++;
  
//        printf("a=%d b=%d c=%d mVal=%d count=%d\n", a, b, c, mVal, count);

        if (mVal > x) {
            count--;
            b++;
            c = b;

            break;
        }
    }

    if (c == 10) {
        b++;
        c = b;
        
        if (b == 10) {
            a++;
            b = a;
            c = a;
        }
    }
    
    multiplication(x);
    
    return;
}
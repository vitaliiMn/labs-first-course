//18 вариант
#include <stdio.h>

long long Pow(int k){
    long long s = 1;
    int i;

    for (i = 0; i < k; ++i) 
        s *= 10;
        
    return s;
}

int Size(long long s){
    int k = 0;

    while(s != 0){
        s = s / 10;
        ++k;
    }

    return k;
}

int main() {
    long long s, a, b;
    int k;

    while (1) {
        scanf ("%lld", &s);
        k = Size(s);

        if( k>= 3){
            b = s / Pow(k - 2);
            b = b % 10;

            s -= b * Pow(k - 2);

            a = s / 100;
            a = a % 10;

            s += (b - a) * 100;

            s += a * Pow(k - 2);

            printf("%lld\n", s);

        } else
            printf("%lld\n", s);
            
    }
    
    return 0;
}

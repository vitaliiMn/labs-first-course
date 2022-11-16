//20 вариант
#include <stdio.h>

#define maxn 100

int main() {
    int mass[maxn][maxn];
    int i, j, n, min, sum;

    scanf("%i", &n);
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            scanf("%d", &mass[i][j]);  

    for (i = 0; i < n; ++i) {
        sum = 0;
        min = mass[0][i];
        for (j = 0; j < n; ++j) {
            sum += mass[j][i];
            if (min > mass[j][i])
                min = mass[j][i];
        } 
        for (j = 0; j < n; ++j)
            if (mass[j][i] == min)
                mass[j][i] = sum;
    }
    for (i = 0; i < n; ++i){
        for (j = 0; j < n; ++j)
            printf("%d ", mass[i][j]);  
        putchar('\n');
    }        
    return 0;
}

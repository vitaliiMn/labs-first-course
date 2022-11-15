//18 вариант
#include <stdio.h>

int Check(char a) {
    int e = 0;
    if (a == 'A' || a == 'a')
        e = 1;
    if (a == 'E' || a == 'e')
        e = 2;
    if (a == 'I' || a == 'i')
        e = 4;
    if (a == 'O' || a == 'o')
        e = 8;
    if (a == 'U' || a == 'u')
        e = 16;
    if (a == 'Y' || a == 'y')
        e = 32;
    return e;
}

int main() {
    short int start = 1, final = 0, bool1 = 0;
    int s, first = 0, second = 0;
    char a;
    while (1) {
        a = getchar();
        if (final) {
            if (a == EOF) 
                break;
            continue;       
        }

        if (a == ' ' || a == ',' || a == '\t' || a == '\v' || a == '\n' || a == EOF) {   
            if (bool1) {
                bool1 = 0;
                if (a == ' ' || a == ',' || a == '\n') {

                    if (start) 
                        start = 0;
                    else 
                        if ((first & second) == 0)  
                            final = 1;       

                    second = first;
                    first = 0;   
                } else {     
                    if (!start) 
                        if ((first & second) == 0)
                            final = 1;                
                    if (a == EOF) 
                        break;    
                    second = first = 0;
                    start = 1; 
                }
            } else
                if (a == EOF)
                    break;  
        } else {
            bool1 = 1;
            s = Check(a);
            if ((s & first) == 0) 
                first += s; 
        }
    }
    if (final) 
        printf("YES\n");
    else 
        printf("NO\n");
    return 0;
}

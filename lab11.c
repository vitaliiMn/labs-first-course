// 18 вариант
#include <stdio.h>

int Check (char a){
    
    int i;
    char q;

    for(i = 0; i <= 9; ++i){
        q = i+'0';
        if (a == q){
            return i;
        }
    }

    if(a == '.'){
        return 10;
    }

    return -1;
}

double Pow (int k){
    
    int i;

    double s = 1;

    for (i = 0; i < k; ++i){
        s = s / 10;
    }

    return s;
}

void Fahrenheit (double s){

    s= s * 9 / 5 + 32;

    printf ("%g", s);
    printf ("F");

}

int main() {
    short int bool1 = 0, bool2 =0, printCheck =0, arithmeticSign = 0;
    char a, e = ' ';
    int symbol, k=0;
    double s = 0;

    while ( 1 ){

    a = getchar ();

    if (a == EOF) {
        if (printCheck == 1){
            if (arithmeticSign == 1){
            Fahrenheit (s*(-1));
            } else
            Fahrenheit (s);

        } else{
            if (arithmeticSign == 0){
            printf ("%g", s);
            } else {
            printf ("%g", s*(-1));
            }
                
            putchar('C');
        }                
    break;
    }

        if (a == '-' && e == ' '){
            if(arithmeticSign == 0){
            arithmeticSign = 1;
            continue;
            } else{
                e = a;
            }
        }

        if (printCheck == 1 && (a == ' '||a == '\n')){

            if (arithmeticSign == 1){
            Fahrenheit (s*(-1));
            } else
            Fahrenheit (s);

            putchar (a);

            e = a;
            if (e == '\n'){
                e = ' ';
            }

            arithmeticSign = printCheck = bool1 = bool2 = s = k = 0;
            continue;
        } 

        if (printCheck == 1){
                if (arithmeticSign == 0){
                printf ("%g", s);
                } else {
                printf ("%g", s*(-1));
                }
                
                putchar('C');
                putchar(a);

                e=a;

                printCheck = arithmeticSign = bool1 = bool2 = s = k = 0;
                continue;
        }
              
    symbol = Check (a);

    if (symbol == -1){

        if (bool1 == 0){
            if(arithmeticSign ==1)
            putchar('-');

            arithmeticSign = 0;

            putchar (a);
            e = a;
              if (e == '\n'){
                e = ' ';
            }
            continue;
        } 

        if (bool1 == 1){
            if (a == 'C'){
              printCheck = 1;

            } else {
                if(arithmeticSign == 0){
                printf ("%g", s);
                } else{
                printf ("%g", s*(-1));
                }
                putchar(a);
                e = a;
                  if (e == '\n'){
                e = ' ';
            }
                arithmeticSign = 0;
                bool1 = bool2 = s = k = 0;
            }
        }
        
    } else {

        if (e == ' ')
        bool1 = 1;

        if (bool1 == 0){
            if(arithmeticSign == 1){
                putchar('-');
                arithmeticSign = 0;
            }
            putchar(a);
        } 

        if (bool1 == 1){

        if (symbol!= 10){

            if (bool2 == 0){
                
            s *= 10;
            s += symbol;
            
            } 
            
            else {

                 ++k;
            s += symbol* Pow (k);

            }

        } 
        
        else {
            if (bool2 == 1){
                if(arithmeticSign == 1){
                putchar('-');
                arithmeticSign = 0;
                }
                printf ("%g", s);
                putchar(a);

                bool1 = bool2 = s = k = 0;
                e=a;
                  if (e == '\n'){
                    e = ' ';
                  }
                continue;
            }

            bool2 = 1;

            ++k;
            s += symbol * Pow (k);

        }

        }
    }
    
    e = a;

    if (e == '\n'){
      e = ' ';
        }
    }
    return 0;
}

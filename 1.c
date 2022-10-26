#include <stdio.h>

const int i0 = 6;
const int ji = 2;
const int l0 =-15;
 int i,j,l;
 int x=-10,y=-10,x2=-20,y2=-20,r=10;

void MOVE(int k){
    int inew,jnew,lnew;
    int v1,v2,v3;

    inew=(i*i*i-j*j*j+l*l*l-k)%20;
    v1=i*j*l-k;
    v2=i*i*l-k;
    v3=j*l*l-k;

    int max,min;
    max=v1;
    min=v1;
    if(v2>max)
        max=v2;
    if(v3>max)
        max=v3;
    if(v2<min)
        min=v2;
    if(v3<min){
        min=v3;
    }
    jnew=min%30;
    lnew=max%30;
    
    i=inew;
    j=jnew;
    l=lnew;
}
int CHECK(int k){
    if(((i-x)*(i-x)+(j-y)*(j-y)<=r*r) && ((i-x2)*(i-x2)+(j-y2)*(j-y2)<=r*r)){
        return 1;
    }
    return 0;
}
int main (){

    i=i0;
    j=ji;
    l=l0;
    int k=0;

    while(k<=50){
        if(CHECK(k)){
             printf("попадание\n");
             printf("координа абсцисс %d\n",i);
             printf("координа ординат %d\n",j);
             printf("параметр движениея %d\n",l);
             printf("число интераций %d\n",k);
             return 0;
        }
        MOVE(k);
        ++k;
    }
    
    printf("число интераций %d\n",k-1);
    printf ("промах\n");
    printf("координа абсцисс %d\n",i);
    printf("координа ординат %d\n",j);
    printf("параметр движениея %d\n",l);
  return 0;
}

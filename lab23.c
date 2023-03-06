#include <stdio.h>
#include <string.h>

#define N 1000

struct vec2d {
    long long prew;  // ссылка на предыдущую вершину
    long long next1, next2; // сслылка на последующую вершину
    long long wal; // значение вершины 
};

long long CalcHeight(struct vec2d *mass,long long u, long long kol) {
    if(mass[u].prew == u){
        return kol;
    } else {
        return CalcHeight(mass, mass[u].prew, kol + 1);
    }
}

long long Check(struct vec2d *mass){
    long long i;
    long long now, prew;
    prew = -1;
    for(i = 0; i < N; ++i) {
        if(mass[i].next1 == -1 && mass[i].next2 == -1 && mass[i].prew != -1) { 
            now = CalcHeight(mass, i, 0);
            //printf("now = %lld\n", now);
            if(now != prew && prew != -1) {
                return -2;
            }
            prew = now;
        }
    }
    return now;
}

int main() {   
    struct vec2d mass[N];

    for(long long i = 0; i < N; ++i) {
        mass[i].prew = -1;
        mass[i].next1 = -1;
        mass[i].next2 = -1;
        mass[i].wal = -1;
    }
    mass[0].wal = 0;
    mass[0].prew = 0;

    printf("введети желаемое действие над деревом\n");
  
    // можно ввести "insert" - добавить элемент, "erase" - удалить элемент, "show", "check"
    // после первого нужно предыдущую вершину, текущую и значение текущей
    // после второго аналогично
    // третье и четвертое дальнейшего ввода не требуют
    // check проверит наличие всех листьев на одном уровне и в случае успеха выведит их глубину, иначе -1
    // show визуализирует граф в виде списка смежности

    char str[10];

    while(scanf("%s",str) == 1) {

        long long u, v, wal ;

        if(strcmp(str, "insert") == 0) {
            scanf("%lld %lld %lld", &u, &v, &wal);
            --u;
            --v;
            if(u == v) {
                printf("ошибка ввода\n");
            } else { 
                if((mass[u].next1 != -1 && mass[u].next2 != -1) || (mass[u].prew == -1) || (mass[v].prew != -1) ) {
                    printf("невозможно добавить \n");
                } else{
                    if(mass[u].next1 == -1 && mass[u].next2 == -1 ) {
                        mass[u].next1 = v;
                        mass[v].wal = wal;
                        mass[v].prew = u;
                    } else {
                        if(mass[u].next1 != -1 && mass[u].next2 != v) {
                            long long w = mass[mass[u].next1].wal;
                            if(w > wal) {
                                mass[u].next2 = mass[u].next1;
                                mass[u].next1 = v;
                                mass[v].wal = wal;
                                mass[v].prew = u;
                            } else {
                                mass[u].next2 = v;
                                mass[v].wal = wal;
                                mass[v].prew = u;
                            }
                        } else {
                            if(mass[u].next2 != -1 && mass[u].next1 != v) {
                                long long w = mass[mass[u].next2].wal;
                                if(w > wal) {
                                    mass[u].next1 = v;
                                    mass[v].wal = wal;
                                    mass[v].prew = u;
                                } else {
                                    mass[u].next1 = mass[u].next2;
                                    mass[u].next2 = v;
                                    mass[v].wal = wal;
                                    mass[v].prew = u;
                                }
                            } else {
                                printf("ошибка ввода\n");
                            }
                        }
                    }
                }
            }
        }

        if(strcmp(str, "erase") == 0) {
            scanf("%lld %lld %lld", &u, &v, &wal);
            --u;
            --v;
            if(u == v) {
                printf("ошибка ввода\n");
            } else{
                if(mass[v].next1 != -1 || mass[v].next2 != -1) {
                    printf("невозможно удалить \n");
                } else {
                    if(mass[u].next1 == v ) {
                        mass[v].prew = -1;
                        mass[u].next1 = -1;
                    } else {
                        if(mass[u].next2 == v) {
                            mass[v].prew = -1;
                            mass[u].next2 = -1;
                        } else {
                            printf("не корректный ввод\n");
                        }
                    }
                }
            }
        }

        if(strcmp(str, "show") == 0) {
            printf("вывод\n");
            for(long long i = 1;i < 100; ++i ) {
                if(mass[i].prew != -1)
                    printf("%lld %lld %lld\n", mass[i].prew + 1, i + 1, mass[i].wal);
            }
            printf("конец вывода\n");
        }

        if(strcmp(str, "check") == 0) {
            printf("%lld\n", Check(mass) + 1);
        }
    }

    return 0;
}

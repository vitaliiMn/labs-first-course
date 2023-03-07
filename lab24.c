#include <stdio.h>
#include <string.h>

#define N 1000

struct vec2d {
    int prew;  // ссылка на предыдущую вершину
    int next1, next2; // сслылка на последующую вершину
    char wal; // значение вершины 
};

struct stack {
    char mass[N];
    int top;
};

struct output {
    char mass[N];
    int poz;
};

void PushUt(struct output *out, char a) {
    out->mass[out->poz] = a;
    ++out->poz;

}

int Empty(struct stack *st) {
    if(st->top == 0) {
        return 1;
    } else {
        return 0;
    }
}

void Push(struct stack *st, char a) {
    if(st->top != N) {
        st->mass[st->top] = a;
        ++st->top;
    }
}

void Pop(struct stack *st) {
    --st->top;
}

char Top(struct stack *st) {
    char a = st->mass[st->top - 1];
    return a;
}

int ValueOperator(char a) {
    if(a == '*' || a == '/') {
        return 2;
    }
    if(a == '+' || a == '-') {
        return 1;
    }
    return -1;
}

void InfixConversionToPostfix(char *infix, char *postfix, int n) {
    struct stack st;
    st.top = 0;
    struct output out;
    out.poz = 0;
    for(int i = 0; i < n; ++i) {
        char a = infix[i];
        if(a >= '0'&& a <= '9') {
            PushUt(&out, a);
        } else {
            if(Empty(&st)) {
                Push(&st, a);            
            } else {        
                if(ValueOperator(a) > ValueOperator(Top(&st))) {
                    Push(&st, a);
                } else {
                    while(ValueOperator(a) <= ValueOperator(Top(&st))&& !Empty(&st)) {
                        PushUt(&out, Top(&st));
                        Pop(&st);
                    }

                    Push(&st, a);
                }
            }
        }
    }

    while(st.top != 0) {
        char a = Top(&st);
        PushUt(&out, a);
        --st.top;
    }
    for(int i = 0; i < n; ++i) {
        postfix[i] = out.mass[i];
    }
}

void PostfixConversationToTree(struct vec2d *mass, struct stack *st, int nownumber, int prew, int n) {
    //printf("now = %c\n", Top(st));
    char a = Top(st);
    Pop(st);
    mass[nownumber].wal = a;
    mass[nownumber].prew = prew;
    if(a >= '0' && a <= '9') {
        return;
    }
    char c = Top(st);
    if(c >= '0' && c <= '9') {
        mass[nownumber].next2 = n + st->top;     
        mass[n + st->top].prew = nownumber;
        mass[n + st->top].wal = c;
        Pop(st);
    } else {
        mass[nownumber].next2 = n - st->top;
        PostfixConversationToTree(mass, st, n - st->top, nownumber, n);
    }
    c = Top(st);
    if(c >= '0' && c <= '9') {
        mass[nownumber].next1 = n + st->top;   
        mass[n + st->top].prew = nownumber;
        mass[n + st->top].wal = c;
        Pop(st);
    } else {
        mass[nownumber].next1 = n - st->top;
        PostfixConversationToTree(mass, st, n - st->top, nownumber, n);
    }
}

void EraseNull(struct vec2d *mass) {
    for(int i = 0; i < N; ++i) {
        if(mass[i].next1 == -1 && mass[i].next2 == -1 && mass[i].wal == '0') {
            int u = i;
            int v = i;
            while(mass[u].prew != u && (mass[u].wal == '*' || mass[u].wal == '/' || mass[u].wal == '0')) {
                u = mass[u].prew;
                if(v == mass[u].next1) {
                    mass[u].next1 = -1;
                } else {
                     mass[u].next2 = -1;
                }
                mass[v].prew = -1;
                v = u;
            }
            mass[u].wal = 't';
        }
    }
}

void dfs(struct vec2d *mass, int i) {
    if(i == -1) {
        return;
    }
    dfs(mass, mass[i].next1);
    if(mass[i].wal != 't') {
        printf("%c", mass[i].wal);
    }
    dfs(mass, mass[i].next2);
}

int main() {
    printf("введите длину строки и арифметическое выражение\n");
    int n;
    scanf("%d", &n);
    char infix[N];
    char postfix[N];

    scanf("%s", infix);
    InfixConversionToPostfix(infix, postfix, n);

    struct vec2d mass[N];

    for(int i = 0; i < N; ++i) {
        mass[i].prew = -1;
        mass[i].next1 = -1;
        mass[i].next2 = -1;
        mass[i].wal = -1;
    }

    struct stack st;

    for(int i = 0; i < n; ++i) {
        Push(&st, postfix[i]);
        //printf("%c ",postfix[i]);
    }

    PostfixConversationToTree(mass, &st, 0, 0, n);

     for(int i = 0; i < N; ++i) {
        if(mass[i].prew != -1) {
            //printf(" %d %d %d %d %c \n",i, mass[i].prew, mass[i].next1, mass[i].next2 , mass[i].wal);
        }
    }

    EraseNull(mass);

    for(int i = 0; i < N; ++i) {
        if(mass[i].prew != -1) {
            //printf("%d %d %d %c \n",i, mass[i].next1, mass[i].next2 , mass[i].wal);
        }
    }
    dfs(mass, 0);

    return 0;
}

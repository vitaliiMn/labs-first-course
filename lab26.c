#include <stdio.h>

#define N 1000
#define inf 1e9

struct queue {
    int mass[N];
    int first, last;
    int quantity;
};

int Empty(struct queue *q) {
    if(q->quantity == 0) {
        return 1;
    }
    return 0;
}

void Announce(struct queue *q) {
    q->first = 0;
    q->last = -1;
    q->quantity = 0;
}

void Reinqueue(struct queue *q) {
    int k = q->first;
    for(int i = 0; i < q->quantity; ++i) {
        q->mass[i] = q->mass[i + k];
    }
    q->first = 0;
    q->last = q->quantity - 1;
}

void Push(struct queue *q, int el) {
    if(q->last != N - 1) {
        ++q->last;
        q->mass[q->last] = el;
        ++q->quantity;
    } else {
        if(q->first != 0) {
            Reinqueue(q);
            ++q->last;
            q->mass[q->last] = el;
            ++q->quantity;
        }
    }
}

void Pop(struct queue *q) {
    if(q->first != N - 1) {
        ++q->first;
        --q->quantity;
    }
}

int Back(struct queue *q) {
    if(!Empty(q)) {
        return q->mass[q->last];
    }
}

int Front(struct queue *q) {
    if(!Empty(q)) {
    return q->mass[q->first];
    }
}

int Size(struct queue *q) {
    return q->quantity;
}

void Sort(struct queue *q) {
    struct queue q2;
    Announce(&q2);
    int n = Size(q);
    for(int i = 0; i < n; ++i) {
        int minel = inf;
        for(int j = 0; j < Size(q); ++j) {
            int el = Front(q);  
            if(el < minel) {
                minel = el;
            }
            Pop(q);
            Push(q, el);
        }
        while(minel != Front(q)) {
            int el = Front(q);
            Pop(q);
            Push(q, el);
        }    
        Push(&q2, Front(q));
        Pop(q);
    }
    for(int i = 0; i < n; ++i) {
        Push(q, Front(&q2));
        Pop(&q2);
    }
}

int main() {
    struct queue q;
    Announce(&q);
    Push(&q, 9);
    Push(&q, 1);
    Push(&q, 5);
    Push(&q, 3);
    Push(&q, 5);
    Push(&q, 3);
    Sort(&q);
    while(!Empty(&q)) {
        printf("%d ", Front(&q));
        Pop(&q);
    }
    printf("\n");

    return 0;
}

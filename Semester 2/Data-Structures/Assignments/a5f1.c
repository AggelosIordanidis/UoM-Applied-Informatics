#include <stdio.h>
#include <stdbool.h>
#define megisto_plithos 1001
typedef bool typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;
void Dimiourgia(typos_synolou synolo);
void Katholiko(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
void Diagrafi(stoixeio_synolou stoixeio, typos_synolou synolo);
bool Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
bool KenoSynolo(typos_synolou synolo);
bool IsaSynola(typos_synolou s1, typos_synolou s2);
bool Yposynolo(typos_synolou s1, typos_synolou s2);
void EnosiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou enosi);
void TomiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou tomi);
void DiaforaSynolou(typos_synolou s1, typos_synolou s2, typos_synolou diafora);
void createFibonacciSet(int max, typos_synolou s);
int main() {
    typos_synolou fibSet;
    int max_val, num;
    printf("Dwse to megistoarithmo. ");
    scanf("%d", &max_val);
    createFibonacciSet(max_val, fibSet);
    for (int i = 0; i <= max_val; i++) {
        if (Melos(i, fibSet)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    while (1) {
        printf("Enter number to check: ");
        scanf("%d", &num);
        if (num < 0) break;
        if (num < megisto_plithos && Melos(num, fibSet))
            printf("Fibonacci!\n");
        else
            printf("Not Fibonacci...\n");
    }
    return 0;
}
void Dimiourgia(typos_synolou synolo) {
    stoixeio_synolou i;
    for (i = 0; i < megisto_plithos; i++)
    synolo[i] = false;
}
void Katholiko(typos_synolou synolo) {
    stoixeio_synolou i;
    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = true;
}
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo) {
    synolo[stoixeio] = true;
}
void Diagrafi(stoixeio_synolou stoixeio, typos_synolou synolo) {
    synolo[stoixeio] = false;
}
bool Melos(stoixeio_synolou stoixeio, typos_synolou synolo) {
    return synolo[stoixeio];
}
bool KenoSynolo(typos_synolou synolo) {
    stoixeio_synolou i;
    bool keno;
    keno=true;
    i = 0;
    while (i < megisto_plithos  && keno) {
        if (Melos(i, synolo))
            keno = false;
        else
            i++;
    }
    return keno;
}
bool IsaSynola(typos_synolou s1, typos_synolou s2) {
    stoixeio_synolou i;
    bool isa;
    isa = true;
    i=0;
    while (i < megisto_plithos && isa)
        if (Melos(i,s1) != Melos(i,s2))
            isa = false;
        else
            i++;
    return isa;
}
bool Yposynolo(typos_synolou s1, typos_synolou s2) {
    stoixeio_synolou i;
    bool yposyn;
    yposyn = true;
    i=0;
    while (i < megisto_plithos && yposyn)
        if (Melos(i, s1) && !Melos(i, s2))
            yposyn = false;
        else
            i++;
    return yposyn;
}
void EnosiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou enosi) {
    stoixeio_synolou i;
    for (i = 0; i < megisto_plithos; i++)
        enosi[i] = Melos(i, s1) || Melos(i, s2);
}

void TomiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou tomi) {
    stoixeio_synolou i;
    for (i = 0; i < megisto_plithos; i++)
        tomi[i] = Melos(i, s1) && Melos(i, s2);
}
void DiaforaSynolou(typos_synolou s1, typos_synolou s2, typos_synolou diafora) {
    stoixeio_synolou i;
    for (i = 0; i < megisto_plithos; i++)
        diafora[i] = Melos(i, s1) && (!Melos(i, s2));
}
void createFibonacciSet(int max, typos_synolou s) {
    int f1 = 0, f2 = 1, next = 0;
    Dimiourgia(s);
    if (max >= 0) Eisagogi(f1, s);
    if (max >= 1) Eisagogi(f2, s);
    next = f1 + f2;
    while (next <= max) {
        Eisagogi(next, s);
        f1 = f2;
        f2 = next;
        next = f1 + f2;
    }
}

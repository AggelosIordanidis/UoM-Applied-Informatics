#include <stdio.h>
#include <stdbool.h>
#define megisto_plithos 256
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
void EmfanisiSynolou(typos_synolou s);
int main() {
    typos_synolou Universal, S, T, Result;
    Dimiourgia(Universal);
    Katholiko(Universal);
    EmfanisiSynolou(Universal);
    Dimiourgia(S);
    Eisagogi('A', S); Eisagogi('B', S); Eisagogi('C', S); Eisagogi('D', S);
    EmfanisiSynolou(S);
    Dimiourgia(T);
    Eisagogi('A', T); Eisagogi('C', T); Eisagogi('E', T); Eisagogi('G', T); Eisagogi('I', T);
    EmfanisiSynolou(T);
    if (IsaSynola(S, T)) printf("ISA SYNOLA\n"); else printf("NOT ISA SYNOLA\n");
    if (Yposynolo(S, T)) printf("S YPOSYNOLO T\n"); else printf("NOT S YPOSYNOLO T\n");
    if (Yposynolo(T, S)) printf("T YPOSYNOLO S\n"); else printf("NOT T YPOSYNOLO S\n");
    EnosiSynolou(S, T, Result);
    EmfanisiSynolou(Result);
    TomiSynolou(S, T, Result);
    EmfanisiSynolou(Result);
    DiaforaSynolou(S, T, Result);
    EmfanisiSynolou(Result);
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
void EmfanisiSynolou(typos_synolou s) {
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < 26; i++) {
        if (Melos(alphabet[i], s)) {
            printf("%c ", alphabet[i]);
        }
    }
    printf("\n");
}

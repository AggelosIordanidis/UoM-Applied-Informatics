#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define StackLimit 50
typedef int StackElementType;
typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;
void CreateStack(StackType *Stack);
bool EmptyStack(StackType Stack);
bool FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void menu(int *choice);
void TraverseStack(StackType Stack);
StackElementType GetNthElementA (StackType *Stack, int n);
StackElementType GetNthElementB(StackType *Stack, int n);

int main() {
    StackType AStack;
    StackElementType x;
    int n, i;
    CreateStack(&AStack);
    for (i = 2; i <= 50; i += 2) {
        Push(&AStack, i);
    }
    TraverseStack(AStack);
    do {
        printf("Dwse n: ");
        scanf("%d", &n);
    } while (n <= 0 || n > (AStack.Top + 1));
    x = GetNthElementA(&AStack, n);
    printf("Nth element with GetNthElementA = %d\n", x);
    TraverseStack(AStack);
    x = GetNthElementB(&AStack, n);
    printf("Nth element with GetNthElementB = %d\n", x);
    TraverseStack(AStack);
    return 0;
}

void CreateStack(StackType *Stack) {
    Stack -> Top = -1;
}

bool EmptyStack(StackType Stack) {
    return (Stack.Top == -1);
}

bool FullStack(StackType Stack) {
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item) {
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item) {
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

void menu(int *choice) {
  printf("XRHSIMOPOIHSE TIS PARAKATW ENTOLES GIA NA ELEGJEIS TO unit StackADT\n");
  printf("1 ---- DHMIOYRGIA STOIBAS\n");
  printf("2 ---- ADEIASMA THS STOIBAS\n");
  printf("3 ---- ELEGXOS KENHS STOIBAS\n");
  printf("4 ---  POP STOIXEIOY APO TH KORYFH THS STOIBA\n");
  printf("5 ---  PUSH STH KORYFH THS STOIBAS\n");
  printf("6 ---- EMFANISH STOIXEIWN STOIBAS (BOH8HTHKH)\n");
  printf("7 ---- EXIT\n");
  printf("Choice 1-7: ");
  do {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>7);
}

void TraverseStack(StackType Stack) {
    int i;
    printf("plithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}

StackElementType GetNthElementA(StackType *Stack, int n) {
  StackElementType nelement, item;
  StackType tempS;
  CreateStack(&tempS);
  for (int i=0; i<n; i++) {
    Pop(Stack, &item);
    Push(&tempS, item);
  }
  nelement = item;
  while (!EmptyStack(tempS)) {
    Pop(&tempS, &item);
    Push(Stack, item);
  }
  return nelement;
}

StackElementType GetNthElementB(StackType *Stack, int n) {
  StackElementType item;
  for (int i=0; i<n; i++) {
    Pop(Stack, &item);
  }
  return item;
}

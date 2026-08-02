#include <stdio.h>
#include <stdbool.h>
#define StackLimit 20

typedef int StackElementType;
typedef struct {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

void CreateStack(StackType *Stack);
bool EmptyStack(StackType Stack);
bool FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);

int main () {
  StackType AStack, tempStack;
  StackElementType x, temp, var;
  int i, n;
  CreateStack(&AStack);
  CreateStack(&tempStack);
  for (i=0; i<15; i++) {
    Push(&AStack, i*10);
  }
  TraverseStack(AStack);
  printf("Give nth element (n<=6) ");
  scanf("%d", &n);
  printf("\n");
  Pop(&AStack, &temp);
  Pop(&AStack, &x);
  printf("Question a: x=%d\n", x);
  TraverseStack(AStack);
  printf("\n");
  Pop(&AStack, &temp);
  Pop(&AStack, &x);
  Push(&AStack, x);
  Push(&AStack, temp);
  printf("Question b: x=%d\n", x);
  TraverseStack(AStack);
  printf("\n");
  for (i=1; i<=n; i++) {
    Pop(&AStack, &x);
  }
  printf("Question c: x=%d\n", x);
  TraverseStack(AStack);
  printf("\n");
  for (i = 1; i <= n; i++) {
    Pop(&AStack, &x);
    Push(&tempStack, x);
  }
  while (!EmptyStack(tempStack)) {
    Pop(&tempStack, &var);
    Push(&AStack, var);
  }
  printf("Question d: x=%d\n", x);
  TraverseStack(AStack);
  printf("\n");
  CreateStack(&tempStack);
  while (!EmptyStack(AStack)) {
    Pop(&AStack, &x);
    Push(&tempStack, x);
  }
  while (!EmptyStack(tempStack)) {
    Pop(&tempStack, &var);
    Push(&AStack, var);
  }
  printf("Question e: x=%d\n", x);
  TraverseStack(AStack);
  printf("\n");
  CreateStack(&tempStack);
  while (AStack.Top >= 2) {
    Pop(&AStack, &x);
    Push(&tempStack, x);
  }
  while (!EmptyStack(tempStack)) {
    Pop(&tempStack, &var);
    Push(&AStack, var);
  }
  printf("Question f: x=%d\n", x);
  TraverseStack(AStack);
  printf("\n");
  CreateStack(&tempStack);
  while (!EmptyStack(AStack)) {
    Pop(&AStack, &x);
    Push(&tempStack, x);
  }
  printf("Question g: x=%d\n", x);
  TraverseStack(AStack);
  printf("\n");
  return 0;
}

void CreateStack(StackType *Stack) {
    Stack->Top = -1;
}
bool EmptyStack(StackType Stack) {
    return (Stack.Top == -1);
}
bool FullStack(StackType Stack) {
    return (Stack.Top == StackLimit - 1);
}
void Push(StackType *Stack, StackElementType Item) {
    if (!FullStack(*Stack)) {
        Stack->Top++;
        Stack->Element[Stack->Top] = Item;
    }
}
void Pop(StackType *Stack, StackElementType *Item) {
    if (!EmptyStack(*Stack)) {
        *Item = Stack->Element[Stack->Top];
        Stack->Top--;
    }
}
void TraverseStack(StackType Stack) {
    int i;
    printf("plithos sto stack %d\n",Stack.Top+1);
    for (i=0; i<=Stack.Top; i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}

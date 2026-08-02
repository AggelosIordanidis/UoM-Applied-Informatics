#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int StackElementType;
typedef struct StackNode *StackPointer;
typedef struct StackNode {
  StackElementType Data;
  StackPointer Next;
} StackNode;

void CreateStack(StackPointer *Stack);
bool EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);

int main() {
  int i, n, pos;
  StackElementType AnItem, x, max;
  StackPointer AStack, TempStack, FinStack;
  CreateStack(&AStack);
  CreateStack(&TempStack);
  CreateStack(&FinStack);
  printf("PLITHOS ARITHMWN: ");
  scanf("%d", &n);
  for (i=0; i<n; i++) {
    printf("DWSE TON %do ARITHMO: ", i+1);
    scanf("%d", &AnItem);
    Push(&AStack, AnItem);
  }
  Pop(&AStack, &x);
  max = x;
  Push(&TempStack, x);
  while (!EmptyStack(AStack)) {
    Pop(&AStack, &x);
    if (x > max) {
      max = x;
    }
    Push(&TempStack, x);
  }
  pos = 1;
  while (!EmptyStack(TempStack)) {
    Pop(&TempStack, &x);
    if (x == max) {
      Push(&FinStack, pos);
    }
    pos++;
  }
  printf("O megalyteros arithmos einai: %d\n", max);
  printf("kai brisketai stis theseis:\n");
  while (!EmptyStack(FinStack)) {
    Pop(&FinStack, &x);
    printf("%d ", x);
  }
  printf("\n");
  return 0;
}

void CreateStack(StackPointer *Stack) {
  *Stack = NULL;
}
bool EmptyStack(StackPointer Stack) {
  return (Stack == NULL);
}
void Push(StackPointer *Stack, StackElementType Item) {
  StackPointer TempPtr;
  TempPtr = (StackPointer)malloc(sizeof(struct StackNode));
  TempPtr->Data = Item;
  TempPtr->Next = *Stack;
  *Stack = TempPtr;
}
void Pop(StackPointer *Stack, StackElementType *Item) {
  StackPointer TempPtr;
  if (EmptyStack(*Stack)) {
    printf("EMPTY Stack\n");
  }
  else {
    TempPtr = *Stack;
    *Item = TempPtr->Data;
    *Stack = TempPtr->Next;
    free(TempPtr);
  }
}

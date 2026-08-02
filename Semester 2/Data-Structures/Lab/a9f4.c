#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char StackElementType;
typedef struct StackNode *StackPointer;
typedef struct StackNode {
  StackElementType Data;
  StackPointer Next;
} StackNode;
typedef char QueueElementType;
typedef struct QueueNode *QueuePointer;
typedef struct QueueNode {
  QueueElementType Data;
  QueuePointer Next;
} QueueNode;
typedef struct {
  QueuePointer Front;
  QueuePointer Rear;
} QueueType;

void CreateStack(StackPointer *Stack);
bool EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);
void CreateQ(QueueType *Queue);
bool EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void TraverseStack(StackPointer Stack);
void TraverseQ(QueueType Queue);

int main() {
  StackElementType AItemS;
  int i, length;
  char str[40];
  bool flag;
  StackPointer AStack;
  QueueType AQueue;
  QueueElementType AItemQ;
  CreateStack(&AStack);
  CreateQ(&AQueue);
  printf("DWSE TO ALFARITHMITIKO: ");
  scanf("%s", str);
  length = strlen(str);
  for (i=0; i<length; i++) {
    Push(&AStack, str[i]);
    AddQ(&AQueue, str[i]);
  }
  TraverseStack(AStack);
  TraverseQ(AQueue);
  flag = true;
  while (flag && (!EmptyQ(AQueue))) {
    Pop(&AStack, &AItemS);
    RemoveQ(&AQueue, &AItemQ);
    if (AItemQ != AItemS) flag = false;
  }
  if (flag) printf("%s ACCEPTED\n", str);
  else printf("%s REJECTED\n", str);
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
void CreateQ(QueueType *Queue) {
  Queue->Front = NULL;
  Queue->Rear = NULL;
}
bool EmptyQ(QueueType Queue) {
  return (Queue.Front == NULL);
}
void AddQ(QueueType *Queue, QueueElementType Item) {
  QueuePointer TempPtr;
  TempPtr = (QueuePointer)malloc(sizeof(struct QueueNode));
  TempPtr->Data = Item;
  TempPtr->Next = NULL;
  if (Queue->Front == NULL)
    Queue->Front = TempPtr;
  else
    Queue->Rear->Next = TempPtr;
  Queue->Rear = TempPtr;
}
void RemoveQ(QueueType *Queue, QueueElementType *Item) {
  QueuePointer TempPtr;
  if (EmptyQ(*Queue)) {
    printf("EMPTY Queue\n");
  }
   else {
    TempPtr = Queue->Front;
    *Item=TempPtr->Data;
    Queue->Front = Queue->Front->Next;
    free(TempPtr);
    if (Queue->Front == NULL) Queue->Rear = NULL;
  }
}
void TraverseStack(StackPointer Stack) {
  StackPointer CurrPtr;
  if (EmptyStack(Stack)) {
    printf("EMPTY Stack\n");
  }
  else {
    printf("Stack of characters\n");
    CurrPtr = Stack;
    while (CurrPtr != NULL) {
        printf("%c ", CurrPtr->Data);
        CurrPtr = CurrPtr->Next;
    }
  }
   printf("\n");
}
void TraverseQ(QueueType Queue) {
  QueuePointer CurrPtr;
  if (EmptyQ(Queue)) {
    printf("EMPTY Queue\n");
  }
  else {
    printf("Queue of characters\n");
    CurrPtr = Queue.Front;
    while (CurrPtr != NULL) {
      printf("%c ", CurrPtr->Data);
      CurrPtr = CurrPtr->Next;
    }
   }
  printf("\n");
}

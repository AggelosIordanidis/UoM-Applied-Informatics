#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode *QueuePointer;
typedef struct {
  char surname[16], name[16], number[11];
  int ticket;
} QueueElementType;
typedef struct QueueNode {
  QueueElementType Data;
  QueuePointer Next;
} QueueNode;
typedef struct {
  QueuePointer Front;
  QueuePointer Rear;
} QueueType;

void CreateQ(QueueType *Queue);
bool EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void TraverseQ(QueueType Queue);

int main() {
  int n, i, free;
  QueueElementType temp, item;
  QueueType AQueue;
  CreateQ(&AQueue);
  printf("DWSE TO PLITHOS TWN ATOMWN: ");
  scanf("%d", &n);
  for (i=0; i<n; i++) {
    printf("DWSE ONOMA ");
    scanf("%s", temp.name);
    printf("DWSE EPITHETO ");
    scanf("%s", temp.surname);
    printf("DWSE THLEFWNO ");
    scanf("%s", temp.number);
    printf("DWSE TYPOS EISITHRIOY(0=olokliro, 1=miso): ");
    scanf("%d", &temp.ticket);
    AddQ(&AQueue, temp);
  }
  printf("Initial Queue\n");
  TraverseQ(AQueue);
  printf("DWSTE ARITHMO ELEUTHERWN THESEWN: ");
  scanf("%d", &free);
  for (i=0; i<free; i++) {
    RemoveQ(&AQueue, &item);
  }
  printf("Final Queue\n");
  TraverseQ(AQueue);
  return 0;
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
void TraverseQ(QueueType Queue) {
  QueuePointer CurrPtr;
  if (EmptyQ(Queue)) {
    printf("EMPTY Queue\n");
  }
  else {
    CurrPtr = Queue.Front;
    while (CurrPtr != NULL) {
      printf("%s, %s, %s, %d\n", CurrPtr->Data.name, CurrPtr->Data.surname, CurrPtr->Data.number, CurrPtr->Data.ticket);
      CurrPtr = CurrPtr->Next;
    }
   }
}

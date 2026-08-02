#include <stdbool.h>
#include <stdio.h>
#define QueueLimit 10

typedef int QueueElementType;
typedef struct {
  int Front, Rear, Count;
  QueueElementType Element[QueueLimit];
} QueueType;

void CreateQ(QueueType *Queue);
bool EmptyQ(QueueType Queue);
bool FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);
void PrintPointers(QueueType Queue);

int main() {
  int i;
  QueueType AQueue;
  QueueElementType x;
  CreateQ(&AQueue);
  printf("a\n");
  for (i=0; i<10; i++) {
    AddQ(&AQueue, i);
  }
  TraverseQ(AQueue);
  PrintPointers(AQueue);
  printf("b\n");
  AddQ(&AQueue, 67);
  TraverseQ(AQueue);
  PrintPointers(AQueue);
  printf("c\n");
  RemoveQ(&AQueue, &x);
  TraverseQ(AQueue);
  printf("Removed item=%d ", x);
  PrintPointers(AQueue);
  printf("d\n");
  AddQ(&AQueue, 25);
  TraverseQ(AQueue);
  PrintPointers(AQueue);
  printf("e\n");
  AddQ(&AQueue, 67);
  TraverseQ(AQueue);
  PrintPointers(AQueue);
  printf("f\n");
  for (i=0; i<QueueLimit; i++) {
    RemoveQ(&AQueue, &x);
    TraverseQ(AQueue);
    printf("Removed item=%d ", x);
    PrintPointers(AQueue);
  }
}

void CreateQ(QueueType *Queue) {
  Queue->Front = 0;
  Queue->Rear = 0;
  Queue->Count = 0;
}
bool EmptyQ(QueueType Queue) {
  return (Queue.Count == 0);
}
bool FullQ(QueueType Queue) {
  return (Queue.Count == QueueLimit);
}
void AddQ(QueueType *Queue, QueueElementType Item) {
  if (!FullQ(*Queue)) {
    Queue->Element[Queue->Rear] = Item;
    Queue->Rear = (Queue->Rear + 1) % QueueLimit;
    Queue->Count++;
  } else {
      printf("Full Queue\n");
    }
}
void RemoveQ(QueueType *Queue, QueueElementType *Item) {
  if (!EmptyQ(*Queue)) {
    *Item = Queue->Element[Queue->Front];
    Queue->Front = (Queue->Front + 1) % QueueLimit;
    Queue->Count--;
  } else {
      printf("Empty Queue\n");
    }
}
void TraverseQ(QueueType Queue) {
  int i, current;
  if (!EmptyQ(Queue)) {
    printf("Queue: ");
    current = Queue.Front;
    for (i = 0; i < Queue.Count; i++) {
        printf("%d ", Queue.Element[current]);
        current = (current + 1) % QueueLimit;
    }
    printf("\n");
    } else {
        printf("Queue: Empty Queue\n");
      }
}
void PrintPointers(QueueType Queue) {
  printf("Front=%d Rear=%d Count=%d\n", Queue.Front, Queue.Rear, Queue.Count);
}

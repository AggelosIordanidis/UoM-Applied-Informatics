#include <stdbool.h>
#include <stdio.h>
#define QueueLimit 21

typedef int QueueElementType;
typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

void CreateQ(QueueType *Queue);
bool EmptyQ(QueueType Queue);
bool FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);
bool ProcessQ(QueueType *Queue, QueueElementType Item);

int main () {
  QueueType EvenQueue, OddQueue;
  CreateQ(&EvenQueue);
  CreateQ(&OddQueue);
  int i, even, odd;
  for (i=0; i<20; i++) {
    if (i % 2 == 0) AddQ(&EvenQueue, i);
  }
  printf("EvenQueue\n");
  TraverseQ(EvenQueue);
   for (i=0; i<20; i++) {
    if (i % 2 == 1) AddQ(&OddQueue, i);
  }
  printf("OddQueue\n");
  TraverseQ(OddQueue);
  printf("Give number of items = ");
  scanf("%d", &even);
  printf("EvenQueue\n");
  ProcessQ(&EvenQueue, even);
  TraverseQ(EvenQueue);
  printf("Give number of items = ");
  scanf("%d", &odd);
  printf("OddQueue\n");
  ProcessQ(&OddQueue, odd);
  TraverseQ(OddQueue);
  return 0;
}

void CreateQ(QueueType *Queue) {
	Queue->Front = 0;
	Queue->Rear = 0;
}
bool EmptyQ(QueueType Queue) {
	return (Queue.Front == Queue.Rear);
}
bool FullQ(QueueType Queue) {
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}
void RemoveQ(QueueType *Queue, QueueElementType *Item) {
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue\n");
}
void AddQ(QueueType *Queue, QueueElementType Item) {
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
	}
	else
		printf("Full Queue\n");
}
void TraverseQ(QueueType Queue) {
	int current;
	if (!EmptyQ(Queue)) {
        current = Queue.Front;
	    while (current != Queue.Rear) {
            printf("%d ", Queue.Element[current]);
		  current = (current + 1) % QueueLimit;
	   }
	   printf("\n");
    }
    else printf("Empty Queue\n");
}
bool ProcessQ(QueueType *Queue, QueueElementType Item) {
  QueueElementType temp;
    for (int i = 0; i < Item; i++) {
        if (!EmptyQ(*Queue)) {
            RemoveQ(Queue, &temp);
            AddQ(Queue, temp);
        }
    }
}

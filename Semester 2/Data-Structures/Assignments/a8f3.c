#include <stdbool.h>
#include <stdio.h>
#define QueueLimit 34

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
bool SearchQ(QueueType *Queue, QueueElementType Item);

int main () {
  QueueType AQueue;
  int i, value;
  CreateQ(&AQueue);
  for (i=1; i<=QueueLimit; i++) {
    AddQ(&AQueue, 3*i);
  }
  TraverseQ(AQueue);
  printf("Give the search value: ");
  scanf("%d", &value);
  if (SearchQ(&AQueue, value)) {
    printf("Found\n");
  } else {
    printf("Not Found\n");
  }
  TraverseQ(AQueue);
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
bool SearchQ(QueueType *Queue, QueueElementType Item) {
  QueueElementType temp;
  while (!EmptyQ(*Queue)) {
    RemoveQ(Queue, &temp);
    if (Item == temp) return true;
  }
  return false;
}

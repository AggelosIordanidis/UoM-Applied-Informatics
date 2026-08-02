#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define QueueLimit 16
#define StackLimit 16

typedef int QueueElementType;
typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;
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
void CreateQ(QueueType *Queue);
bool EmptyQ(QueueType Queue);
bool FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void ReverseQ (QueueType *Queue);
void TraverseQ(QueueType Queue);

int main() {
    QueueType AQueue;
    int i;
    CreateQ(&AQueue);
    for (i = 1; i <= 15; i++) {
        AddQ(&AQueue, 2 * i);
    }
    TraverseQ(AQueue);
    ReverseQ(&AQueue);
    TraverseQ(AQueue);
    return 0;
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
void ReverseQ (QueueType *Queue) {
  StackType tempS;
  QueueElementType item;
  CreateStack(&tempS);
  while (!EmptyQ(*Queue)) {
    RemoveQ(Queue, &item);
    Push(&tempS, item);
  }
  while (!EmptyStack(tempS)) {
        Pop(&tempS, &item);
        AddQ(Queue, item);
  }
}

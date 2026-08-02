#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define NumberOfNodes 10
#define NilValue -1

typedef struct {
  int am, bathmos;
} ListElementType;
typedef int ListPointer;
typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
bool EmptyList(ListPointer List);
bool FullList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void ReleaseNode(NodeType Node[NumberOfNodes], ListPointer P, ListPointer *FreePtr);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr);
void TraverseLinked(ListPointer List, NodeType Node[]);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);

int main () {
  int i;
  ListPointer AList;
  NodeType Node[NumberOfNodes];
  ListPointer FreePtr,PredPtr;
  PredPtr = NilValue;
  ListElementType AnItem;
  InitializeStoragePool(Node, &FreePtr);
  CreateList(&AList);
  printf("Question C\n");
  printAll(AList, FreePtr, Node);
  printf("Question D\n");
  TraverseLinked(AList, Node);
  printf("Question E\n");
  for (i=0; i<5; i++) {
    printf("Dwse am: ");
    scanf("%d", &AnItem.am);
    printf("Dwse mark: ");
    scanf("%d", &AnItem.bathmos);
    Insert(&AList, Node, &FreePtr, PredPtr, AnItem);
  }
  printf("Question F\n");
  printAll(AList, FreePtr, Node);
  printf("Question G\n");
  TraverseLinked(AList, Node);
  printf("Question H\n");
  printf("DWSE TH 8ESH TOY PROHGOYMENO STOIXEIOY GIA DIAGRAFH: ");
  scanf("%d", &PredPtr);
  Delete(&AList, Node, &FreePtr, PredPtr);
  printf("Question I\n");
  printAll(AList, FreePtr, Node);
  printf("Question J\n");
  TraverseLinked(AList, Node);
  return 0;
}

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr) {
   int i;
    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data.am = -1;
        Node[i].Data.bathmos = -1;
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data.am = -1;
    Node[NumberOfNodes-1].Data.bathmos = -1;
    *FreePtr=0;
}
void CreateList(ListPointer *List) {
  *List=NilValue;
}
bool EmptyList(ListPointer List) {
  return (List==NilValue);
}
bool FullList(ListPointer FreePtr) {
  return (FreePtr == NilValue);
}
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]) {
  *P = *FreePtr;
  if (!FullList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}
void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr) {
  Node[P].Next =*FreePtr;
  Node[P].Data.am = -1;
  Node[P].Data.bathmos = -1;
  *FreePtr =P;
}
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item) {
  ListPointer TempPtr;
  GetNode(&TempPtr,FreePtr,Node);
  if (!FullList(TempPtr)) {
    if (PredPtr==NilValue)
    {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data = Item;
        Node[TempPtr].Next = Node[PredPtr].Next;
        Node[PredPtr].Next = TempPtr;
      }
}
  else
    printf("Full List ...\n");
}
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr) {
  ListPointer TempPtr ;

  if (!EmptyList(*List)) {
    if (PredPtr == NilValue)
    {
        TempPtr =*List;
        *List =Node[TempPtr].Next;
    }
    else
      {
        TempPtr =Node[PredPtr].Next;
        Node[PredPtr].Next =Node[TempPtr].Next;
      }
      ReleaseNode(Node,TempPtr,FreePtr);
  }
  else
    printf("Empty List ...\n");
}
void TraverseLinked(ListPointer List, NodeType Node[]) {
  ListPointer CurrPtr;
  if (!EmptyList(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d: %d, %d->%d) ",CurrPtr,Node[CurrPtr].Data.am, Node[CurrPtr].Data.bathmos, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]) {
    int i;
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d: %d, %d->%d) ", i, Node[i].Data.am, Node[i].Data.bathmos, Node[i].Next);
    printf("\n");
}

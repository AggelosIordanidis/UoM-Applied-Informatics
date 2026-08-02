#include <stdio.h>
#include <stdbool.h>
#define NumberOfNodes 10
#define NilValue -1

typedef int ListElementType;
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
bool Search(ListPointer FreePtr, ListPointer List, NodeType Node[NumberOfNodes], ListElementType Item,ListPointer *PredPtr);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);

int main () {
  int i, num;
  char choice;
  ListElementType AnItem;
  ListPointer FreePtr,PredPtr, AList;
  NodeType Node[NumberOfNodes];
  PredPtr = NilValue;
  InitializeStoragePool(Node, &FreePtr);
  CreateList(&AList);
  printf("Question C\n");
  printAll(AList, FreePtr, Node);
  printf("Question D\n");
  TraverseLinked(AList, Node);
  printf("Question E\n");
  do {
    printf("Give a number: ");
    scanf("%d", &AnItem);
    printf("\n");
    if (!Search(FreePtr, AList, Node, AnItem, &PredPtr)) {
      Insert(&AList, Node, &FreePtr, PredPtr, AnItem);
    } else {
      printf("Item already exists\n");
    }
    printf("Continue Y/N: ");
    scanf(" %c", &choice);
  } while (choice == 'y');
  printf("Question F\n");
  printAll(AList, FreePtr, Node);
  printf("Question G\n");
  TraverseLinked(AList, Node);
  printf("Question H\n");
  if (!EmptyList(AList)) {
    printf("Not an Empty List\n");
  } else {
    printf("Empty List\n");
  }
  printf("Question I\n");
  if (!FullList(FreePtr)) {
    printf("Not a Full List\n");
  } else {
    printf("Full List\n");
  }
  printf("Question J\n");
  printf("Search for a number\n");
  for (i=0; i<2; i++) {
    printf("Give a number ");
    scanf("%d", &num);
    if (Search(FreePtr, AList, Node, num, &PredPtr)) {
      printf("The number is in the list and its predecessor is in position %d\n", PredPtr);
    } else {
      printf("The number is not in the list\n");
    }
  }
  return 0;
}

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr) {
    for (int i=0; i<NumberOfNodes-1;i++) {
        Node[i].Next=i+1;
        Node[i].Data=-1;
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data=-1;
    *FreePtr=0;
}
void CreateList(ListPointer *List) {
  *List = NilValue;
}
bool EmptyList(ListPointer List) {
  return (List == NilValue);
}
bool FullList(ListPointer FreePtr) {
  return (FreePtr == NilValue);
}
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]) {
  *P = *FreePtr;
  if (!FullList(*FreePtr))
    *FreePtr = Node[*FreePtr].Next;
}
void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr) {
  Node[P].Next = *FreePtr;
  Node[P].Data = -1;
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
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =Node[PredPtr].Next;
        Node[PredPtr].Next =TempPtr;
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
  printf("Linked List\n");
  if (!EmptyList(List)) {
      CurrPtr =List;
      while (CurrPtr != NilValue) {
          printf("(%d: %d->%d) ",CurrPtr,Node[CurrPtr].Data, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]) {
    int i;
    printf("Storage pool\n");
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d: %d->%d) ", i, Node[i].Data, Node[i].Next);
    printf("\n");
}
bool Search(ListPointer FreePtr, ListPointer List, NodeType Node[NumberOfNodes], ListElementType Item, ListPointer *PredPtr) {
    ListPointer CurrPtr;
    *PredPtr = NilValue;
    CurrPtr = List;
    while (CurrPtr != NilValue && (Node[CurrPtr].Data < Item)) {
        *PredPtr = CurrPtr;
        CurrPtr = Node[CurrPtr].Next;
    }
    if (CurrPtr != NilValue && (Node[CurrPtr].Data == Item)) {
        return true;
      } else {
        return false;
      }
}

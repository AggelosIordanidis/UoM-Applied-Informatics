#include <stdio.h>
#include <stdbool.h>
#define NumberOfNodes 10
#define NilValue -1
#define StackLimit 50

typedef struct {
  int am;
  float grade;
} ListElementType;
typedef int ListPointer;
typedef struct {
  ListElementType Data;
  ListPointer  Next;
} NodeType;
typedef int StackElementType;
typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

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
void CreateStack(StackType *Stack);
bool EmptyStack(StackType Stack);
bool FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);
float FindMins(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack);

int main () {
  int i;
  ListElementType AnItem;
  ListPointer AList, FreePtr, PredPtr;
  NodeType Node[NumberOfNodes];
  StackElementType x;
  StackType AStack;
  CreateStack(&AStack);
  PredPtr = NilValue;
  InitializeStoragePool(Node, &FreePtr);
  CreateList(&AList);
  printf("Question C\n");
  printAll(AList, FreePtr, Node);
  printf("Question D\n");
  TraverseLinked(AList, Node);
  printf("Question E\n");
  for (i=0; i<5; i++) {
    printf("DWSE AM GIA EISAGWGH STH LISTA: ");
    scanf("%d", &AnItem.am);
    printf("DWSE VATHMO GIA EISAGWGH STH LISTA: ");
    scanf("%f", &AnItem.grade);
    Insert(&AList, Node, &FreePtr, PredPtr, AnItem);
  }
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
  if (!FullList(AList)) {
    printf("Not a Full List");
  } else {
    printf("Full List");
  }
  printf("\nQuestion J\n");
  printf("Min value=%.1f\n", FindMins(AList, Node, &AStack));
  printf("AM with min grade are: ");
  while (!EmptyStack(AStack)) {
    Pop(&AStack, &x);
    printf("%d ", x);
  }
  printf("\nQuestion K\n");
  printf("\n");
  TraverseStack(AStack);
  printf("\nQuestion L\n");
  printAll(AList, FreePtr, Node);
  printf("Question M\n");
  TraverseLinked(AList, Node);
  return 0;
}

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr) {
   int i;
    for (i=0; i<NumberOfNodes-1;i++){
        Node[i].Next=i+1;
        Node[i].Data.am=-1;
        Node[i].Data.grade=-1;
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data.am=-1;
    Node[NumberOfNodes-1].Data.grade=-1;
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
  if (!FullList(*FreePtr)) {
    *FreePtr =Node[*FreePtr].Next;
  }
}
void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr) {
  Node[P].Next =*FreePtr;
  Node[P].Data.am = -1;
  Node[P].Data.grade=-1;
  *FreePtr =P;
}
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item) {
  ListPointer TempPtr;
  GetNode(&TempPtr,FreePtr,Node);
  if (!FullList(TempPtr)) {
    if (PredPtr==NilValue) {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    } else {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =Node[PredPtr].Next;
        Node[PredPtr].Next =TempPtr;
      }
  } else
    printf("Full List ...\n");
}
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr) {
  ListPointer TempPtr ;
  if (!EmptyList(*List)) {
    if (PredPtr == NilValue) {
        TempPtr =*List;
        *List =Node[TempPtr].Next;
    } else {
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
          printf("(%d:<%d,%.1f> ->%d) ",CurrPtr,Node[CurrPtr].Data.am, Node[CurrPtr].Data.grade, Node[CurrPtr].Next);
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
        printf("(%d:<%d,%.1f> ->%d) ", i, Node[i].Data.am, Node[i].Data.grade, Node[i].Next);
    printf("\n");
}
void CreateStack(StackType *Stack) {
    Stack -> Top = -1;
}
bool EmptyStack(StackType Stack) {
    return (Stack.Top == NilValue);
}
bool FullStack(StackType Stack) {
    return (Stack.Top == (StackLimit - 1));
}
void Push(StackType *Stack, StackElementType Item) {
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else {
        printf("Full Stack...");
    }
}
void Pop(StackType *Stack, StackElementType *Item) {
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else {
        printf("Empty Stack...");
    }
}
void TraverseStack(StackType Stack) {
    int i;
    printf("plithos sto stack %d\n",Stack.Top+1);
    if (Stack.Top != NilValue) {
      for (i=0; i<=Stack.Top; i++) {
        printf("%d ",Stack.Element[i]);
      }
    }
    printf("\n");
}
float FindMins(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack) {
  ListPointer CurrPtr;
  float min;
  if (!EmptyList(List)) {
    CurrPtr = List;
    min = Node[CurrPtr].Data.grade;
    while (CurrPtr != NilValue) {
      if (Node[CurrPtr].Data.grade < min) {
         min = Node[CurrPtr].Data.grade;
      }
      CurrPtr = Node[CurrPtr].Next;
    }
    CurrPtr = List;
    while (CurrPtr != NilValue) {
      if (Node[CurrPtr].Data.grade == min) {
        Push(Stack, Node[CurrPtr].Data.am);
      }
      CurrPtr = Node[CurrPtr].Next;
    }
    return min;
  } else {
    printf("Empty list ...\n");
    return NilValue;
  }
}

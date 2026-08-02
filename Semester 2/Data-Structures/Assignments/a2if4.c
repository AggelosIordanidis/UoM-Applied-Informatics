#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ListElementType;
typedef struct ListNode *ListPointer;
typedef struct ListNode {
  ListElementType Data;
  ListPointer Next;
} ListNode;

void CreateList(ListPointer *List);
bool EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);
void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, bool *Found);
void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, bool *Found);
void intersection_list(ListPointer List, ListPointer BList, ListPointer *FinalList);

int main() {
  int n, i;
  ListElementType AnItem;
  ListPointer PredPtr, AList, BList, FList;
  PredPtr = FList = NULL;
  CreateList(&AList);
  CreateList(&BList);
  CreateList(&FList);
  printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS 1: ");
  scanf("%d", &n);
  for (i=0; i<n; i++) {
    printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS 1: ");
    scanf("%d", &AnItem);
    LinkedInsert(&AList, AnItem, PredPtr);
  }
  printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS 2: ");
  scanf("%d", &n);
  for (i=0; i<n; i++) {
    printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS 2: ");
    scanf("%d", &AnItem);
    LinkedInsert(&BList, AnItem, PredPtr);
  }
  printf("1 list\n");
  LinkedTraverse(AList);
  printf("\n2 list\n");
  LinkedTraverse(BList);
  printf("\nFinal list\n");
  intersection_list(AList, BList, &FList);
  LinkedTraverse(FList);
  printf("\n");
  return 0;
}

void CreateList(ListPointer *List) {
  *List = NULL;
}
bool EmptyList(ListPointer List) {
  return (List==NULL);
}
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr){
  ListPointer TempPtr;
  TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
  TempPtr->Data = Item;
  if (PredPtr==NULL) {
    TempPtr->Next = *List;
    *List = TempPtr;
  }
  else {
    TempPtr->Next = PredPtr->Next;
    PredPtr->Next = TempPtr;
  }
}
void LinkedDelete(ListPointer *List, ListPointer PredPtr) {
  ListPointer TempPtr;
  if (EmptyList(*List))
    printf("EMPTY LIST\n");
  else {
    if (PredPtr == NULL) {
      TempPtr = *List;
      *List = TempPtr->Next;
    }
    else {
      TempPtr = PredPtr->Next;
      PredPtr->Next = TempPtr->Next;
    }
      free(TempPtr);
  }
}
void LinkedTraverse(ListPointer List) {
  ListPointer CurrPtr;
  if (EmptyList(List))
    printf("EMPTY LIST\n");
  else {
    CurrPtr = List;
    while (CurrPtr!=NULL) {
        printf("%d ", (*CurrPtr).Data);
        CurrPtr = CurrPtr->Next;
    }
  }
}
void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, bool *Found) {
  ListPointer CurrPtr;
  CurrPtr = List;
  *PredPtr=NULL;
  *Found= false;
  while (!(*Found) && CurrPtr!=NULL) {
    if (CurrPtr->Data==Item )
      *Found = true;
    else {
      *PredPtr = CurrPtr;
      CurrPtr = CurrPtr->Next;
    }
  }
}
void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, bool *Found) {
  ListPointer CurrPtr;
  bool DoneSearching;
  CurrPtr = List;
  *PredPtr = NULL;
  DoneSearching = false;
  *Found = false;
  while (!DoneSearching && CurrPtr!=NULL ) {
    if (CurrPtr->Data>=Item ) {
      DoneSearching = true;
      *Found = (CurrPtr->Data==Item);
    }
    else {
      *PredPtr = CurrPtr;
      CurrPtr = CurrPtr->Next;
    }
  }
}
void intersection_list(ListPointer List, ListPointer BList, ListPointer *FList) {
  ListPointer CurrPtr, PredPtr;
  CurrPtr = BList;
  bool Found, AlreadyIn;
  while (CurrPtr != NULL) {
    LinearSearch(List, CurrPtr->Data, &PredPtr, &Found);
    if (Found) {
      LinearSearch(*FList, CurrPtr->Data, &PredPtr, &AlreadyIn);
      if (!AlreadyIn) {
        LinkedInsert(FList, CurrPtr->Data, NULL);
      }
    }
    CurrPtr = CurrPtr->Next;
  }
}

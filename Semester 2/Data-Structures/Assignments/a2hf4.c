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
void delete_list_every_second_element(ListPointer List);

int main() {
  int n, i;
  ListPointer PredPtr, AList;
  PredPtr = NULL;
  ListElementType AnItem;
  CreateList(&AList);
  printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS: ");
  scanf("%d", &n);
  for (i=0; i<n; i++) {
    printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS: ");
    scanf("%d", &AnItem);
    LinkedInsert(&AList, AnItem, PredPtr);
  }
  printf("Initial List\n");
  LinkedTraverse(AList);
  printf("\nFinal List\n");
  delete_list_every_second_element(AList);
  LinkedTraverse(AList);
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
void delete_list_every_second_element(ListPointer List) {
  ListPointer CurrPtr;
  CurrPtr = List;
  while ((CurrPtr != NULL) && (CurrPtr->Next != NULL)) {
    LinkedDelete(&List, CurrPtr);
    CurrPtr = CurrPtr->Next;
  }
}

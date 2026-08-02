#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

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
void inverse_list(ListPointer *List);

int main() {
  ListPointer AList, PredPtr;
  PredPtr = NULL;
  int n, i;
  ListElementType item;
  CreateList(&AList);
  printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS: ");
  scanf("%d", &n);
  for (i=0; i<n; i++) {
    printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS: ");
    scanf("%d", &item);
    LinkedInsert(&AList, item, PredPtr);
  }
  printf("Initial List\n");
  LinkedTraverse(AList);
  printf("Final List\n");
  inverse_list(&AList);
  LinkedTraverse(AList);
  return 0;
}

void CreateList(ListPointer *List) {
	*List = NULL;
}
bool EmptyList(ListPointer List) {
	return (List==NULL);
}
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr) {
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
  if (EmptyList(List)) {
    printf("EMPTY LIST\n");
  }
  else {
    CurrPtr = List;
    while ( CurrPtr!=NULL ) {
      printf("%d ", (*CurrPtr).Data);
      CurrPtr = CurrPtr->Next;
    }
    printf("\n");
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
    if (CurrPtr->Data>=Item) {
      DoneSearching = true;
      *Found = (CurrPtr->Data==Item);
    }
    else {
      *PredPtr = CurrPtr;
      CurrPtr = CurrPtr->Next;
    }
  }
}
void inverse_list(ListPointer *List) {
  ListPointer HelpList, CurrPtr;
  CreateList(&HelpList);
  if (!EmptyList(*List)) {
    CurrPtr = *List;
    while (CurrPtr != NULL) {
      LinkedInsert(&HelpList, CurrPtr->Data, NULL);
      CurrPtr = CurrPtr->Next;
      LinkedDelete(List, NULL);
    }
    *List = HelpList;
  }
}


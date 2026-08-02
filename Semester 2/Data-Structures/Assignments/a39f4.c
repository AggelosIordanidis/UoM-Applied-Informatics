#include <stdio.h>
#include <stdbool.h>
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

int main() {
  ListPointer AList, PredPtr;
  bool Found;
  CreateList(&AList);
  ListElementType itemsToInsert[] = {30, 10, 50, 20, 40};
  for (int i = 0; i < 5; i++) {
    OrderedLinearSearch(AList, itemsToInsert[i], &PredPtr, &Found);
    LinkedInsert(&AList, itemsToInsert[i], PredPtr);
  }
  printf("Traverse after insertions:\n");
  LinkedTraverse(AList);
  LinearSearch(AList, 20, &PredPtr, &Found);
  if (Found) printf("LinearSearch for 20: Found\n");
  else printf("LinearSearch for 20: NOT found\n");
  LinearSearch(AList, 99, &PredPtr, &Found);
  if (Found) printf("LinearSearch for 99: Found\n");
  else printf("LinearSearch for 99: NOT found\n");
  OrderedLinearSearch(AList, 30, &PredPtr, &Found);
  if (Found) printf("OrderedLinearSearch for 30: Found\n");
  else printf("OrderedLinearSearch for 30: NOT found\n");
  OrderedLinearSearch(AList, 88, &PredPtr, &Found);
  if (Found) printf("OrderedLinearSearch for 88: Found\n");
  else printf("OrderedLinearSearch for 88: NOT found\n");
  OrderedLinearSearch(AList, 40, &PredPtr, &Found);
  if (Found) {
    LinkedDelete(&AList, PredPtr);
    printf("Traverse after deleting 40:\n");
    LinkedTraverse(AList);
  }
  OrderedLinearSearch(AList, 10, &PredPtr, &Found);
  if (Found) {
    LinkedDelete(&AList, PredPtr);
    printf("Traverse after deleting 10:\n");
    LinkedTraverse(AList);
  }
  OrderedLinearSearch(AList, 25, &PredPtr, &Found);
  LinkedInsert(&AList, 25, PredPtr);
  printf("Traverse after inserting 25:\n");
  LinkedTraverse(AList);
  return 0;
}

void CreateList(ListPointer *List) {
  *List = (ListPointer)malloc(sizeof(ListNode));
  if (*List != NULL) {
    (*List)->Next = *List;
  }
}
bool EmptyList(ListPointer List) {
  return (List->Next == List);
}
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr) {
  ListPointer TempPtr = (ListPointer)malloc(sizeof(ListNode));
  TempPtr->Data = Item;
  TempPtr->Next = PredPtr->Next;
  PredPtr->Next = TempPtr;
}
void LinkedDelete(ListPointer *List, ListPointer PredPtr) {
  if (EmptyList(*List)) {
    printf("EMPTY LIST\n");
  } else {
    ListPointer TempPtr = PredPtr->Next;
    PredPtr->Next = TempPtr->Next;
    free(TempPtr);
  }
}
void LinkedTraverse(ListPointer List) {
  if (EmptyList(List)) {
    printf("EMPTY LIST\n");
  } else {
    ListPointer CurrPtr = List->Next;
    while (CurrPtr != List) {
      printf("%d ", CurrPtr->Data);
      CurrPtr = CurrPtr->Next;
    }
    printf("\n");
    }
}
void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, bool *Found) {
  ListPointer CurrPtr;
  CurrPtr = List->Next;
  *PredPtr = List;
  *Found = false;
  while (!(*Found) && CurrPtr != List) {
    if (CurrPtr->Data == Item)
      *Found = true;
    else {
      *PredPtr = CurrPtr;
      CurrPtr = CurrPtr->Next;
    }
  }
}
void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, bool *Found) {
  ListPointer CurrPtr;
  bool DoneSearching = false;
  CurrPtr = List->Next;
  *PredPtr = List;
  *Found = false;
  while (!DoneSearching && CurrPtr != List) {
    if (CurrPtr->Data >= Item) {
      DoneSearching = true;
      *Found = (CurrPtr->Data == Item);
    } else {
      *PredPtr = CurrPtr;
      CurrPtr = CurrPtr->Next;
    }
  }
}

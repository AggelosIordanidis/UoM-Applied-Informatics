#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char BinTreeElementType;
typedef struct BinTreeNode *BinTreePointer;
typedef struct BinTreeNode {
  BinTreeElementType Data;
  BinTreePointer LChild, RChild;
} BinTreeNode;

void CreateBST(BinTreePointer *Root);
bool EmptyBST(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, bool *Found, BinTreePointer *LocPtr);
void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void RecBSTInorder(BinTreePointer Root);
void RecBSTPreorder(BinTreePointer Root);
void RecBSTPostorder(BinTreePointer Root);
bool IdenticalBSTs(BinTreePointer Root, BinTreePointer Root2);

int main() {
  BinTreePointer ARoot, BRoot, CRoot;
  bool AB;
  bool BC;
  char AStr[] = {'I','D','E','N','T','I','C','A','L'};
  char BStr[] = {'D','I','F','F','E','R','E','N','T'};
  CreateBST(&ARoot);
  CreateBST(&BRoot);
  CreateBST(&CRoot);
  for (int i=0; i<9; i++) {
    RecBSTInsert(&ARoot, AStr[i]);
    RecBSTInsert(&BRoot, AStr[i]);
    RecBSTInsert(&CRoot, BStr[i]);
  }
  AB = IdenticalBSTs(ARoot, BRoot);
  BC = IdenticalBSTs(BRoot, CRoot);
  if (!AB)  printf("Ta dyadika dentra A kai b diafferoun\n");
  else printf("Ta dyadika dentra A kai B einai idia\n");
  if (!BC) printf("Ta dyadika dentra B kai C diafferoun\n");
  else printf("Ta dyadika dentra B kai C einai idia\n");
  return 0;
}

void CreateBST(BinTreePointer *Root) {
  *Root = NULL;
}
bool EmptyBST(BinTreePointer Root) {
  return (Root==NULL);
}
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item) {
    if (EmptyBST(*Root)) {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        (*Root) ->Data = Item;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else
        if (Item < (*Root) ->Data)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if (Item > (*Root) ->Data)
            RecBSTInsert(&(*Root) ->RChild,Item);
        else
            printf("TO STOIXEIO EINAI HDH STO DDA\n");
}
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, bool *Found, BinTreePointer *LocPtr) {
  if (EmptyBST(Root))
    *Found=false;
  else
    if (KeyValue < Root->Data)
        RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
    else
        if (KeyValue > Root->Data)
            RecBSTSearch(Root->RChild, KeyValue, &(*Found), &(*LocPtr));
        else {
            *Found = true;
            *LocPtr=Root;
        }
}
void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue) {
  BinTreePointer TempPtr;
  if (EmptyBST(*Root))
    printf("TO STOIXEIO DEN BRE8HKE STO DDA\n");
  else
    if (KeyValue < (*Root)->Data)
        RecBSTDelete(&((*Root)->LChild), KeyValue);
    else if (KeyValue > (*Root)->Data)
        RecBSTDelete(&((*Root)->RChild), KeyValue);
        if ((*Root)->LChild ==NULL) {
          TempPtr = *Root;
          *Root = (*Root)->RChild;
          free(TempPtr);
        }
        else if ((*Root)->RChild == NULL) {
          TempPtr = *Root;
          *Root = (*Root)->LChild;
          free(TempPtr);
        }
        else {
          TempPtr = (*Root)->RChild;
          while (TempPtr->LChild != NULL)
            TempPtr = TempPtr->LChild;
         (*Root)->Data = TempPtr->Data;
         RecBSTDelete(&((*Root)->RChild), (*Root)->Data);
      }
}
void RecBSTInorder(BinTreePointer Root) {
  if (!EmptyBST(Root)) {
    RecBSTInorder(Root->LChild);
    printf("%d ",Root->Data);
    RecBSTInorder(Root->RChild);
  }
}
void RecBSTPreorder(BinTreePointer Root) {
  if (!EmptyBST(Root)) {
    printf("%d ",Root->Data);
    RecBSTPreorder(Root->LChild);
    RecBSTPreorder(Root->RChild);
  }
}
void RecBSTPostorder(BinTreePointer Root) {
  if (!EmptyBST(Root)) {
    RecBSTPostorder(Root->LChild);
    RecBSTPostorder(Root->RChild);
    printf("%d ",Root->Data);
  }
}
bool IdenticalBSTs(BinTreePointer Root1, BinTreePointer Root2) {
  if (Root1 == NULL && Root2 == NULL) return true;
  if (Root1 == NULL || Root2 == NULL || Root1->Data != Root2->Data) return false;
  return (IdenticalBSTs(Root1->LChild, Root2->LChild) && IdenticalBSTs(Root1->RChild, Root2->RChild));
}

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int BinTreeElementType;
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
int BSTDepth(BinTreePointer Root);

int main() {
  int depth = 0;
  char str[] = {'P','R','O','C','E','D','U','R','E'};
  BinTreePointer ARoot;
  CreateBST(&ARoot);
  for (int i=0; i<9; i++) {
    RecBSTInsert(&ARoot, str[i]);
  }
  depth = BSTDepth(ARoot);
  printf("To vathos toy DDA einai: %d\n", depth);
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
int BSTDepth(BinTreePointer Root) {
  int left, right;
  if (EmptyBST(Root)) {
    return 0;
  } else {
    left = BSTDepth(Root->LChild);
    right = BSTDepth(Root->RChild);
    if (left > right) return 1 + left;
    else return 1 + right;
  }
}

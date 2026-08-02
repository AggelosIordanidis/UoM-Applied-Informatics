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
int CountLeaves(BinTreePointer Root);

int main() {
  int count = 0;
  char choice;
  BinTreePointer ARoot;
  BinTreeElementType AnItem;
  CreateBST(&ARoot);
  do {
    printf("Enter a number for insertion in the Tree: ");
    scanf("%d", &AnItem);
    do {
      printf("Continue Y/N: ");
      scanf(" %c", &choice);
    } while ((choice != 'Y') && (choice != 'N'));
    RecBSTInsert(&ARoot, AnItem);
  } while (choice != 'N');
  printf("Elements of BST\n");
  RecBSTInorder(ARoot);
  count = CountLeaves(ARoot);
  printf("\nNumber of leaves %d", count);
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
int CountLeaves(BinTreePointer Root) {
  if (EmptyBST(Root))
    return 0;
  if (Root->LChild == NULL && Root->RChild == NULL)
    return 1;
  return CountLeaves(Root->LChild) + CountLeaves(Root->RChild);
}

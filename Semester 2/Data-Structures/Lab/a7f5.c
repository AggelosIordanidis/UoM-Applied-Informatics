#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef char BinTreeElementType;
typedef struct BinTreeNode *BinTreePointer;
typedef struct BinTreeNode {
  BinTreeElementType Data;
  BinTreePointer LChild, RChild;
} BinTreeNode;

void CreateBST(BinTreePointer *Root);
bool EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, bool *Found, BinTreePointer *LocPtr);
void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, bool *Found, BinTreePointer *LocPtr, BinTreePointer *Parent);
void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
BinTreeElementType MinBSTValue(BinTreePointer Root);
BinTreeElementType MaxBSTValue(BinTreePointer Root);

int main() {
  int i;
  char str[] = "PROCEDURE";
  BinTreePointer ARoot, LocPtr;
  BinTreeElementType AnItem;
  bool Found;
  CreateBST(&ARoot);
  for (i=0; i<strlen(str); i++) {
    BSTInsert(&ARoot, str[i]);
  }
  printf("Node with min value: %c\n", MinBSTValue(ARoot));
  printf("Node with max value: %c\n", MaxBSTValue(ARoot));
  return 0;
}


BinTreeElementType MinBSTValue(BinTreePointer Root) {
  BinTreePointer temp;
  temp = Root;
  while (temp->LChild != NULL) {
    temp = temp->LChild;
  }
  return temp->Data;
}
BinTreeElementType MaxBSTValue(BinTreePointer Root) {
  BinTreePointer temp;
  temp = Root;
  while (temp->RChild != NULL) {
    temp = temp->RChild;
  }
  return temp->Data;
}
void CreateBST(BinTreePointer *Root) {
  *Root = NULL;
}

bool EmptyBST(BinTreePointer Root) {
  return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item) {
  BinTreePointer LocPtr, Parent;
  bool Found;
  LocPtr = *Root;
  Parent = NULL;
  Found = false;
  while (!Found && LocPtr != NULL) {
    Parent = LocPtr;
    if (Item < LocPtr->Data)
        LocPtr = LocPtr ->LChild;
    else if (Item > LocPtr ->Data)
        LocPtr = LocPtr ->RChild;
    else
        Found = true;
    }
    if (Found)
      printf("TO %c EINAI HDH STO DDA\n", Item);
    else {
      LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
      LocPtr ->Data = Item;
      LocPtr ->LChild = NULL;
      LocPtr ->RChild = NULL;
      if (Parent == NULL)
        *Root = LocPtr;
      else if (Item < Parent ->Data)
        Parent ->LChild = LocPtr;
      else
        Parent ->RChild = LocPtr;
    }
}
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, bool *Found, BinTreePointer *LocPtr) {
  (*LocPtr) = Root;
  (*Found) = false;
  while (!(*Found) && (*LocPtr) != NULL) {
    if (KeyValue < (*LocPtr)->Data)
      (*LocPtr) = (*LocPtr)->LChild;
    else
      if (KeyValue > (*LocPtr)->Data)
        (*LocPtr) = (*LocPtr)->RChild;
      else (*Found) = true;
  }
}
void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, bool *Found, BinTreePointer *LocPtr, BinTreePointer *Parent) {
  *LocPtr = Root;
  *Parent=NULL;
  *Found = false;
  while (!(*Found) && *LocPtr != NULL) {
    if (KeyValue < (*LocPtr)->Data) {
      *Parent=*LocPtr;
      *LocPtr = (*LocPtr)->LChild;
    }
    else
      if (KeyValue > (*LocPtr)->Data) {
        *Parent=*LocPtr;
        *LocPtr = (*LocPtr)->RChild;
      }
      else *Found = true;
  }
}
void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue) {
  BinTreePointer n,
  Parent,
  nNext,
  SubTree;
  bool Found;
  BSTSearch2(*Root, KeyValue, &Found , &n, &Parent);
  if (!Found)
    printf("TO STOIXEIO DEN EINAI STO DDA\n");
  else {
    if (n->LChild != NULL && n->RChild != NULL) {  // κόμβος προς διαγραφή με δύο παιδιά
                 //Βρες τον ενδοδιατεταγμένο επόμενο και τον πατέρα του
        nNext = n->RChild;
                 Parent = n;
                 while (nNext->LChild !=NULL)  //* DIASXISH PROS TA ARISTERA *)
                 {
                      Parent = nNext;
                      nNext = nNext->LChild;
                 }
                /* Αντιγραφή των περιεχομένων του nNext στον n και
                αλλαγή του n ώστε να δείχνει στον επόμενο */
                n->Data = nNext->Data;
                n = nNext;
          } //Συνεχίζουμε με την περίπτωση που ο κόμβος έχει το πολύ 1 παιδί
          SubTree = n->LChild;
          if (SubTree == NULL)
             SubTree = n->RChild;
          if (Parent == NULL)                 //* 8A DIAGRAFEI H RIZA *)
             *Root = SubTree;
          else if (Parent->LChild == n)
                  Parent->LChild = SubTree;
               else
                   Parent->RChild = SubTree;
          free(n);
     }
}


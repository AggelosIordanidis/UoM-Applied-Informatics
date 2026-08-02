#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
  char am[9], name[11], surname[11];
} BinTreeElementType;
typedef struct BinTreeNode *BinTreePointer;
typedef struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} BinTreeNode;

void CreateBST(BinTreePointer *Root);
bool EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, bool *Found, BinTreePointer *LocPtr, int *nodes);
void BuildBST(BinTreePointer *Root);

int main() {
  BinTreePointer LocPtr, ATree;
  BinTreeElementType AnItem;
  bool found;
  int i, count;
  CreateBST(&ATree);
  BuildBST(&ATree);
  for (i=0; i<3; i++) {
    count = 0;
    printf("Give am:");
    scanf("%9s", AnItem.am);
    BSTSearch(ATree, AnItem, &found, &LocPtr, &count);
    if (!found) {
      printf("komboi=%d o foithths den brethike sto DDA\n", count);
    } else {
      printf("komboi=%d AM=%s Onoma=%s Epwnymo=%s\n", count, LocPtr->Data.am, LocPtr->Data.name, LocPtr->Data.surname);
    }
  }
  return 0;
}

void CreateBST(BinTreePointer *Root){
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
    int res = strcmp(Item.am, LocPtr->Data.am);
    if (res < 0)
        LocPtr = LocPtr->LChild;
    else if (res > 0)
        LocPtr = LocPtr->RChild;
    else
        Found = true;
    }
  if (!Found) {
    LocPtr = (BinTreePointer)malloc(sizeof(struct BinTreeNode));
    strcpy(LocPtr->Data.am, Item.am);
    strcpy(LocPtr->Data.name, Item.name);
    strcpy(LocPtr->Data.surname, Item.surname);
    LocPtr->LChild = NULL;
    LocPtr->RChild = NULL;
    if (Parent == NULL)
        *Root = LocPtr;
    else if (strcmp(Item.am, Parent->Data.am) < 0)
        Parent->LChild = LocPtr;
    else
        Parent->RChild = LocPtr;
    }
}
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, bool *Found, BinTreePointer *LocPtr, int *nodes) {
  *LocPtr = Root;
  *Found = false;
  while (!(*Found) && (*LocPtr) != NULL) {
    int res = strcmp(KeyValue.am, (*LocPtr)->Data.am);
    if (res < 0)
        *LocPtr = (*LocPtr)->LChild;
    else if (res > 0)
        *LocPtr = (*LocPtr)->RChild;
    else
        *Found = true;
    (*nodes)++;
  }
}
void BuildBST(BinTreePointer *Root) {
  FILE *infile;
  BinTreeElementType item;
  infile = fopen("i31f5.txt", "r");
  if (infile == NULL) {
    printf("Cannot open input file.\n");
    exit(1);
  }
  while (true) {
    int nscan = fscanf(infile, "%s %s %s", item.am, item.name, item.surname);
    if (nscan == EOF) break;
    BSTInsert(Root, item);
  }
  fclose(infile);
}

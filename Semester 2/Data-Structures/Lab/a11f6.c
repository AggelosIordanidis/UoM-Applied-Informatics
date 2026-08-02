#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define HMax 7

typedef int ListElementType;
typedef int KeyType;
typedef struct HashNode *HashPointer;
typedef struct HashNode{
  KeyType Key;
  ListElementType Data;
  HashPointer Next;
} HashNode;
typedef HashPointer HashType[HMax];

void CreateHashWithChaining(HashType HashTable);
int HashKey(KeyType Key);
void InsertItem(HashType HashTable,HashNode Item);
bool SearchHash(HashType HashTable,KeyType KeyArg,HashPointer *Loc,HashPointer *Pred);
void DeleteItem(HashType HashTable,KeyType KeyArg);
void menu(int *choice);
void printHashTable(HashType HashTable);
void printHashTable2(HashType HashTable);

int main(){
  int choice;
  char ch;
  HashType HList;
  HashNode AnItem;
  KeyType AKey;
  HashPointer Loc, Pred;
  CreateHashWithChaining(HList);
  printHashTable(HList);
  do {
    menu(&choice);
    switch(choice) {
        case 1: do {
            printf("Enter the key for insertion in the Hash: ");
            scanf("%d", &AnItem.Key);
            printf("Enter the data for insertion in the Hash: ");
            scanf("%d", &AnItem.Data);
            InsertItem(HList, AnItem);
            printf("Continue Y/N: ");
            do {
              scanf(" %c", &ch);
            } while (toupper(ch) != 'N' && toupper(ch) != 'Y');
        } while (toupper(ch) != 'N');
        break;
        case 2: printf("Enter a number for deleting in the Hash: ");
            scanf("%d", &AKey);
            DeleteItem(HList, AKey);
        break;
        case 3: printf("Enter a number for searching in the Hash: ");
            scanf("%d", &AKey);
            if (SearchHash(HList,AKey,&Loc,&Pred))
              printf("TO KLEIDI YPARXEI \n");
            else
              printf("DEN YPARXEI EGGRAFH ME KLEIDI %d\n", AKey);
        break;
        case 4: printHashTable(HList);
            break;
        case 5: printHashTable2(HList);
            break;
    }
  } while (choice != 6);

}

int HashKey(KeyType Key) {
  return Key % HMax;
}

void CreateHashWithChaining(HashType HashTable) {
  int i;
  for (i=0;i<HMax;i++) HashTable[i] = NULL;
}

void InsertItem(HashType HashTable, HashNode Item){
  int HVal;
  HashPointer newNode, Loc, Pred;

  if (SearchHash(HashTable, Item.Key, &Loc, &Pred)){
    printf("YPARXEI HDH TO KLEIDI\n");
  } else {
    newNode = (HashPointer)malloc(sizeof(struct HashNode));
    newNode->Key = Item.Key;
    newNode->Data = Item.Data;
    newNode->Next = NULL;

    HVal = HashKey(Item.Key);

    if (HashTable[HVal] == NULL){
      HashTable[HVal] = newNode;
    } else {
      HashPointer temp = HashTable[HVal];
      while (temp->Next != NULL){
        temp = temp->Next;
      }
      temp->Next = newNode;
    }
  }
}

bool SearchHash(HashType HashTable,KeyType KeyArg,HashPointer *Loc,HashPointer *Pred) {
  int HVal;
  bool found = false;
  HVal = HashKey(KeyArg);
  if (HashTable[HVal] == NULL){
    *Loc = NULL;
    *Pred = NULL;
  } else {
    *Pred = NULL;
    *Loc = HashTable[HVal];
    while (*Loc != NULL && !found) {
        if (KeyArg == (*Loc)->Key) {
          found=true;
        } else {
          *Pred=*Loc;
          *Loc=(*Loc)->Next;
        }
    }
  }
  return found;
}

void DeleteItem(HashType HashTable,KeyType KeyArg) {
  HashPointer Loc, Pred;
  int HVal;
  if (SearchHash(HashTable,KeyArg,&Loc,&Pred)){
    if (Pred != NULL) {
        Pred->Next = Loc->Next;
    } else {
        HVal = HashKey(KeyArg);
        HashTable[HVal] = Loc->Next;
    }
    free(Loc);
  }
  else printf("DEN BRETHKE TO KLEIDI \n");
}

void menu(int *choice) {
  printf("\n                  MENOY                  \n");
  printf("-------------------------------------------------\n");
  printf("1. EISAGWGH EGGRAFHS\n");
  printf("2. DIAGRAFH EGGRAFHS\n");
  printf("3. ANAZHTHSH EGGRAFHS\n");
  printf("4. EMFANISH DOMHS\n");
  printf("5. EMFANISH DOMHS2\n");
  printf("6. EXIT\n");
  printf("CHOICE: ");
  do {
    scanf("%d", choice);
  } while (*choice<1 || *choice>6);
}


void printHashTable(HashType HashTable) {
  int i;
  HashPointer temp ;
  for (i=0;i<HMax;i++)
    if (HashTable[i] == NULL) printf ("%d, Null\n", i);
    else {
      printf("%d: ", i);
      temp = HashTable[i];
      while (temp != NULL) {
        printf("[%d, %d]->",temp->Key, temp->Data);
        temp = temp->Next;
      }
      printf("End of list\n");
    }
}

void printHashTable2(HashType HashTable) {
  int i;
  HashPointer temp;
  for (i=0;i<HMax;i++) {
    if (HashTable[i] != NULL) {
      printf("%d: ", i);
      temp = HashTable[i];
      while (temp != NULL) {
        printf("[%d, %d]->", temp->Key, temp->Data);
        temp = temp->Next;
      }
      printf("End of list\n");
    }
  }
}

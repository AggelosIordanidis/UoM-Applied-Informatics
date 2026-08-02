#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char BinTreeElementType[20];

typedef struct BinTreeNode *BinTreePointer;
typedef struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} BinTreeNode;

void CreateBST(BinTreePointer *Root);
bool EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, bool *Found, BinTreePointer *LocPtr);
void InorderTraversal(BinTreePointer Root);
void CreateDictionary(BinTreePointer *Root, FILE *fp);
int SpellingCheck(BinTreePointer Root, FILE *fp);


int main()
{

   BinTreePointer ARoot;
   FILE *fp1,*fp2;
   int NCount;

   CreateBST(&ARoot);

   fp1 = fopen("i112f5.txt", "r");

   if (fp1==NULL) {
    printf("Error opening dictionary file!\n");
    return 1;
   }

   CreateDictionary(&ARoot, fp1);
   fclose(fp1);

   printf("Dictionary Words\n");

   InorderTraversal(ARoot);
   printf("\n");

   fp2 = fopen("i111f5.txt", "r");
   if(fp2==NULL){
    printf("Error opening text file!\n");
    return 1;
   }

   printf("Words not in Dictionary\n");
   NCount = SpellingCheck(ARoot, fp2);
   fclose(fp2);

   printf("Words of words not in Dictionary: %d\n", NCount);


	return 0;
}

void CreateDictionary(BinTreePointer *Root, FILE *fp){
     BinTreeElementType word;
     while (fscanf(fp, "%s", word) != EOF){
            BSTInsert(Root, word);
     }
}

int SpellingCheck(BinTreePointer Root , FILE *fp){
     BinTreeElementType word;
     bool Found;
     BinTreePointer LocPtr;
     int count = 0;
     while (fscanf(fp, "%s", word) != EOF) {
        BSTSearch(Root, word, &Found, &LocPtr);
        if (!Found) {
            printf("%s\n", word);
            count++;
        }
    }
    return count;
}


void CreateBST(BinTreePointer *Root)
/* Λειτουργία: Δημιουργεί ένα κενό ΔΔΑ.
   Επιστρέφει:  Τον μηδενικό δείκτη(NULL) Root
*/
{
    *Root = NULL;
}

bool EmptyBST(BinTreePointer Root)
/* Δέχεται:   Ενα ΔΔα με το Root να δείχνει στη ρίζα του.
  Λειτουργία: Ελέγχει αν το ΔΔΑ είναι κενό.
  Επιστρέφει: true αν το ΔΔΑ είναι κενό και false διαφορετικά
*/
{   return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item) {
    BinTreePointer LocPtr, Parent;
    bool Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = false;

    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;

        int res = strcmp(Item, LocPtr->Data);
        if (res < 0)
            LocPtr = LocPtr->LChild;
        else if (res > 0)
            LocPtr = LocPtr->RChild;
        else
            Found = true;
    }

    if (!Found) {
        LocPtr = (BinTreePointer)malloc(sizeof(struct BinTreeNode));
        strcpy(LocPtr->Data, Item);
        LocPtr->LChild = NULL;
        LocPtr->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (strcmp(Item, Parent->Data) < 0)
            Parent->LChild = LocPtr;
        else
            Parent->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, bool *Found, BinTreePointer *LocPtr) {
    *LocPtr = Root;
    *Found = false;
    while (!(*Found) && (*LocPtr) != NULL) {
        int res = strcmp(KeyValue, (*LocPtr)->Data);
        if (res < 0)
            *LocPtr = (*LocPtr)->LChild;
        else if (res > 0)
            *LocPtr = (*LocPtr)->RChild;
        else
            *Found = true;
    }
}


void InorderTraversal(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί ενδοδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (!EmptyBST(Root)) {
        InorderTraversal(Root->LChild);
        printf("%s\n",Root->Data);
        InorderTraversal(Root->RChild);
    }
}

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define ListLimit 50
typedef struct {
   int am;
   char name[21];
} ListElementType;
typedef struct {
    int Size;
    ListElementType Element[ListLimit];
} ListType;

void CreateList(ListType *List);
bool EmptyList(ListType List);
bool FullList(ListType List);
void Insert(ListType *List, ListElementType Item, int Pos);
void Delete(ListType *List, int Pos);
void TraverseList(ListType List);
int search(ListType List, ListElementType AnItem);

int main () {
    int Apos, i, foundPos;
    ListElementType AnItem;
    ListType AList;
    CreateList(&AList);
    for (i=1; i<=3; i++) {
        printf("DWSE AM : ");
        scanf("%d", &AnItem.am);
        while (getchar() != '\n');
        printf("DWSE Name : ");
        scanf("%20[^\n]", AnItem.name);
        while (getchar() != '\n');
        Insert(&AList, AnItem, -1);
    }
    TraverseList(AList);
    printf("DWSE AM : ");
    scanf("%d", &AnItem.am);
    foundPos = search(AList, AnItem);
    if (foundPos != -1) {
        Delete(&AList, foundPos);
    }
    TraverseList(AList);
    return 0;
}

void CreateList(ListType *List) {
    List -> Size = 0;
}
bool EmptyList(ListType List) {
    return (List.Size == 0);
}
bool FullList(ListType List) {
    return (List.Size == (ListLimit));
}
void Insert(ListType *List, ListElementType Item, int Pos) {
    int i;
    if (FullList(*List))
        printf("Full list...\n");
    else
    {
        for (i=List->Size-1; i>=Pos+1;i--)
            List->Element[i+1] = List ->Element[i];
        List->Element[Pos+1]=Item;
        List->Size++;
    }
}
void Delete(ListType *List, int Pos) {
    int i;
    if (EmptyList(*List))
        printf("Empty list...\n");
    else
    {
        for (i=Pos; i<List->Size-1; i++)
            List->Element[i] = List ->Element[i+1];
        List->Size--;
    }
}
void TraverseList(ListType List){
    int i;
    if (EmptyList(List))
      	printf("Empty List\n");
    else
    {
        printf("\nPlithos stoixeiwn sth lista %d\n",List.Size);
        for (i=0;i<List.Size;i++)
            printf("%d, %s\n",List.Element[i].am, List.Element[i].name);
    }
    printf("\n");
}
int search(ListType List, ListElementType AnItem) {
    int i;
    for (i = 0; i < List.Size; i++) {
        if (List.Element[i].am == AnItem.am) {
            return i;
        }
    }
    return -1;
}

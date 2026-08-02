#include <stdio.h>
#include <stdbool.h>
#define StackLimit 80

typedef char StackElementType;
typedef struct {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

void CreateStack(StackType *Stack);
bool EmptyStack(StackType Stack);
bool FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);

int main() {
    StackType box, temp;
    int prices[StackLimit], tempPrices[StackLimit];
    int n, price;
    char size, item;
    int i;
    CreateStack(&box);
    printf("Give number of items ");
    scanf("%d", &n);
    printf("Give the items to store\n");
    for (i = 0; i < n; i++) {
        printf("Give price ");
        scanf("%d", &price);
        printf("Give size ");
        scanf(" %c", &size);
        Push(&box, size);
        prices[box.Top] = price;
    }
    printf("Items in the box\n");
    printf("plithos sto stack %d\n", box.Top + 1);
    for (i = 0; i <= box.Top; i++)
        printf("%c, %d\n", box.Element[i], prices[i]);
    printf("What size do you want? ");
    scanf(" %c", &size);
    CreateStack(&temp);
    int tempTop = -1;
    int found = 0;
    while (!EmptyStack(box)) {
        price = prices[box.Top];
        Pop(&box, &item);
        if (item == size) {
            found = 1;
            break;
        }
        tempTop++;
        tempPrices[tempTop] = price;
        Push(&temp, item);
    }
    if (found)
        printf("Found the size %c\n", size);
    else
        printf("Not Found the size %c\n", size);
    printf("Items in the box\n");
    printf("plithos sto stack %d\n", box.Top + 1);
    for (i = 0; i <= box.Top; i++)
        printf("%c, %d\n", box.Element[i], prices[i]);
    printf("Items out of the box\n");
    printf("plithos sto stack %d\n", temp.Top + 1);
    for (i = 0; i <= temp.Top; i++)
        printf("%c, %d\n", temp.Element[i], tempPrices[i]);
    while (!EmptyStack(temp)) {
        price = tempPrices[tempTop];
        Pop(&temp, &item);
        tempTop--;
        Push(&box, item);
        prices[box.Top] = price;
    }
    printf("Items in the box\n");
    printf("plithos sto stack %d\n", box.Top + 1);
    for (i = 0; i <= box.Top; i++)
        printf("%c, %d\n", box.Element[i], prices[i]);
    printf("Items out of the box\n");
    printf("plithos sto stack 0\n");

    return 0;
}

void CreateStack(StackType *Stack) {
    Stack->Top = -1;
}

bool EmptyStack(StackType Stack) {
    return (Stack.Top == -1);
}

bool FullStack(StackType Stack) {
    return (Stack.Top == StackLimit - 1);
}

void Push(StackType *Stack, StackElementType Item) {
    if (!FullStack(*Stack)) {
        Stack->Top++;
        Stack->Element[Stack->Top] = Item;
    }
}

void Pop(StackType *Stack, StackElementType *Item) {
    if (!EmptyStack(*Stack)) {
        *Item = Stack->Element[Stack->Top];
        Stack->Top--;
    }
}

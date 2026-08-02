#include <stdio.h>
#include <stdbool.h>
#define StackLimit 80

typedef char StackElementType;
typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

void CreateStack(StackType *Stack);
bool EmptyStack(StackType Stack);
bool FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);

int main () {
  StackType s;
    StackElementType ch, topChar;
    bool foundC = false;
    bool isCorrect = true;
    CreateStack(&s);
    printf("Enter string:\n");
    while (isCorrect) {
        scanf(" %c", &ch);
        while (getchar() != '\n');
        if (ch == '#') {
            break;
        }
        if (!foundC) {
            if (ch == 'C') {
                foundC = true;
            } else {
                Push(&s, ch);
            }
        }
        else {
            if (!EmptyStack(s)) {
                Pop(&s, &topChar);
                if (ch != topChar) {
                    isCorrect = false;
                }
            } else {
                isCorrect = false;
            }
        }
    }
    if (foundC && isCorrect && EmptyStack(s)) {
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }
    return 0;
}

void CreateStack(StackType *Stack) {
    Stack -> Top = -1;
}
bool EmptyStack(StackType Stack) {
    return (Stack.Top == -1);
}
bool FullStack(StackType Stack) {
    return (Stack.Top == (StackLimit - 1));
}
void Push(StackType *Stack, StackElementType Item) {
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}
void Pop(StackType *Stack, StackElementType *Item) {
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

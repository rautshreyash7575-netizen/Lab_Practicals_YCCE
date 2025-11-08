#include <stdio.h>
#include <string.h>
#define MAX 50   
int stack[MAX];
int top = -1;   

void push(int value) {
    if (top == MAX - 1) {
        printf("\nStack Overflow! Cannot push %d\n", value);
    } else {
        stack[++top] = value;
        printf("%d pushed onto stack.\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("\nStack Underflow! Cannot pop element.\n");
    } else {
        printf("%d popped from stack.\n", stack[top--]);
    }
}


void display() {
    if (top == -1) {
        printf("\nStack is empty.\n");
    } else {
        printf("\nCurrent Stack (Top to Bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}


void checkPalindrome() {
    char str[50];
    int len, i, mid, flag = 1;

    printf("\nEnter a string to check palindrome: ");
    scanf("%s", str);
    len = strlen(str);
    top = -1;  

    
    for (i = 0; i < len / 2; i++) {
        push(str[i]);
    }

   
    if (len % 2 != 0) {
        i++;
    }

    
    for (; i < len; i++) {
        if (str[i] != stack[top--]) {
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("\nThe string '%s' is a Palindrome.\n", str);
    else
        printf("\nThe string '%s' is NOT a Palindrome.\n", str);
}

void demonstrateOverflowUnderflow() {
    printf("\n--- Demonstrating Overflow ---\n");
    top = -1; 
    for (int i = 0; i <= MAX; i++) {
        push(i);
    }

    printf("\n--- Demonstrating Underflow ---\n");
    for (int i = 0; i <= MAX; i++) {
        pop();
    }
}

int main() {
    int choice, value;

    printf("----- STACK OPERATIONS USING ARRAY -----\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push an Element onto Stack\n");
        printf("2. Pop an Element from Stack\n");
        printf("3. Check Palindrome using Stack\n");
        printf("4. Demonstrate Overflow and Underflow\n");
        printf("5. Display Stack Status\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            checkPalindrome();
            break;

        case 4:
            demonstrateOverflowUnderflow();
            break;

        case 5:
            display();
            break;

        case 6:
            printf("\nExiting program.\n");
            return 0;

        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
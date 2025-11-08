#include <stdio.h>
#define MAX 50   // maximum size of queue

char queue[MAX];
int front = -1, rear = -1;

// Function to check if queue is full
int isFull() {
    return rear == MAX - 1;
}

// Function to check if queue is empty
int isEmpty() {
    return (front == -1 || front > rear);
}

// Function to insert (enqueue) an element into the queue
void insert(char value) {
    if (isFull()) {
        printf("\nQueue Overflow! Cannot insert '%c'\n", value);
        return;
    }
    if (front == -1) {
        front = 0;  // first element insertion
    }
    queue[++rear] = value;
    printf("Inserted '%c' into the queue.\n", value);
}

// Function to delete (dequeue) an element from the queue
void delete() {
    if (isEmpty()) {
        printf("\nQueue Underflow! Cannot delete element.\n");
        return;
    }
    printf("Deleted '%c' from the queue.\n", queue[front++]);

    if (front > rear) {  // reset when queue becomes empty
        front = rear = -1;
    }
}

// Function to display queue elements
void display() {
    if (isEmpty()) {
        printf("\nQueue is empty.\n");
        return;
    }
    printf("\nCurrent Queue (Front to Rear):\n");
    for (int i = front; i <= rear; i++) {
        printf("%c ", queue[i]);
    }
    printf("\n");
}

// Function to demonstrate overflow and underflow
void demonstrateOverflowUnderflow() {
    printf("\n--- Demonstrating Overflow ---\n");
    front = rear = -1;
    for (int i = 0; i <= MAX; i++) {
        insert('A' + (i % 26));  // inserting characters A-Z repeatedly
    }

    printf("\n--- Demonstrating Underflow ---\n");
    for (int i = 0; i <= MAX; i++) {
        delete();
    }
}

// Main Function
int main() {
    int choice;
    char value;

    printf("----- QUEUE OPERATIONS USING ARRAY -----\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an Element into Queue\n");
        printf("2. Delete an Element from Queue\n");
        printf("3. Demonstrate Overflow and Underflow\n");
        printf("4. Display Queue Status\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter a character to insert: ");
            scanf(" %c", &value); // space before %c to ignore newline
            insert(value);
            break;

        case 2:
            delete();
            break;

        case 3:
            demonstrateOverflowUnderflow();
            break;

        case 4:
            display();
            break;

        case 5:
            printf("\nExiting program.\n");
            return 0;

        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
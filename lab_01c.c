#include <stdio.h>

struct Student {
    int rollNo;
    char name[50];
    int age;
    float avgMarks;
};

void bubbleSort(struct Student s[], int n) {
    struct Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].avgMarks < s[j + 1].avgMarks) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    for (int i = 0; i < n; i++) {
        printf("Roll No: ");
        scanf("%d", &s[i].rollNo);

        printf("Name: ");
        scanf(" %[^\n]", s[i].name);

        printf("Age: ");
        scanf("%d", &s[i].age);

        printf("Average Marks: ");
        scanf("%f", &s[i].avgMarks);
    }

    bubbleSort(s, n);

    printf("\nSorted Students (by Average Marks):\n");
    for (int i = 0; i < n; i++) {
        printf("%d %s %d %.2f\n",
               s[i].rollNo, s[i].name, s[i].age, s[i].avgMarks);
    }

    return 0;
}

#include <stdio.h>

void analyzeMarks(int *marks, int count) {
    printf("\nStudent\tMarks\tCategory\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%d\t", i + 1, marks[i]);

        if (marks[i] < 35)
            printf("Fail");
        else if (marks[i] <= 69)
            printf("Pass");
        else if (marks[i] <= 84)
            printf("Merit");
        else
            printf("Distinction");

        printf("\n");
    }
}

int main() {
    FILE *fp;
    int marks[100], count = 0;

    fp = fopen("marks.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fscanf(fp, "%d", &marks[count]) != EOF) {
        count++;
    }

    fclose(fp);

    analyzeMarks(marks, count);

    return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/wait.h>

sem_t sem1, sem2, sem3;

void printTable(int num, sem_t *current, sem_t *next) {
    sem_wait(current);
    printf("\nTable of %d:\n", num);
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
    }
    sem_post(next);
}

int main() {
    sem_init(&sem1, 0, 1);
    sem_init(&sem2, 0, 0);
    sem_init(&sem3, 0, 0);

    if (fork() == 0) {
        printTable(2, &sem1, &sem2);
        return 0;
    }
    if (fork() == 0) {
        printTable(3, &sem2, &sem3);
        return 0;
    }
    if (fork() == 0) {
        printTable(4, &sem3, &sem1);
        return 0;
    }

    wait(NULL);
    wait(NULL);
    wait(NULL);

    sem_destroy(&sem1);
    sem_destroy(&sem2);
    sem_destroy(&sem3);

    return 0;
}

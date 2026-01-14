#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

int main() {
    FILE *fp;
    char ch;
    int vowels = 0, consonants = 0;

    pid_t pid = fork();

    if (pid > 0) {   // Parent process
        fp = fopen("text.txt", "w");
        fprintf(fp, "Operating Systems");
        fclose(fp);
    } 
    else {           // Child process
        sleep(1);    // Ensure parent writes first
        fp = fopen("text.txt", "r");

        while ((ch = fgetc(fp)) != EOF) {
            ch = tolower(ch);
            if (ch >= 'a' && ch <= 'z') {
                if (ch == 'a' || ch == 'e' || ch == 'i' ||
                    ch == 'o' || ch == 'u')
                    vowels++;
                else
                    consonants++;
            }
        }
        fclose(fp);

        printf("Vowels: %d\n", vowels);
        printf("Consonants: %d\n", consonants);
    }

    return 0;
}

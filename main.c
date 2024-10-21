#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SHI 1
#define FU 2
#define MI 3
#define MAX_LENGHT 3
#include "func.c"
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int shi;
int fu;
int mi;
int score;
char input[MAX_LENGHT];
char input2[MAX_LENGHT];
int inp1;
int inp2;
int score1 = 0;
int score2 = 0;
char prenom1[20];
char prenom2[20];




int main() {
    printf("Entrez Prénom 1 >\n");
    fgets(prenom1, 20, stdin);
    prenom1[strcspn(prenom1, "\n")] = 0; // remove newline character
    printf("Entrez Prénom 2 >\n");
    fgets(prenom2, 20, stdin);
    prenom2[strcspn(prenom2, "\n")] = 0; // remove newline character
    system("clear");
    printf("open with a save file ? y/n \n");
    char savea[2];  
    fgets(savea, 2, stdin);
    savea[strcspn(savea, "\n")] = 0; 
    if (strcmp("y", savea) == 0) {
        load_score(prenom1, prenom2, &score1, &score2);
    } else {
        save_score(prenom1, prenom2, 0, 0);
    }

    while (1) {
        system("clear");
        printf("---------------------- ShiFuMi ! --------------------\n");
        printf("%s ? : 1 - Shi // 2 - Fu // 3 - Mi //  0 for exit \n", prenom1);
        fgets(input, MAX_LENGHT, stdin);
        inp1 = atoi(input);
        if(inp1 == 0) {
            exit(0);
        }
        system("clear");
        printf("%s ? : 1 - Shi // 2 - Fu // 3 - Mi //  0 for exit\n", prenom2);
        fgets(input2, MAX_LENGHT, stdin);
        inp2 = atoi(input2);
        if(inp2 == 0) {
            exit(0);
        }
        system("clear");
        switch (inp1) {
            case SHI:
                switch (inp2) {
                    case SHI:
                        printf("égalité\n");
                        break;
                    case FU:
                        printf("%s a perdu\n", prenom1);
                        score2++;
                        break;
                    case MI:
                        printf("%s  a gagné\n", prenom1);
                        score1++;
                        break;
                    default:
                        printf("Entrée invalide\n");
                        break;
                }
                break;
            case FU:
                switch (inp2) {
                    case SHI:
                        printf("%s a gagné\n", prenom2);
                        score2++;
                        break;
                    case FU:
                        printf("égalité\n");
                        break;
                    case MI:
                        printf("%s a perdu\n", prenom2);
                        score1++;
                        break;
                    default:
                        printf("Entrée invalide\n");
                        break;
                }
                break;
            case MI:
                switch (inp2) {
                    case SHI:
                        printf("%s a perdu\n", prenom2);
                        score1++;
                        break;
                    case FU:
                        printf("égalité\n");
                        break;
                    case MI:
                        printf("%s a gagné\n", prenom2);
                        score2++;
                        break;
                    default:
                        printf("Entrée invalide\n");
                        break;
                }
                break;
            default:
                printf("Entrée invalide\n");
                break;
        }
        printf("Le score de %s est de :%d\n", prenom1, score1);
        printf("Le score de %s est de :%d\n", prenom2, score2);
        printf("Appuyez sur entrée pour continuer..\n");
        getchar();
        system("clear");
        save_score(prenom1, prenom2, score1, score2);
    }
    return 0;
}
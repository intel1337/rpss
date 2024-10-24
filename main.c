#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "func.c"

#define SHI 1
#define FU 2
#define MI 3
#define MAX_LENGTH 3

int shi;
int fu;
int mi;

int score;

int inp1;
int inp2;

int score1 = 0;
int score2 = 0;

char input[MAX_LENGTH];
char input2[MAX_LENGTH];

char prenom1[50];
char prenom2[50];

/*
████████  
██          ██  
██          ██  
████████
*/

void save_score(char *prenom1, char *prenom2, int score1, int score2) {
    FILE *fptr = fopen("save.txt", "w");
    if(fptr == NULL) {
        printf("Error opening file\n");
        return;
    }
    fprintf(fptr, "Player1 :%s\n", prenom1);
    if(score1 > 1){
        fprintf(fptr, "Wins :%d\n", score1);
    } else {
        fprintf(fptr, "Win :%d\n", score1);
    }
    fprintf(fptr, "Player2 :%s\n", prenom2);
    if(score2 > 1){
        fprintf(fptr, "Wins :%d\n", score2);
    } else {
        fprintf(fptr, "Win :%d\n", score2);
    }
    fclose(fptr);
}
void load_score(char *prenom1, char *prenom2, int *score1, int *score2) {
    FILE *fptr = fopen("save.txt", "r+");
    if(fptr == NULL) {
        printf("Error opening file\n");
        return;
    }
    fscanf(fptr, "Player1 :%[^\n]\n", prenom1);
    fscanf(fptr, "Win :%d\n", score1);
    fscanf(fptr, "Player2 :%[^\n]\n", prenom2);
    fscanf(fptr, "Win :%d\n", score2);
    fclose(fptr);
}
void ascii(){
    printf("      ::::::::  :::    ::: ::::::::::: :::::::::: :::    :::   :::   :::   :::::::::::\n");
    printf("    :+:    :+: :+:    :+:     :+:     :+:        :+:    :+:  :+:+: :+:+:      :+:     \n");
    printf("   +:+        +:+    +:+     +:+     +:+        +:+    +:+ +:+ +:+:+ +:+     +:+      \n");
    printf("  +#++:++#++ +#++:++#++     +#+     :#::+::#   +#+    +:+ +#+  +:+  +#+     +#+       \n");
    printf("        +#+ +#+    +#+     +#+     +#+        +#+    +#+ +#+       +#+     +#+        \n");
    printf("#+#    #+# #+#    #+#     #+#     #+#        #+#    #+# #+#       #+#     #+#         \n");
    printf("########  ###    ### ########### ###         ########  ###       ### ###########      \n");
    printf("\n");

}
int main() {
    system("clear");
    ascii();
    // Prenom 1
    printf("█████████████████████ \n");
    printf("██Entrez Prénom 1 >██\n");
    printf("█████████████████████\n");
    printf("\n>");
    fgets(prenom1, 50, stdin);
    prenom1[strcspn(prenom1, "\n")] = 0; 
    ascii();
    // Prenom 2
    printf("█████████████████████ \n");
    printf("██Entrez Prénom 2 >██\n");
    printf("█████████████████████\n");
    printf("\n>");
    fgets(prenom2, 50, stdin);
    prenom2[strcspn(prenom2, "\n")] = 0; 

    system("clear");
    ascii();
    printf("Open with a save file ? y/n \n");
    char savea[MAX_LENGTH];
    printf(">");
    fgets(savea, MAX_LENGTH, stdin);
    savea[strcspn(savea, "\n")] = 0; 
    // Save File
    if (strcmp("y", savea) == 0) {
        load_score(prenom1, prenom2, &score1, &score2);
    } else {
        save_score(prenom1, prenom2, 0, 0);
    }
    // Loop
    /**/
    while (1) {
    system("clear");
    ascii();
    printf("                    %s ? : 1 - Shi // 2 - Fu // 3 - Mi //  0 for exit \n", prenom1);
    printf(">");
    fgets(input, MAX_LENGTH, stdin);
    strtok(input, "\n"); // Remove the newline character
    if (strcmp(input, "0") == 0) {
        break;
    }
    inp1 = atoi(input);

    system("clear");
    ascii();
    printf("                    %s ? : 1 - Shi // 2 - Fu // 3 - Mi //  0 for exit\n", prenom2);
    printf(">");
    fgets(input2, MAX_LENGTH, stdin);
    strtok(input2, "\n"); // Remove the newline character
    if (strcmp(input2, "0") == 0) {
        break;
    }
    inp2 = atoi(input2);

        system("clear");
        ascii();
        // main switch
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
        }
        // End
        
        printf("Le score de %s est de :%d\n", prenom1, score1);
        printf("Le score de %s est de :%d\n", prenom2, score2);
        sleep(4);
        system("clear");
        save_score(prenom1, prenom2, score1, score2);
    }
    return 0;
}


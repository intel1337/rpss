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

#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"
#define UBLK "\e[4;30m"
#define URED "\e[4;31m"
#define UGRN "\e[4;32m"
#define UYEL "\e[4;33m"
#define UBLU "\e[4;34m"
#define UMAG "\e[4;35m"
#define UCYN "\e[4;36m"
#define UWHT "\e[4;37m"
#define BLKB "\e[40m"
#define REDB "\e[41m"
#define GRNB "\e[42m"
#define YELB "\e[43m"
#define BLUB "\e[44m"
#define MAGB "\e[45m"
#define CYNB "\e[46m"
#define WHTB "\e[47m"
#define BLKHB "\e[0;100m"
#define REDHB "\e[0;101m"
#define GRNHB "\e[0;102m"
#define YELHB "\e[0;103m"
#define BLUHB "\e[0;104m"
#define MAGHB "\e[0;105m"
#define CYNHB "\e[0;106m"
#define WHTHB "\e[0;107m"
#define HBLK "\e[0;90m"
#define HRED "\e[0;91m"
#define HGRN "\e[0;92m"
#define HYEL "\e[0;93m"
#define HBLU "\e[0;94m"
#define HMAG "\e[0;95m"
#define HCYN "\e[0;96m"
#define HWHT "\e[0;97m"
#define BHBLK "\e[1;90m"
#define BHRED "\e[1;91m"
#define BHGRN "\e[1;92m"
#define BHYEL "\e[1;93m"
#define BHBLU "\e[1;94m"
#define BHMAG "\e[1;95m"
#define BHCYN "\e[1;96m"
#define BHWHT "\e[1;97m"
#define reset "\e[0m"
#define CRESET "\e[0m"
#define COLOR_RESET "\e[0m"

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
    printf("%s", MAG);
    printf("      ::::::::  :::    ::: ::::::::::: :::::::::: :::    :::   :::   :::   :::::::::::\n");
    printf("%s", CYN);
    printf("    :+:    :+: :+:    :+:     :+:     :+:        :+:    :+:  :+:+: :+:+:      :+:     \n");
    printf("%s", BLU);
    printf("   +:+        +:+    +:+     +:+     +:+        +:+    +:+ +:+ +:+:+ +:+     +:+      \n");
    printf("%s", WHT);
    printf("  +#++:++#++ +#++:++#++     +#+     :#::+::#   +#+    +:+ +#+  +:+  +#+     +#+       \n");
    printf("%s", BLU);
    printf("        +#+ +#+    +#+     +#+     +#+        +#+    +#+ +#+       +#+     +#+        \n");
    printf("%s", CYN);
    printf("#+#    #+# #+#    #+#     #+#     #+#        #+#    #+# #+#       #+#     #+#         \n");
    printf("%s", MAG);
    printf("########  ###    ### ########### ###         ########  ###       ### ###########      \n");
    printf("\n");
    printf("%s" reset);

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



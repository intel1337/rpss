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
    fclose(fptr); // close the file
}
void load_score(char *prenom1, char *prenom2, int *score1, int *score2) {
    FILE *fptr = fopen("save.txt", "r");
    if(fptr == NULL) {
        printf("Error opening file\n");
        return;
    }
    fscanf(fptr, "Player1 :%[^\n]\n", prenom1);
    fscanf(fptr, "Score1 :%d\n", score1);
    fscanf(fptr, "Player2 :%[^\n]\n", prenom2);
    fscanf(fptr, "Score2 :%d\n", score2);
    fclose(fptr); // close the file
}
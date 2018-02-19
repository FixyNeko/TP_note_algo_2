#include <stdio.h>
#include <stdlib.h>
#define TAILLE_ENSEMBLE 2
#define TAILLE_TABLEAU TAILLE_ENSEMBLE + 1
#define TRUE 1
#define FALSE 0

int estIndependanteM(int matrice[TAILLE_TABLEAU][TAILLE_TABLEAU]){
    int i,j;
    for(i = 1; i < TAILLE_ENSEMBLE; i++){
        for(j = 1; j < TAILLE_ENSEMBLE; j++){
            if(matrice[i][j] == 1){ //si on trouve un seul 1 ça veut dire que R n'est pas vide
                return FALSE;
            }
        }
    }
    return TRUE;
}

int estIndependanteL(int liste[TAILLE_ENSEMBLE]){
    int i;
    for(i = 0; i < TAILLE_ENSEMBLE; i++){
        if(liste[i].suivant != NULL){ //si on trouve un seul non nul, ça veut dire qu'il y a une relation et donc R n'est pas vide
            return FALSE;
        }
    }
    return TRUE;
}

int estCompleteM(int matrice[TAILLE_TABLEAU][TAILLE_TABLEAU]){
    int i,j;
    for(i = 1; i < TAILLE_ENSEMBLE; i++){
        if(matrice[i][i] == 1){ //si on trouve un seul 1 sur la diagonale ça veut dire qu'un element est en relation avec lui meme donc c'est pas complet
            return FALSE;
        }
    }
    return TRUE;
}

int estCompleteL(int liste[TAILLE_ENSEMBLE]){
    //a faire en sinspirant de adjacentL() quand elle sera verifiée
    return FALSE;
}


int main(){

    return 0;
}

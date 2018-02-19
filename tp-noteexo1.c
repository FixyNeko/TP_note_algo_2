#include <stdio.h>
#include <stdlib.h>
#define TAILLE_ENSEMBLE 2
#define TAILLE_TABLEAU TAILLE_ENSEMBLE + 1
#define TRUE 1
#define FALSE 0

/*TODO: remplirL() doit bien marcher, mais besoin de AfficherL() pour etre nsur.
        AfficherL() à debugger (pb dans l'acces aux elements)
        adjacentL() a tester
        coder les deux voisins()
*/

/*
Exo4.1
q1
matrice : taille(V) * taille(V) = O(taille(V)^2)
liste : pour chaque element deux cases : un pour la valeur et un pour l'adresse du suivant et le cas extreme c'est quand
tous les elements sont en relationa avec tous donc => 2 * taille(V) * taille(V) donc O(taille(V)^2) comme la matrice
q2 CODE
q3 adjacentM O(1), une seule instruction
adjacentL au max, O(taille(V)), si tous les y sont en relation avec le x recherche
voisinM O(taille(V))
voisinL complexite est la taille de la liste renvoyee par voisinsL() donc au pire O(taille(V)) mais on peut aussi dire O(taille(voisinL(x)))
*/

struct element{
    int val;
    struct element * suivant;
};

void remplirM(int matrice[TAILLE_TABLEAU][TAILLE_TABLEAU]){
	int i,j;
	int val;
	matrice[0][0] = 8;
	for(i = 1; i <= TAILLE_ENSEMBLE; i++){
        matrice[0][i]=i;
        matrice[i][0]=i;
	}
	for(i = 1; i < TAILLE_TABLEAU; i++){
		for(j = i; j < TAILLE_TABLEAU; j++){
			printf("Entrez la valeur de A[%d][%d]: ",i,j);
			scanf("%d",&val);
			matrice[i][j]=val;
			matrice[j][i]=val;
		}
	}
}

void remplirL(struct element** liste){
	int i,j;
	int val;
	//on etiquette la premiere case de chaque liste
	for(i = 1; i < TAILLE_TABLEAU; i++){
        liste[i] = (struct element*) malloc(sizeof(struct element));
        liste[i]->val = i;
        liste[i]->suivant = NULL;
	}

    printf("Init list done\n");
	// puis on entre les y en relation avec les x
	struct element * elemCourant;

	for(i = 1; i < TAILLE_TABLEAU; i++){
        printf("    i = %d\n", i);
        liste[i]->suivant = (struct element*) malloc(sizeof(struct element));
        elemCourant = liste[i]->suivant;
		for(j = 0; j < TAILLE_ENSEMBLE; j++){
            printf("Entrez la valeur de l'element suivant en relation avec %d : ", i);
			scanf("%d",&val);

			if(val == -1)
                break;

            elemCourant->val = val;
            elemCourant->suivant = (struct element*) malloc(sizeof(struct element));
            printf("%d\n", elemCourant->val);
            elemCourant = elemCourant->suivant;
		}
        elemCourant->suivant = NULL;
        elemCourant->val = -1;
	}
}

void afficheM(int matrice[TAILLE_TABLEAU][TAILLE_TABLEAU]){
	int i,j;
	for(i = 0; i < TAILLE_TABLEAU; i++){
		for(j = 0; j < TAILLE_TABLEAU; j++){
        	printf("%d ",matrice[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void afficheL(struct element **liste){
	int i;
	struct element * elemCourant;
	for(i = 1; i < TAILLE_TABLEAU; i++){
        printf("%d : ", liste[i]->val);
        elemCourant = liste[i];
        printf("val avant while: ");
        printf("%d\n", elemCourant->val);
		while((elemCourant->val != -1) && (elemCourant->suivant != NULL)){
		    printf("%d - ", elemCourant->val);
		    elemCourant = elemCourant->suivant;
        }
        printf("//\n");

    }
}

int adjacentsM(int matrice[TAILLE_TABLEAU][TAILLE_TABLEAU], int x, int y){
    int i;
    int indiceX = 0, indiceY = 0;
    //on trouve l'indice de x et de y dans le tableau
    for(i = 1; i < TAILLE_TABLEAU; i++){
        if(matrice[0][i] == x){
            indiceX = i;
        }
        if(matrice[0][i] == y){
            indiceY = i;
        }
    }
    //on verifie si la case au croisement vaut 1, ce qui veut dire que x et y sont adjacents.
    if(matrice[indiceX][indiceY] == 1){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

int adjacentsL(struct element liste[TAILLE_TABLEAU], int x, int y){
    int i;
    int indiceX;
    for(i = 1; i < TAILLE_TABLEAU; i++){
        if(liste[i].val == x){
            indiceX = i;
            break;
        }
    }
    struct element * next = liste[indiceX].suivant;
    while(liste[indiceX].suivant != NULL){
        if(liste[indiceX].val == y){
            return TRUE;
            break;
        }
        next = next->suivant;
    }
    return FALSE;
}

int voisinsM(){
    //on appelle adjavcent
    return 0;
}

int voisinsL(){
    //on appelle adjacent
    return 0;
}

int main(){
    //matrices : tout marche
    /*int matrice[TAILLE_TABLEAU][TAILLE_TABLEAU];
    remplirM(matrice);
    afficheM(matrice);
    for(i=1;i<=TAILLE_ENSEMBLE;i++){
        for(j=1;j<=TAILLE_ENSEMBLE;j++){
            printf("%d adjactent a %d : %d\n", i, j, adjacentsM(matrice,i,j));
        }
    }*/
    struct element **liste = (struct element**) malloc(TAILLE_TABLEAU * sizeof(struct element*));
    printf("malloc done\n");
    remplirL(liste);
    printf("remplir done\n");
    afficheL(liste);
    
    return 0;
}

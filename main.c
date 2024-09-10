#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define taille 10

int random_number(){
    int number = rand() % 100;
    return number;
}

int* montrer(int* tableau){
    for(int i = 0; i < taille; i++){
        printf("%d ",tableau[i]);
    }
    printf("\n\n");
}

char* calcul_maximal(int* tableau){
    static char resultat[100];
    int number = tableau[0];
    int indice = 0;
    for (int i = 0; i < taille  ; i++){
        if (tableau[i] > number) {
            number = tableau[i];
            indice = i;
        }
    }
    sprintf(resultat, "Le maximum du tableau est : %d et son indice est : %d.\n",number,indice);
    return resultat;
}

char* calcul_minimal(int* tableau){
    static char resultat[100];
    int number = tableau[0];
    int indice = 0;
    for (int i = 0; i < taille  ; i++){
        if (tableau[i] < number) {
            number = tableau[i];
            indice = i;
        }
    }
    sprintf(resultat, "Le minimum du tableau est : %d et son indice est : %d.\n",number,indice);
    return resultat;
}

int* trier(int* tableau){
    for (int i = 0; i < taille; i++){
        for (int j = 0; j < taille; j++){
            if(tableau[j] > tableau[j+1]){
                int temp = tableau[j];
                tableau[j] = tableau[j+1];
                tableau[j+1] = temp;
            }
        }
    }
}

int main() {
    srand(time(0));
    int tableau[taille];

    for(int i = 0; i < taille; i++){
        tableau[i] = random_number();
    }

    printf("\nLe contenu du tableau est le suivant :\n\n");

    montrer(tableau);

    printf("%s",calcul_maximal(tableau));
    printf("%s",calcul_minimal(tableau));

    printf("\n");

    trier(tableau);

    montrer(tableau);

    return 0;
}

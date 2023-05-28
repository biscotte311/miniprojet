#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "library.h"
// Fonction permettant l'affichage d'un résultat ou d'une erreur
void affichage (verification v, char * texte) {
	// initialisation de la variable resultat qui contien le texte
    char * resultat=texte;
	// condtion pour vérifier qu'il n'y a pas d'erreur
    if (v.isVerified==false){
		// affichage d'un message d'erreur
        printf("******************************\n");
        printf("*           Erreur           *\n");
        printf("******************************\n\n");
        printf("Un caractere special a ete rencontre : %s\n", v.c);
        printf("Votre message n'a pas pu etre chiffre ou etre dechiffrer en raison du ce caractere suivant \n");
    } else {
		// affichage du résultat
        printf("Voici le resultat : %s\n",resultat);
        
    }
}
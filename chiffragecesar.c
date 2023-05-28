#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonction pour chiffrer une chaîne de caractères avec le chiffrement de César
char * chiffrement_cesar(char* message, int cle) {
	// initialisation de la longueur du message
    int longueur = strlen(message);
	// initialisation du compteut
    int i;
	// parcour du message
    for (i = 0; i < longueur; i++) {
		// condition dans le cas où le caractères est bien écrivable
        if (message[i] >=' ' && message[i]<= '~' ){
			// modification du caractères
            message[i] = ((message[i] - ' ' + cle) % 95) + ' ';
        }
    }
	// renvoi du message chiffrer
    return message;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Fonction de chiffrement d'un message par la méthode de vigenere
char* chiffrement_vigenere(char* message, char* cle) {
	// initialisation de la longueur du message
	int longueurMessage = strlen(message);
	// initialisation de la longueur de la clé
	int longueurCle = strlen(cle);
	// initialisation de la varaible qui contiendra le message chiffré
	char* messageChiffre = (char*) malloc((longueurMessage + 1) * sizeof(char));
	// parcours du message
	for (int i = 0, j = 0; i < longueurMessage; i++, j++) {
		// condition pour mettre à 0 le compteur j dans le cas où on dépasse la longueur de la clé
        if (j == longueurCle){
            j = 0;
		}
		// variable contenant le caractère à la i éme position du message
        int caractereMessage = message[i];
		// variable contenant le caractère à la i éme position de la clé
        int caractereCle = cle[j];
		// condition pour vérifier que le caractère est bien imprimable
        if (caractereMessage >=' ' && caractereMessage <= '~' ){
			// modification du caractère 
        	int caractereChiffre = ((caractereMessage-' ' + caractereCle-' ') % 95) +' ';
			// condtion dans le cas où le caractère n'est plus imprimable alors on lui retire 95 positions dans la table ascii
        	if (caractereChiffre > '~'){
                caractereChiffre = caractereChiffre- 95;
        	}
			// enregistrement du nouveau caractère
        	messageChiffre[i] = caractereChiffre;
        }
    }
	// retour du message chiffrer
    return messageChiffre;
}




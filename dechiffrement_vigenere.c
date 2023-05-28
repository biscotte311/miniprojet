#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  Fonction pour chiffrer une chaîne de caractères avec le chiffrement de vigenere
char* dechiffrement_vigenere(char* message, char* cle) {
	// initialisation de la longueur du message
	int longueurMessage = strlen(message);
	// initialisation de la longueur de la clé
	int longueurCle = strlen(cle);
	// initialisation de la variable qui contiendra le message déchiffré
	char* messageDechiffre = (char*) malloc((longueurMessage + 1) * sizeof(char));
	// parcour de message à déchiffrer
	for (int i = 0, j = 0; i < longueurMessage; i++, j++) {
		// condition pour mettre à 0 le compteur j dans le cas où on dépasse la longueur de la clé
        if (j == longueurCle){
            j = 0;
		}
		// récupération d'un caractère du message
        int caractereMessage = message[i];
		// récupération d'un caractère de la clé
        int caractereCle = cle[j];
		
		// vérification que le caractère du message est bien imprimable
        if (caractereMessage >=' ' && caractereMessage <= '~' ){
			// modification du caractère
        	int caractereDechiffre = (((caractereMessage - ' ') - (caractereCle -' ')) % 95) +' ';
			// dans le cas où le caractère n'est plus imprimable on rajoute 95 dans la position de la table ascii
        	if (caractereDechiffre < ' '){
                caractereDechiffre = caractereDechiffre + 95;
        	}
			// on enregistre le nouveau caractère
        	messageDechiffre[i] = caractereDechiffre;
        }
    }
	// retour du message déchiffré
    return messageDechiffre;
}


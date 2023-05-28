#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Fonction pour déchiffrer une chaîne de caractères avec le chiffrement de César
char * dechiffrement_cesar(char* message, int cle) {
	// initialisation de la longueur du message
    int longueur = strlen(message);
	//initialisation du compteur i de la boucle for
    int i;
	// clé premetant le déchiffrement du message
    cle = cle % 95;
	// boucle parcourant le message
	for (i = 0; i < longueur; i++) {
		// on vérifie que le caractère est bien imprimable
        if (message[i] >=' ' && message[i]<= '~' ){
			// modification du caractère à la i éme position du message
            message[i] = ' ' + ((message[i] - ' ' - cle ));
			// condition dans le cas ou le caractère modifier n'est plus imprimable
			if (message[i]< ' ') {
				// on rajoute 95 position au caractère dans la table ascii
				message[i]=message[i]+95;
			}
		}
		}
		//retour du message déchiffré
		return message;
        }
    
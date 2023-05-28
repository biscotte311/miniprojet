#include <stdbool.h>
#include <stdio.h>
#include "library.h"

// cette fonction verifie qu'il n'y a pas de charactère special dans le message
// la fonction prend entree un message et renvoie un tuple contenant un booleen indiquant la prese de characteres spiaux et 
// un charactère qui correspond au premier caractère spiecial rencontré, si il n'y en a pas, le char retourne est egal à 0
verification verifier (const char * message){

verification v = {'0', true};
int i = 0;
    // tant que c'est pas la fin du message
    while (message[i] != '\0'){
        // si caractere courant pas dans la table ascii ET different de \n (saut de ligne) de plus 9, correspondant au caractère tab, n'est pas à une erreur
        if((message[i] < ' ' || message[i] > '~') && message[i] != '\n' && message[i]!=9){
            // return caractere problematique et isVerified = false
            v.c = message[i];
            v.isVerified = false;
            return v;
        }
        i++;
    }
    // sinon v = {'0', true} , pour rappel c = 0 signifie qu'il n'y a pas de caractère special dans le message
    return v;
}
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <setjmp.h>
#include <stdlib.h>
#include "library.h"
void main();
char * recuperationDuTexte();
char * cryptageDecriptage(int i, char * texte);
verification v;

void main(){
	// initialisation du point de reprise pour le premier choix de l utilisateur
    jmp_buf ptRep;
	// initialisation du point de reprise dans le cas d'une erreur
    jmp_buf ptRep1;
    // variable qui sauvegarde le choix de l'utilisateur
    char x;
    // varible de suppression des valeurs saisies en trop par l utilisateur
    char c;
    // variable qui contient le texte de l utilisateur
    char * texte;
    // texte apres modification
    char * nouveauTexte;

    printf("Bienvenue dans le logiciel de cryptage de texte\n");
    // nous allons dans un premier temps recuperer le texte de l'utilisateur via la fonction "recuperationDuTexte"
    texte = recuperationDuTexte();
	// vérification que le message ne contient pas de caractère non imprimable via la fonction "verifier"
    v=verifier(texte);
	// condition pour vérifier qu'il n'y a pas d'erreurs
    if(v.isVerified==false){
		// nouveauTexte prend la valeur du texte entré par l'utilisateur
        nouveauTexte=texte;
		// saut du code jusqu'à la fin pour afficher le résultat avec erreur
        longjmp(ptRep1,1);
    }
    // positionnement du point de reprise dans le cas ou la valeur rentré est fausse pour la selection de cryptage ou de decryptage
    setjmp(ptRep);
    
    //affichage de l'option de cryptage ou de decryptage du texte
    printf("Veuillez choisir le mode : \n");
    printf("    - 1 crypter \n");
    printf("    - 2 decrypter \n");
    // recuperation de la premiere valeur
    x = getchar();
    c = getchar();
    //suppression de toutes les valeurs qui suivent
    while (c != '\n'){
        c= getchar();
    }
    
    switch (x){
        // choix du cryptage
        case '1':
			// appelle de la fonction cryptageDecriptage avec la valeur 0 pour le cryptage
            nouveauTexte = cryptageDecriptage(0,texte);
            //affichage(nouveauTexte);
            break;
        // choix du decryptage
        case '2':
			// appelle de la fonction cryptageDecriptage avec la valeur 10 pour le décryptage
            nouveauTexte = cryptageDecriptage(1,texte);
            break;
        // dans le cas ou l utilisateur a rentré une valeur erroné
        default:
            // saut au point de reprise quand la valeur est fausse plus affichage d un message d erreur
            printf("La valeur rentrer ne correspond pas veuillez retenter\n\n");
            longjmp(ptRep, 1);
            break;
    }
	// positionnement du pointeur de reprise dans le cas où une erreur a été rencontrée
    setjmp(ptRep1);
	// envoie des informations à la fonction d'affichage
    affichage(v, nouveauTexte);
    // libération de la mémoire occupée par le texte
    free(texte);

}

// Fonction qui selon le choix de l'utilisateur décrypte ou crypte le message
char * cryptageDecriptage(int i, char * texte){    
	// initialisation du point de reprise pour le premier choix de l'utilisateur
    jmp_buf ptRep;
	// initialisation du point de reprise pour dans le cas où il a rentré une clé erronée pour le chiffrement_cesar
    jmp_buf ptRep1;
	// initialisation de la variable qui enregistrera les caractere de type entier pour la clé  de cesar
    char entier;
	// initialisation de la variable qui enreistrera las caracteres pour la clé de vigenaire
    char caractere;
	// initialisation de la variable qui vérfie si il n'y a pas de dépassement dans la taille de la variable clefc
    int conter;
	// initialisation de la tailleInitial de la variable clefc
    int tailleInitial=10;
	// initialisation de la variable clefc qui contiendra la clef de chiffrement pour vigenaire
    char * clefc= malloc(tailleInitial* sizeof(char));
	// initialisation de la variable clefi qui contiendra la clef de chiffrement pour cesar
    int clefi;
	// initialisation de la variable y qui récupérera le choix de l'uilisateur
    char y;
	// initialisation de la variable qui supprimera toutes valeurs superflues lors de la saisie du choix
    char c;
	// variable qui contiendra le message modifié
    char * nouveauTexte;
    //positionnement du point de reprise dans le cas ou la valeur rentrée est fausse pour la selection du mode de cryptage
    setjmp(ptRep);
    printf("Veuillez choisir le type de cryptage : \n");
    printf("    - 1 César \n");
    printf("    - 2 Vigenère \n");
	// récupéreration de la valeur du choix de l'uilisateur
    y= getchar();
	// suppression des autres valeurs
    c= getchar();
    //suppression de toutes les valeurs qui suivent
    while (c != '\n'){
        c= getchar();
    }
    

	// choix de l'utilisateur
    switch(y){
		// choix de cesar
        case '1': 
			// positionnement du pointeur dans le cas où la clef cesar est erronée
            setjmp(ptRep1);
            printf("Entrer la valeur de la clef : \n");
			// récupération de la clef
            entier = getchar();
			
            conter=0;
            while(entier!='\n'){
				// dans le cas où il y a dépassement de la taille de la variable clefc
                if (conter == tailleInitial){
					// réalocation de mémoire pour la varible clefc
                    clefc= (char *)realloc(clefc,(tailleInitial+100)*sizeof(char));
                    tailleInitial+=100;
					
                }
				// ajout de l'entier
                clefc[conter]=entier;
                conter++;
                entier=getchar();
            }
			// convertir la clefc en entier
            clefi=(int)strtol(clefc,NULL,10);
			// dans le cas où il y a une erreur
            if(clefi==NULL){
                printf("La valeur de la clef est erroner\n");
				// saut au point de reprise pour que l'uilisateur entre une clef valable
                longjmp(ptRep1,1);
            }

			// rappel du choix de l'uilisateur pour le chiffrage ou le déchiffrage
            if (i==0){                
				// appel de la fonction de chiffrement de cesar
                nouveauTexte=chiffrement_cesar(texte,clefi);
            } else{
				// appel de la fonction de dechiffrement de cesar
                nouveauTexte=dechiffrement_cesar(texte, clefi);
            }
            break;
		// choix de vigenaire
        case '2':
			
            printf("Entrer la valeur de la clef : \n");
			// récupéreration de la clef de chiffrement pur vigenaire
            caractere = getchar();
            conter=0;
            while(caractere != '\n'){
				// dans le cas où la taille de la variable clefc n'est pas assez grand on réaloue de la place en mémoire
                if (conter == tailleInitial){
                    clefc= (char *)realloc(clefc,(tailleInitial+100)*sizeof(char));
                    tailleInitial+=100;
                }
				// enregistrement du caractere
                clefc[conter]=caractere;
                conter++;
                caractere=getchar();
            }
			// rappel du choix de l'uilisateur
            if (i==0){
				// appel de fonction de chiffrement de vigenaire
                nouveauTexte=chiffrement_vigenere(texte,clefc);
            } else{
				// appel de la fonction de déchiffrement de vigenaire
                nouveauTexte=dechiffrement_vigenere(texte,clefc);
            }
            break;
        default:
            // saut au point de reprise quand la valeur est fausse
            printf("La valeur rentrer ne correspond pas veuillez retenter\n\n");
            longjmp(ptRep, 1);
            break;
    }
	// renvoie du texte modifié
    return nouveauTexte;
}

char * recuperationDuTexte(){
	// initialisation des compteurs
    int i=0;
    int j=0;
	// initialisation des variables de récupérations des caractères 
    char x;
    char c;
    // initialisation de la variable fic qui contiendra un potentiel fichier
    FILE* fic;
	// initialisation des taille des varaibles texte
    int tailleInitial= 100; 
    int tailleInitial1= 100;  
	// initialisation de la variable texte 
    char *texte = malloc(tailleInitial* sizeof(char));
	// initialisation de la variable lien qui contiendra le lien vers un fichier
    char *lien=malloc(tailleInitial1* sizeof(char));
	// initialisation du point de reprise dans le cas où le lien est erroné
	jmp_buf ptRep1;
	// initialisation du point de reprise
    jmp_buf ptRep;
	// positionnement d'un point du reprise dans le cas où l'utilisateur se trompe pour les choix
    setjmp(ptRep);

    printf("Veuillez choisir le type de texte : \n");
    printf("    - 1 entrer le texte à la main\n");
    printf("    - 2 depuis un fichier texte\n");
	
	// récupération du choix et suppression des valeurs en trop
    x = getchar();
    c = getchar();

    while (c != '\n'){
        c= getchar();
    }
	// choix de l'utilisateur
    switch (x){
		// dans le cas où il souhaite entrer à la main le texte
        case '1' :
            printf("Entrer le texte : ");
			// récupération des caractères
            c=getchar();
            i=0;
            while(c!='\n'){
				// dans le cas où le message dépasse sa taille, réalocation de mémoire
                if (i == tailleInitial){
                    texte= (char *)realloc(texte,(tailleInitial+100)*sizeof(char));
                    tailleInitial+=100;
                }
				// ajout du caractere
                texte[i]= c;
                i++;
                c=getchar();
            }  
			// dans le cas où le message dépasse sa taille réalocation de mémoire pour rajouter le caractere de fin '\0'
            if (i == tailleInitial){
                    texte= (char *)realloc(texte,(tailleInitial+100)*sizeof(char));
                    tailleInitial+=100;
            }
            texte[i]= '\0';          
            break;
		// dans le cas où l'uilisateur veux utilser un texte depuis un fichier
        case '2' :    
			setjmp(ptRep1);
			// récupération du lien vers le fichier
            printf("Entrer le lien de votre fichier : \n");
            c=getchar();
            i=0;
            while(c!='\n'){
				// dans le cas où le message dépasse sa taille, réalocation de mémoire
                if (i == tailleInitial1){
                    lien= (char *)realloc(lien, (tailleInitial1+100)*sizeof(char));
                    tailleInitial1+=100;
                }
                lien[i]= c;
                i++;
                c=getchar();
            }  
			// ouverture du fichier choisit
            fic= fopen(lien, "r");
			// cas si le fichier n'existe pas
            if (fic == NULL){
                printf("Erreur a l ouverture du fichier texte\n");
				// saut vers le point de reprise pour que l'uilisateur indique un nouveau lien
				longjmp(ptRep1,1);
            } else {
				// initialisation de la varaible qui contiendra les lignes du fichier
                char* ligne =NULL;
				// initialisation de la taille de la ligne
                size_t taille =0;
				// réalocation de la premiere ligne
                getline(&ligne, &taille, fic);
				// compteur de la longueur du texte
                i=0;
				// tant qu'il reste un ligne à récupérer
                while ( ! feof(fic)){
					// initialisation du compteur de la ligne
                    j=0;
                    // récupération des caractères de la lignes
                    c=ligne[j];

                    while(c!='\n'){
						// dans le cas où le message dépasse sa taille, réalocation de mémoire
                        if (i == tailleInitial){
                            texte= (char *)realloc(texte,(tailleInitial+100)*sizeof(char));
                            tailleInitial+=100;
                        }
                        texte[i]= c;
                        i++;
                        j++;
                        c=ligne[j];
                    } 
					// dans le cas où le message dépassem sa taille réalocation de mémoire pour l'ajout du caractere '/n'
                    if (i == tailleInitial){
                            texte= (char *)realloc(texte,(tailleInitial+1)*sizeof(char));
                            tailleInitial+=1;
                    }
                    texte[i]='\n';
                    i++;
					// récupération de la nouvelle ligne
                    getline(&ligne, &taille, fic);
                }
				// fermeture du fichier
                fclose(fic);
				// dans le cas où le message dépasse sa taille, réalocation de mémoire pour l'ajout du caractère de fin '\0'
                if (i == tailleInitial){
                                texte= (char *)realloc(texte,(tailleInitial+1)*sizeof(char));
                                tailleInitial+=1;
                }
                texte[i]='\0';
            }
            break;
        default:
			// dans le cas où l'utilisateur a rentré une valeur erronée
            printf("La valeur rentrer ne correspond pas veuillez retenter\n\n");
            longjmp(ptRep, 1);
            break;
    }
	// retour du texte 
    return texte;
}
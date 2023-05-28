// création de la structure verification
typedef struct {
    char c;
    bool isVerified;
} verification ;
// signature des différentes fonctions à utiliser dans le main
char * dechiffrement_cesar(char* message, int cle);
char * chiffrement_cesar(char* message, int cle);
char* chiffrement_vigenere(char* message, char* cle);
char* dechiffrement_vigenere(char* message, char* cle);
verification verifier (const char * message);
void affichage (verification v, char * text);
Chiffrement de messages

Ceci est application de protection de textes permettant le chiffrement et le déchiffrement de messages
par les chiffrements César et Vigenère.

fonctionnement de l'application : 

Pour faire fonctionner notre application, il faut tout d'abord avoir correctement téléchargé tous les fichiers. 
Assurez-vous d'installer les fichiers dans un dossier séparé afin d'éviter toute corruption d'autres fichiers.

Une fois cette étape terminée, lancez la commande suivante : "make clean" qui nettoiera tous les fichiers liés à la compilation de l'application.

Ensuite, exécutez la commande suivante : "make main" qui compilera l'application.

Enfin, il vous suffit de taper la commande "./main" dans le terminal et l'application se lancera. 
Il ne vous reste plus qu'à suivre les indications de l'application.

Attention, veillez à exécuter toutes ces commandes en étant positionné dans le terminal.


Détail des fonctions :

affichage : in verification ( char c; bool isVerified;)
Cette fonction permet l'affichage du résultat.

chiffrement_cesar : in (message, cle), out (message crypté)
Cette fonction permet de chiffrer une chaîne de caractères avec le chiffrement de César.

chiffrement_vigenere : in (message, cle), out (message crypté)
Cette fonction permet de chiffrer une chaîne de caractères avec le chiffrement de vigenère.

dechiffrement_cesar : in (message, cle), out (message décrypté)
déchiffrer une chaîne de caractères ayant été chiffrée avec le chiffrement de César

dechiffrement_vigenere : in (message, cle), out (message décrypté)
déchiffrer une chaîne de caractères ayant été chiffrée avec le chiffrement de vigenère.

verifier : in (message), out verification ( char c; bool isVerified;)
Cette fonction verifie qu'il n'y a pas de charactère special dans le message.

Par ALDEBERT Clément, BARTHE Stuart-victor, GAYRARD Matéo, BARRET Quentin
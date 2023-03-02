TP2 du cours de CPP à CY Tech par S

Comme il y avait 2 exercices différents, le makefile compilera les 2 exerices (qui se trouvent dans des sous dossier de src) en des programmes séparés

En faisant: make
vous obtiendrez:
bin/hanoi
bin/pair

que vous pouvez lancer

Pour le 2eme exercice, il y a surement plus que demandé donc voici un récap de ce qui a été fait:
- Possibilité de jouer au jeu (on demande à l'utilisateur à chaque fois de sélectionner 2 tours pour déplacer un disque)
  * Gestion des mauvaises valeurs dans le cin
  * Gestion des différents cas non valide
- Possibilité de jouer à une version "modifié" où l'utilisateur choisi le nombre de tours et de disques
  * 2 constructeurs pour différencier avec le cas précédent
- Fonction solve qui résout automatique la version classique du jeu (3 tours, 4 disques) en recursif
  * Pour etre sur, on check quand meme si l'algo a bien réussi a solve le jeu

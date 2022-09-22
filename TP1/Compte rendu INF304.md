# Compte rendu INF304

<p align="right">EL-BOUCH ISMAIL JIANG Yilun MAMADOU DIALLO</p>

## Première partie

### Exercice 1

Dans ce programme on va afficher un message d'erreur s'il ne reçoit pas exactement 2 arguments entrés 

### Exercice 2, 3

Dans cette fonction qui prend en paramètres deux chaines de caractères, qui sont les noms des deux fichiers dans lesquelles on travaillera. On commence par ouvrir les deux fichiers, le deuxième fichier on l'ouvre en mode écriture qui est le mode (W+) et le premier fichier on l'ouvre en mode lecture qui est le mode (r). Dans la condition if, si le fichier copie est différent de NULL ce qui veut dire que le fichier n'est pas vide et pareil pour le fichier source on initialise le caractère c par le premier caractère dans le fichier source en utilisant la fonction `fgets()`, et dans le WHILE on dit tant que c est different de la fin du fichier (EOF=END OF FILE) on copie le contenu de c dans le fichier  copie en utilisant la fonction `fputs()`, et après on affecte le caractère suivant du fichier source au variable c et on refait le même travail jusqu'a ce que la boucle s'arrête et c'est le cas  de END OF FILE.`fclose()` sert à fermer les deux fichiers.

Ainsi le programme va afficher un message d'erreur si la ligne de commande est incorrecte.

### Exercice 4

Dans ce programme on va lire une date au format "jour, mois, année" dans un fichier.

On ouvre le fichier input en mode lecture et après on lit les 3 lignes en utilisant la fonction `fscanf()` et on afficher leur somme après dans la console.

## Deuxième partie

### Exercice 1

Tout d'abord nous avons installer l'extension pour voir l'image de format PGM

Apres avoir compiler le programme a l'aide de la commande make, qui permet d'effectuer une certaine tache a la suite d'un évènement, on peut avoir des ficher d'exécution pour exécuter des programme C.

### Exercice 2,3

Dans l'exercice 2 on a compléter la fonction inverse vidéo pour respecter sa spécification 

``` c
p = lepixel(im1, i, j);
p_inverse = max - p; // avec le max= 255
affecter_pixel(im2, i, j, p_inverse); // modifier le pixel origin au pixel inversé
```

## Fin du rapport


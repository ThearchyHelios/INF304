# Compte rendu INF304 TP2

<p align="right">EL-BOUCH ISMAIL JIANG Yilun MAMADOU DIALLO</p>

## Première partie: Tests et déboggage

### Exercice 0:

Dans l'exercice 0 on a tester la procédure `tri_insertion` du paquetage `tri`

### Exercice 1:

On a fait pas mal de teste pour tester la fonction de tri et après on a compiler le programme `exécutif_test_tri` a l'aide de la commande make : avec les /tests fonctionnels on reçoit le tri d'une manière croissante des nombre rentrer. Et avec les Tests de robustesse si on demande de rentrer N nombre et nous on rentre que N-3 nombre, dans ce cas la on reçoit dans les 3 premier ligne des zéros et après on revoit la suite trier 

Apres avoir tester le programme `exec_test_tri` on contacter qu'il y a un problème des fois a la fin il fait pas le tri exact par exemple (il mit 75 et après il mit 74 et a la fin 75). Donc la fonction tri_insertion n'est pas correcte il faut ajouter dans la boucle While que clef est inférieur ou égale 

```c
while ((j >= 0) && (Clef <= (t->tab[j] - 1))) 
```





### Exercice 4:

Dans la fonction `oracle` qui a en paramètre un tableau d'entier dont le rôle est de vérifier que le résultat retenu par la procédure testée correspond bien a sa spécification; donc la fonction oracle compare compare 2 valeur de tableau consécutivement par exemple la valeur qui est stocker dans le tableau d'indice 0 et la valeur qui stocker dans le tableau d'indicatrices 0+1 = 1. Et qui retourne 0 si la valeur stocker dans le tableau de l'indice i est supérieur que la valeur stocker d'indice i+1, sinon il retourne 1.

Après nous avons compléter la procédure test_tri_insertion, en utilisant cet oracle, afin d'afficher automatiquement quels tests échouent.


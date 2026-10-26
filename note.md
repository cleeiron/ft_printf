1. LES CONVERSIONS À GÉRER
-------------------------

%c : Afficher un caractère.
%s : Afficher une chaîne de caractères.
%p : Afficher l'adresse d'un pointeur.
%d : Afficher un entier signé en décimal.
%i : Afficher un entier signé en décimal (comme %d).
%u : Afficher un entier non signé en décimal.
%x : Afficher un entier non signé en hexadécimal minuscule.
%X : Afficher un entier non signé en hexadécimal majuscule.
%% : Afficher le caractère '%'.

Pour %d et %i, le fonctionnement est identique dans printf.


2. LES FONCTIONS QUE JE PENSE DEVOIR CRÉER
------------------------------------------

ft_print_char : Afficher un caractère.
ft_print_str  : Afficher une chaîne de caractères.
ft_print_nbr  : Afficher un entier.
ft_print_ptr  : Afficher une adresse mémoire.
ft_print_hex  : Afficher un nombre en hexadécimal.

Ces fonctions doivent également permettre de compter le nombre
de caractères écrits.

Je pourrais donc leur donner un type de retour int.


3. LES FONCTIONS VARIADIQUES
----------------------------

Pour utiliser les fonctions variadiques :

#include <stdarg.h>

va_list :
Déclarer une variable permettant de parcourir les arguments
supplémentaires.

va_start :
Initialiser le parcours des arguments.

va_arg :
Récupérer l'argument suivant en précisant son type.

va_copy :
Copier l'état d'une liste d'arguments pour permettre
un deuxième parcours indépendant.

va_end :
Terminer le parcours des arguments.

Le prototype de ma fonction est :

int ft_printf(const char *format, ...);

Le premier argument est format.

Les trois points (...) permettent de recevoir des arguments
supplémentaires.

Je dois déclarer une variable :

va_list args;

Puis initialiser le parcours :

va_start(args, format);

ATTENTION :

Le deuxième paramètre de va_start n'est pas le nombre
d'arguments.

C'est le dernier paramètre nommé de la fonction.

Dans ft_printf, ce paramètre est format.

Je n'ai donc pas besoin de calculer le nombre d'arguments
à l'avance.

À la fin de ma fonction, je dois appeler :

va_end(args);


4. COMMENT GÉRER LE PREMIER ARGUMENT : FORMAT ?
-----------------------------------------------

Je dois créer une fonction qui parcourt le premier argument
pour chercher les caractères '%'.

Au départ, j'avais pensé utiliser ft_strchr pour chercher '%'.

Mais ft_strchr renvoie un pointeur vers la première occurrence
du caractère recherché.

Pour ft_printf, il semble plus simple de parcourir toute
la chaîne avec une boucle while et un indice i.

Exemple :

ft_printf("Bonjour %s, tu as %d ans", "Lucas", 25);

Le premier argument est :

"Bonjour %s, tu as %d ans"

Je dois parcourir cette chaîne caractère par caractère.

Si le caractère est différent de '%', je l'affiche.

Si le caractère est '%', je regarde le caractère suivant
pour connaître la conversion à effectuer.

Une fois la conversion traitée, je continue le parcours
après les deux caractères de la conversion.

Par exemple :

format[i]      = '%'
format[i + 1]  = 's'

Ici, je sais que je dois récupérer une chaîne de caractères.

Je pourrais créer une fonction qui reçoit le caractère
situé après '%' et qui appelle la bonne fonction d'affichage.

Par exemple :

ft_conversion(...)

Son rôle serait de déterminer s'il faut appeler :

ft_print_char()
ft_print_str()
ft_print_nbr()
ft_print_ptr()
ft_print_hex()


5. COMMENT RÉCUPÉRER LES ARGUMENTS ?
-----------------------------------

Au départ, je pensais qu'il fallait traiter le premier
argument comme le deuxième, le deuxième comme le troisième, etc.

Mais en réalité, format est un paramètre nommé,
séparé des arguments variadiques.

Exemple :

ft_printf("%s a %d ans", "Lucas", 25);

J'ai :

format = "%s a %d ans"

Premier argument variadique = "Lucas"
Deuxième argument variadique = 25

Quand je rencontre %s, je récupère :

va_arg(args, char *);

Cela me donne "Lucas".

Quand je rencontre ensuite %d, je récupère :

va_arg(args, int);

Cela me donne 25.

Chaque appel à va_arg avance automatiquement
vers l'argument suivant.

Je n'ai pas besoin de gérer moi-même les positions
des arguments.


6. QUEL TYPE UTILISER AVEC VA_ARG ?
----------------------------------

%c : va_arg(args, int)
%s : va_arg(args, char *)
%p : va_arg(args, void *)
%d : va_arg(args, int)
%i : va_arg(args, int)
%u : va_arg(args, unsigned int)
%x : va_arg(args, unsigned int)
%X : va_arg(args, unsigned int)
%% : Aucun va_arg nécessaire.

Pour %c, je dois récupérer un int et non un char.

Pourquoi ?

Parce que les arguments de type char sont automatiquement
convertis en int lorsqu'ils sont transmis à une fonction
variadique.


7. QUE SE PASSE-T-IL SI LE FORMAT NE CORRESPOND PAS À L'ARGUMENT ?
-----------------------------------------------------------------

Je m'étais posé cette question :

Si je rencontre %c, mais que l'argument n'est pas un caractère,
quelle est la valeur de retour ?

va_arg ne vérifie pas si le type demandé correspond réellement
à l'argument transmis.

Exemple :

ft_printf("%d", "Bonjour");

Ici, %d attend un int, mais on transmet un pointeur
vers une chaîne.

Cela peut provoquer un comportement indéfini.

Il n'y a donc pas de valeur de retour garantie.

Je ne dois pas essayer de détecter automatiquement
le véritable type des arguments.

Mon programme doit utiliser les conversions indiquées
dans format, comme le fait printf.


8. EST-CE QUE JE DOIS UTILISER FT_SPLIT ?
----------------------------------------

J'avais pensé séparer les arguments avec ft_split,
en utilisant la virgule comme séparateur.

Mais les virgules qui séparent les arguments dans le code C
ne font pas partie de la chaîne format.

Exemple :

ft_printf("%s %d", "Lucas", 25);

Les trois arguments sont transmis séparément à la fonction.

Je ne reçois pas une seule chaîne contenant :

"%s %d", "Lucas", 25

Je n'ai donc pas besoin de ft_split.

Je dois simplement parcourir format et utiliser va_arg
lorsque je rencontre une conversion.


9. EST-CE QUE JE DOIS COMPTER LES '%' ?
--------------------------------------

J'avais pensé compter les '%' pour savoir combien
d'arguments récupérer.

Mais ce n'est pas nécessaire.

va_start initialise le parcours sans avoir besoin
de connaître le nombre d'arguments.

Ensuite, chaque conversion me permet de savoir
si je dois récupérer un argument.

Exemple :

ft_printf("%d %s %% %c", 42, "Salut", 'A');

Je rencontre :

%d : Je récupère un int.
%s : Je récupère un char *.
%% : J'affiche '%' sans récupérer d'argument.
%c : Je récupère un int.

Il y a quatre conversions, mais seulement trois
arguments variadiques.

Je n'ai donc pas besoin de compter les '%'.


10. COMMENT AFFICHER UNE ADRESSE MÉMOIRE AVEC %p ?
-------------------------------------------------

Je dois encore réfléchir à la manière d'afficher
l'adresse d'un pointeur.

Exemple :

int nbr;

nbr = 42;
ft_printf("%p", (void *)&nbr);

Je dois afficher l'adresse mémoire de nbr,
et non sa valeur 42.

Pour cela :

1. Je récupère l'argument avec va_arg(args, void *).

2. Je convertis l'adresse en une représentation hexadécimale.

3. Je gère le préfixe 0x et le cas du pointeur nul
   selon le comportement attendu.

4. Je compte les caractères écrits.

Je pourrai probablement réutiliser une partie
de ma fonction d'affichage hexadécimal.


11. COMMENT AFFICHER UN NOMBRE EN HEXADÉCIMAL ?
----------------------------------------------

J'avais pensé utiliser une fonction semblable
à ft_putnbr_base.

Cette idée est bonne.

Pour %x et %X, je dois convertir un entier
non signé en base 16.

Les caractères utilisés pour %x sont :

"0123456789abcdef"

Pour %X :

"0123456789ABCDEF"

Exemple :

ft_printf("%x", 255);

Affiche :

ff

Je dois donc créer une fonction capable d'afficher
un nombre en base 16.

Elle devra aussi compter les caractères écrits.


12. LES CAS PARTICULIERS À NE PAS OUBLIER
-----------------------------------------

VALEUR DE RETOUR :

ft_printf doit retourner le nombre de caractères écrits,
et non simplement 0.

%c AVEC '\0' :

Le caractère nul doit être compté,
même s'il n'est pas visible.

%s AVEC NULL :

Comparer le comportement avec printf
sur mon environnement.

%d AVEC INT_MIN :

Gérer correctement le plus petit entier signé.

%u :

Un entier non signé ne se traite pas exactement
comme un entier signé.

%p :

Afficher une adresse et gérer le pointeur nul.

%x ET %X :

Même conversion en base 16, mais avec des lettres
minuscules ou majuscules.

%% :

Afficher un seul '%' et compter un caractère.

ERREUR D'ÉCRITURE :

Prévoir également la gestion d'un échec de write.
printf peut retourner une valeur négative en cas d'erreur.


13. COMMENT JE PENSE ORGANISER MON PROGRAMME
--------------------------------------------

Je pourrais séparer mon programme en plusieurs fonctions.

LA FONCTION PRINCIPALE FT_PRINTF :

Elle doit :

- Initialiser va_list.
- Parcourir format.
- Afficher les caractères normaux.
- Détecter les '%'.
- Appeler la fonction de conversion.
- Compter les caractères écrits.
- Terminer va_list.
- Retourner le nombre de caractères écrits.

LA FONCTION FT_CONVERSION :

Elle doit :

- Regarder le caractère situé après '%'.
- Déterminer la conversion à effectuer.
- Récupérer le bon argument avec va_arg si nécessaire.
- Appeler la fonction d'affichage correspondante.
- Retourner le nombre de caractères écrits.

LES FONCTIONS D'AFFICHAGE :

Elles doivent afficher les caractères, chaînes,
nombres ou adresses.

Elles doivent également retourner le nombre
de caractères écrits pour que ft_printf puisse
calculer son résultat final.







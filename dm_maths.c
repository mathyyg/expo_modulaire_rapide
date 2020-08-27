#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Programme d'exponentation modulaire rapide
int cpt = 0;

unsigned long long int expomodu(unsigned long long int a,unsigned long long int b,unsigned long long int c) { // Fonction qui calcule (a^b)%c
	unsigned int res = 1; // initialisation de la variable stockant le résultant
	a=a%c; 
	
	while(b>0) {
		if((b&1)==1) { // comparaison AND entre l'exposant e et 1 en base 2
			res=(res*a)%c; // si le résultat est 1 alors res prend a modulo c
		}
			b>>=1; // ici on "enlève" un 1 à la représentation binaire de e, on fait un décalage à droite de 1, donc on le divise par 2
			
			// le but de cette ligne est d'obtenir le quotient par une puissance de 2 sans passer par des divisions
			
			a=(a*a)%c; // a prend le résultat de a^2 modulo c, donc la division du nombre pour optimiser le nombre d'étapes...
		// le programme renvoie resultat qu'on affectera à une variable dans le main
			cpt = cpt + 1; // compteur d'étapes
	}
	return res;
}

int main() {
	unsigned long long int nb,exposant,modulo,resultat;
	
	printf("Entrez le nombre (positif seulement): \n"); // Entrée des variables par l'utilisateur
	scanf("%llu",&nb);
	printf("Entrez l'exposant (positif seulement): \n"); // Important: il est précisé "positif seulement" car unsigned int ne prend que des valeurs positives
	//si on entre -1 par exemple, la variable prendra la valeur 0
	scanf("%llu",&exposant);
	printf("Entrez le modulo (positif seulement): \n"); // si on voulait le passer en int
	scanf("%llu",&modulo);
	
	resultat = expomodu(nb,exposant,modulo); // appel de la fonction expomodu avec les paramètres demandés juste avant...
	printf("Le résultat est: %llu \n",resultat); // affichage du résultat :) 
	printf("Nombre d'étapes: %d \n",cpt); 
	return 0;
}

// gcc -o dm dm_maths.c -std=c99 -Wall -Wextra -pedantic -lm

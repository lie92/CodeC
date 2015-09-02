#include <stdio.h>
#include <stdlib.h>

//void affiche(int tab[], int taille);
int sommeTableau(int tab[], int taille);
double moyenneTableau(int tab[], int taille);

int main()
{
     int tab[4] = {3, 4, 5, 5};
     //affiche(tab, 4);
     //printf("%d \n", sommeTableau(tab, 4));
     printf("%f \n", moyenneTableau(tab, 4));
     return 0;
}

void affiche(int tab[], int taille)
{
     int i;
     for (i = 0; i < taille; i++)
     {
	  printf("%d ", tab[i]);
     }
     printf("\n");
}

int sommeTableau(int tab[], int taille)
{
     int i = 0;
     int resultat = 0;
     while(i < taille)
     {
	  resultat = resultat + tab[i];
	  i++;
     }
     // printf("%d \n %d \n", resultat, taille);
     return resultat; 
}

double moyenneTableau(int tab[], int taille)
{
     return (double)sommeTableau(tab, taille)/(double)taille;
}

#include <stdio.h>
#include <stdlib.h>

void affiche(int tab[], int taille);
//int sommeTableau(int tab[], int taille);
//double moyenneTableau(int tab[], int taille);
//void copie(int tableauOriginal[], int tableauCopie[], int tailleTableau);
void maximumTableau(int tableau[], int tailleTableau, int valeurMax);	       
void ordonnerTableau(int tableau[], int tailleTableau);

int main()
{
     int tab[6] = {9, 4, 7, 5, 10, 5};
     //affiche(tab, 4);
     //printf("%d \n", sommeTableau(tab, 4));
     //printf("%f \n", moyenneTableau(tab, 4));
     //int tabb[4];
     //copie(tab, tabb, 4);
     //affiche(tabb, 4);
     // maximumTableau(tab, 4, 4);
     //affiche(tab, 4);
     ordonnerTableau(tab, 4);
     affiche(tab, 4);
     return 0;
}

void affiche(int tab[], int taille)
{
     if(taille != 0)
     {
	  int i;
	  for (i = 0; i < taille; i++)
	  {
	       printf("%d ", tab[i]);
	  }
	  printf("\n");  
     }
     
}

int sommeTableau(int tab[], int taille)
{
     if(taille != 0)
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
     
}

double moyenneTableau(int tab[], int taille)
{
     if(taille != 0)
     {
	  return (double)sommeTableau(tab, taille)/(double)taille;
     }
}

void copie(int tableauOriginal[], int tableauCopie[], int tailleTableau)
{
     if(tailleTableau != 0)
     {
     	  int i;
	  for(i = 0; i < tailleTableau; i++)
	  {
	       /* int j; */
	       /* for(j = 0; j < i; j++) */
	       /* { */
	       /*      printf("%d ", tableauCopie[j]); */
	       /* } */
	       /* printf("\n");	 */  
	       tableauCopie[i] = tableauOriginal[i];
	  }
     }
}

void maximumTableau(int tableau[], int tailleTableau, int valeurMax)
{
     if(tailleTableau == 0)
     {}
     else
     {
	  int i;
	  for(i = 0; i < tailleTableau; i++)
	  {
	       if(valeurMax < tableau[i])
	       {
		    tableau[i] = 0;
	       }
	  }
     }
}

void ordonnerTableau(int tableau[], int tailleTableau) //bubble sort
{
     int i = tailleTableau;
     int b = 1;
     int iterat = 0;
     while(i > 0 && b == 1)
     {
	  b = 0;
	  int j;
	  if(tableau[j] > tableau[j + 1])
	  {
	       for(j = 0; j < i; j++)
	       {
		    int temp = tableau[j];
		    tableau[j] = tableau[i];
		    tableau[i] = temp;
		    b = 1;
		    iterat++;
	       }
	  }
	  i--;
     }
     printf("il a eu %d", iterat);
}
	  
	  	  
	  

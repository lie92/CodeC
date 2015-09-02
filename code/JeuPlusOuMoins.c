#include <stdio.h>
#include <stdio.h>
#include <time.h>

int main (int arg, char** argv)
{
  int continuerPartie = 1;    //utilise un int

  int level = 0;
  int MAX = 0, MIN = 1;

    
  while(continuerPartie == 1)
    {
        
      do
	{
	   printf("quel niveau voulez vous ? \n 1 =  entre 1-100 \n 2 = entre 1-1000 \n 3 = entre 1-10000 \n Vous choisissez le niveau : ");
	  scanf("%d", &level);
	  switch(level)
	    {
	    case 1:
	      MAX = 100;
	      break;
	    case 2:
	      MAX = 1000;
	      break;
	    case 3:
	      MAX = 10000;
	      break;
	    default:
	      MAX = 0;
	      printf("choisissez parmi les 3 niveaux proposes \n");
	      break;
	    }
	}while(level != 1 && level != 2  && level != 3);

      
      srand(time(NULL));	
      int test = 0;
      int nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
      int essais = 1;
      //printf("%d \n",nombreMystere);  pour les test ;D
      do
	{
	  printf("Quel est le nombre mystere ?\n");
	  scanf("%d", &test);
	  if(nombreMystere < test )
	    {
	      printf("il est inferieur\n");
	    }
	  else if(nombreMystere > test)
	    {
	      printf("il est superieur\n");
	    }
	  else
	    {
	      printf("Bravo vous avez le nombre mystere %d en %d \n", nombreMystere, essais);
	    }
	       
	  essais++;
        }while(test != nombreMystere);
       
      do
	{
	  printf("voulez vous continuer ? Rentrer 1 (oui) ou 0 (non)\n");
	  int reponse = 10;
	  scanf("%d", &reponse);
	  switch(reponse)
	    {
	    case 0:
	      continuerPartie = 0;
	      // printf("vous avez choisi d'arreter !\n");
	      break;
	    case 1:
	      continuerPartie = 1;
	      //printf("vous avez choisi de continuer !\n");
	      break;
	    default:
	      printf("rentrez 1 ou 0");
	      continuerPartie = 10;
	    }
	}while(continuerPartie != 0 && continuerPartie != 1);
    }
  return 0;
}


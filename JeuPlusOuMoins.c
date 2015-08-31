#include <stdio.h>
#include <stdio.h>
#include <time.h>

int main (int arg, char** argv)
{
     srand(time(NULL));
     const int MAX = 100, MIN = 1;
     int test = 0;
     int nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
     int essais = 1;

     
     do
     {
	       printf("Quel est le nombre mystere ?\n");
	       scanf("%d", &test);
	       if(nombreMystere < test)
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

     return 0;
}

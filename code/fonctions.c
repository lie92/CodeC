#include <stdio.h>
#include <stdlib.h>

int triple(int);

int main()
{
     int nombre = 0;
     printf("Votre nombre ?\n");
     scanf("%d", &nombre);
     printf("Son triple vaut %d \n", triple(nombre));
     return 0;
}
int triple (int nombre)
{
     return 3 * nombre;
}

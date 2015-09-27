#include<stdio.h>

FILE *img_file;

int main(int argc, char *argv[])
{
    char *args[argc];
    int i;
    for (i = 0; i < argc; i++)
        args[i] = argv[i];

    img_file = fopen(*args, "r");
    if (!img_file)
        return 1;

    putchar(**argv);
    putchar(*(*argv + 1));;

    int c;
    while ((c = getc(img_file)) != EOF)
        putchar(c);
    fclose(img_file);
    return 0;
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned long ulong;
typedef char byte;

int* img;
FILE *img_file;

void open_bitmap()
{
    fseek(img_file, 4, SEEK_SET);

    char *magic_nb = "";
    magic_nb += fgetc(img_file);
    magic_nb += fgetc(img_file);

    uint size = fgetc(img_file) | (fgetc(img_file) << 8)
                | (fgetc(img_file) << 16) | (fgetc(img_file) << 24);

    fseek(img_file, 4, SEEK_CUR);

    uint shift = fgetc(img_file) | fgetc(img_file) << 8
                 | fgetc(img_file) << 16 | fgetc(img_file) << 24;

    uint dib_size = fgetc(img_file) | fgetc(img_file) << 8
                    | fgetc(img_file) << 16 | fgetc(img_file) << 24;

    uint width = fgetc(img_file) | fgetc(img_file) << 8
                 | fgetc(img_file) << 16 | fgetc(img_file) << 24;

    uint height = fgetc(img_file) | fgetc(img_file) << 8
                  | fgetc(img_file) << 16 | fgetc(img_file) << 24;

    ushort color_maps = fgetc(img_file) | fgetc(img_file) << 8;

    ushort bits_per_pixel = fgetc(img_file) | fgetc(img_file) << 8;

    uint compression = fgetc(img_file) | fgetc(img_file) << 8
                       | fgetc(img_file) << 16 | fgetc(img_file) << 24;

    uint pixel_array_size = fgetc(img_file) | fgetc(img_file) << 8
                            | fgetc(img_file) << 16 | fgetc(img_file) << 24;

    fseek(img_file, 8, SEEK_CUR);

    uint palette_colors = fgetc(img_file) | fgetc(img_file) << 8
                          | fgetc(img_file) << 16 | fgetc(img_file) << 24;

    uint important_colors = fgetc(img_file) | fgetc(img_file) << 8
                            | fgetc(img_file) << 16 | fgetc(img_file) << 24;

    printf("BMP header :\n%s%s%s%o%s%o%s%o%s%o%s%o%s%o%s%o%s%o%s%o%s%o%s%o",
           "  magic nb : ",
           magic_nb,
           "\n  image size : ",
           0,//DEBUG, B_to_MiB
           "MiB\n  shift : ",
           shift,
           "\nDIB header :\n  DIB header size : ",
           dib_size,
           "B\n  width : ",
           width,
           "\n  height : ",
           height,
           "\n  color maps used : ",
           color_maps,// DEBUG
           "\n  bits per pixel : ",
           bits_per_pixel,
           "\n  compression : ",
           compression,
           "\n  pixel array size : ",
           0,//DEBUG, B_to_MiB
           "MiB\n  palette colors : ",
           palette_colors,
           "\n  important colors : ",
           important_colors);

}// void print_header


/*
** Converts a number of bytes into a number of mebibytes
** and returns the result as a string.
** The result includes decimal places.
*/
char *B_to_MiB(uint nb)
{
    /* string i = to_string(100000 * ((ulong)nb & 0xFFFFF) >> 20); */

    /* for (byte c = 5 - i.length(); c > 0; c--) */
    /*     i = '0' + i; */
    /* return to_string(nb >> 20) + '.' + i; */


    //char *i = 100000 * ((ulong)nb & 0xFFFFF) >> 20;//DEBUG !!!
    //for (byte c = 5 - i.length(); c > 0; c--)
    //    i = strcat("0" + i);
    //return to_string(nb >> 20) + '.' + i;
}


int main(int argc, char *argv[])
{
    img_file = fopen(*argv, "r");
    open_bitmap();
    printf("%X\n", fgetc(img_file));
    fclose(img_file);

    return 0;
}// int main

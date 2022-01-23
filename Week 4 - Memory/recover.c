#include <stdio.h>
#include <stdbool.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
 if (argc != 2)
 {
     printf("Try again:\n");
     return 1;
 }
 FILE *file = fopen(argv[1], "r");
 if (file == NULL)
 {
     printf("Try again\n");
     return 1;
 }

int count = 0;
uint8_t buffer[512];
char filename[10];
FILE *img = NULL;
while (fread(&buffer, 512, 1, file))
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        if (count == 0)
        {
            sprintf(filename, "%03i.jpg",count);
            img = fopen(filename, "w");
            fwrite(&buffer,512,1,img);
            count+=1;
        }
        else
        {
            fclose(img);
            sprintf(filename, "%03i.jpg",count);
            img = fopen(filename, "w");
            fwrite(&buffer,512,1,img);
            count+=1;
        }
    }
    else
    {
        if (count != 0)
        {
            fwrite(&buffer,512,1,img);
        }
    }

}

fclose(file);
fclose(img);
return 0;
}

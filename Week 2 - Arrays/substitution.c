#include <stdio.h>
#include <stdbool.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main(int argc, string argv[])
{

    int i = 0;
    if (argc != 2)
    {
        printf("Try again with valid key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Try again with valid key\n");
        return 1;
    }
    int count_alpha = 0;
    for (i=0;argv[1][i] != '\0';i++)
    {
        if (isalpha(argv[1][i]))
        {
            count_alpha += 1;
        }
    }
    if (count_alpha != 26)
    {
        printf("Try again with valid key\n");
        return 1;
    }

    int i1 = 0;
    int count_2 = 0;
    char string1[30] = "0";
    for (i1=0; i1 != 25; i1++)
    {
        strcat(string1,"0");
    }

    int flag = 0;
    int i2 = 0;
    int dict_int = 0;
    for (i2 = 0; argv[1][i2] != '\0'; i2++)
    {
        char temp_char = tolower(argv[1][i2]);
        int i3 = 0;
        for (i3 = 0; string1[i3] != '\0'; i3++)
        {
            if (string1[i3] == temp_char)
            {
                flag+=1;
                printf("Try again:\n");
                return 1;
            }
        }

        string1[dict_int] = temp_char;
        dict_int += 1;

    }

    string plaintext = get_string("plaintext: ");

    char key[30];
    strcpy(key,argv[1]);

    int i4 = 0;

    for (i4 = 0; plaintext[i4] != '\0'; i4 ++)
    {
        if (isalpha(plaintext[i4]))
        {
            if (isupper(plaintext[i4]))
            {
                int ascii = plaintext[i4] - 65;
                plaintext[i4] = toupper(key[ascii]);
            }
            else
            {
                int ascii = plaintext[i4] - 97;
                plaintext[i4] = tolower(key[ascii]);
            }


        }

    }
    printf("ciphertext: %s\n",plaintext);
  
    return 0;
}

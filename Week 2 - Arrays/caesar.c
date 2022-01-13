#include <stdio.h>
#include <stdbool.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void rotate(char string1[], int k)
{

    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    char alphabet1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i1 = 0;
    for (i1 = 0; string1[i1] != '\0'; i1++)
    {
        if (isalpha(string1[i1]))
        {

            if (islower(string1[i1]))
            {
                int temp1 = 0;
                temp1 = string1[i1] - 96;
                int ci  = (temp1 + k) % 26;
                string1[i1] = alphabet[ci-1];
            }
            else
            {
                int temp1 = 0;
                temp1 = string1[i1] - 64;
                int ci  = (temp1 + k) % 26;
                string1[i1] = alphabet1[ci-1];
            }
        }
    }
    printf("ciphertext: %s\n",string1);


}



int main(int argc, string argv[])
{
    argc -= 1;
    if (argc != 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int i = 0;
    for (i = 0 ; argv[1][i] != '\0'; i ++)
    {

        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int k = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");
    rotate(plaintext, k);

    return 0;
}

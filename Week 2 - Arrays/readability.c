#include <stdio.h>
#include <stdbool.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


int count_letters(char string1[])
{
    int length = strlen(string1);
    int i = 0;
    int count1 = 0;
    for (i = 0; string1[i] != '\0'; i ++)
    {
        if (isalpha(string1[i]))
        {
            count1 += 1;
        }
    }
    return count1;
}

int count_words(char string1[])
{
    int i = 0;
    int count_spaces_or_dot = 0;
    for (i = 0 ; string1[i] != '\0'; i++)
    {
        if (string1[i] == ' ')
        {
            count_spaces_or_dot += 1;
        }
    }
    count_spaces_or_dot += 1;
    return count_spaces_or_dot;
}


int count_sentence(char string1[])
{
    int count2 = 0;
    int i = 0;

    for (i = 0; string1[i] != '\0'; i++)
    {
        if (string1[i] == '.' || string1[i] == '?' || string1[i] == '!')
        {
            count2 += 1;
        }
    }

    return count2;
}




int main()
{
    string book_string = get_string("Type string from book here:");
  
    float letters = (float) count_letters(book_string);

    float words = (float) count_words(book_string);

    float sentences = (float) count_sentence(book_string);

    float word_average = (letters/words) * 100;
    float sen_average = (sentences / words) * 100;
    float index1 = 0.0588 * word_average - 0.296 * sen_average - 15.8;

    int index = (int) round(index1);
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n",index);
    }

    return 0;
}

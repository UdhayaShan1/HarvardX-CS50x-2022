#include <stdio.h>
#include <stdbool.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    long credit = get_long("Input credit number here: ");
    //4003600000000014
    char credit_string[100];
    sprintf(credit_string, "%li", credit);
    int length1;
    length1 = strlen(credit_string);

    int i = 0;
    int sum1 = 0;
    for (i = 0; credit_string[i] != '\0'; i ++)
    {
        if (length1 % 2 == 0)
        {
            if (i%2==0)
            {
            int temp1 = (credit_string[i] - 48) * 2;

            bool x1 = false;
            while (x1==false)
                {
                sum1 += temp1 % 10;
                temp1 = temp1 / 10;
                if (temp1 < 1)
                    {
                    break;
                    }
                }
            }
        }
        else
        {
            if (i%2!=0)
            {
            int temp1 = (credit_string[i] - 48) * 2;

            bool x1 = false;
            while (x1==false)
                {
                sum1 += temp1 % 10;
                temp1 = temp1 / 10;
                if (temp1 < 1)
                    {
                    break;
                    }
                }
            }
        }
    }

    int i1 =0;
    int sum2 = 0;
    for (i1 = 0; credit_string[i1] != '\0'; i1 ++)
    {
        if (length1 % 2 == 0)
        {
            if (i1 % 2!=0)
        {
            int temp1 = credit_string[i1] - 48;
            sum1 = sum1 + temp1;
        }
        }
        else
        {
            if (i1 % 2==0)
        {
            int temp1 = credit_string[i1] - 48;
            sum1 = sum1 + temp1;
        }
        }

    }

    char finalstr[20];
    sprintf(finalstr,"%d",sum1);
    int length_final = strlen(finalstr);

    int last = finalstr[length_final-1]-48;


    int master = (credit_string[0] -48) * 10 + (credit_string[1]-48);


    if (last == 0)
    {
        if (credit_string[0] == '4')
        {
            if (length1 == 13 || length1 == 16)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (master >= 51 && master <= 55)
        {
            if (length1 == 16)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (master == 34 || master == 37)
        {
            if (length1 == 15)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

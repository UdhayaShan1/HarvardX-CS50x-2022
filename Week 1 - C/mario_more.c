#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>

int main()
{
    int height = get_int("Height: ");
    if (height < 1 || height > 8)
    {
        bool x = false;
        while (x==false)
        {
            height = get_int("Try a number between 1 and 8 ");
            if (height >= 1 && height <= 8)
            {
                break;
            }
        }
    }

    int i = 0;
    int k1 = height - 1;
    int k2 = 1;
    int k3 = 1;
    for (i = 0 ; i < height; i++)
    {
        bool x1 = false;
        int count = 0;
        while (x1==false)
        {
            if (count == k1)
            {
                break;
            }

            printf(" ");
            count += 1;

        }

        bool y1 = false;
        int count1 = 0;
        while (y1==false)
        {
            if (count1 == k2)
            {
                break;
            }
            printf("#");
            count1+=1;
        }
        printf("  ");
        bool x2 = false;
        int count2 = 0;
        while (x2==false)
        {
            if (count2 == k3)
            {
                break;
            }

            printf("#");
            count2 += 1;
        }
        printf("\n");
        k1-=1;
        k2+=1;
        k3+=1;

    }

    return 0;
}

#include <stdio.h>
#include <stdbool.h>
#include <cs50.h>
int main()
{
    int height;
    printf("Height: ");
    height = get_int("Enter a positive number:");
    if (height < 1 || height > 8)
    {
        bool x = false;
        while (x==false)
        {
            height = get_int("Try typing a positive integer between 1 and 8: ");
            if (height > 0 && height < 9)
            {
                break;
            }
        }
    }
    int k1 = 1;
    int k2 = 1;
    int i;
    for (i=0; i<height; i++)
    {
        bool y1 = false;
        int count = 0;
        while(y1 == false)
        {
            if (count == height - k1)
            {
                break;
            }
            printf(" ");
            count += 1;

        }
        bool y2 = false;
        count = 0;
        while (y2==false)
        {
            if (count == k2)
            {
                break;
            }
            printf("#");
            count+=1;

        }
        printf("\n");
        k1+=1;
        k2+=1;
    }

    return 0;
}

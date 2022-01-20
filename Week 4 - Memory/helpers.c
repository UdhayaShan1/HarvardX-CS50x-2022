#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;
            float avg =  ((red+blue+green) / 3.0);
            image[i][j].rgbtRed = (int) round(avg);
            image[i][j].rgbtBlue = (int) round(avg);
            image[i][j].rgbtGreen = (int) round(avg);

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float originalRed = (float) image[i][j].rgbtRed;
            float originalBlue = (float) image[i][j].rgbtBlue;
            float originalGreen = (float) image[i][j].rgbtGreen;
            float sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            float sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;
            float sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            if (sepiaRed > 255.0)
            {
                sepiaRed = 255.0;
            }
            if (sepiaBlue > 255.0)
            {
                sepiaGreen = 255.0;
            }
            if (sepiaGreen > 255.0)
            {
                sepiaGreen = 255.0;
            }
            image[i][j].rgbtRed = (int) round(sepiaRed);
            image[i][j].rgbtBlue = (int) round(sepiaBlue);
            image[i][j].rgbtGreen = (int) round(sepiaGreen);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float round1 = width / 2.0;
            int round2 = (int) round(round1);
            if (j>=round2)
            {
                break;
            }
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;
            int red1 = image[i][width-j-1].rgbtRed;
            int blue1 = image[i][width-j-1].rgbtBlue;
            int green1 = image[i][width-j-1].rgbtGreen;
            image[i][j].rgbtRed = red1;
            image[i][j].rgbtBlue = blue1;
            image[i][j].rgbtGreen = green1;
            image[i][width-j-1].rgbtRed = red;
            image[i][width-j-1].rgbtBlue = blue;
            image[i][width-j-1].rgbtGreen = green;

        }
    }




    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int array1[height][width][3];
    int i = 0;
    int j = 0;

    for (i =0 ; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            int red = 0;
            int blue = 0;
            int green = 0;
            int block = 0;
            for (int i1 = i-1; i1 < i +2; i1++)
            {
                for(int j1 = j-1; j1 < j +2; j1++)
                {
                    if (i1 < 0 || j1 < 0 || i1 >= height || j1 >= width)
                    {
                        continue;
                    }
                    else
                    {
                        red += image[i1][j1].rgbtRed;
                        blue += image[i1][j1].rgbtBlue;
                        green += image[i1][j1].rgbtGreen;
                        block+=1;

                    }
                }
            }
            array1[i][j][0] = (int) round(red / (float)block);
            array1[i][j][1] = (int) round(blue / (float)block);
            array1[i][j][2] = (int) round(green / (float)block);
        }
    }

    int i3=0;
    int j3=0;
    for (i3 =0 ; i3 < height; i3++)
    {
        for(j3 = 0; j3 < width; j3++)
        {
            image[i3][j3].rgbtRed = array1[i3][j3][0];
            image[i3][j3].rgbtBlue = array1[i3][j3][1];
            image[i3][j3].rgbtGreen = array1[i3][j3][2];
        }
    }
    return;
}

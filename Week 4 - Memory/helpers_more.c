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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    int array[height][width][2][3];
    int i1 = 0;
    int j1 = 0;
    for (i1 = 0 ; i1 < height; i1 ++)
    {
        for (j1 = 0; j1 < width; j1++)
        {
            int i2 = 0;
            int j2 = 0;
            int j_temp = 0;
            int i_temp = 0;

            int gx_red = 0;
            int gy_red = 0;

            int gx_blue = 0;
            int gy_blue = 0;

            int gx_green = 0;
            int gy_green = 0;
            for(i2 = i1 -1; i2 < i1 +2; i2 ++)
            {
                for (j2 = j1 -1; j2 < j1 +2; j2++)
                {
                    if (i2 < 0 || j2 < 0 || i2 >= height || j2 >= width)
                    {
                        j_temp+=1;
                        continue;
                    }
                    else
                    {
                        gx_red += Gx[i_temp][j_temp] * image[i2][j2].rgbtRed;
                        gx_blue += Gx[i_temp][j_temp] * image[i2][j2].rgbtBlue;
                        gx_green += Gx[i_temp][j_temp] * image[i2][j2].rgbtGreen;

                        gy_red += Gy[i_temp][j_temp] * image[i2][j2].rgbtRed;
                        gy_blue += Gy[i_temp][j_temp] * image[i2][j2].rgbtBlue;
                        gy_green += Gy[i_temp][j_temp] * image[i2][j2].rgbtGreen;
                        j_temp +=1;
                    }
                }
                i_temp +=1;
                j_temp = 0;
            }
            array[i1][j1][0][0] = gx_red;
            array[i1][j1][0][1] = gx_blue;
            array[i1][j1][0][2] = gx_green;
            array[i1][j1][1][0] = gy_red;
            array[i1][j1][1][1] = gy_blue;
            array[i1][j1][1][2] = gy_green;

        }
    }



    int i5 = 0;
    int j5 = 0;
    for (i5 = 0; i5 < height; i5++)
    {
        for (j5 = 0; j5 < width ; j5++)
        {
            float sum_red = (float) array[i5][j5][0][0] * (float) array[i5][j5][0][0] + (float) array[i5][j5][1][0] * (float) array[i5][j5][1][0];
            float sum_blue = (float) array[i5][j5][0][1] * (float) array[i5][j5][0][1] + (float) array[i5][j5][1][1] * (float) array[i5][j5][1][1];
            float sum_green = (float) array[i5][j5][0][2] * (float) array[i5][j5][0][2] + (float) array[i5][j5][1][2] * (float) array[i5][j5][1][2];
            float root_red = (float) sqrt (sum_red);
            int round_red = (int) round(root_red);

            float root_blue = (float) sqrt (sum_blue);
            int round_blue = (int) round(root_blue);

            float root_green = (float) sqrt (sum_green);
            int round_green = (int) round(root_green);

            if (round_red > 255)
            {
                round_red = 255;
            }
            if (round_blue > 255)
            {
                round_blue = 255;
            }
            if (round_green > 255)
            {
                round_green = 255;
            }
            image[i5][j5].rgbtRed = round_red;
            image[i5][j5].rgbtBlue = round_blue;
            image[i5][j5].rgbtGreen = round_green;
        }
    }
    return;
}

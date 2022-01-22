#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int i1 = 0;
    int j1 = 0;
    int array_x[height][width][3];
    int array_y[height][width][3];
    for(i1 = 0; i1 < height; i1 ++ )
    {
        for(j1=0 ; j1< width; j1++)
        {
            int gx_red = 0;
            int gx_blue = 0;
            int gx_green = 0;
            for(int i2 = i1 -1; i2 < i1+2;i2++)
            {
                for(int j2 = j1-1; j2 < j1+2;j2++)
                {
                    if (i2 < 0 || j2 < 0 || i2 >= height || j2 >= width)
                    {
                        continue;
                    }
                    else
                    {
                        if (i2 == i1 - 1 || i2 == i1 + 1)
                        {
                            if (j2 == j1 -1)
                            {
                                gx_red += (-1) * image[i2][j2].rgbtRed;
                                gx_blue += (-1) * image[i2][j2].rgbtBlue;
                                gx_green += (-1) * image[i2][j2].rgbtGreen;
                            }
                            else if (j2 == j1+1)
                            {
                                gx_red += image[i2][j2].rgbtRed;
                                gx_blue += image[i2][j2].rgbtBlue;
                                gx_green += image[i2][j2].rgbtGreen;
                            }
                        else if (i2 == i1)
                        {
                            if (j2 == j1 -1)
                            {
                                gx_red += (-2) * image[i2][j2].rgbtRed;
                                gx_blue += (-2) * image[i2][j2].rgbtBlue;
                                gx_green += (-2) * image[i2][j2].rgbtGreen;
                            }
                            else if (j2 == j1+1)
                            {
                                gx_red += 2*image[i2][j2].rgbtRed;
                                gx_blue += 2*image[i2][j2].rgbtBlue;
                                gx_green += 2*image[i2][j2].rgbtGreen;
                            }
                        }
                    }
                }
            }
        }
        array_x[i1][j1][0] = gx_red;
        array_x[i1][j1][1] = gx_blue;
        array_x[i1][j1][2] = gx_green;
        }
    }

    int i3 = 0;
    int j3 = 0;
    for (i3 = 0; i3 < height ; i3++)
    {
        for (j3 = 0; j3 < width; j3++)
        {
            int gy_red = 0;
            int gy_blue = 0;
            int gy_green = 0;
            for (int i4 = i3 -1; i4 < i3 +2; i4++)
            {
                for (int j4 = j3 -1; j4 < j3+2; j4++)
                {
                    if (i4 < 0 || j4 < 0 || i4 >= height || j4 >= width)
                    {
                        continue;
                    }
                    else
                    {
                        if (j4 == j3 -1 || j4 == j3+1)
                        {
                            if (i4 == i3-1)
                            {
                                gy_red += (-1)*image[i4][j4].rgbtRed;
                                gy_blue += (-1)*image[i4][j4].rgbtBlue;
                                gy_green += (-1)*image[i4][j4].rgbtGreen;
                            }
                            else if (i4 == i3+1)
                            {
                                gy_red += (1)*image[i4][j4].rgbtRed;
                                gy_blue += (1)*image[i4][j4].rgbtBlue;
                                gy_green += (1)*image[i4][j4].rgbtGreen;
                            }
                        }
                        else if (j4 == j3)
                        {
                            if (i4 == i3-1)
                            {
                                gy_red += (-2)*image[i4][j4].rgbtRed;
                                gy_blue += (-2)*image[i4][j4].rgbtBlue;
                                gy_green += (-2)*image[i4][j4].rgbtGreen;
                            }
                            else if (i4 == i3 + 1)
                            {
                                gy_red += (2)*image[i4][j4].rgbtRed;
                                gy_blue += (2)*image[i4][j4].rgbtBlue;
                                gy_green += (2)*image[i4][j4].rgbtGreen;
                            }
                        }
                    }
                }
            }
        array_y[i3][j3][0] = gy_red;
        array_y[i3][j3][1] = gy_blue;
        array_y[i3][j3][2] = gy_green;
        }
    }
    int i5 = 0;
    int j5 = 0;
    for (i5 = 0; i5 < height; i5++)
    {
        for (j5 = 0; j5 < width ; j5++)
        {
            float sum_red = (float) array_x[i5][j5][0] * (float) array_x[i5][j5][0] + (float) array_y[i5][j5][0] * (float) array_y[i5][j5][0];
            float sum_blue = (float) array_x[i5][j5][1] * (float) array_x[i5][j5][1] + (float) array_y[i5][j5][1] * (float) array_y[i5][j5][1];
            float sum_green = (float) array_x[i5][j5][2] * (float) array_x[i5][j5][2] + (float) array_y[i5][j5][2] * (float) array_y[i5][j5][2];
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

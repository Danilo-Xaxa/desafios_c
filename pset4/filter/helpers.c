#include "helpers.h"

#include <stdio.h>
#include <math.h> // eu que botei aqui


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red_channel = image[i][j].rgbtRed;
            int green_channel = image[i][j].rgbtGreen;
            int blue_channel = image[i][j].rgbtBlue;

            float average = round((red_channel + green_channel + blue_channel) / 3.0); // esse .0 no 3 me rendeu horas de dor de cabeça

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
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
            int red_channel = image[i][j].rgbtRed;
            int green_channel = image[i][j].rgbtGreen;
            int blue_channel = image[i][j].rgbtBlue;

            int sepia_red = round(0.393 * red_channel + 0.769 * green_channel + 0.189 * blue_channel);
            int sepia_green = round(0.349 * red_channel + 0.686 * green_channel + 0.168 * blue_channel);
            int sepia_blue = round(0.272 * red_channel + 0.534 * green_channel + 0.131 * blue_channel);

            if (sepia_red > 255)
            {
                sepia_red = 255;
            }

            if (sepia_green > 255)
            {
                sepia_green = 255;
            }

            if (sepia_blue > 255)
            {
                sepia_blue = 255;
            }

            image[i][j].rgbtRed = sepia_red;
            image[i][j].rgbtGreen = sepia_green;
            image[i][j].rgbtBlue = sepia_blue;
        }
    }
    return;
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        RGBTRIPLE row[width];

        for (int j = 0; j < width; j++)
        {
            row[j] = image[i][j];
        }

    int meio = width / 2 - 0.5;
    for (int k = 0; k < width; k++)
        {
            if (width - k - 1 == meio)
            {
                image[i][k] = row[meio];
            }
            else
            {
                image[i][k] = row[width - k - 1];
            }
        }
    }
    return;
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE vari[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average_red = 0;
            float average_green = 0;
            float average_blue = 0;
            int a[] = {i-1, i, i+1};
            int b[] = {j-1, j, j+1};
            float pixels = 0;

            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    int x = a[k];
                    int y = b[l];

                    if (x >= 0 && x < height && y >= 0 && y < width) // (se image[i + k][j + l] existe) algumas horas pq tava usando (height > a >= 0) e coisa do tipo
                    {
                        RGBTRIPLE meu_pixel = image[x][y];

                        average_red += meu_pixel.rgbtRed;
                        average_green += meu_pixel.rgbtGreen;
                        average_blue += meu_pixel.rgbtBlue;
                        pixels++;
                    }
                }
            }

            vari[i][j].rgbtRed = round(average_red / pixels);
            vari[i][j].rgbtGreen = round(average_green / pixels);
            vari[i][j].rgbtBlue = round(average_blue / pixels);
        }

    }

    for (int z = 0; z < height; z++)
    {
        for (int o = 0; o < width; o++)
        {
            image[z][o] = vari[z][o];
        }
    }
    return;
}

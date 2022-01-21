#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++){
        for (int j = 0;  j < width; j++){
            int avg = (int)(round((image[i][j].rgbtRed  + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.00));
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++){
        for (int j = 0;  j < width / 2; j++){
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float count = 0.00;
            int sumRed = 0, sumBlue =  0, sumGreen = 0;             //Has to be integer cause it's the sum of lots of number

            for (int k = i -1; k <= i +1; k++)
            {
                for (int l = j -1; l <= j +1; l++)
                {
                    if (k < 0 || k > height - 1 || l < 0 || l > width - 1){
                        continue;
                    }
                    sumRed += image[k][l].rgbtRed;
                    sumGreen += image[k][l].rgbtGreen;
                    sumBlue += image[k][l].rgbtBlue;
                    count++;
                }
            }
            temp[i][j].rgbtRed = round(sumRed / count);
            temp[i][j].rgbtGreen = round(sumGreen / count);
            temp[i][j].rgbtBlue = round(sumBlue / count);
        }
    }
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            image[i][j] = temp[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    float tempRed[height][width], tempGreen[height][width], tempBlue[height][width];

    int Gx[9] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int Gy[9] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0;

            float tempTotalGxRed = 0, tempTotalGxGreen = 0, tempTotalGxBlue = 0;
            float tempTotalGyRed = 0, tempTotalGyGreen = 0, tempTotalGyBlue = 0;

            for (int k = i -1; k <= i +1; k++)
            {
                for (int l = j -1; l <= j +1; l++)
                {
                    if (k < 0 || k > height - 1 || l < 0 || l > width - 1){
                        count++;
                        continue;
                    }
                    tempTotalGxRed      += image[k][l].rgbtRed * Gx[count];
                    tempTotalGxGreen    += image[k][l].rgbtGreen * Gx[count];
                    tempTotalGxBlue     += image[k][l].rgbtBlue * Gx[count];

                    tempTotalGyRed      += image[k][l].rgbtRed * Gy[count];
                    tempTotalGyGreen    += image[k][l].rgbtGreen * Gy[count];
                    tempTotalGyBlue     += image[k][l].rgbtBlue * Gy[count];
                    count++;
                }
            }

            tempRed[i][j]   = round(sqrt(pow(tempTotalGxRed, 2) + pow(tempTotalGyRed, 2)));
            tempGreen[i][j] = round(sqrt(pow(tempTotalGxGreen, 2) + pow(tempTotalGyGreen, 2)));
            tempBlue[i][j]  = round(sqrt(pow(tempTotalGxBlue, 2) + pow(tempTotalGyBlue, 2)));
        }
    }
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){

            if (tempRed[i][j] > 255) tempRed[i][j] = 255;
            if (tempGreen[i][j]  > 255) tempGreen[i][j] = 255;
            if (tempBlue[i][j] > 255) tempBlue[i][j] = 255;

            image[i][j].rgbtRed = tempRed[i][j];
            image[i][j].rgbtGreen = tempGreen[i][j];
            image[i][j].rgbtBlue = tempBlue[i][j];
        }
    }
    return;
}

// Alexander Torjyan 28 Per 1
// CS50 Problem set 4

// Convert image to grayscale
int red_sum = 0;
int green_sum = 0;
int blue_sum = 0;
int counter = 0;
int red_mean = 0;
int green_mean = 0;
int blue_mean = 0;

for (int i = 0; i < height; i++)
{
    for (int j = 0; j < width; j++)
    {
        for (int n = -1; n < 1; n++)
        {
            for (int m = -1; m < 1; m++)
            {
                int current_row = i + n;
                int current_col = j + m;
                if (current_col < 0 || current_row < 0 || current_col == width || current_row == height)
                {
                    continue;
                }
                else
                {
                    red_sum = red_sum + copy[n][m].rgbtRed;
                    green_sum = green_sum + copy[n][m].rgbtGreen;
                    blue_sum = blue_sum + copy[n][m].rgbtBlue;
                    counter ++;
                }
            }
        }
        red_mean = round(red_sum / counter);
        green_mean = round(green_sum / counter);
        blue_mean = round(blue_sum / counter);

        image[i][j].rgbtRed = red_mean;
        image[i][j].rgbtGreen = green_mean;
        image[i][j].rgbtBlue = blue_mean;
    }
}
return;

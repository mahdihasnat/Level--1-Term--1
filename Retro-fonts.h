#ifndef RETRO_FONTS_H
#define RETRO_FONTS_H
#define Retro_grid_cols 5
#define Retro_grid_rows 8

static int retro_fonts[128][Retro_grid_rows ][Retro_grid_cols];

void LoadFonts()
{
    FILE * fp = fopen("Retro-Fonts.txt", "r");
    if(fp != NULL)
    {
        while(!feof(fp))
        {
            int ascii;
            fscanf(fp, "%d", &ascii);
            for(int i = 0; i<=7; i++)
                for(int j = 0; j< 5; j++)
                    fscanf(fp, "%d", &retro_fonts[ascii][i][j]);
        }
    }
    else
    {
        printf("retro text.txt file not found\n");
    }
    fclose(fp);
    return;

}

static void RetroLetter(double x, double y, char c, double width, double height)
{
    double block_x;
    double block_y;
    //iFilledRectangle(x,y,width,height);
    for(int i = 0; i<Retro_grid_rows; i++)
    {
        block_x = x;
        block_y = y + i*height;
        for(int j = 0; j<Retro_grid_cols; j++)
        {
            if(retro_fonts[c][i][j] == 1)
            iFilledRectangle(block_x, block_y, width, height);
            block_x += width;
        }
    }
    return;
}

void RetroText(double x, double y, char str[], int width = 2, int height = 0)
{
    if(height == 0)
        height = width;

    y = y - height;

    for(int c = 0; str[c] != 0; c++)
    {
        RetroLetter(x, y, str[c], width, height);
        x += width*(Retro_grid_cols + 1);
    }
    return;
}




#endif // RETRO_FONTS_H

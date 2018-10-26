
void print_help(void)
{
    iShowBMP(0,SHIFT,"menu_bac.bmp");//
    switch(draw_mode)
    {
        case 15:
        iShowBMP(0,SHIFT,"HELP_1.bmp");
        break;
        case 151:
        iShowBMP(0,SHIFT,"HELP_2.bmp");
        break;
        case 152:
        iShowBMP(0,SHIFT,"HELP_3.bmp");
        break;
    }
}




void help_change()
{
    if(draw_mode==15)
        draw_mode=151;
    else
    {
        draw_mode++;
    }
    if(draw_mode>=153)
        draw_mode=1;
}
void help_input_mouse(int button, int state, int mx, int my)
{
    help_change();
}
void help_input_key(unsigned char key)
{
    help_change();
}

void help_input_sp_key(unsigned char key)
{
    help_change();
}

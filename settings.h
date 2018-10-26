int settings_p=1;

void print_settings(void)
{
    iShowBMP(0,0+SHIFT,"menu_bac.bmp");//
    //printing the boxes with text
    iSetColor(0,255,255);
    {
        iRectangle((SCREEN_WIDTH-400)/2,10+SHIFT,400,580);
    }

    iSetColor(0,179,255);
    iFilledRectangle((SCREEN_WIDTH-400)/2+60,380-(settings_p-1)*100+SHIFT,280,40);

    iSetColor(0,255,255);
    iRectangle((SCREEN_WIDTH-400)/2+50,175+SHIFT,300,50);
    iRectangle((SCREEN_WIDTH-400)/2+50,275+SHIFT,300,50);
    iRectangle((SCREEN_WIDTH-400)/2+50,375+SHIFT,300,50);

    iText((SCREEN_WIDTH-400)/2+100,390+SHIFT,"   Sounds-> ON",GLUT_BITMAP_TIMES_ROMAN_24);
    iText((SCREEN_WIDTH-400)/2+100,290+SHIFT,"   Sounds-> OFF ",GLUT_BITMAP_TIMES_ROMAN_24);
    iText((SCREEN_WIDTH-400)/2+100,190+SHIFT,"   RETURN MENU ",GLUT_BITMAP_TIMES_ROMAN_24);

}


void settings_input_mouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(mx>=(SCREEN_WIDTH-400)/2+50 && mx<=(SCREEN_WIDTH-400)/2+350 &&my>=175 && my<= 175+50)
        {
            draw_mode=1;
        }
        else if(mx>=(SCREEN_WIDTH-400)/2+50 && mx<=(SCREEN_WIDTH-400)/2+350 &&my>=275 && my<= 275+50)
        {

            stop_music();
            draw_mode=1;
            sound =0;
        }

        else if(mx>=(SCREEN_WIDTH-400)/2+50 && mx<=(SCREEN_WIDTH-400)/2+350 &&my>=375 && my<= 375+50)
        {
            sound=1;
            start_music();
            draw_mode=1;

        }
    }
}

void settings_input_key(unsigned char key)
{
    if(key=='\r')
    {
        settings_input_mouse(GLUT_LEFT_BUTTON,GLUT_DOWN,(SCREEN_WIDTH-400)/2+60,382-(settings_p-1)*100);
    }
    else if(key==8){
        //printf("draw_mode =%d\n",draw_mode);
        draw_mode=1;
    }
}

void settings_input_sp_key(unsigned char key)
{

    if (key == GLUT_KEY_UP)
    {

        settings_p--;
        if(settings_p<1)
            settings_p=3;

    }
    else if(key == GLUT_KEY_DOWN)
    {

        settings_p++;
        if(settings_p>3)
            settings_p=1;

    }
}

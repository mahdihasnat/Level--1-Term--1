int load_menu_p=1;

void print_load_menu(void) /// drawmode=12
{
    //printf(" here");

    iShowBMP(0,SHIFT,"menu_bac.bmp");//
    iSetColor(0,255,255);
    for(int i=0+SHIFT; i<680; i+=85)
    {
        iRectangle((SCREEN_WIDTH-400)/2,20+i,400,45);
        if(i+20<=110+SHIFT)
            continue;
        iLine((SCREEN_WIDTH-400)/2+100,20+i,(SCREEN_WIDTH-400)/2+100,20+i+45);
        iLine((SCREEN_WIDTH-400)/2+250,20+i,(SCREEN_WIDTH-400)/2+250,20+i+45);
    }

    iSetColor(0,179,255);
    iFilledRectangle((SCREEN_WIDTH-400)/2+10,532.5-(load_menu_p-1)*85+SHIFT,380,40);

    iSetColor(255,0,0);

    for(int i=1; i<6; i++)
    {
        if(g[i-1].dual_mode==0)
        {
            iText(440,545-(i-1)*85+SHIFT,"EMPTY",GLUT_BITMAP_TIMES_ROMAN_24);
            continue;
            //iText(300,545-(i-1)*85+SHIFT,"NULL",GLUT_BITMAP_TIMES_ROMAN_24);
        }
        else if(g[i-1].dual_mode==1)
        {
            iText(300,545-(i-1)*85+SHIFT,"  Single",GLUT_BITMAP_TIMES_ROMAN_24);
        }
        else if(g[i-1].dual_mode==2)
        {
            iText(300,545-(i-1)*85+SHIFT,"   Dual",GLUT_BITMAP_TIMES_ROMAN_24);
        }
        iText(align_string((SCREEN_WIDTH-400)/2+100,150,g[i-1].p1.user_name),545-(i-1)*85+SHIFT,g[i-1].p1.user_name,GLUT_BITMAP_TIMES_ROMAN_24);
        if(strcmp(g[i-1].p2.user_name,"NULL"))
           iText(align_string((SCREEN_WIDTH-400)/2+100+150,150,g[i-1].p2.user_name),545-(i-1)*85+SHIFT,g[i-1].p2.user_name,GLUT_BITMAP_TIMES_ROMAN_24);
    }
    iText(340,545-5*85+SHIFT,"DELETE SELECTED GAME",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(370,545-6*85+SHIFT,"BACK TO MAIN MENU",GLUT_BITMAP_TIMES_ROMAN_24);
}

void print_delete_confirmation() /// drawmode 121
{
    iShowBMP(0,SHIFT,"menu_bac.bmp");
    iSetColor(0,255,255);

    //iText((SCREEN_WIDTH-400)/2+90,10+SHIFT+400,"DELETE THIS DATA",GLUT_BITMAP_TIMES_ROMAN_24);


    int i=load_menu_p;

    for(int i=0+SHIFT; i<680; i+=2*85)
    {

        iRectangle((SCREEN_WIDTH-400)/2,20+i,400,45);
    }
    iLine((SCREEN_WIDTH-400)/2+100,20+SHIFT+85*4,(SCREEN_WIDTH-400)/2+100,20+SHIFT+85*4+45);
    iLine((SCREEN_WIDTH-400)/2+250,20+SHIFT+85*4,(SCREEN_WIDTH-400)/2+250,20+SHIFT+85*4+45);



    if(g[i-1].dual_mode==1)
    {
        iText(300,545-(3-1)*85+SHIFT,"SINGLE",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    else if(g[i-1].dual_mode==2)
    {
        iText(300,545-(3-1)*85+SHIFT,"DUAL",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    iText(align_string(400,150,g[i-1].p1.user_name),545-(3-1)*85+SHIFT,g[i-1].p1.user_name,GLUT_BITMAP_TIMES_ROMAN_24);
    iText(align_string(550,150,g[i-1].p2.user_name),545-(3-1)*85+SHIFT,g[i-1].p2.user_name,GLUT_BITMAP_TIMES_ROMAN_24);

    iText(340+45,545-0*85+SHIFT,"DELETE THIS DATA",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(340+90,545-4*85+SHIFT,"CONFIRM",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(370,545-6*85+SHIFT,"BACK TO MAIN MENU",GLUT_BITMAP_TIMES_ROMAN_24);

}

void delete_input_mouse(int button, int state, int mx, int my)
{

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(mx>=(SCREEN_WIDTH-400)/2 && mx<=(SCREEN_WIDTH-400)/2+400 &&my>=20+0 && my<=20+0+45)
        {
            draw_mode=12;
        }
        else if(mx>=(SCREEN_WIDTH-400)/2 && mx<=(SCREEN_WIDTH-400)/2+400 &&my>=20+2*85 && my<= 20+2*85+45)
        {
            //printf("del\n");
            delate_game(load_menu_p-1);
            draw_mode=12;
            return ;
        }
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here

    }
}

void load_input_mouse(int button, int state, int mx, int my)
{

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        for(int i=1; i<6; i++)
        {

            if(mx>=(SCREEN_WIDTH-400)/2 && mx<=(SCREEN_WIDTH-400)/2+400 &&my>=615-i*85&& my<= 615-i*85+45)
            {
                if(g[i-1].dual_mode==0)
                    return ;
                play_game(g[i-1]);
                return ;
            }
        }
        if(mx>=(SCREEN_WIDTH-400)/2 && mx<=(SCREEN_WIDTH-400)/2+400 &&my>=105 && my<= 105+45)
        {
            //printf("del\n");
            if(g[load_menu_p-1].dual_mode==0)
                return ;
            draw_mode=121;
            return ;
            // heree for delate
        }
        else if(mx>=(SCREEN_WIDTH-400)/2 && mx<=(SCREEN_WIDTH-400)/2+400 &&my>=20 && my<= 20+45)
        {
            goto_main_menu();
            draw_mode=1;
        }
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here

    }
}


void load_input_key(unsigned char key)
{
    if(key=='\r')
    {
        load_input_mouse(GLUT_LEFT_BUTTON,GLUT_DOWN,(SCREEN_WIDTH-400)/2+200,615-load_menu_p*85+10);
        return ;
    }
    if(key==8)
        draw_mode=1;
}

void delete_input_key(unsigned char key)
{
    if(key=='\r')
    {
        delate_game(load_menu_p-1);
        draw_mode=12;
        return ;
    }
    if(key==8)
        draw_mode=12;
}

void load_input_sp_key(unsigned char key)
{
    if (key == GLUT_KEY_END)
    {
        exit(0);
    }
    else if (key == GLUT_KEY_UP)
    {

        load_menu_p--;
        if(load_menu_p<1)
            load_menu_p=5;

    }
    else if(key == GLUT_KEY_DOWN)
    {

        load_menu_p++;
        if(load_menu_p>5)
            load_menu_p=1;

    }
    else if(key == GLUT_KEY_RIGHT)
    {

    }
    else if(key == GLUT_KEY_LEFT)
    {

    }
    //place your codes for other keys here
}


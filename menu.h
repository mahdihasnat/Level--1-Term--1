
#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 680

int mode_input_p=1;
int menu_p=1;

void goto_main_menu()
{
    reset_game(p1);
    reset_game(p2);
    draw_mode=1;

}
void pre_game_over(game_data &a)
{
    a.my_car.x=(SCREEN_WIDTH-500)/2+100;
    a.my_car.y=0;
    iPauseTimer(timer_idx[0]);
    iPauseTimer(timer_idx[1]);
    iPauseTimer(timer_idx[2]);
    iPauseTimer(timer_idx[3]);
    iPauseTimer(timer_idx[4]);

    a.total_car=0;
    update_high_score(a);
    //get_high_score();

}
void post_game_over(game_data &a)
{
    a.total_car=0;
    a.score=0;
    a.level=1;
    int_to_string(a.score,score_str);
    int_to_string(a.level,level_str);
    a.user_name[user_name_idx=0]=0;
    CAR_SPEED = 5;
    a.passed_car=0;

}
void print_game_over()
{
    if(dual_mode==2)
        iShowBMP(0,0+SHIFT,"game_over_dual.bmp");
    else iShowBMP(0,0+SHIFT,"game_over_1.bmp");
    iSetColor(255,255,255);
    strcpy(show_score,"Your SCORE : ");
    strcat(show_score,score_str);
    //iText(710,400+SHIFT,score_str,GLUT_BITMAP_TIMES_ROMAN_24);
    RetroText(720,387+SHIFT,score_str,6);
    iSetColor(0,0,0);

    if(dual_mode==2)
    {
        char str[100];
        if(win_p==1)
        {

            strcpy(str,p1.user_name);

        }
        else if(win_p==2)
        {

            strcpy(str,p2.user_name);

        }
        strcat(str," WINS ! :)");
        //iText(510,450+SHIFT,str,GLUT_BITMAP_TIMES_ROMAN_24);
        RetroText(100,450+SHIFT,str,6);
    }
}



/// 1= menu,2=playing game,3= game over
/// 11=new game ,12=load game ,13 =high score,14=setting,15=help,16=about 17=exit
/// 20= pause menu, 21=contunue,22 = save game, 23=return menu
/// 10 =mode_input

void print_menu(void)//printing the front menu
{
    iShowBMP(0,0+SHIFT,"menu_bac.bmp");//
    //printing the boxes with text
    iSetColor(0,255,255);
    for(int i=0+SHIFT; i<680; i+=85)
    {
        iRectangle((SCREEN_WIDTH-400)/2,20+i,400,45);
    }

    iSetColor(0,179,255);
    iFilledRectangle((SCREEN_WIDTH-400)/2+10,532.5-(menu_p-1)*85+SHIFT,380,40);

    iSetColor(255,0,0);
    iText(420,545+SHIFT," NEW GAME",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(420,460+SHIFT," LOAD GAME",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(420,375+SHIFT,"HALL OF FAME",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(420,290+SHIFT,"  SETTINGS",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(420,205+SHIFT,"       HELP",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(420,120+SHIFT,"      ABOUT",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(420,35+SHIFT,"       EXIT",GLUT_BITMAP_TIMES_ROMAN_24);
}
///
void print_menu_mode_11()
{
    iShowBMP(0,0+SHIFT,"menu_bac.bmp");

    iSetColor(0,0,0);
    if(draw_mode==111)
    iText(280,400+SHIFT,"PLEASE ENTER FIRST PLAYER NAME",GLUT_BITMAP_TIMES_ROMAN_24);

    else if(draw_mode==112)
    iText(280,400+SHIFT,"PLEASE ENTER SECOND PLAYER NAME ",GLUT_BITMAP_TIMES_ROMAN_24);

    iSetColor(0,255,255);
    iRectangle((SCREEN_WIDTH-400)/2,300+SHIFT,400,50);

    iSetColor(0,0,0);
    if(draw_mode==111)
    iText((SCREEN_WIDTH-400)/2,320+SHIFT,p1.user_name,GLUT_BITMAP_TIMES_ROMAN_24);

    else if(draw_mode==112)
    iText((SCREEN_WIDTH-400)/2,320+SHIFT,p2.user_name,GLUT_BITMAP_TIMES_ROMAN_24);

}

void menu_input_mouse(int button, int state, int mx, int my)
{
    if(draw_mode==12)
    {
        load_input_mouse(button,state,mx,my);
        return ;
    }
    else if(draw_mode==10)
    {
        mode_input_mouse(button,state,mx,my);
        return ;
    }
    else if(draw_mode==13)
    {
        high_score_input_mouse(button,state,mx,my);
        return ;
    }
    else if(draw_mode==14)
    {
        settings_input_mouse(button,state,mx,my);
        return ;
    }
    else if(draw_mode==121)
    {
        delete_input_mouse(button,state,mx,my);
        return ;
    }
    else if(draw_mode==15||draw_mode==151||draw_mode==152)
    {
        help_input_mouse(button,state,mx,my);
        return ;
    }
    else if(draw_mode==1)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx>=(SCREEN_WIDTH-400)/2 && mx<=(SCREEN_WIDTH-400)/2+400 &&my>=530 && my<= 530+45)
            {

                draw_mode=10;
            }
            else if(mx>=(SCREEN_WIDTH-400)/2 && mx<=(SCREEN_WIDTH-400)/2+400 &&my>=445 && my<= 445+45)
            {

                draw_mode=12;
            }
            else if(mx>=(SCREEN_WIDTH-400)/2 && mx<=(SCREEN_WIDTH-400)/2+400 &&my>=360 && my<= 360+45)
            {

                draw_mode=13;
            }
            else if(mx>=(SCREEN_WIDTH-400)/2 && mx<=(SCREEN_WIDTH-400)/2+400 &&my>=275 && my<= 275+45)
            {

                draw_mode=14;
            }
            else if(mx>=(SCREEN_WIDTH-400)/2 && mx<=(SCREEN_WIDTH-400)/2+400 &&my>=190 && my<= 190+45)
            {

                draw_mode=15;
            }
            else if(mx>=(SCREEN_WIDTH-400)/2 && mx<=(SCREEN_WIDTH-400)/2+400 &&my>=105 && my<= 105+45)
            {

                draw_mode=16;
            }
            else if(mx>=(SCREEN_WIDTH-400)/2 && mx<=(SCREEN_WIDTH-400)/2+400 &&my>=20 && my<= 20+45)
            {

                exit(17);
            }
        }
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here

    }
}

void menu_input_key(unsigned char key)
{
    if(draw_mode==12)
    {
        load_input_key(key);
        return ;
    }
    else if(draw_mode==10)
    {
        mode_input_key(key);
        return ;
    }
    else if(draw_mode==14)
    {
        settings_input_key(key);
        return ;
    }

    else if(draw_mode==13)
    {
        high_score_input_key(key);
        return ;
    }

    else if(draw_mode==111||draw_mode==112)
    {
        //printf(" here\n");
        get_user_string(key);
        return ;
    }
    else if(draw_mode==121)
    {
        delete_input_key(key);
        return ;
    }
    else if(draw_mode==15||draw_mode==151||draw_mode==152)
    {
        help_input_key(key);
        return ;
    }
    else if(draw_mode==1)
    {

        if(key=='\r')
        {
            menu_input_mouse(GLUT_LEFT_BUTTON,GLUT_DOWN,(SCREEN_WIDTH-400)/2+100,532.5-(menu_p-1)*85);
            return ;
        }
        else if(key=='N'||key=='n')
            menu_p=1;
        else if(key=='L'||key=='l')
            menu_p=2;
        else if(key=='H'||key=='h')
            menu_p=3;
        else if(key=='S'||key=='s')
            menu_p=4;
        else if(key=='a'||key=='A')
            menu_p=6;
        else if(key=='e'||key=='e')
            menu_p=7;

        return ;
    }
    if(key==8)
        draw_mode=1;
}

void menu_input_sp_key(unsigned char key)
{
    if(draw_mode==12)
    {
        load_input_sp_key(key);
        return ;
    }
    else if(draw_mode==10)
    {
        mode_input_sp_key(key);
        return ;
    }
    else if(draw_mode==14)
    {
        settings_input_sp_key(key);
        return ;
    }
    else if(draw_mode==13)
    {
        high_score_input_sp_key(key);
        return ;
    }
    else if(draw_mode==15||draw_mode==151||draw_mode==152)
    {
        help_input_sp_key(key);
        return ;
    }
    else if(draw_mode==1)
    {

        if (key == GLUT_KEY_END)
        {

            exit(0);
        }
        else if (key == GLUT_KEY_UP)
        {

            menu_p--;
            if(menu_p<1)
                menu_p=7;
        }
        else if(key == GLUT_KEY_DOWN)
        {

            menu_p++;
            if(menu_p>7)
                menu_p=1;

        }
        else if(key == GLUT_KEY_RIGHT)
        {

        }
        else if(key == GLUT_KEY_LEFT)
        {

        }
        //place your codes for other keys here
    }
}

void print_mode_input()
{
    iShowBMP(0,0+SHIFT,"menu_bac.bmp");//
    //printing the boxes with text
    iSetColor(0,255,255);
    {
        iRectangle((SCREEN_WIDTH-400)/2,10+SHIFT,400,580);
    }

    iSetColor(0,179,255);
    iFilledRectangle((SCREEN_WIDTH-400)/2+60,380-(mode_input_p-1)*100+SHIFT,280,40);

    iSetColor(0,255,255);
    iRectangle((SCREEN_WIDTH-400)/2+50,175+SHIFT,300,50);
    iRectangle((SCREEN_WIDTH-400)/2+50,275+SHIFT,300,50);
    iRectangle((SCREEN_WIDTH-400)/2+50,375+SHIFT,300,50);

    iText((SCREEN_WIDTH-400)/2+100,390+SHIFT,"         SINGLE ",GLUT_BITMAP_TIMES_ROMAN_24);
    iText((SCREEN_WIDTH-400)/2+100,290+SHIFT,"           DUAL ",GLUT_BITMAP_TIMES_ROMAN_24);
    iText((SCREEN_WIDTH-400)/2+100,190+SHIFT,"   RETURN MENU ",GLUT_BITMAP_TIMES_ROMAN_24);

}

void mode_input_mouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(mx>=(SCREEN_WIDTH-400)/2+50 && mx<=(SCREEN_WIDTH-400)/2+350 &&my>=175 && my<= 175+50)
        {
            draw_mode=1;
        }
        else if(mx>=(SCREEN_WIDTH-400)/2+50 && mx<=(SCREEN_WIDTH-400)/2+350 &&my>=275 && my<= 275+50)
        {
            draw_mode=111;
            dual_mode=2;
        }

        else if(mx>=(SCREEN_WIDTH-400)/2+50 && mx<=(SCREEN_WIDTH-400)/2+350 &&my>=375 && my<= 375+50)
        {
            draw_mode=111;
            dual_mode=1;
        }
    }
}

void mode_input_key(unsigned char key)
{
    if(key=='\r')
    {
        mode_input_mouse(GLUT_LEFT_BUTTON,GLUT_DOWN,(SCREEN_WIDTH-400)/2+60,382-(mode_input_p-1)*100);
    }
    else if(key==8){
        //printf("draw_mode =%d\n",draw_mode);
        draw_mode=1;
    }
}

void mode_input_sp_key(unsigned char key)
{

    if (key == GLUT_KEY_UP)
    {

        mode_input_p--;
        if(mode_input_p<1)
            mode_input_p=3;


    }
    else if(key == GLUT_KEY_DOWN)
    {

        mode_input_p++;
        if(mode_input_p>3)
            mode_input_p=1;

    }
}

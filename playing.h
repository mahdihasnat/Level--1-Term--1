//
//#define SCREEN_WIDTH 1000
//#define SCREEN_HEIGHT 680

#define CAR_WIDTH 50
#define CAR_HEIGHT 75
#define CAR_PER_LEVEL 10
#define PER_KEY_MOVE 30
#define LIFE_START 5

int pause_menu_p=1;


void play_start()
{
    char str1[100],str2[100];
    strcpy(str1,p1.user_name);
    strcpy(str2,p2.user_name);

    reset_game(p1);
    reset_game(p2);

    strcpy(p1.user_name,str1);
    strcpy(p2.user_name,str2);


    iResumeTimer(timer_idx[0]);
    iResumeTimer(timer_idx[1]);
    iResumeTimer(timer_idx[2]);
    CAR_SPEED=5+(p1.level-1);

}


void playing_input_mouse(int button, int state, int mx, int my)
{
    if(draw_mode==20)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx>=(SCREEN_WIDTH-400)/2+50 && mx<=(SCREEN_WIDTH-400)/2+350 &&my>=175 && my<= 175+50)
            {
                //printf(" here ");
                draw_mode=1;
                p1.user_name[user_name_idx=0]=0;
                reset_game(p1);
                reset_game(p2);
                dual_mode=0;
            }
            else if(mx>=(SCREEN_WIDTH-400)/2+50 && mx<=(SCREEN_WIDTH-400)/2+350 &&my>=275 && my<= 275+50)
            {


                save_game();
                draw_mode=1;
                // here for save game;
            }

            else if(mx>=(SCREEN_WIDTH-400)/2+50 && mx<=(SCREEN_WIDTH-400)/2+350 &&my>=375 && my<= 375+50)
            {

                draw_mode=2;
                resume_game();
                return ;
            }


        }
        if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        {
            //place your codes here
        }
    }
}


void change_my_car_key(unsigned char key,game_data *a)
{

    if(key == 'W'||key=='w')
    {
        a->my_car.y+=PER_KEY_MOVE;
        if(a->my_car.y+CAR_HEIGHT>SCREEN_HEIGHT-SHIFT)
            a->my_car.y=SCREEN_HEIGHT-CAR_HEIGHT-SHIFT;
    }
    else if(key == 's'||key=='S')
    {
        a->my_car.y-=PER_KEY_MOVE;
        if(a->my_car.y<0)
            a->my_car.y=0;
    }
    else if(key == 'D'||key=='d')
    {
        a->my_car.x+=PER_KEY_MOVE;
        if(a->my_car.x+CAR_WIDTH >400)
            a->my_car.x=400-CAR_WIDTH;
    }
    else if(key == 'a'||key=='A')
    {
        a->my_car.x-=PER_KEY_MOVE;
        if(a->my_car.x<100)
            a->my_car.x=100;
    }
}

void playing_input_key(unsigned char key)
{

    if(draw_mode==20)
    {
        if(key=='\r')
        {
            playing_input_mouse(GLUT_LEFT_BUTTON,GLUT_DOWN,(SCREEN_WIDTH-400)/2+60,382-(pause_menu_p-1)*100);
            return ;
        }
        return ;
    }
    else if(draw_mode==2)
    {
        if(key=='p'||key=='P')
        {

            pause_game();
            draw_mode=20;
        }
        change_my_car_key(key,&p1);
    }

}


///change my car for changing the orientatation of my car
void change_my_car_sp_key(char key,game_data *a)
{

    if (key == GLUT_KEY_END)
    {
        exit(0);
    }
    else if(key == GLUT_KEY_UP)
    {
        a->my_car.y+=PER_KEY_MOVE;
        if(a->my_car.y+CAR_HEIGHT>SCREEN_HEIGHT-SHIFT)
            a->my_car.y=SCREEN_HEIGHT-CAR_HEIGHT-SHIFT;
    }
    else if(key == GLUT_KEY_DOWN)
    {
        a->my_car.y-=PER_KEY_MOVE;
        if(a->my_car.y<0)
            a->my_car.y=0;
    }
    else if(key == GLUT_KEY_RIGHT)
    {
        a->my_car.x+=PER_KEY_MOVE;
        if(a->my_car.x+CAR_WIDTH >400)
            a->my_car.x=400-CAR_WIDTH;
    }
    else if(key == GLUT_KEY_LEFT)
    {
        a->my_car.x-=PER_KEY_MOVE;
        if(a->my_car.x<100)
            a->my_car.x=100;
    }
    //printf(" x= %f y= %f\n",a->my_car.x,a->my_car.y);
}


void playing_input_sp_key(unsigned char key)
{

    if (key == GLUT_KEY_END)
    {

        exit(0);
    }
    if(draw_mode==2)
    {
        if(dual_mode==2)
        {
            change_my_car_sp_key(key,&p2);
        }
        else if(dual_mode==1)
            change_my_car_sp_key(key,&p1);
        else printf(" dual mode !=1,!=2\n");
    }
    else if(draw_mode==20)
    {

        if (key == GLUT_KEY_UP)
        {

            pause_menu_p--;
            if(pause_menu_p<1)
                pause_menu_p=3;

        }
        else if(key == GLUT_KEY_DOWN)
        {

            pause_menu_p++;
            if(pause_menu_p>3)
                pause_menu_p=1;

        }
        else if(key == GLUT_KEY_RIGHT)
        {

        }
        else if(key == GLUT_KEY_LEFT)
        {

        }
    }
    //place your codes for other keys here
}



void print_player_inf()
{
    iSetColor(129,209,153);
    iFilledRectangle(400,0+SHIFT,200,600);

    char str[100]="LEVEL : ";
    strcat(str,level_str);
    iSetColor(255,255,255);
    iText(440,570+SHIFT,str,GLUT_BITMAP_TIMES_ROMAN_24);
    iLine(400,560+SHIFT,600,560+SHIFT);

    strcpy(str,"LEFT PLAYER : ");
    iText(400,520+SHIFT,str,GLUT_BITMAP_TIMES_ROMAN_24);


    str[0]=0;
    int space=(30-strlen(p1.user_name))/2;
    for(int i=0;i<space;i++)
        strcat(str," ");
    strcat(str,p1.user_name);
    iText(400,490+SHIFT,str,GLUT_BITMAP_TIMES_ROMAN_24);


    iText(400,460+SHIFT,"SCORE :",GLUT_BITMAP_TIMES_ROMAN_24);
    int_to_string(p1.score,score_str);
    iText(400,430+SHIFT,score_str,GLUT_BITMAP_TIMES_ROMAN_24);

    print_life_meter(400+70,280+10+SHIFT,p1.life);

    iLine(400,280+SHIFT,600,280+SHIFT);

    iSetColor(255,255,255);
    iText(400,250+SHIFT,"RIGHT PLAYER : ",GLUT_BITMAP_TIMES_ROMAN_24);


    str[0]=0;
    space=(30-strlen(p2.user_name))/2;
    for(int i=0;i<space;i++)
        strcat(str," ");
    strcat(str,p2.user_name);


    iText(400,220+SHIFT,str,GLUT_BITMAP_TIMES_ROMAN_24);
    iText(400,190+SHIFT,"SCORE :",GLUT_BITMAP_TIMES_ROMAN_24);
    int_to_string(p2.score,score_str);
    iText(400,160+SHIFT,score_str,GLUT_BITMAP_TIMES_ROMAN_24);



    print_life_meter(400+70,10+SHIFT,p2.life);


}


void print_pause_menu() /// draw_mode =20
{
    iShowBMP(0,SHIFT,"menu_bac.bmp");//
    //printing the boxes with text


    //iRectangle((SCREEN_WIDTH-400)/2,10,400,580);

    iSetColor(0,179,255);
    iFilledRectangle((SCREEN_WIDTH-400)/2+60,380-(pause_menu_p-1)*100+SHIFT,280,40);

    iSetColor(0,255,255);
    iRectangle((SCREEN_WIDTH-400)/2+50,175+SHIFT,300,50);
    iRectangle((SCREEN_WIDTH-400)/2+50,275+SHIFT,300,50);
    iRectangle((SCREEN_WIDTH-400)/2+50,375+SHIFT,300,50);

    iText((SCREEN_WIDTH-400)/2+100,390+SHIFT,"     CONTINUE ",GLUT_BITMAP_TIMES_ROMAN_24);
    iText((SCREEN_WIDTH-400)/2+100,290+SHIFT,"     SAVE GAME",GLUT_BITMAP_TIMES_ROMAN_24);
    iText((SCREEN_WIDTH-400)/2+100,190+SHIFT,"   RETURN MENU ",GLUT_BITMAP_TIMES_ROMAN_24);

}

void reset_game(game_data &a)
{
    game_data tmp;
    a=tmp;
    a.user_name[user_name_idx=0]=0;
    iPauseTimer(timer_idx[0]);
    iPauseTimer(timer_idx[1]);
    iPauseTimer(timer_idx[2]);
    iPauseTimer(timer_idx[3]);
    iPauseTimer(timer_idx[4]);
    CAR_SPEED=5+(a.level-1);
}

void play_game(struct game tmp)
{
    /*
       strcpy(user_name,a.user_name);
       total_car=a.total_car;
       for(int i=0;i<total_car;i++)
           cars[i]=a.cars[i];
       my_car=a.my_car;
       life=a.life;
       passed_car=a.passed_car;
       score=a.score;
       level=a.level;

       */
    dual_mode=tmp.dual_mode;
    p1=tmp.p1;
    p2=tmp.p2;

    CAR_SPEED=5+(tmp.p1.level-1);
    iResumeTimer(timer_idx[0]);
    iResumeTimer(timer_idx[1]);
    iResumeTimer(timer_idx[2]);

    draw_mode=2;
}
void get_user_string(char key)
{
    if(key == '\r')
    {
        if(user_name_idx==0)
            return ;
        if(draw_mode==112)
        {
            play_start();
            draw_mode=2;
        }
        else if(draw_mode==111)
        {
            if(dual_mode==2)
            {
                draw_mode=112;
                user_name_idx=0;
            }
            else if(dual_mode==1)
            {
                play_start();
                draw_mode=2;
            }
        }
    }
    else if(key==8)
    {
        if(user_name_idx!=0)
        {

            if(draw_mode==111)
                p1.user_name[--user_name_idx]=0;
            else if(draw_mode==112)
                p2.user_name[--user_name_idx]=0;
        }
        else
        {
            if(draw_mode==112)
            {
                p2.user_name[user_name_idx=0]=0;
                user_name_idx=strlen(p1.user_name)-1;
                draw_mode=111;
            }
            else
            {
                p2.user_name[user_name_idx=0]=0;
                draw_mode=1;
            }
        }
    }
    else if(user_name_idx>=9)
        return ;
    else
    {

        if(draw_mode==111)
        {
            p1.user_name[user_name_idx]=key;
            p1.user_name[++user_name_idx]=0;
        }
        else if(draw_mode==112)
        {
            p2.user_name[user_name_idx]=key;
            p2.user_name[++user_name_idx]=0;
        }
    }
}




void pause_game()
{
    iPauseTimer(timer_idx[0]);
    iPauseTimer(timer_idx[1]);
    iPauseTimer(timer_idx[2]);
    iPauseTimer(timer_idx[3]);
    iPauseTimer(timer_idx[4]);

}
void resume_game()
{
    iResumeTimer(timer_idx[0]);
    iResumeTimer(timer_idx[1]);
    iResumeTimer(timer_idx[2]);
}

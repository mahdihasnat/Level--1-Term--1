# include "iGraphics.h"
# include <windows.h>
# include "Retro-fonts.h"
// global variables




#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 680
#define SHIFT 80


#define CAR_WIDTH 50
#define CAR_HEIGHT 75

#define PER_KEY_MOVE 30
#define LIFE_START 5





int draw_mode=1;/// modes are needed in handling the different phase of the game

/// 1= menu,2=playing game,3= game over
/// 11=new game ,12=load game ,13 =high score,14=setting,15=help,16=about 17=exit
/// 20= pause menu, 21=contunue,22 = save game, 23=return menu
/// 10 =mode_input


int timer_idx[10];
//char user_name[100];

int user_name_idx=0;
//int life;
//int score=0;
double CAR_SPEED = 5;
//int level=1;
//int passed_car=0;
//int total_car=0;
//int flag_special_car=0;

int dual_mode=0;// dual mode 0 means undefined 1 for single 2 for double
int win_p=0;
struct power
{
    double x,y;
    int type,flg;
    power()
    {
        flg=0;
    }
};//using name power v :p

struct high_score
{
    char name[100];
    int score;
    high_score()
    {
        strcpy(name,"NULL");
        score=0;
    }
} hs[7] ;


struct car
{
    double x,y;
    int type;
};


struct game_data
{
    char user_name[100];
    int total_car;
    car cars[100];
    car my_car;
    power p;

    int life;
    int passed_car;
    int score;
    int level;
    game_data()
    {
        strcpy(user_name,"NULL");
        score=0;
        my_car.type=0;
        my_car.y=0;
        my_car.x=200;
        life=LIFE_START;
        total_car=0;
        level=1;
        p.flg=0;
        passed_car=0;
    }
} p1,p2;

struct game
{
    int dual_mode;
    struct game_data p1,p2;
    game()
    {
        dual_mode=0;
    }
} g[6];


# include "prototypes.h"
# include "road.h"
# include "car.h"
# include "menu.h"
//# include "updating_data.h"
# include "sounds.h"
# include "playing.h"
# include "settings.h"
# include "help.h"
# include "about.h"
# include "highscore.h"
# include "load_game.h"
# include "save_data.h"
# include "aligner.h"



/// 1= menu,2=playing game,3= game over
/// 11=new game ,12=load game ,13 =high score,14=setting,15=help,16=about 17=exit
/// 20= pause menu, 21=continue ,22 = save game, 23=return menu
/// 11 = input user name 111=first player 112 second player  10=mode_input
///121= confirmation

void iDraw()
{
    iClear();
    // road position will be middle of size
    // road width =500,height =600
    //printf("carspeed =%f\n",CAR_SPEED);
    if(draw_mode==1)// printing menu
    {
        print_menu();
    }
    else if(draw_mode==10)
    {
        print_mode_input();
    }
    else if(draw_mode==111||draw_mode==112)
    {
        print_menu_mode_11();
    }
    else if(draw_mode==13)
    {
        print_high_score();
    }
    else if(draw_mode==14)
    {
        print_settings();
    }
    else if(draw_mode==15 ||draw_mode==151||draw_mode==152)
    {
        print_help();
    }
    else if(draw_mode==16)
    {
        print_about();
    }
    else if(draw_mode==2)//running the game
    {
        if(dual_mode==2)
        {
            print_road_background(0,SHIFT);
            print_road_background(500,SHIFT);

            print_all_cars(0,SHIFT,p1);
            print_all_cars(500,SHIFT,p2);

            print_player_inf();


            if(car_col(p1))
            {
                pre_game_over(p1);
                pre_game_over(p2);
                draw_mode=3;
                win_p=2;
            }
            else if(car_col(p2))
            {
                pre_game_over(p1);
                pre_game_over(p2);
                draw_mode=3;
                win_p=1;
            }

        }
        else if(dual_mode==1)
        {
            iSetColor(198,103,103);
            iFilledRectangle(0,0+SHIFT,1000,600);
            print_road_background(250,SHIFT);
            print_all_cars(250,SHIFT,p1);
            print_road_right();
            print_road_left();

            if(car_col(p1))
            {
                pre_game_over(p1);
                draw_mode=3;// if car collides with one another mode switched to game over
                //exit(1);
            }
        }

    }
    else if(draw_mode==3)//game over
    {
        print_game_over();

    }

    else if(draw_mode==20)
    {
        print_pause_menu();
    }
    else if(draw_mode==12)
    {
        print_load_menu();
    }
    else if(draw_mode==121)
    {
        print_delete_confirmation();
    }


    iSetColor(0,0,0);
    iFilledRectangle(0,0,SCREEN_WIDTH,SHIFT);
    iSetColor(255,255,255);
    //for(int i=0;i<1000;i++)
        //for(int j=0;j<600;j++)
    //RetroText(0,5,"A MAHDI KOWSHIC production",6,7);
}
/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/

void iMouseMove(int mx, int my)
{
    //printf("x = %d, y= %d\n",mx,my);
    //place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
{

    if(draw_mode==1 || (draw_mode>=10&&draw_mode<20) || (draw_mode>=110 && draw_mode<200))
    {
        menu_input_mouse( button, state,mx, my-SHIFT);
        return ;
    }/*
    else if(draw_mode==3)
    {
        draw_mode=1;
        post_game_over(p1);
        post_game_over(p2);
        return ;
    }*/
    else if(draw_mode==2||(draw_mode>=20&&draw_mode<30))
    {
        playing_input_mouse(button,state,mx,my-SHIFT);
        return ;
    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {

    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {

    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/


void iKeyboard(unsigned char key)
{
/*
    if(key=='q'|| key=='Q')
        exit(1);
*/
    if(draw_mode==1||(draw_mode>=10&&draw_mode<20) || (draw_mode>=110 && draw_mode<200))
    {
        menu_input_key(key);
        return ;
    }
    else if(draw_mode==3)
    {
        if(key == 'W'||key=='w'||key == 's'||key=='S'||key == 'D'||key=='d'||key == 'a'||key=='A')
        {
            return ;
        }
        else
        {
            draw_mode=1;
            post_game_over(p1);
            post_game_over(p2);
            return ;
        }
    }
    else if(draw_mode==2||(draw_mode>=20&&draw_mode<30))
    {
        playing_input_key(key);
        return ;
    }
    /*if (key == 'q' ||key == 'Q')
    {
        exit(0);
    }*/
    //place your codes for other keys here
}


/*
	function iSpecialKeyboard() is called whenver user iSetColor(198,103,103);
    iFilledRectangle(0,0,1000,600);hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key)
{
    if(draw_mode==1||(draw_mode>=10&&draw_mode<20) || (draw_mode>=110 && draw_mode<200))
    {
        menu_input_sp_key(key);
        return ;
    }
    if(draw_mode==2||(draw_mode>=20&&draw_mode<30))
    {
        playing_input_sp_key(key);
        return ;
    }
    if(draw_mode==3)
    {

        if (key == GLUT_KEY_UP||key == GLUT_KEY_DOWN||key == GLUT_KEY_RIGHT||key == GLUT_KEY_LEFT )
        {

            return ;
        }
        else
        {

            post_game_over(p1);
            post_game_over(p2);
            draw_mode=1;
        }
    }
    if (key == GLUT_KEY_END)
    {
        exit(0);
    }
    //place your codes for other keys here
}


int main()
{
    //place your own initialization codes here.
    LoadFonts();
    time_t  t;
    srand((unsigned) time(&t));

    start_music();


    timer_idx[0]=iSetTimer(1,road_run);
    timer_idx[1]=iSetTimer(1,car_run);
    timer_idx[2]=iSetTimer(1000,car_new);
    timer_idx[3]=iSetTimer(700,car_new);
    timer_idx[4]=iSetTimer(500,car_new);
    timer_idx[5]=iSetTimer(180000,sync_music);


    iPauseTimer(timer_idx[0]);
    iPauseTimer(timer_idx[1]);
    iPauseTimer(timer_idx[2]);
    iPauseTimer(timer_idx[3]);
    iPauseTimer(timer_idx[4]);

    load_game_data();

    get_high_score();

    p1.user_name[0]=0;
    p2.user_name[0]=0;
    iInitialize(SCREEN_WIDTH,SCREEN_HEIGHT,"NEED FOR SPEED" );
    return 0;
}

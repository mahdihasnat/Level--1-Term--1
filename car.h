
#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 680


#define CAR_WIDTH 50
#define CAR_HEIGHT 75
#define CAR_PER_LEVEL 10
#define PER_KEY_MOVE 30
#define min(x,y) (x<y ? x : y)


//prototypes
void print_car(int left,int bottom,int type);
void print_car_pic(double left,double bottom,int type);
void print_car_demo(double left,double bottom,int type);
int car_col_cmp(car a,car b);


void print_all_cars(double left,double bottom,game_data &a)
{

    print_car_demo(left+a.my_car.x,bottom+a.my_car.y,a.my_car.type);
    for(int i=0; i<a.total_car; i++)
        print_car_demo(left+a.cars[i].x,bottom+a.cars[i].y,a.cars[i].type);
    if(a.p.flg)
    {
        print_car_demo(left+a.p.x,bottom+a.p.y,a.p.type);
    }
}

void print_car(int left,int bottom, int type)
{

    /*
    left+=100;bottom+=100;
    iSetColor(255,0,0);
    iFilledRectangle(left,bottom,80,120);//printing main body
    //printing the headlights
    iFilledEllipse(left+30,bottom-30,5,3,15);
    iFilledEllipse(left+80-30,bottom-30,5,3,15);
    //printing the front part
    iSetColor(0,255,0);
    iFilledRectangle(left+20,bottom-30,40,30);

    //printing side bars
    iSetColor(0,0,0);
    iFilledRectangle(left,bottom,5,120);
    iFilledRectangle(left-5+80,bottom,5,120);
    //iFilledCircle()
    */
    //drawTexture(left,bottom,textures[3]);
    //iShowBMP(left,bottom,"pic_car_3.bmp");
}
void print_car_demo(double left,double bottom,int type)
{
    iSetColor(255,255,255);
    //iFilledRectangle(left,bottom,CAR_WIDTH,CAR_HEIGHT);

    iSetColor(0,0,0);
    if(type==0)
    {
        iText(left,bottom+10,"BUET");
        iText(left,bottom,"IAN");
        iShowBMP(left,bottom,"car1.bmp");
    }
    else if(type==1)
    {
        iText(left,bottom+10,"CT");
        iShowBMP(left,bottom,"car2.bmp");
    }
    else if(type==2)
    {
        iText(left,bottom+10,"Online");
        iShowBMP(left,bottom,"car3.bmp");
    }
    else if(type==3)
    {
        iText(left,bottom+10,"Lab");
        iShowBMP(left,bottom,"car4.bmp");
    }
    else if(type==4)
    {
        iText(left,bottom+10,"Quiz");
        iShowBMP(left,bottom,"car5.bmp");
    }
    else if(type==5)
    {
        iText(left,bottom+10,"Viva");
        iShowBMP(left,bottom,"car6.bmp");// i+1 :/
    }
    else if(type==11) //powers
    {
        iSetColor(28,189,34);
        //iFilledCircle(left+15,bottom+15,15);
        iShowBMP(left,bottom,"life.bmp");
    }
    else if(type==12)
    {
        iSetColor(200,189,34);
        iShowBMP(left,bottom,"score.bmp");
    }
    else if(type==13)
    {
        iSetColor(208,189,204);
        iShowBMP(left,bottom,"speed.bmp");
    }
}

void car_new()
{
    p1.cars[p1.total_car].x=100+rand()%(300-CAR_WIDTH);
    p1.cars[p1.total_car].y=SCREEN_HEIGHT;
    p1.cars[p1.total_car].type=rand()%5+1;
    p2.cars[p2.total_car]=p1.cars[p1.total_car];
    p1.total_car++;
    p2.total_car++;
}
int car_and_power(game_data a,int x)
{
    for(int i=0; i<a.total_car; i++)
    {
        if(abs(a.cars[i].x-x)<=50 && abs(a.cars[i].y-600)<=75)
            return 1;
    }
    return 0;
}
void car_run()
{
    if(CAR_SPEED<=9.0)
    {
        iResumeTimer(timer_idx[2]);
        iPauseTimer(timer_idx[3]);
        iPauseTimer(timer_idx[4]);
    }
    else if(CAR_SPEED<=13.0)
    {
        iResumeTimer(timer_idx[3]);
        iPauseTimer(timer_idx[2]);
        iPauseTimer(timer_idx[4]);
    }
    else
    {
        iResumeTimer(timer_idx[4]);
        iPauseTimer(timer_idx[2]);
        iPauseTimer(timer_idx[3]);
    }


    p1.p.y-=CAR_SPEED;
    if(dual_mode==2)
        p2.p.y-=CAR_SPEED;

    for(int i=0; i<p1.total_car; i++)
    {
        p1.cars[i].y-=CAR_SPEED;
    }
    for(int i=0; i<p1.total_car; i++)
    {
        if(p1.cars[i].y+CAR_HEIGHT<0)
        {
            // car passing here
            --p1.total_car;
            p1.cars[i]=p1.cars[p1.total_car];
            p1.passed_car++;
            p1.score+=10;
            //int_to_string(p1.score,score_str);
        }
    }
    if(p1.passed_car>=CAR_PER_LEVEL)
    {
        p1.level++;
        int_to_string(p1.level,level_str);
        CAR_SPEED++;
        p1.passed_car=0;

        // special car part
            p1.p.flg=1;
            do
            {
                p1.p.x=100+rand()%(300-CAR_WIDTH);
            }
            while(car_and_power(p1,p1.p.x));

            p1.p.y=SCREEN_HEIGHT;

            //p1.p.type=11+0;// powers are 11 12 13
            p1.p.type=11+(rand()%3);// powers are 11 12 13


    }

/// p2
    for(int i=0; i<p2.total_car; i++)
    {
        p2.cars[i].y-=CAR_SPEED;
    }
    for(int i=0; i<p2.total_car; i++)
    {
        if(p2.cars[i].y+CAR_HEIGHT<0)
        {
            // car passing here
            --p2.total_car;
            p2.cars[i]=p2.cars[p2.total_car];
            p2.passed_car++;
            p2.score+=10;
            //int_to_string(p2.score,score_str);
        }
    }
    if(p2.passed_car>=CAR_PER_LEVEL)
    {
        p2.level++;
        int_to_string(p2.level,level_str);
        //CAR_SPEED++;
        p2.passed_car=0;

        if(p1.p.flg)
        {

            p2.p.flg=1;
            p2.p.x=p1.p.x;
            p2.p.y=SCREEN_HEIGHT;
            p2.p.type=p1.p.type;// powers are 11 12 13
        }
        else
        {
            p2.p.flg=1;
            do
            {
                p2.p.x=100+rand()%(300-CAR_WIDTH);
            }
            while(car_and_power(p2,p2.p.x));

            p2.p.y=SCREEN_HEIGHT;

            //p2.p.type=11+0;// powers are 11 12 13
            p2.p.type=11+(rand()%3);// powers are 11 12 13

        }

    }
    if(p1.p.flg)
    {
        power_col(p1);
    }
    if(p2.p.flg)
    {
        power_col(p2);
    }

}

void power_col(game_data &a)
{
    if(abs(a.my_car.x-a.p.x)<CAR_WIDTH && abs(a.my_car.y-a.p.y)<CAR_HEIGHT)
    {
        if(a.p.type==11)
        {
            a.life=min(a.life+2,5);
        }
        else if(a.p.type==12)
        {
            a.score+=150;

        }
        else if(a.p.type==13)
        {
            a.score=max(0,a.score-200);
        }
        a.p.flg=0;

    }
}


int car_col(game_data &a)
{
   // return 0;
    for(int i=0; i<a.total_car; i++)
    {
        if(car_col_cmp(a,i))
        {
            a.life--;
            return a.life<=0;
        }
    }
    return 0;
}
int car_col_cmp(game_data &a,int i)
{
    if(abs(a.my_car.x-a.cars[i].x)<CAR_WIDTH && abs(a.my_car.y-a.cars[i].y)<CAR_HEIGHT)
    {
        a.cars[i]=a.cars[--a.total_car];
        return 1;
    }
    return 0;
}



#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 680


char * int_to_string(int a,char *s)
{
    if(a<10)
    {
        *s=a+'0';
        s++;
        *s=0;
        return s;
    }
    s=int_to_string(a/10,s);
    *s=a%10+'0';
    s++;
    *s=0;
    return s;
}


static double line_extra=0;
static double road_extra=0;
char score_str[20]="0";
char level_str[20]="1";
char show_score[50]="";

void print_road_right()
{
    iSetColor(198,103+SHIFT,103);
    iFilledRectangle((SCREEN_WIDTH-500)/2+500,0+SHIFT,(SCREEN_WIDTH-500)/2,SCREEN_HEIGHT);

    // score print
    iSetColor(255,255,255);
    strcpy(show_score,"Your SCORE : ");
    int_to_string(p1.score,score_str);
    strcat(show_score,score_str);
    iText((SCREEN_WIDTH-500)/2+500+10,400+50+SHIFT,show_score,GLUT_BITMAP_TIMES_ROMAN_24);


    strcpy(show_score,"Level : ");
    strcat(show_score,level_str);
    iText((SCREEN_WIDTH-500)/2+500+10,200+50+SHIFT,show_score,GLUT_BITMAP_TIMES_ROMAN_24);



}
void print_road_left()
{
    iSetColor(255,255,255);
    iText(align_string(0,250,p1.user_name),490+SHIFT,p1.user_name,GLUT_BITMAP_TIMES_ROMAN_24);

    print_life_meter(100,350,p1.life);
}

void print_life_meter(double left,double bottom,int life)
{

    int i;
    iRectangle(left,bottom,60,80);
    iRectangle(left+15,bottom+80,30,20);
    if(life==5)
    {
        iSetColor(0,128,0);


    }
    if(life==4)
    {
        iSetColor(255,127,8);

    }
    else if(life==3)
    {
        iSetColor(255,255,0);
    }
    else if(life==2)
    {
        iSetColor(238,130,238);
    }
    else if(life==1)
    {
        iSetColor(220,20,60);
    }
    for(i=0;i<life;i++){
        if(i==4){
                iFilledRectangle(left+15+4,bottom+80+4,30-8,20-8);
        }
        else iFilledRectangle(left+4,bottom+i*20+4,52,12);
       }
}

void print_road_background(double left,double bottom)
{
    iSetColor(255,255,255);
    iShowBMP(left,bottom,"pic_road_3.bmp");// background image
    iSetColor(255,255,255);

    iSetColor(255,255,255);// white color
    for(int i=2;i<=3;i++){
        for(int j=0;j<30;j++){
            iFilledRectangle(left+i*100-3.5,bottom+line_extra+j*40,7,20);
        }
    }

}
void road_run()
{
    line_extra-=1;
    road_extra-=1;

    if(line_extra<-20) line_extra=20;
    if(road_extra<-600) road_extra=0;
}



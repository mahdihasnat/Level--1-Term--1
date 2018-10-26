void print_high_score()
{

    iShowBMP(0,SHIFT,"halloffame.bmp");//
    int gap=12,c=4,serial;
    char str[100];

    iSetColor(255,0,0);
    iText((SCREEN_WIDTH-400)/2+30+70,610,"HALL OF FAME",GLUT_BITMAP_TIMES_ROMAN_24);


    for(int i=0+SHIFT+85; i<510; i+=85,c--)
    {
        if(strcmp(hs[c].name,"NULL")==0)
            continue;


        iRectangle((SCREEN_WIDTH-400)/2,20+i,400,45);

        str[0]=0;
        int_to_string(c+1,str);
        strcat(str," . ");
        iText((SCREEN_WIDTH-400)/2+gap,20+i+gap,str,GLUT_BITMAP_TIMES_ROMAN_24);

        iText((SCREEN_WIDTH-400)/2+gap+30,20+i+gap,hs[c].name,GLUT_BITMAP_TIMES_ROMAN_24);
        str[0]=0;
        int_to_string(hs[c].score,str);
        iText((SCREEN_WIDTH-400)/2+gap+300,20+i+gap,str,GLUT_BITMAP_TIMES_ROMAN_24);
        //if(i+20<=110+SHIFT) continue;
        //iLine((SCREEN_WIDTH-400)/2+100,20+i,(SCREEN_WIDTH-400)/2+100,20+i+45);
        //iLine((SCREEN_WIDTH-400)/2+250,20+i,(SCREEN_WIDTH-400)/2+250,20+i+45);
    }

    iRectangle((SCREEN_WIDTH-400)/2,20+SHIFT,400,45);
    iText((SCREEN_WIDTH-400)/2+30+40,20+SHIFT+15,"BACK TO MAIN MENU",GLUT_BITMAP_TIMES_ROMAN_24);
}


void get_high_score()
{

    FILE *f;
    f=fopen("high_score","r");

    if(f==NULL)
    {
        //printf("ki re goru");
        return ;
    }
    fread(&hs,sizeof(struct high_score),6,f);

    fclose(f);

}

void high_score_input_mouse(int button, int state, int mx, int my)
{
    if(draw_mode==13)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            //printf("here\n");
            if(mx>=(SCREEN_WIDTH-400)/2 && mx<=(SCREEN_WIDTH-400)/2+400 && my>=20&& my<=20+45 )
            {
                //printf("HERE HERER\n");
                draw_mode=1;
            }
        }
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here

    }
}


void high_score_input_key(unsigned char key)
{
    if(key=='d' || key=='D')
    {
        erase_high_score();
    }
    else if(key==8)
    {
        draw_mode=1;
    }
}

void high_score_input_sp_key(unsigned char key)
{

}


void update_high_score(struct game_data a)
{
    strcpy(hs[6].name,a.user_name);
    hs[6].score=a.score;
    int num=6;
    struct high_score t;
    for(; num; num--)
    {
        if(hs[num].score>hs[num-1].score)
        {
            t=hs[num];
            hs[num]=hs[num-1];
            hs[num-1]=t;
        }
        else
            break;
    }
    FILE *fp;
    fp=fopen("high_score","wb");
    if(fp==NULL)
    {
        printf("error writing high score file");
        return ;
    }
    fwrite(&hs,sizeof(struct high_score),6,fp);
    fclose(fp);
    //printf("been here");

}


void erase_high_score()
{
    FILE *fp=fopen("high_score","w");
    fclose(fp);
}



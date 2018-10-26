/*
int total_game_information=0;

void save_game()
{
    //load_a_game();
    update_game();
    save_file();
}

void save_file(void)
{
    FILE *fp;
    if((fp=fopen("game_data.txt","w"))==NULL)
        printf("error opening file");

    fprintf(fp,"%d\n",total_game_information);
    printf("total game inf  %d\n",total_game_information);

    for(int i=0;i<total_game_information;i++)
    {
        fprintf(fp,"%s\n",game_information[i].user_name);
        fprintf(fp,"%d \n",game_information[i].total_car);
        for(int j=0;j<game_information[i].total_car;j++)
            fprintf(fp,"%f %f %d \n",game_information[i].cars[j].x,game_information[i].cars[j].y,game_information[i].cars[j].type);
        fprintf(fp,"%f %f %d\n",game_information[i].my_car.x,game_information[i].my_car.y,game_information[i].my_car.type);
        fprintf(fp,"%d %d %d %d\n",game_information[i].life,game_information[i].passed_car,game_information[i].score,game_information[i].level);

    }

    fclose(fp);

}
void update_game()
{
    total_game_information=min(5,total_game_information+1);
    game_information[total_game_information-1]=p1;

}
*/
/*
void load_a_game()
{
    strcpy(a.user_name,user_name);
    a.total_car=total_car;
    for(int i=0;i<total_car;i++)
        a.cars[i]=cars[i];
    a.my_car=my_car;
    a.life=life;
    a.passed_car=passed_car;
    a.score=score;
    a.level=level;
}
*/
/*
void load_game_data()
{
    FILE *fp;
    fp=fopen("game_data.txt","a+");
    fseek(fp,0,SEEK_SET);
    fscanf(fp," %d",&total_game_information);
    printf("total game inf  %d\n",total_game_information);

    for(int i=0;i<total_game_information;i++)
    {
        fscanf(fp," %s",game_information[i].user_name);
        fscanf(fp," %d",&game_information[i].total_car);
        for(int j=0;j<game_information[i].total_car;j++)
            fscanf(fp,"%f %f %d",&game_information[i].cars[j].x,&game_information[i].cars[j].y,&game_information[i].cars[j].type);
        fscanf(fp,"%f %f %d",&game_information[i].my_car.x,&game_information[i].my_car.y,&game_information[i].my_car.type);
        fscanf(fp,"%d %d %d %d",&game_information[i].life,&game_information[i].passed_car,&game_information[i].score,&game_information[i].level);

    }
    fclose(fp);
    return ;
}

void delate_game(int idx)
{
    struct game_data tmp;
    for(int i=idx;i<4;i++)
        game_information[i]=game_information[i+1];
    game_information[4]=tmp;
    total_game_information--;
    total_game_information=max(0,total_game_information);
    save_file();
}
*/

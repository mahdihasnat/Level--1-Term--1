int  total_g_inf=0;

void save_game()
{
    //load_a_game();
    update_game();
    save_file();
    game_data tmp;
    p1=tmp;
    p2=tmp;
    dual_mode=0;
    p1.user_name[user_name_idx=0]=0;
    p2.user_name[user_name_idx=0]=0;
}



void save_file(void)
{
    FILE *fp;
    if((fp=fopen("g_data","w"))==NULL)
    {
        printf("error opening g data file");
        return ;
    }
    fwrite(&total_g_inf,sizeof(int ),1,fp);

    fwrite(g,sizeof(struct game ),6,fp);

    fclose(fp);

}

void update_game()
{
    for(int i=5;i>0;i--)
        g[i]=g[i-1];
    total_g_inf=min(5,total_g_inf+1);
    g[0].p1=p1;
    g[0].p2=p2;
    g[0].dual_mode=dual_mode;

}

void load_game_data()
{
    FILE *fp;
    fp=fopen("g_data","r");

    fread(&total_g_inf,sizeof(int ),1,fp);
    //printf("total game inf  %d\n",total_g_inf);

    fread(g,sizeof(struct game),6,fp);

    fclose(fp);
    return ;
}


void delate_game(int idx)
{
    struct game tmp;

    for(int i=idx;i<4;i++) g[i]=g[i+1];

    g[4]=tmp;

    total_g_inf--;
    total_g_inf=max(0,total_g_inf);
    save_file();
}

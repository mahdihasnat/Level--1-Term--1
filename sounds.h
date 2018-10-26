
int sound=1;






void start_music()
{
    PlaySound("music.wav",NULL,SND_ASYNC);
    sound=1;
}

void stop_music()
{
    PlaySound(NULL,NULL,SND_ASYNC);
    sound=0;
}

void sync_music()
{
    if(sound)
        PlaySound("music.wav",NULL,SND_ASYNC);
}


double align_string(double left,double dx,char *p)
{
    int up=0,down=0;
    while(*p){
        if(*p>64&&*p<91) up++;
        else down++;
        p++;
    }
    double sp=up*16+down*12;
    if(sp>dx) return left;
      return  left+(dx-sp)/2;
}

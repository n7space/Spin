typedef m {float x;}
chan q = [5] of {m};
chan synchro = [1] of {bit}
active proctype sender()
{

    q!3.14;
    float x = 2.7;
    q!x;
    synchro!1;
}

active proctype receiver()
{
    m a;
    //q?a;
    //printf("a = %f\n", a.x);
    synchro?1;
    for (a in q)
    {
        printf("%f\n",a.x);
        
    }
}
typedef m {float x;}
chan q = [5] of {m};

active proctype sender()
{

    q!3.14;
    float x = 2.7;
    q!x;

}

active proctype receiver()
{
    m a;
    //q?a;
    //printf("a = %f\n", a.x);
    for (a in q)
    {
        printf("%f\n",a.x);
    }
}
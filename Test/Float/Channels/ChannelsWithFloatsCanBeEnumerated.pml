/* elements in channels must be structure to allow channel enumeration */
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
    /* wait on synchro channel for filled q channel */
    synchro?1;
    
    for (a in q)
    {
        printf("%f\n",a.x);
    }
}
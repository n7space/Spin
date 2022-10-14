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
    
    float correct_answers[2];
    correct_answers[0]=3.14;
    correct_answers[1]=2.7;
    byte count =0;
    for (a in q)
    {
        printf("%f\n",a.x);
        assert(a.x == correct_answers[count]);
        count++;
    }
}
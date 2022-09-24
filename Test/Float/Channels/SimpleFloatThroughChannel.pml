chan q = [5] of {float};

active proctype sender()
{
    /* float literals can be sent explicitly */
    q!3.14;
    /* floats can be sent as variable */
    float x = 2.7;
    q!x;
}

active proctype receiver()
{
    float a;
    q?a;
    printf("first value = %f\n", a);
    q?a;
    printf("second value = %f\n", a);
}   
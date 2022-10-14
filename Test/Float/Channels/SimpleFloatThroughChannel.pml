float epsilon = 0.001;
#define isFloatEqual(a, b) ((a-b)<epsilon && (a-b)>-epsilon)

chan q = [5] of {float};

active proctype sender()
{
    
    /* int literals can be sent explicitly */
    q!2.7;
    /* ints can be sent as variable */
    float x = 3.14;
    q!x;
}


active proctype receiver()
{
    float a;
    float b;
    
    q?a;
    q?b;

    printf("first value = %f\n", a);
    
    printf("second value = %f\n", b);
    assert( isFloatEqual(a, 2.7) );
    assert( isFloatEqual(b, 3.14) );
}   
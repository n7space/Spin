active proctype test() {
    float epsilon = 0.00001;
    float x = 123;
    printf("x = %f\n", x);
    assert(x == 123.0);

    float y = 43.;
    printf("y = %f\n", y);
    assert(y == 43.0);

    float z = 56.1;
    printf("z = %f\n", z);
    assert(z - 56.1 < epsilon);

    x = 56.13;
    printf("x = %f\n", x);
    assert(x - 5613.0 / 100.0 <= epsilon);

    x = 5.2e+1;
    printf("x = %f\n", x);
    assert(x - 52.0 < epsilon);
    
    x = 5.3e+10;
    printf("x = %f\n", x);
    assert(x - 5.3e+5 * 1e+5 < epsilon);

    x = 520e-1;
    printf("x = %f\n", x);
    assert(x - 52.0 < epsilon);

    float a=3.0e+1 / 10;
    float b=12.0;
    float c;
    c = a + b - 0.01;
    printf("c variable has value of %f\n", c);
    assert(c < 15.0);
    assert(c >= 14.9899);
    assert(c <= 14.991);
    assert(c >= 14.98);
    assert(c <= 15.0-0.01);
    assert(c <= 14.99);
    printf("a variable has value of %f\n", a);
    printf("b variable has value of %f\n", b);
//    assert(radd == 28.0);
//    assert(rsub == -4.0);
//    assert(rmul == 192);
//    assert(rdiv > rdiv_lower);
//    assert(rdiv < rdiv_upper);
 //   printf("Float arithmetic: %f and %f == (+)%f (-)%f (*)%f (/)%f\n",
 //       a, b, radd, rsub, rmul, rdiv);
}

active proctype test() {
    float epsilon = 0.00001;
    float x = 123;
    printf("123 as float = %f\n", x);
    assert(x == 123.0);

    float y = 43.;
    printf("43. = %f\n", y);
    assert(y == 43.0);

    float z = 56.1;
    printf("56.1 = %f\n", z);
    assert(z - 56.1 < epsilon);

    x = 56.13;
    printf("56.13 = %f\n", x);
    assert(x - 5613.0 / 100.0 <= epsilon);

    x = 5.2e+1;
    printf("5.2e+1 = %f\n", x);
    assert(x - 52.0 < epsilon);
    
    x = 5.3e+10;
    printf("5.3e+10 = %f\n", x);
    assert(x - 5.3e+5 * 1e+5 < epsilon);

    x = 520e-1;
    printf("520e-1 = %f\n", x);
    assert(x - 52.0 < epsilon);

    float a=3.0e+1 / 10;
    float b=12.0;
    float c;
    c = a + b - 0.01;
    printf("3.0e+1/10 + 12.0 - 0.01 = %f\n", c);
    assert(c < 15.0);
    assert(c >= 14.9899);
    assert(c <= 14.991);
    assert(c >= 14.98);
    assert(c <= 15.0-0.01);
    assert(c <= 14.99);
    printf("3.0e+1 / 10 = %f\n", a);
}

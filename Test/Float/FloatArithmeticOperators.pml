active proctype test() {
    float a = 14.25;
    float b = -a;
    int c = 14;
    // float var is properly compared with int
    assert(c != a);
    assert(14.0 != 0);
    assert(a < 15);
    assert(a > c);
    assert(a >= c);
    assert(a <= 15)

    // float var is properly compared to float
    assert(a != b);
    assert(b == b);
    assert(a < 14.3);
    assert(a > 14.2);
    assert(a >= a);
    assert(a <= a);

    // float can be negated
    assert(b == -14.25);
    // int can be negated
    assert(-c == -14);
    // float can be added to another float
    assert(a+0.25 == 14.5);
    // float can be substracted from another float
    assert(a-0.25 == 14.0);
    // float can be multiplied by int
    assert(a*2 == 28.5);
    // float can be multiplied by float
    assert(a*2.0 == 28.5);
    // float can be devided by int
    assert(45.0 / 2 == 22.5);
        // float can be devided by float
    assert(45.0 / 2.0 == 22.5);

    // int can be devided by int giving float
    assert(45 / 2 == 22);
    // int can be devided by float giving float
    assert(45 / 2.0 == 22.5);

    printf("Negated %f == %f\n",
        a, b);
}

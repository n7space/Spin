active proctype test() {
    float a;
    float b;
    float radd;
    float rsub;
    float rdiv;
    float rmul;
    float rdiv_upper;
    float rdiv_lower;
    rdiv_lower = 0.74;
    rdiv_upper = 0.76;
    a = 12.0;
    b = 16.0;
    radd = a + b;
    rsub = a - b;
    rmul = a * b;
    rdiv = a / b;
    assert(radd == 28.0);
    assert(rsub == -4.0);
    assert(rmul == 192.0);
    assert(rdiv > rdiv_lower);
    assert(rdiv < rdiv_upper);
    printf("Float arithmetic: %f and %f == (+)%f (-)%f (*)%f (/)%f\n",
        a, b, radd, rsub, rmul, rdiv);
}

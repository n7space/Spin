active proctype test() {
    float a=3.0;
    float b=12.0;
    float c;
    c = a + b - 0.01;
    printf("c variable has value of %f\n", c);
    assert(c < 15.0);
    assert(c == 14.9899999);
    assert(c>=14.98);
    assert(c==15.0-0.01);
    assert(c==14.99);
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

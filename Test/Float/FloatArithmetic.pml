active proctype test() {
    float a;
    float b;
    float radd;
    float rsub;
    float rdiv;
    float rmul;
    a = 12;
    b = 16;
    radd = a + b;
    rsub = a - b;
    rmul = a * b;
    rdiv = a / b;
    printf("Float arithmetic: %f and %f == (+)%f (-)%f (*)%f (/)%f\n",
        a, b, radd, rsub, rmul, rdiv);
}
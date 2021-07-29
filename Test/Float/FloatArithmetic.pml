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
    printf("Float arithmetic: %.2f and %.2f == (+)%.2f (-)%.2f (*)%.2f (/)%.2f",
        radd, rsub, rmul, rdiv);
}
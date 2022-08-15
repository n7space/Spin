// This is needed because dot notation is not yet supported by the lexer
hidden float tmpN;
hidden float tmpD;

inline makeFloat(f, nominator, denominator) {
    tmpN = nominator;
    tmpD = denominator;
    f = tmpN / tmpD;
}

active proctype test() {
    float a = 14.25;
    float b = -a;
    assert(b == -14.25);
    printf("Float arithmetic operators:\n a == %f, b == %f\n",
        a, b);
}

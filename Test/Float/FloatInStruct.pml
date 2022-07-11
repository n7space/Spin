typedef Data {
    int counter;
    float value;
}

// This is needed because dot notation is not yet supported by the lexer
hidden float tmpN;
hidden float tmpD;

inline makeFloat(f, nominator, denominator) {
    tmpN = nominator;
    tmpD = denominator;
    f = tmpN / tmpD;
}

active proctype test() {
    Data d;
    int i;
    float f;
    d.counter = 0;
    d.value = 0;
    makeFloat(f, 1, 10);
    for (i : 1..101 ) {
        d.counter = d.counter + 1;
        d.value = d.value + f;
    }
    assert(d.counter == 101);    
    assert(d.value < 11);
    assert(d.value > 10);
    printf("Data is %d and %f\n", d.counter, d.value);
}

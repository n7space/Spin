#define STORE_SIZE 10

// This is needed because dot notation is not yet supported by the lexer
hidden float tmpN;
hidden float tmpD;

inline makeFloat(f, nominator, denominator) {
    tmpN = nominator;
    tmpD = denominator;
    f = tmpN / tmpD;
}

typedef Message {
    int index;
    float value;
}

typedef Data {
    float values[STORE_SIZE];
}

Data data;
chan queue = [0] of {Message};

inline random10(x) {
    if
    ::x = 0;
    ::x = 1;
    ::x = 2;
    ::x = 3;
    ::x = 4;
    ::x = 5;
    ::x = 6;
    ::x = 7;
    ::x = 8;
    ::x = 9;
    fi
}

inline randomFloat(x) {
    if    
    ::makeFloat(x, 1, 10);
    ::makeFloat(x, 2, 10);
    ::makeFloat(x, 3, 10);
    ::makeFloat(x, 4, 10);
    ::makeFloat(x, 5, 10);
    ::makeFloat(x, 6, 10);
    ::makeFloat(x, 7, 10);
    ::makeFloat(x, 8, 10);
    ::makeFloat(x, 9, 10);    
    fi
}

active proctype receiver() {
    Message msg;
    do
    ::  queue?msg;
        data.values[msg.index] = msg.value;
    od
}

active proctype sender() {
    Message msg;
    do
    ::  random10(msg.index);
        randomFloat(msg.value);
        queue!msg;
    od
}

#define p(i) ((data.values[i] > 0) && (data.values[i] < 1))

// Value will eventually be set to something larger than 0 and smaller than 1
ltl stop0 {[]<> p(0)}

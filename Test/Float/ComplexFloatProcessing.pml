#define STORE_SIZE 10

typedef Message {
    int index;
    float value;
}

typedef Data {
    float values[STORE_SIZE];
}

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
    ::x = 0.1;
    ::x = 0.2;
    ::x = 0.3;
    ::x = 0.4;
    ::x = 0.5;
    ::x = 0.6;
    ::x = 0.7;
    ::x = 0.8;
    ::x = 0.9;    
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

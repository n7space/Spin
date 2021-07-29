typedef union MyUnion {
    int a;
    int b;
}

chan queue = [0] of {MyUnion};

active proctype sender() {
    MyUnion data;
    data.a = 1969;
    queue!data;
    data.b = 1337;
    queue!data;
}

active proctype receiver() {
    MyUnion data;
    queue?data;
    assert(data.a == 1969);
    printf("Data is %d\n", data.a);
    queue?data;
    assert(data.b == 1337);
    printf("Data is %d\n", data.b);
}

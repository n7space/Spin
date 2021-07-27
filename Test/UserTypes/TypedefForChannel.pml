typedef MyStruct {
    int a;
    int b;    
}

chan queue = [0] of {MyStruct};

active proctype sender() {
    MyStruct data;
    data.a = 1969;
    data.b = 1337;
    queue!data;
    data.a = 10;
    data.b = 50;
    queue!data;
}

active proctype receiver() {
    MyStruct data;
    queue?data;
    assert(data.a == 1969);
    assert(data.b == 1337);
    printf("Data is %d and %d\n", data.a, data.b);
    queue?data;
    assert(data.a == 10);
    assert(data.b == 50);    
    printf("Data is %d and %d\n", data.a, data.b);
}

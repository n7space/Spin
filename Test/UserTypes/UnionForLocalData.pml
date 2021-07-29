typedef union MyUnion {
    int a;
    int b;
}

active proctype test() {
    MyUnion data;
    data.a = 12;
    assert(data.a == 12);
    printf("Data is %d\n", data.a);
    data.b = 17;    
    assert(data.b == 17);
    printf("Data is %d\n", data.b);
}
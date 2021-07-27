typedef MyStruct {
    int a;
    int b;    
}

active proctype test() {
    MyStruct data;
    data.a = 12;
    data.b = 17;
    assert(data.a == 12);
    assert(data.b == 17);
    printf("data is %d and %d\n", data.a, data.b);
}
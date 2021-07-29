typedef MyStruct {
    int a;
    int b;    
}

MyStruct g_Data;

active proctype test() {
    g_Data.a = 12;
    g_Data.b = 17;
    assert(g_Data.a == 12);
    assert(g_Data.b == 17);
    printf("Data is %d and %d\n", g_Data.a, g_Data.b);
}
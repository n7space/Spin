typedef union MyUnion {
    int a;
    int b;
}

MyUnion g_Data;

active proctype test() {    
    g_Data.a = 12;
    assert(g_Data.a == 12);
    printf("Data is %d\n", g_Data.a);
    g_Data.b = 17;    
    assert(g_Data.b == 17);
    printf("Data is %d\n", g_Data.b);
}
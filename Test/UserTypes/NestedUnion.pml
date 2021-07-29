typedef union Child {
    int a;
    int b;
}

typedef union Parent {
    Child c1;
    Child c2;
}

Parent g_Data;

active proctype test() {
    g_Data.c1.a = 100;
    assert(g_Data.c1.a == 100);
    printf("Data c1 a is %d\n", g_Data.c1.a);
    g_Data.c1.b = 200;
    assert(g_Data.c1.b == 200);
    printf("Data c1 b is %d\n", g_Data.c1.b);
    g_Data.c2.a = 10;
    assert(g_Data.c2.a == 10);
    printf("Data c2 a is %d\n", g_Data.c2.a);
    g_Data.c2.b = 20;
    assert(g_Data.c2.b == 20);
    printf("Data c2 b is %d\n", g_Data.c2.b);
}
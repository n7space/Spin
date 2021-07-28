typedef Child {
    int a;
    int b;
}

typedef Parent {
    Child c1;
    Child c2;
}

Parent g_Data;

active proctype test() {
    g_Data.c1.a = 100;
    g_Data.c1.b = 200;

    g_Data.c2.a = 10;
    g_Data.c2.b = 20;

    assert(g_Data.c1.a == 100);
    assert(g_Data.c1.b == 200);
    assert(g_Data.c2.a == 10);
    assert(g_Data.c2.b == 20);
    printf("Data c1 is %d and %d\nData c2 is %d and %d\n",
        g_Data.c1.a,g_Data.c1.b,g_Data.c2.a,g_Data.c2.b);
}
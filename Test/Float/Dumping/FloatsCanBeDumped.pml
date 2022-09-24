float float_var;
byte byte_var;
int int_var;
float float_array[2];

typedef three_floats
{   
    float inner_float_array[3];
}

typedef inner_float_struct
{
    int inner_int;
    three_floats floats;
}

typedef item
{
    bit bit_field;
    byte byte_field;
    int int_field;
    float float_field;
    inner_float_struct inner_float_struct_array[2];
}

item item_array[2];

chan struct_channel = [2] of {inner_float_struct};

inline fill_struct(i, seed){
    if
    :: seed == 0 -> i.bit_field = 0;
    :: else -> i.bit_field = 1;
    fi
    i.byte_field = 9 + seed;
    i.int_field = 3432 + seed;
    i.float_field = 5.56 + seed;
    i.inner_float_struct_array[0].inner_int = 21 + seed;
    i.inner_float_struct_array[0].floats.inner_float_array[0] = 0.25 + seed;
    i.inner_float_struct_array[0].floats.inner_float_array[1] = 1.5 + seed;
    i.inner_float_struct_array[0].floats.inner_float_array[2] = 1.75 + seed;
    i.inner_float_struct_array[1].inner_int = 21 + seed + 1;
    i.inner_float_struct_array[1].floats.inner_float_array[0] = 0.25 + seed + 1;
    i.inner_float_struct_array[1].floats.inner_float_array[1] = 1.5 + seed + 1;
    i.inner_float_struct_array[1].floats.inner_float_array[2] = 1.75 + seed + 1;
}

chan copying_channel = [1] of {three_floats};


inline copy_inner_float_struct( origin, destination )
{
    destination.inner_int = origin.inner_int;

    copying_channel!origin.floats;
    copying_channel?destination.floats;
}

active proctype test_dump(){
    float_var = 4.83;
    byte_var = 6;
    int_var = 234565;
    
    float_array[0] = 3.14;
    float_array[1] = 2.7;

    fill_struct(item_array[0], 0);
    fill_struct(item_array[1], 3);
    
    inner_float_struct msg;
    
    copy_inner_float_struct(item_array[0].inner_float_struct_array[1], msg);
    struct_channel!msg;
    
    copy_inner_float_struct(item_array[1].inner_float_struct_array[0], msg);
    struct_channel!msg;

    /* next sending blocks proctype and triggers dumping */
    struct_channel!msg;
}
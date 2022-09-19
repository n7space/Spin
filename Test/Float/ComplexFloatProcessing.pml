#define STORE_SIZE 10


typedef Message {
    int index;
    float value;
}

typedef Data {
    float values[STORE_SIZE];
    int intValue;
    float floatValue;
    byte byteValue;
}

Data data;
chan queue = [1] of {Message};

inline printData()
{
    printf("data[0]=%f\n", data.values[0]);
    printf("data[1]=%f\n", data.values[1]);
    printf("data[2]=%f\n", data.values[2]);
    printf("data[3]=%f\n", data.values[3]);
    printf("data[4]=%f\n", data.values[4]);
    printf("data[5]=%f\n", data.values[5]);
    printf("data[6]=%f\n", data.values[6]);
    printf("data[7]=%f\n", data.values[7]);
    printf("data[8]=%f\n", data.values[8]);
    printf("data[9]=%f\n", data.values[9]);
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

float finalValue=0.25;
int finalIndex = STORE_SIZE + 1;

active proctype receiver() {
    Message msg;
    
    do
    ::queue?msg;
        printf("Receiver: index=%d, value=%f\n", msg.index, msg.value);
        if
        ::msg.index == finalIndex && msg.value == finalValue -> 
            printf("Final message received!\n");
            break;
        ::msg.index < STORE_SIZE -> data.values[msg.index] = msg.value;
        ::else -> 
            printf("Erronous index = %d\n", msg.index);
            break;
        fi
        
    od
}

active proctype sender() {
    Message msg;
    byte count;
    do
    ::count < 10 ->
        
        //random10(msg.index);
        //randomFloat(msg.value);
        msg.index = count;
        msg.value = count/10.0 + 0.1;
        if
        :: msg.value == 1.0 -> msg.value = 0.75;
        :: else -> skip;
        fi
        printf("Sender messsage: index=%d, value=%f\n", msg.index, msg.value);
        queue!msg;
        count++;
    ::else -> break;
    od

    msg.index = finalIndex;
    msg.value = finalValue;
    queue!msg;
    queue!msg;
    queue!msg;
    printData();
}

#define p(i) ((data.values[i] >= 0.0) && (data.values[i] < 1.0))

// Value will eventually be set to something larger than 0 and smaller than 1
ltl stop0 {[]<> p(0)}

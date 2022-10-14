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

Data data[3];
chan queue = [2] of {Message};
chan dqueue = [3] of {Data};


float finalValue=0.25;
int finalIndex = STORE_SIZE + 1;

proctype receiver() {
    Message msg;
    
    do
    ::queue?msg;
        printf("Receiver: index=%d, value=%f\n", msg.index, msg.value);
        if
        ::(msg.index == finalIndex && msg.value == finalValue) -> 
            printf("Final message received!\n");
            break;
        ::else -> 
            if 
            ::msg.index < STORE_SIZE -> 
                data[0].values[msg.index] = msg.value; 
                data[0].byteValue = data[0].byteValue + msg.value * 10;
                data[1].floatValue = data[1].floatValue  + msg.value; 
                data[2].intValue = data[2].intValue + msg.index;
            ::else ->
                printf("Erronous index = %d\n", msg.index);
                break;
            fi
        fi
        
    od
    dqueue!data[0];
    dqueue!data[1];
    dqueue!data[2];
}

proctype sender() {
    Message msg;
    byte count;
    do
    ::count < 10 ->
        msg.index = count;
        msg.value = count/10.0 + 0.1;
        if
        :: msg.value == 1.0 -> msg.value = 0.75;
        :: else -> skip;
        fi
        printf("Sender messsage: index=%d, value=%f\n", msg.index, msg.value);
        queue!msg;
        count++;
    ::else -> 
        msg.index = finalIndex;
        msg.value = finalValue;
        queue!msg;
        break;
    od

    /* fill-up the queue */
    queue!msg;
    msg.value = 0.3;
    queue!msg;
    /* sending this will trigger global vars dumping */
    msg.value = 0.4;
    queue!msg;
}

#define p(i) ((data[0].values[i] >= 0.0) && (data[0].values[i] < 1.0))

init{

    ltl stop0 {[] p(0)}
    run receiver();
    run sender();

}
// Value will eventually be set to something larger than 0 and smaller than 1


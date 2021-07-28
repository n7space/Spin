mtype = {WRITE_CMD, READ_CMD, READ_NOTIF}
mtype = {STATUS_OK, STATUS_FAILED}

typedef WriteDataCommand {
    byte register;
    short data;
}

typedef ReadDataCommand {
    byte register;
}

typedef DataReadNotification {
    byte register;
    short data;
    mtype status;
}

typedef MessagePayload {
    WriteDataCommand writeCmd;
    ReadDataCommand readCmd;
    DataReadNotification readNotif;
}

typedef Message {
    mtype kind;
    MessagePayload payload;
}

chan uplink = [0] of {Message};
chan downlink = [0] of {Message};
short registers[255];

active proctype rtu() {
    Message msgIn;
    Message msgOut;
    do
    ::uplink?msgIn;
        if
        :: (msgIn.kind == WRITE_CMD) ->
            registers[msgIn.payload.writeCmd.register] = msgIn.payload.writeCmd.data;
        :: (msgIn.kind == READ_CMD) ->
            msgOut.kind = READ_NOTIF;
            msgOut.payload.readNotif.register = msgIn.payload.readCmd.register;
            // Artificial failure - we can only read from registers 0-3
            if 
            ::(msgIn.payload.readCmd.register > 3) ->
                msgOut.payload.readNotif.status = STATUS_FAILED;
                msgOut.payload.readNotif.data = 0;
            ::(msgIn.payload.readCmd.register <= 3) ->                
                msgOut.payload.readNotif.status = STATUS_OK;
                msgOut.payload.readNotif.data = registers[msgIn.payload.readCmd.register];
            fi
            downlink!msgOut;
        :: (msgIn.kind == READ_NOTIF) -> assert(false);
        fi
    od
}

inline random4(value) {
    if
    ::value = 1;
    ::value = 2;
    ::value = 3;
    ::value = 4;
    fi
}

// This is not important for the checking itself, however it introduces more realistic
// complexity and data exchanges
inline random100(value) {
    if
    ::value = 10;
    ::value = 20;
    ::value = 30;
    ::value = 40;
    ::value = 50;
    ::value = 60;
    ::value = 70;
    ::value = 80;
    ::value = 90;
    ::value = 100;
    fi
}

active proctype cnc() {
    Message msgIn;
    Message msgOut;
    do
    ::downlink?msgIn ->
        assert(msgIn.kind == READ_NOTIF);
        assert(msgIn.payload.readNotif.status == STATUS_OK);
    ::msgOut.kind = WRITE_CMD;
        random4(msgOut.payload.writeCmd.register);
        random100(msgOut.payload.writeCmd.data);
        uplink!msgOut;
    ::msgOut.kind = READ_CMD;
        random4(msgOut.payload.readCmd.register);        
        uplink!msgOut;
    od
}
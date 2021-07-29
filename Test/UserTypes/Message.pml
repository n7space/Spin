mtype = {WRITE_CMD, READ_CMD, READ_NOTIF}
mtype = {STATUS_OK, STATUS_FAILED}

typedef WriteDataCommand {
    byte reg;
    short data;
}

typedef ReadDataCommand {
    byte reg;
}

typedef DataReadNotification {
    byte reg;
    short data;
    mtype status;
}

typedef union MessagePayload {
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
short regs[255];

active proctype rtu() {
    Message msgIn;
    Message msgOut;
    end: do
    ::uplink?msgIn;
        if
        :: (msgIn.kind == WRITE_CMD) ->
            regs[msgIn.payload.writeCmd.reg] = msgIn.payload.writeCmd.data;
        :: (msgIn.kind == READ_CMD) ->
            msgOut.kind = READ_NOTIF;
            msgOut.payload.readNotif.reg = msgIn.payload.readCmd.reg;
            // Artificial failure - we can only read from registers 0-3
            if 
            ::(msgIn.payload.readCmd.reg > 3) ->
                msgOut.payload.readNotif.status = STATUS_FAILED;
                msgOut.payload.readNotif.data = 0;
            ::(msgIn.payload.readCmd.reg <= 3) ->                
                msgOut.payload.readNotif.status = STATUS_OK;
                msgOut.payload.readNotif.data = regs[msgIn.payload.readCmd.reg];
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
    end: do
    ::downlink?msgIn ->
        assert(msgIn.kind == READ_NOTIF);
        assert(msgIn.payload.readNotif.status == STATUS_OK);
    ::msgOut.kind = WRITE_CMD;
        random4(msgOut.payload.writeCmd.reg);
        random100(msgOut.payload.writeCmd.data);
        uplink!msgOut;
    ::msgOut.kind = READ_CMD;
        random4(msgOut.payload.readCmd.reg);        
        uplink!msgOut;
    od
}
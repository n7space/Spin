#include "dataview.pml"
#include "actuator.pml"
#include "controller.pml"
#include "env_inlines.pml"
typedef system_state {
    Actuator_Context actuator;
    Controller_Context controller;
    AggregateTimerData timers;
}

int inited;
chan Actuator_test_less_channel = [1] of {MyPacket};
MyPacket Actuator_test_less_signal_parameter;
bool Actuator_test_less_channel_used = 0;
chan Actuator_test_greater_channel = [1] of {MyPacket};
MyPacket Actuator_test_greater_signal_parameter;
bool Actuator_test_greater_channel_used = 0;
chan Actuator_test_less_equal_channel = [1] of {MyPacket};
MyPacket Actuator_test_less_equal_signal_parameter;
bool Actuator_test_less_equal_channel_used = 0;
chan Actuator_test_greater_equal_channel = [1] of {MyPacket};
MyPacket Actuator_test_greater_equal_signal_parameter;
bool Actuator_test_greater_equal_channel_used = 0;
chan Controller_result_channel = [1] of {MyFlag};
MyFlag Controller_result_signal_parameter;
bool Controller_result_channel_used = 0;
system_state global_state;
chan Controller_lock = [1] of {int};
chan Actuator_lock = [1] of {int};
inline Controller_0_RI_0_test_less(actuator_test_less_p1)
{
    Actuator_test_less_channel!actuator_test_less_p1;
}
inline Controller_0_RI_0_test_greater(actuator_test_greater_p1)
{
    Actuator_test_greater_channel!actuator_test_greater_p1;
}
inline Controller_0_RI_0_test_less_equal(actuator_test_less_equal_p1)
{
    Actuator_test_less_equal_channel!actuator_test_less_equal_p1;
}
inline Controller_0_RI_0_test_greater_equal(actuator_test_greater_equal_p1)
{
    Actuator_test_greater_equal_channel!actuator_test_greater_equal_p1;
}
inline Actuator_check_queue()
{
    atomic {
        (empty(Actuator_test_less_channel) && (empty(Actuator_test_greater_channel) && (empty(Actuator_test_less_equal_channel) && empty(Actuator_test_greater_equal_channel))));
    }
}
inline Actuator_0_RI_0_result(controller_result_p1)
{
    Controller_result_channel!controller_result_p1;
}
inline Controller_check_queue()
{
    atomic {
        empty(Controller_result_channel);
    }
}
active proctype Actuator_test_less() priority 1
{
    inited;
    do
    ::  atomic {
        nempty(Actuator_test_less_channel);
        Actuator_lock?_;
Actuator_test_less_loop:
        if
        ::  nempty(Actuator_test_less_channel);
            Actuator_test_less_channel?Actuator_test_less_signal_parameter;
            Actuator_test_less_channel_used = 1;
            Actuator_0_PI_0_test_less(Actuator_test_less_signal_parameter);
            goto Actuator_test_less_loop;
        ::  empty(Actuator_test_less_channel);
            skip;
        fi;
        Actuator_lock!1;
    }
    od;
}
active proctype Actuator_test_greater() priority 1
{
    inited;
    do
    ::  atomic {
        nempty(Actuator_test_greater_channel);
        Actuator_lock?_;
Actuator_test_greater_loop:
        if
        ::  nempty(Actuator_test_greater_channel);
            Actuator_test_greater_channel?Actuator_test_greater_signal_parameter;
            Actuator_test_greater_channel_used = 1;
            Actuator_0_PI_0_test_greater(Actuator_test_greater_signal_parameter);
            goto Actuator_test_greater_loop;
        ::  empty(Actuator_test_greater_channel);
            skip;
        fi;
        Actuator_lock!1;
    }
    od;
}
active proctype Actuator_test_less_equal() priority 1
{
    inited;
    do
    ::  atomic {
        nempty(Actuator_test_less_equal_channel);
        Actuator_lock?_;
Actuator_test_less_equal_loop:
        if
        ::  nempty(Actuator_test_less_equal_channel);
            Actuator_test_less_equal_channel?Actuator_test_less_equal_signal_parameter;
            Actuator_test_less_equal_channel_used = 1;
            Actuator_0_PI_0_test_less_equal(Actuator_test_less_equal_signal_parameter);
            goto Actuator_test_less_equal_loop;
        ::  empty(Actuator_test_less_equal_channel);
            skip;
        fi;
        Actuator_lock!1;
    }
    od;
}
active proctype Actuator_test_greater_equal() priority 1
{
    inited;
    do
    ::  atomic {
        nempty(Actuator_test_greater_equal_channel);
        Actuator_lock?_;
Actuator_test_greater_equal_loop:
        if
        ::  nempty(Actuator_test_greater_equal_channel);
            Actuator_test_greater_equal_channel?Actuator_test_greater_equal_signal_parameter;
            Actuator_test_greater_equal_channel_used = 1;
            Actuator_0_PI_0_test_greater_equal(Actuator_test_greater_equal_signal_parameter);
            goto Actuator_test_greater_equal_loop;
        ::  empty(Actuator_test_greater_equal_channel);
            skip;
        fi;
        Actuator_lock!1;
    }
    od;
}
active proctype Controller_result() priority 1
{
    inited;
    do
    ::  atomic {
        nempty(Controller_result_channel);
        Controller_lock?_;
Controller_result_loop:
        if
        ::  nempty(Controller_result_channel);
            Controller_result_channel?Controller_result_signal_parameter;
            Controller_result_channel_used = 1;
            Controller_0_PI_0_result(Controller_result_signal_parameter);
            goto Controller_result_loop;
        ::  empty(Controller_result_channel);
            skip;
        fi;
        Controller_lock!1;
    }
    od;
}
init
{
    atomic {
        global_dataview_init();
        Controller_0_init();
        Controller_lock!1;
        Actuator_0_init();
        Actuator_lock!1;
        inited = 1;
    }
}
#include "scl.pml"

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
chan Actuator_test_add_channel = [1] of {MyPacket};
MyPacket Actuator_test_add_signal_parameter;
bool Actuator_test_add_channel_used = 0;
chan Actuator_test_sub_channel = [1] of {MyPacket};
MyPacket Actuator_test_sub_signal_parameter;
bool Actuator_test_sub_channel_used = 0;
chan Actuator_test_div_channel = [1] of {MyPacket};
MyPacket Actuator_test_div_signal_parameter;
bool Actuator_test_div_channel_used = 0;
chan Actuator_test_mul_channel = [1] of {MyPacket};
MyPacket Actuator_test_mul_signal_parameter;
bool Actuator_test_mul_channel_used = 0;
chan Controller_result_channel = [1] of {MyReal};
MyReal Controller_result_signal_parameter;
bool Controller_result_channel_used = 0;
system_state global_state;
chan Controller_lock = [1] of {int};
chan Actuator_lock = [1] of {int};
inline Controller_0_RI_0_test_add(actuator_test_add_p1)
{
    Actuator_test_add_channel!actuator_test_add_p1;
}
inline Controller_0_RI_0_test_sub(actuator_test_sub_p1)
{
    Actuator_test_sub_channel!actuator_test_sub_p1;
}
inline Controller_0_RI_0_test_div(actuator_test_div_p1)
{
    Actuator_test_div_channel!actuator_test_div_p1;
}
inline Controller_0_RI_0_test_mul(actuator_test_mul_p1)
{
    Actuator_test_mul_channel!actuator_test_mul_p1;
}
inline Actuator_check_queue()
{
    atomic {
        (empty(Actuator_test_add_channel) && (empty(Actuator_test_sub_channel) && (empty(Actuator_test_div_channel) && empty(Actuator_test_mul_channel))));
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
active proctype Actuator_test_add() priority 1
{
    inited;
    do
    ::  atomic {
        nempty(Actuator_test_add_channel);
        Actuator_lock?_;
Actuator_test_add_loop:
        if
        ::  nempty(Actuator_test_add_channel);
            Actuator_test_add_channel?Actuator_test_add_signal_parameter;
            Actuator_test_add_channel_used = 1;
            Actuator_0_PI_0_test_add(Actuator_test_add_signal_parameter);
            goto Actuator_test_add_loop;
        ::  empty(Actuator_test_add_channel);
            skip;
        fi;
        Actuator_lock!1;
    }
    od;
}
active proctype Actuator_test_sub() priority 1
{
    inited;
    do
    ::  atomic {
        nempty(Actuator_test_sub_channel);
        Actuator_lock?_;
Actuator_test_sub_loop:
        if
        ::  nempty(Actuator_test_sub_channel);
            Actuator_test_sub_channel?Actuator_test_sub_signal_parameter;
            Actuator_test_sub_channel_used = 1;
            Actuator_0_PI_0_test_sub(Actuator_test_sub_signal_parameter);
            goto Actuator_test_sub_loop;
        ::  empty(Actuator_test_sub_channel);
            skip;
        fi;
        Actuator_lock!1;
    }
    od;
}
active proctype Actuator_test_div() priority 1
{
    inited;
    do
    ::  atomic {
        nempty(Actuator_test_div_channel);
        Actuator_lock?_;
Actuator_test_div_loop:
        if
        ::  nempty(Actuator_test_div_channel);
            Actuator_test_div_channel?Actuator_test_div_signal_parameter;
            Actuator_test_div_channel_used = 1;
            Actuator_0_PI_0_test_div(Actuator_test_div_signal_parameter);
            goto Actuator_test_div_loop;
        ::  empty(Actuator_test_div_channel);
            skip;
        fi;
        Actuator_lock!1;
    }
    od;
}
active proctype Actuator_test_mul() priority 1
{
    inited;
    do
    ::  atomic {
        nempty(Actuator_test_mul_channel);
        Actuator_lock?_;
Actuator_test_mul_loop:
        if
        ::  nempty(Actuator_test_mul_channel);
            Actuator_test_mul_channel?Actuator_test_mul_signal_parameter;
            Actuator_test_mul_channel_used = 1;
            Actuator_0_PI_0_test_mul(Actuator_test_mul_signal_parameter);
            goto Actuator_test_mul_loop;
        ::  empty(Actuator_test_mul_channel);
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

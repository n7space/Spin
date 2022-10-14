#include "dataview.pml"
#include "controller.pml"
#include "actuator.pml"
#include "env_inlines.pml"
typedef system_state {
    Controller_Context controller;
    Actuator_Context actuator;
    AggregateTimerData timers;
}

int inited;
chan Controller_result_channel = [1] of {MyReal};
MyReal Controller_result_signal_parameter;
bool Controller_result_channel_used = 0;
chan Actuator_test_simple_channel = [1] of {MyReal};
MyReal Actuator_test_simple_signal_parameter;
bool Actuator_test_simple_channel_used = 0;
chan Actuator_test_sequence_channel = [1] of {MySequence};
MySequence Actuator_test_sequence_signal_parameter;
bool Actuator_test_sequence_channel_used = 0;
chan Actuator_test_array_channel = [1] of {MyArray};
MyArray Actuator_test_array_signal_parameter;
bool Actuator_test_array_channel_used = 0;
system_state global_state;
chan Controller_lock = [1] of {int};
chan Actuator_lock = [1] of {int};
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
inline Controller_0_RI_0_test_simple(actuator_test_simple_p1)
{
    Actuator_test_simple_channel!actuator_test_simple_p1;
}
inline Controller_0_RI_0_test_sequence(actuator_test_sequence_p1)
{
    Actuator_test_sequence_channel!actuator_test_sequence_p1;
}
inline Controller_0_RI_0_test_array(actuator_test_array_p1)
{
    Actuator_test_array_channel!actuator_test_array_p1;
}
inline Actuator_check_queue()
{
    atomic {
        (empty(Actuator_test_simple_channel) && (empty(Actuator_test_sequence_channel) && empty(Actuator_test_array_channel)));
    }
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
active proctype Actuator_test_simple() priority 1
{
    inited;
    do
    ::  atomic {
        nempty(Actuator_test_simple_channel);
        Actuator_lock?_;
Actuator_test_simple_loop:
        if
        ::  nempty(Actuator_test_simple_channel);
            Actuator_test_simple_channel?Actuator_test_simple_signal_parameter;
            Actuator_test_simple_channel_used = 1;
            Actuator_0_PI_0_test_simple(Actuator_test_simple_signal_parameter);
            goto Actuator_test_simple_loop;
        ::  empty(Actuator_test_simple_channel);
            skip;
        fi;
        Actuator_lock!1;
    }
    od;
}
active proctype Actuator_test_sequence() priority 1
{
    inited;
    do
    ::  atomic {
        nempty(Actuator_test_sequence_channel);
        Actuator_lock?_;
Actuator_test_sequence_loop:
        if
        ::  nempty(Actuator_test_sequence_channel);
            Actuator_test_sequence_channel?Actuator_test_sequence_signal_parameter;
            Actuator_test_sequence_channel_used = 1;
            Actuator_0_PI_0_test_sequence(Actuator_test_sequence_signal_parameter);
            goto Actuator_test_sequence_loop;
        ::  empty(Actuator_test_sequence_channel);
            skip;
        fi;
        Actuator_lock!1;
    }
    od;
}
active proctype Actuator_test_array() priority 1
{
    inited;
    do
    ::  atomic {
        nempty(Actuator_test_array_channel);
        Actuator_lock?_;
Actuator_test_array_loop:
        if
        ::  nempty(Actuator_test_array_channel);
            Actuator_test_array_channel?Actuator_test_array_signal_parameter;
            Actuator_test_array_channel_used = 1;
            Actuator_0_PI_0_test_array(Actuator_test_array_signal_parameter);
            goto Actuator_test_array_loop;
        ::  empty(Actuator_test_array_channel);
            skip;
        fi;
        Actuator_lock!1;
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

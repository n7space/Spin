inline Actuator_0_transition(id)
{
  int transition_id;
  transition_id = id;
  do
  ::if
    ::(transition_id == -1)->
      break;
    ::(transition_id == 0)->
      transition_id = -1;
      global_state.actuator.state = Actuator_States_wait;
      goto continuous_signals;
    ::(transition_id == 1)->
      if
      ::((global_state.actuator.packet.lhs <= global_state.actuator.packet.rhs) == false)->
        MyFlag_assign_value(global_state.actuator.ret, false);
      ::((global_state.actuator.packet.lhs <= global_state.actuator.packet.rhs) == true)->
        MyFlag_assign_value(global_state.actuator.ret, true);
      fi;
      Actuator_0_RI_0_result(global_state.actuator.ret);
      transition_id = -1;
      global_state.actuator.state = Actuator_States_wait;
      goto continuous_signals;
    ::(transition_id == 2)->
      if
      ::((global_state.actuator.packet.lhs > global_state.actuator.packet.rhs) == false)->
        MyFlag_assign_value(global_state.actuator.ret, false);
      ::((global_state.actuator.packet.lhs > global_state.actuator.packet.rhs) == true)->
        MyFlag_assign_value(global_state.actuator.ret, true);
      fi;
      Actuator_0_RI_0_result(global_state.actuator.ret);
      transition_id = -1;
      global_state.actuator.state = Actuator_States_wait;
      goto continuous_signals;
    ::(transition_id == 3)->
      if
      ::((global_state.actuator.packet.lhs >= global_state.actuator.packet.rhs) == false)->
        MyFlag_assign_value(global_state.actuator.ret, false);
      ::((global_state.actuator.packet.lhs >= global_state.actuator.packet.rhs) == true)->
        MyFlag_assign_value(global_state.actuator.ret, true);
      fi;
      Actuator_0_RI_0_result(global_state.actuator.ret);
      transition_id = -1;
      global_state.actuator.state = Actuator_States_wait;
      goto continuous_signals;
    ::(transition_id == 4)->
      if
      ::((global_state.actuator.packet.lhs < global_state.actuator.packet.rhs) == false)->
        MyFlag_assign_value(global_state.actuator.ret, false);
      ::((global_state.actuator.packet.lhs < global_state.actuator.packet.rhs) == true)->
        MyFlag_assign_value(global_state.actuator.ret, true);
      fi;
      Actuator_0_RI_0_result(global_state.actuator.ret);
      transition_id = -1;
      global_state.actuator.state = Actuator_States_wait;
      goto continuous_signals;
    fi;
    continuous_signals: 
  od;
}
inline Actuator_0_init()
{
  Actuator_0_transition(0);
}
inline Actuator_0_PI_0_test_greater(input_param)
{
  if
  ::(global_state.actuator.state == Actuator_States_wait)->
    MyPacket_assign_value(global_state.actuator.packet, input_param);
    Actuator_0_transition(2);
  ::else->
    skip;
  fi;
}
inline Actuator_0_PI_0_test_greater_equal(input_param)
{
  if
  ::(global_state.actuator.state == Actuator_States_wait)->
    MyPacket_assign_value(global_state.actuator.packet, input_param);
    Actuator_0_transition(3);
  ::else->
    skip;
  fi;
}
inline Actuator_0_PI_0_test_less(input_param)
{
  if
  ::(global_state.actuator.state == Actuator_States_wait)->
    MyPacket_assign_value(global_state.actuator.packet, input_param);
    Actuator_0_transition(4);
  ::else->
    skip;
  fi;
}
inline Actuator_0_PI_0_test_less_equal(input_param)
{
  if
  ::(global_state.actuator.state == Actuator_States_wait)->
    MyPacket_assign_value(global_state.actuator.packet, input_param);
    Actuator_0_transition(1);
  ::else->
    skip;
  fi;
}

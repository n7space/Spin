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
      MyReal_assign_value(global_state.actuator.ret, (global_state.actuator.packet.lhs / global_state.actuator.packet.rhs));
      Actuator_0_RI_0_result(global_state.actuator.ret);
      transition_id = -1;
      global_state.actuator.state = Actuator_States_wait;
      goto continuous_signals;
    ::(transition_id == 2)->
      MyReal_assign_value(global_state.actuator.ret, (global_state.actuator.packet.lhs * global_state.actuator.packet.rhs));
      Actuator_0_RI_0_result(global_state.actuator.ret);
      transition_id = -1;
      global_state.actuator.state = Actuator_States_wait;
      goto continuous_signals;
    ::(transition_id == 3)->
      MyReal_assign_value(global_state.actuator.ret, (global_state.actuator.packet.lhs - global_state.actuator.packet.rhs));
      Actuator_0_RI_0_result(global_state.actuator.ret);
      transition_id = -1;
      global_state.actuator.state = Actuator_States_wait;
      goto continuous_signals;
    ::(transition_id == 4)->
      MyReal_assign_value(global_state.actuator.ret, (global_state.actuator.packet.lhs + global_state.actuator.packet.rhs));
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
inline Actuator_0_PI_0_test_add(input_param)
{
  if
  ::(global_state.actuator.state == Actuator_States_wait)->
    MyPacket_assign_value(global_state.actuator.packet, input_param);
    Actuator_0_transition(4);
  ::else->
    skip;
  fi;
}
inline Actuator_0_PI_0_test_div(input_param)
{
  if
  ::(global_state.actuator.state == Actuator_States_wait)->
    MyPacket_assign_value(global_state.actuator.packet, input_param);
    Actuator_0_transition(1);
  ::else->
    skip;
  fi;
}
inline Actuator_0_PI_0_test_mul(input_param)
{
  if
  ::(global_state.actuator.state == Actuator_States_wait)->
    MyPacket_assign_value(global_state.actuator.packet, input_param);
    Actuator_0_transition(2);
  ::else->
    skip;
  fi;
}
inline Actuator_0_PI_0_test_sub(input_param)
{
  if
  ::(global_state.actuator.state == Actuator_States_wait)->
    MyPacket_assign_value(global_state.actuator.packet, input_param);
    Actuator_0_transition(3);
  ::else->
    skip;
  fi;
}

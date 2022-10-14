inline Controller_0_transition(id)
{
  int transition_id;
  transition_id = id;
  do
  ::if
    ::(transition_id == -1)->
      break;
    ::(transition_id == 0)->
      {
        MyReal_assign_value(global_state.controller.packet.lhs, 2.2);
        MyReal_assign_value(global_state.controller.packet.rhs, 2.2);
      }
      Controller_0_RI_0_test_add(global_state.controller.packet);
      transition_id = -1;
      global_state.controller.state = Controller_States_waitadd;
      goto continuous_signals;
    ::(transition_id == 1)->
      if
      ::((((global_state.controller.ret - 4.4) <= global_state.controller.epsilon) && ((global_state.controller.ret - 4.4) >= (- global_state.controller.epsilon))) == false)->
        transition_id = -1;
        global_state.controller.state = Controller_States_error;
        goto continuous_signals;
      ::((((global_state.controller.ret - 4.4) <= global_state.controller.epsilon) && ((global_state.controller.ret - 4.4) >= (- global_state.controller.epsilon))) == true)->
        {
          MyReal_assign_value(global_state.controller.packet.lhs, 5.2);
          MyReal_assign_value(global_state.controller.packet.rhs, 4.0);
        }
        Controller_0_RI_0_test_sub(global_state.controller.packet);
        transition_id = -1;
        global_state.controller.state = Controller_States_waitsub;
        goto continuous_signals;
      fi;
    ::(transition_id == 2)->
      if
      ::((((global_state.controller.ret - 3.3) <= global_state.controller.epsilon) && ((global_state.controller.ret - 3.3) >= (- global_state.controller.epsilon))) == false)->
        transition_id = -1;
        global_state.controller.state = Controller_States_error;
        goto continuous_signals;
      ::((((global_state.controller.ret - 3.3) <= global_state.controller.epsilon) && ((global_state.controller.ret - 3.3) >= (- global_state.controller.epsilon))) == true)->
        transition_id = -1;
        global_state.controller.state = Controller_States_finished;
		 printf("state finished\n");
        goto continuous_signals;
      fi;
    ::(transition_id == 3)->
      if
      ::((((global_state.controller.ret - 1.2) <= global_state.controller.epsilon) && ((global_state.controller.ret - 1.2) >= (- global_state.controller.epsilon))) == false)->
        transition_id = -1;
        global_state.controller.state = Controller_States_error;
        goto continuous_signals;
      ::((((global_state.controller.ret - 1.2) <= global_state.controller.epsilon) && ((global_state.controller.ret - 1.2) >= (- global_state.controller.epsilon))) == true)->
        {
          MyReal_assign_value(global_state.controller.packet.lhs, 4.0);
          MyReal_assign_value(global_state.controller.packet.rhs, 5.5);
        }
        Controller_0_RI_0_test_mul(global_state.controller.packet);
        transition_id = -1;
        global_state.controller.state = Controller_States_waitmul;
        goto continuous_signals;
      fi;
    ::(transition_id == 4)->
      if
      ::((((global_state.controller.ret - 22.0) <= global_state.controller.epsilon) && ((global_state.controller.ret - 22.0) >= (- global_state.controller.epsilon))) == false)->
        transition_id = -1;
        global_state.controller.state = Controller_States_error;
        goto continuous_signals;
      ::((((global_state.controller.ret - 22.0) <= global_state.controller.epsilon) && ((global_state.controller.ret - 22.0) >= (- global_state.controller.epsilon))) == true)->
        {
          MyReal_assign_value(global_state.controller.packet.lhs, 9.9);
          MyReal_assign_value(global_state.controller.packet.rhs, 3.0);
        }
        Controller_0_RI_0_test_div(global_state.controller.packet);
        transition_id = -1;
        global_state.controller.state = Controller_States_waitdiv;
        goto continuous_signals;
      fi;
    fi;
    continuous_signals:
  od;
}
inline Controller_0_init()
{
  MyReal_assign_value(global_state.controller.epsilon, 0.001);
  Controller_0_transition(0);
}
inline Controller_0_PI_0_result(input_param)
{
  if
  ::(global_state.controller.state == Controller_States_waitadd)->
    MyReal_assign_value(global_state.controller.ret, input_param);
    Controller_0_transition(1);
  ::(global_state.controller.state == Controller_States_waitdiv)->
    MyReal_assign_value(global_state.controller.ret, input_param);
    Controller_0_transition(2);
  ::(global_state.controller.state == Controller_States_waitmul)->
    MyReal_assign_value(global_state.controller.ret, input_param);
    Controller_0_transition(4);
  ::(global_state.controller.state == Controller_States_waitsub)->
    MyReal_assign_value(global_state.controller.ret, input_param);
    Controller_0_transition(3);
  ::else->
    skip;
  fi;
}

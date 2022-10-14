inline Controller_0_transition(id)
{
  int transition_id;
  transition_id = id;
  do
  ::if
    ::(transition_id == -1)->
      break;
    ::(transition_id == 0)->
      MyReal_assign_value(global_state.controller.simple_param, 3.1415);
      Controller_0_RI_0_test_simple(global_state.controller.simple_param);
      transition_id = -1;
      global_state.controller.state = Controller_States_waitforsimplepositive;
      goto continuous_signals;
    ::(transition_id == 1)->
      if
      ::((((global_state.controller.ret - -3.2) <= global_state.controller.epsilon) && ((global_state.controller.ret - -3.2) >= (- global_state.controller.epsilon))) == true)->
        {
          MyReal_assign_value(global_state.controller.sequence_param.first, 4.5);
          MyReal_assign_value(global_state.controller.sequence_param.second, 2.0);
        }
        Controller_0_RI_0_test_sequence(global_state.controller.sequence_param);
        transition_id = -1;
        global_state.controller.state = Controller_States_waitforsequencepositive;
        goto continuous_signals;
      ::else->
        transition_id = -1;
        global_state.controller.state = Controller_States_error;
        goto continuous_signals;
      fi;
    ::(transition_id == 2)->
      if
      ::(((global_state.controller.ret <= global_state.controller.epsilon) && (global_state.controller.ret >= (- global_state.controller.epsilon))) == false)->
        transition_id = -1;
        global_state.controller.state = Controller_States_error;
        goto continuous_signals;
      ::(((global_state.controller.ret <= global_state.controller.epsilon) && (global_state.controller.ret >= (- global_state.controller.epsilon))) == true)->
        MyReal_assign_value(global_state.controller.simple_param, -3.2);
        Controller_0_RI_0_test_simple(global_state.controller.simple_param);
        transition_id = -1;
        global_state.controller.state = Controller_States_waitforsimplenegative;
        goto continuous_signals;
      fi;
    ::(transition_id == 3)->
      if
      ::((((global_state.controller.ret - 4.5) <= global_state.controller.epsilon) && ((global_state.controller.ret - 4.5) >= (- global_state.controller.epsilon))) == false)->
        transition_id = -1;
        global_state.controller.state = Controller_States_error;
        goto continuous_signals;
      ::((((global_state.controller.ret - 4.5) <= global_state.controller.epsilon) && ((global_state.controller.ret - 4.5) >= (- global_state.controller.epsilon))) == true)->
        {
          MyReal_assign_value(global_state.controller.sequence_param.first, 0.0);
          MyReal_assign_value(global_state.controller.sequence_param.second, 2.0);
        }
        Controller_0_RI_0_test_sequence(global_state.controller.sequence_param);
        transition_id = -1;
        global_state.controller.state = Controller_States_waitforsequencezero;
        goto continuous_signals;
      fi;
    ::(transition_id == 4)->
      if
      ::((((global_state.controller.ret - -4.6) <= global_state.controller.epsilon) && ((global_state.controller.ret - -4.6) >= (- global_state.controller.epsilon))) == false)->
        transition_id = -1;
        global_state.controller.state = Controller_States_error;
        goto continuous_signals;
      ::((((global_state.controller.ret - -4.6) <= global_state.controller.epsilon) && ((global_state.controller.ret - -4.6) >= (- global_state.controller.epsilon))) == true)->
        {
          MyReal_assign_value(global_state.controller.array_param.data[0], 5.7);
          MyReal_assign_value(global_state.controller.array_param.data[1], 5.0);
          MyReal_assign_value(global_state.controller.array_param.data[2], 5.0);
          MyReal_assign_value(global_state.controller.array_param.data[3], 5.0);
        }
        Controller_0_RI_0_test_array(global_state.controller.array_param);
        transition_id = -1;
        global_state.controller.state = Controller_States_waitforarraypositive;
        goto continuous_signals;
      fi;
    ::(transition_id == 5)->
      if
      ::(((global_state.controller.ret <= global_state.controller.epsilon) && (global_state.controller.ret >= (- global_state.controller.epsilon))) == false)->
        transition_id = -1;
        global_state.controller.state = Controller_States_error;
        goto continuous_signals;
      ::(((global_state.controller.ret <= global_state.controller.epsilon) && (global_state.controller.ret >= (- global_state.controller.epsilon))) == true)->
        {
          MyReal_assign_value(global_state.controller.sequence_param.first, -4.6);
          MyReal_assign_value(global_state.controller.sequence_param.second, 2.0);
        }
        Controller_0_RI_0_test_sequence(global_state.controller.sequence_param);
        transition_id = -1;
        global_state.controller.state = Controller_States_waitforsequencenegative;
        goto continuous_signals;
      fi;
    ::(transition_id == 6)->
      if
      ::((((global_state.controller.ret - 5.7) <= global_state.controller.epsilon) && ((global_state.controller.ret - 5.7) >= (- global_state.controller.epsilon))) == false)->
        transition_id = -1;
        global_state.controller.state = Controller_States_error;
        goto continuous_signals;
      ::((((global_state.controller.ret - 5.7) <= global_state.controller.epsilon) && ((global_state.controller.ret - 5.7) >= (- global_state.controller.epsilon))) == true)->
        {
          MyReal_assign_value(global_state.controller.array_param.data[0], 0.0);
          MyReal_assign_value(global_state.controller.array_param.data[1], 1.0);
          MyReal_assign_value(global_state.controller.array_param.data[2], 2.0);
          MyReal_assign_value(global_state.controller.array_param.data[3], 3.0);
        }
        Controller_0_RI_0_test_array(global_state.controller.array_param);
        transition_id = -1;
        global_state.controller.state = Controller_States_waitforarrayzero;
        goto continuous_signals;
      fi;
    ::(transition_id == 7)->
      if
      ::(((global_state.controller.ret <= global_state.controller.epsilon) && (global_state.controller.ret >= (- global_state.controller.epsilon))) == false)->
        transition_id = -1;
        global_state.controller.state = Controller_States_error;
        goto continuous_signals;
      ::(((global_state.controller.ret <= global_state.controller.epsilon) && (global_state.controller.ret >= (- global_state.controller.epsilon))) == true)->
        {
          MyReal_assign_value(global_state.controller.array_param.data[0], -5.9);
          MyReal_assign_value(global_state.controller.array_param.data[1], -4.0);
          MyReal_assign_value(global_state.controller.array_param.data[2], -3.0);
          MyReal_assign_value(global_state.controller.array_param.data[3], -2.0);
        }
        Controller_0_RI_0_test_array(global_state.controller.array_param);
        transition_id = -1;
        global_state.controller.state = Controller_States_waitforarraynegative;
        goto continuous_signals;
      fi;
    ::(transition_id == 8)->
      if
      ::((((global_state.controller.ret - -5.9) <= global_state.controller.epsilon) && ((global_state.controller.ret - -5.9) >= (- global_state.controller.epsilon))) == true)->
        transition_id = -1;
        global_state.controller.state = Controller_States_finished;
		printf("state finished\n");
        goto continuous_signals;
      ::((((global_state.controller.ret - -5.9) <= global_state.controller.epsilon) && ((global_state.controller.ret - -5.9) >= (- global_state.controller.epsilon))) == false)->
        transition_id = -1;
        global_state.controller.state = Controller_States_error;
        goto continuous_signals;
      fi;
    ::(transition_id == 9)->
      if
      ::((((global_state.controller.ret - 3.1415) <= global_state.controller.epsilon) && ((global_state.controller.ret - 3.1415) >= (- global_state.controller.epsilon))) == false)->
        transition_id = -1;
        global_state.controller.state = Controller_States_error;
        goto continuous_signals;
      ::((((global_state.controller.ret - 3.1415) <= global_state.controller.epsilon) && ((global_state.controller.ret - 3.1415) >= (- global_state.controller.epsilon))) == true)->
        MyReal_assign_value(global_state.controller.simple_param, 0.0);
        Controller_0_RI_0_test_simple(global_state.controller.simple_param);
        transition_id = -1;
        global_state.controller.state = Controller_States_waitforsimplezero;
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
  ::(global_state.controller.state == Controller_States_waitforarraynegative)->
    MyReal_assign_value(global_state.controller.ret, input_param);
    Controller_0_transition(8);
  ::(global_state.controller.state == Controller_States_waitforarraypositive)->
    MyReal_assign_value(global_state.controller.ret, input_param);
    Controller_0_transition(6);
  ::(global_state.controller.state == Controller_States_waitforarrayzero)->
    MyReal_assign_value(global_state.controller.ret, input_param);
    Controller_0_transition(7);
  ::(global_state.controller.state == Controller_States_waitforsequencenegative)->
    MyReal_assign_value(global_state.controller.ret, input_param);
    Controller_0_transition(4);
  ::(global_state.controller.state == Controller_States_waitforsequencepositive)->
    MyReal_assign_value(global_state.controller.ret, input_param);
    Controller_0_transition(3);
  ::(global_state.controller.state == Controller_States_waitforsequencezero)->
    MyReal_assign_value(global_state.controller.ret, input_param);
    Controller_0_transition(5);
  ::(global_state.controller.state == Controller_States_waitforsimplenegative)->
    MyReal_assign_value(global_state.controller.ret, input_param);
    Controller_0_transition(1);
  ::(global_state.controller.state == Controller_States_waitforsimplepositive)->
    MyReal_assign_value(global_state.controller.ret, input_param);
    Controller_0_transition(9);
  ::(global_state.controller.state == Controller_States_waitforsimplezero)->
    MyReal_assign_value(global_state.controller.ret, input_param);
    Controller_0_transition(2);
  ::else->
    skip;
  fi;
}

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
        MyReal_assign_value(global_state.controller.packet.rhs, 4.0);
      }
      Controller_0_RI_0_test_less(global_state.controller.packet);
      transition_id = -1;
      global_state.controller.state = Controller_States_waitlesstrue;
      goto continuous_signals;
    ::(transition_id == 1)->
      if
      ::(global_state.controller.ret == true)->
        transition_id = -1;
        global_state.controller.state = Controller_States_finished;
		 printf("state finished\n");
        goto continuous_signals;
      ::(global_state.controller.ret == false)->
        transition_id = -1;
        global_state.controller.state = Controller_States_error;
        goto continuous_signals;
      fi;
    ::(transition_id == 2)->
      if
      ::(global_state.controller.ret == false)->
        transition_id = -1;
        global_state.controller.state = Controller_States_error;
        goto continuous_signals;
      ::(global_state.controller.ret == true)->
        {
          MyReal_assign_value(global_state.controller.packet.lhs, 2.8);
          MyReal_assign_value(global_state.controller.packet.rhs, -2.8);
        }
        Controller_0_RI_0_test_greater_equal(global_state.controller.packet);
        transition_id = -1;
        global_state.controller.state = Controller_States_waitgreaterequaltrueb;
        goto continuous_signals;
      fi;
    ::(transition_id == 3)->
      if
      ::(global_state.controller.ret == true)->
        transition_id = -1;
        global_state.controller.state = Controller_States_error;
        goto continuous_signals;
      ::(global_state.controller.ret == false)->
        {
          MyReal_assign_value(global_state.controller.packet.lhs, 2.5);
          MyReal_assign_value(global_state.controller.packet.rhs, 2.5);
        }
        Controller_0_RI_0_test_greater_equal(global_state.controller.packet);
        transition_id = -1;
        global_state.controller.state = Controller_States_waitgreaterequaltruea;
        goto continuous_signals;
      fi;
    ::(transition_id == 4)->
      if
      ::(global_state.controller.ret == false)->
        transition_id = -1;
        global_state.controller.state = Controller_States_error;
        goto continuous_signals;
      ::(global_state.controller.ret == true)->
        {
          MyReal_assign_value(global_state.controller.packet.lhs, 2.1);
          MyReal_assign_value(global_state.controller.packet.rhs, 2.1);
        }
        Controller_0_RI_0_test_less(global_state.controller.packet);
        transition_id = -1;
        global_state.controller.state = Controller_States_waitlessfalsea;
        goto continuous_signals;
      fi;
    ::(transition_id == 5)->
      if
      ::(global_state.controller.ret == true)->
        transition_id = -1;
        global_state.controller.state = Controller_States_error;
        goto continuous_signals;
      ::(global_state.controller.ret == false)->
        {
          MyReal_assign_value(global_state.controller.packet.lhs, 2.8);
          MyReal_assign_value(global_state.controller.packet.rhs, 4.2);
        }
        Controller_0_RI_0_test_greater(global_state.controller.packet);
        transition_id = -1;
        global_state.controller.state = Controller_States_waitgreaterfalsea;
        goto continuous_signals;
      fi;
    ::(transition_id == 6)->
      if
      ::(global_state.controller.ret == false)->
        transition_id = -1;
        global_state.controller.state = Controller_States_error;
        goto continuous_signals;
      ::(global_state.controller.ret == true)->
        {
          MyReal_assign_value(global_state.controller.packet.lhs, 2.0);
          MyReal_assign_value(global_state.controller.packet.rhs, -2.0);
        }
        Controller_0_RI_0_test_less_equal(global_state.controller.packet);
        transition_id = -1;
        global_state.controller.state = Controller_States_waitlessequalfalse;
        goto continuous_signals;
      fi;
    ::(transition_id == 7)->
      if
      ::(global_state.controller.ret == false)->
        transition_id = -1;
        global_state.controller.state = Controller_States_error;
        goto continuous_signals;
      ::(global_state.controller.ret == true)->
        {
          MyReal_assign_value(global_state.controller.packet.lhs, 2.7);
          MyReal_assign_value(global_state.controller.packet.rhs, 2.7);
        }
        Controller_0_RI_0_test_less_equal(global_state.controller.packet);
        transition_id = -1;
        global_state.controller.state = Controller_States_waitlessequaltrueb;
        goto continuous_signals;
      fi;
    ::(transition_id == 8)->
      if
      ::(global_state.controller.ret == true)->
        transition_id = -1;
        global_state.controller.state = Controller_States_error;
        goto continuous_signals;
      ::(global_state.controller.ret == false)->
        {
          MyReal_assign_value(global_state.controller.packet.lhs, 2.4);
          MyReal_assign_value(global_state.controller.packet.rhs, 4.4);
        }
        Controller_0_RI_0_test_less_equal(global_state.controller.packet);
        transition_id = -1;
        global_state.controller.state = Controller_States_waitlessequaltruea;
        goto continuous_signals;
      fi;
    ::(transition_id == 9)->
      if
      ::(global_state.controller.ret == true)->
        transition_id = -1;
        global_state.controller.state = Controller_States_error;
        goto continuous_signals;
      ::(global_state.controller.ret == false)->
        {
          MyReal_assign_value(global_state.controller.packet.lhs, 2.3);
          MyReal_assign_value(global_state.controller.packet.rhs, -2.3);
        }
        Controller_0_RI_0_test_less(global_state.controller.packet);
        transition_id = -1;
        global_state.controller.state = Controller_States_waitlessfalseb;
        goto continuous_signals;
      fi;
    ::(transition_id == 10)->
      if
      ::(global_state.controller.ret == true)->
        transition_id = -1;
        global_state.controller.state = Controller_States_error;
        goto continuous_signals;
      ::(global_state.controller.ret == false)->
        {
          MyReal_assign_value(global_state.controller.packet.lhs, 2.2);
          MyReal_assign_value(global_state.controller.packet.rhs, 2.2);
        }
        Controller_0_RI_0_test_greater(global_state.controller.packet);
        transition_id = -1;
        global_state.controller.state = Controller_States_waitgreaterfalseb;
        goto continuous_signals;
      fi;
    ::(transition_id == 11)->
      if
      ::(global_state.controller.ret == true)->
        transition_id = -1;
        global_state.controller.state = Controller_States_error;
        goto continuous_signals;
      ::(global_state.controller.ret == false)->
        {
          MyReal_assign_value(global_state.controller.packet.lhs, 2.3);
          MyReal_assign_value(global_state.controller.packet.rhs, -2.3);
        }
        Controller_0_RI_0_test_greater(global_state.controller.packet);
        transition_id = -1;
        global_state.controller.state = Controller_States_waitgreatertrue;
        goto continuous_signals;
      fi;
    ::(transition_id == 12)->
      if
      ::(global_state.controller.ret == false)->
        transition_id = -1;
        global_state.controller.state = Controller_States_error;
        goto continuous_signals;
      ::(global_state.controller.ret == true)->
        {
          MyReal_assign_value(global_state.controller.packet.lhs, 2.9);
          MyReal_assign_value(global_state.controller.packet.rhs, 4.0);
        }
        Controller_0_RI_0_test_greater_equal(global_state.controller.packet);
        transition_id = -1;
        global_state.controller.state = Controller_States_waitgreaterequalfalse;
        goto continuous_signals;
      fi;
    fi;
    continuous_signals:
  od;
}
inline Controller_0_init()
{
  Controller_0_transition(0);
}
inline Controller_0_PI_0_result(input_param)
{
  if
  ::(global_state.controller.state == Controller_States_waitgreaterequalfalse)->
    MyFlag_assign_value(global_state.controller.ret, input_param);
    Controller_0_transition(3);
  ::(global_state.controller.state == Controller_States_waitgreaterequaltruea)->
    MyFlag_assign_value(global_state.controller.ret, input_param);
    Controller_0_transition(2);
  ::(global_state.controller.state == Controller_States_waitgreaterequaltrueb)->
    MyFlag_assign_value(global_state.controller.ret, input_param);
    Controller_0_transition(1);
  ::(global_state.controller.state == Controller_States_waitgreaterfalsea)->
    MyFlag_assign_value(global_state.controller.ret, input_param);
    Controller_0_transition(10);
  ::(global_state.controller.state == Controller_States_waitgreaterfalseb)->
    MyFlag_assign_value(global_state.controller.ret, input_param);
    Controller_0_transition(11);
  ::(global_state.controller.state == Controller_States_waitgreatertrue)->
    MyFlag_assign_value(global_state.controller.ret, input_param);
    Controller_0_transition(12);
  ::(global_state.controller.state == Controller_States_waitlessequalfalse)->
    MyFlag_assign_value(global_state.controller.ret, input_param);
    Controller_0_transition(5);
  ::(global_state.controller.state == Controller_States_waitlessequaltruea)->
    MyFlag_assign_value(global_state.controller.ret, input_param);
    Controller_0_transition(7);
  ::(global_state.controller.state == Controller_States_waitlessequaltrueb)->
    MyFlag_assign_value(global_state.controller.ret, input_param);
    Controller_0_transition(6);
  ::(global_state.controller.state == Controller_States_waitlessfalsea)->
    MyFlag_assign_value(global_state.controller.ret, input_param);
    Controller_0_transition(9);
  ::(global_state.controller.state == Controller_States_waitlessfalseb)->
    MyFlag_assign_value(global_state.controller.ret, input_param);
    Controller_0_transition(8);
  ::(global_state.controller.state == Controller_States_waitlesstrue)->
    MyFlag_assign_value(global_state.controller.ret, input_param);
    Controller_0_transition(4);
  ::else->
    skip;
  fi;
}

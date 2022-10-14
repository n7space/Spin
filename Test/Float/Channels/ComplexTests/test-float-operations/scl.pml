never{
  start: 
  do
  ::inited->
    break;
  ::else->
    goto start;
  od;
  accept_all: 
  do
  :: atomic {
    (global_state.controller.state == Controller_States_error)->
      assert((! (global_state.controller.state == Controller_States_error)));
    }
  ::(global_state.controller.state == Controller_States_finished)->
    goto state_0;
  ::else->
    goto accept_all;
  od;
  state_0: 
  do
  :: atomic {
    (global_state.controller.state == Controller_States_error)->
      assert((! (global_state.controller.state == Controller_States_error)));
    }
  ::else->
    goto state_0;
  od;
}

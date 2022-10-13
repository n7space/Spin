never{
  start: 
  do
  ::inited->
    break;
  ::else->
    goto start;
  od;
  system_inited: 
  do
  :: atomic {
    (global_state.controller.state == Controller_States_finished)->
      assert((! (global_state.controller.state == Controller_States_finished)));
    }
  ::else->
    goto system_inited;
  od;
}

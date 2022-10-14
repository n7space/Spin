chan actuator_ping_channel = [1] of {float};
chan controller_pong_channel = [1] of {float};
 
active proctype actuator() {
  float myVal;
  actuator_ping_channel?myVal
  controller_pong_channel!myVal;
}
 
active proctype controller() {
  float someVal = 3.1415;
  float result;
  float epsilon = 0.001;
  actuator_ping_channel!someVal;

  controller_pong_channel?result;
  printf("Got pong = %f\n", result);
  
  assert((result - 3.1415 <= epsilon) && (result - 3.1415 >= -epsilon));
}

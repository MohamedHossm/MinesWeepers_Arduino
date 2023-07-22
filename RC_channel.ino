void Channel()
{
  if (receiver_input[3] > 30)yaw = 'R';
  else if (receiver_input[3] < 15)yaw = 'L';
  else yaw = 'M';
  if (receiver_input[1] > 75)pitch = 'L';
  else if (receiver_input[1] < -75)pitch = 'H';
  else pitch = 'M';
  switch_A = receiver_input[4];
}


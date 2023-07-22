void PLOT (int DISTANCE) {
  if (DISTANCE >= 0 && DISTANCE < 100 ) plot = 1;
  if ( 100 < DISTANCE && DISTANCE <= 200 ) plot = 2;
  if ( 200 < DISTANCE && DISTANCE <= 300 ) plot = 3;
  if ( 300 < DISTANCE && DISTANCE <= 400 ) plot = 4;
  if ( 400 < DISTANCE && DISTANCE <= 500 ) plot = 5;
  if ( 500 < DISTANCE && DISTANCE <= 600 ) plot = 6;
  if ( 600 < DISTANCE && DISTANCE <= 700 ) plot = 7;
  if ( 700 < DISTANCE && DISTANCE <= 800 ) plot = 8;
  if ( 800 < DISTANCE && DISTANCE <= 900 ) plot = 9;
  if ( 900 < DISTANCE && DISTANCE <= 1000 ) plot = 10;
  if ( 1000 < DISTANCE && DISTANCE <= 1100 ) plot = 11;
  if ( 1100 < DISTANCE && DISTANCE <= 1200 ) plot = 12;
  if ( 1200 < DISTANCE && DISTANCE <= 1300 ) plot = 13;
  if ( 1300 < DISTANCE && DISTANCE <= 1400 ) plot = 14;
  if ( 1400 < DISTANCE && DISTANCE <= 1500 ) plot = 15;
  if ( 1500 < DISTANCE && DISTANCE <= 1600 ) plot = 16;
  if ( 1600 < DISTANCE && DISTANCE <= 1700 ) plot = 17;
  if ( 1700 < DISTANCE && DISTANCE <= 1800 ) plot = 18;
  if ( 1800 < DISTANCE && DISTANCE <= 1900  ) plot = 19;
}
//****************************************************************
void LINE() {
  if (pitch == 'H' && flag == 0) {
    line ++ ;
    EncoderZero();
    flag = 1;
  }
  else if (pitch == 'M' && flag == 1) {
    flag = 0;
  }
  else if (pitch == 'L' && flag == 0) {
    line -- ;
    EncoderZero();
    flag = 1;
  }
  else if (pitch == 'M' && flag == 1) {
    flag = 0;
  }
  if (line <= 1)line = 1;
  if (line >= 10)line = 10;
}
//***************************************************************
void Zero () {
  if (yaw == 'R' && z == 0) {
    if (zero == 1 ){
      zero =0;
      z = 1;
    }
    else if (zero == 0 ){
      zero =1;
      z = 1;
  }
  }
   if (yaw == 'M') {
    z = 0;
  }
}

//********************************************************************
void auto_map()
{

  if (receiver_input[2] > 10 && switch_A <= 1000 )
  {
    AutoEncoderZero();
  }
  else if (receiver_input[2] > 10 && switch_A >= 1500)
  {
    AutoEncoderZero();
  }
  else if (receiver_input[0] > 10)
  {
    if (Total_Distance_MP > 40 && plot == 19 && Map_flag[0] == 0)
    {
      EncoderZero();
      zero = 1;
      Map_flag[0] = 1;
    }
    else if (Total_Distance_MP > 40 && plot == 1 && Map_flag[1] == 1)
    {
      zero = 0;
      line ++ ;
      Map_flag[1] = 0;
    }
  }
  else if (receiver_input[0] < -10)
  {
    if (Total_Distance_MP > 40 && plot == 19 && Map_flag[0] == 0)
    {
      EncoderZero();
      zero = 1;
      Map_flag[0] = 1;
    }
    else if (Total_Distance_MP > 40 && plot == 1 && Map_flag[1] == 1)
    {
      zero = 0;
      line ++ ;
      Map_flag[1] = 0;
    }
  }

}

int ENCODER_FW(int Encoder , int Encoder_Counter  , int EncoderDistance)      // encoder in forward
{
  Encode = digitalRead(Encoder);

  if (Encode == 0 && Encoder_index[Encoder_Counter] == 0)
  {
    count[Encoder_Counter]++;
    Encoder_index[Encoder_Counter] = 1;
  }

  else if (Encode == 1 && Encoder_index[Encoder_Counter] == 1) {
    Encoder_index[Encoder_Counter] = 0;
  }

  distance =  ((count[Encoder_Counter] * (EncoderDistance)) / Encoder_Holes);
  return distance;
}
//**********************************************************************************
int ENCODER_BW(int Encoder , int Encoder_Counter  , int EncoderDistance)     //encoder in backward
{

  Encode = digitalRead(Encoder);

  if (Encode == 1 && Encoder_index_BW[Encoder_Counter] == 0)
  {
    count_BW[Encoder_Counter]++;
    Encoder_index_BW[Encoder_Counter] = 1;
  }

  else if (Encode == 0 && Encoder_index_BW[Encoder_Counter] == 1) {
    Encoder_index_BW[Encoder_Counter] = 0;
  }

  distance_BW =  ((count_BW[Encoder_Counter] * (EncoderDistance)) / Encoder_Holes);
  return distance_BW;
}
//************************************************************************
int ENCODER_MP(int Encoder , int Encoder_Counter , int EncoderDistance)      //encoder in backward
{

  Encode = digitalRead(Encoder);

  if (Encode == 1 && Encoder_index_MP[Encoder_Counter] == 0)
  {
    count_MP[Encoder_Counter]++;
    Encoder_index_MP[Encoder_Counter] = 1;
  }

  else if (Encode == 0 && Encoder_index_MP[Encoder_Counter] == 1) {
    Encoder_index_MP[Encoder_Counter] = 0;
  }

  distance_MP =  ((count_MP[Encoder_Counter] * (EncoderDistance)) / Encoder_Holes);
  return distance_MP;

}
//*********************************************************************************
//==============================================================================
void TOTAL_DISTANCE(char data)
{
  if (data == 'F')                        //distance in forward
  {

    Total_Distance_F =   ENCODER_FW(ENCODER_PIN_1, 0 , 98)
                         + ENCODER_FW(ENCODER_PIN_2, 1 , 99)
                         + ENCODER_FW(ENCODER_PIN_3, 2 ,  98)
                         + ENCODER_FW(ENCODER_PIN_4, 3 ,  99);

    Total_Distance_F = Total_Distance_F / 4 ;
  }
  else if (data == 'B')                     //distance in backward
  {
    Total_Distance_BW =   ENCODER_BW(ENCODER_PIN_1, 0  , 98)
                          + ENCODER_BW(ENCODER_PIN_2, 1 , 99)
                          + ENCODER_BW(ENCODER_PIN_3, 2 ,  98)
                          + ENCODER_BW(ENCODER_PIN_4, 3 ,  99);

    Total_Distance_BW = Total_Distance_BW / 4 ;
  }
  else if (data == 'M')                     //distance in backward
  {
    Total_Distance_MP =   ENCODER_MP(ENCODER_PIN_1, 0, 98)
                          + ENCODER_MP(ENCODER_PIN_2,1, 99)
                          + ENCODER_MP(ENCODER_PIN_3,2, 98)
                          + ENCODER_MP(ENCODER_PIN_4,3, 99);

    Total_Distance_MP = Total_Distance_MP / 4 ;
  }
  else if (data == 'T')            // total distance
  {
    Total_Distance_T = Total_Distance_F  ;//- Total_Distance_BW ;
  }
}

void EncoderZero() {

  count_BW[0] = 0;
  count_BW[1] = 0;
  count_BW[2] = 0;
  count_BW[3] = 0;
  count[0] = 0;
  count[1] = 0;
  count[2] = 0;
  count[3] = 0;
  distance_BW = 0;
  distance = 0;
  Total_Distance_T = 0;
  Total_Distance_F = 0;
  Total_Distance_BW = 0;
  mkanyR = 0;
  mkanyL = 0;
}

void AutoEncoderZero() {

  count_MP[0] = 0;
  count_MP[1] = 0;
  count_MP[2] = 0;
  count_MP[3] = 0;

  if(Map_flag[0] == 1)
  {
    Map_flag[1] = 1;
  }
  Map_flag[0] = 0;

  distance_MP = 0;
  Total_Distance_MP = 0;

}



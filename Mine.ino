void MINE(int *LandMineR , int *LandMineL , int Cal)
{

  if (Sensor_Right_Reading == 1 ) {            //mine_right Cheack up 0r down
    pulseR++;
    if (pulseR > Cal) {
      *LandMineR = 1;
      pulseR = 0;
    }
  }
  else if (Sensor_Right_Reading == 0 )
  {
    pulseR = 0;
    *LandMineR = 0;
  }


  if (Sensor_Left_Reading == 1 ) {
    pulseL++;
    if (pulseL > Cal) {
      *LandMineL = 1;
      pulseL = 0;
    }
  }
  else if (Sensor_Left_Reading == 0 ) {
    pulseL = 0;
    *LandMineL = 0;
  }

}
//*********************************************************************
void DetectR () {
  if (timerflagR == 0) {
    timerR = millis();
    timerflagR = 1;
  }
  if (millis() - timerR < 2000) {
    doneR = 1;
    Move(0 , HIGH , LOW);
    digitalWrite(LED, HIGH);
    digitalWrite(Siren, LOW);
    Go = 0;

  }
  else if ((millis() - timerR >= 2000)  && (millis() - timerR < 2250)) {
    digitalWrite(LED, LOW);
    digitalWrite(Siren, HIGH);
    if (receiver_input[2] < 10) {
      landmineR = 100;
    }
    else if (receiver_input[2] > 10) {
      landmineR = 200;
    }
    Data_Send[5] = landmineR;

  }
  else if (millis() - timerR >= 2250)
  {
    landmineR = 0;
    Go = 1;
    Data_Send[5] = landmineR;
//    offtimerR = millis();
  }
}


void DetectL () {
  if (timerflagL == 0) {
    timerL = millis();
    timerflagL = 1;
  }
  if (millis() - timerL < 2000) {
    Move(0 , HIGH , LOW);
    digitalWrite(LED, HIGH);
    digitalWrite(Siren, LOW);
    doneL = 1;
    Go = 0;
  }
  else if ((millis() - timerL >= 2000)  && (millis() - timerL < 2250) ) {
    digitalWrite(LED, LOW);
    digitalWrite(Siren, HIGH);
    if (receiver_input[2] < 10) {
      landmineL = 100;
    }
    else if (receiver_input[2] > 10) {
      landmineL = 200;
    }
    Data_Send[4] = landmineL;
  }
  else if (millis() - timerL >= 2250)
  {
    landmineL = 0;
    Go = 1;
    Data_Send[4] = landmineL;
//    offtimerL = millis();
  }
}

void Final_Read_SensorR()
{
  if (doneR == 0 ) {
    MINE(&landmineR, 0 , 100);
  }
  if (( mkanyR - plot >= 1 || plot - mkanyR >= 1) && Sensor_Right_Reading == 0 ) {
    doneR = 0;
    timerflagR = 0;

  }

  if (landmineR > 0 ) {
    mkanyR = plot;
    DetectR ();
  }
}
void Final_Read_SensorL()
{
  if (doneL == 0 && line <= 9 ) {
    MINE(0, &landmineL , 100);
  }
  if (( mkanyL - plot >= 1 || plot - mkanyL >= 1) && Sensor_Left_Reading == 0) {
    doneL = 0;
    timerflagL = 0;
  }

  if (landmineL > 0  ) {
    mkanyL = plot;
    DetectL ();
  }
}

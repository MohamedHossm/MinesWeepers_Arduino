#include "MSRC.h"

MS_RC RC;

#define B_R_D  6
#define B_R_P  5
#define B_L_D  8
#define B_L_P  7
#define F_R_D  11
#define F_R_P  12
#define F_L_D  9
#define F_L_P  10

#define R_Sensor  3
#define L_Sensor  2

#define Siren  30

#define LED  13

#define ENCODER_PIN_1  24
#define ENCODER_PIN_2  25
#define ENCODER_PIN_3  26
#define ENCODER_PIN_4  27

//#define EncoderDistance 94
#define Encoder_Holes 20

int Data_Send[10] = {0};
int Data_index = 0;

int Encode = 0;
int DISTANCE = 0 ;
int plot = 0;
int Total_Distance_F = 0;
int Total_Distance_BW = 0;
int Total_Distance_T = 0;
int Total_Distance_MP = 0 ;

int Map_flag[3] = {0};

int Encoder_index[4] = {0};
long count[4] = {0};

int Encoder_index_BW[4] = {0};
long count_BW[4] = {0};

int Encoder_index_MP[4] = {0};
long count_MP[4] = {0};

volatile int receiver_input[6] = {0};
int switch_A = 0;
char yaw = 'M';
char pitch = 'M';
int offtimerR = 0;
int offtimerL = 0;
int timerflagR = 0;
int timerflagL = 0;
int Speed_L = 0;
int Speed_R = 0;
int distance_BW = 0;
int distance_MP ;
int distance = 0;
unsigned long timerR = 0;
unsigned long timerL = 0;
unsigned long Loop_Counter = 0;
int z = 0;
int line = 0;
int flag = 1;
int t7t = 0;
int zero = 0;

int landmineL = 0;
int landmineR = 0;
unsigned char Sensor_Right_Reading = 0;
unsigned char Sensor_Left_Reading = 0;
int pulseR = 0;
int pulseL = 0;
int Go = 1;
int doneL = 0;
int doneR = 0;
int mkanyL = 0;
int mkanyR = 0;
//*****************************************************************************
void setup() {
  Serial1.begin(9600);
  Serial.begin(115200);
  pinMode(B_R_D, OUTPUT);
  pinMode(B_R_P, OUTPUT);
  pinMode(B_L_D, OUTPUT);
  pinMode(B_L_P, OUTPUT);
  pinMode(F_R_D, OUTPUT);
  pinMode(F_R_P, OUTPUT);
  pinMode(F_L_D, OUTPUT);
  pinMode(F_L_P, OUTPUT);
  pinMode(Siren, OUTPUT);
  digitalWrite(Siren, HIGH);
  pinMode(LED, OUTPUT);
  pinMode(L_Sensor, INPUT);
  pinMode(R_Sensor, INPUT);
  pinMode(ENCODER_PIN_1, INPUT);
  pinMode(ENCODER_PIN_2, INPUT);
  pinMode(ENCODER_PIN_3, INPUT);
  pinMode(ENCODER_PIN_4, INPUT);
  RC.MS_Void_RcInit();
  Loop_Counter = micros();
}
//===================================================================================
void loop() {
  Sensor_Right_Reading = digitalRead(R_Sensor);
  Sensor_Left_Reading = digitalRead(L_Sensor);
  RC.MS_Void_RcChannels(receiver_input);
  TOTAL_DISTANCE('T');
  TOTAL_DISTANCE('M');
  Total_Distance_T = (Total_Distance_T) * (0.95);
  PLOT(Total_Distance_T);
  Channel();
  LINE();
  Serial1.Transmitter(&Data_index, Data_Send[Data_index] , 10);  //(SB , NB ,DA ,RX ,TX)
  Data_Send[0] = Total_Distance_BW ;
  Data_Send[1] = Total_Distance_T;
  Data_Send[2] = plot;
  Data_Send[3] = line;
  //5 & 6 landmine send in mine fun..
  Data_Send[6] = t7t;
  Data_Send[7] = zero;
  auto_map();
  Zero();
  //-------------------------------------------------------------------------
  if (zero == 0) {

    Final_Read_SensorL();
    Final_Read_SensorR();

    if (Go == 1)
    {
      if (receiver_input[2] > 10 && switch_A >= 1500)
      {
        Move(receiver_input[2], HIGH, LOW);
        //TOTAL_DISTANCE('B');
      }
      else if (receiver_input[2] > 10 && switch_A <= 1000)
      {
        Move(receiver_input[2], LOW, HIGH);
        TOTAL_DISTANCE('F');
      }
      else if (receiver_input[0] > 10)
      {
        TURN(receiver_input[0], HIGH, LOW);
      }
      else if (receiver_input[0] < -10)
      {
        TURN(-receiver_input[0], LOW, HIGH);
      }
      else
      {
        Stop();
      }
    }
  }

  //***********************************************************************
  else if (zero == 1) {
    if (receiver_input[2] > 10 && switch_A >= 1500)
    {
      Move(receiver_input[2], HIGH, LOW);
    }
    else if (receiver_input[2] > 10 && switch_A <= 1000)
    {
      Move(receiver_input[2], LOW, HIGH);
      TOTAL_DISTANCE('B');
    }
    else if (receiver_input[0] > 10)
    {
      TURN(receiver_input[0], HIGH, LOW);
    }
    else if (receiver_input[0] < -10)
    {
      TURN(-receiver_input[0], LOW, HIGH);
    }
    else
    {
      Stop();
    }
  }
}

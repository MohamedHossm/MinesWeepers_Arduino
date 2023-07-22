void Move(int Speed, boolean high, boolean low )
{
  Speed_R = Speed;
  Speed_L = Speed;
  if (receiver_input[0] > 1){
   Speed_R = Speed + receiver_input[0];
   Speed_L = Speed - receiver_input[0]; 
  }
else if ( receiver_input[0] < -1){
   Speed_L = Speed - receiver_input[0];
   Speed_R = Speed + receiver_input[0]; 
  }
  Speed_L = constrain (Speed_L ,0,100);
  Speed_R = constrain (Speed_R ,0,100);
  digitalWrite(B_R_D, low);
  digitalWrite(B_L_D, low);
  digitalWrite(F_R_D, low);
  digitalWrite(F_L_D, high);
  analogWrite(B_L_P, Speed_R); 
  analogWrite(B_R_P, (Speed_L*0.74));  
  analogWrite(F_L_P, (Speed_R*1.13));
  analogWrite(F_R_P, (Speed_L*0.84));
}
//******************
void TURN(int Speed, boolean high, boolean low )
{
  Speed = constrain(Speed, 0, 80);
  digitalWrite(B_R_D, low);
  digitalWrite(B_L_D, high);
  digitalWrite(F_R_D, low);
  digitalWrite(F_L_D, low);
  analogWrite(B_L_P, Speed);
  analogWrite(B_R_P, Speed);
  analogWrite(F_L_P, Speed);
  analogWrite(F_R_P, Speed);
}
//*******************
void Stop()
{
  digitalWrite(B_R_D, LOW);
  digitalWrite(B_L_D, LOW);
  digitalWrite(F_R_D, LOW);
  digitalWrite(F_L_D, LOW);
  analogWrite(B_L_P, 0);
  analogWrite(B_R_P, 0);
  analogWrite(F_L_P, 0);
  analogWrite(F_R_P, 0);
}

void Print () {
    Serial.print( ENCODER_FW(ENCODER_PIN_1, 0 , 98)); //forward_Left
    Serial.print("   ");
    Serial.print( ENCODER_FW(ENCODER_PIN_2, 1 , 99));   //back_left
    Serial.print("   ");
    Serial.print( ENCODER_FW(ENCODER_PIN_3, 2 , 98));  //forward_right
    Serial.print("   ");
    Serial.println( ENCODER_FW(ENCODER_PIN_4, 3 ,99)); //back_right
}

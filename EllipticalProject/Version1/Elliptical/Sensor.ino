void checkSensor(){
  bool c = digitalRead(D3);

  if(c==HIGH){
    if (check == LOW){
      count++;
      PulsesBetweenSeconds++;
      steps = count/3.75;

      double temp = (millis() - prevStepTime);
      cadence = 15000/temp;      
      prevStepTime = millis();

      cadenceAvg[i] = cadence;
      i++;
      if (i == cA){
        i = 0;
      }
      
      if (cadence < 150){
        digitalWrite(LED_BUILTIN, HIGH);
      }
      else {
        digitalWrite(LED_BUILTIN, LOW);
      }
      
      check = HIGH;
    }
  }
  else{
    check = LOW;
  }
}

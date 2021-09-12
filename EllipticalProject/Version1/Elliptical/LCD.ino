void LCDsetup() {
  lcd.init();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("iamJohnnySam");
  lcd.setCursor(0,1);
  lcd.print("Elliptical Prjct");
}

void updateLCD(){ 
  lcd.setCursor(0,0);
  lcd.print("T> ");
  lcd.setCursor(3,0);
  int temp = int(floor(RunTime/60));
  if (temp<10){
    lcd.print("0");
    lcd.setCursor(4,0);
  }
  lcd.print(temp);
  lcd.setCursor(5,0);
  lcd.print(":");
  lcd.setCursor(6,0);
  temp = RunTime-(int(floor(RunTime/60))*60);
  if (temp<10){
    lcd.print("0");
    lcd.setCursor(7,0);
  }
  lcd.print(temp);
  lcd.setCursor(8,0);
  lcd.print(" S> ");
  lcd.setCursor(12,0);
  lcd.print(int(steps));
  
  if (activeStatus){
    lcd.setCursor(0,1);
    lcd.print("P> ");
    lcd.setCursor(3,1);
    double temp2 = 0;
    for (int j=0; j<cA; j++){
      temp2 += cadenceAvg[j];
    }
    lcd.print(int(temp2/cA));
  }
  else if (dispPage==1){
    lcd.setCursor(0,1);
    lcd.print("  -- PAUSED --  ");
    dispPage = 2;
  }
  else if (dispPage==2){
    lcd.setCursor(0,1);
    lcd.print(">>>   >.<   <<< ");
    dispPage = 1;
  }
}

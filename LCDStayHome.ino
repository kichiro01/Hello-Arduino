#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.print("  STAY");
  lcd.setCursor(0, 1);
  lcd.print("        HOME     "); 
  
  pinMode(7, INPUT); 
}

void loop() {
  int sensorState = digitalRead(7);//sensor（2ピン）からの反応（HIGH　or　LOWを変数「sensorState」に格納

 

  //HIGHの場合
  if(sensorState == HIGH){
    Serial.println("反応");
    lcd.display();
    delay(3000);
  } else {
    Serial.println("反応なし");
    lcd.noDisplay();
    delay(3000);
  }
}

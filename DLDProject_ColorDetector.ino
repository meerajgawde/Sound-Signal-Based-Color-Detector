#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);//RS,EN,D4,D5,D6,D7

const int s0 = 8;  
const int s1 = 9;  
const int s2 = 10;  
const int s3 = 11;  
const int out = 12;  
// LED pins connected to Arduino

// Variables  
int red = 0;  
int grn = 0;  
int blu = 0;  
   
void setup()  
{  
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);  
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH);  
}  
   
void loop()
{  
   lcd.setCursor(0, 0);
  lcd.print("RGB Col Detector");//printing name
  color();
  Serial.print("R Intensity:");  
  Serial.print(red, DEC);  
  Serial.print(" G Intensity: ");  
  Serial.print(grn, DEC);  
  Serial.print(" B Intensity : ");  
  Serial.print(blu, DEC);  
  //Serial.println();

  if (red > 2  && red < 18   &&  grn >  2 && grn < 19    &&  blu > 2  && blu < 16)
  {
   Serial.println(" - (White Color)");
   lcd.setCursor(0, 1);
   lcd.print("   White   ");
   delay(1000);

  }
  else if (red > 80 && red < 125  &&  grn > 90 && grn < 125   &&  blu > 80 && blu < 125)
  {
   Serial.println(" - (Black Color)");
   lcd.setCursor(0, 1);
   lcd.print("   Black   ");
  delay(1000);
   }
  else if (red > 12 && red < 40   &&  grn > 40 && grn < 150    &&  blu > 33 && blu < 150)
  {
   Serial.println(" - (Red Color)");
   lcd.setCursor(0, 1);
   lcd.print("   Red   ");
   delay(1000);
  }
  else if (red > 50 && red < 95   &&  grn > 28 && grn < 70    &&  blu > 45 && blu < 85)
  {
   Serial.println(" - (Green Color)");
   lcd.setCursor(0, 1);
   lcd.print("   Green   ");
   delay(1000);

   }
  else if (red > 10 && red < 20   &&  grn > 10 && grn < 25    &&  blu > 20 && blu < 38)
  {
   Serial.println(" - (Yellow Color)");
   lcd.setCursor(0, 1);
   lcd.print("   Yellow   ");
   delay(1000);

   }
  else if (red > 65 && red < 125  &&  grn > 65 && grn < 115   &&  blu > 28 && blu < 65)
  {
   Serial.println(" - (Blue Color)");
   lcd.setCursor(0, 1);
   lcd.print("   Blue   ");
   delay(1000);

   }
  else  
  {
   Serial.println(" - (No Colour)");
   lcd.setCursor(0, 1);
   lcd.print("   no colour   ");
   delay(1000);
   }
 }  
   
void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  //count OUT, pRed, RED  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  //count OUT, pBLUE, BLUE  
  blu = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  //count OUT, pGreen, GREEN  
  grn = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}

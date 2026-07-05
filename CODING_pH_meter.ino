/*
  Combined pH Meter with I2C LCD Display
  Original pH logic by: Unknown / Analog Sensor Standard
  LCD Logic by: Arduino_uno_guy
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// --- pH Sensor Configuration ---
#define PH_OFFSET -1.00 
#define SensorPin A0         
unsigned long int avgValue;  
float b;
int buf[10], temp;

// --- LCD Configuration ---
// I2C address 0x27, 16 column, 2 row
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize Serial for debugging
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  
  // Initialize LCD
  lcd.init();
  lcd.backlight();
  
  // Splash screen
  lcd.setCursor(0, 0);
  lcd.print("pH Meter System");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);
  lcd.clear();
}

void loop() {
  // 1. Collect 10 samples from the sensor
  for(int i=0; i<10; i++) { 
    buf[i] = analogRead(SensorPin);
    delay(10);
  }

  // 2. Sort the samples (Bubble Sort) to remove outliers
  for(int i=0; i<9; i++) {
    for(int j=i+1; j<10; j++) {
      if(buf[i] > buf[j]) {
        temp = buf[i];
        buf[i] = buf[j];
        buf[j] = temp;
      }
    }
  }

  // 3. Average the middle 6 samples
  avgValue = 0;
  for(int i=2; i<8; i++) {
    avgValue += buf[i];
  }

  // 4. Convert Analog Value to Voltage and then to pH
  // Voltage = (avg / 6) * (5.0 / 1024)
  float phVoltage = (float)avgValue * 5.0 / 1024 / 6; 
  float phValue = 3.5 * phVoltage + PH_OFFSET;

  // 5. Output to Serial Monitor (for PC debugging)
  Serial.print("Voltage: ");
  Serial.print(phVoltage, 2);
  Serial.print(" | pH: ");
  Serial.println(phValue, 2);

  // 6. Update LCD Display
  lcd.setCursor(0, 0);
  lcd.print("Status: Ready   "); // Extra spaces clear old text
  lcd.setCursor(0, 1);
  lcd.print("pH Value: ");
  lcd.print(phValue, 2);
  lcd.print("  "); // Clear trailing digits

  // 7. Visual indicator (Blink onboard LED)
  digitalWrite(13, HIGH);       
  delay(800);
  digitalWrite(13, LOW); 
  delay(200); // Small pause for stability
}
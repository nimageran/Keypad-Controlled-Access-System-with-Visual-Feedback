#include <Keypad.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

Servo myServo;
LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address to 0x27 for a 16 chars and 2 line display

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'D','9','8','7'},
  {'C','5','6','B'},
  {'B','6','5','4'},
  {'A','3','2','1'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
String enteredCode = "";
const String correctCode = "1234";
int greenLED = 12; // Green LED connected to pin 12
int redLED = 13;   // Red LED connected to pin 13

void setup() {
  myServo.attach(10);
  myServo.write(0);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  Serial.begin(9600);
  
  lcd.init();                      // Initialize the LCD
  lcd.backlight();                 // Turn on the backlight
  lcd.print("Enter Password:");
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    enteredCode += key;
    Serial.println(key);
    
    // Update LCD with entered code
    lcd.setCursor(0, 1);
    lcd.print("                "); // Clear the second line
    lcd.setCursor(0, 1);
    lcd.print(enteredCode);
    
    if (enteredCode.length() == 4) {
      if (enteredCode == correctCode) {
        lcd.clear();
        lcd.print("Correct Password");
        lcd.setCursor(0, 1);
        lcd.print("Opening Door...");
        
        myServo.write(90);
        digitalWrite(greenLED, HIGH); // Turn on green LED immediately
        delay(5000); // Green LED on for 5 seconds
        digitalWrite(greenLED, LOW);  // Turn off green LED
        delay(25000); // Additional delay if you want the servo to stay longer
        myServo.write(0);
        
        lcd.clear();
        lcd.print("Door Closed");
        delay(2000);
      } else {
        lcd.clear();
        lcd.print("Wrong Password!");
        
        digitalWrite(redLED, HIGH);   // Turn on red LED
        delay(2000); // Red LED is on for 2 seconds
        digitalWrite(redLED, LOW);    // Turn off red LED
      }
      enteredCode = ""; // Reset the entered code
      
      // Reset LCD for next entry
      lcd.clear();
      lcd.print("Enter Password:");
    }
  }
}
/*
  Beginning to test displaying data on LCD for Ella's treat box

 This sketch prints will welcome Ella to the treat dispensor and 
 will count how many times she presses the button.

 Initial credit to hello world example, I am modifying it for my needs.


  The circuit:
 See fritzing drawing

 */
// include the library code:
#include <LiquidCrystal.h>

// Button setup
const int  buttonPin = 6;

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print greeting message to the LCD.
  lcd.setCursor(2, 0);
  lcd.print("Hello Ella!");
  delay(1000);
  lcd.setCursor(2, 1);
  lcd.print("Want Treats?");
  delay(1000);
  lcd.setCursor(0, 0);
  PRESSBUTTON:lcd.print("Press button");
  lcd.setCursor(0, 1);
  // Clear the bottom LCD row
  lcd.print("                ");
}

void loop() {
  PRESSBUTTON:lcd.clear();
  lcd.print("Press Button");
  delay(50);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin); 
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      lcd.clear();
      lcd.setCursor(5, 0);
      lcd.print("Treat");
      lcd.setCursor(2, 1);
      lcd.print("Dispensing...");
      delay(1000);
      lcd.clear();
      // if the current state is HIGH then the button
      // went from off to on:
      buttonPushCounter++;
      Serial.println("on");
      lcd.setCursor(0, 1);
      lcd.print("Count:");
      lcd.setCursor(6, 1);
      lcd.print(buttonPushCounter);
      int countDown = 6;
      lcd.setCursor(0, 0);
      lcd.print("Countdown:");
      lcd.setCursor(10, 0);
      lcd.print(countDown);
      do
      {
        countDown--;
        lcd.setCursor(10, 0);
        lcd.print(countDown);
        delay(1000);
      } while (countDown > 0);
     goto PRESSBUTTON;
    } else {
      // if the current state is LOW then the button
      // wend from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState = buttonState;

}


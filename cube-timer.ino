#include <Wire.h> //Required Library for communication Arduino Nano With LCD i2c.
#include <LiquidCrystal_I2C.h> //Required Library for usage of LCD i2c.

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD I2C address and size.
const int buttonPin = 2; // Set the push button pin.
bool isRunning = false; // Set the running state variable.
unsigned long startTime = 0; // Set the start time variable.
unsigned long elapsedTime = 0; // Set the elapsed time variable.

void setup() {
  lcd.init(); // Initialize the LCD display.
  lcd.backlight(); // Turn on the LCD backlight.
  lcd.setCursor(0, 0); // Set the cursor position to row 1, column 1.
  lcd.print("Press to Start"); // Display the initial message.
  pinMode(buttonPin, INPUT_PULLUP); // Set the button pin as input with pullup resistor.
}

void loop() {
  if (digitalRead(buttonPin) == LOW) { // If the button is pressed.
    if (!isRunning) { // If the stopwatch is not running.
      isRunning = true; // Set the running state to true.
      startTime = millis(); // Record the start time.
      lcd.clear(); // Clear the LCD display.
      lcd.setCursor(0, 0); // Set the cursor position to row 1, column 1.
      lcd.print("Running..."); // Display the running message.
    } else { // If the stopwatch is running.
      isRunning = false; // Set the running state to false.
      elapsedTime = millis() - startTime; // Calculate the elapsed time.
      lcd.clear(); // Clear the LCD display.
      lcd.setCursor(0, 0); // Set the cursor position to row 1, column 1.
      lcd.print("Time: "); // Display the time label.
      lcd.print(elapsedTime / 1000); // Display the elapsed time in seconds.
      lcd.print(" s"); // Display the time unit.
    }
    delay(100); // Debounce the button.
  }
}

#include<LiquidCrystal_I2C.h>
#include<Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};

Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

LiquidCrystal_I2C lcd(0x20, 4, 5, 6, 0, 1, 2, 3, 7, NEGATIVE);

int getNumber() {
  String numStr = "";
  char key = 0;
  while (true) {
    key = kpd.getKey();
    if (key != NO_KEY) {
      if (key >= '0' && key <= '9') {
        numStr += key;
        lcd.print(key);  // Show the entered digit on the LCD
      } else if (key == '#') {  // Assume '#' is the "enter" key
        break;
      }
    }
    delay(5);
  }
  return numStr.toInt();  // Convert the accumulated string to an integer
}

char getOperation() {
  char key = 0;
  while (key == 0 || (key > 'D' && key < 'A')) { // select only A,B,C or D
    key = kpd.getKey();
    delay(5);
  }
  switch (key) {
    case 'A':
      return '+';
    case 'B':
      return '-';
    case 'C':
      return 'x';
    case 'D':
      return '/';
  }
}

void setup() {
  lcd.begin(16, 2);
  lcd.backlight(); // Ensure the LCD backlight is on
}

void loop() {
  lcd.clear();
  lcd.print("Enter first num");
  lcd.setCursor(0, 1);
  lcd.print("number");
  int num1 = getNumber();

  lcd.clear();
  lcd.print("Enter second num");
  lcd.setCursor(0, 1);
  lcd.print("number");
  int num2 = getNumber();

  lcd.clear();
  lcd.print("Enter operation");
  lcd.setCursor(0, 1);
  lcd.print("A=+ B=- C=x D=/");
  char operation = getOperation();

  int result = 0;
  bool error = false;
  switch (operation) {
    case '+':
      result = num1 + num2;
      break;
    case '-':
      result = num1 - num2;
      break;
    case 'x':
      result = num1 * num2;
      break;
    case '/':
      if (num2 != 0) {
        result = num1 / num2;
      } else {
        error = true;
      }
      break;
  }

  lcd.clear();
  String expression = String(num1) + operation + String(num2) + " = " + String(result);

  if (!error) {
    lcd.print(expression.c_str());
  } else {
    lcd.print("Invalid operation");
  }

   // Scrolling message
  String message = "Press any key to restart";
  int len = message.length();
  while (true) {
    for (int i = 0; i < len; i++) {
      lcd.setCursor(0, 1);
      if (i <= len - 16) {
        lcd.print(message.substring(i, i + 16)); // Print a substring of 16 characters
      } else {
        // Handle the case where the substring length is less than 16 characters
        String displayStr = message.substring(i) + " " + message.substring(0, 16 - (len - i));
        lcd.print(displayStr);
      }
      delay(500); // Adjust delay for scrolling speed
      char key = kpd.getKey();
      if (key != NO_KEY) {
        return; // Exit the loop to restart the process
  }
    }
  }
}

# 18_Basic_calculator_updated

# LCD Keypad Calculator with Scrolling Message

## Overview

This project implements a simple calculator using an LCD display and a keypad. The user can enter two numbers and select an operation (addition, subtraction, multiplication, division), and the result is displayed on the LCD. After displaying the result, a scrolling message prompts the user to press any key to restart the calculation.

## Components

- Arduino Board (e.g., Arduino Uno)
- 16x2 LCD with I2C interface
- 4x4 Keypad
- Connecting wires

## Libraries Used

- `LiquidCrystal_I2C` for interfacing with the I2C LCD.
- `Keypad` for handling keypad input.

## Circuit Diagram

| LCD Pin | Arduino Pin | | Keypad Row/Col | Arduino Pin |
|---------|--------------| |----------------|-------------|
| VCC     | 5V           | | R1             | 2           |
| GND     | GND          | | R2             | 3           |
| SDA     | A4           | | R3             | 4           |
| SCL     | A5           | | R4             | 5           |
|         |              | | C1             | 6           |
|         |              | | C2             | 7           |
|         |              | | C3             | 8           |
|         |              | | C4             | 9           |

## Installation and Setup

1. **Install Arduino IDE**: Ensure you have the Arduino IDE installed on your computer.
2. **Install Required Libraries**: 
   - Open the Arduino IDE.
   - Go to `Sketch -> Include Library -> Manage Libraries`.
   - Search for `LiquidCrystal_I2C` and `Keypad`, then install them.

3. **Connect the Components**:
   - Follow the circuit diagram to connect the LCD and the keypad to the Arduino.
   - Ensure the connections are secure and correct.

4. **Upload the Code**:
   - Open the Arduino IDE.
   - Copy the provided code into the IDE.
   - Select the correct board and port from `Tools -> Board` and `Tools -> Port`.
   - Click on the upload button to upload the code to the Arduino.

## Code Explanation

### Main Functions

1. **getNumber()**:
   - Reads multiple digits from the keypad to form a number.
   - Stops reading when the `#` key is pressed, which acts as an "enter" key.
   
2. **getOperation()**:
   - Waits for a valid operation key (A, B, C, D) to be pressed.
   - Maps keys to operations: A -> `+`, B -> `-`, C -> `x`, D -> `/`.

3. **setup()**:
   - Initializes the LCD and turns on the backlight.

4. **loop()**:
   - Main loop that handles the flow of the calculator.
   - Prompts the user to enter two numbers and an operation.
   - Displays the result or an error message if the operation is invalid (e.g., division by zero).
   - Displays a scrolling message prompting the user to restart the calculation.

### Scrolling Message

- The message "Press any key to restart" scrolls continuously on the LCD.
- The scrolling effect is achieved by displaying substrings of the message.
- If a key is pressed, the loop breaks, and the process restarts.

## Example Usage

1. **Start the Calculator**:
   - Upon powering the Arduino, the LCD prompts to enter the first number.

2. **Enter the First Number**:
   - Use the keypad to enter the digits. Press `#` to confirm the number.

3. **Enter the Second Number**:
   - After the first number is confirmed, the LCD prompts for the second number.
   - Enter the second number and press `#` to confirm.

4. **Select an Operation**:
   - The LCD prompts for an operation (A=+, B=-, C=x, D=/).
   - Press the corresponding key for the desired operation.

5. **View the Result**:
   - The result of the calculation is displayed on the LCD.
   - If there is an error (e.g., division by zero), an error message is displayed.

6. **Restart**:
   - A scrolling message "Press any key to restart" appears.
   - Press any key to restart the calculation process.

## Troubleshooting

- **No Display on LCD**: 
  - Ensure the I2C address is correct. The address in the code is `0x20`. Change it if necessary.
  - Check connections for the SDA and SCL lines.

- **Keypad Not Responding**:
  - Verify connections for the keypad rows and columns.
  - Ensure the keypad library is correctly installed.

## Additional Notes

- The LCD backlight is controlled within the `setup()` function. Ensure it is turned on for better visibility.
- Adjust the scrolling speed by changing the `delay` value in the loop.

## License

This project is open-source and free to use. Feel free to modify and distribute as needed.

---

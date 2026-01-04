# Digital Logic Keypad Lock Using Arduino

## Overview
This project demonstrates a digital logic–based access control system using an Arduino Uno and external TTL logic ICs. A 4×4 matrix keypad is used to enter a 4-bit binary password, which is verified using hardware logic rather than software comparison. The project is designed for academic and learning purposes to understand the integration of embedded systems with digital logic design.

## Description
The system accepts a binary password through a matrix keypad and forwards the entered data to external digital logic circuits using the Arduino as an interface. The password bits are latched using a D flip-flop and compared with a predefined reference code using logic comparison circuitry. Based on the comparison result, the system grants or denies access by controlling a relay, LEDs, and a buzzer.

## Components Used

| Component | Description | Quantity |
|---------|-------------|----------|
| Arduino Uno | Microcontroller board used for control and interfacing | 1 |
| 4×4 Matrix Keypad | Used for entering the binary password | 1 |
| 74175 D Flip-Flop IC | Latches the entered 4-bit data | 1 |
| 74LS85 Comparator IC | Compares input data with reference code | 1 |
| Relay Module | Controls the solenoid lock | 1 |
| Solenoid Lock | Electromechanical locking mechanism | 1 |
| Green LED | Indicates access granted | 1 |
| Red LED | Indicates access denied | 1 |
| Buzzer | Audible alert for incorrect password | 1 |
| Resistors | Current limitin


## Pin Configuration

| Arduino Pin | Connected Component | Purpose |
|------------|--------------------|---------|
| D2 | Keypad Row 1 | Keypad input |
| D3 | Keypad Row 2 | Keypad input |
| D4 | Keypad Row 3 | Keypad input |
| D5 | Keypad Row 4 | Keypad input |
| D6 | Keypad Column 1 | Keypad input |
| D7 | Keypad Column 2 | Keypad input |
| D8 | Keypad Column 3 | Keypad input |
| D9 | Keypad Column 4 | Keypad input |
| A0 | Logic Data Bit 1 | Sends bit to flip-flop |
| A1 | Logic Data Bit 2 | Sends bit to flip-flop |
| A2 | Logic Data Bit 3 | Sends bit to flip-flop |
| A3 | Logic Data Bit 4 | Sends bit to flip-flop |
| A4 | Clock Input | Latches data into flip-flop |
| D13 | Match Output | Reads comparison result |
| A5 | Relay Module | Controls solenoid lock |
| D10 | Green LED | Access granted indication |
| D11 | Red LED | Access denied indication |
| D12 | Buzzer | Audible alert |

## Circuit Diagram
The complete circuit diagram showing the keypad, Arduino Uno, digital logic ICs, relay module, and solenoid lock is provided below.

![Circuit Diagram](https://github.com/GaneshSarode/Digital-Logic-Keypad-Lock/blob/main/Circuit_arduino_Lock.png)

## Working Principle
When a user enters a binary password using the keypad, the Arduino reads each key press and stores the input temporarily. After four bits are entered, the Arduino sends these bits to the D flip-flop and generates a clock pulse to latch the data. The latched output is then compared with a predefined reference code using digital logic hardware. If the comparison result indicates a match, the Arduino activates the relay to unlock the solenoid and turns on the green LED. If the comparison fails, the system activates the red LED and buzzer to indicate access denial.

## Algorithm
The system initializes all input and output devices at startup. It continuously monitors the keypad for user input and accepts only binary digits. After receiving four valid inputs, the data is transmitted to the logic circuit and latched using a clock pulse. The match signal from the logic circuit is then read. Based on this signal, the system either unlocks the door for a fixed duration or triggers an alert before resetting for the next attempt.

## Demonstration Video
A working demonstration of the project is available at the following link:

▶️ (https://drive.google.com/drive/folders/1qFAE0AJx-bJ7SAtpHNI1C4CywPkGX7wV)

## Limitations
This project accepts only binary input and is intended strictly for educational demonstration. It is not designed to provide real-world security and does not include features such as encryption, tamper detection, or user authentication management.

## Future Improvements
The project can be enhanced by adding EEPROM-based password storage, an LCD display for user interaction, a lockout mechanism after multiple failed attempts, or replacing discrete logic gates with more advanced comparator or security ICs.

## Author
Ganesh Sarode

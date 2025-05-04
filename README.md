# Digital Clock with Alarm

## Overview
This project is a simple digital clock with an alarm feature implemented in C. It displays the current time in a 24-hour format and allows the user to set an alarm. When the system time matches the alarm time, the program triggers an alarm sound and displays a message.

## Features
- Displays the current time in real-time.
- Allows the user to set an alarm in 24-hour format.
- Triggers an alarm sound when the set time is reached.
- Displays a message "Alarm is over" after the alarm triggers.
- Cross-platform screen clearing for better compatibility.

## How to Use
1. Compile the program using a C compiler (e.g., GCC or Visual Studio).
2. Run the compiled executable.
3. Follow the prompts to set the alarm time in 24-hour format.
4. The program will display the current time and trigger the alarm when the set time is reached.
5. Press `Ctrl+C` to exit the program at any time.

## Requirements
- A C compiler (e.g., GCC, Visual Studio).
- Windows operating system (for `Beep` and `Sleep` functions).

## Compilation Instructions
1. Open a terminal or command prompt.
2. Navigate to the project directory.
3. Compile the program using the following command:
   ```
   gcc -o output/project.exe project.c -lwinmm
   ```
4. Run the program:
   ```
   output\project.exe
   ```

## Notes
- The program uses `Beep` and `Sleep` functions, which are specific to Windows. For other operating systems, these functions need to be replaced with platform-specific alternatives.
- The screen-clearing function is cross-platform and uses `system("cls")` for Windows and `system("clear")` for other systems.

## Example
### Input:
```
Hour (0-23): 7
Minute (0-59): 30
Second (0-59): 0
```
### Output:
```
Alarm set for 07:30:00
Current Time: 07:29:59
...
***** ALARM! *****
Alarm is over.
Exiting program...
```

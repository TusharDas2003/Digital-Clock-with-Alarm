#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>  // For Sleep() and Beep() on Windows

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void displayCurrentTime() {
    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime); // Get system time
    timeinfo = localtime(&rawtime); // Convert to local time

    printf("Current Time: %02d:%02d:%02d\n", 
           timeinfo->tm_hour, 
           timeinfo->tm_min, 
           timeinfo->tm_sec);
}

int isValidTime(int hour, int minute, int second) {
    return (hour >= 0 && hour <= 23) && (minute >= 0 && minute <= 59) && (second >= 0 && second <= 59);
}

void setAlarmTime(int *hour, int *minute, int *second) {
    while (1) {
        printf("Hour (0-23): ");
        scanf("%d", hour);

        printf("Minute (0-59): ");
        scanf("%d", minute);

        printf("Second (0-59): ");
        scanf("%d", second);

        if (isValidTime(*hour, *minute, *second)) {
            break;
        } else {
            printf("Invalid time entered. Please try again.\n\n");
        }
    }
}

int main() {
    int alarmHour, alarmMinute, alarmSecond;

    printf("===== Digital Clock with Alarm =====\n");
    printf("Set Alarm Time (24-hour format)\n");

    setAlarmTime(&alarmHour, &alarmMinute, &alarmSecond);

    printf("\nAlarm set for %02d:%02d:%02d\n\n", alarmHour, alarmMinute, alarmSecond);

    int alarmTriggered = 0; // Flag to check if alarm has triggered

    while (1) {
        time_t now;
        struct tm *currentTime;

        time(&now);
        currentTime = localtime(&now);

        clearScreen(); // Cross-platform screen clearing
        displayCurrentTime();

        if (!alarmTriggered && currentTime->tm_hour == alarmHour &&
            currentTime->tm_min == alarmMinute &&
            currentTime->tm_sec == alarmSecond) {

            printf("\n***** ALARM! *****\n");
            for (int i = 0; i < 5; i++) {
                Beep(1000, 500); // Frequency, Duration
                Sleep(500);
            }

            printf("\nAlarm is over.\n");
            alarmTriggered = 1; // Set flag to indicate alarm has triggered
        }

        if (alarmTriggered) {
            printf("\nAlarm is over.\n");
            break; // Exit loop after showing the message
        }

        printf("Press Ctrl+C to exit the program at any time.\n");
        Sleep(1000); // Wait 1 second
    }

    printf("Exiting program...\n");
    return 0;
}


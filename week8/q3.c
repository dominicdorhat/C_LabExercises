#include <stdio.h>
#define HOUR 3600
#define MINUTE 60

typedef struct {
    int hours;
    int minutes;
    int seconds;
} time;

time convertTime(int *intPtr);

int main () {
    
    int * intPtr, input;
    intPtr = &input;
    printf("Enter a integer: ");
    scanf("%d", &input);
    time Time = convertTime(intPtr);
    printf("Hour: %d \nMinute: %d\nSecond: %d\n", Time.hours, Time.minutes, Time.seconds);

    
}

time convertTime(int *intPtr) {
    int remainingSeconds;
    time Time;
    Time.hours = *intPtr / (HOUR);
    remainingSeconds = *intPtr - (Time.hours * HOUR);
    Time.minutes = remainingSeconds/MINUTE;
    Time.seconds = remainingSeconds - (Time.minutes * MINUTE);
    return Time;
}
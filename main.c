#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to push a notification
void pushNotify(char* header, char* desc) {
    char args[150];

    // Push notification OS Based
    #if defined (__linux__)
        sprintf(args, "notify-send '%s' '%s'", header, desc);
    #elif defined(__APPLE__) || defined(__MACH__)
        sprintf(args, "osascript -e 'display notification \"%s\" with title \"%s\" sound name \"Glass\"'", desc, header);
    #endif

    system(args);
}

// Function to print a line with a carriage return and clear the line
void printLine(char* line) {
    printf("\r\x1b[2K%s", line);
    fflush(stdout);
}

// Function to print and push notification
void notify(char* header, char* desc) {
    printf("%s\n%s\n\n", header, desc);
    pushNotify(header, desc);
}

// Function to run the focus timer
void runFocus(int state, int focus, int rest, int lrest, int mul, int fsesi) {
    sleep(focus * mul);

    char desc[100];
    if (state == (fsesi * 2 - 2) && state != 0) {
        sprintf(desc, "Now take a long rest. Note: Long Rest %d sec", lrest * mul);
        notify("Thankyou for your focus!", desc);
    } else {
        sprintf(desc, "Now take some rest. Note: Rest %d sec", rest * mul);
        notify("Focus is end!", desc);
    }
}

// Function to run the rest timer
void runRest(int state, int focus, int rest, int lrest, int mul, int fsesi) {
    char desc[100];
    sprintf(desc, "Note: Focus %d sec", focus * mul);

    if (state % (fsesi * 2 - 1) != 0) {
        sleep(rest * mul);
    } else {
        sleep(lrest * mul);
    }

    notify("Rest Times Up!", desc);
}

int main() {
    int focus = 10, rest = 5, lrest = 15, mul = 1, fsesi = 4;
    int state = 0;

    printf("Timer start %d sec!\n\n", focus * mul);

    while (1){
        // timer Focus
        if (state % 2 == 0) {
            runFocus(state, focus, rest, lrest, mul, fsesi);
            state++;
        }

        // timer Rest
        else {
            runRest(state, focus, rest, lrest, mul, fsesi);

            if (state % (fsesi * 2 - 1) != 0) {
                state++;
            } else {
                state = 0;
            }
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to push a notification
void pushNotify(char* header, char* desc) {
    char args[300];

    // Push notification OS Based
    #if defined (__linux__)
        snprintf(args, sizeof(args), "notify-send '%s' '%s'", header, desc);
    #elif defined(__APPLE__) || defined(__MACH__)
        snprintf(args, sizeof(args), "osascript -e 'display notification \"%s\" with title \"%s\" sound name \"Glass\"'", desc, header);
    #endif

    system(args);
}

// Function to clear the screen (i mean terminal)
void clear() {
    printf("\x1b[H\x1b[J");
    fflush(stdout);
}

// Function to print a line with a carriage return and clear the line
void printLine(char* head, char* desc) {
    clear();
    printf("\x1b[2;4H%s\x1b[3;4H%s", head, desc);   // Margin 1 line and 4 spaces
    fflush(stdout);
}

// Function to run the focus timer
void runFocus(int state, int focus, int rest, int lrest, int mul, int fsesi) {
    char desc[100], head[100];

    for (int i = 0; i < focus * mul; i++) {
        sprintf(head, "Note: Focus %d seconds", focus * mul);
        sprintf(desc, "Time elapsed: %d seconds", i);
        printLine(head, desc);
        sleep(1);
    }

    if (state == (fsesi * 2 - 2) && state != 0) {
        sprintf(desc, "Now take a long rest. Note: Long Rest %d sec", lrest * mul);
        pushNotify("Thankyou for your focus!", desc);
    } else {
        sprintf(desc, "Now take some rest. Note: Rest %d sec", rest * mul);
        pushNotify("Focus is end!", desc);
    }
}

// Function to run the rest timer
void runRest(int state, int focus, int rest, int lrest, int mul, int fsesi) {
    char head[100], desc[100];

    if (state % (fsesi * 2 - 1) != 0) {
        for (int i = 0; i < rest * mul; i++) {
            sprintf(head, "Note: Rest %d seconds", rest * mul);
            sprintf(desc, "Time elapsed: %d seconds", i);
            printLine(head, desc);
            sleep(1);
        }
    } else {
        for (int i = 0; i < lrest * mul; i++) {
            sprintf(head, "Note: Long Rest %d seconds", lrest * mul);
            sprintf(desc, "Time elapsed: %d seconds", i);
            printLine(head, desc);
            sleep(1);
        }
    }

    sprintf(desc, "Note: Focus %d sec", focus * mul);
    pushNotify("Rest Times Up!", desc);
}

// TODO: Implement window width with STDIN_FILENO
// Why? cause it can refresh every time the window is resized
// Implement this in printLine function
int windowWidth() {
    return 0;
}

// TODO: Check terminal window size
// Why? Cause if you have terminal width that too small, the output will be cut off
// Implement this in start of the program
void initWindow(){

}

int main() {
    int focus = 10, rest = 5, lrest = 15, mul = 1, fsesi = 4;
    int state = 0;

    clear();

    char desc[100];
    sprintf(desc, "Note: Focus %d sec", focus * mul);
    pushNotify("Focus Start!", desc);

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

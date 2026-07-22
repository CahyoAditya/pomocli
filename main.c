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

// TODO: change current printf with this function
// Function to print a line with a carriage return and clear the line
void printLine(char* line) {
    printf("\r\x1b[2K%s", line);
}

int main() {
    // Here's the variables that define the timer settings
    // 1. focus = Timer for focus
    // 2. rest = Timer for normal rest
    // 3. lrest = Timer for long rest
    // 4. mul = Multiplyer for Timer, the default is 60 cause from minute to second
    // 5. fsesi = Count for long rest (fsesi = 4 means 4 time focus to get long rest)

    int focus = 25, rest = 5, lrest = 15, mul = 1, fsesi = 4;

    int state = 0;
    printf("Timer start %d sec!\n\n", focus * mul);

    while (1){
        // timer Focus
        if (state % 2 == 0) {
            sleep(focus * mul);

            // Logic for long rest
            if (state == (fsesi * 2 - 2) && state != 0) {
                char header[50] = "Thankyou for your focus!";
                char desc[100];
                sprintf(desc, "Now take a long rest. Note: Long Rest %d sec", lrest * mul);

                printf("%s\n%s\n\n", header, desc);
                pushNotify(header, desc);
            }

            // Logic for normal rest
            else {
                char header[50] = "Focus is end!";
                char desc[100];
                sprintf(desc, "Now take some rest. Note: Rest %d sec", rest * mul);

                printf("%s\n%s\n\n", header, desc);
                pushNotify(header, desc);
            }

            state++;
        }

        // timer Rest
        else if (state % 2 != 0) {
            // normal Rest
            if (state % (fsesi * 2 - 1) != 0) {
                sleep(rest * mul);

                char header[50] = "Rest Times Up!";
                char desc[100];
                sprintf(desc, "Note: Focus %d sec", focus * mul);

                printf("%s\n%s\n\n", header, desc);
                pushNotify(header, desc);
                state++;
            }

            // long Rest
            else {
                sleep(lrest * mul);

                char header[50] = "Rest Times Up!";
                char desc[100];
                sprintf(desc, "Note: Focus %d sec", focus * mul);

                printf("%s\n%s\n\n", header, desc);
                pushNotify(header, desc);
                state = 0;
            }
        }
    }

    return 0;
}

#include <stdio.h>
#include <unistd.h>

int main() {
    // focus = Timer for focus
    // rest = Timer for normal rest
    // lrest = Timer for long rest
    // mul = Multiplyer for Timer, the default is 60 cause from minute to second
    // fsesi = Count for long rest (fsesi = 4 means 4 time focus to get long rest)
    int focus = 25, rest = 5, lrest = 15, mul = 1, fsesi = 4;

    int state = 0;
    printf("Timer start %d sec!\n\n", focus * mul);

    while (1){
        // timer Focus
        if (state % 2 == 0) {
            sleep(focus * mul);
            if (state == (fsesi * 2 - 2) && state != 0) printf("Thankyou for your focus! Now take a long rest.\nNote: Long Rest %d sec\n\n", lrest * mul);
            else printf("Focus is end, Now take some rest!\nNote: Rest %d sec\n\n", rest * mul);
            state++;
        }

        // timer Rest
        else if (state % 2 != 0) {
            // normal Rest
            if (state % (fsesi * 2 - 1) != 0) {
                sleep(rest * mul);
                printf("Rest Time's Up!\nNote: Focus %d sec\n\n", focus * mul);
                state++;
            }

            // long Rest
            else {
                sleep(lrest * mul);
                printf("Rest Time's Up!\nNote: Focus %d sec\n\n", focus * mul);
                state = 0;
            }
        }
    }

    return 0;
}

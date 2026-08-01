<div align="center">

# PomoCLI

PomoCLI is a minimalist command-line interface (CLI) Pomodoro Timer application written in C. It is designed to be extremely lightweight and integrates native desktop notifications (Linux & macOS) to help you stay focused and productive.

![Language C](https://img.shields.io/badge/Language-C-00599C?style=flat-square&logo=c&logoColor=white)
![OS Linux](https://img.shields.io/badge/OS-Linux-FCC624?style=flat-square&logo=linux&logoColor=black)
![OS macOS](https://img.shields.io/badge/OS-macOS-000000?style=flat-square&logo=apple&logoColor=white)

</div>

[Screencast_20260730_082947.webm](https://github.com/user-attachments/assets/4a5194c9-cb62-4d5b-8ad3-9f9329980e6c)

## Key Features

- Automatic Pomodoro Loop: Structured cycles consisting of Focus, Short Rest, and Long Rest sessions.
- Native OS Notifications:
  - Linux: Uses the `notify-send` utility.
  - macOS: Uses AppleScript (`osascript`) with the default notification sound.
- Extremely Lightweight: Written in pure C without any external dependencies.


## How the Cycle Works (Default)

By default, the application is configured with the following settings (in seconds/minutes depending on the multiplier `mul`):
- Focus Time: 25 time units (governed by the `focus` variable).
- Short Rest: 5 time units (governed by the `rest` variable).
- Long Rest: 15 time units (governed by the `lrest` variable).
- Session Cycle: After every 4 Focus sessions (governed by the `fsesi` variable), you will get 1 Long Rest session.

To change these settings, you can edit their values in [main.c](main.c#L24). For example, changing the `mul` variable to `60` will convert the time units into minutes. For a detailed guide, please refer to the [Time Customization](#time-customization) section below.


## System Requirements

Before running the application, make sure you have:
1. C Compiler: `gcc` or `clang`.
2. Notification System:
   - Linux: Ensure the `libnotify` package (for `notify-send`) is installed (usually pre-installed on most desktop distributions).
   - macOS: No additional installation needed, as it uses the built-in `osascript` utility.



## Time Customization

If you want to customize the focus duration, rest duration, or the time multiplier (e.g., from seconds to minutes), you can edit the configuration line in [main.c](main.c#L24):

```c
int focus = 25, rest = 5, lrest = 15, mul = 1, fsesi = 4;
```

Variable Explanations:
- `focus`: Focus session duration (default: `25`).
- `rest`: Short rest session duration (default: `5`).
- `lrest`: Long rest session duration (default: `15`).
- `mul`: Time multiplier. Change `mul = 60` to convert the time units above to minutes (default is `1` for seconds to facilitate testing).
- `fsesi`: Number of focus sessions before starting a long rest (default: `4`).

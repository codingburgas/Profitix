[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/u5k3noT3)
<p align = "center">
<img src= "resources/profitix_logo.png" alt="Profitix">
  
<hr>

# <img src= "resources/trophy_icon.png" alt="trophy icon">Our Team
 
### Tsvetan Zhekov - Scrum Trainer
### Nikolai Zhelev - Developer
### Kaloyan Iliev - Developer
### Yuan Tomov - Developer

# <img src= "resources/light-bulb_icon.png" alt="light bulb">About the app

### Profitix is a personal finance manager built in C++ for the Windows Subsystem for Linux (WSL). Using `dialog` with `ncurses` for a text-based interface, it helps users track income, expenses, and budgets. Designed to be simple and efficient, Profitix offers an accessible, console-based solution for managing finances directly from the terminal.

# <img src= "resources/download_dark.png#gh-light-mode-only" alt="download icon"><img src= "resources/download_light.png#gh-dark-mode-only" alt="download icon"> Setup & Installation

#### *These instructions will help you copy and run our project.*

#### *NOTE: This project works natively on Linux as long as the dependencies are met. Debugging on windows requires extra steps*

## <img src= "resources/windows_logo.png" alt="windows logo"> Windows Dependencies:

#### - CMake (Must be installed on both host OS and WSL); CLion (Project does not work on VS2022 due to an unfixed bug);

#### - Windows Subsystem for Linux must be enabled in optionalfeatures;

#### - A WSL distribution (Preferably Ubuntu);

#### *[Here's an in-depth guide on how to install WSL](https://learn.microsoft.com/en-us/windows/wsl/install)*

## <img src= "resources/linux_logo.png" alt="linux logo"> Linux Dependencies (WSL):

#### - cmake gcc clang gdb build-essential dialog make (Install with package manager of your distribution, apt for Ubuntu);

## In CLion, WSL is required as a toolchain and has to be added manually

#### Go to Settings -> Build, Execution, Deployment -> Toolchains and add WSL.

## <img src= "resources/door_icon.png" alt="door icon"> Opening the project

#### - In CLion, Go to Main Menu -> Open and select the CMakeLists.txt file in the 'profitix' directory, and then chose 'Open as Project' in case the Run, Debug and Build options are greyed out.

#### - Go to Run/Debug Configurations and check 'Emulate terminal in the output console', otherwise the TUI won't load correctly

## In Jetbrains CLion, the 'Line height' property  is set to 1.2, making the TUI look choppy:

#### - Go to Settings -> Editor -> Font and set line height to 1.0

## <img src= "resources/hammer_icon.png" alt="hammer icon"> Building the project outside of CLion

#### 1. In a WSL terminal, go to the 'profitix' directory (where the source files are located) and run these commands:

#### 2. cmake .

#### 3. make

#### 4. An executable named 'profitix' should appear. To run it, type:

#### 5. ./profitix

# <img src= "resources/word_logo.png" alt="document icon"> Documentation

### <img src= "resources/word_logo.png" alt="word logo"> [Documentation](https://codingburgas-my.sharepoint.com/:w:/g/personal/tpzhekov22_codingburgas_bg/EY5Xn24vpb9Jm7dZjGcnNgEBEdhi7QtvRrLGRenVdO3HeA?e=DrkBwy)
### <img src= "resources/powerpoint_logo.png" alt="powerpoint logo"> [Presentation](https://codingburgas-my.sharepoint.com/:p:/g/personal/tpzhekov22_codingburgas_bg/EWe4U4ZiMfVEtiA6gaSuwBkBwcewCGP52OkZa6guijc0Tg?e=rih6CA)

# <img src= "resources/laptop_icon.png" alt="laptop icon"> Used Technologies

### Used code editor & collaborative service:
#### [![idk](https://skillicons.dev/icons?i=clion,linux,github,git)](https://skillicons.dev)
### Used technologies for our project development:
#### <img src= "resources/C++_icon_light.png#gh-dark-mode-only" alt="C++ icon"><img src= "resources/C++_icon_dark.png#gh-light-mode-only" alt="C++ icon">
### Used tools for our documentation & presentation & communication:
#### <img src= "resources/word_logo_big.png" alt="word logo"> <img src= "resources/powerpoint_logo_big.png" alt="powerpoint logo"> <img src= "resources/microsoft_teams_logo.png" alt="microsoft teams logo">

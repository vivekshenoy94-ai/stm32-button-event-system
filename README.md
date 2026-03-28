# STM32 Button Event System (State Machine + Timer Debounce)

------------------------------------------------------------------------

## Overview
This project demonstrates a **robust event-driven embedded system**
using:

-   External Interrupts (EXTI) for button detection
-   Timer Interrupts for debounce
-   State Machine for structured control

The system separates **detection, validation, and action**, ensuring
reliable and scalable behavior.

## Hardware Setup
Button → PC13 (EXTI Falling Edge)\
LED → PA5 (Output)\
Timer → TIM2 (\~20 ms debounce)\
MCU → STM32F446RE


## Key Features
Interrupt-driven button handling (EXTI)\
Timer-based debounce handling\
State machine-based control logic\
Clean separation of ISR and main loop\
Deterministic and stable behavior

## System Architecture

EXTI → Detect edge\
↓\
Timer → Debounce validation\
↓\
State Machine → Decision making\
↓\
Main Loop → Action execution

## System Flow
Button Press (PC13)  
→ EXTI Interrupt Triggered \
→ Start Debounce Timer\
→ Timer ISR validates press\
→ State = BUTTON_PRESSED\
→ Main loop processes event\
→ LED Toggle (PA5)



## Advantages
Eliminates button bounce issues\
Stable and deterministic response\
Clean separation of detection and validation

## Considerations
ISR kept minimal\
Debounce handled via timer\
State machine ensures clean transitions\
Main loop must remain non-blocking

## Learning Outcomes
EXTI interrupt handling\
Timer-based debounce\
State machine design\
ISR design best practices\
Debounce using hardware timer\
Event-driven embedded system design


## Author
Vivek Shenoy K\
Embedded SW Architect

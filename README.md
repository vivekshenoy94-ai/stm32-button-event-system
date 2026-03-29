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

## System Evolution

This project evolved through multiple iterations to improve system reliability,
control flow, and architectural clarity.


### Version 1 — Basic State Machine (ISR-Driven)

- Implemented a simple state machine:
  - BUTTON_IDLE
  - BUTTON_PRESSED
- Debounce handled using timer interrupt
- State transitions and actions handled inside ISR

#### Limitations

- Logic tightly coupled inside interrupts
- Hard to scale for complex behaviors
- Difficult to debug and extend
- Violates best practice: heavy ISR processing


### Version 2 — Refactored State Machine (Main-Driven)

- Retained state machine concept but improved structure
- Moved decision-making and actions to main loop
- ISR used only for:
  - Event detection (EXTI)
  - Signal validation (Timer)

#### Improvements

- Clean separation of concerns
- Improved system predictability
- Easier debugging and maintenance
- Scalable for advanced features


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

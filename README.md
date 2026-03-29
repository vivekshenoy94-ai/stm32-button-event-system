# STM32 Button Event System (Debounce + Short/Long Press)

------------------------------------------------------------------------

## Overview
This project demonstrates a **robust event-driven embedded system**
using:

-   External Interrupts (EXTI) for button detection
-   Timer Interrupts for debounce
-   State Machine for structured control
-   Event-driven logic for user interraction

The system separates **detection, validation, and action**, ensuring
reliable and scalable behavior.

## Hardware Setup
- Button → PC13 (EXTI Rising & Falling Edge)
  - External pull-up configuration:
     - Idle state → HIGH  
     - Button Press → LOW (Falling Edge)  
     - Button Release → HIGH (Rising Edge)  
- LED → PA5 (Output)  
- Timer → TIM2 (~20 ms debounce)  
- MCU → STM32F446RE

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

### Version 3 — Event-Driven Architecture with Short & Long Press Handling (Current)

- Introduced event-based behavior:
  - EVENT_SHORT_PRESS
  - EVENT_LONG_PRESS
- Press duration measured using HAL_GetTick()
- Timing starts *after debounce validation*
- Actions triggered only in main loop

#### System Behavior

- *Short Press (< 2000 ms):*
  - LED toggles once
  - Action is triggered exactly once per press

- *Long Press (> 2000 ms):*
  - LED enters continuous toggle mode (non-blocking)
  - Behavior persists until next user interaction

#### Improvements

- Accurate press duration measurement  
- No duplicate or premature triggers  
- Clear separation between *state (validation)* and *event (action)*  
- Supports advanced features like long press  
- Non-blocking behavior for continuous actions

## Key Features
- Interrupt-driven button handling (EXTI)
- Timer-based debounce handling
- State machine-based signal validation
- Event-driven action handling
- Clean separation of ISR and main loop
- Short press detection  
- Long press detection (> 2 seconds)  
- Non-blocking LED behavior
- Deterministic and stable behavior

## System Architecture

EXTI → Detect edge\
↓\
Timer → Debounce validation\
↓\
State Machine → Signal correctness\
↓\
Event Generation (on release)\
↓\
Main Loop → Action execution

## System Flow
Button Press (PC13)\
→ EXTI Interrupt Triggered\
→ Start Debounce Timer\
→ Timer ISR validates press\
→ State = BUTTON_PRESSED\
→ Capture press_start_time

Button Release\
→ Measure press_duration\
→ Classify:\
     < 2000 ms → SHORT PRESS\
     > 2000 ms → LONG PRESS\
→ Generate event

Main Loop\
→ Execute corresponding action


## Advantages
- Eliminates button bounce issues  
- Stable and deterministic response  
- Accurate press duration measurement  
- Clean separation of detection, validation, and action  
- Scalable for advanced input handling

## Considerations
- ISR kept minimal\
- Debounce handled via timer\
- State machine ensures clean transitions\
- Main loop must remain non-blocking

## Learning Outcomes
- EXTI interrupt handling\
- Timer-based debounce\
- State machine design\
- ISR design best practices\
- Debounce using hardware timer\
- Event-driven embedded system design\
- Separation of concerns in embedded systems


## Author
Vivek Shenoy K\
Embedded Software Architect

========================================
PROJECT OVERVIEW
========================================
This project implements a simple finite state machine (FSM) using an Arduino.
The system transitions through four states: INIT, READY, RUN, and FAULT.
Each state represents a different operating mode of the system.

========================================
SYSTEM STATES
========================================
INIT
Initial system startup state. The system performs basic initialization
and then automatically moves to READY.

READY
The system is idle and prepared to start operation. It waits for a valid
user interaction before transitioning to RUN.

RUN
The system is active. If the active state lasts longer than the allowed time,
the system enters the FAULT state.

FAULT
Error state. The system indicates a fault condition and remains in this state
until a manual reset is performed.

========================================
STATE TRANSITIONS
========================================
INIT  -> READY
READY -> RUN
RUN   -> READY
RUN   -> FAULT
FAULT -> INIT

========================================
BEHAVIOR SUMMARY
========================================
The system continuously runs without blocking delays.
State changes are clearly defined and predictable.
Each state is entered and reported only once per transition.

========================================
END OF DOCUMENT
========================================

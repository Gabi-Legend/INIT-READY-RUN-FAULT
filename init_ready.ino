int touch_sensor = 2;
int button = 3;
int RED = 4;
int BLUE = 5;
int GREEN = 6;

enum State {
  INIT,
  READY,
  RUN,
  FAULT
};

State currentState = INIT;
State previousState = FAULT;

unsigned long runStartTime = 0;
unsigned long lastBlinkTime = 0;
bool blinkState = false;

void setColor(bool r, bool g, bool b) {
  digitalWrite(RED, r);
  digitalWrite(GREEN, g);
  digitalWrite(BLUE, b);
}

void setup() {
  pinMode(touch_sensor, INPUT);
  pinMode(button, INPUT_PULLUP);

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int touchVal = digitalRead(touch_sensor);
  bool buttonPressed = (digitalRead(button) == LOW);

  if (currentState != previousState) {
    switch (currentState) {
      case INIT:
        Serial.println("INIT STATE");
        setColor(0, 0, 1);   // albastru
        break;

      case READY:
        Serial.println("READY STATE");
        setColor(0, 1, 0);   // verde
        break;

      case RUN:
        Serial.println("RUN STATE");
        setColor(1, 0, 0);   // rosu
        runStartTime = millis();
        break;

      case FAULT:
        Serial.println("FAULT STATE");
        break;
    }
    previousState = currentState;
  }

  /* ================= FSM LOGIC ================= */

  switch (currentState) {

    case INIT:
      currentState = READY;
      break;

    case READY:
      if (touchVal == HIGH && buttonPressed) {
        currentState = RUN;
      }
      break;

    case RUN:
      if (touchVal == LOW) {
        currentState = READY;
      }

      // RUN prea mult timp → FAULT
      if (millis() - runStartTime > 5000) {
        currentState = FAULT;
      }
      break;

    case FAULT:
      // LED rosu intermitent
      if (millis() - lastBlinkTime > 300) {
        blinkState = !blinkState;
        setColor(blinkState, 0, 0);
        lastBlinkTime = millis();
      }

      // reset din FAULT
      if (buttonPressed) {
        currentState = INIT;
      }
      break;
  }
}

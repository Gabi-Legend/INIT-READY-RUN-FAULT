int touch_sensor = 2;

enum State {
  INIT,
  READY,
  RUN,
  FAULT
};
State currentState = INIT;
bool initPrinted = false;
bool readyPrinted = false;
void setup() {
  pinMode(touch_sensor, INPUT);
  Serial.begin(9600);
}
void loop() {
  int val = digitalRead(touch_sensor);
  if (currentState == INIT) {
    if (!initPrinted) {
      Serial.println("INIT STATE");
      initPrinted = true;
    }
    currentState = READY;
  }
  if (currentState == READY) {
    if (!readyPrinted) {
      Serial.println("READY STATE");
      readyPrinted = true;
    }
    if (val == HIGH) {
      currentState = RUN;
    }
  }
}

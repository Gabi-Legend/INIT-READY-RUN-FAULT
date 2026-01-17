int touch_sensor = 8;

enum State {
  INIT,
  READY,
  RUN,
  FAULT
};

State currentState = INIT;

void setup() {
  pinMode(touch_sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  bool val = digitalRead(touch_sensor);
  switch (currentState) {
    case INIT:
      Serial.println("INIT STATE");
      if(touch_sensor == HIGH){
        currentState = READY;
      }else{
        currentState = FAULT;
      }
      delay(500);
      break;
    case READY:
      Serial.println("READY STATE");
      delay(500)
      break;
    case RUN:
      Serial.println("RUN STATE");
      delay(500)
      break;
    case FAULT:
      Serial.println("FAULT STATE");
      delay(500)
      break;
  }
}

int touch_sensor = 8;

void setup() {
  pinMode(touch_sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  bool val = digitalRead(touch_sensor);
  if(val == HIGH){
    Serial.println(1);
    delay(100);
  } else{
    Serial.println(0);
    delay(100);
  }
}

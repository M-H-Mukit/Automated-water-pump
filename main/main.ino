#define THRESHOLD 30
#define SWITCH A3
#define POWER1 10
#define POWER2 6
#define POWER3 5
#define POWER4 4
#define DEBUGx
#define RUNTIME 25  // minutes

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SWITCH, INPUT_PULLUP);
  pinMode(POWER1, OUTPUT);
  pinMode(POWER2, OUTPUT);
  pinMode(POWER3, OUTPUT);

  pinMode(13, OUTPUT);
  Serial.print("Tesing tank\n");

  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (isPressed()) {

    turnOnMotor();
    DELAYTIMING(RUNTIME);  // delay to keep the motor running
    turnOffMotor();
  }
}

void turnOnMotor() {
  digitalWrite(POWER1, HIGH);
  digitalWrite(POWER2, HIGH);
  digitalWrite(POWER3, HIGH);
  digitalWrite(POWER4, HIGH);
  digitalWrite(13, HIGH);

}

void turnOffMotor() {
  digitalWrite(POWER1, LOW);
  digitalWrite(POWER2, LOW);
  digitalWrite(POWER3, LOW);
  digitalWrite(POWER4, LOW);
  digitalWrite(13, LOW);
}


bool isPressed() {
  int val;
  val = analogRead(SWITCH);

#ifdef DEBUG
  Serial.println(val);
#endif

  if (val < THRESHOLD) {
    delay(100);
    val = analogRead(SWITCH);
#ifdef DEBUG
    Serial.println(val);
#endif
    if (val < THRESHOLD) {
      return true;
    }
  }

  return false;
}

void DELAYTIMING(int t) {
  t = t * 60;
  for (int i = 0; i < t; i++) {
    delay(1000);  // as delay is 1000 mili second use minute value as parameter
  }
}

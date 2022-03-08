#define THRESHOLD 100
#define SWITCH A3
#define POWER 10
#define DEBUGx
#define RUNTIME 25 // minutes

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SWITCH, INPUT_PULLUP);
  pinMode(POWER, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.print("Tesing tank\n");

  delay (2000);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (isPressed()) {
    digitalWrite(POWER, HIGH);
    digitalWrite(13, HIGH);
    DELAYTIMING(RUNTIME); // delay to keep the motor running
    digitalWrite(POWER, LOW);
    digitalWrite(13, LOW);
  }
}

bool isPressed() {
  int val;
  val = analogRead(SWITCH);

#ifdef DEBUG
  Serial.println(val);
#endif

  if (val < THRESHOLD )
    return true;
  else
    return false;
}

void DELAYTIMING (int t)
{
  t = t * 60;
  for (int i = 0; i < t; i++)
  {
    delay(1000); // as delay is 1000 mili second use minute value as parameter
  }
}

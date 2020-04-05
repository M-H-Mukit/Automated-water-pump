#define THRESHOLD 100
#define SWITCH 5
#define POWER 6
#define dealyTiming 2
#define DEBUGx


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SWITCH, OUTPUT);
  pinMode(POWER, OUTPUT);
  Serial.print("Tesing tank\n");

  delay (2000);
}

int MIN = 0, MAX = 0;

int Test = 0;
void loop() {
  // put your main code here, to run repeatedly:
  readSensor();

  if (MIN == 0) {

    //  Serial.println("waiting 2 sec in MIN");

    delay (2000);
    readSensor();

    if (MIN == 0) {

      while (true)
      {
        //        Serial.println("in while swaiting for max");

        analogWrite(SWITCH, 255);
        readSensor ();
        if (MAX == 1 ) {

          //      Serial.println("waiting 2 sec in MAX");
          delay (2000);
          readSensor ();

          if (MAX == 1)
          {
            digitalWrite(SWITCH, LOW);
            break;
          }

        }

      }

    }
  }

}

void readSensor() {
  DELAYTIMING(dealyTiming); // need to change

  int lowLabel , highLabel ;
  digitalWrite(POWER, HIGH);
  lowLabel = analogRead(A5);
  highLabel= analogRead(A4);
  if (lowLabel > THRESHOLD )
    MIN = 1;                /// cafefulll
  else MIN = 0;
  if (highLabel > THRESHOLD )
    MAX = 1;
  else MAX = 0;

#ifdef DEBUG
  Serial.print(MIN);
  Serial.print('\t');
  Serial.print(MAX);
  Serial.print('\t');

  Serial.print(lowLabel);
  Serial.print('\t');
  Serial.println(highLabel);
#endif

}

void DELAYTIMING (int t)
{
  for (int i = 0; i < t; i++)
  {
    delay(1000); // as delay is 1000 mili second use 60 as parameter for 1 minute
  }
}



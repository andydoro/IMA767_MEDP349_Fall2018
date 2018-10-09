
const int ledPin = 3;

int numOfTimes = 1;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  //Serial.print(ledPins[6]);

  for (int i = 0; i < 6; i = i + 1) {
    pinMode(ledPins[i], OUTPUT);
  }
 pinMode(ledPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  // blink some number of times with some delay
  /*
    for (int i = 1; i < numOfTimes; i++) {
      digitalWrite(ledPins[0], HIGH);
      delay(1000 / numOfTimes);
      digitalWrite(ledPins[0], LOW);
      delay(1000 / numOfTimes);
    }
  */

  blinkLED(numOfTimes, 1000 / numOfTimes);

  delay(500);
  Serial.println(numOfTimes);
  numOfTimes++;

}

void blinkLED(int numBlinks, int delayTime) {
  for (int i = 0; i < numBlinks; i++) {
    digitalWrite(ledPin, HIGH);
    delay(delayTime);
    digitalWrite(ledPin, LOW);
    delay(delayTime);
  }
}


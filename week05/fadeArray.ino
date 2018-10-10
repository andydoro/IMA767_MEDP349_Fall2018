int ledPin[6] = {3, 5, 6, 9, 10, 11};
int fadeValue[6] = {0, 51, 102, 153, 204, 255};
int fadeIncrement[6] = {1, 1, 1, 1, 1, -1};

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  // set all to OUTPUT
  for (int i = 0; i < 6; i++) {
    pinMode(ledPin[i], OUTPUT);
  }

  // blink all!
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < 6; i++) {
      digitalWrite(ledPin[i], HIGH);
    }
    delay(200);
    for (int i = 0; i < 6; i++) {
      digitalWrite(ledPin[i], LOW);
    }
    delay(200);
  }

  delay(500);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 6; i++) {
    analogWrite(ledPin[i], fadeValue[i]); // write the values

    fadeValue[i] = fadeValue[i] + fadeIncrement[i]; // increment the values

    if (fadeValue[i] < 1) { // if value goes too low...
      fadeIncrement[i] = 1;
    } else if (fadeValue[i] > 254) { // if value goes too high...
      fadeIncrement[i] = -1;
    }
    Serial.print(fadeValue[i]);
    Serial.print("\t");
  }
  Serial.println("");
  //delay(1);

}


int blinkInterval = 500; // 2HZ
int amplifyTime = 10000; // 10 Seconds

int ledState = LOW;
const int ledPin = 4;
const int pushButton = 2;

unsigned long previousMillis = 0; 
unsigned long pushedAtMillis = 0; 

void setup() {
  
  Serial.begin(9600);
  pinMode(pushButton, INPUT);

}

void loop() {
  int buttonState = digitalRead(pushButton);
  Serial.println(ledState);
  unsigned long currentMillis = millis();

  if (buttonState) {
    pushedAtMillis = currentMillis;
  }

  if (currentMillis - pushedAtMillis <= amplifyTime) {
    if (currentMillis - previousMillis >= blinkInterval) {
      previousMillis = currentMillis;
      ledState = HIGH;
    }
  } else {
      ledState = LOW;
  }

  digitalWrite(ledPin, ledState);
  delay(1);

}

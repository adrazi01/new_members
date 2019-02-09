const int pushButton = 2;
const int trigger = 10;
int pushButtonCounter = 0;
unsigned long previousMillisHigh = 0;
unsigned long previousMillisLow = 0;
const long intervalHigh = 200;
const long intervalLow = 1800;
int lastButtonState = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(pushButton, INPUT);
  pinMode(trigger, OUTPUT);
}

void loop() {
  
  unsigned long currentMillis = millis();
  unsigned long timer = currentMillis;
  
  if (currentMillis - previousMillisHigh >= intervalHigh){
      previousMillisHigh = currentMillis;
      digitalWrite(trigger, LOW);

      if (currentMillis - previousMillisLow >= intervalLow){
        previousMillisLow = currentMillis;
        digitalWrite(trigger, HIGH);
        }
  }
  
  int buttonState = digitalRead(pushButton);

  if (buttonState != lastButtonState){
    if (buttonState == HIGH){
      pushButtonCounter++;
      timer = 0;
    }
  }
  lastButtonState = buttonState;

  if (timer > 8000){
    if (timer < 8005){
      Serial.println(pushButtonCounter);
    }
  }
}

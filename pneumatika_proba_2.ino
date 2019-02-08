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
  
  unsigned long currentMillisHigh = millis();
  unsigned long currentMillisLow = millis();
  unsigned long timer = millis();
  
  if (currentMillisHigh - previousMillisHigh >= intervalHigh){
      previousMillisHigh = currentMillisHigh;
      digitalWrite(trigger, LOW);

      if (currentMillisLow - previousMillisLow >= intervalLow){
        previousMillisLow = currentMillisLow;
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

  if (timer > 8000){    //ako push button nije pritisnut unutar 8 sekundi onda je vjv gotovo
    Serial.println(pushButtonCounter);
    }
}

const int pushButton = 2;
int brojac = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  digitalWrite(10, HIGH);
  delay(200);
  digitalWrite(10, LOW);
  int buttonState = digitalRead(2);
  if (buttonState == HIGH){
    brojac++;
    Serial.println(brojac);
    }

  delay(2000); //RIJESIT OVO I DODAT TXT
}

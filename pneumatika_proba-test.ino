#define INPUT_SENSOR_PIN 2
#define TRIGGER_PIN 10 //use pin for TRIGGER_PIN instead of builtin led

unsigned long previousMillisHigh = 0;
unsigned long previousMillisLow = 0;
const long intervalHigh = 200;
const long intervalLow = 1800;
int pushButtonCounter = 0;
int cycleWithoutButtonInput = 0;

static void IncrementCounter(); //declaration of function to be used in interrupt rutine
bool triggerFlag = false;       // flag when to turn on trigger

void setup()
{
  Serial.begin(9600);

  pinMode(INPUT_SENSOR_PIN, INPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(INPUT_SENSOR_PIN, HIGH);                                               // set internal pulldown
  attachInterrupt(digitalPinToInterrupt(INPUT_SENSOR_PIN), IncrementCounter, RISING); //set interrupt for received button presses
}

void loop()
{

  unsigned long currentMillis = millis();
  unsigned long timer = currentMillis;

  if (currentMillis - previousMillisHigh >= intervalHigh)
  {
    previousMillisHigh = currentMillis;
    if (triggerFlag) //this is here so we avoid unnecessary call of digitalWrite function
    {
      digitalWrite(TRIGGER_PIN, LOW);
      triggerFlag = false;
    }

    if (currentMillis - previousMillisLow >= intervalLow)
    {
      previousMillisLow = currentMillis;
      triggerFlag = true;
      digitalWrite(TRIGGER_PIN, HIGH);
      cycleWithoutButtonInput++;
    }
  }
  if (cycleWithoutButtonInput > 10)
  {
    Serial.println(pushButtonCounter);
  }
}

static void IncrementCounter() //definition of function to be used in interrupt rutine - increment push button counter
{
  pushButtonCounter++;
  cycleWithoutButtonInput = 0;
}

const int BUZZER = 33;
const int GREEN_LED = 25; // TODO put in right PIN
const int RED_LED = 26; // TODO put in right PIN

void setup() {
  // put your setup code here, to run once:

  // LEDs SETUP
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  // BUZZER SETUP
  pinMode(BUZZER, OUTPUT);
  
  // TERMINAL OUTPUT SETUP
  Serial.begin(115200);
  delay(2000);
  Serial.print("ESP32 started");
}

void loop() {
  // put your main code here, to run repeatedly:

  // TURN GREEN AND LED ON
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, HIGH);

  // BUZZING
  tone(BUZZER, 1000); //1kHz
  Serial.print("Buzzzzin");
  delay(1000); //1 sec

  // TURN GREEN AND LED ON
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);

  tone(BUZZER, 100);
  Serial.print("Buzzzzin");
  delay(2000);
}

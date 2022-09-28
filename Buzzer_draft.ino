
const int buzzer = 33;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
  Serial.begin(115200);
  delay(2000);
  Serial.print("ESP32 started");
}

void loop() {
  // put your main code here, to run repeatedly:
 tone(buzzer, 1000); //1kHz
 Serial.print("Buzzzzin");
 delay(1000); //1 sec
 tone(buzzer, 100);
 Serial.print("Buzzzzin");
 delay(2000);
}

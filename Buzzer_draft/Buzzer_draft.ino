
const int buzzerPin = 33;     // pin to which the buzzer is connected

int const pulseSensorPin = 0; // pin to which the pulsemeter is connected
int pulseSignal;              // data received from the pulsemeter
int pulseThreshold = 550;     // threshold that determines, which "tump" to consider as a heartbeat 
int lowerPulse = 600;         // threshold for the lower boundary of the pulse
int higherPulse = 800;        // threshold for the higher boundary of the pulse

int boardLED = 13;            // On-board arduino LED 
int greenLED = 0;             // pin to which the green LED is connected
int redLED = 0;               // pin to which the red LED is connected

int microphonePin = 0;        // pin to which the microphone is connected
int soundThreshold = 100;     // threshold used for averaging the "noisy" sound received from the microphone
int clappingThreshold = 600;  // threshold used to detect if the sound received by the microphone is a clap (or could be something else)

int gameButton = 0;           // pin to which the button used for the mental stimulation game is connected
int lastStateGame = LOW;
int muteButton = 0;           // pin to which the button used for muting the mental stimulation game is connected
int lastStateMute = LOW;

// put your setup code here, to run once:
void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(pulseSensorPin, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(gameButton, INPUT_PULLUP);
  pinMode(muteButton, INPUT_PULLUP);

  Serial.begin(115200);
  delay(2000);
  Serial.print("ESP32 started");

}
// put your main code here, to run repeatedly:
void loop() {
  
  // code used for the pulsemeter
  pulseSignal = analogRead(pulseSensorPin);

  if(pulseSignal > pulseThreshold) {
    Serial.println("Pulse detected: " + pulseSignal);

    if(pulseSignal > higherPulse) {
      digitalWrite(boardLED,HIGH);
      Serial.println("Your pulse is too high: " + pulseSignal);

    } else if(pulseSignal < lowerPulse) {
      digitalWrite(boardLED,LOW);
      Serial.println("Your pulse is too low: " + pulseSignal);
    } 
  } 
  delay(100);

  // code used for the microphone
  long sum = 0;

  for(int i = 0; i < soundThreshold; i++) { // analog-to-digital converter
    sum += analogRead(microphonePin); // detect and store the voltage in the sum
  }

  sum = sum/soundThreshold; // to removed some noise, create an average

  if (sum > clappingThreshold) {  // detects if the sound received from the user is a clap
    Serial.println("A clap was detected");
  } 
  delay(100);

  // code used for the buttons
  currentStateGame = digitalRead(gameButton);
  currentStateMute = digitalRead(muteButton);
  
  if(lastStateGame == LOW && currentStateGame == HIGH) {  // detects if the button is clicked 
    Serial.println("The game button was clicked !!")
    lastStateGame = currentStateGame;    
  }

  if (lastStateMute == LOW && currentStateMute == HIGH) {
     Serial.println("The mute button was clicked !!")
     lastStateMute = currentStateMute
  }
  delay(100);

  // code used for the buzzer
  tone(buzzerPin, 1000);    //1kHz
  Serial.print("Buzzzzin");
  delay(1000);              // wait 1 second
  
  tone(buzzerPin, 100);     // 100 Hz
  Serial.print("Buzzzzin");
  delay(2000);              // wait 2 seconds
}

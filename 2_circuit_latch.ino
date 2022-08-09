

// Define power latch pin  Arduino (Digital 5)
const int powerLatch = 5;

#define LED_PIN 9

void setup() {
  // Define pin as an OUTPUT
  pinMode(powerLatch, OUTPUT); 
  
  // Keeps the circuit on
  
  digitalWrite(powerLatch, HIGH);
  delay(1000);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW );
  delay(1000);
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW );
  delay(1000);
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW );
  
  delay(15000);
  
  // Turns the power latch circuit off
  digitalWrite(powerLatch, LOW);
}

void loop() {

 
}

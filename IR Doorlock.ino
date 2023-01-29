#include <IRremote.h> //Infrared Library

int InfraRedRecievePin = 3;
IRrecv irrecv(InfraRedRecievePin);
decode_results results;

const int RELAY_PIN = 7;  // the Arduino pin, which connects to the IN pin of relay

int locked = 1; //boolean integer represents the locks state. Lock is locked by default

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(RELAY_PIN, OUTPUT);

}

void loop() {
  if (irrecv.decode(&results)) { //Infrared signal has been decoded
    if (locked == 0) { //lock 
      locked = 1;
      digitalWrite(RELAY_PIN, LOW);
    } else { //unlock
      locked = 0;
      digitalWrite(RELAY_PIN, HIGH);
    }
    delay(500);
    irrecv.resume(); // Receive next IR signal (if any)
  }
}
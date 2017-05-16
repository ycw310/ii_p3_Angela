

//Definitions
const int HR_RX = 13;
int ledPin = 12; //05_12_17
byte oldSample, sample;


void setup() {
  Serial.begin(9600);
  pinMode (HR_RX, INPUT);  //Signal pin to input
  pinMode(ledPin, OUTPUT); //define ledPin 12 blink 05_12_17

  Serial.println("Waiting for heart beat...");

  //Wait until a heart beat is detected
  while (!digitalRead(HR_RX)) {};
  Serial.println ("Heart beat detected!");
  

}

void loop()
{

  sample = digitalRead(HR_RX);  //Store signal output
  if (sample && (oldSample != sample))
  {
    Serial.println("Beat");
    digitalWrite(ledPin, HIGH);   // sets the LED on
    delay(500);                  // waits for a second
    digitalWrite(ledPin, LOW);    // sets the LED off
    delay(500);                  // waits for a second

  }
}

  

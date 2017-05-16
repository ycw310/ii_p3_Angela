//Definitions
const int HR_RX = 13;
byte oldSample, sample;
#define SERIAL_PLOTTER  2
static int outputType = SERIAL_PLOTTER;

void setup() {
  Serial.begin(115200);     
  //Serial.begin(9600);
  pinMode (HR_RX, INPUT);  //Signal pin to input
  

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

  }

  oldSample = sample;           //Store last signal received

}


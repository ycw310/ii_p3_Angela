//Definitions
int blinkPin = 13;                // 05_06_17 pin to blink led at each beat
int fadePin = 5;                  // 05_06_17 pin to do fancy classy fading blink at each beat
//int fadeRate = 0;                 // 05_06_17 used to fade LED on with PWM on fadePin
const int HR_RX = 7;
byte oldSample, sample;


void setup() {
  Serial.begin(9600);
  pinMode (HR_RX, INPUT);  //Signal pin to input
  //pinMode(LED13,OUTPUT);  // pin that will blink to your heartbeat! 05/06/17
  pinMode(blinkPin, OUTPUT); // 05_06_17 pin that will blink to your heartbeat!
  pinMode(fadePin, OUTPUT); // 05_06_17 pin that will fade to your heartbeat!


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
//    digitalWrite(LED13,HIGH);
//  }
//  else {
//     digitalWrite(LED13,LOW);                //  Else, the sigal must be below "550", so "turn-off" this LED.

//ledFadeToBeat();                      // Makes the LED Fade Effect Happen
//delay(20);                             //  take a break
//}


//void ledFadeToBeat(){
//   // fadeRate -= 15;                         //  set LED fade value
//    //fadeRate = constrain(fadeRate,0,255);   //  keep LED fade value from going into negative numbers!
//    analogWrite(fadePin,fadeRate);          //  fade LED
//  }




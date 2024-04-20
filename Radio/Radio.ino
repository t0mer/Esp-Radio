
#include <TEA5767.h>



TEA5767 radio = TEA5767();

float frequency = 91.8; //Enter your own Frequency
long baud = 115200; //Enter your own Baudrate for the serial communication
// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

String header;

void setup() {
  //Setup Serial and I2C interface
  Serial.begin(baud);
  Wire.begin();
  
  //Set Frequency to start with
  radio.setFrequency(frequency);
  
  //Print the radio info to the serial monitor
  printFrequency();
  printStereo();
  printSignalLevel();

}

void loop() {

}


void printFrequency(){
  // Print out the frequency
  Serial.print("Frequency: ");
  Serial.println(frequency, 2);
}

void printStereo(){
  // Print out if station transmits in Stereo or Mono
  bool stereo = radio.isStereo();
  Serial.print("Stereo: ");
  Serial.println(stereo);
}

void printSignalLevel(){
  // Print out the signal level
  short level = radio.getSignalLevel();
  Serial.print("Signal (0-15): ");
  Serial.println(level);
}



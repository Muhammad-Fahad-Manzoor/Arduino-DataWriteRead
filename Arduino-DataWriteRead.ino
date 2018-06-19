/*
 SD card Functionality
 The circuit:
 * SD card attached to SPI bus as follows:
 ** 3V3  - 5V  - Black     (3V3 to 5V connection)
 ** CS   - 49  - Yellow    (pin 49 is selected as chip select - can be used any other pin)
 ** MOSI - 51  - Green     (pin 51 belongs  to SPI- master out slave in)
 ** CLK  - 52  - Blue      (pin 50 belongs to SPI - Clock)
 ** MISO - 50  - Red       (pin 50 belongs to SPI - master in slave out)
 ** GND  - GND - Off-white (GND)
 */
#include <SPI.h> // SPI library added for SD-card communication protocol
#include <SD.h>  // SD library added for SD-card feature
#include <Wire.h> // supports wiring

const int chipSelect=49; // pin 49 acts as chip select
File DataReader;         // declare file variable

void setup() {

  #ifndef ESP8266
     while (!Serial);     // will pause Zero, Leonardo, etc until serial console opens
  #endif
  
  // Open serial communications and wait for port to open:
  Serial.begin(115200);

/***************************************SD Feature***************************************************************/
  Serial.println("");
  Serial.println("Initializing SD card...");
 
  // For Mega boards with an Ethernet shield, make sure the **Wiznet chip is not selected**:
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH); // **davekw7x: If it's low, the Wiznet chip corrupts the SPI bus**
 
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) 
  {
    Serial.println("Card failed, or not present");
    Serial.println("       ");
    while (1);
  }
 
  Serial.println("card initialized.");
  Serial.println("       ");
  
  //************************Check for file, open it and perform writing*******************************
  
  // open the file. Note that only one file can be open at a time, so you have to close this one before opening another.
  DataReader = SD.open("writing.txt", FILE_WRITE); // if doesn't find the file, it will create it
  
  // if the file opened okay, write to it:
  if (DataReader) {
    Serial.print("Writing to writing.txt...");
    DataReader.println("hello");
    // close the file:
    DataReader.close();
    Serial.println("");
    Serial.println("File writing is done and file is closed");
    } 
    else {
      // if the file didn't open, print an error:
      Serial.println("error opening test.txt");
    }

//************************re-open the file for reading:*******************************
  Serial.println("");
  DataReader = SD.open("data.txt");
    if (DataReader) 
      {
      Serial.println("reading data.txt...");
      Serial.println("File contains following data");
      Serial.println("");

      // read from the file until there's nothing else in it:
      while (DataReader.available()) 
        {
        Serial.write(DataReader.read());
        }
        Serial.println("");
        // close the file:
        DataReader.close();
        Serial.println("");
        Serial.println("File Reading is done and file is closed");
      } 
    else 
      {
        // if the file didn't open, print an error:
        Serial.println("error opening data.txt");
      }

//********************************************************************************************************//
 }
 

void loop() {
  // nothing happens after setup finishes.
}

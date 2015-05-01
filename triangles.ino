// INTERACTIVE LIGHT DISPLAY IN RESPONSE TO SOUND
// with optional buzzer tones

// By Andrea Kereliuk for Sheridan College IMM, 2014-2015

// Parts:
  // MAX9814 Electret Microphone Amplifier 
    // https://www.adafruit.com/products/1713
  // 4 LEDs
  // DC Buzzer (SPKBZ-221005)  
// With help from the tutorials from:
  // Bill Earl @ Adafruit
    // https://learn.adafruit.com/adafruit-microphone-amplifier-breakout/measuring-sound-levels
  // Starting Electronics
    // http://startingelectronics.com/beginners/circuits/arduino-buzzer/
//

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>

// For the breakout, you can use any 2 or 3 pins
// These pins will also work for the 1.8" TFT shield
#define TFT_CS     10
#define TFT_RST    0  // you can also connect this to the Arduino reset
                      // in which case, set this #define pin to 0!
#define TFT_DC     8

// Option 1 (recommended): must use the hardware SPI pins
// (for UNO thats sclk = 13 and sid = 11) and pin 10 must be
// an output. This is much faster - also required if you want
// to use the microSD card (see the image drawing example)
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);

// Option 2: use any pins but a little slower!
#define TFT_SCLK 13   // set these to be whatever pins you like!
#define TFT_MOSI 11   // set these to be whatever pins you like!
//Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);


const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;
 
int soundVal = 0;           // variable to store the value read


void setup()
{
  Serial.begin(9600);
  Serial.print("Hello! ST7735 TFT Test");

  // Use this initializer if you're using a 1.8" TFT
  tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab

  Serial.println("Initialized");

  uint16_t time = millis();
  tft.fillScreen(ST7735_BLACK);
  time = millis() - time;




  Serial.begin(9600);          //  setup serial
  Serial.println("done");
  delay(1000);
}

void loop()
{

   
   // Use this initializer if you're using a 1.8" TFT
   //tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab

  int color = 0xF800;
  int count = 0;

  //start loop (runs for 1 second each(?)
  for (int16_t i = 0; i < 500; i++) {
    
   //COLLECT VOLTS (SOUND)
   unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level
 
   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;
 
   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      soundVal = analogRead(0);
      if (soundVal < 1024)  // toss out spurious readings
      {
         if (soundVal > signalMax)
         {
            signalMax = soundVal;  // save just the max levels
         }
         else if (soundVal < signalMin)
         {
            signalMin = soundVal;  // save just the min levels
         }
      }
   }
   peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
   double volts = (peakToPeak * 3.3) / 1024;  // convert to volts
   
      Serial.println(volts);
   
   //end volt collection section
    
    //change colours
    color+=50;
    
    //add to count for clearing ability
    count+=1;
    
    //draw triangles
    tft.drawTriangle(tft.width()/2, tft.height()/2, volts*500, volts*100,
      volts*200, volts*500, color);
  
    //clear screen
    if (count >=250) {
      tft.fillScreen(ST7735_BLACK);
      count = 0;
    }
  }
 
}

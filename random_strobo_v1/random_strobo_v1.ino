/*
Ivar Veermäe strobo Linnagaleriisse
Tõnu Tunnel okt 2013
tonu@tonutunnel.com

Pimendatud ruum, kolm akent, kolm strobo.
Kõik strobod plingivad eraldi suvalises rütmis.
Kõige rohkem 15x/sec; kõige vähem 1x/3sec jooksul.

Paralleelne sõltumatu plinkimine tugineb sellele demole : 
http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
*/


//declare constants
#define FLASH 20           // sähvatuse kestus (ms)
#define MIN 100            // minimaalne delay sähvatuste vahel (ms)
#define MAX 3000           // maksimaalne delay sähvatuste vahel (ms)
#define pinYks 3      // esimene TIP -> led
#define pinKaks 4      // teine TIP -> led
#define pinKolm 5      // kolmas TIP -> led

// Variables will change:
int ledState = LOW;             // ledState used to set the LED
long prevMillis1 = 0;        // will store last time LED was updated
long prevMillis2 = 0;
long prevMillis3 = 0;
long random1;              // esimene aken genereeritud delay
long random2;              // teine aken genereeritud delay
long random3;              // kolmas aken genereeritud delay




void setup(){
  Serial.begin(9600);
  randomSeed(analogRead(0));
  
  //genereerime esimesed rändom delay'd
  random1 = random(MIN, MAX);
  random2 = random(MIN, MAX);
  random3 = random(MIN, MAX);
}


//see osa on programmi korduv osa
void loop() { 
  
  
  unsigned long curMillis1 = millis(); 
  unsigned long curMillis2 = millis();
  unsigned long curMillis3 = millis();
  

  
  if(curMillis1 - prevMillis1 > random1) {
    analogWrite(pinYks, 255);
    delay(FLASH);
    analogWrite(pinYks, 0);
    
    Serial.println("random1:");  // for debugging
    Serial.println(random1);
    
    // save the last time you blinked the LED 
    prevMillis1 = curMillis1;   
    //uus rändom delay
    random1 = random(MIN, MAX);
  }
  
    if(curMillis2 - prevMillis2 > random2) {
    analogWrite(pinKaks, 255);
    delay(FLASH);
    analogWrite(pinKaks, 0);
    
    Serial.println("random2:");  // for debugging
    Serial.println(random2);
    
    // save the last time you blinked the LED 
    prevMillis2 = curMillis2;   
    //uus rändom delay
    random2 = random(MIN, MAX);
  }
  
    if(curMillis3 - prevMillis3 > random3) {
    analogWrite(pinKolm, 255);
    delay(FLASH);
    analogWrite(pinKolm, 0);
    
    Serial.println("random3:");  // for debugging
    Serial.println(random3);
    
    // save the last time you blinked the LED 
    prevMillis3 = curMillis3;   
    //uus rändom delay
    random3 = random(MIN, MAX);
  }


  delay(1); // stabiilsuseks 1ms
}



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
#define FLASH 10          // sähvatuse kestus (ms)
#define MIN 10            // minimaalne delay sähvatuste vahel (ms)
#define MAX 1300           // maksimaalne delay sähvatuste vahel (ms)

int led1 = 10;            // arduino klemmid kus küljes led'id on
int led2 = 11;
int led3 = 13;

// Variables will change:
long prevMillis1 = 0;        // will store last time LED was updated
long prevMillis2 = 0;
long prevMillis3 = 0;
long prevMillis4 = 0;
long random1;              // esimene aken genereeritud delay
long random2;              // teine aken genereeritud delay
long random3;              // kolmas aken genereeritud delay
long random4;              // ootamatu delay jaoks




void setup(){
  Serial.begin(9600);
  randomSeed(analogRead(0));
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
  //esialgu kustu:
  analogWrite(led1, 0);
  analogWrite(led2, 0);
  analogWrite(led3, 0);
  
  
//  //genereerime esimesed rändom delay'd
//  random1 = random(MIN, MAX);
//  random2 = random(MIN, MAX);
//  random3 = random(MIN, MAX);
}


//see osa on programmi korduv osa
void loop() { 
  
  
  unsigned long curMillis1 = millis(); 
  unsigned long curMillis2 = millis();
  unsigned long curMillis3 = millis();
  unsigned long curMillis4 = millis();
  random4 = 0;
  
  
  
  if(curMillis1 - prevMillis1 > random1) {
    analogWrite(led1, 255); //põleb
    delay(FLASH);
    analogWrite(led1, 0); //kustu
    
    Serial.println("random1:");  // for debugging
    Serial.println(random1);
    
    // save the last time you blinked the LED 
    prevMillis1 = curMillis1;   
    //uus rändom delay
    random1 = random(MIN, MAX);
  }
  
    if(curMillis2 - prevMillis2 > random2) {
    analogWrite(led2, 255); //põleb
    delay(FLASH);
    analogWrite(led2, 0); //kustu
    
    Serial.println("random2:");  // for debugging
    Serial.println(random2);
    
    // save the last time you blinked the LED 
    prevMillis2 = curMillis2;   
    //uus rändom delay
    random2 = random(MIN, MAX);
  }
  
    if(curMillis3 - prevMillis3 > random3) {
    analogWrite(led3, 255); //põleb
    delay(FLASH);
    analogWrite(led3, 0); //kustu
    
    Serial.println("random3:");  // for debugging
    Serial.println(random3);
    
    // save the last time you blinked the LED 
    prevMillis3 = curMillis3;   
    //uus rändom delay
    random3 = random(MIN, MAX);
  }
  
    
   random4 = random(2200, 3000);
   if(curMillis4 - prevMillis4 > 15000) {
    delay(random4);
    Serial.println("randomDELAY:");  // for debugging
    Serial.println(random4);
    prevMillis4 = curMillis4;
    random4 = 0;
  }
 


  delay(1); // stabiilsuseks 1ms
}



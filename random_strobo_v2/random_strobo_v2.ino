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

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
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
long prevMillis5 = 0;
long random1;              // esimene aken genereeritud delay
long random2;              // teine aken genereeritud delay
long random3;              // kolmas aken genereeritud delay
long random4;              // ootamatu delay jaoks
long random5;              // random case



//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
void setup(){
  Serial.begin(9600);
  randomSeed(analogRead(0));      // more random due to analogPin voltage fluctuation
  
  random1 = random(MIN, MAX);
  random2 = random(MIN, MAX);
  random3 = random(MIN, MAX);
  random4 = random(2200, 3000);  //random delay
  random5 = random(1,3);         //random case
  
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


//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//see osa on programmi korduv osa
void loop() { 
  
  unsigned long curMillis1 = millis(); 
  unsigned long curMillis2 = millis();
  unsigned long curMillis3 = millis();
  unsigned long curMillis4 = millis();
  unsigned long curMillis5 = millis();

  
  
  
  Serial.println("RANDOM-CASE");
  Serial.println(random5);
  
  switch (random5) {
  case 1:
    // statements
    break;
  case 2:
    // statements
    break;
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



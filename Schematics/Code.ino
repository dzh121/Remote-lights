#include <IRremote.h>
#include <FastLED.h>


#define LED_PIN     8
#define NUM_LEDS    300

#define ON 0xFFE01F
#define OFF  0XFF609F  
#define BRIGHT DOWN 0XFF20DF
#define BRIGHT UP 0XFFA05F
#define WHITE 0XFFD02F
#define RED 0XFF906F
#define RED1  0XFFB04F
#define RED2  0XFFA857
#define ORANGE  0XFF9867
#define YELLOW  0XFF8877
#define GREEN 0XFF10EF
#define GREEN1 0XFF30CF
#define BLUE  0XFF50AF
#define BLUE1 0XFF708F
#define BLUE2 0XFF28D7
#define BLUE3 0XFF18E7
#define BLUE4 0XFF08F7
#define PURPLE  0XFF6897
#define PURPLE1 0XFF58A7
#define PINK  0XFF48B7
#define FLASH 0XFFF00F
#define STROBE 0xFFE817
#define FADE 0XFFD827
#define smooth 0xFFC837
#define brightnessDown 0xFF20DF
#define brightnessUp 0xFFA05F


int BRIGHTNESS = 255;
#define SATURATION 255  
CRGB leds[NUM_LEDS];
int IRPIN = 2;
IRrecv irrecv(IRPIN);
decode_results result;
int button = 0;
bool b = true;
int y = 0;
int value;
uint8_t hue = 0;

int rr=252;
int gg=0;
int bb=0;
CRGB led[NUM_LEDS];
int s=0;

void setup(){
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

  FastLED.setBrightness(BRIGHTNESS);
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn();
  Serial.println("Enabled IRin");
  
  
  for(int i = NUM_LEDS; i > 0; i--) {
        leds[i] = CRGB ( 0, 0, 0);
        FastLED.show();
      }
  CHSV hsv;
  CRGB rgb;
  Serial.println("ready");
}

void loop() 
{
  if (irrecv.decode(&result)) 
  {
    Serial.print("Value: ");
    Serial.println(result.value, HEX);
    int value = result.value;
    remoteLeds();
    irrecv.resume(); 
  }
}
void remoteLeds(){
  int f = 0;
  y = 0;
  b = true;
  Serial.println(result.value, HEX);
  switch(result.value){
    case brightnessDown:
      if(BRIGHTNESS-50 <= 30){
        FastLED.setBrightness(30);
      }else{
        BRIGHTNESS -= 50;
        FastLED.setBrightness(BRIGHTNESS);
      }
      break;
    case brightnessUp:
      if(BRIGHTNESS+50 >= 255){
        FastLED.setBrightness(255);
      }else{
        BRIGHTNESS += 50;
        FastLED.setBrightness(BRIGHTNESS);
      }
      
      break;
    case ON:
    Serial.println("on");
    for(int i = NUM_LEDS; i >= 0; i--) {
        leds[i] = CRGB ( 255, 0, 0);
        FastLED.show();
      }
      FastLED.show();
      break;
    case OFF:
    Serial.println("off");
      for(int i = NUM_LEDS; i >= 0; i--) {
        leds[i] = CRGB ( 0, 0, 0);
        FastLED.show();
      }
      break;
    case RED:
    Serial.println("red");
      for(int i = NUM_LEDS; i >= 0; i--) {
        leds[i] = CRGB (255, 0, 0);
        FastLED.show();
      }
      break;
    case RED1:
    Serial.println("red1");
      for(int i = NUM_LEDS; i >= 0; i--) {
        leds[i] = CRGB (186,78,61);
        FastLED.show();
      }
      break;
    case RED2:
    Serial.println("red2");
      for(int i = NUM_LEDS; i >= 0; i--) {
        leds[i] = CRGB (167,74,54);
        FastLED.show();
        //delay(40);
      }
      break;
    case ORANGE:
    Serial.println("orange");
      for(int i = NUM_LEDS; i >= 0; i--) {
        leds[i] = CRGB (255,69,0);
        FastLED.show();
        //delay(40);
      }
      break;
    case YELLOW:
    Serial.println("yellow");
      for(int i = NUM_LEDS; i >= 0; i--) {
        leds[i] = CRGB (255,255,0);
        FastLED.show();
      }
      break;
    case GREEN:
    Serial.println("green");
      for(int i = NUM_LEDS; i >= 0; i--) {
        leds[i] = CRGB (0,255,0);
        FastLED.show();
      }
      break;
    case GREEN1:
    Serial.println("green1");
      for(int i = NUM_LEDS; i >= 0; i--) {
        leds[i] = CRGB (36,87,54);
        FastLED.show();
      }
      break;
    case BLUE:
    Serial.println("blue");
      for(int i = NUM_LEDS; i >= 0; i--) {
        leds[i] = CRGB (0,0,255);
        FastLED.show();
      }
      break;
    case BLUE1:
    Serial.println("blue1");
      for(int i = NUM_LEDS; i >= 0; i--) {
        leds[i] = CRGB (38,61,91);
        FastLED.show();
      }
      break;
    case BLUE2:
    Serial.println("blue2");
      for(int i = NUM_LEDS; i >= 0; i--) {
        leds[i] = CRGB (38,61,91);
        FastLED.show();
      }
      break;
    case BLUE3:
    Serial.println("blue3");
      for(int i = NUM_LEDS; i >= 0; i--) {
        leds[i] = CRGB (15,51,73);
        FastLED.show();
      }
      break;
    case BLUE4:
    Serial.println("blue4");
      for(int i = NUM_LEDS; i >= 0; i--) {
        leds[i] = CRGB (15,51,73);
        FastLED.show();
      }
      break;
    case PURPLE:
    Serial.println("purple");
      for(int i = NUM_LEDS; i >= 0; i--) {
        leds[i] = CRGB (239,0,139);
        FastLED.show();
      }
      break;
    case PURPLE1:
    Serial.println("purple1");
      for(int i = NUM_LEDS; i > 0; i--) {
        leds[i] = CRGB (239,0,170);
        FastLED.show();
      }
      break;
    case PINK:
    Serial.println("pink");
      for(int i = NUM_LEDS; i >= 0; i--) {
        leds[i] = CRGB (255, 182, 193);
        FastLED.show();
      }
      break;
    case WHITE:
      Serial.println("white");
      for(int i = NUM_LEDS; i >= 0; i--) {
        leds[i] = CRGB (255,255,255);
        FastLED.show();
      }
      break;
  case FLASH:
   while(1){
      flashs:
      if(b){
        for(int i = NUM_LEDS; i >= 0; i--) {
          leds[i] = CRGB (255, 0, 0);
          FastLED.show();
          delay(40);
          if (irrecv.decode(&result)) {
            f++;
            if (f > 1){
              Serial.println("broke from flash");
              b = false;
              goto flashs;
            }
            irrecv.resume();
          }
        }
        delay(1000);
        for(int i = NUM_LEDS; i >= 0; i--) {
          leds[i] = CRGB (186,78,61);
          FastLED.show();
          delay(40);
          if (irrecv.decode(&result)) {
            f++;
            if (f > 1){
              Serial.println("broke from flash");
              b = false;
              goto flashs;
            }
            irrecv.resume();
          }
        }
        delay(1000);
        for(int i = NUM_LEDS; i >= 0; i--) {
          leds[i] = CRGB (167,74,54);
          FastLED.show();
          delay(40);
          if (irrecv.decode(&result)) {
            f++;
            if (f > 1){
              Serial.println("broke from flash");
              b = false;
              goto flashs;
            }
            irrecv.resume();
          }
        }
      delay(1000);
        for(int i = NUM_LEDS; i >= 0; i--) {
          leds[i] = CRGB (255,69,0);
          FastLED.show();
          delay(40);
          if (irrecv.decode(&result)) {
            f++;
            if (f > 1){
              Serial.println("broke from flash");
              b = false;
              goto flashs;
            }
            irrecv.resume();
          }
        }
      delay(1000);
        for(int i = NUM_LEDS; i >= 0; i--) {
          leds[i] = CRGB (255,255,0);
          FastLED.show();
      delay(40);
      if (irrecv.decode(&result)) {
            f++;
            if (f > 1){
              Serial.println("broke from flash");
              b = false;
              goto flashs;
            }
            irrecv.resume();
          }
        }
      delay(1000);
        for(int i = NUM_LEDS; i >= 0; i--) {
          leds[i] = CRGB (0,255,0);
          FastLED.show();
    delay(40);
    if (irrecv.decode(&result)) {
            f++;
            if (f > 1){
              Serial.println("broke from flash");
              b = false;
              goto flashs;
            }
            irrecv.resume();
          }
        }
        delay(1000);
        for(int i = NUM_LEDS; i >= 0; i--) {
          leds[i] = CRGB (36,87,54);
          FastLED.show();
      delay(40);
      if (irrecv.decode(&result)) {
            f++;
            if (f > 1){
              Serial.println("broke from flash");
              b = false;
              goto flashs;
            }
            irrecv.resume();
          }
        }
      
        for(int i = NUM_LEDS; i >= 0; i--) {
          leds[i] = CRGB (0,0,255);
          FastLED.show();
      delay(40);
      if (irrecv.decode(&result)) {
            f++;
            if (f > 1){
              Serial.println("broke from flash");
              b = false;
              goto flashs;
            }
            irrecv.resume();
          }
        }
      
        for(int i = NUM_LEDS; i >= 0; i--) {
          leds[i] = CRGB (38,61,91);
          FastLED.show();    
          delay(40);
          if (irrecv.decode(&result)) {
            f++;
            if (f > 1){
              Serial.println("broke from flash");
              b = false;
              goto flashs;
            }
            irrecv.resume();
          }
        }
        
        for(int i = NUM_LEDS; i >= 0; i--) {
          leds[i] = CRGB (38,61,91);
          FastLED.show();
    delay(40);
    if (irrecv.decode(&result)) {
            f++;
            if (f > 1){
              Serial.println("broke from flash");
              b = false;
              goto flashs;
            }
            irrecv.resume();
          }
        }
        for(int i = NUM_LEDS; i >= 0; i--) {
          leds[i] = CRGB (15,51,73);
          FastLED.show();
      delay(40);
      if (irrecv.decode(&result)) {
            f++;
            if (f > 1){
              Serial.println("broke from flash");
              b = false;
              goto flashs;
            }
            irrecv.resume();
          }
        }
      
        for(int i = NUM_LEDS; i >= 0; i--) {
          leds[i] = CRGB (15,51,73);
          FastLED.show();
      delay(40);
      if (irrecv.decode(&result)) {
            f++;
            if (f > 1){
              Serial.println("broke from flash");
              b = false;
              goto flashs;
            }
            irrecv.resume();
          }
        }
        
        for(int i = NUM_LEDS; i >= 0; i--) {
          leds[i] = CRGB (239,0,139);
          FastLED.show();
      delay(40);
      if (irrecv.decode(&result)) {
            f++;
            if (f > 1){
              Serial.println("broke from flash");
              b = false;
              goto flashs;
            }
            irrecv.resume();
          }
        }
        
        for(int i = NUM_LEDS; i >= 0; i--) {
          leds[i] = CRGB (128,0,128);
          FastLED.show();
      delay(40);
      if (irrecv.decode(&result)) {
            f++;
            if (f > 1){
              Serial.println("broke from flash");
              b = false;
              goto flashs;
            }
            irrecv.resume();
          }
        }
        
        for(int i = NUM_LEDS; i >= 0; i--) {
          leds[i] = CRGB (255, 182, 193);
          FastLED.show();
      delay(40);
      if (irrecv.decode(&result)) {
            f++;
            if (f > 1){
              Serial.println("broke from flash");
              b = false;
              goto flashs;
            }
            irrecv.resume();
          }
        }
        for(int i = NUM_LEDS; i >= 0; i--) {
          leds[i] = CRGB (255,255,255);
          FastLED.show();
          delay(40);
          if (irrecv.decode(&result)) {
            f++;
            if (f > 1){
              Serial.println(result.value,HEX);
              Serial.println("broke from flash");
              b = false;
              goto flashs;
            }
            irrecv.resume();
          }
      }
      }else{
        break;
      }
    }
    case STROBE:
      while(1){
        STROBES:
        
        if(b){        
          for(int i = NUM_LEDS; i >= 0; i--) {
            leds[i] = CHSV(random8(),255,255);
            if(i+20 > NUM_LEDS){

            }else{
              leds[i+20] = CHSV(random8(),255,255);
              FastLED.show();
            }

            delay(40);
            if (irrecv.decode(&result)) {
              f++;
              if (f > 1){
                Serial.println(result.value,HEX);
                Serial.println("broke from flash");
                b = false;
                goto STROBES;
              }
              irrecv.resume();
            }
          }
        }else{
          break;          
        }
      }
    case FADE:
      while(1){
        FADES:
        int r1 = random(0,255);
        int g1 = random(0,255);
        int b1 = random(0,255);
        int r2 = random(0,255);
        int g2 = random(0,255);
        int b2 = random(0,255);
        int r3 = random(0,255);
        int g3 = random(0,255);
        int b3 = random(0,255);
        int r4 = random(0,255);
        int g4 = random(0,255);
        int b4 = random(0,255);
        int r5 = random(0,255);
        int g5 = random(0,255);
        int b5 = random(0,255);
        int r6 = random(0,255);
        int g6 = random(0,255);
        int b6 = random(0,255);
        int r7 = random(0,255);
        int g7 = random(0,255);
        int b7 = random(0,255);
        int r8 = random(0,255);
        int g8 = random(0,255);
        int b8 = random(0,255);
        int r9 = random(0,255);
        int g9 = random(0,255);
        int b9 = random(0,255);
        int r10 = random(0,255);
        int g10 = random(0,255);
        int b10 = random(0,255);
        if(b){        
          for(int i = NUM_LEDS; i >= 0; i--) {
            leds[i] = CRGB (r1,g1,b1);
            if(i+20 > NUM_LEDS){
                // nothing
            }else{
              leds[i+20] = CRGB (r2,g2,b2);
              FastLED.show();
            }
            if(i-20 < 0){
                // nothing
            }else{
              leds[i-20] = CRGB (r3,g3,b3);
              FastLED.show();
            }
            if(i+50 > NUM_LEDS){
                // nothing
            }else{
              leds[i+50] = CRGB (r4,g4,b4);
              FastLED.show();
            }
            if(i-60 < 0){
                // nothing
            }else{
              leds[i-50] = CRGB (r5,g5,b5);
              FastLED.show();
            }
            if(i-90 < 0){
                // nothing
            }else{
              leds[i-90] = CRGB (r6,g6,b6);
              FastLED.show();
            }
            if(i-120 < 0){
                // nothing
            }else{
              leds[i-120] = CRGB (r7,g7,b7);
              FastLED.show();
            }
            if(i-180 < 0){
                // nothing
            }else{
              leds[i-180] = CRGB (r8,g8,b8);
              FastLED.show();
            }
            if(i-220 < 0){
                // nothing
            }else{
              leds[i-220] = CRGB (r9,g9,b9);
              FastLED.show();
            }
            if(i-260 < 0){
              // nothing
            }else{
              leds[i-260] = CRGB (r10,g10,b10);
              FastLED.show();
            }

            delay(40);
            if (irrecv.decode(&result)) {
              f++;
              if (f > 1){
                Serial.println(result.value,HEX);
                Serial.println("broke from fade");
                b = false;
                goto FADES;
              }
              irrecv.resume();
            }
          }
        }else{
          break;          
        }
      }
    case smooth:
      Serial.println("smooth");
      while(1){
        SMOOTH: 
        if(b){     
          for (int j = 0; j < 255; j++) {
              for (int i = 0; i < NUM_LEDS; i++) {
                leds[i] = CHSV(i - (j * 2), SATURATION, BRIGHTNESS); 
             } 
              FastLED.show();
              delay(25); 
              if (irrecv.decode(&result)) {
                f++;
                if (f > 1){
                  Serial.println(result.value,HEX);
                  Serial.println("broke from SMOOTH");
                  b = false;
                  goto SMOOTH;
                }
                irrecv.resume();

              }
            }   
          }else{
            break;          
          }
    }
    break;
  }
}

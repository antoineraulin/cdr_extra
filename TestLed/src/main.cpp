// #include <Arduino.h>
// #include <FastLED.h>
// #define LED_PIN 5
// #define NUM_LEDS 14
// CRGB leds[NUM_LEDS];

// void setup()
// {
//   // put your setup code here, to run once:
//   pinMode(13, OUTPUT);

//   Serial.begin(9600);

//   FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
// }

// void loop()
// {
//     for (int i = 0; i <= 3; i++)
//     {
//       leds[2 + i] = CRGB(255, 0, 0);
//       leds[6 + i] = CRGB(255, 0, 0);
//       leds[10 + i] = CRGB(255, 0, 0);
//       FastLED.show();
//       delay(50);
//       leds[2 + i] = CRGB(0, 0, 0);
//       leds[6 + i] = CRGB(0, 0, 0);
//       leds[10 + i] = CRGB(0, 0, 0);
//       FastLED.show();
//       delay(50);
//     }
    
  
// }


//Déclaration éléments pour les servos :
#include <Arduino.h>
#include <Servo.h>
Servo myservohaut;
Servo myservobas;

//Déclaration éléments pour les Leds :
#include <FastLED.h>
#define LED_PIN 5
#define NUM_LEDS 14
CRGB leds[NUM_LEDS];

int pos;      // variable to store the servo position
int spe = 2;  //Incrémente position du servo haut
int de = 250; //Delay pour les servos
int val = 0;

//Servo haut : Position plié : 100  Position déplié : 220
//Servo Bas  : Position plié : 90   Position déplié : 10

void Monter()
{

  // for (pos = 100; pos <= 190; pos += spe)
  // {
  //   myservohaut.write(pos);
  //   delay(de);
  // }
  myservohaut.write(180);
  myservobas.write(10);
}

void setup()
{

  pinMode(7, INPUT); // sets the digital pin 7 as input
  pinMode(13, OUTPUT);

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

  


  
  myservohaut.attach(10); // Le servo haut sur le pin 9 de l'Arduino
  myservobas.attach(9);   // Le servo bas au pin 10 de l'Arduino

  myservohaut.write(100); //on reset la position des bras
  myservobas.write(85);
  Serial.begin(9600);
  
  while(digitalRead(7) == HIGH){
    digitalWrite(13, HIGH);
    delay(50);
    digitalWrite(13, LOW);
    delay(50);
  }
}

void loop()
{

  // val = digitalRead(2);
  // while (val == HIGH)
  // {
  //   val = digitalRead(2);
  // }

  Monter();

  while (true) //val == LOW
  {
    
    for (int i = -1; i <= NUM_LEDS; i++)
    {
      leds[i + 1] = CRGB(0, 0, 255);
      leds[i + 2] = CRGB(255, 255, 255);
      leds[i + 3] = CRGB(255, 0, 0);
      leds[i] = CRGB(0, 0, 0);

      /*leds[i+10] = CRGB ( 0, 0, 255);
    leds[i+11] = CRGB ( 255, 255, 255);
    leds[i+12] = CRGB ( 255, 0, 0);
    leds[i+9] = CRGB ( 0, 0, 0);*/
      FastLED.show();
      delay(60);
    }
    for (int i = NUM_LEDS; i >= -1; i--)
    {
      leds[i - 2] = CRGB(0, 0, 255);
      leds[i - 1] = CRGB(255, 255, 255);
      leds[i] = CRGB(255, 0, 0);
      leds[i + 1] = CRGB(0, 0, 0);

      /*leds[i-10] = CRGB ( 255, 0, 0);
    leds[i-11] = CRGB ( 255, 255, 255);
    leds[i-12] = CRGB ( 0, 0, 255);
    leds[i-9] = CRGB ( 0, 0, 0);*/
      FastLED.show();
      delay(60);
    }
  }
}


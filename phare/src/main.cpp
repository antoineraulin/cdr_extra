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
  myservohaut.write(178);
  myservobas.write(10);
}

void setup()
{

  pinMode(7, INPUT);   // pin 7 : Main Button
  pinMode(13, OUTPUT); // internal led

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS); //init led strip

  for (int i = 0; i < 14; i++) //reset all leds
  {
    leds[i] = CRGB(0, 0, 0);
  }

  myservohaut.attach(10); // Le servo haut sur le pin 9 de l'Arduino
  myservobas.attach(9);   // Le servo bas au pin 10 de l'Arduino

  myservohaut.write(100); //on reset la position des bras
  myservobas.write(85);

  while (digitalRead(7) == HIGH)
  { // waiting for button switch, blinking internal led
    digitalWrite(13, HIGH);
    delay(50);
    digitalWrite(13, LOW);
    delay(50);
  }
}

void loop()
{

  Monter(); // monte le bras

  while (true) //boucle infini pour les leds
  {

    for (int i = -1; i <= NUM_LEDS; i++)
    {
      leds[i + 1] = CRGB(0, 0, 255);
      leds[i + 2] = CRGB(255, 255, 255);
      leds[i + 3] = CRGB(255, 0, 0);
      leds[i] = CRGB(0, 0, 0);

      FastLED.show();
      delay(60);
    }
    for (int i = NUM_LEDS; i >= -1; i--)
    {
      leds[i - 2] = CRGB(0, 0, 255);
      leds[i - 1] = CRGB(255, 255, 255);
      leds[i] = CRGB(255, 0, 0);
      leds[i + 1] = CRGB(0, 0, 0);

      FastLED.show();
      delay(60);
    }
  }
}

#include <FastLED.h>

#define PIN_LEDS 4
#define PIN_SPINDLE A0
#define PIN_LASER A1
#define PIN_AIR 13
#define PIN_PRESSURE A7
#define PIN_PUMP_ENA 8
#define PIN_PUMP_DIR 7
#define PIN_PUMP_STEP 6

#define NUM_LEDS 3

CRGB leds[NUM_LEDS];


void setup() {
  // Serial
  Serial.begin(115200);

  // LEDs
  FastLED.addLeds<WS2812B, PIN_LEDS, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(255);

  // Spindle
  pinMode(PIN_SPINDLE, OUTPUT);
  digitalWrite(PIN_SPINDLE, LOW);

  // Laser
  pinMode(PIN_LASER, OUTPUT);
  digitalWrite(PIN_LASER, LOW);

  // Air Solenoid
  pinMode(PIN_AIR, OUTPUT);
  digitalWrite(PIN_AIR, LOW);

  // Mist Pump Stepper
  pinMode(PIN_PUMP_ENA, OUTPUT);
  digitalWrite(PIN_PUMP_ENA, HIGH);
  pinMode(PIN_PUMP_DIR, OUTPUT);
  digitalWrite(PIN_PUMP_DIR, LOW);
  pinMode(PIN_PUMP_STEP, OUTPUT);
  digitalWrite(PIN_PUMP_STEP, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Test");

  leds[0] = CRGB::Red;
  leds[1] = CRGB::Green;
  leds[2] = CRGB::Blue;

  FastLED.show();

  digitalWrite(PIN_PUMP_ENA, LOW);
  digitalWrite(PIN_PUMP_DIR, HIGH);
  

  while(0) {
    digitalWrite(PIN_PUMP_STEP, HIGH);
    digitalWrite(PIN_PUMP_STEP, LOW);
    delay(1);
  }


  //digitalWrite(PIN_AIR, 1);
  delay(100);
  int pressure = analogRead(PIN_PRESSURE);
  Serial.println(pressure);
  delay(1000);
  //digitalWrite(PIN_AIR, 0);
  delay(500);
  pressure = analogRead(PIN_PRESSURE);
  Serial.println(pressure);
  delay(1000);

  //delay(1000);
  //digitalWrite(PIN_SPINDLE, 1);
  //delay(200);
  //digitalWrite(PIN_LASER, 1);
  //delay(1000);
  //digitalWrite(PIN_SPINDLE, 0);
  //digitalWrite(PIN_AIR, 0);
  //delay(200);
  //digitalWrite(PIN_LASER, 0);


}

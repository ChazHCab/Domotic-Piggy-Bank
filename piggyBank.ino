//:Oled;
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(128, 64, &Wire, -1);
//:Servo;
#include <Servo.h>
Servo myservo;
//:Distanza;
#include "SR04.h"
SR04 sr04 = SR04(7, 8); //: Echo & Trig;
long valore;
void setup() {
  pinMode(5, OUTPUT); //:ROSSO;
  pinMode(4, OUTPUT); //: VERDE;
  //:Oled;
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 25);
  display.print("WELCOME!!!");
  display.setCursor(0, 45);
  display.setTextSize(1);
  display.print("Made by Charles");
  for (int x = 0; x < 128; x++) {
    display.drawPixel(x, 60, WHITE);
    display.display();
  }
  delay(500);
  display.clearDisplay();
  display.display();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(25, 25);
  display.print("Loading");
  display.display();
  display.setCursor(45, 45);
  delay(1000);
  display.print("$");
  display.display();
  delay(1000);
  display.print("$");
  display.display();
  delay(1000);
  display.print("$");
  display.display();
  display.clearDisplay();
  display.display();
  //:Servo;
  myservo.attach(6);
  //:Monitor Seriale;
  Serial.begin(9600);
}

void loop() {
  //:Distanza;
  valore = sr04.Distance();
  Serial.println(valore);
  if (valore < 9) {
    myservo.write(40);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    //: 1° Parte;
    display.clearDisplay();
    display.fillCircle(65, 10, 20, WHITE);
    display.fillCircle(65, 10, 15, BLACK);
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(58, 0);
    display.print("$");
    display.drawRoundRect(40, 50, 50, 9, 8, WHITE);
    display.display();
    //: 2° Parte;
    delay(500);
    display.clearDisplay();
    display.fillCircle(65, 20, 20, WHITE);
    display.fillCircle(65, 20, 15, BLACK);
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(58, 10);
    display.print("$");
    display.drawRoundRect(40, 50, 50, 9, 8, WHITE);
    display.display();
    //: 3° Parte;
    delay(500);
    display.clearDisplay();
    display.fillCircle(65, 30, 20, WHITE);
    display.fillCircle(65, 30, 15, BLACK);
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(58, 20);
    display.print("$");
    display.drawRoundRect(40, 50, 50, 9, 8, WHITE);
    display.display();
    //: 4° Parte;
    delay(500);
    display.clearDisplay();
    display.fillCircle(65, 35, 20, WHITE);
    display.fillCircle(65, 35, 15, BLACK);
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(58, 25);
    display.print("$");
    display.drawRoundRect(40, 50, 50, 9, 8, WHITE);
    display.display();
    delay(500);
  }
  else {
    myservo.write(0);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(15, 15);
    display.print("INSERIRE");
    display.setCursor(25, 35);
    display.print("MONETA");
    display.display();
  }

}

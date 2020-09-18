#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
//#include <DS3231.h>
#include <DS1307RTC.h>
#include "DHT.h"
#include "hardware_conf.h"

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
//RTClib Time;
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

//variable global
int dataKadarAir = 0;
int dataSuhu;
int dataKelembapan;


void setup() {
  // put your setup code here, to run once:
  //init lcd and RTC
  Wire.begin();
  //lcd.init();
  lcd.backlight();

  //init sensor DHT22
  dht.begin();

  //init button controll
  init_button();

  //LCD OPENING
  lcd.setCursor(0,0);
  lcd.print("SKRIPSI");
  lcd.setCursor(0,1);
  lcd.print("AHMAD MUHAJIR");
  delay(1000);
  lcd.clear();

}

void loop() {
  // put your main code here, to run repeatedly:
  homeScreen();

}

int readDataKadarAir(){
  dataKadarAir = analogRead(pin_soil_moisture);
  dataKadarAir = map(dataKadarAir, 1024, 0, 0, 100);
  
}

int readDataSuhu(){
  dataSuhu = dht.readHumidity();
  return dataSuhu;
}

int readDataKelembapan(){
  dataKelembapan = dht.readTemperature();
  return dataKelembapan;
}

void homeScreen(){
  lcd.clear();
  
//  Datetinme.now = Time.now();
//  lcd.setCursor(0,0);
//  lcd.print(now.hour());
//  lcd.setCursor(3,0);
//  lcd.print(now.minute());
//  lcd.setCursor(6,0);
//  lcd.print(now.second());

  lcd.setCursor(0,1);
  lcd.print("T");
  lcd.setCursor(1,1);
  lcd.print(readDataSuhu());
  lcd.setCursor(3,1);
  lcd.print("C");

  lcd.setCursor(5,1);
  lcd.print("H");
  lcd.setCursor(6,1);
  lcd.print(readDataKelembapan());
  lcd.setCursor(8,1);
  lcd.print("%");

  lcd.setCursor(10,1);
  lcd.print("K");
  lcd.setCursor(11,1);
  lcd.print(readDataKadarAir());
  lcd.setCursor(13,1);
  lcd.print("%");

  delay(1000);
}

void menu(){
 lcd.clear();
 delay(200);
 int menu = 0;
 while (1) {
   if (!button_UP) {
     if (++menu > 1) menu = 0;
     delay(200);
   }
   if (!button_DOWN) {
     if (--menu < 0) menu = 1;
     delay(200);
   }
   switch (menu) {
   case 0:
      lcd.setCursor(0, 0);
      lcd.print("> Test Sensor");
      lcd.setCursor(0, 1);
      lcd.print(" Test Lamp & Pump ");
      if (!button_OK)menuSensor() ;
   break;
   case 1:
      lcd.setCursor(0, 0);
      lcd.print(" View DataIndex");
      lcd.setCursor(0, 1);
      lcd.print("> Scan Sensor ");
      if (!button_OK)menuOutput() ;
   break;
   }
   if (!button_BACK) {
     break;
   }
 }
 lcd.clear();
 delay(200);
}

void menuSensor(){
   lcd.clear();
   delay(200);
   int menu = 0;
   while (1) {
     if (!button_UP) {
       if (++menu > 1) menu = 0;
       delay(200);
     }
     if (!button_DOWN) {
       if (--menu < 0) menu = 1;
       delay(200);
     }
     switch (menu) {
     case 0:
        lcd.setCursor(0, 0);
        lcd.print("> Sensor DHT22");
        lcd.setCursor(0, 1);
        lcd.print(" Sensor Kadar Air ");
        //if (!button_OK)menuSensor() ;
     break;
     case 1:
        lcd.setCursor(0, 0);
        lcd.print(" Sensor DHT22");
        lcd.setCursor(0, 1);
        lcd.print("> Sensor Kadar Air ");
        //if (!button_OK)menuOutput() ;
     break;
     }
     if (!button_BACK) {
       break;
     }
   }
   lcd.clear();
   delay(200);
}

void menuOutput(){
   lcd.clear();
   delay(200);
   int menu = 0;
   while (1) {
     if (!button_UP) {
       if (++menu > 1) menu = 0;
       delay(200);
     }
     if (!button_DOWN) {
       if (--menu < 0) menu = 1;
       delay(200);
     }
     switch (menu) {
     case 0:
        lcd.setCursor(0, 0);
        lcd.print("> Test Lamp");
        lcd.setCursor(0, 1);
        lcd.print(" Test Pump");
        //if (!button_OK)menuSensor() ;
     break;
     case 1:
        lcd.setCursor(0, 0);
        lcd.print(" Test Lamp");
        lcd.setCursor(0, 1);
        lcd.print("> Test Pump");
        //if (!button_OK)menuOutput() ;
     break;
     }
     if (!button_BACK) {
       break;
     }
   }
   lcd.clear();
   delay(200);
}

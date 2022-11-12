/* -----------------------------------------------------------------------------------
   Pin layout should be as follows:
   Signal     Pin              Pin               Pin                  Pin       Pin
            ESP8266          LCD I2C         MFRC522 board          Buzzer      LED
   -----------------------------------------------------------------------------------
   Reset      RST/D8                             RST
   SPI SS     D4                                 SDA
   SPI MOSI   D5                                 MOSI
   SPI MISO   D7                                 MISO
   SPI SCK    D6                                 SCK
   SDA        D2              SDA
   SCL        D1              SCL
   5V         VIN             VIN
   Digital(0/1)D8                                                     D7        D3
   3.3V       3V3                                3.3V
   GND        GND             GND                GND                  GND       GND
*/

#include <Arduino.h>
#include <SPI.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
#include <MFRC522.h>

#define BUTTON_PIN D3
#define SS_PIN D4
#define RST_PIN D8

LiquidCrystal_I2C lcd(PCF8574_ADDR_A21_A11_A01, 20, 4); //PCF8574_ADDR_A21_A11_A01 mereferensikan 0x27 Address (Platform IO)
MFRC522 mfrc522(SS_PIN, RST_PIN);

void saveData(){

}
void rfidRead()
{
}

void rfidSign()
{
}

void lcdSend(int msg)
{
}

void relay()
{
}

void led()
{
}

void buzzer()
{
}

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  EEPROM.begin(4096);

  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.print("................");

  SPI.begin();
  mfrc522.PCD_Init();

  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Please Tag Card");
}

void loop()
{
  // put your main code here, to run repeatedly:
}

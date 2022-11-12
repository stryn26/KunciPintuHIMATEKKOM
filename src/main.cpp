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
#include <StreamUtils.h>

#define BUTTON_PIN D3
#define SS_PIN D4
#define RST_PIN D8

String tmp_data = "";

LiquidCrystal_I2C lcd(PCF8574_ADDR_A21_A11_A01, 20, 4); //PCF8574_ADDR_A21_A11_A01 mereferensikan 0x27 Address (Platform IO)
MFRC522 mfrc522(SS_PIN, RST_PIN);

void saveData(String Data){

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
  // Kode yang digunakan untuk membaca kartu apakah terbaca atau tidak , ketika tidak maka program akan melanjutkan ke awal loop 
  // ini akan mempersingkat proses 
  if ( ! mfrc522.PICC_IsNewCardPresent()) //ini akan memastikkan bahwa ada kartu yang terdeteksi ,
  { 
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) //pada proses ini data akan disimpan sementara
  {
    return;
  }

  Serial.println(F("**Card Detected:**"));
  Serial.println();
  //start block kode uid
  Serial.print(" UID tag :");
  
  //kode yang digunakan untuk menampilkan UID kartu dari mfrc255
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     tmp_data.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ")); // ini akan membangun UID string utuh yang awalnya berbentuk array dari mfrc522
     tmp_data.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  tmp_data.toUpperCase();//membuat data menjadi uppercase
  
  Serial.println();
  //end block kode uid

}

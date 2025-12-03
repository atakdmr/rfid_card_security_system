#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

// --- PINLER ---
#define SS_PIN 10        // RC522 SDA
#define RST_PIN 9        // RC522 RST
#define SERVO_PIN 3      // Kapı kilidi için servo

MFRC522 rfid(SS_PIN, RST_PIN);
Servo lockServo;

// --- YETKİLİ KART UID (Kendi kart UID'ini buraya yazacaksın) ---
byte authorizedCard[4] = {0xDE, 0xAD, 0xBE, 0xEF};

// --- Zaman ayarları ---
int openAngle = 90;   // kapı açık konumu
int closeAngle = 0;   // kapı kapalı konumu
int unlockDuration = 3000; // kapı açık kalma süresi (ms)

// --- SETUP ---
void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();

  lockServo.attach(SERVO_PIN);
  lockServo.write(closeAngle); // başlangıç: kapalı

  Serial.println("RFID Kapı Güvenlik Sistemi Hazır");
}

// --- UID Karşılaştırma Fonksiyonu ---
bool isCardAuthorized(byte *buffer) {
  for (int i = 0; i < 4; i++) {
    if (buffer[i] != authorizedCard[i]) return false;
  }
  return true;
}

// --- LOOP ---
void loop() {
  // Kart okutulmuş mu?
  if (!rfid.PICC_IsNewCardPresent()) return;
  if (!rfid.PICC_ReadCardSerial()) return;

  Serial.print("Kart Okundu! UID: ");

  // UID yazdır
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i], HEX);
    Serial.print(" ");
  }
  Serial.println();

  // Doğrulama
  if (isCardAuthorized(rfid.uid.uidByte)) {
    Serial.println(">> Yetkili Kart — Kapı Açılıyor...");
    lockServo.write(openAngle);
    delay(unlockDuration);
    lockServo.write(closeAngle);
    Serial.println(">> Kapı Kapandı.");
  } else {
    Serial.println(">> Yetkisiz Kart! Kapı Açılmadı.");
  }

  // Temizlik
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}

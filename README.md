# rfid_card_security_system
Bu proje, RC522 RFID okuyucu modülü kullanarak kimlik doğrulama yapan ve doğru kart okutulduğunda servo motor veya röle üzerinden kapı kilidini açan bir güvenli giriş sistemidir. Yetkilendirme, erişim kontrolü ve RFID tabanlı kimlik doğrulama mantığını öğrenmek için ideal bir projedir.

🔧 Özellikler

RC522 RFID Modülü ile kart UID okuma

Yetkili kart doğrulaması (tek veya çoklu kart eklenebilir)

Servo motor ile kapı kilidi açma / kapama

Alternatif olarak röle ile elektronik kilit kontrolü

Seri Monitör üzerinden UID takibi

Basit, anlaşılır, modüler kod yapısı

📌 Kullanılan Donanımlar

Arduino Uno / Nano

RC522 RFID Okuyucu

Servo Motor (SG90 / MG996R vs.) veya Röle Modülü

Breadboard & jumper kablolar

3.3V güç hattı (RFID için)

🧩 Devre Bağlantıları
RC522 → Arduino
RC522 Pin	Arduino
SDA	10
SCK	13
MOSI	11
MISO	12
RST	9
3.3V	3.3V
GND	GND
Servo → Arduino
Servo	Arduino
Sinyal	3
VCC	5V
GND	GND
🛠️ Gereken Kütüphaneler

Arduino IDE üzerinden:
Sketch → Include Library → Manage Libraries

Yükle:

MFRC522

SPI

Servo

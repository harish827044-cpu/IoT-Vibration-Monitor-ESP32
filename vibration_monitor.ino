#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Adafruit_MPU6050 mpu;

const float VIBRATION_THRESHOLD = 15.0;

void setup() {
  Serial.begin(115200);
  
  // OLED Initialization
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("BMS / VIB MONITOR");
  display.display();

  // MPU6050 Initialization
  if (!mpu.begin()) { while (1) yield(); }
  delay(1000);
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  float intensity = sqrt(sq(a.acceleration.x) + sq(a.acceleration.y) + sq(a.acceleration.z));

  // Update OLED Display
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.println("INDUSTRIAL MONITOR");
  display.println("--------------------");
  
  display.setCursor(0, 25);
  display.print("Vib: ");
  display.print(intensity);
  display.println(" m/s2");

  display.setCursor(0, 45);
  if (intensity > VIBRATION_THRESHOLD) {
    display.setTextSize(2);
    display.println("!! ALERT !!");
    Serial.println("CRITICAL VIBRATION!");
  } else {
    display.setTextSize(1);
    display.println("Status: NORMAL");
  }
  
  display.display();
  delay(200);
}
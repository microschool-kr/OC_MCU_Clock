#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
// Date and time functions using a DS3231 RTC connected via I2C and Wire lib
#include "RTClib.h"

RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// 요일, 월, 년을 문자열로 변환하는 함수
String DayMonthYear(uint8_t Day,uint8_t Month,uint16_t Year){
  String DayMonthYearText;
  if (Month==1)  DayMonthYearText="JAN ";
  if (Month==2)  DayMonthYearText="FEB ";
  if (Month==3)  DayMonthYearText="MAR ";
  if (Month==4)  DayMonthYearText="APR ";
  if (Month==5)  DayMonthYearText="MAY ";
  if (Month==6)  DayMonthYearText="JUN ";
  if (Month==7)  DayMonthYearText="JUL ";
  if (Month==8)  DayMonthYearText="AUG ";
  if (Month==9)  DayMonthYearText="SEP ";
  if (Month==10)  DayMonthYearText="OCT ";
  if (Month==11)  DayMonthYearText="NOV ";
  if (Month==12)  DayMonthYearText="DEC ";

  DayMonthYearText=DayMonthYearText+Day;
  if (Day==1)DayMonthYearText=DayMonthYearText+"st ";
  if (Day==2)DayMonthYearText=DayMonthYearText+"nd ";
  if (Day>2)DayMonthYearText=DayMonthYearText+"th ";

  DayMonthYearText=DayMonthYearText+Year;
  
  return DayMonthYearText;
}

// 시, 분, 초를 문자열로 변환하는 함수
String AddLeadingZero(uint8_t x){
  String AddLeadingZeroText;
  if(x<10) AddLeadingZeroText="0"; 
  else AddLeadingZeroText=""; 
  AddLeadingZeroText=AddLeadingZeroText+x;
  return AddLeadingZeroText;
}



void setup () {
  Serial.begin(57600);

#ifndef ESP8266
  while (!Serial); // wait for serial port to connect. Needed for native USB
#endif

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  // When time needs to be re-set on a previously configured device, the
  // following line sets the RTC to the date & time this sketch was compiled
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // This line sets the RTC with an explicit date & time, for example to set
  // January 21, 2014 at 3am you would call:
  // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  display.clearDisplay();
}

void loop () {
	DateTime now = rtc.now();

	display.clearDisplay();

	display.fillRect(0,0,128,15,SSD1306_WHITE);
	display.fillRect(0,17,128,15,SSD1306_BLACK);
	display.fillRect(0,31,128,33,SSD1306_WHITE);

  	display.setCursor(1,1); 
  	display.setTextSize(2);
  	display.setTextColor(SSD1306_BLACK); 
	display.print(daysOfTheWeek[now.dayOfTheWeek()]);

  	display.setCursor(1,18); 
  	display.setTextSize(1);
 	display.setTextColor(SSD1306_WHITE); 
	display.print(DayMonthYear(now.day(),now.month(),now.year()));

  	display.setCursor(3,35); 
  	display.setTextSize(3);  
  	display.setTextColor(SSD1306_BLACK); 
	display.print(AddLeadingZero(now.hour()));
	display.print(":");
	display.println(AddLeadingZero(now.minute()));
	
	display.setCursor(100,35); 
  	display.setTextSize(2);
  	display.setTextColor(SSD1306_BLACK); 
  	display.print(AddLeadingZero(now.second()));
	display.display();
  	// 1초 마다 시간이 바뀌도록 수정 
  	delay(1000); 
}

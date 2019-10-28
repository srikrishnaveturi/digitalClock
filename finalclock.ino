//THIS CODE IS WRITTEN FOR ARDUINO MEGO,FOR UNO CHANGE THE BUZZER PIN FROM 36 TO A PORT FROM 2-13
#include <RTClib.h>
RTC_DS1307 rtc;
int HOUR = 14, MINUTE = 18;     // initialize with you desired time
void setup () {
  while (!Serial); // for Leonardo/Micro/Zero
  Serial.begin(57600);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running");
   
  }
 //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  //rtc.adjust(DateTime(2019, 10, 24, 1, 23, 0));
  pinMode(36, OUTPUT);
}
void loop () {
  DateTime now = rtc.now();
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
  if (now.hour() == HOUR && now.minute() == MINUTE)
  {
    Serial.println("buzzzzzz");
    for(int i = 0;i<10;i++)
    {
    digitalWrite(36, HIGH);
    delay(500);
    digitalWrite(36, LOW);
    delay(500);
    }
  }
  Serial.println();
  delay(1000);
}

#define ozoneTrippedLED 6
#define resetButton 8
#define eepromaddress 0
#include <EEPROM.h>

void setup() {
  Serial.begin(9600);
  pinMode(ozoneTrippedLED, OUTPUT);
  pinMode(resetButton, INPUT);
  //EEPROM.update(eepromaddress, 1);
}

int reset;
int tripped;
int safeLevel = 100;

char buffer[30];
int ozone,temp,hume = 0;

void loop() {

delay(500);


reset = digitalRead(resetButton);
tripped = EEPROM.read(eepromaddress);


digitalWrite(ozoneTrippedLED, tripped);


if (ozone > safeLevel){
  EEPROM.update(eepromaddress, 1);
}

if (reset == HIGH){
  EEPROM.update(eepromaddress, 0);
  Serial.println("reset pushed");

}
Serial.print("tripped ?: ");
Serial.println(tripped);

//Serial.println(Serial.available());
if (Serial.available() >=19) {
    for (int i=0; i<19; i++) {
      buffer[i] = Serial.read();
    }
    Serial.print(buffer);
    char* token = strtok(buffer,",");
    ozone = atoi(token);
    Serial.print("ozone : ");
    Serial.println(ozone);
    token = strtok(NULL,",");
    temp = atoi(token);
    //Serial.print(temp);
    Serial.println();
    token = strtok(NULL,",");
    hume = atoi(token);
    //Serial.print(hume);
    Serial.println();
  }
}

void setup() {
  Serial.begin(9600);
}

int count = 0;
char buffer[30];
void loop() {

int ozone,temp,hume;

//Serial.println(Serial.available());
if (Serial.available() >=19) {
    for (int i=0; i<19; i++) {
      buffer[i] = Serial.read();
    }
    char* token = strtok(buffer,",");
    ozone = atoi(token);
    Serial.print("ozone ppb" + ozone);
    Serial.println();
    token = strtok(NULL,",");
    temp = atoi(token);
    token = strtok(NULL,",");
    hume = atoi(token);

    
  }
}

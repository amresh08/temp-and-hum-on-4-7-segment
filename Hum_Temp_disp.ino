// read the description on this link for pin connection
// https://github.com/amresh08/temp-and-hum-on-4-7-segment/edit/main/README.md
#include <DHT.h>

#define DHTPIN 12
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

unsigned char val[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67};
unsigned char h[] = {0x76,0x40};
void setup() {
  dht.begin();
  DDRD = B11111111; // Setting Port D as output
  pinMode(8, OUTPUT); // D1
  pinMode(9, OUTPUT); // D2
  pinMode(10, OUTPUT); // D3
  pinMode(11, OUTPUT); // D4
  pinMode(12, INPUT); 
  pinMode(13, INPUT);

  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
}

void loop() {
 if( digitalRead(13)==LOW){
   int humidity = dht.readHumidity();
   if (isnan(humidity)) {
     return;
   }
   disph();
   displayNumber(humidity, 2);
   delay(5);
 }
  
 else{
   float temperature = dht.readTemperature();
   if (isnan(temperature)) {
     return;
   }
  int integerPart = (int)temperature;
  float decimalPart = temperature - integerPart; // Calculate the decimal part

  displayNumber(integerPart, 0);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(7,HIGH);
  delay(5);
  displayNumber((int)round(decimalPart * 100), 2); // Round the decimal part and convert to integer
}
}

void displayNumber(int number, int digitOffset) {
  int digit = 0;
  for (int i = 0; i < 2; i++) {
    if (i == 0) {
      digit = number / 10;
    }
    if (i == 1) {
      digit = number % 10;
    }
    // Update only one segment at a time
    digitalWrite(8, (digitOffset + i == 0) ? LOW : HIGH); // D1
    digitalWrite(9, (digitOffset + i == 1) ? LOW : HIGH); // D2
    digitalWrite(10, (digitOffset + i == 2) ? LOW : HIGH); // D3
    digitalWrite(11, (digitOffset + i == 3) ? LOW : HIGH); // D4
    PORTD = val[digit];
    delay(5);
  }
}

void disph(){
  for(int i=0;i<2;i++){
  digitalWrite(8, (i == 0) ? LOW : HIGH);
  digitalWrite(9, (i == 1) ? LOW : HIGH); 
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  PORTD = h[i];
  delay(5);
  }
}

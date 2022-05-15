#include <DHT.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
#define DHTPIN 9
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);

const char BUTTON_PIN=7;
bool pressed = false;
bool prev_state = false;
bool state=false;
int counter=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
  pinMode(BUTTON_PIN,INPUT_PULLUP);
  dht.begin();
}

void loop() { 
  // put your main code here, to run repeatedly:
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  
  String formattedtempF = String(f, 2);
  String formattedtempC = String(t, 2);
  String formattedhumidity = String(h, 2);  
  bool currentstate = digitalRead(BUTTON_PIN);
  if(prev_state != currentstate)
if(state!=currentstate){
  if(currentstate == HIGH){
    if(counter%2==0){
       lcd.clear();
       lcd.setCursor(0,0);
    lcd.print("TEM(F):");
    lcd.print(formattedtempF);
    lcd.print(" EN");
    lcd.setCursor(0,1);
    lcd.print("HUM(%): ");
    lcd.print(formattedhumidity);
      }
    else{
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("SIC(C): ");
        formattedtempC.replace('.',',');
      lcd.print(formattedtempC);
    lcd.print(" TR");
    lcd.setCursor(0,1);
    lcd.print("NEM(%): ");
    formattedhumidity.replace('.',',');
    lcd.print(formattedhumidity);
    }
        counter++;
   
  }
}
 
}


#include <SoftwareSerial.h>
SoftwareSerial HC12(10, 11);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  HC12.begin(9600);
}

void loop()
{
  while(HC12.available())
    Serial.write(HC12.read());
  
  while(Serial.available())
    HC12.write(Serial.read());
}

void a()
{
  static int count = 0;
  Serial.print("(a): {" + String(count++) + "}\n");

  double d = ((double)rand()/RAND_MAX)*5500 + 2500;
  delay(d);
}

void b()
{
  Serial.print("\n(b): ");
  delay(1000);

  if(Serial.available() > 0)
  {
    String input = Serial.readStringUntil('\n');
    if(3 <= input.length() &&
       input.substring(0,5) == "(a): ")
    {
      Serial.print("Got it a: [" + input + "]");
      blink6();
    }
  }

  delay(1000);
}

void blink6()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
}
String voice;
int ledPin = 8;
void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Serial.println("Typw 'on' or 'off' to control LED");
}
void loop()
{
  while (Serial.available())
  {
    delay(10);
    char c = Serial.read();
    voice += c;
  }
  if (voice.length() > 0)
  {
    Serial.println("CReceived: " + voice);
    
    if (voice.indexOf("on") >= 0)
    {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED ON");
    }
    else if (voice.indexOf("off") >= 0)
    {
      digitalWrite(ledPin, LOW);
      Serial.println("LED OFF");
    }
    voice = "";
  }
}
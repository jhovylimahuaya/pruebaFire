
int FOTRESISPin=A0;
int sensorValue = 0;
int PIRPin= 12;
int RELPin1 = 11;
int RELPin2 = 10;
int RELPin3 = 9;
int RELPin4 = 8;


void setup() {
  Serial.begin(9600);
  pinMode(RELPin1, OUTPUT);
  pinMode(RELPin2, OUTPUT);
  pinMode(RELPin3, OUTPUT);
  pinMode(RELPin4, OUTPUT);
  pinMode(PIRPin, INPUT);
}

void loop() {


  {
    if(Serial.available()>0)
    {
      if(Serial.read()=='1')
      {
        digitalWrite(RELPin3, HIGH);
      }
      else{
        digitalWrite(RELPin3, LOW);
      }
    }
  }
  
//Enciende el foco con la ausencia de luz en la fotoresistencia sensor
 sensorValue = analogRead(FOTRESISPin);
 Serial.println(sensorValue);
 if(sensorValue > 600)
 {
   digitalWrite(RELPin1,HIGH);
 }
 else{
  digitalWrite(RELPin1,LOW);
 }

 //Enciende el foco con la deteccion de movimiento
  int value= digitalRead(PIRPin);
  delay(50);
  Serial.println(value);

  if (value == HIGH)
  {
    digitalWrite(RELPin2, HIGH);
    delay(10000);
  }
  else
  {
    digitalWrite(RELPin2, LOW);
  }
 
}

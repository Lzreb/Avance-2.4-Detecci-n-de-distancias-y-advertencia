const int Trigger = 6;   // Pin del Trigger
const int Echo = 5;      // Pin de Echo
const int Buzzer = 4;    // Pin Buzzer

void setup() {
  
// Iniciamos Serial y definimos INPUT y OUTPUT
  Serial.begin(9600);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(Buzzer, OUTPUT);
}

void loop() {
  digitalWrite(Trigger, LOW);
  delayMicroseconds(2);
  
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);

  // Medición de distancia en base al tiempo de espera
  long t = pulseIn(Echo, HIGH);
  long d = t / 59;

  // Comunica la distancia en el Serial
  Serial.print(d);
  Serial.print(" cm");
  Serial.println();

  // Activación del Buzzer en base a la distancia
  if (d > 0 && d < 50) {
    // Tono del Buzzer
    tone(Buzzer, 2500); 
    delay(30);                     
    noTone(Buzzer); 
    delay(d * 10);                 
  } else {
    noTone(Buzzer);
    delay(50);                     
  }
}
// inclui biblioteca servo
#include <Servo.h>. 
// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int trigPin = 10;
const int echoPin = 11;
// varaivel para duração e distancias
long duration;
int distance;
Servo myServo; // cria o objeto servo motor para ser usado
void setup() {
  const int pinoBuzzer = 2; //PINO DIGITAL EM QUE O BUZZER ESTÁ CONECTADO
  pinMode(trigPin, OUTPUT); // define pino entrada
  pinMode(echoPin, INPUT); // define pino saida
  Serial.begin(9600);
  myServo.attach(12); // define em qual pino o servo ta preso
}
void loop() {
  // rgira o servo de 15 a 165 graus
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();// função que mede a distancia 
  
  Serial.print(i); // envia o angulo para a porta seria
  Serial.print(","); // carater usado apra separar as informações enviadas
  Serial.print(distance); // envia a distancia para a porta serial
  Serial.print("."); // carater usado  para separar as informações enviadas
  }
  // repete as linhas de 15 a 165 graus
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
  
}




// função que calcula a distancia através do sensor ultrasonico
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // le o pino do sensor para saber a distancia
  distance= duration*0.034/2;
  return distance;
}

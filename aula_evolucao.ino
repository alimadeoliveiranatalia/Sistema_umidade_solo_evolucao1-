// Programa: Monitoramento de umidade do solo com leds alertas e aviso sonoro.
// Autor: Álacy Serrão e Natália Lima 

#define sensor_umidade A0
#define alerta_vermelho 5
#define alerta_amarelo 6
#define alerta_verde 7
#define alerta_som 8 

int valor_sensor;

void setup() {
 

  pinMode(sensor_umidade, INPUT);
  pinMode(alerta_vermelho, OUTPUT);
  pinMode(alerta_amarelo, OUTPUT);
  pinMode(alerta_verde, OUTPUT);
  pinMode(alerta_som, OUTPUT);

}

   
void loop() {

valor_sensor = analogRead(sensor_umidade);

if(valor_sensor > 800 && valor_sensor < 1024 ){
  // Terra Seca
  digitalWrite(alerta_vermelho, HIGH);
  digitalWrite(alerta_amarelo, LOW);
  digitalWrite(alerta_verde, LOW); 
  tone(alerta_som, 200); 
}

 if(valor_sensor > 400 && valor_sensor < 800 ){
  // Terra umida moderada
  digitalWrite(alerta_amarelo, HIGH);
  digitalWrite(alerta_vermelho, LOW);
  digitalWrite(alerta_verde, LOW);
  noTone() // para desligar o Buzzer
  
}

if(valor_sensor < 400 ){
  // Terra bem umida
  digitalWrite(alerta_verde, HIGH);
  digitalWrite(alerta_amarelo, LOW);
  digitalWrite(alerta_vermelho, LOW);
 noTone() // para desligar o Buzzer
  
}
  


delay(1000);

  

}

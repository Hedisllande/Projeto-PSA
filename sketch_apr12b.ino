// Define os pinos utilizados
const int sensor1Pin1 = 13; // Sensor 1 - Pino 13
const int sensor1Pin2 = 12; // Sensor 2 - Pino 12
const int eletrovalvula1Pin = 10; // Eletrovalvula 1 - Pino 10
const int eletrovalvula2Pin = 9; // Eletrovalvula 2 - Pino 9
const int motorPin = 2; // Motor - Pino 2
const int botao1Pin = 0; // Botão 1 - Pino 0
const int botao2Pin = 1; // Botão 2 - Pino 1

// Variáveis para contar a ativação dos sensores
int contadorSensor1 = 0;
int contadorSensor2 = 0;
int estado_botao1; // Variável para armazenar o estado do pino 0
int estado_botao2; // Variável para armazenar o estado do pino 1

void setup() {
  // Define os pinos como entrada ou saída
  pinMode(sensor1Pin1, INPUT);
  pinMode(sensor1Pin2, INPUT);
  pinMode(eletrovalvula1Pin, OUTPUT);
  pinMode(eletrovalvula2Pin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(botao1Pin, INPUT);
  pinMode(botao2Pin, INPUT);
}

void loop() {
 // Armazena o estado do pino 0
  estado_botao1 = digitalRead(botao1Pin);
  
 // Armazena o estado do pino 1
  estado_botao2 = digitalRead(botao2Pin);
  

  // Verifica se o pino 0 está ativo
 if (digitalRead(estado_botao1) == HIGH) {
    digitalWrite(motorPin, HIGH); // Ativa o pino 2
  } else {
    digitalWrite(motorPin, LOW); // Desativa o pino 2
  }
  
  // Verifica se o pino 1 está ativo
  if (digitalRead(estado_botao2) == HIGH) {
    digitalWrite(motorPin, LOW); // Desativa o pino 2
  }


  // Verifica se o sensor 1 foi ativado
  if (digitalRead(sensor1Pin1) == HIGH) {
    contadorSensor1++; // Incrementa o contador
    if (contadorSensor1 == 6) {
      digitalWrite(eletrovalvula1Pin, HIGH); // Ativa a eletrovalvula 1
      contadorSensor1 = 0; // Reinicia o contador
    }
  }

  // Verifica se o sensor 2 foi ativado
  if (digitalRead(sensor1Pin2) == HIGH) {
    contadorSensor2++; // Incrementa o contador
    if (contadorSensor2 == 6) {
      digitalWrite(eletrovalvula2Pin, HIGH); // Ativa a eletrovalvula 2
      contadorSensor2 = 0; // Reinicia o contador
    }
  } 

  // Verifica se ambas as eletrovalvulas estão ativas
  if (digitalRead(eletrovalvula1Pin) == HIGH && digitalRead(eletrovalvula2Pin) == HIGH) {
    digitalWrite(motorPin, LOW); // Desativa os motores
  } else {
    digitalWrite(motorPin, HIGH); // Ativa os motores
  }

}

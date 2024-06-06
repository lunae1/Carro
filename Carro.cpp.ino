// Carro.cpp
#include "Carro.h"

Carro::Carro(int en1, int in1, int in2, int en2, int in3, int in4, int btRx, int btTx) 
  : _EN1(en1), _IN1(in1), _IN2(in2), _EN2(en2), _IN3(in3), _IN4(in4), _bluet(btRx, btTx) {
  _cont = 0;
  _PWM = 200;
}

void Carro::iniciar() {
  Serial.begin(9600);
  _bluet.begin(9600);

  pinMode(_EN1, OUTPUT);
  analogWrite(_EN1, _PWM);
  pinMode(_IN1, OUTPUT);
  pinMode(_IN2, OUTPUT);

  pinMode(_EN2, OUTPUT);
  analogWrite(_EN2, _PWM);
  pinMode(_IN3, OUTPUT);
  pinMode(_IN4, OUTPUT);
}

void Carro::procesarComando() {
  while (_bluet.available()) {
    char myChar = _bluet.read();
    Serial.print(myChar);

    if (myChar == 'X') {
      cambioVelocidad();
    } else if (myChar == 'O') {
      girar();
    } else if (myChar == 'F' || myChar == 'U') {
      adelante();
    } else if (myChar == 'B' || myChar == 'D') {
      atras();
    } else if (myChar == 'L') {
      izquierda();
    } else if (myChar == 'R') {
      derecha();
    } else if (myChar == 'p' || myChar == 'S') {
      parar();
    }
  }
}

void Carro::cambioVelocidad() {
  _cont++;
  if (_cont == 1) {
    _PWM = 200;
  } else if (_cont == 2) {
    _PWM = 230;
  } else if (_cont == 3) {
    _PWM = 255;
    _cont = 0;
  }
  analogWrite(_EN1, _PWM);
  analogWrite(_EN2, _PWM);
}

void Carro::adelante() {
  Serial.print("Adelante");
  digitalWrite(_IN1, HIGH);
  digitalWrite(_IN2, LOW);
  digitalWrite(_IN3, LOW);
  digitalWrite(_IN4, HIGH);
}

void Carro::atras() {
  Serial.print("Atras");
  digitalWrite(_IN1, LOW);
  digitalWrite(_IN2, HIGH);
  digitalWrite(_IN3, HIGH);
  digitalWrite(_IN4, LOW);
}

void Carro::izquierda() {
  Serial.print("Izquierda");
  digitalWrite(_IN1, LOW);
  digitalWrite(_IN2, LOW);
  digitalWrite(_IN3, LOW);
  digitalWrite(_IN4, HIGH);
}

void Carro::derecha() {
  Serial.print("Derecha");
  digitalWrite(_IN1, HIGH);
  digitalWrite(_IN2, LOW);
  digitalWrite(_IN3, LOW);
  digitalWrite(_IN4, LOW);
}

void Carro::parar() {
  Serial.print("Detenido");
  digitalWrite(_IN1, LOW);
  digitalWrite(_IN2, LOW);
  digitalWrite(_IN3, LOW);
  digitalWrite(_IN4, LOW);
}

void Carro::girar() {
  digitalWrite(_IN1, HIGH);
  digitalWrite(_IN2, LOW);
  digitalWrite(_IN3, HIGH);
  digitalWrite(_IN4, LOW);
  delay(1000);
}

// ProgramaPrincipal.ino
#include "Carro.h"

// Pines Motores y Bluetooth
int EN1 = 9;    // PWM
int IN1 = 8;
int IN2 = 7;

int EN2 = 3;    // PWM
int IN3 = 6;
int IN4 = 10;

int btRx = 4;
int btTx = 5;

// Crear objeto Carro
Carro miCarro(EN1, IN1, IN2, EN2, IN3, IN4, btRx, btTx);

void setup() {
  miCarro.iniciar();
}

void loop() {
  miCarro.procesarComando();
}

// ProgramaPrincipal.ino
#include "Carro.h"

// Pines Motores y Bluetooth
int EN1 = 9;    // PWM
int IN1 = 8;
int IN2 = 7;

int EN2 = 3;    // PWM
int IN3 = 6;
int IN4 = 10;

int BT_RX = 4;
int BT_TX = 5;

// Crear objeto Carro
Carro miCarro(EN1, IN1, IN2, EN2, IN3, IN4, BT_RX, BT_TX);

void setup() {
  miCarro.iniciar();
}

void loop() {
  miCarro.procesarComando();
}

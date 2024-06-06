// Carro.h
#ifndef Carro_h
#define Carro_h

#include <Arduino.h>
#include <SoftwareSerial.h>

class Carro {
  public:
    Carro(int en1, int in1, int in2, int en2, int in3, int in4, int btRx, int btTx);
    void iniciar();
    void procesarComando();
    void cambioVelocidad();
    void adelante();
    void atras();
    void izquierda();
    void derecha();
    void parar();
    void girar();
    
  private:
    int _EN1, _IN1, _IN2, _EN2, _IN3, _IN4;
    int _cont;
    int _PWM;
    SoftwareSerial _bluet;
};

#endif

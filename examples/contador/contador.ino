#include <MatrizLed.h>

/*
 * Contador con varias pantallas
 */

MatrizLed pantalla;
int contador = 0;

void setup() {
  pantalla.begin(12, 11, 10, 2); // dataPin, clkPin, csPin, numero de matrices de 8x8
}

void loop() { 
  pantalla.borrar();
  pantalla.escribirCifra(contador);
  contador++;
  delay(1000);
}

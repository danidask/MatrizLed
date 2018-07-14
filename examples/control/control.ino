#include <MatrizLed.h>

/*
 * Contola aspectos de la pantalla, como intensidad, ecendido, apagado
 */

MatrizLed pantalla;

void setup() {
  pantalla.begin(12, 11, 10, 2); // dataPin, clkPin, csPin, numero de matrices de 8x8
  pantalla.setIntensidad(12); // intensidad entre 0 y 15 (maximo brillo)
  pantalla.escribirFrase("XX");
}

void loop() { 
  delay(1000);
  pantalla.apagar(); // Apaga la pantalla (consume menos energia)
  delay(1000);
  pantalla.encender();
}

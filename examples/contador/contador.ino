#include <MatrizLed.h>

/*
 * Contador con varias pantallas
 */

MatrizLed pantalla;
int contador = 0;
char salida[3]; // Array donde se almacenará el valor formateado (dos caracteres mas fin de linea)

void setup() {
  pantalla.begin(12,11,10,2); // dataPin, clkPin, csPin, numero de matrices de 8x8
}

void loop() { 
  pantalla.borrar();
  sprintf(salida, "%2d", contador); // guardamos el valor del contador, formateado con dos espacios, como cadena de texto
  pantalla.escribirFrase(salida, 0);
  contador++;
  delay(1000);
}

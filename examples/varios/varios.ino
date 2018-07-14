#include <MatrizLed.h>

/*
 * Varios ejemplos
 */

MatrizLed pantalla;

void setup() {
  pantalla.begin(12, 11, 10, 2); // dataPin, clkPin, csPin, numero de matrices de 8x8
}

void loop() { 
  // Controlar LEDs independientes
  pantalla.borrar();
  pantalla.setLed(0, 1, 3, true); // numero de matriz (empezando por 0), fila, columna, estado
  pantalla.setLed(0, 0, 2, true);
  pantalla.setLed(0, 2, 4, true);
  pantalla.setLed(0, 3, 5, true);
  delay(2000);

  // Escribir caracteres sueltos
  pantalla.borrar();
  pantalla.escribirCaracter('O' , 0); // Caracter, posicion en la pantalla
  pantalla.escribirCaracter('K' , 8);
  delay(2000);

  // Escribir texto estatico
  pantalla.borrar();
  pantalla.escribirFrase("Test");
  delay(2000);
  
  // Desplazar texto manualmente hacia la derecha
  pantalla.borrar();
  for(int i=0; i<10; i++){
    pantalla.escribirFrase("1234", i); // Texto, posicion en la pantalla
    delay(500);
  }

  // Desplazar texto manualmente hacia la izquierda
  pantalla.borrar();
  for(int i = 0; i > -10; i--){
    pantalla.escribirFrase("abcd", i);
    delay(500);
  }

}

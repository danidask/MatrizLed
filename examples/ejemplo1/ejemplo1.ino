#include "MatrizLed.h"

MatrizLed pantalla;

void setup() {
  pantalla.begin(12,11,10,2); // dataPin, clkPin, csPin, numero de matrices de 8x8
}

void loop() { 
  pantalla.borrar();
  pantalla.setLed(0, 1, 3, true); // numero de matriz (empezando por 0), fila, columna, estado
  pantalla.setLed(0, 0, 2, true);
  pantalla.setLed(0, 2, 4, true);
  pantalla.setLed(0, 3, 5, true);
  delay(2000);

  pantalla.borrar();
  pantalla.escribirCaracter('O' , 0); // Caracter, posicion en la pantalla
  pantalla.escribirCaracter('K' , 8);
  delay(2000);

  pantalla.borrar();
  pantalla.escribirFrase("Test", 0); // Texto, posicion en la pantalla
  delay(2000);
  
  pantalla.borrar();
  for(int i=0; i<10; i++){
    pantalla.escribirFrase("1234", i);
    delay(500);
  }

  pantalla.borrar();
  for(int i = 0; i > -10; i--){
    pantalla.escribirFrase("abcd", i);
    delay(500);
  }

  pantalla.borrar();
  while(true){
    pantalla.escribirFraseScroll("Hola Mundo", 200); // Texto, milisegundos entre frames
  }

}

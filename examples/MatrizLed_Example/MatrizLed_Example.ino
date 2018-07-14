#include "MatrizLed.h"

MatrizLed pantalla = MatrizLed(12,11,10,2);

void setup() {
  pantalla.begin();
  Serial.begin(9600);
}

void loop() { 
  pantalla.borrar();
  // numero pantalla, fila, columna, estado
  pantalla.setLed(0, 0, 2, true);
  pantalla.setLed(0, 1, 3, true);
  pantalla.setLed(0, 2, 4, true);
  pantalla.setLed(0, 3, 5, true);
  delay(2000);


  pantalla.borrar();
  pantalla.escribirCaracter('O' , 0);
  pantalla.escribirCaracter('K' , 8);
  delay(2000);

  pantalla.borrar();
  pantalla.escribirFrase("Test", 0);
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
    pantalla.escribirFraseScroll("Hola Mundo", 200);
  }


}

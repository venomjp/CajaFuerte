/*************************************************
CAJA FUERTE
Juan Pedro Perianes
30-1-2022
**************************************************
VIERNES TECNOLÓGICOS 2022
"Escape Room: Usa la Electrónica para ser libre"
**************************************************
Con este programa vamos a controlar la caja fuerte en la que guardaremos los premios finales y el examen que hay que robar.
Componentes:
- Arduino UNO
- Display LCD i2C -(SCL=A5, SDA=A4)
- Teclado matricial 4x4 (D2-D19)
- Led Rojo = CERRADA (D11)
- Led Verde = ABIERTA (D12)
- Servo (D10)
*/

// BIBLIOTECAS ----------------------------------
#include <Arduino.h>
#include <Servo.h>

// OBJETOS Y VARIABLES GLOBALES -----------------
Servo cerradura;  // creo el objeto para controlar un servo
int posicion = 0; // almacena la posicion del servo

// SETUP ----------------------------------------
void setup() {
  cerradura.attach(9);  // attaches the servo on pin 9 to the servo object
  
}//fin_setup


// LOOP -----------------------------------------
void loop() {
  
  //cerradura.write(pos); //escribo la posicion en el servo 0=abierto 180=cerrad
  
}//fin_loop



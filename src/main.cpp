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
*************************************************/

// BIBLIOTECAS ----------------------------------
#include <Arduino.h>
#include <Servo.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

// DEFINES Y CONSTANTES -------------------------
#define servo 10         // pin de conexión del servo
#define cerrada 11       // pin del led Rojo que indica puerta cerrada
#define abierta 12       // pin del led Verde que indica puerta abierta
const byte FILAS = 4;    // 4 FILAS
const byte COLUMNAS = 4; // 4 COLUMNAS

// OBJETOS Y VARIABLES GLOBALES -----------------
// Servo ......................
Servo cerradura;  // creo el objeto para controlar un servo
int posicion = 0; // almacena la posicion del servo
                  // 0=abierto - 180=cerrada
// Teclado ....................
char keys[FILAS][COLUMNAS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};
byte pinesFilas[FILAS] = {9, 8, 7, 6};       //conexión de las filas 1-4
byte pinesColumnas[COLUMNAS] = {5, 4, 3, 2}; //conexión de las columnas 1-4

Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS); // creo el objeto para controlar el teclado

unsigned long contador;
unsigned long tiempoInicio;
String mensaje="";

// SETUP ----------------------------------------
void setup()
{
  // inicicialización servo.......
  cerradura.attach(servo); // pin en el que se conecta el servo
  // inicialización pto serie ....
  Serial.begin(9600);
  Serial.println ("Caja Fuerte... iniciando...");
  // inicialización variables de tiempo
  contador = 0;
  tiempoInicio = millis();


} //fin_setup

// LOOP -----------------------------------------
void loop()
{

  //cerradura.write(posicion);
  
  //leo tecla
  char tecla=teclado.getKey();
  //si hay tecla pulsada la muestro por pto serie
  if (tecla){
    mensaje="Tecla: " + tecla;
    Serial.println (mensaje);
  }

} //fin_loop

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
#define ptaCerrada 11       // pin del led Rojo que indica puerta cerrada
#define ptaAbierta 12       // pin del led Verde que indica puerta abierta
#define abrir 180           // servo abrir = 180º
#define cerrar 22            // servo cerrar = 0º
const byte FILAS = 4;    // 4 FILAS
const byte COLUMNAS = 4; // 4 COLUMNAS

// OBJETOS Y VARIABLES GLOBALES -----------------
// Servo ...............................................................
Servo cerradura;  // creo el objeto para controlar un servo
int posicion = 0; // almacena la posicion del servo
                  // 0=abierto - 180=cerrada
// Teclado .............................................................
char keys[FILAS][COLUMNAS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};
byte pinesFilas[FILAS] = {9, 8, 7, 6};       //conexión de las filas 1-4
byte pinesColumnas[COLUMNAS] = {5, 4, 3, 2}; //conexión de las columnas 1-4

Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS); // creo el objeto para controlar el teclado

//LCD ..................................................................
LiquidCrystal_I2C lcd (0x3F, 16, 2);  //creo el objeto LCD dir. 0x3F

// SETUP ----------------------------------------
void setup()
{
  // inicicialización servo..........................................
  cerradura.attach(servo); // pin en el que se conecta el servo
  cerradura.write(cerrar);
  // inicialización pto serie .......................................
  Serial.begin(9600);
  Serial.println ("Caja Fuerte... iniciando...");
  // inicializar LCD ................................................
  lcd.init(); //inicializo lcd
  lcd.backlight();  //enciendo luz de fondo
  lcd.print("- Caja Fuerte -");
  // inicialización leds ............................................
  pinMode(ptaAbierta, OUTPUT);    //led puerta abierta como salida
  pinMode(ptaCerrada, OUTPUT);    //led puerta cerrada como salida
  digitalWrite(ptaAbierta,LOW);   //apago led
  digitalWrite(ptaCerrada,LOW);   //apago led



} //fin_setup

// LOOP -----------------------------------------
void loop()
{

  //cerradura.write(posicion);
  
  //leo tecla
  char tecla=teclado.getKey();
  //si hay tecla pulsada la muestro por pto serie
  if (tecla){
    Serial.print(F("Tecla: "));
    Serial.println (tecla);
    lcd.setCursor(0,1); //col=0, fila=1 (2ªlinea)
    lcd.print ("Tecla: ");
    lcd.print (tecla);
  }
  if (tecla=='1'){
    digitalWrite(ptaAbierta, HIGH);
  }
  if (tecla=='2'){
    digitalWrite(ptaCerrada, HIGH);
  }
  if (tecla=='*'){
    digitalWrite(ptaAbierta, LOW);
    digitalWrite(ptaCerrada, LOW);
  }
  if (tecla=='A')
  {
    cerradura.write(abrir);     //abrir cerradura
  }
  if (tecla=='C')
  {
    cerradura.write(cerrar);     //cerrar cerradura
  }

} //fin_loop

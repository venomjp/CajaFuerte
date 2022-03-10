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
#define abrir 22           // servo abrir = 180º
#define cerrar 180           // servo cerrar = 0º
#define longPassword 11     // longitud de la password: 10 caracteres
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

//Variables globales ...................................................
int contador=0;
char tecla;
char datos[longPassword];
char passMaster[longPassword]="09A65C7844";
bool passCorrecta;
bool cajaAbierta=false;     //indica caja cerrada

//FUNCIONES
void limpiarDatos(void);
void passwordIncorrecta(void);
void passwordCorrecta(void);



// SETUP ----------------------------------------
void setup()
{
  // inicicialización servo..........................................
  cerradura.attach(servo); // pin en el que se conecta el servo
  cerradura.write((cerrar+30));
  delay(100);
  cerradura.write(cerrar);
  // inicialización pto serie .......................................
  Serial.begin(9600);
  Serial.println ("Caja Fuerte... iniciando...");
  // inicializar LCD ................................................
  lcd.init(); //inicializo lcd
  lcd.backlight();  //enciendo luz de fondo
  lcd.setCursor(0,0); //col=0, fila=0 (1ªlinea)
  lcd.print("- Caja Fuerte -");
  lcd.setCursor(0,1); //col=0, fila=1 (2ªlinea)
  lcd.print("# to Password");
  // inicialización leds ............................................
  pinMode(ptaAbierta, OUTPUT);    //led puerta abierta como salida
  pinMode(ptaCerrada, OUTPUT);    //led puerta cerrada como salida
  digitalWrite(ptaAbierta,LOW);   //apago led
  digitalWrite(ptaCerrada,HIGH);  //enciendo led



} //fin_setup

// LOOP -----------------------------------------
void loop()
{

  //leo tecla
  tecla=teclado.getKey();
  if (tecla)
  {
    if (tecla=='#'){
      if (cajaAbierta){
        //cerrar caja
        digitalWrite(ptaCerrada, HIGH); //indico led pta cerrada
        digitalWrite(ptaAbierta, LOW);
        cerradura.write(cerrar);        //cerrar cerradura
        cajaAbierta=false;
      }
      limpiarDatos();
    }
    else{
      datos[contador]=tecla;
      lcd.setCursor(contador,1);
      lcd.print(datos[contador]);
      contador++;
    }
  }

  if (contador==(longPassword-1)){
    lcd.clear();

    if (!strcmp(datos, passMaster)){
      //pass correcta
      passwordCorrecta();
      cerradura.write(abrir);     //abrir cerradura
      digitalWrite(ptaAbierta, HIGH);
      digitalWrite(ptaCerrada, LOW);
      cajaAbierta=true;
    }
    else{
      //pass incorrecta
      passwordIncorrecta();
    }
    limpiarDatos();
  }
} //fin_loop

void limpiarDatos()
{
  while (contador!=0){
    datos[contador--] = 0;
  }
  lcd.clear();
  lcd.setCursor(0,0); //col=0, fila=0 (1ªlinea)
  lcd.print("Introduce 10");
  lcd.setCursor(0,1); //col=0, fila=1 (2ªlinea)
  lcd.print("teclas password");
  delay (3000);
  lcd.clear();
  lcd.setCursor(0,0); //col=0, fila=0 (1ªlinea)
  lcd.print("Password:");
  return;
}

void passwordIncorrecta()
{
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print("Password");
  lcd.setCursor (0,1);
  lcd.print("Incorrecta");
  delay (2000);
}

void passwordCorrecta()
{
  lcd.clear();
  lcd.setCursor (0,0);
  lcd.print("Password");
  lcd.setCursor (0,1);
  lcd.print("Correcta!!!!");
  delay (2000);
}

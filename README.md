# Caja Fuerte con Arduino
* Este pequeño proyecto se utiliza en 
<a rel="license" href="https://www.uc3m.es/secundaria/divulgacion-ciencia/viernes-tecnologicos">ElectroEscape: usa la electrónica para ser libre</a> dentro de los **Viernes Tecnológicos** organizados por la *Universidad Carlos III de Madrid*

* Consiste en la fabricación de una caja fuerte "de cartón" y cuya apertura está controlada por un Arduino UNO, para lo que hay que introducir una combinación de 10 teclas.

## Idea
<img alt="Idea" style="border-width:0" src="imagenes/cajaFuerte_idea.png" width="600" align = "center"/></a>

## Imágenes
* Caja de cartón

<img alt="De Cartón" style="border-width:0" src="imagenes/cajaDeCarton.jpg" width="600" align = "center"/></a>

* Electrónica y Arduino

<img alt="Electrónica y Arduino" style="border-width:0" src="imagenes/arduino.jpg" width="600" align = "center"/></a>
* Caja acabada

<img alt="Caja acabada" style="border-width:0" src="imagenes/cajaFuerte_acabada.jpg" width="600" align = "center"/></a>

## Esquema electrónico
Esquema realizado en Fritzing que ilustra las conexiones entre los distintos elementos:
* Arduino UNO Rev. 3
* Teclado matricial de 4x4
* LCD + i2C
* Servo
* 2 LEDs
* Power Bank (5V)

<img alt="Esquema en fritzing" style="border-width:0" src="imagenes/Esquema.png" width="600" align = "center"/></a>

## Código Arduino

* Ha sido escrito en VSCode + PlatformIO para un Arduino UNO R3 con un Display LCD i2C y un teclado matricial de 4x4 teclas. Disponible en la carpeta "src".

## Piezas realizadas con impresión 3D

* STLs de las distintas piezas en la carpeta "stl"

<img alt="STLs" style="border-width:0" src="imagenes/stl.png" width="600" align = "center"/></a>

* El montaje se ha realizado con cajas de carton, las distintas piezas fabricadas en PLA, un par de bisagras y pintura gris.


# Licencia
<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">
<img alt="Licencia Creative Commons" style="border-width:0" src="imagenes/by-sa.png" width="200" align = "center"/></a>

<br /><span xmlns:dct="http://purl.org/dc/terms/" property="dct:title">**Caja Fuerte de Cartón**. </span> Por <span xmlns:cc="http://creativecommons.org/ns#" property="cc:attributionName">Juan Pedro Perianes Rodríguez</span> se distribuye bajo una <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">Licencia Creative Commons Atribución-CompartirIgual 4.0 Internacional</a>.

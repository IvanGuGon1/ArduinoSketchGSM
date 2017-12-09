
#include <SoftwareSerial.h>    // Incluimos la libreria SoftwareSerial
SoftwareSerial mySerial(8, 9); // Declaramos los pines RX(8) y TX(9) que vamos a usar
 
void setup(){
Serial.begin(9600);       // Iniciamos la comunicacion serie
mySerial.begin(9600);     // Iniciamos una segunda comunicacion serie
delay(1000);              // Pausa de 1 segundo
            
}
 
void loop(){
if (mySerial.available()){          // Si la comunicacion SoftwareSerial tiene datos
  Serial.write(mySerial.read());    // Los sacamos por la comunicacion serie normal
} 
  
if (Serial.available()){            // Si la comunicacion serie normal tiene datos
  while(Serial.available()) {       // y mientras tenga datos que mostrar 
    mySerial.write(Serial.read());  // Los sacamos por la comunicacion SoftwareSerial
  } 
  mySerial.println();               // Enviamos un fin de linea
}
}
 



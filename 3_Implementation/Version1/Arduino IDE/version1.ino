#include <avr/io.h>
#include <util/delay.h>
#include <HCSR04.h>
#include <NXTBluetooth.h>

#define ULTRASONIC_TRIG_PIN 12
#define ULTRASONIC_ECHO_PIN 13
HCSR04 ultrasonic(ULTRASONIC_TRIG_PIN,ULTRASONIC_ECHO_PIN);
NXTBluetooth bluetooth(2, 3, 1, 10);

void init_us();
unsigned char mydata;
int i,duration=0,distance=0;
String message;

void init_us() {            /*To initialize Ultrasonic sensor(HC SR-04) through a Sample trigger*/
  PORTB &=~(1<<PORTB0);     /*B0 Trigger O/P*/
  _delay_ms(5);
  PORTB |=(1<<PORTB0);
  _delay_ms(10);
  PORTB &=~(1<<PORTB0);
  _delay_ms(5);
}

void setup() {
  Serial.begin(9600);                              /*begin the serial communication with the bluetooth module and the computer*/
  bluetooth.begin(9600);
  Serial.println("Beginning to send messages to NXT");
  DDRB |= (1<<DDB2)|(1<<DDB3)|(1<<DDB0)|(1<<DDB4); /*B2&B3 are indicator LED's,B0 is Ultrasonic Sensor Trigger O/P,B4 Motor load*/
  DDRB &= ~(1<<DDB1);                              /*B1 is Ultrasonic Sensor Echo I/P*/
}

void loop() {
  if(Serial.available()>0)
  {
    init_us();
    duration = pulseIn(PORTB1,HIGH);
    distance = (duration/2)*2.91; 
    mydata=Serial.read();
    /*if (distance>70) */ /*Tank level-Low,Turn on the motor & Indicate the user via Bluetooth*/
    if(mydata=='A'){
        PORTB |=(1<<PORTB2);
        PORTB |=(1<<PORTB4);
        PORTB &=~(1<<PORTB3);
        for (i = 0; i < 10; i += 1) {
            message = String("Motor Turned On " + String(i + 1) + "!");
          }
        Serial.println("Water level's low, Motor Turned On");/*If interfaced, Message will be sent to Connected Bluetooth user*/
        bluetooth.write(message, i);
      }
    /*else if (distance<20) */ /*Tank level-High,Turn on the motor & Indicate the user via Bluetooth*/      
    else if(mydata=='B'){
        PORTB &=~(1<<PORTB2);
        PORTB &=~(1<<PORTB4);
        PORTB |=(1<<PORTB3);
        for (i = 0; i < 10; i += 1) {
            message = String("Motor Turned Off " + String(i + 1) + "!");
          }
        Serial.println("Water level's High, Motor Turned Off");/*If interfaced, Message will be sent to Connected Bluetooth user*/
        bluetooth.write(message, i);    /*note that messages can't exede 59 characters including the null terminator*/
      }
      bluetooth.update();
  }
}

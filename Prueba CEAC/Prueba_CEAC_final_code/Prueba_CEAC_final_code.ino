#include <Servo.h>
#include <NewBot.h>  //Libreria creada
#include <IRremote.h>
NewBot bot;

#define PinIR 4
#define KEY_1 1
#define KEY_2 2
#define KEY_3 3
#define KEY_4 4
#define KEY_5 5
#define PinServoBase 9
#define PinServoCodo 10

IRrecv irrecv(PinIR);
decode_results results;

Servo ServoBase;
Servo ServoCodo;

int pos = 90;

void setup() {
  
  Serial.begin(9600);
  bot.startRobot(); 
  irrecv.enableIRIn();
  ServoBase.attach(PinServoBase);
  ServoCodo.attach(PinServoCodo);
}

void loop() {
  
  bot. bumpers();
  
  if(irrecv.decode(&results)){
    switch(results.value){

      case KEY_1:
      bot.forward(1000);
      delay(500);
      
     for(pos = 30; pos < 170; pos += 2){  //recorre de 0 a 180 grados 
           ServoBase.write(pos);              //le dice al servo de ir a la posición "pos"
           delay(10);                      //espera 10 ms para que el servo alcance la posición
      } 
     for(pos = 170; pos>=30; pos-=2){     //recorre de 180 a 0 grados                          
           ServoBase.write(pos);             //le dice al servo de ir a la posición "pos"
           delay(10);                       //espera 10 ms para que el servo alcance la posición 
      }
      
     ServoBase.write(90);
     delay(500);
     bot.rastrear();
    
      break;

      case KEY_2:
      bot.reverse(1000);
      break;
      
      case KEY_3:
      bot.Right(1000);
      delay(50);
      bot.R2D2(13);
      break;
           
      case KEY_4:
      bot.Left(1000);
      delay(50);
      bot.R2D2(13);
      break;

      case KEY_5:
      bot.stopBot(1000);
      break;
    }
       irrecv.resume();
  }

 
}
 

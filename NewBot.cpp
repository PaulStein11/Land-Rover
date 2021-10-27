//
//  awesomeRobot.cpp
//  
//
//
//

#include "NewBot.h"
#include "Arduino.h"

NewBot::NewBot(){
}

void NewBot::startRobot(){
    
    pinMode(motor1, OUTPUT);
    pinMode(motor2, OUTPUT);
    pinMode(motor3, OUTPUT);
    pinMode(motor4, OUTPUT);
    pinMode(bumper_izq, INPUT_PULLUP); 
    pinMode(bumper_der, INPUT_PULLUP); 
    pinMode(ledR, OUTPUT);
    pinMode(ledV, OUTPUT);
    
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);

    pinMode(PinBuzzer, OUTPUT);

    pinMode(Trigger, OUTPUT);
    pinMode(Echo, INPUT);
}

void NewBot::forward(int duration){
    
    analogWrite(ENA, 170);
    analogWrite(ENB, 170);
    
    
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, HIGH);
    
    delay(duration);
    
}

void NewBot::reverse(int duration){
    
    analogWrite(ENA, 150);
    analogWrite(ENB, 150);
    
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, LOW);
    
    delay(duration);
    
}

void NewBot::Right(int duration){
    
    analogWrite(ENA, 130);
    analogWrite(ENB, 130);
    
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, HIGH);
    
    delay(duration);
}

void NewBot::Left(int duration){
    
    analogWrite(ENA, 130);
    analogWrite(ENB, 130);
    
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, LOW);
    
    delay(duration);
    
}

void NewBot::stopBot(int duration){
    
    digitalWrite(ENA, LOW);
    digitalWrite(ENB, LOW);

    delay(duration);
    
}
void NewBot::bumpers(){

    if(digitalRead(bumper_der)){
      
      digitalWrite(ledR, HIGH);
      reverse(500);
      Left(500);
      
      digitalWrite(ledR, LOW);
      forward(50);
      
    }

    if(digitalRead(bumper_izq)){
      
      digitalWrite(ledV, HIGH);
      reverse(500);
      Right(500);
      
      digitalWrite(ledV, LOW);
      forward(50);
          
    }
  

}
void NewBot::beep(int Buzzer, float noteFrequency, long noteDuration)
{
  int x;
  float microsecondsPerWave = 1000000/noteFrequency;
  float millisecondsPerCycle = 1000/(microsecondsPerWave * 2);
  float loopTime = noteDuration + millisecondsPerCycle;
  for(x=0;x<loopTime; x++)
  {
    digitalWrite(Buzzer, HIGH);
    delayMicroseconds(microsecondsPerWave);
    digitalWrite(Buzzer, LOW);
    delayMicroseconds(microsecondsPerWave);
  }
  
}
void NewBot::R2D2 (int Buzzer){
    beep(Buzzer, note_E7, 500);
  beep(Buzzer, note_C7, 500);
  beep(Buzzer, note_D7, 500);
  beep(Buzzer, note_E7, 500);
  beep(Buzzer, note_G7, 500);
  beep(Buzzer, note_A7, 500);
  beep(Buzzer, note_G7, 500);
  beep(Buzzer, note_F7, 500);
  beep(Buzzer, note_F7, 500);
 // beep(Buzzer, note_E7, 500);
 // beep(Buzzer, note_D7, 500);
 // beep(Buzzer, note_C7, 500);

  
}
void NewBot::rastrear(){
         
      int cm = Ping(Trigger, Echo);
      Serial.print("Distancia: ");
      Serial.println(cm);
      delay(1000);
      

      if(cm >= 80 && cm <= 40){
        
         analogWrite(ENA, 225);
         analogWrite(ENB, 225);
         
         
         Serial.println("entre 80 - 40: Avanza");
      }
      if (cm <= 40 && cm >= 10){
         analogWrite(ENA, 130);
         analogWrite(ENB, 130);
         
         
         Serial.println("entre 20 - 10: LENTO");
                 
      }
     
      if (cm < 10){
        Serial.println("menos de 10: Detente");
        stopBot(100);
      }
      
}
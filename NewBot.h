//
//  
//
//
//

#ifndef NewBot_h
#define NewBot_h

#include "Arduino.h"

class NewBot
{
public:
    
    NewBot();
    
    void startRobot();
    void forward(int duration);
    void reverse(int duration);
    void Right(int duration);
    void Left(int duration);
    void stopBot(int duration);
    void bumpers();
    void R2D2(int Buzzer);
    void beep(int Buzzer, float noteFrequency, long noteDuration);
    void rastrear();
    
    int motor1 = 6;
    int motor2 = 7;
    int motor3 = 8;
    int motor4 = 11;
    
    int ENA = 5;
    int ENB = 12;
    int PinBuzzer = 13;


    int bumper_izq = 2;
    int bumper_der = 3;

    int ledR = A4;
    int ledV = A5;

    int Trigger = A0;
    int Echo = A1;
    
int Ping (int Trigger, int Echo){
  long duration, distanceCm;

  digitalWrite(Trigger, LOW);
  delayMicroseconds(4);
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);

  duration = pulseIn(Echo, HIGH);
  distanceCm = duration * 10/292/2;
  return distanceCm;
}
 const float note_C0 = 16.35;
    const float note_Db0 = 17.32;
    const float note_D0 = 18.35;
    const float note_Eb0 = 19.45;
    const float note_E0 = 20.6;
    const float note_F0 = 21.83;
    const float note_Gb0 = 23.12;
    const float note_G0 = 24.5;
    const float note_Ab0 = 25.96;
    const float note_A0 = 27.5;
    const float note_Bb0 = 29.14;
    const float note_B0 = 30.87;
    const float note_C1 = 32.7;
    const float note_Db1 = 34.65;
    const float note_D1 = 36.71;
    const float note_Eb1 = 38.89;
    const float note_E1 = 41.2;
    const float note_F1 = 43.65;
    const float note_Gb1 = 46.25;
    const float note_G1 = 49;
    const float note_Ab1 = 51.91;
    const float note_A1 = 55;
    const float note_Bb1 = 58.27;
    const float note_B1 = 61.74;
    const float note_C2 = 65.41;
    const float note_Db2 = 69.3;
    const float note_D2 = 73.42;
    const float note_Eb2 = 77.78;
    const float note_E2 = 82.41;
    const float note_F2 = 87.31;
    const float note_Gb2 = 92.5;
    const float note_G2 = 98;
    const float note_Ab2 = 103.83;
    const float note_A2 = 110;
    const float note_Bb2 = 116.54;
    const float note_B2 = 123.47;
    const float note_C3 = 130.81;
    const float note_Db3 = 138.59;
    const float note_D3 = 146.83;
    const float note_Eb3 = 155.56;
    const float note_E3 = 164.81;
    const float note_F3 = 174.61;
    const float note_Gb3 = 185;
    const float note_G3 = 196;
    const float note_Ab3 = 207.65;
    const float note_A3 = 220;
    const float note_Bb3 = 233.08;
    const float note_B3 = 246.94;
    const float note_C4 = 261.63;
    const float note_Db4 = 277.18;
    const float note_D4 = 293.66;
    const float note_Eb4 = 311.13;
    const float note_E4 = 329.63;
    const float note_F4 = 349.23;
    const float note_Gb4 = 369.99;
    const float note_G4 = 392;
    const float note_Ab4 = 415.3;
    const float note_A4 = 440;
    const float note_Bb4 = 466.16;
    const float note_B4 = 493.88;
    const float note_C5 = 523.25;
    const float note_Db5 = 554.37;
    const float note_D5 = 587.33;
    const float note_Eb5 = 622.25;
    const float note_E5 = 659.26;
    const float note_F5 = 698.46;
    const float note_Gb5 = 739.99;
    const float note_G5 = 783.99;
    const float note_Ab5 = 830.61;
    const float note_A5 = 880;
    const float note_Bb5 = 932.33;
    const float note_B5 = 987.77;
    const float note_C6 = 1046.5;
    const float note_Db6 = 1108.73;
    const float note_D6 = 1174.66;
    const float note_Eb6 = 1244.51;
    const float note_E6 = 1318.51;
    const float note_F6 = 1396.91;
    const float note_Gb6 = 1479.98;
    const float note_G6 = 1567.98;
    const float note_Ab6 = 1661.22;
    const float note_A6 = 1760;
    const float note_Bb6 = 1864.66;
    const float note_B6 = 1975.53;
    const float note_C7 = 2093;
    const float note_Db7 = 2217.46;
    const float note_D7 = 2349.32;
    const float note_Eb7 = 2489.02;
    const float note_E7 = 2637.02;
    const float note_F7 = 2793.83;
    const float note_Gb7 = 2959.96;
    const float note_G7 = 3135.96;
    const float note_Ab7 = 3322.44;
    const float note_A7 = 3520;
    const float note_Bb7 = 3729.31;
    const float note_B7 = 3951.07;
    const float note_C8 = 4186.01;
    const float note_Db8 = 4434.92;
    const float note_D8 = 4698.64;
    const float note_Eb8 = 4978.03;

};

#endif /* awesomeRobot_h */
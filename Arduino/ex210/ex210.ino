#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#include "pitches.h"
#define PRESET 0

int melody[]=
{ NOTE_G4,NOTE_G4,NOTE_A4,NOTE_A4,NOTE_G4,NOTE_G4,NOTE_E4,
NOTE_G4,NOTE_G4,NOTE_E4,NOTE_E4,NOTE_D4,PRESET,
NOTE_G4,NOTE_G4,NOTE_A4,NOTE_A4,NOTE_G4,NOTE_G4,NOTE_E4,
NOTE_G4,NOTE_G4,NOTE_D4,NOTE_E4,NOTE_C4,PRESET
};
int durations[]=
{
  8,8,8,8,8,8,16, 8,8,8,8,24,8,
  8,8,8,8,8,8,16, 8,8,8,8,24,8
};
int thisNote;
int dur;
int pauseNotes;
void setup()
{
  for(int i=8;i<=12;i++)
  {
    pinMode(i,OUTPUT);
  }
}
void loop()
{
  if(digitalRead(6)==1)
  {
    for(thisNote=0;thisNote<26;thisNote++)
    {
      dur=1000/32*durations[thisNote];
      tone(7,melody[thisNote],dur);
      switch(melody[thisNote])
      {
        case NOTE_C4:
          digitalWrite(12,HIGH);
          break;
        case NOTE_D4:
          digitalWrite(11,HIGH);
          break;
        case NOTE_E4:
          digitalWrite(10,HIGH);
          break;
        case NOTE_G4:
          digitalWrite(9,HIGH);
          break;
        case NOTE_A4:
          digitalWrite(8,HIGH);
          break;
      }
      pauseNotes=dur*1.3;
      delay(pauseNotes);
      noTone(7);
      for(int i=8;i<=12;i++)
      {
        digitalWrite(i,LOW);
      }
    }
  }
}


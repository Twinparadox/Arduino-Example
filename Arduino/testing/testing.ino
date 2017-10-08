#include <MsTimer2.h>

 

#define SPACE { \

  {0,0,0,0,0,0,0}, \

  {0,0,0,0,0,0,0}, \

  {0,0,0,0,0,0,0}, \

  {0,0,0,0,0,0,0}, \

  {0,0,0,0,0,0,0} \

}

 

#define I { \

{0, 1, 1, 1, 1, 0, 0}, \

{0, 0, 1, 1, 0, 0, 0}, \

{0, 0, 1, 1, 0, 0, 0}, \

{0, 0, 1, 1, 0, 0, 0}, \

{0, 1, 1, 1, 1, 0, 0} \

}

 

#define Heart { \

{0, 1, 1, 0, 1, 1, 0}, \

{1, 1, 1, 1, 1, 1, 1}, \

{0, 1, 1, 1, 1, 1, 0}, \

{0, 0, 1, 1, 1, 0, 0}, \

{0, 0, 0, 1, 0, 0, 0} \

}

 

#define Y { \

{0, 1, 1, 0, 0, 1, 1}, \

{0, 1, 1, 0, 0, 1, 1}, \

{0, 0, 1, 1, 1, 1, 0}, \

{0, 0, 0, 1, 1, 0, 0}, \

{0, 0, 0, 1, 1, 0, 0} \

}

 

#define O { \

{0, 0, 1, 1, 1, 0, 0}, \

{0, 1, 1, 0, 1, 1, 0}, \

{0, 1, 1, 0, 1, 1, 0}, \

{0, 1, 1, 0, 1, 1, 0}, \

{0, 0, 1, 1, 1, 0, 0} \

}

 

#define U { \

{0, 1, 1, 0, 0, 1, 1}, \

{0, 1, 1, 0, 0, 1, 1}, \

{0, 1, 1, 0, 0, 1, 1}, \

{0, 1, 1, 0, 0, 1, 1}, \

{0, 0, 1, 1, 1, 1, 0} \

}

 

byte col = 0;

int row = 0;

byte leds[5][7];

int font = 0;

int i,j,k;

 

int pins[13] = {-1, 9,17, 3, 14, 5, 16, 12, 15, 10, 2, 8, 13};

int cols[5] = {pins[1] , pins[3] , pins[10], pins[7], pins[8]};

int rows[7] = {pins[12] , pins[11], pins[2], pins[9], pins[4], pins[5], pins[6]};

 

const int numFonts = 6;

byte fonts[numFonts][5][7] = {

  I , Heart , Y , O , U , SPACE};

 

  void setFont(int font){

    for (int i = 0; i<5; i++){

      for (int j=0; j<7; j++){

        leds[i][j] = fonts[font][i][j];

      }

    }

  }

  void slideFont(int font, int del){

    for(k=0;k<7;k++){

      for(i=0;i<6;i++){

        for(j=0;j<5;j++){

          leds[j][i]=leds[j][i+1];

        }

      }

      for (j=0;j<5;j++){

        leds[j][6] = fonts[font][j][0+k];

      }

      delay(del);

    }

  }

  void dotDisplay(){

    digitalWrite(cols[col],HIGH);

    col++;

    if(col==5){

      col=0;

    }

    for(row =0; row<7; row++){

      if(leds[col][6-row] == 1){

        digitalWrite(rows[row], HIGH);

      }

      else {

        digitalWrite(rows[row], LOW);

      }

    }

    digitalWrite(cols[col], LOW);

  }

 

  void setup(){

    for(int i=1; i<=12;i++){

      pinMode(pins[i], OUTPUT);

        }

        MsTimer2::set(2,dotDisplay);

        MsTimer2::start();

 

        setFont(font);

      }

      

      void loop(){

        font = ++font % numFonts;

        slideFont(font,100);

      }

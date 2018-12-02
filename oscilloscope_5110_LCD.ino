#include Adafruit Pcd8544.h

#include Adafruit Gfx.h

int dial1,dial2; long tim,values[84];

Adafruit_PCD8544 display = Adafruit_PCD8544(13,11,9,10,8);

void setup(){
display.begin();
display.setContrast(50);
}

void loop() {

dial1 = analogRead(A1); //fine tuner for time per division

dial2 = analogRead(A2); //range selector for time per division

//////////////oscilloscope/////////////////

int n=map(dial2,0,1023,1,30); // range,either from 0-1000,1000-2000,2000-3000 and so on
tim=map(dial1,0,1023,(n-1)*1000,n*1000);

for(int i=0;i<84;i++){
values[i]=map(analogRead(A0),0,1023,0,47); //getting values
delayMicroseconds(tim);
}

display.clearDisplay();
display.drawLine(0,24,84,24,BLACK); //x-axis
display.drawLine(42,0,42,48,BLACK); //y-axis
display.drawRect(0,0,84,48, BLACK);

for(int i=4;i<=44;i+=5){
display.drawLine(41,i,43,i,BLACK); //scale
}

for(int i=0;i<84;i++){
display.drawLine(i,47-values[i],i,47-values[i+1], BLACK); //drawing graph
}

display.display();
}

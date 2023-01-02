#include <ezButton.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

ezButton button1(13);
ezButton button2(33);
ezButton button3(14);
ezButton button4(27);
ezButton button5(26);


bool goingUp = true;
int currentFloor = 1;
int buttonState = 0;

void setup()
{

  Serial.begin(9600);

  button1.setDebounceTime(25);
  button2.setDebounceTime(25);
  button3.setDebounceTime(25);
  button4.setDebounceTime(25);
  button5.setDebounceTime(25);

  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  };

  delay(2000);     
  oled.clearDisplay();
  displayMessage();


  oled.clearDisplay();
}

void loop(){

  button1.loop();
  button2.loop();
  button3.loop();
  button4.loop();
  button5.loop();

  if (button1.isPressed()){
    Serial.println("Button 1 is pressed");
    if(currentFloor > 1){
      moveDown(1, 1);
    }
  }
  else if (button2.isPressed()){
  Serial.println("Button 2 is pressed");
if(currentFloor < 2){
      moveUp(2, 25);
    } else if(currentFloor > 2){
      moveDown(2, 25);
    }
  }
  else if (button3.isPressed()){
   Serial.println("Button 3 is pressed");
if(currentFloor < 3){
      moveUp(2, 25);
    } else if(currentFloor > 3){
      moveDown(2, 25);
    }
  }
  else if (button4.isPressed()){
  Serial.println("Button 4 is pressed");
if(currentFloor < 4){
      moveUp(2, 25);
    } else if(currentFloor > 4){
      moveDown(2, 25);
    }
  }
  else if (button5.isPressed()){
   Serial.println("Button 1 is pressed");
if(currentFloor < 5){
      moveUp(2, 25);
    } else if(currentFloor > 5){
      moveDown(2, 25);
    }
  }

  delay(10);
}

void moveDown(int floorNumber, int cursorPosition){
  while(currentFloor >= floorNumber){
    oled.setTextSize(5);
    oled.setTextColor(WHITE);
    oled.setCursor(20, 20);
    oled.println(currentFloor);
    Serial.println("Going Down...");
    oled.setCursor(60, 15);
    oled.write(25);
    oled.display();

    delay(1000);
    currentFloor--;
    oled.clearDisplay();
  }
      currentFloor = floorNumber;
      displayMessage();
}

void moveUp(int floorNumber, int cursorPosition)
 {
     while(currentFloor <= floorNumber){
       oled.setTextSize(1);
       oled.setTextColor(WHITE);
       oled.setCursor(20, 20);
       oled.println(currentFloor);
       oled.display();
       Serial.println("Going Up...");
       oled.setCursor(60, 15);
       oled.write(24);
       oled.display();

       delay(1000);
       currentFloor++;
       oled.clearDisplay();
     } 
      currentFloor = floorNumber;
      displayMessage();
}
  

void displayMessage(){
  oled.setTextSize(2);      
  oled.setTextColor(WHITE);   

  oled.setCursor(2, 5);       
  oled.println("Press");
  oled.display();            

  oled.setCursor(2, 25);      
  oled.println("floor");
  oled.display();            

  oled.setCursor(2, 45);      
  oled.println("number"); 
  oled.display();              

  delay(1000);
  oled.clearDisplay();
}

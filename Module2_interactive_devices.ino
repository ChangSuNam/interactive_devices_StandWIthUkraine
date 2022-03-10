#include <ArduinoJson.h>
/**
 * This program allows ESP32 to interact with a switch, potentiometer, and joystick.
 * 
 * Uses ArduinoJson Libary to send output of switch, potentiometer and joystick to the
 * 
 * @Author ChangSu Nam
 * @UNI cn2521
 * @Since Module 2 March 2022
 * 
 */

/**
 * Constants for the pins
 * 
 * switchPin the pin switch is connected to.
 * joystickXPin the pin VRx of joystick is connected to.
 * joystickXPin the pin VRy of joystick is connected to.
 * joystickSWPin the pin switch of joystick is connected to.
 * potentiometerPin the pin potentiometer is connected to.
 * 
 * capacity the capacity for json object
 */
 
const int switchPin = 26;          // the pin is connected to pin 26 of TTGO
const int joystickXPin = 13;    // the pin is connected to pin 13 of TTGO
const int joystickYPin = 27;      // the pin is connected to pin 27 of TTGO
const int joystickSWPin = 25;     // the pin is connected to pin 25 of TTGO
const int potentiometerPin = 12;  // the pin is connected to pin 12 of TTGO


const int capacity = JSON_OBJECT_SIZE(100);

StaticJsonDocument<capacity> doc;
/**
 * Variables.
 * 
 * switchState the state of switch, either on or off.
 * 
 */
int switchState = 0;         // variable for reading the status of switch. 
int joystickSwitchState = 0;         // variable for reading the status of joystick's switch. 

void setup() {

  Serial.begin(115200);
 // delay(1000); 
  pinMode(switchPin, INPUT_PULLUP);//switch, default HIFH state: pull-up resistor.
  pinMode(joystickSWPin, INPUT_PULLUP);//joystick sw default HIFH state: pull-up resistor.
}


void loop() {
   /** 
    *  Potentiometer
    */
   delay(100); 
    
   int potentVal =  map(analogRead(potentiometerPin), 0, 4095, 0, 100); 
   //potentOutput = map(pooh tentVal, 0,)
   //Serial.print(potentVal);
   //Serial.print("  "); 
   
   /**
    * Joystick
    */

   int xVal = map(analogRead(joystickXPin), 0, 4095, 0, 100); 
   int yVal = map(analogRead(joystickYPin), 0, 4095, 0, 100); 
   //int xVal = digitalRead(joystickXPin);   //Reads 0 or 1(right)
   //int yVal = digitalRead(joystickYPin);   //Reads 0 or 1(up)
   //   Serial.print(xVal);
   //   Serial.print("  "); 
   //   Serial.print(yVal);
   //   Serial.print("  "); 
 
  
  // read the state of the pushbutton value:

  int joystickSWVal = -1;
  joystickSwitchState = digitalRead(joystickSWPin);
  if (joystickSwitchState == HIGH) { //button not pressed
    joystickSWVal = digitalRead(joystickSWPin);
//    Serial.print(joystickSWVal);   //1
//     Serial.print("  "); 
  }else{ // button pressed
     joystickSWVal = digitalRead(joystickSWPin);
//      Serial.print(joystickSWVal);   //0
//       Serial.print("  "); 
  }
  
  /**
   * Switch
   */
   int switchVal = -1;
  // read the state of the pushbutton value:
    switchState = digitalRead(switchPin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (switchState == HIGH) {  //button not pressed
    switchVal = digitalRead(switchPin);
//    Serial.print(switchVal);     //1
//     Serial.println("  "); 
  } else { //button pressed.
    switchVal = digitalRead(switchPin);
//    Serial.print(switchVal);    //0
//     Serial.println("  "); 
  }

  /**
   * Create JSON object as below:
   *  
   *      {
   *    "potentiometer": potentVal, 
   *    "X": xVal,
   *    "Y": yVal,
   *    "joystickSW": joystickSWVal,
   *    "switch":switchVal
   *   } 
   */

  doc["P"] = potentVal; 
  doc["X"] = xVal;
  doc["Y"] = yVal;
  doc["J"]= joystickSWVal;
  doc["S"]= switchVal;
  
  // print JSON doc to serial port
  String output = "";
  serializeJson(doc, output);
  Serial.print("\n");
  Serial.print(output+"\n");
  
  
  }

## Creating an interactive device with ESP32



# Project Description
  
  
  For this project, an interactive device was built with the following hardwares:
1. ESP32 TTGO
2.  Momentary, normally open, single pole single throw switch
3.  Joystick, which can act as a switch when it is pressed.
4. Potentiometer

First, ESP32 was soldered with two headers:

![IMG_9296](https://user-images.githubusercontent.com/25335750/157591450-5bb7082d-62ea-4182-aee3-8adc3043146f.jpg)
![IMG_9297](https://user-images.githubusercontent.com/25335750/157591470-e4a156c7-a188-4565-bdce-cf481e4a7fb5.jpg)

The headers have pins that female to female wires can be connected to. 

Since the switch does not have pins for female to female wires, it was soldered to a normal wire, which was soldered to a female to female wire cut in half: 
![IMG_9458](https://user-images.githubusercontent.com/25335750/157594343-11e98873-98cc-49e9-a082-59edf0dc6f4e.jpg)

Then, the components were connected to the pins by female to female wires.

Joystick:
![IMG_9486](https://user-images.githubusercontent.com/25335750/157594360-4b057f64-07ac-4b9b-890d-3768ba020dce.jpg)
![IMG_9487](https://user-images.githubusercontent.com/25335750/157594393-d5a0af47-c9df-4d40-a478-df3bdb75e099.jpg)
![IMG_9488](https://user-images.githubusercontent.com/25335750/157594401-433cdcc9-b28d-4662-b8b8-21fbbcc8b992.jpg)

Potentiometer and switch:
![IMG_9489](https://user-images.githubusercontent.com/25335750/157594447-7f0299bf-c971-4913-9d17-adbb776f36f7.jpg)
![IMG_9485](https://user-images.githubusercontent.com/25335750/157594452-dee4bb7b-9b75-4d47-8f39-82c4396cfa1a.jpg)
![IMG_9490](https://user-images.githubusercontent.com/25335750/157594529-29b1d360-3c73-4676-965b-4c7582e3aa15.jpg)

The specific connections on ESP32 for the components are stated below:

Switch: One end was connected to ground, the other one to pin 26, the GPIO, to read digital values like 0 or 1.

Potentiometer: 1. The rightmost pin of potentiometer was connected to 3.3v, bottom left pin of TTGO ESP32.
2. The middle pin of the potentiometer was connected to pin 12 of TTGO ESP32.
3. The leftmost pin of the potentiometer was connected to second ground pin from top left.

Joystick: 1. GND pin of the joystick was connected to bottom right ground pin of TTGO ESP32
	        2. 5V pin of the joystick was connected to top right 3V pin of TTGO ESP32
	        3. VRy pin of the joystick was connected to pin 27 of TTGO ESP32.
          4. VRx pin of the joystick was connected to pin 13 of TTGO ESP32.
  	     5. SW pin of the joystick was connected to pin 25 of TTGO ESP32.

The ESP32 was then connected to a laptop so that a program can be loaded on it via Arduino IDE. The code reads the input that user creates with the switch, potentiometer, and joystick with either anlaogueRead() or digitalRead(). With theses values, it creates a JSON data, which is then serially printed. "ArduinoJson" was used to convert the data to JSON: https://arduinojson.org 

The details of the code can be found at: https://github.com/ChangSuNam/interactive_devices_StandWIthUkraine/blob/main/Module2_interactive_devices.ino

The JSON data is then received by a javascript code, which allows the user to interact with a simple html page with texts, images, buttons and audio. 

The content of the html page contains information on the Russia-Ukraine crisis, 2022. It displays 4 buttons and the flag of Ukraine. When each of the button is chosen with the joystick and clicked with the switch, it displays specific informations regarding the crisis under the buttons. For instance, when "Donation" button is clicked, the page displays ways to donate to Ukraine.

The flag is set to slowly fade out to a Russian flag, and the user can prevent this by pressing the buttons. However, the flag starts to fade again, and the user needs to constantly press the button. This was set to imply that if the world loses interest in Ukraine and stop caring about it, the whole country would be taken over by Russia, like how they annexed Crimea in 2014. In addition, the html page plays the national anthem of Ukraine, and the volume can be controlled with the potentiometer.

The code for javascript can be found at: https://github.com/ChangSuNam/interactive_devices_StandWIthUkraine/blob/main/standWithUkraine.js

The code for html can be found at: https://github.com/ChangSuNam/interactive_devices_StandWIthUkraine/blob/main/standWithUkraine.html

The source of the picture displayed is: https://image5jvqbd.fmkorea.com/files/attach/new2/20220307/486616/3518195379/4406615044/99b983892094b5c6d2fc3736e15da7d1.jpg 

The source of the audio file is: https://web.archive.org/web/20041019081257/http://www.navyband.navy.mil/anthems/ANTHEMS/Ukraine.mp3

Finally, the ESP32 and the components were enclosed in a cardboard box, which was then covered with white papers.
![IMG_9586](https://user-images.githubusercontent.com/25335750/157601871-d4acbd95-443e-448b-916c-0fa5f7b9769d.jpg)
![IMG_9593](https://user-images.githubusercontent.com/25335750/157601900-f870193f-c181-44e6-bfd4-bb0ec865551d.jpg)
I cut the board so that the components could fit.
![IMG_9595](https://user-images.githubusercontent.com/25335750/157602383-f20b157d-5fe5-4d0d-bce3-7fcbe829338c.jpg)
![IMG_9597](https://user-images.githubusercontent.com/25335750/157602422-cba8dfb3-5dda-4969-b53c-fbfc8e404b33.jpg)
![IMG_9600](https://user-images.githubusercontent.com/25335750/157602482-b6a46e97-81a7-4021-9699-6fc5c84d24f7.jpg)

The target audience of this project is anyone. I wish this project reminds anyone who encounters this that freedom is not free. 

Technical difficulties I experienced doing this project was that when JSON data was sent serially, it sometimes arrived on the javascript's side as incomplete fractions, causing error to stop the while(true) loop receiving JSON data constantly. This was fixed using try{} catch(e){} block to skip the error and continue looping. In addition, I initially connected the switch to the GPIO 37 pin on ESP32, but this did not work because pin 34 to pin 39 do not have pulllup or pulldown resistors. More information on this can be found at:https://www.espressif.com/sites/default/files/documentation/esp32_datasheet_en.pdf

The video recording of this project can be found at: https://youtu.be/v0MUYf-T6SM
The github pages for this project: https://changsunam.github.io/interactive_devices_StandWIthUkraine/







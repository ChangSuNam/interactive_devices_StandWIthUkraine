## Creating an interactive device with ESP32



# Description of the project
  
  
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

Potentiometer: -The rightmost pin of potentiometer was connected to 3.3v, bottom left pin of TTGO ESP32.
		           -The middle pin of the potentiometer was connected to pin 12 of TTGO ESP32.
		           -The leftmost pin of the potentiometer was connected to second ground pin from top left.

Joystick: -GND pin of the joystick was connected to bottom right ground pin of TTGO ESP32
	        -5V pin of the joystick was connected to top right 3V pin of TTGO ESP32
	        -VRy pin of the joystick was connected to pin 27 of TTGO ESP32.
          -VRx pin of the joystick was connected to pin 13 of TTGO ESP32.
  	      -SW pin of the joystick was connected to pin 25 of TTGO ESP32.
![image](https://user-images.githubusercontent.com/25335750/157594632-e48d89b5-3661-4dbe-bd7a-bcbab17f55cd.png)

The ESP32 was then connected to a laptop so that a program can be loaded on it via Arduino IDE. The code reads the input that user creates with the switch, potentiometer, and joystick with either anlaogueRead() or digitalRead(). With theses values, it creates a JSON data, which is then serially printed. "ArduinoJson" was used to convert the data to JSON: https://arduinojson.org 
The details of the code can be found at: https://github.com/ChangSuNam/interactive_devices_StandWIthUkraine/blob/main/Module2_interactive_devices.ino

The JSON data is then received by a javascript code, which allows the user to interact with a simple html page with texts, images, buttons and audio. 

The source of the picture is: 
The source of the audio file is: 








## Header 2
### Header 3

- Bulleted
- List

1. Numbered
2. List

**Bold** and _Italic_ and `Code` text

[Link](url) and ![Image](src)
```

For more details see [Basic writing and formatting syntax](https://docs.github.com/en/github/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax).

### Jekyll Themes

Your Pages site will use the layout and styles from the Jekyll theme you have selected in your [repository settings](https://github.com/ChangSuNam/interactive_devices_StandWIthUkraine/settings/pages). The name of this theme is saved in the Jekyll `_config.yml` configuration file.

### Support or Contact

Having trouble with Pages? Check out our [documentation](https://docs.github.com/categories/github-pages-basics/) or [contact support](https://support.github.com/contact) and we’ll help you sort it out.

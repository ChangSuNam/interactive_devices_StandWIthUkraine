let xVal;
let yVal;
let potent;
let SW;
let joystickSW;
let op = 1;
let buttonFocus = -1;
let img = document.createElement("img");
img.src = "supportingCountries.jpeg";
let audio = new Audio("national_anthem.mp3");
audio.volume = 1;
$(document).ready(function () {

  setInterval(function () {
    let flag = document.getElementById("ukraine");
    if (op > 0) {
      op = op - 0.001;
      flag.style.opacity = op;
    }
  }, 10); // 1000 == 1 second

  document.getElementById("buttonWest").focus();

})


//when the user clicks anywhere on the page
document.addEventListener('click', async () => {
  audio.play();
  // Prompt user to select any serial port.
  var port = await navigator.serial.requestPort();
  await port.open({ baudRate: 115200 });
  let decoder = new TextDecoderStream();
  inputDone = port.readable.pipeTo(decoder.writable);
  inputStream = decoder.readable;
  reader = inputStream.getReader();

  while (true) {
    const { value, done } = await reader.read();

    if (done) {
      // Allow the serial port to be closed later.
      alert("closing connection, good bye!")
      reader.releaseLock();
      break;
    }
    if (value) {
      try {
        let jsonData = JSON.parse(value);
        xVal = jsonData.X;
        yVal = jsonData.Y;
        potent = jsonData.P;
        joystickSW = jsonData.J;
        SW = jsonData.S;

        //set the volume of the audio with the value from potentiometer.
        audio.volume = potent / 100;

        if (joystickSW == 0) { // if joystick's button is pressed, change opacity to 1
          op = 1; //resets opacity
        }

        if (xVal < 30) { // left
          document.getElementById("buttonWest").focus(); 
          buttonFocus = 1;
          console.log("buttonFocus is: " + buttonFocus);
        }
        if (xVal > 70) { // right
          document.getElementById("buttonEast").focus(); 
          buttonFocus = 0;
          console.log("buttonFocus is: " + buttonFocus);
        }
        if (yVal < 30) { // down
          document.getElementById("buttonSouth").focus(); 
          buttonFocus = 2;
          console.log("buttonFocus is: " + buttonFocus);
        }
        if (yVal > 70) { // up
          document.getElementById("buttonNorth").focus(); 
          buttonFocus = 3;
          console.log("buttonFocus is: " + buttonFocus);
        }

        if (SW == 0) { // if switch pressed
          op = op + 0.4;
          let update = "";


          if (buttonFocus == 0) {
            //console.log("0");
            $(".textRow").empty();
            update = $("<div>");

            $(update).append("You can see the live news and an interactive map of the war on: <ul> 'https://liveuamap.com/' </ul>  The government of Ukraine updates the following twitter account: <ul>'https://twitter.com/ukraine'</ul> " + "</div>");
            $("#textDiv").append(update);

          }
          else if (buttonFocus == 1) {
            $(".textRow").empty();
            update = $("<br><br><br><br><div>");
            $(update).append("Most countries do not support Russia's invasion:" + "</div>");
            $("#textDiv").append(update);
            document.getElementById("textDiv").appendChild(img);
          }
          else if (buttonFocus == 2) {
            
            $(".textRow").empty();
            update = $("<div>");
            $(update).append("On 24th Feb 2022, Russia invaded Ukraine in order to 'bring peace' and fight against the Nazis of Ukraine. However, this is a propaganda to justify Russia's attempt to expand, and strengthen their geopolitical influence in Europe against NATO and the free world." + "</div>");
            $("#textDiv").append(update);
          }
          else if (buttonFocus == 3) {
           
            $(".textRow").empty();
            update = $("<div> <ul>");
            $(update).append(" There are various ways you can donate to Ukraine: <ul>-'https://www.globalgiving.org/projects/ukraine-crisis-relief-fund/'</ul>  <ul>-'https://www.directrelief.org/emergency/ukraine-crisis/'</ul> <ul>-BTC: 357a3So9CbsNfBBgFYACGvxxS6tMaDoa1P</ul>   <ul>-ETH and USDT (ERC-20): 0x165CD37b4C644C2921454429E7F9358d18A45e14</ul>" + " </ul></div>");
            $("#textDiv").append(update);
          }

        }


      }

      catch (e) {
        // Code to run if an exception occurs
        continue;
      }




    }
  }
});







# Waste_Segregation_System
This project is a working prototype for an automated waste system that uses image pre processing in real time to segregate waste objects based on four distinct categories.

----------------------------------------------------------------------------------------------------------------------------------------------------------

## Ensure the following requirements software requirements - 
 - Python v3.11.1
 - Arduino IDE  2.2.1

----------------------------------------------------------------------------------------------------------------------------------------------------------

## Changes that might be required in the code - 

 - Ensure you have the model in the correct file path in Intergration.ipynb
 - Setup the arduino connection (GPIO Pin 9 ihas been used for input in the IDE Code)
 - Setup the webcam connection (Integration .ipynb has a function to image from camera and it accesses the camera using port. Find the port connection       to which the webcam is connected to the workstation and modify the code)
 - In the arduino code check for the initial position of the servo motor. Based on that changes might be required for reprogramming the shaft movement.
 - Integration.ipynb eshtablishes a connection with .ino file using Serial library and binds them using a port. Check for the port in the IDE and            update in Integration file as per requirements.

----------------------------------------------------------------------------------------------------------------------------------------------------------

## Project Implementation steps - 

 - Start by compiling the arduino ide code and uploading it to the arduino
 - Start the kernel execution for the python file. (Camera initialization takes a long time so it might take over a minute for the execution to begin)
 - Place the waste object in front of the webcam (The code checks for an object every 20 seconds)
 - This image will be fed to the pretrained CNN model which will then assign it a prediction class (0- No Object Detected, 1-Cardboard, 2- Metal, 3-         Plastic, 4- Paper)
 - Once the waste object is assigned a predicted class switch the conveyor belt on (The distance between image capture module and shaft is around 20         seconds hence the code in arduino is mostly programmed to run make corresponding shaft action for the predicted class within these 20            
   seconds using delays . Note that this is also the reason why the image capture module also only detects for objects every 20 seconds.                     Changes are to be made in the code as per the time to takes to travel from image capture module to the shaft)
 - Now based on the predicted class, every class has a different shaft action. Plastic category will make the shaft push the object inwards, metal           category will make the shaft push the object outwards. Paper and cardboard will put the shaft on standby position.

----------------------------------------------------------------------------------------------------------------------------------------------------------

## Tips - 

 - Make sure to read the comment lines to improve your understanding of the coding section.
 - Ensure that you have the correct port number for the modules as per project requirements.
 - The model is very sensitive to text so ensure any waste you are using does not have text in the model.

----------------------------------------------------------------------------------------------------------------------------------------------------------

## Suggested Improvements - 

 - You can add a code that will check constantly for object detection instead of timing it to detect image every 20 seconds.
 - Due to limited hardware, we only added a single shaft(servo motor) but integrating multiple shafts by using relays will increase the functionalty as      it increase the number of classes.


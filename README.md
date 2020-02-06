# **Rubik'sCubeSolvingAlgorithm**

### This project teaches the user to solve a Rubik cube, without using a particular case, adapting to the mix cube configuration.

## *Componente*: 
- LCD 1602 Module
- Button
- LED
- Wires
- Breadboard
- Arduino Uno R3 or Mega
- Bluetooth Module

## *Beginning:*
The program receives as input the configuration of the mixed cube via the Bluetooth module.
  I used Bluetooth Terminal, connected to the HC-06 device (the module connected to the arduino).
  For easy communication and interpretation between devices I assigned each color a code, as follows:
 
  (W) white        - 0
  
  (Y) yellow     - 1
  
  (R) red       - 2
  
  (G) green      - 3
  
  (B) blue   - 4
  
  (O) orange - 5
 
 At each side of the cube completely inserted, we receive back the displayed side using the color initials in English, for verification.
 Finally, after entering all sides, "Cub filled" is displayed and the following characters are no longer saved.
 
## *Solving the cube:*
 Next, we will receive on the LCD each step that we must execute so that in the end we can solve the Rubik cube.
 In order to solve it, we must follow a set of rules.
 
 1. *Positioning the Rubik's cube:*
  - The face of the cube that has the red square, will be pointed at us.
  
  -The face of the cube that has the yellow middle square will be held up.
  
  - The program offers a correct solution for the cubes that have to the left of the red side, the green side, and to the right of the red side, the blue side.
 
 2. *Moves codes:*
  
  - The capital letters are a movement of the respective layer in the clockwise direction..
  
  - The small letters represent a movement of the respective layer in the opposite direction to the clockwise ones.
  
  - R = right, (the blue side) and r = right reverse 
  
  - L = left, (the green side) and l = left reverse
  
  - U = up, (the yellow side) and u = up reverse
  
  - D = down, (the white side), and d = down reverse
  
  - F = front, (the red side), and f = front reverse
  
  - B = back, (the orange side) and b = back reverse
 
Immediately after entering the cube configuration, the first move appears. After we have performed the respective move in accordance with the above rules, we will press the button and after the adjacent LED lights up, we know that we have moved to the next move.

When we reach the end, the cube will be solved and the LED will remain lit.
  
  
  

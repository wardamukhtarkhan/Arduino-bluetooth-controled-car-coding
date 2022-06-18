// REMOTE CONTROL CAR CODE
//Arduino Bluetooth Controlled Car//

#include <AFMotor.h>
//initial motors pin
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
char command;

void setup() {
  Serial.begin(9600); //Set the baud rate to your Bluetooth module.

}

void loop() {
  if (Serial.available() > 0)
  {
   command = Serial.read();
   Stop(); // initialize with motors stoped
   //Change pin mode only if new command is diferent from previous.
   //Serial.println (command);
   switch (command)
   {
    case 'F':
     forward();
     break;
    case 'B':
     back();
     break;
    case 'L':
     left();
     break;
    case 'R':
     right();
     break; 
   }
  }
}
   void forward()
   {
    motor1.setSpeed(255); // Define maximum velocity
    motor1.run(FORWARD); //Rotate the motor anti-clockwise
    motor2.setSpeed(255);
    motor2.run(FORWARD); 
    motor3.setSpeed(255);
    motor3.run(FORWARD); 
    motor4.setSpeed(255);
    motor4.run(FORWARD);
   }

  void back()
  {
    motor1.setSpeed(255); //Define maximum velocity
    motor1.run(BACKWARD); //Rotate the motor anti-clockwise
    motor2.setSpeed(255);
    motor2.run(BACKWARD); 
    motor3.setSpeed(255);
    motor3.run(BACKWARD); 
    motor4.setSpeed(255);
    motor4.run(BACKWARD); 
  }   
  void left()
  {
    motor1.setSpeed(255); //Define maximum velocity
    motor1.run(BACKWARD); //Rotate the motor anti-clockwise
    motor2.setSpeed(255);
    motor2.run(FORWARD); 
    motor3.setSpeed(255);
    motor3.run(FORWARD); 
    motor4.setSpeed(255);
    motor4.run(BACKWARD);  
  }

  void right()
  {
    motor1.setSpeed(255); //Define maximum velocity
    motor1.run(FORWARD); //Rotate the motor anti-clockwise
    motor2.setSpeed(255);
    motor2.run(BACKWARD); 
    motor3.setSpeed(255);
    motor3.run(BACKWARD); 
    motor4.setSpeed(255);
    motor4.run(FORWARD);  
  } 

  void Stop()
  {
    motor1.setSpeed(0); //Define minimum velocity
    motor1.run(RELEASE); //Stop the motor when release the button
    motor2.setSpeed(0);
    motor2.run(RELEASE); 
    motor3.setSpeed(0);
    motor3.run(RELEASE); 
    motor4.setSpeed(0);
    motor4.run(RELEASE);  
  }    
  

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
#include <Servo.h> 

Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
int pos = 0;    // variable to store the servo position 
int inPin1 = 4;
int inPin2 = 5;
int val1 = HIGH;  
int val2 = HIGH;  

//tray
int motor_1_clock = 13;
int motor_1_anticlock = 12;

//lift motor 2
int motor_2_clock = 8;
int motor_2_anticlock = 7;

// the setup routine runs once when you press reset:

void m1a(){
  digitalWrite(motor_1_clock, HIGH);
  delay(200);
  digitalWrite(motor_1_clock, LOW);
}

void m2c(){
  digitalWrite(motor_2_clock, HIGH);
  delay(1200);
  digitalWrite(motor_2_clock, LOW);
}

void m1c(){
  digitalWrite(motor_1_anticlock, HIGH);
  delay(300);
  digitalWrite(motor_1_anticlock, LOW);
}

void m2a(){
  digitalWrite(motor_2_anticlock, HIGH);
  delay(1200);
  digitalWrite(motor_2_anticlock, LOW);
}

void sweep(){
  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
}

void setup() {                
  // initialize the digital pin as an output.
  pinMode(motor_1_clock, OUTPUT);     
  pinMode(motor_1_anticlock, OUTPUT);     
  pinMode(motor_2_clock, OUTPUT);     
  pinMode(motor_2_anticlock, OUTPUT);
  
  pinMode(inPin1, INPUT);     
  pinMode(inPin2, INPUT);     
  
  digitalWrite(motor_1_clock, LOW);
  digitalWrite(motor_1_anticlock, LOW);
  digitalWrite(motor_2_clock, LOW);
  digitalWrite(motor_2_anticlock, LOW);

  
  myservo.attach(6); 
  
}

void callLift(){
  m2a(); 
  delay(2000);
}

void drop(){
  m2c(); 
  delay(2000);
  sweep();
}

// the loop routine runs over and over ag+ain forever:
void loop() {
//  sweep();
//  m2c();
//  delay(2000);
//  
//  m1c();
//  delay(2000);
//  m1a(); 
//  delay(2000);
//
//  m2a(); 
//  delay(2000);


  val1 = digitalRead(inPin1);
  if(val1 == HIGH){
 
  }else {
    callLift();
  }
 
  val2 = digitalRead(inPin2); 
  if(val2 == HIGH){
   
  }else {
     //m2c(); 
  
    //drop();
  }

}

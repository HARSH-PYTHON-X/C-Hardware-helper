#include <Servo.h>

// BinaryObject 

class BinaryObject
{
  public :

  int Pin ;

  BinaryObject (int Pin)
  {
    this -> Pin = Pin ;
    pinMode(Pin, OUTPUT) ;
  }

  void ON ()
  {
    digitalWrite(Pin, HIGH) ;
  }

  void OFF ()
  {
    digitalWrite(Pin, LOW) ;
  }
} ;

// Swtiches

class Switch
{
  public :

  int Pin ;
  int ButtonState ;

  Switch (int Pin)
  {
    this -> Pin = Pin ;
  }

  int state ()
  {
    ButtonState = digitalRead(Pin) ;

    return  ButtonState ;
  }
} ;

// SERVO

class SERVO
{
  public :

  int Pin ;
  Servo myservo ;

  SERVO (int Pin)
  {
    this -> Pin = Pin ;
  }

  void rotate (float angle)
  {
    myservo.attach(Pin) ;
    myservo.write(angle) ;
  }
} ;

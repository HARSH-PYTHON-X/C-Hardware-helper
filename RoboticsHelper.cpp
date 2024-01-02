#include <Servo.h>

class BinaryObject // Binary Object //
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

class Switch // Switch //
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

class SERVO // SERVO //
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

class UltraSonicSensor // UltraSonicSensor //
{
  public :

  int TriggerPin ;
  int EchoPin ;

  float SoundSpeed = 0.034 ;
  float Distance ;
  long duration ;

  int SerialBeginCode ;

  UltraSonicSensor (int TriggerPin, int EchoPin, int SerialBeginCode)
  {
    this -> TriggerPin = TriggerPin ;
    this -> EchoPin = EchoPin ;
    this -> SerialBeginCode = SerialBeginCode ;
  }

  float distance ()
  {
    Serial.begin(SerialBeginCode) ;
    pinMode(TriggerPin, OUTPUT) ;
    pinMode(EchoPin, INPUT) ;

    digitalWrite(TriggerPin, LOW) ;
    delayMicroseconds(2) ;

    digitalWrite(TriggerPin, HIGH) ;
    delayMicroseconds(10) ;

    digitalWrite(TriggerPin, LOW) ;

    duration = pulseIn(EchoPin, HIGH) ;

    Distance = duration * SoundSpeed / 2 ;

    return Distance ;
  }
} ;

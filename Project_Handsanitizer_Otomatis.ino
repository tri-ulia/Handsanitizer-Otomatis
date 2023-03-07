 #include <Servo.h>

const int TRIG_PIN  = 9; 
const int ECHO_PIN  = 8; 
const int SERVO_PIN = 7; 


Servo servo; 

float duration_us, distance_cm;

void setup() {
  Serial.begin (9600);      
  pinMode(TRIG_PIN, OUTPUT); 
  pinMode(ECHO_PIN, INPUT);
  servo.attach(SERVO_PIN);
  servo.write(135);
}

void loop() {
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration_us = pulseIn(ECHO_PIN, HIGH);

  distance_cm = 0.017 * duration_us;
  

  if(distance_cm >=10 && distance_cm <=30)
   { servo.write(25); 
    delay(120);
    }
    
  else
    servo.write(135);  


  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(500);
}

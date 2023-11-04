const int motor1EN = 11; // Enable for motor 1(riht) (PWM)
const int motor2EN = 12; // Enable for motor 2 (left)(PWM)
const int motor1IN1 = 9; //en1
const int motor1IN2 = 5; //en2
const int motor2IN1 = 10; //en3
const int motor2IN2 = 6; //en4


void setup() {
  pinMode(motor1EN, OUTPUT);
  pinMode(motor2EN, OUTPUT);
  pinMode(motor1IN1, OUTPUT);
  pinMode(motor1IN2, OUTPUT);
  pinMode(motor2IN1, OUTPUT);
  pinMode(motor2IN2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  char command = 'x';  
 
  if (Serial.available() > 0) {
    command = Serial.read();
  }

  if (command == 'g') { 
    // Move the motors
    digitalWrite(motor1IN1, HIGH);
    digitalWrite(motor1IN2, LOW);
    analogWrite(motor1EN, 200);

    digitalWrite(motor2IN1, HIGH);
    digitalWrite(motor2IN2, LOW);
    analogWrite(motor2EN, 200);
  }
   else if(command == 'r') {
    // stop the motors
     digitalWrite(motor1IN1, HIGH);
    digitalWrite(motor1IN2, LOW);
    analogWrite(motor1EN, 1);

    digitalWrite(motor2IN1, HIGH);
    digitalWrite(motor2IN2, LOW);
    analogWrite(motor2EN, 1); 
  }
  
}

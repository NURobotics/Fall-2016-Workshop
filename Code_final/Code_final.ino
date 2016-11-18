const float pi = 3.141596;

const int en1 = 9;
const int dir1 = 6;

const int en2 = 16;
const int dir2 = 17;

const int x = 15;
const int y = 14;

const int led = 13;

//BE SURE TO CHANGE THE ABOVE PINS TO THE ONES CONNECTED ON YOUR TEENSY

int x_in, y_in, x_new, y_new, x_wheel, y_wheel;
//xnew is one wheel, ynew is other wheel

float star;

void setup() {
  Serial.begin(9600);
  pinMode(en1, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(en2, OUTPUT);

  pinMode(led, OUTPUT);
  pinMode(x, INPUT);
  pinMode(y, INPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(led, HIGH);
  x_in = analogRead(x) - 492;
  y_in = analogRead(y) - 500;

  x_new = x_in * cos(pi / 4) + y_in * sin(pi / 4);
  y_new = -x_in * sin(pi / 4) + y_in * cos(pi / 4);

  move_motor1(y_new);
  move_motor2(x_new);

  Serial.print("x: ");
  Serial.print(x_in);
  Serial.print(" y: ");
  Serial.println(y_in);

}

void move_motor1(int spd) {
  if (spd >= 0) {
    analogWrite(en1, spd);
    digitalWrite(dir1, HIGH);
  } else if (x_in < 0) {
    analogWrite(en1, -spd);
    digitalWrite(dir1, LOW);
  }

}

void move_motor2(int spd) {
  if (spd >= 0) {
    analogWrite(en2, spd);
    digitalWrite(dir2, HIGH);
  } else if (y_in < 0) {
    analogWrite(en2, -spd);
    digitalWrite(dir2, LOW);
  }

}

void all_stop() {
  analogWrite(en1, 0);
  analogWrite(en2, 0);
}


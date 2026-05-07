// تعريف البنات (غيرهم حسب التوصيل عندك)
#define IN1 8
#define IN2 9
#define IN3 12
#define IN4 13

int stepDelay = 2; // سرعة الموتور (قلل الرقم = أسرع)

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

// حركة خطوة واحدة
void stepMotor(int step) {
  switch(step) {
    case 0:
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      break;
    case 1:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      break;
    case 2:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      break;
    case 3:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      break;
  }
}

// دوران للأمام
void rotateForward(int steps) {
  for(int i = 0; i < steps; i++) {
    stepMotor(i % 4);
    delay(stepDelay);
  }
}

// دوران للخلف
void rotateBackward(int steps) {
  for(int i = 0; i < steps; i++) {
    stepMotor(3 - (i % 4));
    delay(stepDelay);
  }
}

void loop() {
  rotateForward(2048); // لفة كاملة تقريباً
  delay(1000);

  rotateBackward(2048);
  delay(1000);
}
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {2,3,4,5};
byte colPins[COLS] = {6,7,8,9};

Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

#define GREEN_LED_PIN 10
#define RED_LED_PIN   11
#define BUZZER_PIN    12
#define MATCH_PIN     13
#define RELAY_PIN     A5

#define DATA_BIT_1_PIN A0
#define DATA_BIT_2_PIN A1
#define DATA_BIT_3_PIN A2
#define DATA_BIT_4_PIN A3
#define CLOCK_PIN      A4

char enteredPassword[5];
int keyCount = 0;

void setup() {
  Serial.begin(9600);

  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  pinMode(DATA_BIT_1_PIN, OUTPUT);
  pinMode(DATA_BIT_2_PIN, OUTPUT);
  pinMode(DATA_BIT_3_PIN, OUTPUT);
  pinMode(DATA_BIT_4_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);

  pinMode(MATCH_PIN, INPUT);

  digitalWrite(RELAY_PIN, HIGH);
}

void loop() {
  char key = kpd.getKey();

  if (key) {
    if ((key == '0' || key == '1') && keyCount < 4) {
      enteredPassword[keyCount++] = key;
      Serial.print("*");
    }
    else if (key == '#') {
      if (keyCount == 4) {
        enteredPassword[4] = '\0';
        checkPassword();
      }
      clearPasswordData();
    }
    else if (key == '*') {
      clearPasswordData();
    }
  }
}

void checkPassword() {
  digitalWrite(DATA_BIT_1_PIN, enteredPassword[0] == '1');
  digitalWrite(DATA_BIT_2_PIN, enteredPassword[1] == '1');
  digitalWrite(DATA_BIT_3_PIN, enteredPassword[2] == '1');
  digitalWrite(DATA_BIT_4_PIN, enteredPassword[3] == '1');

  digitalWrite(CLOCK_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(CLOCK_PIN, LOW);

  delay(5);

  if (digitalRead(MATCH_PIN) == HIGH)
    accessGranted();
  else
    accessDenied();
}

void accessGranted() {
  digitalWrite(GREEN_LED_PIN, HIGH);
  digitalWrite(RELAY_PIN, LOW);
  delay(5000);
  digitalWrite(RELAY_PIN, HIGH);
  digitalWrite(GREEN_LED_PIN, LOW);
}

void accessDenied() {
  digitalWrite(RED_LED_PIN, HIGH);
  for (int i = 0; i < 3; i++) {
    tone(BUZZER_PIN, 1000);
    delay(200);
    noTone(BUZZER_PIN);
    delay(100);
  }
  digitalWrite(RED_LED_PIN, LOW);
}

void clearPasswordData() {
  keyCount = 0;
  for (int i = 0; i < 5; i++)
    enteredPassword[i] = 0;
}

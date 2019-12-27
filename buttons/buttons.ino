#include "keys.h"

const byte rowAmount = 4;
const byte colAmount = 4;

char keys[rowAmount][colAmount] = {keyUp, keyLeft, keyRight, keyDown};

//расположение кнопок
int keyIndexes[4][2] = {
  {0, 1}, {1, 0}, {1, 2}, {2, 1}
};

static bool keyDownMatrix[rowAmount][colAmount];

byte rowPins[rowAmount] = { 5, 4, 3, 2 };
byte colPins[colAmount] = { 6, 7, 8, 9 };

void setup()
{
  for (int i = 0; i < rowAmount; i++) {
    pinMode(rowPins[i], OUTPUT);
    digitalWrite(rowPins[i], HIGH);
  }

  for (int i = 0; i < colAmount; i++) {
    pinMode(colPins[i], INPUT);
    digitalWrite(colPins[i], HIGH);
  }
  Serial1.begin(115200);
}

void loop()
{
  char key = getKey();
  if (key != keyNone) {
    Serial1.write(key);
  }
  delay(15);
}

char getKey()
{
  char result = keyNone;
  for (int k = 0; k < rowAmount; k++){
    int i = keyIndexes[k][0];
    int j = keyIndexes[k][1];
    if (isKeyDown(i, j))
       result = keys[i][j];
  }
  
  return result;
}

bool isKeyDown(int i, int j)
{
  bool result = false;
  digitalWrite(rowPins[i], LOW);
  if (digitalRead(colPins[j]) == LOW) {
    result = true;
  }
  digitalWrite(rowPins[i], HIGH);
  return result;
}

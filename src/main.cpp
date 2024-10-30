#include <Arduino.h>
#include "lib.h"

void setup() {
  // put your setup code here, to run once:

  initSensors();
}

void loop() {
  // put your main code here, to run repeatedly:
  mesureDistance(1);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}
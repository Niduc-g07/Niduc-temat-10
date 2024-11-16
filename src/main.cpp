#include <Arduino.h>
#include "lib.h"
#include "TMR.h"
#include "Median.h"

void setup() {
  // put your setup code here, to run once:
  initSensors();
}

void loop() {
  // put your main code here, to run repeatedly:
  majority_vote(mesureDistance(1),mesureDistance(2),mesureDistance(3));
  find_median_sorted(mesureDistance(1),mesureDistance(2),mesureDistance(3));
  
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}
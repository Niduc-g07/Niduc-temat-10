#include <Arduino.h>
#include "lib.h"
#include "majority.h"
#include "Median.h"
#include "Iterative.h"

void setup() {
  // put your setup code here, to run once:
  initSensors();
}

void loop() {
  // put your main code here, to run repeatedly:
  majority_vote(mesureDistance(1),mesureDistance(2),mesureDistance(3));
  find_median_sorted(mesureDistance(1),mesureDistance(2),mesureDistance(3));
  three_domain_voters(mesureDistance(1),mesureDistance(2),mesureDistance(3));
  iterative_vote(mesureDistance(1),mesureDistance(2),mesureDistance(3));

  delay(100);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}
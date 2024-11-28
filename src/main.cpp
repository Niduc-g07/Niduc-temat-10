#include <Arduino.h>
#include "lib.h"
#include "majority.h"
#include "Median.h"
#include "Iterative.h"


double *data;
void setup() {

  initSensors();        //inicjalizacja czujników
  Serial.begin(9600);   //inicjalizacja portu seryjnego

}

void loop() {
  data = allDistances();                            //szczytanie pomiaru z czujników

  Serial.print("Glosowanie 1: ");                   //wypisanie wyniku algorytmu ?
  Serial.println(majority_vote(data[0], data[1], data[2]));

  Serial.print("Glosowanie 2: ");                   //wypisanie wyniku algorytmu ?
  Serial.println(find_median_sorted(data[0], data[1], data[2]));
  
  Serial.print("Glosowanie 3: ");                   //wypisanie wyniku algorytmu ?
  Serial.println(three_domain_voters(data[0], data[1], data[2]));

  Serial.print("Glosowanie 4: ");                   //wypisanie wyniku algorytmu ?
  Serial.println(iterative_vote(data[0], data[1], data[2]));

  delay(2000);
}

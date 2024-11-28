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

  Serial.print("Wyniki pomiarow:\n1. ");            //wypisanie wynikow do konsoli
  Serial.print(data[0]);
  Serial.print("cm\n2. ");
  Serial.print(data[1]);
  Serial.print("cm\n3. ");
  Serial.print(data[2]);
  Serial.print("cm\n");

  Serial.print("Algorytm ?: ");                     //wypisanie wyniku algorytmu ?
  Serial.println(majority_vote(data[0], data[1], data[2]));

  Serial.print("Algorytm ?: ");                     //wypisanie wyniku algorytmu ?
  Serial.println(find_median_sorted(data[0], data[1], data[2]));
  
  Serial.print("Algorytm ?: ");                     //wypisanie wyniku algorytmu ?
  Serial.println(three_domain_voters(data[0], data[1], data[2]));

  Serial.print("Algorytm ?: ");                     //wypisanie wyniku algorytmu ?
  Serial.println(iterative_vote(data[0], data[1], data[2]));

  delay(2000);
}

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
  data = allDistances();                              //szczytanie pomiaru z czujników

  Serial.print("\nWyniki pomiarow:\n1. ");            //wypisanie wynikow do konsoli
  Serial.print(data[0]);
  Serial.print("cm\n2. ");
  Serial.print(data[1]);
  Serial.print("cm\n3. ");
  Serial.print(data[2]);
  Serial.print("cm\n");

  Serial.print("Algorytm majority_vote: ");                           //wypisanie wyniku algorytmu majority_vote
  Serial.println(majority_vote(data[0], data[1], data[2]));

  Serial.print("Algorytm find_median_sorted: ");                      //wypisanie wyniku algorytmu find_median_sorted
  Serial.println(find_median_sorted(data[0], data[1], data[2]));
  
  Serial.print("Algorytm three_domain_voters: ");                     //wypisanie wyniku algorytmu three_domain_voters
  Serial.println(three_domain_voters(data[0], data[1], data[2]));

  Serial.print("Algorytm iterative_vote: ");                          //wypisanie wyniku algorytmu iterative_vote
  Serial.println(iterative_vote(data[0], data[1], data[2]));

  free(data);

  delay(1500);
}

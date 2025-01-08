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

  // Serial.print("\nWyniki pomiarow:\n1. ");            //wypisanie wyników pomiarów do konsoli
  Serial.print(data[0]);
  Serial.print("; ");
  Serial.print(data[1]);
  Serial.print("; ");
  Serial.print(data[2]);
  Serial.print("; ");

  // Serial.print("Algorytm glosowania wiekszosciowego: ");                            //wypisanie wyniku algorytmu głosowania większościowego 
  Serial.print(majority_vote(data[0], data[1], data[2]));
  Serial.print("; ");

  // Serial.print("Algorytm medianowy: ");                                             //wypisanie wyniku algorytmu medianowego
  Serial.print(find_median_sorted(data[0], data[1], data[2]));
  Serial.print("; ");
  
  // Serial.print("Algorytm odrzucenia najwiekszej roznicy: ");                        //wypisanie wyniku algorytmu odrzucenia największej różnicy
  Serial.print(large_difference_rejection(data[0], data[1], data[2]));
  Serial.print("; ");

  // Serial.print("Algorytm iteracyjny: ");                                            //wypisanie wyniku algorytmu iteracyjnego
  Serial.println(iterative_vote(data[0], data[1], data[2]));


  free(data);                                       //zwolnienie pamięci

  delay(1500);
}

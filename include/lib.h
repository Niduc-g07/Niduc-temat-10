#define trigerPIN1 22                   //definicja pinów wykorzystywanych do pomiarów
#define trigerPIN2 26
#define trigerPIN3 30
#define echoPIN1 23
#define echoPIN2 27
#define echoPIN3 31

void initSensors(){                     //inicjalizacja wykorzystywanych pinów
    pinMode(trigerPIN1, OUTPUT);
    pinMode(trigerPIN2, OUTPUT);
    pinMode(trigerPIN3, OUTPUT);
    pinMode(echoPIN1, INPUT);
    pinMode(echoPIN2, INPUT);
    pinMode(echoPIN3, INPUT);
    return;
}

double mesureDistance (short index){    //funkcja odczytania pomiarów z czujników, jako argument przyjmuje indeks czujnika
                                        //zwraca odległość jako zmienna double

    digitalWrite(trigerPIN1, LOW);      //ustawienie wszystkich czujników w stan spoczynku
    digitalWrite(trigerPIN2, LOW);
    digitalWrite(trigerPIN3, LOW);

    delayMicroseconds(2);               //odczekanie aż czujniki przejdą w odpowiedni stan

    double result;

    switch (index%3){
        case 0:
            digitalWrite(trigerPIN1, HIGH);     //załącza wybrany czujnik
            delayMicroseconds(10);              //odczekuje na zmiane stanu czujnika
            digitalWrite(trigerPIN1, LOW);      //wysłanie wygnału dźwiękowego z czujnika

            result = pulseIn(echoPIN1, HIGH);   //odczytanie po jakim czasie dźwięk wrócił
            break;
        
        case 1:
            digitalWrite(trigerPIN2, HIGH);
            delayMicroseconds(10);
            digitalWrite(trigerPIN2, LOW);

            result = pulseIn(echoPIN2, HIGH);
            break;

        case 2:
            digitalWrite(trigerPIN3, HIGH);
            delayMicroseconds(10);
            digitalWrite(trigerPIN3, LOW);

            result = pulseIn(echoPIN3, HIGH);
            break;
    }

    result *= (0.0343/2.0);                 //zamiana czasu od wysłania do powrotu dźwięku na odległość 
                                            //(mnożymy razy prędkość dźwięku w powietrzu i dzielimy przez 2, ponieważ sygnał przebył drogę dwa razy)

    return result;
}

double *allDistances(){                     //odczytuje odległości z wszystkich czujników i zwraca je w tabeli zmiennych double
    double *result = (double*)malloc(sizeof(double)*3);

    for(int i = 0; i < 3; i++){
        result[i] = mesureDistance(i);
        delay(100);
    }

    result[1]++;
    
    return result;
}
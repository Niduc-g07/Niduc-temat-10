#define trigerPIN1 22
#define trigerPIN2 24
#define trigerPIN3 26
#define echoPIN1 23
#define echoPIN2 25
#define echoPIN3 27

void initSensors(){
    pinMode(trigerPIN1, OUTPUT);
    pinMode(trigerPIN2, OUTPUT);
    pinMode(trigerPIN3, OUTPUT);
    pinMode(echoPIN1, INPUT);
    pinMode(echoPIN2, INPUT);
    pinMode(echoPIN3, INPUT);
    return;
}

double mesureDistance (short index){

    digitalWrite(trigerPIN1, LOW);
    digitalWrite(trigerPIN2, LOW);
    digitalWrite(trigerPIN3, LOW);

    delayMicroseconds(2);

    double result;

    switch (index%3){
        case 0:
            digitalWrite(trigerPIN1, HIGH);
            delayMicroseconds(10);
            digitalWrite(trigerPIN1, LOW);

            result = pulseIn(echoPIN1, HIGH);
            break;
        
        case 1:
            digitalWrite(trigerPIN2, HIGH);
            delayMicroseconds(10);
            digitalWrite(trigerPIN2, LOW);

            result = pulseIn(echoPIN2, HIGH);
            break;

        case 2:
            digitalWrite(trigerPIN2, HIGH);
            delayMicroseconds(10);
            digitalWrite(trigerPIN2, LOW);

            result = pulseIn(echoPIN3, HIGH);
            break;
    }

    result *= (0.0343/2.0);

    return result;
}

double *allDistances(){
    double result[3];

    for(int i = 0; i < 3; i++)
        result[i] = mesureDistance(i);

    return result;
}
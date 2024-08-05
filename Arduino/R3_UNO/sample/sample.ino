#define ONE_WIRE 3

void setup(){
    //pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
}

void loop(){
    pinMode(ONE_WIRE, OUTPUT);
    digitalWrite(ONE_WIRE, LOW);
    delayMicroseconds(500);

    pinMode(ONE_WIRE, INPUT); // LOW 에서 HIGH로 변함
    delayMicroseconds(10);
    
    int32_t time = 0;
    while (++time < 2000000)
    {
        if(digitalRead(ONE_WIRE) == HIGH);
        else Serial.println("Reset Pulse");
        delayMicroseconds(1);
    }

    delay(2);
}

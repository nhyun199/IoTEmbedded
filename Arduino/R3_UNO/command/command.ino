#define ONE_WIRE 3

bool Reset(){
    digitalWrite(ONE_WIRE, LOW);
    pinMode(ONE_WIRE, OUTPUT);

    delayMicroseconds(500);
    pinMode(ONE_WIRE, INPUT);
    delayMicroseconds(100);
     
    
    if(digitalRead(ONE_WIRE) == LOW)
    {
        delayMicroseconds(380);
        //Serial.println("Reset Pulse");
        return true;
    }
    else // HIGH
    {
        return false;
    }   
}

void setup(){
    Serial.begin(9600);
}

void loop(){
    
}


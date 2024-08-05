#define RED 9
#define GREEN 10
#define BLUE 11
#define Button 2
int i = 0;
bool buttonPressed = false;
bool lastButtonState = LOW;

void setup() 
{
  pinMode(Button, INPUT);  
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  Serial.begin(9600);
  while(!Serial) {
  }
  Serial.println("Serial Port Connected.");
}

void loop() 
{
  int buttonState = digitalRead(Button);
  
  if(buttonState != lastButtonState)
  {

    if (buttonState == HIGH && !buttonPressed) 
    {
      Serial.print("Button Pressed. i = ");
      Serial.println(i);        
      buttonPressed = true;
      switch(i % 3)
      {
       case 0 :
          analogWrite(RED, 255);
          analogWrite(BLUE, 221);
          delay(3000);
          analogWrite(RED, 0);
          analogWrite(BLUE, 0);
         break;
       case 1 :
          analogWrite(RED, 0);
          analogWrite(GREEN, 209);
          analogWrite(BLUE, 0);
          delay(3000);
          analogWrite(RED, 0);
          analogWrite(GREEN, 0);
          analogWrite(BLUE, 0);
         break;
        case 2 :
          analogWrite(RED, 255);
          analogWrite(GREEN, 228);          
         delay(3000);
          analogWrite(RED, 0);
          analogWrite(GREEN, 0);          
          break;
      }
      i++;
    }
    else if(buttonState == LOW && buttonPressed)
    {
      buttonPressed = false;
      analogWrite(RED, 0);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 0);
      delay(30);
      Serial.println("Button Not Pressed.");
    }
    lastButtonState = buttonState;
  }  
}

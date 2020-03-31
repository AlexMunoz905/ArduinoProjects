/* sketch 2 
turn on a LED when the button is pressed and let it on when the button is released
*/
int pinButton = 9; //the pin where we connect the button
int LED = 13; //the pin we connect the LED

void setup() {
  pinMode(pinButton, INPUT); //set the button pin as INPUT
  pinMode(LED, OUTPUT); //set the LED pin as OUTPUT
}

void loop() {
  int stateButton = digitalRead(pinButton); //read the state of the button
  if(stateButton == 1) { //if is pressed
     digitalWrite(LED, HIGH); //write 1 or HIGH to led pin
  }
}

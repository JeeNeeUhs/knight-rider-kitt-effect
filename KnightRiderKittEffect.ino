/*materials
 * 1 arduino uno
 * 9 led
 * 1 potantiometer
 * 1 buzzer
 * 34 jumper cable (estimated)
 * 330 ohm resistor
 */
#define buzzer 11 // buzzer 
#define pot A0 // potantiometer
int fast = 50 ; //flash speed
int leds[] = {2,3,4,5,6,7,8,9,10}; //led pins

void setup() {
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  for(int i=0; i<9; i++){
  pinMode(leds[i], OUTPUT);
  }
}

void loop() {

  fast = analogRead(pot);
  Serial.println(fast);

  for(int i=0; i<9; i++){
    fast = analogRead(pot);
    Serial.println(fast/4);
    digitalWrite(buzzer, LOW);
    digitalWrite(leds[i], HIGH);
    delay(fast/4);
    fast = analogRead(pot);
    Serial.println(fast/4);
    digitalWrite(buzzer, HIGH);
    digitalWrite(leds[i], LOW);
  }

  for(int j=8; j>-1; j--){
    fast = analogRead(pot);
    Serial.println(fast/4);
    digitalWrite(buzzer, LOW);
    digitalWrite(leds[j], HIGH);
    delay(fast/4);
    fast = analogRead(pot);
    Serial.println(fast/4);
    digitalWrite(buzzer, HIGH);
    digitalWrite(leds[j], LOW);
  }

}

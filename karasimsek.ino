/*materials
 * 9 led
 * 1 potantiometer
 * 1 buzzer
 * 34 jumper cable (estimated)
 * 330 ohm resistor
 */
#define buzzer 11 // buzzer 
#define pot A0 // potantiometer
int fast = 50 ; //speed
int ledler[] = {2,3,4,5,6,7,8,9,10}; //led pins

void setup() {
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  
  

  for(int i=0; i<9; i++){
    
  pinMode(ledler[i], OUTPUT);
  
  }

}

void loop() {

  fast = analogRead(pot);
  Serial.println(fast);

  for(int i=0; i<9; i++){
    fast = analogRead(pot);
    Serial.println(fast/4);
    digitalWrite(buzzer, LOW);
    digitalWrite(ledler[i], HIGH);
    delay(fast/4);
    fast = analogRead(pot);
    Serial.println(fast/4);
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledler[i], LOW);
  }

  for(int j=8; j>-1; j--){
    fast = analogRead(pot);
    Serial.println(fast/4);
    digitalWrite(buzzer, LOW);
    digitalWrite(ledler[j], HIGH);
    delay(fast/4);
    fast = analogRead(pot);
    Serial.println(fast/4);
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledler[j], LOW);
  }

}

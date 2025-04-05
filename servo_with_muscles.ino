#include <Wire.h>
#include <iarduino_I2C_Matrix_8x8.h>
#include <Servo.h>
iarduino_I2C_Matrix_8x8 disp(0x09);


Servo mys;
int val = 0;
int imp = 0;
bool state = false;

void setup() {
  delay(500);
  disp.begin(&Wire);

  mys.attach(10);
  mys.write(30);
  delay(500);
  Serial.begin(115200);
  pinMode(13, OUTPUT); 
}
void loop() {
  val = analogRead(A0);
  imp = (map(val, 0, 1023, 0, 255));
  Serial.println(imp);

  if (imp > 165) {
    state = !state;
    Serial.println(state);
    if (state) {
      digitalWrite(13, HIGH);
      mys.write(90);
      disp.fillScr(X8_DOWN   ); delay(1000);
      delay(2000);
    }
    else {
      digitalWrite(13, LOW);
      mys.write(0);
      disp.clrScr (X8_DOWN   ); delay(1000);
      delay(2000);
    }

    delay(2000);
  }
 delay(250); 
}
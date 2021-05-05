int pinO2 = 0; // analog input pin 0
int input10bit = 0; // expected values: 0 - 1023
float inputVolt = 0.00; // expected values: 0 - 5

int pinR = 9; // PWM output pin 9
int pinG = 10; // PWM output pin 10
int pinB = 11; // PWM output pin 11

// 14point7 SLC Free: Voltage = (AFR - 9.996) / (9.996 / 5)
float minVoltCyan = 1.25; // corresponds to AFR of 12.495:1 (Lambda of 0.85)
float minVoltGreen = 2.21; // corresponds to AFR of 14.406:1 (Lambda of 0.98)
float minVoltYellow = 2.50; // corresponds to AFR of 14.994:1 (Lambda of 1.02)
float minVoltRed = 2.72; // corresponds to AFR of 15.435:1 (Lambda of 1.05)

// LDperformance Wideband Controller: Voltage = (AFR - 7.35) / (15.04 / 5)
//float minVoltCyan = 1.71; // corresponds to AFR of 12.495:1 (Lambda of 0.85)
//float minVoltGreen = 2.35; // corresponds to AFR of 14.406:1 (Lambda of 0.98)
//float minVoltYellow = 2.54; // corresponds to AFR of 14.994:1 (Lambda of 1.02)
//float minVoltRed = 2.69; // corresponds to AFR of 15.435:1 (Lambda of 1.05)

void setup() {
  pinMode(pinO2, INPUT);
  //Serial.begin(9600);

  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
}

void loop() {
  input10bit = analogRead(pinO2);
  inputVolt = (input10bit * 5.00) / 1023; // 5V corresponds to 1023
  //Serial.println(inputVolt);

  if (inputVolt < minVoltCyan) {
    setColor(0, 0, 255); // blue
  }
  else if (inputVolt < minVoltGreen) {
    setColor(0, 255, 255); // cyan
  }
  else if (inputVolt < minVoltYellow) {
    setColor(0, 255, 0); // green
  }
  else if (inputVolt < minVoltRed) {
    setColor(255, 255, 0); // yellow
  }
  else {
    setColor(255, 0, 0); // red
  }

  delay(20); // reading circa 50 times a second should be plenty
}

void setColor(int valueR, int valueG, int valueB) {
  analogWrite(pinR, valueR);
  analogWrite(pinG, valueG);
  analogWrite(pinB, valueB);
}

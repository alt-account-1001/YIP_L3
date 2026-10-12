// define the channel pins
const int channel_1 = A0;

void setup()
{
  // set the pin modes
  pinMode(channel_1, INPUT);

  // initialize the serial port
  Serial.begin(9600);
}

void loop()
{
  // read the values
  int value_1 = pulseIn(channel_1, HIGH);
  Serial.print("\nch1: ");
  Serial.print(value_1);

  // delay for smooth performance
  delay(1000);
}
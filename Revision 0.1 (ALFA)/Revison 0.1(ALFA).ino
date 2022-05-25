# include <Bounce.h>
# include <MIDI.h>
MIDI_CREATE_INSTANCE(HardwareSerial, Serial2, MIDI);

Bounce button0 = Bounce(0, 5);
Bounce button1 = Bounce(1, 5);
Bounce button2 = Bounce(2, 5);
Bounce button3 = Bounce(3, 5);

void setup() {
  pinMode(0, INPUT_PULLUP);
  pinMode(0, INPUT_PULLUP);
  pinMode(0, INPUT_PULLUP);
  pinMode(0, INPUT_PULLUP);
  MIDI.begin(MIDI_CHANNEL_OMNI);
  Serial2.setTX(10);
  Serial2.setRX(9);
  Serial.begin(31250);
  Serial.println("TeeMidi Revision 2.0(Marmalade");
  delay(1000);
  Serial.println("Made By Joel Mathew Reji (JMR Technologies");
}

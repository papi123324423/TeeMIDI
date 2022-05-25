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

void loop()  {
  button0.update();
  button1.update();
  button2.update();
  button3.update();

  if (button0.fallingEdge()) {
    MIDI.sendNoteOn(60, 64, 1);
    Serial.println("C on");  
  }
if (button0.fallingEdge()) {
    MIDI.sendNoteOn(61, 64, 1);
    Serial.println("C# on");
  }
if (button0.fallingEdge()) {
    MIDI.sendNoteOn(62, 64, 1);
    Serial.println("D on");
  }
if (button0.fallingEdge()) {
    MIDI.sendNoteOn(63, 64, 1);
    Serial.println("Eb on");
  }


if (button0.fallingEdge()) {
    MIDI.sendNoteOff(60, 0, 1);
    Serial.println("C on");
  }
  if (button0.fallingEdge()) {
    MIDI.sendNoteOff(61, 0, 1);
    Serial.println("C on");
  }
  if (button0.fallingEdge()) {
    MIDI.sendNoteOff(62, 0, 1);
    Serial.println("C on");
  }
  if (button0.fallingEdge()) {
    MIDI.sendNoteOff(63, 0, 1);
    Serial.println("C on");
  }

 int type, note, velocity, channel, d1, d2;
 if (MIDI.read()) {
  byte type = MIDI.getType();
  switch (type) {
    case midi::NoteOn:
    note = MIDI.getData1();
    velocity = MIDI.getData2();
    channel = MIDI.getChannel();
     if (velocity > 0) {
          Serial.println(String("Note On:  ch=") + channel + ", note=" + note + ", velocity=" + velocity);
        } else {
          Serial.println(String("Note Off: ch=") + channel + ", note=" + note);
        }
     break;


   case midi::NoteOff:
     note = MIDI.getData1();
     velocity = MIDI.getData2();
     channel = MIDI.getChannel(); 
     Serial.println(String("Note Off: ch=") + channel + ", note=" + note + ", velocity=" + velocity);
        break;
        
       default:
          d1 = MIDI.getData1();
          d2 = MIDI.getData2();
          if (type == 254) {
          }
          else {
          Serial.println(String("Message, type=") + type + ", data = " + d1 + " " + d2);  
          }

  
    } 

  }
}     
  
        

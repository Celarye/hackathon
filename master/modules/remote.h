#include <IRremote.h>

int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);

decode_results results;

void remoteSetup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  Serial.println("Remote setup succeeded");
}

int remoteLoop()
{
  Serial.println("Remote is listening...");
  while (true)
  {
    if (irrecv.decode(&results))
    {
      switch (results.value)
      {
      case 0xC101E57B:
        Serial.println("Remote value detected: ON");
        return 1;

      default:
        Serial.println("Remote value detected: Unrecognized, try again...");
        irrecv.resume();
        break;
      }
    }
  }
}

#include <IRremote.h>

int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);

decode_results results;

void remoteSetup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}

int remoteLoop()
{
  while (true)
  {
    Serial.println("Remote Loop");
    if (irrecv.decode(&results))
    {
      Serial.print("Received value: ");
      Serial.println(results.value, HEX);

      switch (results.value)
      {
      case 0x1BC0157B:
        Serial.println("Remote-detected: RESTART");
        irrecv.resume();
        return 0;
      case 0xC101E57B:
        Serial.println("Remote-detected: ON");
        irrecv.resume();
        return 1;

      default:
        irrecv.resume();
        break;
      }
    }
  }
}

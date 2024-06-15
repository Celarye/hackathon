#include <IRremote.h>

int RECV_PIN = 2;

IRrecv irrecv(RECV_PIN);

decode_results results;

void testsetup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void testloop()
{
  if (irrecv.decode(&results))
  {
    Serial.println(results.value, HEX);


    irrecv.resume();
  }
  delay(100);
}
int relay1 = LIGHT_1;  //This is the Arduino Pin that will control Relay #1
int relay2 = LIGHT_2;  //This is the Arduino Pin that will control Relay #2

void relayInit() 
{
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);  
}

void outsideLightRelayOn()
{
  digitalWrite(relay1, HIGH);    //Switch Relay #1 ON
}

void outsideLightRelayOff()
{
  digitalWrite(relay1, LOW);    //Switch Relay #1 OFF
}

void insideLightRelayOn()
{
  digitalWrite(relay2, HIGH);    //Switch Relay #2 ON
}

void insideLightRelayOff()
{
  digitalWrite(relay2, LOW);    //Switch Relay #2 OFF
}

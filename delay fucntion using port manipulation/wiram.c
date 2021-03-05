unsigned long int secc;
int main(void)
{
  DDRB|=(1<<DDB0);
  while(1)
  {
    PORTB|=(1<<PB0);
    wiram(2000);
    PORTB&=~(1<<PB0);
    wiram(2000);
  }
}
void wiram(int compare)
{
  secc=0;

    // Set the Timer Mode to CTC
    TCCR0A |= (1 << WGM01);

    // Set the value that you want to count to
    OCR0A = 0xF9;

    TIMSK0 |= (1 << OCIE0A);    //Set the ISR COMPA vect

    sei();         //enable interrupts


    TCCR0B |= (1 << CS01)|(1 << CS00);
    // set prescaler to 64 and start the timer

	
  	Serial.begin(9600);
    while (secc!=compare)
    {
      //Serial.println(secc);//main loop
      
    }
}


ISR (TIMER0_COMPA_vect)  // timer0 overflow interrupt
{
  secc=secc+1;;
    //incremented every 1s here
}


/*void setup()
{
  pinMode(8, OUTPUT);
}

void loop()
{
  digitalWrite(8, HIGH);
  wiram(5000); // Wait for 1000 millisecond(s)
  digitalWrite(8, LOW);
  wiram(5000); // Wait for 1000 millisecond(s)
}*/

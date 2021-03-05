/* //test code
void setup(){pinMode(6,OUTPUT);}
void loop(){
tone(6,5000);}*/

int ss=0;
int sss=0;
void toney(uint32_t frequency)
{
  TCCR0A=0;
  TCCR0B=0;
  TCNT0=0;
 // cli(); //pause interrupts
  DDRD|=(1<<DDD5)|(1<<DDD6);
//----------------------------------------------------------------------------------
  
  //Waveform Generation Mode bits (WGM): these control the overall mode of the timer. (TCCRnA and TCCRnB.)
  /*TCCR0A|=(1<<WGM00)|(1<<WGM01); //FAST PWM
  TCCR0B|=(1<<WGM02);*/
  // TCCR0A|=(1<<WGM01); //non PWM-CTC
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
   TCCR0A|=(1<<WGM00);//|(1<<WGM02); //Phase correct PWM TOP=OCRA
//-----------------------------------------------------------------------

  
  
  
//----------------------------------------------------------------------
//*************************************************************************
  //Clock Select bits (CS): these control the clock prescaler=256.  //64
  //TCCR0B|= /*(1<<CS02); */ (1<<CS00)|(1<<CS01);
  if(frequency>7813&&frequency<=62500){
    TCCR0B=TCCR0B&B11111000|B00000001;
  }
  else if(frequency>62&&frequency<=245)
  {
        TCCR0B=TCCR0B&B11111000|B00000100;
  }
   else if(frequency>977&&frequency<=7813)
  {
        TCCR0B=TCCR0B&B11111000|B00000010;
  }
   else if(frequency>245&&frequency<=977)
  {
        TCCR0B=TCCR0B&B11111000|B00000011;
  }
   else if(frequency<=62)
  {
        TCCR0B=TCCR0B&B11111000|B00000101;
  }
//-----------------------------------------------------------------------
  
  
  
  
  
//-----------------------------------------------------------------------
  //Compare Match Output A Mode bits (COMnA): these enable/disable/invert output A
 /* TCCR0A|=(1<<COM0A1); //NON INVERTING FAST PWM 
  TCCR0A&=(~(1<<COM0A0)); //NON INVERTING FAST PWM*/
   //TCCR0A|=(1<<COM0A1)|(1<<COM0A0); //FAST INVERTING
  // TCCR0A|=(1<<COM0A1)|(1<<COM0A0); //non PWM-CTC
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
   TCCR0A|=(1<<COM0A1)|(1<<COM0A0); //Phase correct PWM
//-----------------------------------------------------------------------
  
  
  
  
//-----------------------------------------------------------------------
  //Compare Match Output B Mode bits (COMnB): these enable/disable/invert output B
 /* TCCR0B|=(1<<COM0B1); //NON INVERTING FAST PWM
  TCCR0B&=(~(1<<COM0B0)); //NON INVERTING FAST PWM*/
  //TCCR0B|=(1<<COM0B1)|(1<<COM0B0); //FAST INVERTING
  // TCCR0B|=(1<<COM0B1)|(1<<COM0B0); //non PWM-CTC
//-----------------------------------------------------------------------  
//-----------------------------------------------------------------------
   TCCR0B|=(1<<COM0B1)|(1<<COM0B0); //Phase correct PWM
//-----------------------------------------------------------------------
  
  
  sei(); //enable interrupts
  //Compare match registers
  TIMSK0|=(1<<OCIE0A);
  TIMSK0|=(1<<OCIE0B);
  int ocr;
  ocr=16000000/(256*frequency); //(16000000/(2*64*frequency))-1;
  OCR0A = ocr;
 // OCR0B = 121;//255-ocr;
  
}

ISR(TIMER0_COMPA_vect)
{
  //ss=ss+1;
 // PORTD^=(1<<PD6);
  //PORTD^=(1<<PD5);
}
ISR(TIMER0_COMPB_vect)
{
  //sss=sss+1;
  //PORTD^=(1<<PD6);
  //PORTD^=(1<<PD5);
}
int main(void)
{/*Serial.begin(9600);
  Serial.println("heyy");*/
  toney(12000);     // enter any value between 0 to 62500.
  
  while(1)
  {
    /*Serial.println("ss:->");
    Serial.print(ss);
      Serial.println("sss:->");
    Serial.print(sss);*/
  }
}

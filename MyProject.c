
char dutycycle=0;
int x;
void main() {
x=0;
adcon1=0b00000110;
trisb=0;
trisc=0;
trisd=0b00011111;
portb=0;
portc=0;
portd=0;
PWM1_Init(10000);
PWM1_Start();
PWM1_Set_DUTY(0);

while(1)
{
if(portd.rd0==1)
{
portb.RB0=1;
portb.RB1=0;
dutycycle=63;
PWM1_Set_DUTY(dutycycle);
}
if(portd.rd1==1)
{
portb.RB0=0;
portb.RB1=1;
dutycycle=63;
PWM1_Set_DUTY(dutycycle);
}
if((portd.rd2==1) && (x==0))
{
portb.RB0=0;
portb.RB1=1;
dutycycle=31;
PWM1_Set_DUTY(dutycycle);
x=2;
}
if((portd.rd2==1) && (x==2))
{
portb.RB0=1;
portb.RB1=0;
dutycycle=31;
PWM1_Set_DUTY(dutycycle);
x=0;
}
if((portd.rd3==1)&&(x==0) )
{
portb.RB0=1;
portb.RB1=0;
dutycycle=255;
PWM1_Set_DUTY(dutycycle);
x=2;
}
if((portd.rd3==1)&&(x==2) )
{
portb.RB0=0;
portb.RB1=1;
dutycycle=255;
PWM1_Set_DUTY(dutycycle);
x=0;
}
if(portd.rd4==1 )
{
portb.RB0=0;
portb.RB1=0;
dutycycle=255;
PWM1_Set_DUTY(dutycycle);
}
}
}
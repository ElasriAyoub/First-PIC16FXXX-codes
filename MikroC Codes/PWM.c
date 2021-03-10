// EL ASRI - AIT OMAR - EL HAOUCHI

unsigned short current_duty1,current_duty2;
void Intmain(){
ANSEL=0;
ANSELH=0;
C1ON_bit=0;
C2ON_bit=0;
PORTA=255;
TRISA=0;
PORTB=0;
TRISB=0;
PORTC=0;
TRISC=0;
PWM1_Init(5000);
PWM2_Init(5000);
}
void main() {
Intmain();
current_duty1=16;
current_duty2=16;
PWM1_Start();
PWM2_Start();
PWM1_Set_Duty(current_duty1);
PWM2_Set_Duty(current_duty2);
while(1){
if(RA0_bit){
Delay_ms(40);
current_duty1++;
PWM1_Set_Duty(current_duty1);
}
if(RA1_bit){
Delay_ms(40);
current_duty1--;
PWM1_Set_Duty(current_duty1);
}
if(RA2_bit){
Delay_ms(40);
current_duty2++;
PWM2_Set_Duty(current_duty2);
}
if(RA3_bit){
Delay_ms(40);
current_duty2--;
PWM2_Set_Duty(current_duty2);
}Delay_ms(50);
}
}
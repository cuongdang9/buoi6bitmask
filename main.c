#include<stdio.h>


uint8_t PORT_A = 0x00;

typedef enum{
    GPIO_PIN_0 = 1,
    GPIO_PIN_1 = 1 << 1,
    GPIO_PIN_2 = 1 << 2,
    GPIO_PIN_3 = 1 << 3,
    GPIO_PIN_4 = 1 << 4,
    GPIO_PIN_5 = 1 << 5,
    GPIO_PIN_6 = 1 << 6,
    GPIO_PIN_7 = 1 << 7,
    
}GPIO_PIN;

typedef enum{
    LOW = 0,
    HIGH = 1,
}GPIO_PIN_STATUS;
void digitalWrite(GPIO_PIN PIN, GPIO_PIN_STATUS STATE){
    if(STATE){
        PORT_A |= PIN;
    }else{
        PORT_A &= ~PIN;
    }
}

void delay (){
    for (int i = 0; i<1000; i++){}
}

void BlinkLed (GPIO_PIN PIN){
   for(int i=0;;i++){
   PORT_A |= PIN ; 
   delay();
   PORT_A &= ~PIN; 
   delay();
   } 
}


int main (int argc, char const *argv[])
{
    digitalWrite (GPIO_PIN_2,HIGH); 
    digitalWrite (GPIO_PIN_2,LOW); 
    BlinkLed (GPIO_PIN_2); 
    return 0;
}

 
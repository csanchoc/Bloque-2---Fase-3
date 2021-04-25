#include "GPIO_LPC17xx.h"
#include "PIN_LPC17xx.h"
#include "LPC17xx.h"

#define PUERTO_INT		0
#define riseDIP14			16	//DIP 14
#define PUERTO_PIN		0
#define DIP9					0

extern void EINT3_IRQHandler(void);
extern void initGenerador(void);
int32_t initPin (void);


void EINT3_IRQHandler(void){

		 /* Activa Pin */
			GPIO_PinWrite (PUERTO_PIN, DIP9, 1);
			
		 /* Desactiva Pin */
			GPIO_PinWrite (PUERTO_PIN, DIP9, 0);
		
		 /* Activa Pin */
			GPIO_PinWrite (PUERTO_PIN, DIP9, 1);
			
		 /* Desactiva Pin */
			GPIO_PinWrite (PUERTO_PIN, DIP9, 0);
		
	   /* Clear any pending interrupt */
			LPC_GPIOINT->IO0IntClr = (1 << riseDIP14);
	
}
 
void initGenerador(){
	
/* Configure pins: Output Mode with Pull-down resistors */

	PIN_Configure(PUERTO_INT, riseDIP14, PIN_FUNC_0, PIN_PINMODE_PULLDOWN, PIN_PINMODE_NORMAL);
	NVIC_EnableIRQ(EINT3_IRQn);
	LPC_GPIOINT->IO0IntEnR = (1 << riseDIP14); // Habilita las interrupciones por flanco de subida del pin (DIP14)
	
}

int32_t initPin (void){
	
  /* Configure pins: Output Mode with Pull-down resistors */

    PIN_Configure (PUERTO_PIN, DIP9, PIN_FUNC_0, PIN_PINMODE_PULLDOWN, PIN_PINMODE_NORMAL);
    GPIO_SetDir   (PUERTO_PIN, DIP9, GPIO_DIR_OUTPUT);
    GPIO_PinWrite (PUERTO_PIN, DIP9, 0);
  
}

int main (void){
	
	initGenerador();
	initPin();
	
	while (1){
	
	}
}



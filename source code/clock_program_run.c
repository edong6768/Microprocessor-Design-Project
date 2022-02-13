// ver 6.6.1 sun

// input(d)
// PUSH : D 9~12(low enable)
// KEYPAD : D 1~4(in), 5~8(out) (high enable)

// output(c)
// buzzer : C
// LCD : C9
// 7-segment : E(0~6, 7~10)

#include "clock_program_headers.h"
#include "clock_program_builder.h"

#include <stdio.h>
#include <stdlib.h>

//access pointers and current states
void** total_modes;
int totalmodenum;
timeSession** times;
int curr_modenum, curr_screennum, interruptnum;
screenData* currentscreen;
int lpit0_ch0_flag_counter = 0; /*< LPIT0 timeout counter */


//interrupt handler
void PORTD_IRQHandler(void){
	//NVIC_DisableIRQ(PORTD_IRQn);
	currentscreen->inturruptfuncs[interruptnum]();
	screen_out(currentscreen);
	for(int i=1;i<13;i++) PORTD->PCR[i] |= 0x01000000; // Clear the ISF bit
}

//void LPIT0_Ch0_IRQHandler (void){
//	lpit0_ch0_flag_counter++;         /* Increment LPIT0 timeout counter */
//	times[0]->time_interrupt();
//	LPIT0->MSR |= LPIT_MSR_TIF0_MASK;  /* Clear LPIT0 timer flag 0 */
//}


void clock_program_run(){reconfig_currstate(0, 0, 0);screen_out(currentscreen);}//currtime set screen

int main(void)
{
	 hardware_init();
	 //times_init(1);
	 clock_program_build();
	 clock_program_run();
   while(1) Seg_out(currentscreen->seg_num);//does not reach because of prior 3 function calls
}

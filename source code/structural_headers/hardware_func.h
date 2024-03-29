#ifndef _HW_f_H_
#define _HW_f_H_


#include "device_registers.h"            /* include peripheral declarations S32K144 */
#include "./hardware_headers/clocks_and_modes.h"
#include "./hardware_headers/clocks_and_modes.c"
#include "./hardware_headers/LPUART.h"
#include "./hardware_headers/LPUART.c"

int lpit0_ch1_flag_counter = 0; /*< LPIT0 timeout counter */

//void NVIC_init_IRQs(void){
////	/*LPIT ch0 overflow set*/
////	S32_NVIC->ICPR[1] = 1 << (48 % 32);
////	S32_NVIC->ISER[1] = 1 << (48 % 32);
////	S32_NVIC->IP[48] = 0x00;
////	/*LPIT ch1 overflow set*/
////	S32_NVIC->ICPR[1] = 1 << (49 % 32);
////	S32_NVIC->ISER[1] = 1 << (49 % 32);
////	S32_NVIC->IP[49] = 0x0B;
//	//PORTD
//	S32_NVIC->ICPR[1] |= 1<<(62%32); // Clear any pending IRQ62
//	S32_NVIC->ISER[1] |= 1<<(62%32); // Enable IRQ62
//	S32_NVIC->IP[61] =0xB; //Priority 11 of 15
//}

void NVIC_init_IRQs(void){
//	/*LPIT ch0 overflow set*/
//	S32_NVIC->ICPR[1] = 1 << (48 % 32);
//	S32_NVIC->ISER[1] = 1 << (48 % 32);
//	S32_NVIC->IP[48] = 0x0B;
//	/*LPIT ch1 overflow set*/
//	S32_NVIC->ICPR[1] = 1 << (49 % 32);
//	S32_NVIC->ISER[1] = 1 << (49 % 32);
//	S32_NVIC->IP[49] = 0xB;
	//PORTD
	S32_NVIC->ICPR[1] |= 1<<(62%32); // Clear any pending IRQ62
	S32_NVIC->ISER[1] |= 1<<(62%32); // Enable IRQ62
	S32_NVIC->IP[61] =0x00; 
}

void PORT_init (void)
{
  /*
   * ===============PORTE SEGMENT=====================
   */
	PCC-> PCCn[PCC_PORTD_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */
  PTD->PDDR |= 1<<5|1<<6|1<<7|1<<8;   /* Port D5~D8: Data Direction = output */
  PTD->PDDR &= ~(1<<1&1<<2&1<<3&1<<4&1<<9&1<<10&1<<11&1<<12);  /* Port D1~D4: Data Direction = input */

  PORTD->PCR[1] = PORT_PCR_MUX(1)|PORT_PCR_PFE_MASK; /* Port D1: MUX = GPIO, input filter enabled */
	//PORTD->PCR[1] |=(9<<16); //rising edge
  PORTD->PCR[2] = PORT_PCR_MUX(1)|PORT_PCR_PFE_MASK; /* Port D2: MUX = GPIO, input filter enabled */
	//PORTD->PCR[2] |=(9<<16); //rising edge
  PORTD->PCR[3] = PORT_PCR_MUX(1)|PORT_PCR_PFE_MASK; /* Port D3: MUX = GPIO, input filter enabled */
	//PORTD->PCR[3] |=(9<<16); //rising edge
  PORTD->PCR[4] = PORT_PCR_MUX(1)|PORT_PCR_PFE_MASK; /* Port D4: MUX = GPIO, input filter enabled */
	//PORTD->PCR[4] |=(9<<16); //rising edge

	
  PORTD->PCR[5]  = PORT_PCR_MUX(1);   /* Port D5: MUX = GPIO  */
  PORTD->PCR[6]  = PORT_PCR_MUX(1);   /* Port D6: MUX = GPIO  */
  PORTD->PCR[7]  = PORT_PCR_MUX(1);   /* Port D7: MUX = GPIO  */
  PORTD->PCR[8]  = PORT_PCR_MUX(1);   /* Port D8: MUX = GPIO  */
	
	PORTD->PCR[9] |= PORT_PCR_MUX(1)|PORT_PCR_PFE_MASK;   /* Port D9: MUX = GPIO, input filter enabled */
	PORTD->PCR[9] |=(10<<16); // Port D9 IRQC : interrupt on Falling-edge
  PORTD->PCR[10]  = PORT_PCR_MUX(1)|PORT_PCR_PFE_MASK;   /* Port D10: MUX = GPIO, input filter enabled */
	PORTD->PCR[10] |=(10<<16); // Port D10 IRQC : interrupt on Falling-edge
  PORTD->PCR[11]  = PORT_PCR_MUX(1)|PORT_PCR_PFE_MASK;   /* Port D11: MUX = GPIO, input filter enabled */
	PORTD->PCR[11] |=(10<<16); // Port D11 IRQC : interrupt on Falling-edge
  PORTD->PCR[12]  = PORT_PCR_MUX(1)|PORT_PCR_PFE_MASK;   /* Port D12: MUX = GPIO, input filter enabled */
	PORTD->PCR[12] |=(10<<16); // Port D12 IRQC : interrupt on Falling-edge


	PCC->PCCn[PCC_PORTC_INDEX ]|=PCC_PCCn_CGC_MASK; /* Enable clock for PORTC */
  PORTC->PCR[9]|=PORT_PCR_MUX(2);           /* Port C9: MUX = ALT2,UART1 TX */
  PORTC->PCR[7]|=PORT_PCR_MUX(2);           /* Port C7: MUX = ALT2,UART1 TX */
	
  PCC-> PCCn[PCC_PORTE_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT E */
  PTE->PDDR |= 1<<0|1<<1|1<<2|1<<3|1<<4|1<<5|1<<6;   /* Port E0: Data Direction= output (default) */
  PORTE->PCR[0] = PORT_PCR_MUX(1); /* Port E0: MUX = GPIO */
  PORTE->PCR[1] = PORT_PCR_MUX(1); /* Port E1: MUX = GPIO */
  PORTE->PCR[2] = PORT_PCR_MUX(1); /* Port E2: MUX = GPIO */
  PORTE->PCR[3] = PORT_PCR_MUX(1); /* Port E3: MUX = GPIO */
  PORTE->PCR[4] = PORT_PCR_MUX(1); /* Port E4: MUX = GPIO */
  PORTE->PCR[5] = PORT_PCR_MUX(1); /* Port E5: MUX = GPIO */
  PORTE->PCR[6] = PORT_PCR_MUX(1); /* Port E6: MUX = GPIO */

  PTE->PDDR |= 1<<7|1<<8|1<<9|1<<10;
  PORTE->PCR[7] = PORT_PCR_MUX(1); /* Port E7: MUX = GPIO */
  PORTE->PCR[8] = PORT_PCR_MUX(1); /* Port E8: MUX = GPIO */
  PORTE->PCR[9] = PORT_PCR_MUX(1); /* Port E9: MUX = GPIO */
  PORTE->PCR[10] = PORT_PCR_MUX(1); /* Port E10: MUX = GPIO */
}

void WDOG_disable (void)
{
  WDOG->CNT=0xD928C520;     /* Unlock watchdog       */
  WDOG->TOVAL=0x0000FFFF;   /* Maximum timeout value    */
  WDOG->CS = 0x00002100;    /* Disable watchdog       */
}



void LPIT0_init (uint32_t Dtime)
{
   /*!
    * LPIT Clocking:
    * ==============================
    */
	PCC->PCCn[PCC_LPIT_INDEX] = PCC_PCCn_PCS(6);    /* Clock Src = 6 (SPLL2_DIV2_CLK)*/
	PCC->PCCn[PCC_LPIT_INDEX] |= PCC_PCCn_CGC_MASK; /* Enable clk to LPIT0 regs 		*/
	  /*!
	   * LPIT Initialization:
	   */
	LPIT0->MCR = 0x00000001;  /* DBG_EN-0: Timer chans stop in Debug mode */
	                              	  	  /* DOZE_EN=0: Timer chans are stopped in DOZE mode */
	                              	  	  /* SW_RST=0: SW reset does not reset timer chans, regs */
	                              	  	  /* M_CEN=1: enable module clk (allows writing other LPIT0 regs) */
	LPIT0->MIER = 0x00;  /* TIE0=1: Timer Interrupt Enabled fot Chan 0,1 */

	LPIT0->TMR[0].TVAL =40000;      /* Chan 0 Timeout period: 40M clocks */
    LPIT0->TMR[0].TCTRL = 0x00000001;
	  	  	  	  	  	  	  	  /* T_EN=1: Timer channel is enabled */
	                              /* CHAIN=0: channel chaining is disabled */
	                              /* MODE=0: 32 periodic counter mode */
	                              /* TSOT=0: Timer decrements immediately based on restart */
	                              /* TSOI=0: Timer does not stop after timeout */
	                              /* TROT=0 Timer will not reload on trigger */
	                              /* TRG_SRC=0: External trigger soruce */
	                              /* TRG_SEL=0: Timer chan 0 trigger source is selected*/

	LPIT0->TMR[1].TVAL = Dtime* 40000;      /* Chan 1 Timeout period: 40M clocks */
    LPIT0->TMR[1].TCTRL = 0x00000001;
	  	  	  	  	  	  	  	  /* T_EN=1: Timer channel is enabled */
	                              /* CHAIN=0: channel chaining is disabled */
	                              /* MODE=0: 32 periodic counter mode */
	                              /* TSOT=0: Timer decrements immediately based on restart */
	                              /* TSOI=0: Timer does not stop after timeout */
	                              /* TROT=0 Timer will not reload on trigger */
	                              /* TRG_SRC=0: External trigger soruce */
	                              /* TRG_SEL=0: Timer chan 0 trigger source is selected*/
}

void delay_ms (volatile int ms){
   LPIT0_init(ms);           /* Initialize PIT0 for delay time, timeout  */
   while (0 == (LPIT0->MSR &  LPIT_MSR_TIF1_MASK)) {} /* Wait for LPIT0 CH0 Flag */
               lpit0_ch1_flag_counter++;         /* Increment LPIT0 timeout counter */
               LPIT0->MSR |=LPIT_MSR_TIF1_MASK;//............LPIT_MSR_TIF0_MASK; /* Clear LPIT0 timer flag 0 */
}




hardware_init(){
   WDOG_disable();/* Disable Watchdog in case it is not done in startup code */
   PORT_init();            /* Configure ports */
   SOSC_init_8MHz();       /* Initialize system oscilator for 8 MHz xtal */
   SPLL_init_160MHz();     /* Initialize SPLL to 160 MHz with 8 MHz SOSC */
   NormalRUNmode_80MHz();  /* Init clocks: 80 MHz sysclk & core, 40 MHz bus, 20 MHz flash */
   NVIC_init_IRQs();       /* Enable desired interrupts and priorities */
	 SystemCoreClockUpdate();
   LPIT0_init(1);
   LPUART1_init();        /* Initialize LPUART @ 4800*/

}


//void LPIT0_Ch0_IRQHandler (void){
//	lpit0_ch0_flag_counter++;         /* Increment LPIT0 timeout counter */
//	//num++;
//	LPIT0->MSR |= LPIT_MSR_TIF0_MASK;  /* Clear LPIT0 timer flag 0 */
//}

void LPIT0_Ch1_IRQHandler (void){	  /* delay counter */
	lpit0_ch1_flag_counter++;         /* Increment LPIT1 timeout counter */
	LPIT0->MSR |= LPIT_MSR_TIF1_MASK;  /* Clear LPIT0 timer flag 0 */
}


#endif
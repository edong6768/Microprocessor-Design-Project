// LCD : C9


#include "hardware_func.h"
#include "interruptData.h"

#ifndef _SCR_H_
#define _SCR_H_
int MAX_SCREEN_HEIGHT=4;
unsigned int FND_DATA[10]={0x3F, 0x06,0x5b,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};// 0~9 number
unsigned int FND_SEL[4]={0x0080,0x0100,0x0200,0x0400};


typedef struct{
	char msg[3][23];
	char switch_config[23];
	int seg_num;
	void (**inturruptfuncs)();
	void** others;
	int current_inturrupt;
	int screenNum;
}screenData;

typedef struct{
	screenData** screens;
	int totalscreennum, modeNum;	
}modeData;

void Seg_out(int number){
   int k = 0;
   int d1000, d100, d10, d1;

   	   	   	   	   d1000 = number /1000;
   	   	   	   	   d100 = number % 1000/100;
   	   	   	   	   d10 = number % 100/10;
   	   	   	   	   d1 = number % 10;
     	   	   	   	 delay_ms(1);//???

     	   	   	   	 	 // 1000???
   	   	   	   	 PTE->PSOR = FND_SEL[k];
   	   	   	   	 PTE->PCOR = FND_DATA[d1000];
									delay_ms(1);//???
   	   	   	   	 PTE->PSOR =0x7F;
   	   	   	   	 PTE->PCOR =0x0780;
   	   	   	   	 k++;

                            // 100???
  		         PTE->PSOR = FND_SEL[k];
                 PTE->PCOR = FND_DATA[d100];
                 delay_ms(1);
                 PTE->PSOR =0x7F;
                 PTE->PCOR =0x0780;
  		         k++;

                            //10???
		         PTE->PSOR = FND_SEL[k];
                 PTE->PCOR = FND_DATA[d10];
                 delay_ms(1);
                 PTE->PSOR =0x7F;
                 PTE->PCOR =0x0780;
  		         k++;

                            // 1???
  		         PTE->PSOR = FND_SEL[k];
                 PTE->PCOR = FND_DATA[d1];
                 delay_ms(1);
                 PTE->PSOR =0x7F;
                 PTE->PCOR =0x0780;
 		         k = 0;

}

void screen_out(screenData* currentscreen){
	//initial settings
	char msg_init = 0x00;
	char msg_clear[1] = {0xA3,1};
	char msg_reset= 0xA0;
	char msg_Start = 0xA2;
	//int i=0;
	Seg_out(currentscreen->seg_num);//seg
	LPUART1_transmit_char(msg_init);
	LPUART1_transmit_char(msg_clear[0]);
	LPUART1_transmit_char(msg_clear[1]);
	LPUART1_transmit_char(0xD0);
	LPUART1_transmit_char(0);
	LPUART1_transmit_char(msg_Start);
		for(int j=0;j<3;j++){
			LPUART1_transmit_char(msg_init);
			LPUART1_transmit_char(msg_clear[0]);
			LPUART1_transmit_char(msg_clear[1]);
			LPUART1_transmit_char(0xA1);
			LPUART1_transmit_char(0);
			LPUART1_transmit_char(j);
			LPUART1_transmit_char(msg_Start);
			for(int i=0;currentscreen->msg[j][i] != '\0';i++) {
				LPUART1_transmit_char(currentscreen->msg[j][i]);
				Seg_out(currentscreen->seg_num);//seg
			}
		}
		LPUART1_transmit_char(msg_init);
		LPUART1_transmit_char(msg_clear[0]);
		LPUART1_transmit_char(msg_clear[1]);
		LPUART1_transmit_char(0xD0);
		LPUART1_transmit_char(1);
		LPUART1_transmit_char(0xA1);
		LPUART1_transmit_char(0);
		LPUART1_transmit_char(3);
		LPUART1_transmit_char(msg_Start);
		for(int i=0;currentscreen->switch_config[i] != '\0';i++){
			LPUART1_transmit_char(currentscreen->switch_config[i]);
			Seg_out(currentscreen->seg_num);//seg
		}
}

#endif
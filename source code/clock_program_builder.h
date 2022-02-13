#include <stdio.h>
#include <stdlib.h>
#include "clock_program_headers.h"


extern void** total_modes;
extern int totalmodenum;
extern timeSession** times;
extern int curr_modenum, curr_screennum, interruptnum;
extern screenData* currentscreen;


//0-0 currtimeset>mainlist
	char list1_currtimeset2_hour[23]={' ', 0xaf, 0xa1, 0x88, 0x65, ':', 'h', 'o', 'u', 'r', ' ', 0xa5, 0x65, 0x89, 0x77, ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'};	
	char list1_currtimeset2_minuit[23]={' ', 0xaf, 0xa1, 0x88, 0x65, ':', 'm', 'i', 'n', 'u', 't', 'e', ' ', 0xa5, 0x65, 0x89, 0x77, ' ', ' ', ' ', ' ', ' ', '\0'};	
	char list1_currtimeset1[23]={' ', 0xaf, 0xa1, 0x88, 0x65, ':', 0xb7, 0xb3, 0x9d, 0x62, 0xc0, 0x77, ' ', 0xb7, 0xa1, 0x95, 0xb7,' ', ' ', ' ', ' ', ' ', '\0'};
		
	char switch_config_currtimeset_currtimeset1[23]={' ', ' ', ' ', ' ', ' ', ' ', 'v', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 0xb7, 0xb3, 0x9d, 0x62, '\0', ' '};// x v x ??
	char switch_config_currtimeset_currtimeset2[23]={' ', ' ', 'v', ' ', ' ', ' ', ' ', '^', ' ', ' ', ' ', 0xa5, 0x65, 0x89, 0x77, ' ', ' ', 0xb5, 0xc5, 0x9e, 0x61, '\0', ' '};// v ^ ?? ??
	char switch_config_currtimeset_countryset1[23]={0xa1, 0xa2, 0x9d, 0xa2, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '^', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'};// ?? x ^ x
	char switch_config_currtimeset_countryset2[23]={0xa1, 0xa2, 0x9d, 0xa2, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '^', ' ', ' ', ' ', ' ', ' ', 0xb5, 0xc5, 0x9e, 0x61, '\0'};// ?? x ^ ??
	//????(??)
	char initial_setting_title[23]={'-', ' ', ' ', ' ', ' ', ' ', ' ', 0xc1, 0xa1, 0x8b, 0xa1, 0xac, 0xe9, 0xb8, 0xf7, ' ', ' ', ' ', ' ', ' ', ' ', '-', '\0'};
	//??????(??)
	char currtimeset_title[23]={'-', ' ', ' ', ' ', ' ',0xd1, 0x65, 0xb8, 0x81, 0xaf, 0xa1, 0x88, 0x62, 0xac, 0xe9, 0xb8, 0xf7, ' ', ' ', ' ', ' ', '-', '\0'};
		
	char currtimeset_mainlist_list[2][23]={{' ', 0xaf, 0xa1, 0x88, 0x65, ':', 0xb7, 0xb3, 0x9d, 0x62, 0xc0, 0x77, ' ', 0xb7, 0xa1, 0x95, 0xb7,' ', ' ', ' ', ' ', ' ', '\0'}
									 ,{' ', 0x8a, 0x82, 0x88, 0x61, ':', 0xac, 0xe5, 0xc8, 0x82, 0xc0, 0x77, ' ', 0xb7, 0xa1, 0x95, 0xb7,' ', ' ', ' ', ' ', ' ', '\0'}};
	char currtimeset_mainlist_country_list[12][23]={{' ',0x8a, 0x82, 0x88, 0x61, ':',0x9c,0xe5,0x94,0xe5, ' ', ' ', ' ', ' ', ' ', ' ', 'G', 'M', 'T', ' ', '0', ' ', '\0'}  // ??
											,{' ',0x8a, 0x82, 0x88, 0x61, ':',0xcc,0x61,0x9f,0xa1, ' ', ' ', ' ', ' ', ' ', ' ', 'G', 'M', 'T', '+', '1', ' ', '\0'}  // ??
											,{' ',0x8a, 0x82, 0x88, 0x61, ':',0xa1,0xa1,0xaf,0x61,0xc7,0x61,0xa4,0x61, ' ', ' ', 'G', 'M', 'T', '+', '2', ' ', '\0'}  // ????
											,{' ',0x8a, 0x82, 0x88, 0x61, ':',0x96,0x81,0xa4,0x61,0xb7,0xa1, ' ', ' ', ' ', ' ', 'G', 'M', 'T', '+', '3', ' ', '\0'}  // ???
											,{' ',0x8a, 0x82, 0x88, 0x61, ':',0xb8,0x61,0xc4,0x61,0x9f,0x61,0xc8,0x61, ' ', ' ', 'G', 'M', 'T', '+', '6', ' ', '\0'}  // ????
											,{' ',0x8a, 0x82, 0x88, 0x61, ':',0xa5,0x41,0xb7,0xa1,0xbb,0xb7, ' ', ' ', ' ', ' ', 'G', 'M', 'T', '+', '7', ' ', '\0'}  // ???
											,{' ',0x8a, 0x82, 0x88, 0x61, ':',0xac,0xe1,0xb6,0x89, ' ', ' ', ' ', ' ', ' ', ' ', 'G', 'M', 'T', '+', '8', ' ', '\0'}  // ??
											,{' ',0x8a, 0x82, 0x88, 0x61, ':',0xaf,0xa1,0x97,0x61,0x93,0xa1, ' ', ' ', ' ', ' ', 'G', 'M', 'T', '+', '9', ' ', '\0'}  // ???
											,{' ',0x8a, 0x82, 0x88, 0x61, ':', 'L', 'A', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'G', 'M', 'T', '-', '8', ' ', '\0'}  // LA
											,{' ',0x8a, 0x82, 0x88, 0x61, ':',0xa1,0x42,0xaf,0xa1,0xc5,0xa1,0xaf,0xa1,0xcb,0xa1, 'G', 'M', 'T', '-', '6', ' ', '\0'}  // ?????
											,{' ',0x8a, 0x82, 0x88, 0x61, ':',0x93,0x41,0xb6,0x62, ' ', ' ', ' ', ' ', ' ', ' ', 'G', 'M', 'T', '-', '5', ' ', '\0'}  // ??
											,{' ',0x8a, 0x82, 0x88, 0x61, ':',0xac,0x77,0xcc,0x61,0xb6,0x89,0x9e,0x81, ' ', ' ', 'G', 'M', 'T', '-', '4', ' ', '\0'}};// ????


	//0-1 currtimeset>countrylist										
	char currtimeset_countrylist_list[12][23]={{' ',0x9c,0xe5,0x94,0xe5, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'G', 'M', 'T', ' ', '0', ' ', '\0'}  // ??
											,{' ',0xcc,0x61,0x9f,0xa1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'G', 'M', 'T', '+', '1', ' ', '\0'}  // ??
											,{' ',0xa1,0xa1,0xaf,0x61,0xc7,0x61,0xa4,0x61, ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'G', 'M', 'T', '+', '2', ' ', '\0'}  // ????
											,{' ',0x96,0x81,0xa4,0x61,0xb7,0xa1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'G', 'M', 'T', '+', '3', ' ', '\0'}  // ???
											,{' ',0xb8,0x61,0xc4,0x61,0x9f,0x61,0xc8,0x61, ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'G', 'M', 'T', '+', '6', ' ', '\0'}  // ????
											,{' ',0xa5,0x41,0xb7,0xa1,0xbb,0xb7, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'G', 'M', 'T', '+', '7', ' ', '\0'}  // ???
											,{' ',0xac,0xe1,0xb6,0x89, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'G', 'M', 'T', '+', '8', ' ', '\0'}  // ??
											,{' ',0xaf,0xa1,0x97,0x61,0x93,0xa1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'G', 'M', 'T', '+', '9', ' ', '\0'}  // ???
											,{' ', 'L', 'A', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'G', 'M', 'T', '-', '8', ' ', '\0'}  // LA
											,{' ',0xa1,0x42,0xaf,0xa1,0xc5,0xa1,0xaf,0xa1,0xcb,0xa1, ' ', ' ', ' ', ' ', ' ', 'G', 'M', 'T', '-', '6', ' ', '\0'}  // ?????
											,{' ',0x93,0x41,0xb6,0x62, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'G', 'M', 'T', '-', '5', ' ', '\0'}  // ??
											,{' ',0xac,0x77,0xcc,0x61,0xb6,0x89,0x9e,0x81, ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'G', 'M', 'T', '-', '4', ' ', '\0'}};// ????

	char switch_config_countrylist[23]={' ', ' ', '<', ' ', ' ', ' ', ' ', ' ', 'v', ' ', ' ', ' ', ' ', '^', ' ', ' ', ' ', 0xac, 0xe5, 0xc8, 0x82, '\0', ' '}; // < v ^ ??

	
//1-0 mainscreen		
	char mainscreen_mainlist_list[2][23]={{' ', '1', '.',0xad, 0x41, 0x89, 0x81, 0xaf, 0xa1, 0x89, 0x81, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'}  // ????
									,{' ', '2', '.',0xd1, 0x65, 0xb8, 0x81, 0xaf, 0xa1, 0x88, 0x62, 0xac, 0xe9, 0xb8, 0xf7, ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'}}; // ??????
	//??(??)
	char mainscreen_mainlist_title[23]={'-', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 0xa1, 0x41, 0xb7, 0xa5, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-', '\0'};
	// x v ^ ??
	char switch_config_mainscreen_mainlist_countrylist[23]={' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'v', ' ', ' ', ' ', ' ', '^', ' ', ' ', ' ', 0xac, 0xe5, 0xc8, 0x82, '\0', ' '};
//2-0 worldtime
	//make list          0    1   2    3    4     5    6    7    8    9   10   11   12   13   14   15   16   17   18   19   20    21   22
	char worldtime_mainlist_list[12][23]={{' ',0x9c,0xe5,0x94,0xe5, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ':', ' ', ' ', '\0'}  // ??
										,{' ',0xcc,0x61,0x9f,0xa1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ':', ' ', ' ', '\0'}  // ??
										,{' ',0xa1,0xa1,0xaf,0x61,0xc7,0x61,0xa4,0x61, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ':', ' ', ' ', '\0'}  // ????
										,{' ',0x96,0x81,0xa4,0x61,0xb7,0xa1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ':', ' ', ' ', '\0'}  // ???
										,{' ',0xb8,0x61,0xc4,0x61,0x9f,0x61,0xc8,0x61, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ':', ' ', ' ', '\0'}  // ????
										,{' ',0xa5,0x41,0xb7,0xa1,0xbb,0xb7, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ':', ' ', ' ', '\0'}  // ???
										,{' ',0xac,0xe1,0xb6,0x89, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ':', ' ', ' ', '\0'}  // ??
										,{' ',0xaf,0xa1,0x97,0x61,0x93,0xa1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ':', ' ', ' ', '\0'}  // ???
										,{' ', 'L', 'A', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ':', ' ', ' ', '\0'}  // LA
										,{' ',0xa1,0x42,0xaf,0xa1,0xc5,0xa1,0xaf,0xa1,0xcb,0xa1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ':', ' ', ' ', '\0'}  // ?????
										,{' ',0x93,0x41,0xb6,0x62, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ':', ' ', ' ', '\0'}  // ??
										,{' ',0xac,0x77,0xcc,0x61,0xb6,0x89,0x9e,0x81, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ':', ' ', ' ', '\0'}};// ????
											
	//????(??)
	char worldtime_mainlist_title[23]={'-', ' ', ' ', ' ', ' ', ' ', ' ',0xad, 0x41, 0x89, 0x81, 0xaf, 0xa1, 0x89, 0x81, ' ', ' ', ' ', ' ', ' ', ' ', '-', '\0'};
	// < v ^ x
	char switch_config_worldtime_mainlist_countrylist[23]={' ', ' ', '<', ' ', ' ', ' ', ' ', ' ', 'v', ' ', ' ', ' ', ' ', '^', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'};

	
void reconfig_currstate(int mode_num, int screen_num, int interrupt_num){
	curr_modenum=mode_num;
	curr_screennum=screen_num;
	interruptnum=interrupt_num;
	currentscreen=((modeData*)total_modes[curr_modenum])->screens[curr_screennum];
}

void currenttime_run(){
	timedelay_sec(times[0]->timedata, 1);
	currentscreen->seg_num=timeFormat2timeInt(times[0]->timedata)/100; //refresh seg_num
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////clock program initializers/////////////////////////////////////////////
void mode_currtimesetting_init(void);
void mode_mainscreen_init(void);
void mode_worldtime_init(void);

void clock_program_build(){
	totalmodenum=3;
	total_modes=malloc(sizeof(void*)*totalmodenum);
	for(int i=0;i<totalmodenum;i++) {
		total_modes[i]=malloc(sizeof(modeData*));
		((modeData*)total_modes[i])->modeNum=i;
	}
	mode_currtimesetting_init();		//total_modes[0]
	//mode_mainscreen_init();					//total_modes[1]
	//mode_worldtime_init();					//total_modes[2]
}

void times_init(int n){
	times = malloc(sizeof(timeSession*)*n);
	for(int i=0; i<n;i++){
		times[i]=malloc(sizeof(timeSession));
		times[i]->timenum=i;
		times[i]->timedata=set_timeFormat(0,0,0,0,0,0);//current timeSession initialize
		times[i]->time_interrupt=(void(*)())NULL;	//disable time
	}
}


/////////////////////////////current_time_mode(0)///////////////////////////////////////////

void Screen_CTS_mainsetlist_init(void);
void Screen_CTS_countrylist_init(void);


void mode_currtimesetting_init(){
	int totalscreennum=2;
	int modeNum=0;
	((modeData*)total_modes[modeNum])->totalscreennum=totalscreennum;
	((modeData*)total_modes[modeNum])->modeNum=modeNum;
	
	((modeData*)total_modes[modeNum])->screens=malloc(sizeof(screenData*)*totalscreennum);// allocate memory for screenDatas
	for(int i=0;i<totalscreennum;i++){
		((modeData*)total_modes[modeNum])->screens[i]=malloc(sizeof(screenData)); //added because code below didn't work without it
		((modeData*)total_modes[modeNum])->screens[i]->screenNum=i; // give screenNums to screenDatas
	}
	Screen_CTS_mainsetlist_init();
	Screen_CTS_countrylist_init();
}

//////////////////current_time_mode(0)->mainscreen(0)/////////////////////
void inturrupt_currtimeset1(void);
void inturrupt_currtimeset2(void);
void inturrupt_countryset1(void);
void inturrupt_countryset2(void);


void screenType_listData_CTS_mainsetlist_listalloc_init(screenType_listData* temp){
	//list, input list string should account for cursor position
	temp->list=malloc(sizeof(char*)*temp->size);
	for(int i=0;i<temp->size;i++){
		temp->list[i]=malloc(sizeof(char)*23);
		for(int j=0;j<23;j++)temp->list[i][j]=currtimeset_mainlist_list[i][j];
	}
}

void Screen_CTS_mainsetlist_init(){
	int thisscreennum=0;
	int thismodenum=0;
	screenData* thisscreen=((modeData*)total_modes[thismodenum])->screens[thisscreennum];
	//interrupt func set allocate
	thisscreen->inturruptfuncs=malloc(sizeof(void(*)())*4);//4 interruptfuncsets
	thisscreen->inturruptfuncs[0]=inturrupt_currtimeset1;
	thisscreen->inturruptfuncs[1]=inturrupt_currtimeset2;
	thisscreen->inturruptfuncs[2]=inturrupt_countryset1;
	thisscreen->inturruptfuncs[3]=inturrupt_countryset2;
	thisscreen->current_inturrupt=0;
	
	thisscreen->seg_num=0;//program freezes since screen_out has seg_out inside
	
	
	// allocate memory for list & country_selected_int & timeInt &time_sel
	thisscreen->others=malloc(sizeof(void*)*4);
	
	//make screenType_listData without listdata;
	thisscreen->others[0]=set_screenType_listData(2, 2, 1, initial_setting_title, switch_config_currtimeset_currtimeset1);
	screenType_listData_CTS_mainsetlist_listalloc_init(thisscreen->others[0]);//put listdata in List
		
	//country_selected_int
	thisscreen->others[1]=malloc(sizeof(int));
	*((int*)thisscreen->others[1])=0;
	
	//timeInt
	thisscreen->others[2]=malloc(sizeof(int));
	*((int*)thisscreen->others[2])=0;
		
	//time_sel
	thisscreen->others[3]=malloc(sizeof(int));
	*((int*)thisscreen->others[3])=0;
	
	screentype_list(thisscreen, thisscreen->others[0]);	//put list datas into screenfrom
}


void inturrupt_currtimeset1(){	// x v x ??
		screenType_listData* list=(screenType_listData*)currentscreen->others[0];
		if((PORTD->ISFR & (1<<10)) != 0){	// backspace seg_outed num
			screenType_list_operation_DOWN(list);
			if(!*((int*)currentscreen->others[1])){
				//go to countryset1
				list->switch_config=switch_config_currtimeset_countryset1;
				((modeData*)total_modes[0])->screens[0]->current_inturrupt=2;
				reconfig_currstate(0, 0, 2);	//inturrupt_countryset1
			}
			else{
				//go to countryset2
				list->switch_config=switch_config_currtimeset_countryset2;
				((modeData*)total_modes[0])->screens[0]->current_inturrupt=3;
				reconfig_currstate(0, 0, 3);	//inturrupt_countryset1
			}
		}
		else if((PORTD->ISFR & (1<<12)) != 0){	// set time
				list->switch_config=switch_config_currtimeset_currtimeset2;
			  screenType_list_rewriteLine(list, list1_currtimeset2_hour, 0);	
				((modeData*)total_modes[0])->screens[0]->current_inturrupt=1;
				reconfig_currstate(0, 0, 1);	//inturrupt_currtimeset2
		}
		screentype_list(currentscreen, list);	//put list datas into screenfrom
}
void inturrupt_currtimeset2(){	// v ^ ?? ??
	screenType_listData* list=(screenType_listData*)currentscreen->others[0];
	int *timeInt=((int*)((modeData*)total_modes[0])->screens[0]->others[2]);	
	int *time_sel=((int*)((modeData*)total_modes[0])->screens[0]->others[3]);
		if((PORTD->ISFR & (1<<9)) != 0){	//down sigh, v
			if(!(*time_sel)){
				if(*timeInt/100==0) *timeInt+=2300;
				else *timeInt-=100;
			}
			else{
				if(*timeInt%100==0) *timeInt+=59;
				else *timeInt-=1;
			}
			currentscreen->seg_num=*timeInt;	//seg_num: last 4 digit of timeInt
		}
		else if((PORTD->ISFR & (1<<10)) != 0){	//up sigh, ^
			if(!(*time_sel)){
				if(*timeInt/100==23) *timeInt-=2300;
				else *timeInt+=100;
			}
			else{
				if(*timeInt%100==59) *timeInt-=59;
				else *timeInt+=1;
			}
			currentscreen->seg_num=*timeInt;	//seg_num: last 4 digit of timeInt
		}
		else if((PORTD->ISFR & (1<<11)) != 0){	// ??
			*time_sel=(*time_sel)?0:1;
			if(!(*time_sel)) screenType_list_rewriteLine(list, list1_currtimeset2_hour, 0);	
			else screenType_list_rewriteLine(list, list1_currtimeset2_minuit, 0);	
		}		
		else if((PORTD->ISFR & (1<<12)) != 0){	// ??
			//return to currtimeset1
		  //timeInt2timeFormat(times[0]->timedata, *timeInt);	//set currunt time according to entered timeInt
			list->switch_config=switch_config_currtimeset_currtimeset1;
			screenType_list_rewriteLine(list, list1_currtimeset1, 0);	
			((modeData*)total_modes[0])->screens[0]->current_inturrupt=0;
			reconfig_currstate(0, 0, 0);	//inturrupt_currtimeset;
		}
		screentype_list(currentscreen, list);	//put list datas into screenfrom
}
void inturrupt_countryset1(){	// ?? x ^ x
		screenType_listData* list=(screenType_listData*)currentscreen->others[0];
		if((PORTD->ISFR & (1<<9)) != 0){			//??
			reconfig_currstate(0, 1, 0);//go to countryset screen
		}
		else if((PORTD->ISFR & (1<<11)) != 0){	//up sign, ^
			screenType_list_operation_UP(list);
			//go to currtimeset1
			list->switch_config=switch_config_currtimeset_currtimeset1;
			((modeData*)total_modes[0])->screens[0]->current_inturrupt=0;
			reconfig_currstate(0, 0, 0);	//inturrupt_currtimeset2
			screentype_list(currentscreen, list);	//put list datas into screenfrom
		}
}
void inturrupt_countryset2(){	// ?? x ^ ??
		screenType_listData* list=(screenType_listData*)currentscreen->others[0];
		if((PORTD->ISFR & (1<<9)) != 0){			//??
			reconfig_currstate(0, 1, 0);//go to countryset screen
		}
		else if((PORTD->ISFR & (1<<11)) != 0){	//up sign, ^
			screenType_list_operation_UP(list);
			//go to currtimeset2
			list->switch_config=switch_config_currtimeset_currtimeset1;
			((modeData*)total_modes[0])->screens[0]->current_inturrupt=0;
			reconfig_currstate(0, 0, 0);	//inturrupt_currtimeset2
			screentype_list(currentscreen, list);	//put list datas into screenfrom
		}
		else if((PORTD->ISFR & (1<<12)) != 0){	// ??
			((screenType_listData*)(currentscreen->others[0]))->title=currtimeset_title;	//change title of mainset screen to ??????
			//times[0]->time_interrupt=currenttime_run;
			reconfig_currstate(1, 0, 0);	//go to main menu
		}
}
//////////////////current_time_mode(0)->countrylist(1)/////////////////////



void screenType_listData_CTS_mainsetlist_countryselected_changevalue(int countrynum){	//change main screen to have the name of selected country
	screenData* mainsetlist=((modeData*)total_modes[0])->screens[0];
	*((int*)(mainsetlist->others[1]))=1;
	
	//change list of main screen										
	for(int j=0;j<23;j++) ((screenType_listData*)(mainsetlist->others[0]))->list[1][j]=currtimeset_mainlist_country_list[countrynum][j];
}


void inturrupt_countrylist(){	// < v ^ ??
		screenType_listData* list=(screenType_listData*)currentscreen->others[0];
		int countrynum=list->selected;
			
		if((PORTD->ISFR & (1<<9)) != 0){			//return to previous, <
			screentype_list(((modeData*)total_modes[0])->screens[0], ((modeData*)total_modes[0])->screens[0]->others[0]);	//put list datas into screenfrom
			reconfig_currstate(0, 0, 2);//go back to mainset screen without country selection or change operation
		}
		else if((PORTD->ISFR & (1<<10)) != 0){	//down sigh, v
			screenType_list_operation_DOWN(list);
			screentype_list(currentscreen, list);	//put list datas into screenfrom
		}	
		else if((PORTD->ISFR & (1<<11)) != 0){	//up sign, ^
			screenType_list_operation_UP(list);
			screentype_list(currentscreen, list);	//put list datas into screenfrom
		}
		else if((PORTD->ISFR & (1<<12)) != 0){	// enter, ??
			//change main screen to have the name of selected country
			screenType_listData_CTS_mainsetlist_countryselected_changevalue(countrynum);
			((screenType_listData*)(((modeData*)total_modes[0])->screens[0]->others[0]))->switch_config=switch_config_currtimeset_countryset2;	//change interrupt of mainset screen to countryset2
			((modeData*)total_modes[0])->screens[0]->current_inturrupt=3;
			screentype_list(((modeData*)total_modes[0])->screens[0], ((modeData*)total_modes[0])->screens[0]->others[0]);	//put list datas into screenfrom
			reconfig_currstate(0, 0, 3);//go back to mainset screen with country selected (countryset2)
		}
}

void screenType_listData_CTS_countrylist_listalloc_init(screenType_listData* temp){
	//make list
	//list, input list string should account for cursor position
	temp->list=malloc(sizeof(char*)*temp->size);
	for(int i=0;i<temp->size;i++){
		temp->list[i]=malloc(sizeof(char)*23);
		for(int j=0;j<23;j++)temp->list[i][j]=currtimeset_countrylist_list[i][j];
	}
	
}

void Screen_CTS_countrylist_init(){
	((modeData*)total_modes[0])->screens[1]->inturruptfuncs=malloc(sizeof(void(*)())*1); //1 interruptfuncsets
	((modeData*)total_modes[0])->screens[1]->inturruptfuncs[0]=inturrupt_countrylist;
	((modeData*)total_modes[0])->screens[1]->current_inturrupt=0;
	
	((modeData*)total_modes[0])->screens[1]->seg_num=0; //program freezes since screen_out has seg_out inside
	
	// allocate memory for list
	((modeData*)total_modes[0])->screens[1]->others=malloc(sizeof(void*)*1);
	
	//make screenType_listData without listdata;
	((modeData*)total_modes[0])->screens[1]->others[0]=set_screenType_listData(12, 3, 0, 0, switch_config_countrylist);
	screenType_listData_CTS_countrylist_listalloc_init(((modeData*)total_modes[0])->screens[1]->others[0]);//put listdata in List
		
	screentype_list(((modeData*)total_modes[0])->screens[1], ((modeData*)total_modes[0])->screens[1]->others[0]);	//put list datas into screenfrom
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////







void inturrupt_mainlist(){	// < v ^ x
		screenType_listData* list=(screenType_listData*)currentscreen->others[0];
		if((PORTD->ISFR & (1<<10)) != 0){	//down sigh, v
			screenType_list_operation_DOWN(list);
			screentype_list(currentscreen, list);	//put list datas into screenfrom
		}	
		else if((PORTD->ISFR & (1<<11)) != 0){	//up sign, ^
			screenType_list_operation_UP(list);
			screentype_list(currentscreen, list);	//put list datas into screenfrom
		}
		if((PORTD->ISFR & (1<<12)) != 0){		// enter, ??
			switch(list->selected){
				case 0:
					reconfig_currstate(2, 0, 0);//go to ????
					break;
				case 1:
					times[0]->time_interrupt=(void(*)())NULL;	//disable time
					reconfig_currstate(1, 0, ((modeData*)total_modes[0])->screens[0]->current_inturrupt);//go to ??????
					break;
				default: break;
			}
		}
}

void screenType_listData_MS_mainlist_listalloc_init(screenType_listData* temp){
	//list, input list string should account for cursor position
	temp->list=malloc(sizeof(char*)*temp->size);
	for(int i=0;i<temp->size;i++){
		temp->list[i]=malloc(sizeof(char)*23);
		for(int j=0;j<23;j++)temp->list[i][j]=mainscreen_mainlist_list[i][j];
	}	
}


void Screen_MS_mainlist_init(){
	((modeData*)total_modes[1])->screens[0]->inturruptfuncs=malloc(sizeof(void(*)())*1); //1 interruptfuncsets
	((modeData*)total_modes[1])->screens[0]->inturruptfuncs[0]=inturrupt_mainlist;
	((modeData*)total_modes[1])->screens[0]->current_inturrupt=0;
	
	((modeData*)total_modes[1])->screens[0]->seg_num=0; //program freezes since screen_out has seg_out inside
	
	// allocate memory for list
	((modeData*)total_modes[1])->screens[0]->others=malloc(sizeof(void*)*1);
	
	//make screenType_listData without listdata;
	((modeData*)total_modes[1])->screens[0]->others[0]=set_screenType_listData(2, 2, 1, mainscreen_mainlist_title, switch_config_mainscreen_mainlist_countrylist);
	screenType_listData_MS_mainlist_listalloc_init(((modeData*)total_modes[1])->screens[0]->others[0]);//put listdata in List
		
	screentype_list(((modeData*)total_modes[1])->screens[0], ((modeData*)total_modes[1])->screens[0]->others[0]);	//put list datas into screenfrom
	
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void mode_mainscreen_init(){
	int totalscreennum=1;
	int modeNum=1;
	((modeData*)total_modes[modeNum])->totalscreennum=totalscreennum;
	((modeData*)total_modes[modeNum])->modeNum=modeNum;
	
	((modeData*)total_modes[modeNum])->screens=malloc(sizeof(screenData*)*totalscreennum);// allocate memory for screenDatas
	for(int i=0;i<totalscreennum;i++){
		((modeData*)total_modes[modeNum])->screens[i]=malloc(sizeof(screenData)); //added because code below didn't work without it
		((modeData*)total_modes[modeNum])->screens[i]->screenNum=i; // give screenNums to screenDatas
	}
	Screen_MS_mainlist_init();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////








void inturrupt_worldtime(){	// < v ^ x
		//int countrynum=((screenType_listData*)(currentscreen->others[0]))->selected;
		screenType_listData* list=(screenType_listData*)currentscreen->others[0];
		if((PORTD->ISFR & (1<<9)) != 0){			//return to previous, <
			//times[0]->time_interrupt=currenttime_run;
			reconfig_currstate(1, 0, 0);//go back to mainscreen
		}
		else if((PORTD->ISFR & (1<<10)) != 0){	//down sigh, v
			screenType_list_operation_DOWN(list);
			screentype_list(currentscreen, list);	//put list datas into screenfrom
		}	
		else if((PORTD->ISFR & (1<<11)) != 0){	//up sign, ^
			screenType_list_operation_DOWN(list);
			screentype_list(currentscreen, list);	//put list datas into screenfrom
		}
}

void screenType_listData_WT_mainlist_listalloc_init(screenType_listData* temp){
	//list, input list string should account for cursor position
	temp->list=malloc(sizeof(char*)*temp->size);
	for(int i=0;i<temp->size;i++){
		temp->list[i]=malloc(sizeof(char)*23);
		for(int j=0;j<23;j++)temp->list[i][j]=worldtime_mainlist_list[i][j];
	}
	
}
void time_worldtimes_run(){
	timedelay_sec(times[0]->timedata, 1); //time passes
	char LCD_nums[10]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};	//for LCD
	int worldtimedelays[12]={0, 1, 2, 3, 6, 7, 8, 9, -8, -6, -5, -4};	//for calculating time zone
	int countrynum=((screenType_listData*)(((modeData*)total_modes[0])->screens[1]->others[0]))->selected;	//selected country
	screenType_listData* list=(screenType_listData*)currentscreen->others[0];
	
	// timeformat for each timezone
	timeFormat* worldtimeformats[12];
	for(int i=0;i<12;i++){
		worldtimeformats[i]=set_timeFormat(0, 0, 0, times[0]->timedata->timescales[3]+worldtimedelays[i]-worldtimedelays[countrynum]
																			 ,times[0]->timedata->timescales[4], times[0]->timedata->timescales[5]);//time zone hour delayed
		
		//print if day diff exists
		if(worldtimeformats[i]->timescales[3]<0){	//overflow to day
			worldtimeformats[i]->timescales[2]--;
			worldtimeformats[i]->timescales[3]+=24;
			list->list[i][13]='D';
			list->list[i][14]='-';
			list->list[i][15]='1';
		}
		else if(worldtimeformats[i]->timescales[3]>=24){
			worldtimeformats[i]->timescales[2]++;
			worldtimeformats[i]->timescales[3]-=24;
			list->list[i][13]='D';
			list->list[i][14]='+';
			list->list[i][15]='1';
		}
		//print time to screen
		list->list[i][17]=LCD_nums[worldtimeformats[i]->timescales[3]/10];
		list->list[i][18]=LCD_nums[worldtimeformats[i]->timescales[3]%10];
		list->list[i][20]=LCD_nums[worldtimeformats[i]->timescales[4]/10];
		list->list[i][21]=LCD_nums[worldtimeformats[i]->timescales[4]%10];
	}
	screentype_list(currentscreen, list);	//put list datas into screenfrom
	currentscreen->seg_num=timeFormat2timeInt(times[0]->timedata)/100;  //refresh seg_num
}

void Screen_WT_mainlist_init(){
	((modeData*)total_modes[2])->screens[0]->inturruptfuncs=malloc(sizeof(void(*)())*1); //1 interruptfuncsets
	((modeData*)total_modes[2])->screens[0]->inturruptfuncs[0]=inturrupt_worldtime;
	((modeData*)total_modes[2])->screens[0]->current_inturrupt=0;
	
	((modeData*)total_modes[2])->screens[0]->seg_num=0; //program freezes since screen_out has seg_out inside
	
	// allocate memory for list
	((modeData*)total_modes[2])->screens[0]->others=malloc(sizeof(void*)*1);
	
	//make screenType_listData without listdata;
	((modeData*)total_modes[2])->screens[0]->others[0]=set_screenType_listData(12, 2, 1, worldtime_mainlist_title, switch_config_worldtime_mainlist_countrylist);
	screenType_listData_WT_mainlist_listalloc_init(((modeData*)total_modes[2])->screens[0]->others[0]);//put listdata in List
	//times[0]->time_interrupt=time_worldtimes_run;
	screentype_list(((modeData*)total_modes[2])->screens[0], ((modeData*)total_modes[2])->screens[0]->others[0]);	//put list datas into screenfrom
	
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void mode_worldtime_init(){
	int totalscreennum=1;
	int modeNum=2;
	((modeData*)total_modes[modeNum])->totalscreennum=totalscreennum;
	((modeData*)total_modes[modeNum])->modeNum=modeNum;
	
	((modeData*)total_modes[modeNum])->screens=malloc(sizeof(screenData*)*totalscreennum);// allocate memory for screenDatas
	for(int i=0;i<totalscreennum;i++){
		((modeData*)total_modes[modeNum])->screens[i]=malloc(sizeof(screenData)); //added because code below didn't work without it
		((modeData*)total_modes[modeNum])->screens[i]->screenNum=i; // give screenNums to screenDatas
	}
	Screen_WT_mainlist_init();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

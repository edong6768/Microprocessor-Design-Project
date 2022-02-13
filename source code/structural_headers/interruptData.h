#include <stdlib.h>

#ifndef _INTRPT_S_H_
#define _INTRPT_S_H_

typedef struct{
void (*interruptfunc)(void);	
char *switch_config;
}interruptSet;

interruptSet* set_interruptSet(void (*interruptfunc)(void), char* switch_config){
	interruptSet* temp = malloc(sizeof(interruptSet));
	temp->interruptfunc=interruptfunc;
	temp->switch_config=switch_config;
	return temp;
}	


#endif
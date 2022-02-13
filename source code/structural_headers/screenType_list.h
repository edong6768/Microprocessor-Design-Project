// PUSH : D

#include <stdlib.h>
#include <stdio.h>
#include "screen.h"

#ifndef _SCR_T_LIST_H_
#define _SCR_T_LIST_H_

typedef struct{
	int size, height, cursor_loc, top_num, has_title, selected;
	char** list;
	char *title;		// in screenline format, 23 char
	char *switch_config;	// in screenline format, 23 char
}screenType_listData;


screenType_listData* set_screenType_listData(
	int size, int height, int has_title, 
	char *title, char *switch_config
	){
	screenType_listData *temp = malloc(sizeof(screenType_listData));
	
	//initial state
	temp->cursor_loc=0;
	temp->top_num=0;
	temp->selected=0;
	//enter values
	temp->size=size;
	temp->height=height;
	temp->has_title=has_title;
	//title and switch
	temp->title=title;
	temp->switch_config=switch_config;
	return temp;
}

// display list screen of pList to pScreen 
void screentype_list(screenData* pScreen, screenType_listData* pList){
	//basic structural stuff
	for(int i=0;i<23;i++){
		if(pList->has_title) pScreen->msg[0][i]=pList->title[i];
		pScreen->switch_config[i]=pList->switch_config[i];
	}
	//actual list, skip one space in front of line for cursor 
	for(int i=0;i<pList->height;i++){
		for(int j=0; j<23;j++) {
			pScreen->msg[pList->has_title+i][j]=pList->list[pList->top_num+i][j];
		}
	}
	pScreen->msg[pList->cursor_loc+pList->has_title][0]='>';	//cursor
}
void screenType_list_operation_UP(screenType_listData* list){
			if(list->cursor_loc>0) {
				list->cursor_loc--;
				list->selected--;
			}
			else if(list->top_num>0) {
				list->top_num--;
				list->selected--;
			}
}

void screenType_list_operation_DOWN(screenType_listData* list){
			if(list->cursor_loc<list->height-1) {
				list->cursor_loc++;
				list->selected++;
			}
			else if(list->top_num+list->height<list->size) {
				list->top_num++;
				list->selected++;
			}	
}


int screenType_list_rewriteLine(screenType_listData* list, char* line, int lineNum){
	if(list->size-1<lineNum) return 0;
	else for(int j=0;j<23;j++) list->list[lineNum][j]=line[j];
	return 1;
}


#endif
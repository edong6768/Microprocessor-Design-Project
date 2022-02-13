#include <stdlib.h>

#ifndef _TMS_H_
#define _TMS_H_


typedef struct{
	int timescales[6];
	//int year, month, day, hour, min, sec;	
}timeFormat;

typedef struct{
	timeFormat* timedata;
	void (*time_interrupt)();
	int timenum;
}timeSession;

timeFormat* set_timeFormat(int year, int month, int day, int hour, int min, int sec){
	timeFormat* tmp=malloc(sizeof(timeFormat));
	tmp->timescales[0]=year;
	tmp->timescales[1]=month;
	tmp->timescales[2]=day;
	tmp->timescales[3]=hour;
	tmp->timescales[4]=min;
	tmp->timescales[5]=sec;
	return tmp;
}

void timeInt2timeFormat(timeFormat* tmp, int timeInt){
	tmp->timescales[3]=timeInt/10000;
	tmp->timescales[4]=timeInt%10000/100;
	tmp->timescales[5]=timeInt%100;
}

int timeFormat2timeInt(timeFormat* tmp){
	return tmp->timescales[3]*100+tmp->timescales[4];
}

int timedelay_sec(timeFormat* time, int delay){
	int upperlimit[3]={24, 60, 60};
	int overflow=0;
	time->timescales[5]++;
	for(int i=5;i>2;i--){
			time->timescales[i-1]+=time->timescales[i]/upperlimit[i];
			time->timescales[i]%=upperlimit[i];
	}
	if(time->timescales[2]){
		overflow=1;
		time->timescales[2]=0;
	}
	return overflow;
}

int timedelay_sec_reverse(timeFormat* time, int delay){
	int upperlimit[3]={24, 60, 60};
	int overflow=0;
	time->timescales[5]++;
	for(int i=5, j;i>2;i--){
			if(time->timescales[i]<0){
				j=(-time->timescales[i])/upperlimit[i];
				time->timescales[i-1]-=(j+1);
				time->timescales[i]+=(j+1)*upperlimit[i];
			}
			time->timescales[i-1]-=time->timescales[i]/upperlimit[i];
			time->timescales[i]%=upperlimit[i];
	}
	if(time->timescales[2]){
		overflow=-1;
		time->timescales[2]=0;
	}
	return overflow;
}
//void timestop(){}
	
//int timedelay(timeFormat* time, int mode, int delay){
//	int upperlimit[6]={10000, 12, 31, 23, 59, 59};
//	int month_upper[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//	for(int n=delay;n>=0;n--){
//		time->timescales[mode]++;
//		for(int i=mode;i>0;i--){
//				while(time->timescales[i]>upperlimit[i]){
//					time->timescales[i-1]+=time->timescales[i]/upperlimit[i];
//					time->timescales[i]%=upperlimit[i];
//				}
//		}
//	}
//}

#endif
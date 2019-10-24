/*
 \file		ex1rrp.c
 \author	${user}
 \date		${date}
 \brief		Simple Hello World! for the Ev3
*/

#include <ev3.h>


int main(void){


	InitEV3();
	int i;
	for(i=30; i<=100;i++){
		OnFwdSync(OUT_AC, i);
		Wait(SEC_1);
    }
	Off(OUT_AC);
	FreeEV3();
	return 0;
}

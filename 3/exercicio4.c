/*
 \file		ex.c
 \author	${user}
 \date		${date}
 \brief		Simple Hello World! for the Ev3
*/

#include <ev3.h>

int main(void)
{
	//TODO Place here your variables

	InitEV3();

	for(i=1; i<16; i++){
		OnFwdSync(OUT_AC,50);
		Wait(SEC_2);
		
		if(i%2==0){
			OnFwdReg(OUT_A,25);
			Wait(MS_700);
		}
		if(i%2!=0){
			OnRevReg(OUT_C, 25);
			Wait(MS_700);
		}
	}
	 Off(OUT_A);
	 OnFwdReg(OUT_C,30);
	 Wait(SEC_4);
	 Off(OUT_C);
	
	

	FreeEV3();
	return 0;
}

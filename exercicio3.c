/*
 ============================================================================
 Name        : exercicio4.c
 Author      : Joao
 Version     : 1.0
 Copyright   :
 ============================================================================
 */

#include <stdlib.h>
#include <time.h>
#include <ev3.h>

int main(void){							//motor direito = OUT_C, esquerdo = OUT_B
	InitEV3();

	int numero, i;

	rands(time(0));

	for(i = 0; i < 10; i++)
	{
		numero = rand() % 101;

		if(numero <= 25 || numero > 75)
		{
			OnFwdSync(OUT_C, 40);
			Wait(SEC_2);
		}
		else
		{
			OnFwdReg(OUT_B, 40);
			Wait(SEC_2);
		}
	}


    freeEV3();
    return 0;
}

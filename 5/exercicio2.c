/*
Com base no código abaixo, crie funções para melhorar a interpretação do código e evitar a
repetição desnecessária de comandos.
 */

# include <ev3.h>

void run(int motor, int speed, int wait){
	OnFwdReg(motor, speed);
	Wait (wait);
}

int main (void) {
	InitEV3() ; // Inicializando as funcoes do EV3
	run(OUT_AC, 60, 1000);
	run(OUT_AC, 60, 1000);
	Off(OUT_C) ;
	run(OUT_A, -60, 500);
	Off(OUT_A) ;
	run(OUT_C, -60, 500);
	run(OUT_AC, 60, 1000);
	Off(OUT_C) ;
	run(OUT_A, -60, 500);
	Off(OUT_C) ;
	run(OUT_A, 60, 500);
	run(OUT_AC, 60, 1000);
	Off(OUT_A) ;
	run(OUT_C, 60, 500);
	run(OUT_AC, -60, 1000);
	Off(OUT_AC) ; // Desliga os motores
	FreeEV3 () ; // Desliga todas as funcoes do EV3
	return 0;
}

/*
Baseado no código abaixo, utilizando funções sem a apresentação de parâmetros no escopo do
programa, mostre como seria o mesmo com a utilização de parâmetros
 */

#include <ev3.h>

void girar(int motorRotate, int motorFwrd, int durationRotate, int durationFwrd, int speed) { // Funcao que engloba as instrucoes para fazer o robo girar
	OnRevReg(motorRotate, speed); // Acionando o motor C para tras
	Wait(durationRotate);
	OnFwdReg(motorFwrd, speed);
	Wait(durationFwrd);
}

void andar_frente(int motor, int speed, int duration) { // Funcao que engloba as instrucoes para o robo andar pra frente
	OnFwdReg(motor, speed); // Acionando ambos os motores A e C para frente
	Wait(duration);
}

int main() {
	InitEV3();
	while(ButtonIsDown(BTNDOWN) == 0){ // Botão do brick não pressionado
		InitEV3() ; // Inicializando as funcoes do EV3
		andar_frente(OUT_AC, 60, 1000);
		girar(OUT_C, OUT_AC, 900, 1000, 60);
		girar(OUT_C, OUT_AC, 900, 1000, 60);
		girar(OUT_C, OUT_AC, 900, 1000, 60);
		Off(OUT_AC); // Desliga os motores
		FreeEV3();
	}
	FreeEV3();
	return 0;
}

/*
 Faça um algoritmo que calcule um número aleatório repetidamente, entre 0 e 30, até que o
 botão do brick seja pressionado. Caso seja um número menor que 10, vire à esquerda. Se for
 maior ou igual a 10 e menor que 20 siga em frente. Se for maior ou igual que 20 e menor
 ou igual que 30, vire à direita. Cada função de movimentação deve acontecer por 1 segundo.
 Dica: utilize a função srand().
*/

#include <ev3.h>

int main(void) {

	int random = 0;

	srand(time(0));

	while(1){
		if(ButtonIsDown(BTNDOWN) == 0){ // Botão do brick não pressionado
			random = rand() % (30 + 1 - 0) + 0; // random entre 0 e 30
		}else{ // Botão do brick pressionado
			if(random < 10){
				OnFwdReg(OUT_A, -30);
				OnFwdReg(OUT_C, 30);
				Wait(SEC_1);
			}
			if(random >= 10 && random < 20){
				OnFwdReg(OUT_AC, 30);
				Wait(SEC_1);
			}
			if(random >= 20 && random <= 30){
				OnFwdReg(OUT_A, 30);
				OnFwdReg(OUT_C, -30);
				Wait(SEC_1);
			}
		}
	}

	FreeEV3();
	return 0;
}

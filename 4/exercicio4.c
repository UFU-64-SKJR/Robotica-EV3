/*
 Neste exercício você deverá utilizar o sensor de cor para guiar o robô em uma trajetória num
campo. O campo, como mostrado abaixo, é composto de 4 linhas pretas. O robô deve ser
posicionado antes de qualquer linha. O trajeto a ser percorrido é o seguinte: o robô tem de
seguir em frente, até encontrar a primeira linha preta, então deve retornar até sua posição
inicial, depois deve seguir em frente, até encontrar a segunda linha preta, ignorando a primeira.
O robô deve seguir fazendo esse processo até chegar a quarta e última linha preta
 */

#include <ev3.h>

int main(void) {

	InitEV3();
	int test = setAllSensorMode(COL_COLOR, NO_SEN, NO_SEN, NO_SEN);
	int lastBlackLine = 0;
	int linesCount = 0;
	
	if(test == 0) {
		while(ButtonIsDown(BTNDOWN) == 0){ // Botão do brick não pressionado
			if(linesCount == 4) break;
			OnFwdReg(OUT_AC, 25);
			
			int color = readSensor( IN_1 );
			
			if(color == 1 && MotorRotationCount() > lastBlackLine + 50) { // + 50 para margem de erro
				RotateMotor(OUT_AC, 25, -lastBlackLine);
				ResetRotationCount(OUT_AC);
				linesCount++;
			}
		}
	}


	FreeEV3();
	return 0;
}

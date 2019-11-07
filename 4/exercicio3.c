/*
  Muitas vezes, quando programamos o robô, os motores não operam sincronizados, o que
resulta no robô tendendo para o lado do motor que exerce a menor força. Neste desafio você
irá resolver esse problema. Usando o sensor giroscópio, sem o auxílio de outros sensores, faça
o robô andar em linha reta, corrigindo sua trajetória conforme ele desvie para as laterais
 */

#include <ev3.h>

int main(void) {

	InitEV3();

	int motorSpeedA = 25, motorSpeedC = 25;
	int gyroscope = setAllSensorMode(GYRO_ANG, NO_SEN, NO_SEN, NO_SEN);

	if(gyroscope == 0) {
		while(ButtonIsDown(BTNDOWN) == 0){ // Botão do brick não pressionado
			int initAxis;
			initAxis = readSensor(IN_1);

			OnFwdReg(OUT_A, motorSpeedA);
			OnFwdReg(OUT_C, motorSpeedC);
			while(initAxis != readSensor(IN_1)) {
				int actualAxis = readSensor(IN_1);
				if(initAxis > actualAxis){
					motorSpeedA++;
				}else{
					motorSpeedC++;
				}
			}
		}
	}


	FreeEV3();
	return 0;
}

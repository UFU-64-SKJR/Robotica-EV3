/*
 Crie um robô que “fuja” dos obstáculos, ou seja, ao identificar um obstáculo, dê ré e faça
 uma curva para outro lado. Experimente utilizar os sensores de toque e ultrassônico. Depois,
 analise qual é preferível.
*/

#include <ev3.h>

int main(void) {

	InitEV3();

	int sensor = 1; // 0 = Toque, 1 = Ultrassonico

	if(sensor == 1) {
		int touch = setAllSensorMode(TOUCH_PRESS, NO_SEN, NO_SEN, NO_SEN);

		if(touch == 0) {
			while(ButtonIsDown(BTNDOWN) == 0){ // Botão do brick não pressionado
				OnFwrReg(OUT_AC, 25);
				if(readSensor(IN_1) == 1) {
					OnRevReg(OUT_AC, 25);
					Wait(500);
					Off(OUT_AC);
					OnRevReg(OUT_A, 30);
					OnRevReg(OUT_C, -30);
					Wait(1000);
				}
			}
		}
	}else{ //Sensor ultrassonico
		int ultrasonic = setAllSensorMode(US_DIST_MM, NO_SEN, NO_SEN, NO_SEN);

		if(ultrasonic == 0) {
			while(ButtonIsDown(BTNDOWN) == 0){ // Botão do brick não pressionado
				OnFwrReg(OUT_AC, 25);
				if(500 >= readSensor(IN_1)) {
					Off(OUT_AC);
					while (500 >= readSensor(IN_1)) {
						OnRevReg(OUT_A, 30);
						OnRevReg(OUT_C, -30);
						Wait(1000);
					}
				}
			}
		}
	}

	FreeEV3();
	return 0;
}

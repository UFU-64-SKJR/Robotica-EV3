/*
 . Faça com que o robo ande até que seja encontrado um objeto. Após isto, faça com que o robo
	o capture.
 */

#include <ev3.h>

int main(void) {

	InitEV3();
	int touch = setAllSensorMode(TOUCH_PRESS, NO_SEN, NO_SEN, NO_SEN);

	if(touch == 0) {
		while(ButtonIsDown(BTNDOWN) == 0){ // Botão do brick não pressionado
			OnFwdReg(OUT_AC, 25);
			if(readSensor(IN_1) == 1) {
				Off(OUT_AC);
				OnFwdReg(OUT_B, 10);
				Wait(1000);
				Off(OUT_B);
				OnRevReg(OUT_AC, 25);
			}
		}
	}


	FreeEV3();
	return 0;
}

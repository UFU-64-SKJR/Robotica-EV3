#include <ev3.h>

int main(void) {

	InitEV3();


	while(ButtonIsDown(BTNDOWN) == 0){ // Botão do brick não pressionado
		RotateMotor(OUT_BC, 30, 617);
		break;
	}

	FreeEV3();
	return 0;
}

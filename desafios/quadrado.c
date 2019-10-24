#include <ev3.h>

int main(void) {

	InitEV3();

	while(ButtonIsDown(BTNDOWN) == 0){ // Botão do brick não pressionado
		OnFwdReg(OUT_AC, 30);
		Wait(2000);
		Off(OUT_AC);

		OnFwdReg(OUT_C, 60);
		Wait(650);
		Off(OUT_C);
	}


	FreeEV3();
	return 0;
}

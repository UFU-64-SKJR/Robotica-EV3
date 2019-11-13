/*
No exemplo a seguir, aponte o erro no código e faça a correção para que o código funcione
corretamente:
 */

# include <stdio.h>
# include <stdlib.h>

// Funcao para fazer a multiplicacao
int multiplica (int N1 , int N2) {
	int resultado = N1 * N2; //As variaveis utilziadas dentro da função estavam apontando para as variaveis da main, não sendo possivel acessa-las
	return resultado;
}

int main () {
	int V1 , V2 , resultado ;
	printf("\nDigite o primeiro valor: ") ;
	scanf("%d", &V1) ;
	printf("\nDigite o segundo valor: ");
	scanf("%d", &V2) ;
	resultado = multiplica (V1 ,V2) ; // Chamada da funcao
	printf("\nResultado = %d\n", resultado) ;
	return 0;
}

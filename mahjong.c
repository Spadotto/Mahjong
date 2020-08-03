#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	char tabuleiro[10][10];
	char pecas[100] = {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'G', 'G', 'G', 'G', 'G', 'G','H', 'H', 'H', 'H', 'H', 'H', 'I', 'I', 'I', 'I', 'I', 'I', 'J', 'J', 'J', 'J', 'J', 'J', 'K', 'K', 'K', 'K', 'L', 'L', 'L', 'L', 'M', 'M', 'M', 'M', 'N', 'N', 'N', 'N', 'O', 'O', 'P', 'P', 'Q', 'Q', 'R', 'R'};
	int i, j, aux, vencedor = 0;
	int pecasrest;
	int borda[10][10] = {0};
	int l1, c1, sum1;
	int l2, c2, sum2;
	int nivel, valido = 0;
	time_t hora1, hora2;
	int temporest, hora3 = NULL;

	srand(time(NULL));

	while(valido == 0){
		printf("\nEscolha seu nivel: \n");
		printf("\n(1)Potato: 20 min;");
		printf("\n(2)Boring: 10 min;");
		printf("\n(3)HardCore: 5 min\n");
		scanf("%d", &nivel);

		if(nivel == 1){
			temporest = 1200;
			valido = 1;
		}else if(nivel == 2){
			temporest = 600;
			valido = 1;
		}else if(nivel == 3){
			temporest = 300;
			valido = 1;
		}else{
			printf("\nVoce digitou um valor invalido!\n");
			valido = 0;
		}
		system("cls");
	}

	for(i=0; i<10; i++){//coloca '1' nas bordas da matriz de '0'.
		borda[0][i] = 1;
		borda[10-1][i] = 1;
		borda[i][0] = 1;
		borda[i][10-1] = 1;
	}

	for(i=0; i<10; i++){//preenche com as peças.
		for(j=0; j<10; j++){
			aux = rand()%100;
			if(pecas[aux] == 'X'){
				while(pecas[aux] == 'X'){
					aux = rand()%100;
				}
			}
			tabuleiro[i][j] = pecas[aux];
			pecas[aux] = 'X';
		}
	}

	hora1 = time(NULL);

	printf("\n     0       1    2    3    4    5    6    7    8    9    10\n");
	printf("\n	+-------------------------------------------------------+\n");
	for(i=0; i<10; i++){
		if(i == 9){
			printf("	|                                                       |\n     %d |", i+1);
		}else{
			printf("	|                                                       |\n     %d  |", i+1);
		}
		for(j=0; j<10; j++){
			printf("    %c", tabuleiro[i][j]);
			if(tabuleiro[i][j] == '\n'){
				printf("|\n");
			}
		}
		printf("	|\n	|                                                       |\n");
	}
	printf("	+-------------------------------------------------------+\n ");

	while(temporest > hora3){
		hora2 = time(NULL);

		hora3 = hora2 - hora1;//diferença da hora de inicio de exucução com a atual.

		printf("\n%d\n", hora3);
		scanf("%d %d", &l1, &c1);
		scanf("%d %d", &l2, &c2);
		l1--;
		c1--;
		l2--;
		c2--;
		sum1 = l1*l1-c1*c1;
		sum2 = l2*l2-c2*c2;

		if(tabuleiro[l1][c1] == tabuleiro[l2][c2] && borda[l1][c1] != 0 && borda[l2][c2] != 0 && sum1 != sum2 && tabuleiro[l1][c1] != ' '){
			tabuleiro[l1][c1] = ' ';
			tabuleiro[l2][c2] = ' ';

			//transforma os valores ao redor em borda.
			borda[l1-1][c1] = 1;
			borda[l1][c1-1] = 1;
			borda[l1+1][c1] = 1;
			borda[l1][c1+1] = 1;

			borda[l2-1][c2] = 1;
			borda[l2][c2-1] = 1;
			borda[l2+1][c2] = 1;
			borda[l2][c2+1] = 1;

			system("cls");
			printf("\n     0       1    2    3    4    5    6    7    8    9    10\n");
			printf("\n	+-------------------------------------------------------+\n");
			for(i=0; i<10; i++){
				if(i == 9){
					printf("	|                                                       |\n     %d |", i+1);
				}else{
					printf("	|                                                       |\n     %d  |", i+1);
				}
				for(j=0; j<10; j++){
					printf("    %c", tabuleiro[i][j]);
					if(tabuleiro[i][j] == '\n'){
					printf("|\n");
					}
				}
				printf("	|\n	|                                                       |\n");
			}
			printf("	+-------------------------------------------------------+\n");
		}else{
			printf("	\nJogada invalida!\nTente novamente!");
		}
		vencedor = 0;

		pecasrest=0;
		for(i=0; i<10; i++){//contador para saber se já acabaram todas as peças do tabuleiro.
			for(j=0; j<10; j++){
				if(tabuleiro[i][j] == ' '){
					pecasrest++;
					vencedor += 1;
				}
			}
		}
		if(pecasrest == 100){
			break;
		}
	}
	system("cls");

	if(!vencedor == 100){
		printf("\n	  PARABENS TU VENCESTES!!!\n\n");
	}else{
		printf("\n	  VOCE PERDEU!\n\tACABOU O TEMPO!\n\n");
	}

	system("PAUSE");
	return 0;
}


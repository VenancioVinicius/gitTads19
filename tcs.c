#include <stdio.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <stdio_ext.h>
#include <stdlib.h>

#define LAR 		40
#define ALT 		20
#define CAMINHO 	0
#define PAREDE 		1
#define ENTRADA 	2
#define SAIDA 		3
#define OBJETO		4

int getch(void);

int main() {
	
	int alt, lar, vh, vd, eh, ed, ehf, edf, dh, dd, ae, de, es, ts, tsf, qd, vrd, erd, erdf, drd;
	int turno, partida, tentativa, deg, del;
	int guerreiro, ladino;
	int mapa[ALT][LAR];
	int menu;
	int sec = 5;
	int min = 5;
	int gameover;
	int lin, col, final, px, py;
	int a = 1, b = 0, c = 0, inicio = 0;
	char jogada, dificuldade, personagem, novamente;

	lar = 40;
	alt = 20;
	novamente = 's';
	
while(novamente == 's' || novamente == 'S'){
	tentativa = 1;
	system("clear");
	srand(time(NULL));
	
	printf("\t\t |   /  | |        |      ");
	printf("\n\t\t |  /   | |        |      ");
	printf("\n\t\t | /    | |        |      ");
	printf("\n\t\t | \\    | |        |      ");
	printf("\n\t\t |  \\   | |        |      ");
	printf("\n\t\t |   \\  | |______  |______");

	printf("\n\t ________     _         ___ ___   _____");
	printf("\n\t     |       / \\     | |   |   | |     ");
	printf("\n\t     |      /   \\    | |   |   | |     ");
	printf("\n\t     |     /_____\\   | |   |   | |_____");
	printf("\n\t     /    /_______\\  | |   |   | |     ");
	printf("\n\t  __/    /         \\ | |   |   | |_____");

	printf("\n\n Depois de Jaime ter sido resgatado por seu amigo \nele foi atropelado sem querer, culpando seu amigo \npor isso ele reencarnou como um demônio buscando \nvingança, depois de caçadores encontrarem seu \nesconderijo os mesmos chamaram os heróis que são \nos únicos que podem mata-lo, mate-o antes que ele \ncomplete sua reencarnação.");
	getchar();
	
	system("clear");
	printf("\t\t |   /  | |        |      ");
	printf("\n\t\t |  /   | |        |      ");
	printf("\n\t\t | /    | |        |      ");
	printf("\n\t\t | \\    | |        |      ");
	printf("\n\t\t |  \\   | |        |      ");
	printf("\n\t\t |   \\  | |______  |______");

	printf("\n\t ________     _         ___ ___   _____");
	printf("\n\t     |       / \\     | |   |   | |     ");
	printf("\n\t     |      /   \\    | |   |   | |     ");
	printf("\n\t     |     /_____\\   | |   |   | |_____");
	printf("\n\t     /    /_______\\  | |   |   | |     ");
	printf("\n\t  __/    /         \\ | |   |   | |_____");

	printf("\n\n Dificuldade do jogo: \n 1 - fácil\n 2 - médio\n 3 - difícil\n\n");
	__fpurge(stdin);
	dificuldade = getchar();
	
	system("clear");
	printf("\t\t |   /  | |        |      ");
	printf("\n\t\t |  /   | |        |      ");
	printf("\n\t\t | /    | |        |      ");
	printf("\n\t\t | \\    | |        |      ");
	printf("\n\t\t |  \\   | |        |      ");
	printf("\n\t\t |   \\  | |______  |______");

	printf("\n\t ________     _         ___ ___   _____");
	printf("\n\t     |       / \\     | |   |   | |     ");
	printf("\n\t     |      /   \\    | |   |   | |     ");
	printf("\n\t     |     /_____\\   | |   |   | |_____");
	printf("\n\t     /    /_______\\  | |   |   | |     ");
	printf("\n\t  __/    /         \\ | |   |   | |_____");
	
	printf("\n\n Com qual personagem deseja jogar: \n 1 - Guerrerio: Possui mais vida e força \n 2 - Ladino: possui mais agilidade evitando ataques \n\n");
	__fpurge(stdin);
	personagem = getchar();

	// INICIALIZA O MAPA COM PAREDES
	for(lin=0; lin<alt; lin++) {
		for(col=0; col<lar; col++) {
			mapa[lin][col] = CAMINHO;
			if(lin == 0){ mapa[lin][col] = PAREDE; }
			if(col == 0){ mapa[lin][col] = PAREDE; }
			if(lin == 19){ mapa[lin][col] = PAREDE; }
			if(col == 39){ mapa[lin][col] = PAREDE; }
			
			//FACIL
			if(dificuldade == '1'){
				if(lin == 3 && col != 1 && col != 2 && col != 3 && col != 4 && col != 5 && col != 6 && col != 7 && col != 8 && col != 9 && col != 10 && col != 11 && col != 12 && col != 13 && col != 14 && col != 26 && col != 27 && col != 28 && col != 29 && col != 30 && col != 31 && col != 32 && col != 33 && col != 34 && col != 35 && col != 36 && col != 37 && col != 38){ mapa[lin][col] = PAREDE; }
				if(col == 15 && lin != 1 && lin != 2 && lin != 3 && lin != 17 && lin != 18){ mapa[lin][col] = PAREDE; }
				if(col == 25 && lin != 1 && lin != 2 && lin != 3 && lin != 17 && lin != 18){ mapa[lin][col] = PAREDE; }
				if(lin == 16 && col != 1 && col != 2 && col != 3 && col != 4 && col != 5 && col != 6 && col != 7 && col != 8 && col != 9 && col != 10 && col != 11 && col != 12 && col != 13 && col != 14 && col != 26 && col != 27 && col != 28 && col != 29 && col != 30 && col != 31 && col != 32 && col != 33 && col != 34 && col != 35 && col != 36 && col != 37 && col != 38){ mapa[lin][col] = PAREDE; }
				if(lin == 12 && col != 1 && col != 2 && col != 3 && col != 4 && col != 5 && col != 6 && col != 7 && col != 8 && col != 9 && col != 10 && col != 11 && col != 12 && col != 13 && col != 14 && col != 26 && col != 27 && col != 28 && col != 29 && col != 30 && col != 31 && col != 32 && col != 33 && col != 34 && col != 35 && col != 36 && col != 37 && col != 38){ mapa[lin][col] = PAREDE; }
				
				//INIMIGOS
				if(lin == 5 && col == 20){ mapa[lin][col] = OBJETO; }
				if(lin == 14 && col == 20){ mapa[lin][col] = OBJETO; }
				qd = 1;
			}
			
			//MEDIO
			if(dificuldade == '2'){
				if(col == 5  && lin != 1 && lin != 2 && lin != 3 && lin != 4 && lin != 5 && lin != 6  && lin != 7 && lin != 13 && lin != 14 && lin != 15 && lin != 16 && lin != 17 && lin != 18){ mapa[lin][col] = PAREDE; }
				
				if(col == 15 && lin != 1 && lin != 2 && lin != 3 && lin != 4 && lin != 5 && lin != 6 && lin != 7 && lin != 8 && lin != 9 && lin != 10 && lin != 11 && lin != 17 && lin != 18){ mapa[lin][col] = PAREDE; }
				if(col == 25 && lin != 1 && lin != 2 && lin != 3 && lin != 4 && lin != 5 && lin != 6 && lin != 7 && lin != 8 && lin != 9 && lin != 10 && lin != 11 && lin != 17 && lin != 18){ mapa[lin][col] = PAREDE; }
				if(col == 34  && lin != 1 && lin != 2 && lin != 3 && lin != 4 && lin != 5 && lin != 6  && lin != 7 && lin != 13 && lin != 14 && lin != 15 && lin != 16 && lin != 17 && lin != 18){ mapa[lin][col] = PAREDE; }
				if(lin == 8 && col != 1 && col != 2 && col != 3 && col != 4 && col != 35 && col != 36 && col != 37 && col != 38){ mapa[lin][col] = PAREDE; }
				if(lin == 12 && col != 1 && col != 2 && col != 3 && col != 4 && col != 5 && col != 34 && col != 35 && col != 36 && col != 37 && col != 38){ mapa[lin][col] = PAREDE; }
				if(lin == 16 && col != 1 && col != 2 && col != 3 && col != 4 && col != 5 && col != 6 && col != 7 && col != 8 && col != 9 && col != 10 && col != 11 && col != 12 && col != 13 && col != 14 && col != 26 && col != 27 && col != 28 && col != 29 && col != 30 && col != 31 && col != 32 && col != 33 && col != 34 && col != 35 && col != 36 && col != 37 && col != 38){ mapa[lin][col] = PAREDE; }
				
				//INIMIGOS
				if(lin == 10 && col == 8){ mapa[lin][col] = OBJETO; }
				if(lin == 10 && col == 31){ mapa[lin][col] = OBJETO; }
				if(lin == 14 && col == 20){ mapa[lin][col] = OBJETO; }
				qd = 2;
			}
			
			//MODO DIFICIL
			if(dificuldade == '3'){	
				if(lin == 3 && col != 1 && col != 2 && col != 3 && col != 4 && col != 5 && col != 6 && col != 7 && col != 8 && col != 9 && col != 10 && col != 11 && col != 12 && col != 13 && col != 14 && col != 26 && col != 27 && col != 28 && col != 29 && col != 30 && col != 31 && col != 32 && col != 33 && col != 34 && col != 35 && col != 36 && col != 37 && col != 38){ mapa[lin][col] = PAREDE; }
				if(col == 15 && lin != 1 && lin != 2 && lin != 3 && lin != 9 && lin != 10 && lin != 11 && lin != 17 && lin != 18){ mapa[lin][col] = PAREDE; }
				if(col == 25 && lin != 1 && lin != 2 && lin != 3 && lin != 9 && lin != 10 && lin != 11 && lin != 17 && lin != 18){ mapa[lin][col] = PAREDE; }
				if(col == 5  && lin != 1 && lin != 2 && lin != 3 && lin != 4 && lin != 5 && lin != 6  && lin != 7 && lin != 13 && lin != 14 && lin != 15 && lin != 16 && lin != 17 && lin != 18){ mapa[lin][col] = PAREDE; }
				if(col == 34  && lin != 1 && lin != 2 && lin != 3 && lin != 4 && lin != 5 && lin != 6  && lin != 7 && lin != 13 && lin != 14 && lin != 15 && lin != 16 && lin != 17 && lin != 18){ mapa[lin][col] = PAREDE; }

				if(lin == 16 && col != 1 && col != 2 && col != 3 && col != 4 && col != 5 && col != 6 && col != 7 && col != 8 && col != 9 && col != 10 && col != 11 && col != 12 && col != 13 && col != 14 && col != 26 && col != 27 && col != 28 && col != 29 && col != 30 && col != 31 && col != 32 && col != 33 && col != 34 && col != 35 && col != 36 && col != 37 && col != 38){ mapa[lin][col] = PAREDE; }
			if(lin == 8 && col != 1 && col != 2 && col != 3 && col != 4 && col != 16 && col != 17 && col != 18 && col != 19 && col != 20 && col != 21 && col != 22 && col != 23 && col != 24 && col != 35 && col != 36 && col != 37 && col != 38){ mapa[lin][col] = PAREDE; }
			if(lin == 12 && col != 1 && col != 2 && col != 3 && col != 4 && col != 5 && col != 34 && col != 35 && col != 36 && col != 37 && col != 38){ mapa[lin][col] = PAREDE; }
			
			
			//INIMIGOS
			if(lin == 5 && col == 20){ mapa[lin][col] = OBJETO; }
			if(lin == 10 && col == 8){ mapa[lin][col] = OBJETO; }
			if(lin == 10 && col == 31){ mapa[lin][col] = OBJETO; }
			if(lin == 14 && col == 20){ mapa[lin][col] = OBJETO; }
			qd = 3;
		}
		}
	}

	// MAPA
	partida = 0;
	final = 0;
	px = 10;
	py = 20;
while(partida == 0){
	while(final == 0) {

		system("clear");
		
		//PARA ABRIR O CAMINHO PARA O CHEFE
		if(dificuldade == '1'){
			if(qd == 0){
				for(lin=0; lin<alt; lin++) {
					for(col=0; col<lar; col++) {
						if(lin == 12){ mapa[lin][col] = CAMINHO;}
						if(lin == 12 && col != 1 && col != 2 && col != 3 && col != 4  && col != 5 && col != 6 && col != 7 && col != 8 && col != 9 && col != 10 && col != 11 && col != 12 && col != 13 && col != 14 && col != 16 && col != 17 && col != 18 && col != 19 && col != 20 && col != 21 && col != 22 && col != 23 && col != 24 && col != 35 && col != 36 && col != 37 && col != 38){ mapa[lin][col] = PAREDE; }
						}
				}
			}
		}
		
		if(dificuldade == '2'){
			if(qd == 0){
				for(lin=0; lin<alt; lin++) {
					for(col=0; col<lar; col++) {
						if(lin == 12){ mapa[lin][col] = CAMINHO;}
						if(lin == 12 && col != 1 && col != 2 && col != 3 && col != 4 && col != 16 && col != 17 && col != 18 && col != 19 && col != 20 && col != 21 && col != 22 && col != 23 && col != 24 && col != 35 && col != 36 && col != 37 && col != 38){ mapa[lin][col] = PAREDE; }
						}
				}
			}
		}
		
		if(dificuldade == '3'){	
			if(qd == 0){
				for(lin=0; lin<alt; lin++) {
					for(col=0; col<lar; col++) {
						if(lin == 12){ mapa[lin][col] = CAMINHO;}
						if(lin == 12 && col != 1 && col != 2 && col != 3 && col != 4 && col != 16 && col != 17 && col != 18 && col != 19 && col != 20 && col != 21 && col != 22 && col != 23 && col != 24 && col != 35 && col != 36 && col != 37 && col != 38){ mapa[lin][col] = PAREDE; }
						}
				}
			}
		}
			//if(vh == 0){
			//	for(lin=0; lin<ALT; lin++) {
			//		for(col=0; col<LAR; col++) {
			//			if(lin == 10 && col == 20) {
			//				printf("_");
			//			}
			//		}
			//	}
			//}
			
		printf("\t\n                   O TEMPO ESTA CORRENDO\n");
		
		for(lin=0; lin<ALT; lin++) {
			printf("\t");
			for(col=0; col<LAR; col++) {

				if(lin == px && col == py) {
					printf("♰");
				}
				else if(mapa[lin][col] == CAMINHO) {
					printf(" ");
				}
				else if(mapa[lin][col] == PAREDE) {
					printf("#");
				}
				else if(mapa[lin][col] == OBJETO) {
					printf("✇");
				}
			}
			printf("\n");
		}		
		printf("\t\t    controles: ⇠ ⇡ ⇢ ⇣\n");
		
		
		// CAPTURA TECLA
		jogada = getch();

		// TECLA ESPECIAL
		if(jogada == 27) {
			jogada = getch(); 

			if(jogada == 91) {      
				jogada = getch();
				
				// CIMA
				if(jogada == 65) {
					if( mapa[px-1][py] != PAREDE){
						if(mapa[5][20] == OBJETO){
							if(mapa[px-1][py] == mapa[5][20]){ final = 1; }
						}
						if(px > 1) {
							px--;
						}
					}
				}
	  			// BAIXO
				else if(jogada == 66) {
					if( mapa[px+1][py] != PAREDE){
						if(mapa[14][20] == OBJETO){
		    				if(mapa[px+1][py] == mapa[14][20]){ final = 1; }
		    			}
		    			if(px < LAR-1) {
						px++;
						}
					}
				}
				// DIREITA
				else if(jogada == 67) {
					if( mapa[px][py+1] != PAREDE){
						if(mapa[10][31] == OBJETO){
							if(mapa[px][py+1] == mapa[10][31]){ final = 1; }
						}
						if(py < LAR-1) {
						py++;
						}
			    	}
			    }
				// ESQUERDA
				else if(jogada == 68) {
					if( mapa[px][py-1] != PAREDE){
						if(mapa[10][8] == OBJETO){
							if(mapa[px][py-1] == mapa[10][8]){ final = 1; }
						}
						if(py > 1) {
							py--;
						}
					}
				}
			}
		}
		if(min < 0){
			gameover = 1;
			partida = 1;
			final = 2;
		}
	}

	//STATUS
	if(dificuldade == '1'){
		//GUERREIRO
		if(personagem == '1'){
			vh = 40;
			dh = 8;
			ehf = 60;
			tsf = 8;
		}
		
		//LADINO
		if(personagem == '2'){
			vh = 20;
			dh = 5;
			ehf = 70;
			tsf = 5;
		}
		
		vd = 30;
		vrd = 50;

		dd = 3;
		drd = 2;
		
		edf = 20;
		erdf = 30;
	}
	
	if(dificuldade == '2'){
		//GUERREIRO
		if(personagem == '1'){
			vh = 40;
			dh = 8;
			ehf = 50;
			tsf = 8;
		}
		
		//LADINO
		if(personagem == '2'){
			vh = 20;
			dh = 5;
			ehf = 60;
			tsf = 5;
		}
		
		vd = 30;
		vrd = 50;

		dd = 3;
		drd = 3;
	
		
		edf = 30;	
		erdf = 50;
	}
	
	if(dificuldade == '3'){
		//GUERREIRO
		if(personagem == '1'){
			vh = 40;
			dh = 8;
			ehf = 40;
			tsf = 8;
		}
		
		//LADINO
		if(personagem == '2'){
			vh = 20;
			dh = 5;
			ehf = 50;
			tsf = 5;
		}
		
		vd = 30;
		vrd = 50;
		
		dd = 3;
		drd = 4;
		
		edf = 40;	
		erdf = 60;
	}
	
	ae = 20;
	es = 1;
	
	turno = 1;
		
	if(personagem == 2){
		if(qd == 0){
			vh = 30;
			dh = 5;
			ehf = 60;
			//if(tentativa == 1){
			//	min = min + 5;
			//}
		}
	}
	
	//INICIO DO SISTEMA DE BATALHA
	while(final == 1){
	
		deg = 10 +(vh/2);
		del = 5;
		system("clear");

		//CRONOMETRO
		printf("\t%i:%i\n", min, sec);
		sec--;
		
		if(((min <= 0) && (sec <= 0)) || ((min < 0) && (sec > 0))){
			gameover = 1;
			partida = 1;
			final = 2;
		}
		
		if(sec == 0){
			sec = 59;
			min--;
		}
		
		if(min == 0){
			min = 0;
		}
		

		srand(time (NULL));

		eh = (rand()%100) +1;
		ed = (rand()%100) +1;
		erd = (rand()%100) +1;


		printf("\n LUTE ENQUANTO TEM TEMPO");
		
		printf("\n\n %i° turno", turno);
			turno = turno + 1;

		printf("\n\n\t VIDA   chance de ");
				printf("\n\t\t esquiva");
		if(qd != 0){ 
			printf("\n\n Demônio: %i \t  %i", vd, edf);
		}
		
		else{
			printf("\n\n Rei\n Demônio: %i \t  %i", vrd, erdf);
		}
			printf("\n\n   Herói: %i \t  %i", vh, ehf);
		
		if(personagem == '1'){
			printf("\n\n (Ataque normal = 1) Dano = 5\n (Ataque especial = 2)Dano = 10 + (vida do guerreiro /2)");
			if(es == 0){
				printf(", Cooldown = %i", tsf);
			}
			else{
				tsf = 8;
			}
		}
		if(personagem == '2'){
			printf("\n\n (Ataque normal = 1) Dano = 5\n (Ataque especial = 2)Dano = 5 e +20 esquiva ");
			if(es == 0){
				printf(", Cooldown = %i", tsf);
			}
			else{
				tsf = 5;
			}
		}
		printf("\n");
				
		// CAPTURA TECLA
		jogada = getch();
		
		//VERIFICA JOGADA INVALIDA		
		if(jogada != '1' && jogada != '2'){
			sec++;
			turno = turno - 1;
			printf("\n JOGADA INVALIDA !!!\n Aperte enter");
			
			__fpurge(stdin);
			getchar();
			system("clear");
		}
	
		if(jogada == '1'){
			if(qd != 0){
				if(ed >= edf){
					vd = vd - dh;
				}
			
				if(eh >= ehf){
					vh = vh - dd;
				}
				
				tsf = tsf - 1;
			}
			
			else{
				if(erd >= erdf){
					vrd = vrd - dh;
				}
			
				if(eh > ehf){
					vh = vh - drd;
				}
				
				tsf = tsf - 1;
			}
			
		}
		if(jogada == '2'){
			if(es == 0){
				sec++;
				turno = turno - 1;
				printf("\n JOGADA INVALIDA !!!\n Aperte enter");
				
				__fpurge(stdin);
				getchar();
				system("clear");
			}
		}	
		if(personagem == '1'){
			if(es == 1){
				if(qd != 0){	
					if(jogada == '2'){
						ehf = ehf + ae;
						de = turno;
						if(ed >= edf){
							vd = vd - deg;
						}
						if(eh >= ehf){
							vh = vh - dd;
						}
						es = 0;
						ts = turno;
					}
				}
				
				else{
					if(jogada == '2'){
						ehf = ehf + ae;
						de = turno;
						if(erd >= erdf){
							vrd = vrd - deg;
						}
						if(eh > ehf){
							vh = vh - drd;
						}
						es = 0;
						ts = turno;
					}
				}
			}
		}
		
		if(personagem == '2'){
			if(es == 1){
				if(qd != 0){	
					if(jogada == '2'){
						ehf = ehf + ae;
						de = turno;
						if(ed >= edf){
							vd = vd - del;
						}
						if(eh >= ehf){
							vh = vh - dd;
						}
						es = 0;
						ts = turno;
					}
				}
				
				else{
					if(jogada == '2'){
						ehf = ehf + ae;
						de = turno;
						if(erd >= erdf){
							vrd = vrd - del;
						}
						if(eh > ehf){
							vh = vh - drd;
						}
						es = 0;
						ts = turno;
					}
				}
			}
		}
		
		if(personagem == '1'){
			if(turno == (ts + 8)){
				es = 1;
			}	
		}
		
		if(personagem == '2'){
			if(turno == (ts + 5)){
				es = 1;
			}	
		}
		
		if(vd <= 0){
			for(lin=0; lin<alt; lin++) {
				for(col=0; col<lar; col++) {
					mapa[px][py] = CAMINHO;
				}
			}
			px = 10;
			py = 20;
			qd = qd - 1;
			final = 0;
		}
		
		if(vh <= 0){
			min = min - 1;
			final = 0;
			px = 10;
			py = 20;
			if(qd == 0){
				tentativa = 0;
			}
		}
		
		if(vrd <= 0){
			partida = 1;
			final = 2;
		}
			
		if(turno == (de + 3)){
			ehf = ehf - ae;
		}
	}
}

	system("clear");

	if(vrd <= 0){
		if(dificuldade == '1'){
			printf("\n LUTE ENQUANTO TEM TEMPO");
			
			printf("\n\n %i° turno", turno);
				turno = turno + 1;

			printf("\n\n\t VIDA   chance de ");
					printf("\n\t\t esquiva");
			
			printf("\n\n Rei\n Demônio: 0 \t  %i", erdf);
		
			printf("\n\n   Herói: %i \t  %i", vh, ehf);
		
			printf("\n\n Parabéns Herói você matou uma das formas do Jaime\n Jogue na dificuldade mediana para ver o final\n");
		}
		
		if(dificuldade == '2'){
			printf("\n LUTE ENQUANTO TEM TEMPO");
			
			printf("\n\n %i° turno", turno);
				turno = turno + 1;

			printf("\n\n\t VIDA   chance de ");
					printf("\n\t\t esquiva");
			
			printf("\n\n Rei\n Demônio: 0 \t  %i", erdf);
		
			printf("\n\n   Herói: %i \t  %i", vh, ehf);
		
			printf("\n\n Parabéns Herói você matou uma das formas do Jaime\n Jogue na dificuldade dificil para ver o final verdadeiro\n");
		}
		
		if(dificuldade == '3'){
			printf("\n LUTE ENQUANTO TEM TEMPO");
			
			printf("\n\n %i° turno", turno);
				turno = turno + 1;

			printf("\n\n\t VIDA   chance de ");
					printf("\n\t\t esquiva");
			
			printf("\n\n Rei\n Demônio: 0 \t  %i", erdf);
		
			printf("\n\n   Herói: %i \t  %i", vh, ehf);
		
			printf("\n\n Parabéns Herói você exterminou todas as formas do Jaime\n");
		}
	}

	if(gameover == 1){
		printf("\n LUTE ENQUANTO TEM TEMPO");
		
		printf("\n\n %i° turno", turno);
			turno = turno + 1;

		printf("\n\n\t VIDA   chance de ");
				printf("\n\t\t esquiva");
		
		printf("\n\n Rei\n Demônio: %i \t  %i", vrd, erdf);
	
		printf("\n\n   Herói: %i \t  %i", vh, ehf);
	
		printf("\n\n GAME OVER o tempo acabou \n Jaime teve sua vingança\n");
	}
	
	printf("\n Deseja jogar novamente (s) ou (n) ?\n");
	__fpurge;
	novamente = getchar();
	
}


	printf("\n");
	return 0;
}

int getch(void) {

    struct termios oldattr, newattr;
    int ch;

    tcgetattr( STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO);
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr);

    return ch;
}

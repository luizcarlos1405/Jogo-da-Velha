#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "gconio.h"

#define CIMA 65
#define DIREITA 67
#define BAIXO 66
#define ESQUERDA 68
#define ESCOLHER 10

void inicializacampo(char casas[3][3]){
    int i,
        j;
    for ( i = 0; i < 3 ; i++){
        for ( j = 0; j < 3 ; j++){
            casas[i][j]=' ';
        }
    }
}
/* Atribui o caractere ' ' a todos os elementos da matriz casas a fim de deixar
 *  o campo em branco quando for impresso, evitando imprimir lixo. Faz isso
 * percorrendo todos os valores com os laços for. */

void imprimecampo(char casas[3][3]){
    int i,
        j;
    system("cls || clear");
    printf("\t\t\t         ---------------\n\t\t\t          JOGO DA VELHA \n\t\t\t         ---------------\n\n");
    /* Imprime o título do joguinho na parte de cima. */
    for (i=0;i<3;i++){
        printf("\t\t\t\t      ");
        for (j=0;j<3;j++){
            if (j<2)
                printf("%c|",casas[i][j]);
                /* Imprime as duas primeiras colunas, pois elas não pulam linha.*/
            else if (i<2)
                printf("%c\n\t\t\t\t      -----\n",casas[i][j]);
                /* Imprime a última coluna das duas primeiras linhas, pois
                 * elas preciam pular linha e deixar o separador de linhas '-----'*/
            else
                printf("%c",casas[i][j]);
                /* Imprime o ultimo item da ultima linha sem os '-----' */
        }
    }
}
/* Imprime o campo com os valores que estiverem no vetor casas. a passagem é feita
 * por referência uma vez que o vetor é dado como argumento. Usa a mesma forma
 * que a função incializacampo para percorrer todos os valores. */

char comando(){
    char comando;
    comando = getch();
    return comando;
}
/* Função comando lê e retorna uma tecla pressionada. */

void jogadorx(char casas[3][3], int *ip, int *jp, int *fimdejogo){
    int  pare = 1 ;
    char old = casas[*ip][*jp];
         casas[*ip][*jp] = 'x';
    imprimecampo(casas);
    printf("\n\n\n Use os direcionais para mover e Enter para escolher o local.\n 'S' para sair.");
    while (pare){
        switch(comando()){
            case CIMA:
                if(*ip>0){
                    casas[*ip][*jp]=old;
                    /* Aqui os valores atuais de i e j retornam ao seu valor original, deixando seja lá o
                     * que estivesse naquela posição exatamente onde estava, sem modificar os valores
                     * do campo apenas por se mover por ele. */
                    *ip=*ip-1;
                    /* Aqui alteramos o valor, no caso de i, pois o movimento é na "vertical", é diminuido
                     * 1, nesse caso, em que se quer "andar" pra "cima". Descobri errando que não é possível
                     * usar incremento ou decremento x++/x-- para ponteiros (*ip--, não funciona) */
                    old=casas[*ip][*jp];
                    /* Salvamos o valor da casa logo acima da que se estava antes, para que possamos retornar
                     * o valor novamente, na próxima iteração. */
                    casas[*ip][*jp] = 'x';
                    /* E, finalmente, alteramos o valor, para poder visualizá-lo na hora de imprimir. */
                    imprimecampo(casas);
                    printf("\n\n\n Use os direcionais para mover e Enter para escolher o local.\n 'S' para sair.");
                    /* Pronto, aqui imprimimos o campo, usando o vetor casas, declarado na função 'partida',
                     * na função imprimecampo. */
                }
                /* A variável 'old' serve para guardar o valor antigo da 'casa' do 'campo' do Jogo da Velha.
                 * Por isso ela é iniciada com os valores atuais de i e j (passados por referência usando
                 * os ponteiros declarados na função 'partida'*/
            break;
            case ESQUERDA:
                if(*jp > 0){
                    casas[*ip][*jp] = old;
                    *jp = *jp-1;
                    old = casas[*ip][*jp];
                    casas[*ip][*jp] = 'x';
                    imprimecampo(casas);
                    printf("\n\n\n Use os direcionais para mover e Enter para escolher o local.\n 'S' para sair.");
                }
                /* Exatamente a mesma coisa é feita para os comandos ESQUERDA, DIREITA e BAIXO. */
            break;
            case BAIXO:
                if (*ip < 2){
                    casas[*ip][*jp] = old;
                    *ip = *ip+1;
                    old = casas[*ip][*jp];
                    casas[*ip][*jp] = 'x';
                    imprimecampo(casas);
                    printf("\n\n\n Use os direcionais para mover e Enter para escolher o local.\n 'S' para sair.");
                }
            break;
            case DIREITA:
                if (*jp < 2){
                    casas[*ip][*jp] = old;
                    *jp = *jp+1;
                    old = casas[*ip][*jp];
                    casas[*ip][*jp] = 'x';
                    imprimecampo(casas);
                    printf("\n\n\n Use os direcionais para mover e Enter para escolher o local.\n 'S' para sair.");
                }
            break;
            case ESCOLHER:
                if(old == ' '){
                    casas[*ip][*jp] = 'X';
                    pare = 0;
                    /* Perceba que o caractere que anda pelo campo é minúsculo, mas quando é escolhido o lugar
                     * o caractere deixado é maiúsculo, para facilitar a diferenciação entre o que se move e o
                     * que é fixo. */
                }
            break;
            case 's':
            case 'S':
				*fimdejogo = 0;
				pare = 0;
				/* Para dar a opção de sair a qualquer momento do programa, tendo ou não terminado
				 * a partida. Altera a variável 'continua' declarada na função 'partida' e encerra o laço
				 * que depende dessa variável. Não coicidentemente escolhi o mesmo nome
				 * para o ponteiro. */
            break;
        }
    }
}
/* Função jogadorx rege a jogada do jogadorx e define as mudançadas dos valores de
 * i, j e de um dos valores do vetor casas. Uitiliza ponteiros para passagem por
 * referência.  */

void jogadoro(char casas[3][3], int *ip, int *jp, int *fimdejogo){
    int pare = 1;
    char old = casas[*ip][*jp];
        casas[*ip][*jp] = 'o';
    imprimecampo(casas);
    printf("\n\n\n Use os direcionais para mover e Enter para escolher o local.\n 'S' para sair.");
    while (pare){
        switch(comando()){
            case CIMA:
                if(*ip > 0){
                    casas[*ip][*jp] = old;
                    *ip = *ip-1;
                    old = casas[*ip][*jp];
                    casas[*ip][*jp] = 'o';
                    imprimecampo(casas);
                    printf("\n\n\n Use os direcionais para mover e Enter para escolher o local.\n 'S' para sair.");
                }
            break;
            case ESQUERDA:
                if(*jp > 0){
                    casas[*ip][*jp] = old;
                    *jp = *jp-1;
                    old = casas[*ip][*jp];
                    casas[*ip][*jp] = 'o';
                    imprimecampo(casas);
                    printf("\n\n\n Use os direcionais para mover e Enter para escolher o local.\n 'S' para sair.");
                }
            break;
            case BAIXO:
                if (*ip < 2){
                    casas[*ip][*jp] = old;
                    *ip = *ip+1;
                    old = casas[*ip][*jp];
                    casas[*ip][*jp] = 'o';
                    imprimecampo(casas);
                    printf("\n\n\n Use os direcionais para mover e Enter para escolher o local.\n 'S' para sair.");
                }
            break;
            case DIREITA:
                if (*jp < 2){
                    casas[*ip][*jp] = old;
                    *jp = *jp+1;
                    old = casas[*ip][*jp];
                    casas[*ip][*jp] = 'o';
                    imprimecampo(casas);
                    printf("\n\n\n Use os direcionais para mover e Enter para escolher o local.\n 'S' para sair.");
                }
            break;
            case ESCOLHER:
                if(old == ' '){
                    casas[*ip][*jp] = 'O';
                    pare = 0;
                }
            break;
            case 's':
            case 'S':
				*fimdejogo = 0;
				pare = 0;
			break;
        }
    }
}
/* Função jogadoro rege a jogada do jogadoro e define as mudançadas dos valores de
 * i, j e de um dos valores de vetor casas. Exatamente a mesma coisa que a 'jogadorx',
 * mas usando os caracteres 'o' e 'O'  */

void ganhador(char casas[3][3], int *continua){
    if ((casas[0][0]==casas[0][1]&&casas[0][0]==casas[0][2]&&casas[0][0]=='X')||(casas[1][0]==casas[1][1]&&casas[1][0]==casas[1][2]&&casas[1][0]=='X')||(casas[2][0]==casas[2][1]&&casas[2][0]==casas[2][2]&&casas[2][0]=='X')||(casas[0][0]==casas[1][0]&&casas[0][0]==casas[2][0]&&casas[0][0]=='X')||(casas[0][1]==casas[1][1]&&casas[0][1]==casas[2][1]&&casas[0][1]=='X')||(casas[0][2]==casas[1][2]&&casas[0][2]==casas[2][2]&&casas[0][2]=='X')||(casas[0][0]==casas[1][1]&&casas[0][0]==casas[2][2]&&casas[0][0]=='X')||(casas[0][2]==casas[1][1]&&casas[0][2]==casas[2][0]&&casas[0][2]=='X')){
		system("cls || clear");
		printf("\t\t\t         ---------------\n\t\t\t          JOGO DA VELHA \n\t\t\t         ---------------\n\n");
		imprimecampo(casas);
        printf("\n\n\n\t\t\t\tJogador X venceu!");
        getch();
        *continua = 0;
    }
    /* Infelizmente não consegui ver outra forma de testar e identificar o ganhador senão com todas essas condições.
     * Ainda penso em alterar essa função. Não há muito o que explicar, o if e os else if's testam se alguma das
     * colunas, linhas ou diagonais estão todas preenchidas por 'X' ou por 'O' e então informa que este é o
     * vencedor, pede uma pausa e termina a função alterando o valor da variável 'continua' fazendo com que o
     * laço que define a partida na função 'partida' termine e o laço maior que depende da variável fimdejogo
     * se repita, reiniciando o campo e perguntando se o jogador deseja continuar ou encerrar. */
    else if ((casas[0][0]==casas[0][1]&&casas[0][0]==casas[0][2]&&casas[0][0]=='O')||(casas[1][0]==casas[1][1]&&casas[1][0]==casas[1][2]&&casas[1][0]=='O')||(casas[2][0]==casas[2][1]&&casas[2][0]==casas[2][2]&&casas[2][0]=='O')||(casas[0][0]==casas[1][0]&&casas[0][0]==casas[2][0]&&casas[0][0]=='O')||(casas[0][1]==casas[1][1]&&casas[0][1]==casas[2][1]&&casas[0][1]=='O')||(casas[0][2]==casas[1][2]&&casas[0][2]==casas[2][2]&&casas[0][2]=='O')||(casas[0][0]==casas[1][1]&&casas[0][0]==casas[2][2]&&casas[0][0]=='O')||(casas[0][2]==casas[1][1]&&casas[0][2]==casas[2][0]&&casas[0][2]=='O')){
		system("cls || clear");
		printf("\t\t\t         ---------------\n\t\t\t          JOGO DA VELHA \n\t\t\t         ---------------\n\n");
		imprimecampo(casas);
        printf("\n\n\n\t\t\t\tJogador O venceu!");
        getch();
        *continua = 0;
	}
    else if (casas[0][0]!=' '&&casas[0][1]!=' '&&casas[0][2]!=' '&&casas[1][0]!=' '&&casas[1][1]!=' '&&casas[1][2]!=' '&&casas[2][0]!=' '&&casas[2][1]!=' '&&casas[2][2]!=' '){
		system("cls || clear");
		printf("\t\t\t         ---------------\n\t\t\t          JOGO DA VELHA \n\t\t\t         ---------------\n\n");
		imprimecampo(casas);
        printf("\n\n\n\t\t\t\t   Deu velha!");
        getch();
        *continua = 0;
    }
}
/* Testa se há algum ganhador e altera '0' caso haja, na main isso altera o valor de 'ganhou'
 * alterando, por sua vez 'fimdejogo' que vai decidir se o jogo continua ou não */

int menuprincipal(){
	setlocale(LC_ALL,"Portuguese");
	int dentro = 1,
	/* Variável que definirá se o menu continua rodando no laço while abaixo.
	 * lembrando que dentro do laço 0 == falso e qualquer coisa != 0 é
	 * verdadeiro, simulando uma operação booleana. */
		i = 0;
	/* Variável que mudará com o toque das teclas para definir onde está a seta no menu. */
	char opcao[3];
	/* Vetor que definirá qual opção está sendo selecionada */
	opcao[0] = '>';
	opcao[1] = ' ';
	opcao[2] = ' ';
	/* Inicializa as opções para a forma padrão. */
	system("cls || clear");
	/* Limpa o que estiver escrito no terminal tanto para Windows (cls) quanto para Linux (clear). */
	printf("\t\t\t         ---------------\n\t\t\t          JOGO DA VELHA \n\t\t\t         ---------------\n\n");
	printf("\n%c Jogar\n%c Opcoes (em desenvolvimento)\n%c Sair", opcao[0], opcao[1], opcao[2]);
	/* Imprime o menu na posição inicial com a seta no 'Jogar' */
	while (dentro){
	    switch (comando()){
			case BAIXO:
				if (i < 2){
						opcao[0] = ' ';
						opcao[1] = ' ';
						opcao[2] = ' ';
						/* Resetando as possibilidades de seta */
						i++;
						opcao[i] = '>';
						/* "Movendo" a seta para baixo */
						system("cls || clear");
						printf("\t\t\t         ---------------\n\t\t\t          JOGO DA VELHA \n\t\t\t         ---------------\n\n");
						printf("\n%c Jogar\n%c Opcoes (em desenvolvimento)\n%c Sair", opcao[0], opcao[1], opcao[2]);
						/* Finalmente, imprime o menu como ele estiver. */
				}
			break;
			case CIMA:
				if (i > 0){
						opcao[0] = ' ';
						opcao[1] = ' ';
						opcao[2] = ' ';
						/* Resetando as possibilidades de seta */
						i--;
						opcao[i] = '>';
						/* "Movendo" a seta para cima */
						system("cls || clear");
						printf("\t\t\t         ---------------\n\t\t\t          JOGO DA VELHA \n\t\t\t         ---------------\n\n");
						printf("\n%c Jogar\n%c Opcoes (em desenvolvimento)\n%c Sair", opcao[0], opcao[1], opcao[2]);
						/* Finalmente, imprime o menu como ele estiver. */
				}
			break;
			case ESCOLHER:
				if (i != 1)
					dentro = 0;
				/* Sai do menu, retornando a opção desejada (0, 1 ou 2) */
			break;
		}
	}
	return i;
}
/* Apresenta um menu para que o jogador escolha o que fazer no início do programa
 * ou quando escolher voltar a ele. */

int menufimdejogo(char casas[3][3]){
	int dentro = 1,
	/* Variável que definirá se o menu continua rodando no laço while abaixo.
	 * lembrando que dentro do laço 0 == falso e qualquer coisa != 0 é
	 * verdadeiro, simulando uma operação booleana. */
		i = 1;
	/* Variável que mudará com o toque das teclas para definir onde está a seta no menu. */
	char opcao[3];
	/* Vetor que definirá qual opção está sendo selecionada */
	opcao[0] = ' ';
	opcao[1] = '>';
	system("cls || clear");
	imprimecampo(casas);
	printf("\n\n%c Jogar novamente\n%c Sair", opcao[1], opcao[0]);
	/* Imprime o menu em sua forma padrão, com a seta em 'Jogar Novamente'. */
	while (dentro){
		switch (comando()){
			case CIMA:
				if (i < 1){
					i++;
					opcao[0] = ' ';
					opcao[1] = ' ';
					opcao[i] = '>';
					system("cls || clear");
					imprimecampo(casas);
					printf("\n\n%c Jogar novamente\n%c Sair", opcao[1], opcao[0]);
				}
			break;
			case BAIXO:
				if (i > 0){
					i--;
					opcao[0] = ' ';
					opcao[1] = ' ';
					opcao[i] = '>';
					system("cls || clear");
					imprimecampo(casas);
					printf("\n\n%c Jogar novamente\n%c Sair", opcao[1], opcao[0]);
				}
			break;
			case ESCOLHER:
				dentro = 0;
			break;
		}
	}
	return i;
}
/* Apresenta um menu para que o jogador escolha o que fazer no caso do fim de uma partida.
 * Usa o vetor casas como argumento e retorna a opção (0 ou 1).
 * Usa o mesmo método da função menuprincipal */

void partida(){
	int i = 1,
		j = 1,
		fimdejogo = 1,
		continua = 1;
    char turno = 'x',
		 casas[3][3];
    while (fimdejogo){
		/* Laço maior que dura enquanto o programa estiver rodando só é temrminado
		 * quando é alterado o valor da variável fimdejogo na função 'menufimdejogo'
		 * retornando o jogador para o menu principal (vide 'main')  */
		inicializacampo(casas);
        continua = 1;
        while (continua){
			/* Laço "menor" que dura enquanto não houver ganhador ou até alguém
			 * apertar 'S/s' (o que altera o valor da variável 'continua' como visto
			 * nas funções das jogadas (jogadorx e jogadoro) */
			switch(turno){
			case 'x':
				jogadorx(casas, &i, &j, &continua);
				ganhador(casas, &continua);
				/* Testa se alguém venceu. */
				turno = 'o';
			break;
			case 'o':
				jogadoro(casas, &i, &j, &continua);
				ganhador(casas, &continua);
				turno = 'x';
			break;
			}
        }
        fimdejogo = menufimdejogo(casas);
    }
}
/* Laço para enquanto a partida durar. */

int main();

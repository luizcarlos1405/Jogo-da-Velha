<<<<<<< HEAD
/***********************************************************************************************
 * Programa Jogo-da-Velha M.I. 1.0 criado por Luiz Carlos L. G. de Oliveira                    *
 *                                                                                             *
 * Sinta-se livre para modificar e compartilhar caso queira. Desenvolvi este jogo para fins de *
 * prática apenas. Acabei me empolgando.                                                       *
 * luizcarlos1405@gmail.com                                                                    *
 *                                                                                             *
 ***********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void inicializacampo(char casas[3][3]);
/* Atribui o caractere ' ' a todos os elementos da matriz casas a fim de deixar
 *  o campo em branco quando for impresso, evitando imprimir lixo. Faz isso
 * percorrendo todos os valores com os laços for. */
void imprimecampo(char casas[3][3]);
/* Imprime o campo com os valores que estiverem no vetor casas. a passagem é feita
 * por referência uma vez que o vetor é dado como argumento. Usa a mesma forma
 * que a função incializacampo para percorrer todos os valores. */
char comando();
/* Função comando lê e retorna uma tecla pressionada. */
void jogadorx(char casas[3][3], int *ip, int *jp, int *fimdejogo);
/* Função jogadorx rege a jogada do jogadorx e define as mudançadas dos valores de 
 * i, j e de um dos valores do vetor casas. Uitiliza ponteiros para passagem por
 * referência.  */
void jogadoro(char casas[3][3], int *ip, int *jp, int *fimdejogo);
/* Função jogadoro rege a jogada do jogadoro e define as mudançadas dos valores de 
 * i, j e de um dos valores de vetor casas. Exatamente a mesma coisa que a 'jogadorx',
 * mas usando os caracteres 'o' e 'O'  */
void ganhador(char casas[3][3], int *continua);
/* Testa se há algum ganhador e altera '0' caso haja, na main isso altera o valor de 'ganhou'
 * alterando, por sua vez 'fimdejogo' que vai decidir se o jogo continua ou não */
int menuprincipal();
/* Apresenta um menu para que o jogador escolha o que fazer no início do programa
 * ou quando escolher voltar a ele. */
int menufimdejogo(char casas[3][3]);
/* Apresenta um menu para que o jogador escolha o que fazer no caso do fim de uma partida.
 * Usa o vetor casas como argumento e retorna a opção (0 ou 1).
 * Usa o mesmo método da função menuprincipal */
void partida();
/* Laço para enquanto a partida durar. */
int main(){
	/* A função 'main' acabou ficando bem mais simples do que eu esperava, que bom. */
	setlocale(LC_ALL,"Portuguese");
	/* Não funciona, não sei porque, mas não consigo usar acentos, já tentei por essa função
	 * em tudo quanto é canto, mas acabei deixando a palavra "opções" sem os caracteres da
	 * língua portuguesa mesmo. Só deixei essa função aqui pra, quiçá, mais tarde buscar uma
	 * solução. */
	int sair = 1;
    while (sair){
		switch (menuprincipal()){
			case 0:
				partida();
			break;
			case 2:
				sair = 0;
			break;
		}
	}
	system("cls||clear");
    return 42;
}
=======
/***********************************************************************************************
 * Programa Jogo-da-Velha M.I. 3.0 criado por Luiz Carlos L. G. de Oliveira                    *
 *                                                                                             *
 * Sinta-se livre para modificar e compartilhar caso queira. Desenvolvi este jogo para fins de *
 * prática apenas. Acabei me empolgando.                                                       *
 * luizcarlos1405@gmail.com                                                                    *
 *                                                                                             *
 ***********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void inicializacampo(char casas[3][3]);
/* Atribui o caractere ' ' a todos os elementos da matriz casas a fim de deixar
 *  o campo em branco quando for impresso, evitando imprimir lixo. Faz isso
 * percorrendo todos os valores com os laços for. */
void imprimecampo(char casas[3][3]);
/* Imprime o campo com os valores que estiverem no vetor casas. a passagem é feita
 * por referência uma vez que o vetor é dado como argumento. Usa a mesma forma
 * que a função incializacampo para percorrer todos os valores. */
char comando();
/* Função comando lê e retorna uma tecla pressionada. */
void jogadorx(char casas[3][3], int *ip, int *jp, int *fimdejogo);
/* Função jogadorx rege a jogada do jogadorx e define as mudançadas dos valores de 
 * i, j e de um dos valores do vetor casas. Uitiliza ponteiros para passagem por
 * referência.  */
void jogadoro(char casas[3][3], int *ip, int *jp, int *fimdejogo);
/* Função jogadoro rege a jogada do jogadoro e define as mudançadas dos valores de 
 * i, j e de um dos valores de vetor casas. Exatamente a mesma coisa que a 'jogadorx',
 * mas usando os caracteres 'o' e 'O'  */
void ganhador(char casas[3][3], int *continua);
/* Testa se há algum ganhador e altera '0' caso haja, na main isso altera o valor de 'ganhou'
 * alterando, por sua vez 'fimdejogo' que vai decidir se o jogo continua ou não */
int menuprincipal();
/* Apresenta um menu para que o jogador escolha o que fazer no início do programa
 * ou quando escolher voltar a ele. */
int menufimdejogo(char casas[3][3]);
/* Apresenta um menu para que o jogador escolha o que fazer no caso do fim de uma partida.
 * Usa o vetor casas como argumento e retorna a opção (0 ou 1).
 * Usa o mesmo método da função menuprincipal */
void partida();
/* Laço para enquanto a partida durar. */
int main(){
	/* A função 'main' acabou ficando bem mais simples do que eu esperava, que bom. */
	setlocale(LC_ALL,"Portuguese");
	/* Não funciona, não sei porque, mas não consigo usar acentos, já tentei por essa função
	 * em tudo quanto é canto, mas acabei deixando a palavra "opções" sem os caracteres da
	 * língua portuguesa mesmo. Só deixei essa função aqui pra, quiçá, mais tarde buscar uma
	 * solução. */
	int sair = 1;
    while (sair){
		switch (menuprincipal()){
			case 0:
				partida();
			break;
			case 2:
				sair = 0;
			break;
		}
	}
	system("cls||clear");
    return 42;
}
>>>>>>> 4e70902fd9b4aab42e3b11d523c6b3d144034c33

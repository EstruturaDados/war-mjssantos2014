/* ====================================================================
 * Estrutura de Dados
 * PRATICA: JOGO WAR - DESAFIO NIVEL NOVATO v1.0
 *
 * OBJETIVO: Implementar um jogo de guerra WAR para cadastrar 5 territorios,
 *           cor de cada territorio e numero de tropas.
 *
 * ====================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TERRITORIO 5
#define MAX_COR 10
#define TAM_STRING 30

typedef struct
{
	char nomeTerritorio[TAM_STRING];
	char corTerritorio[MAX_COR];
	int numeroTropas;
} Territorio;


// --- função para limpar o Buffer de entrada ---
void limpabufferentrada()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
		;
}


int main()
{
	Territorio territorio[5];

	printf("================================================\n");
	printf("WAR ESTRUTURADO - CADSATRO INICIAL\n");
	printf("================================================\n");

	printf("Vamos cadastrar os 5 Territoris iniciais do nosso mundo.\n\n");

	for (int i = 0; i < MAX_TERRITORIO; i++)
	{
		printf("--- Cadastrando territorio %d ---\n", i + 1);

		printf("Nome do Territorio: ");
		fgets(territorio[i].nomeTerritorio, TAM_STRING, stdin);
		territorio[i].nomeTerritorio[strcspn(territorio[i].nomeTerritorio, "\n")] = '\0';

		printf("cor do Exercito (ex: Azul, Verde, Amarelo): ");
		fgets(territorio[i].corTerritorio, MAX_COR, stdin);
		territorio[i].corTerritorio[strcspn(territorio[i].corTerritorio, "\n")] = '\0';

		printf("Numero de tropas: ");
		scanf("%d", &territorio[i].numeroTropas);
		// territorio[i].numeroTropas[strcspn(territorio[i].numeroTropas, "\n")] = '\0';
		
		limpabufferentrada();
	}

	printf("================================================\n");
	printf("MAPA DO MUNDO - ESTADO ATUAL\n");
	printf("================================================\n");

	for (int i = 0; i < MAX_TERRITORIO; i++)
	{

		printf("\nTERRITORIO - %d", i + 1);

		printf("\t\n- Nome: %s", territorio[i].nomeTerritorio);
		printf("\t\n- Dominado por: Exercito %s", territorio[i].corTerritorio);
		printf("\t\n- Tropas: %d", territorio[i].numeroTropas);
		printf("\n\n");
	}

	getchar();

	return 0;
}

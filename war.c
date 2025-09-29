/* ====================================================================
 * Estrutura de Dados
 * PRATICA: JOGO WAR - DESAFIO NIVEL NOVATO
 *
 * OBJETIVO: Implementar um jogo de guerra WAR para cadastrar 5 territorios,
 *           cor de cada territorio e numero de tropas.
 *
 * ====================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// --- constantes globais ---
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


// --- CADSATRO DE TERRITORIOS ---



// --- EXIBIR TERRITORIOS ---


// --- FUNÇÃO COMBATE ---


// --- FUNÇÃO PRINCIPAL ---

int main()
{
	srand((unsigned)time(NULL));

	// 1. ALOCAÇÃO DINAMICA DE MEMORIA
	
	Territorio *territorio;
	territorio = (Territorio *)calloc(MAX_TERRITORIO, sizeof(Territorio));

	if (territorio == NULL)
	{
		printf("Erro de alocacao de memoria!\n");
		exit(1);
	}


    // --- colar aqui CADASTRAR TERRITORIO ---
	//FUNÇÃO CADASTRAR TERRITORIOS

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
		
		limpabufferentrada();
    }
		
    // --- FIM CADASTRAR TERRITORIO ---
	
	
	// --- colar aqui EXIBIR TERRITORIO ---
	
	// FUNÇÃO EXIBIR TERRITORIOS

    printf("================================================\n");
	printf("MAPA DO MUNDO - ESTADO ATUAL\n");
	printf("================================================\n");

	for (int i = 0; i < MAX_TERRITORIO; i++)
	{

		printf("%d. ", i + 1);

		printf("%s", territorio[i].nomeTerritorio);
		printf(" (Exercito %s, ", territorio[i].corTerritorio);
		printf("Tropas: %d)", territorio[i].numeroTropas);
		printf("\n");

	}

	getchar();
	
	// --- FIM aqui EXIBIR TERRITORIO ---
	
	
   // --- colar aqui FUNÇÃO COMBATE ---
	// FUNÇÃO ATAQUE

    int atacante, defensor;

    do
    {
        printf("--- FASE DE ATAQUE ---\n");
        printf("Simulando um ataque entre dois territorios...\n");
        printf("Escolha o territorio atacante(1 a 5,[-1 para sair]): ");
        scanf("%d", &atacante);

        switch (atacante)
        {
        //--- começa aqui ---
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            printf("Escolha o territorio defensor(1 a 5): ");
            scanf("%d", &defensor);
            limpabufferentrada();

            atacante -= 1; // ajustar para indice do vetor
            defensor -= 1; // ajustar para indice do vetor

            while (defensor == atacante)
            {
                defensor = rand() % MAX_TERRITORIO;
            }
            printf("O territorio %s (Exercito %s) esta atacando o territorio %s (Exercito %s)\n",
                   territorio[atacante].nomeTerritorio, territorio[atacante].corTerritorio,
                   territorio[defensor].nomeTerritorio, territorio[defensor].corTerritorio);
            printf("Pressione <ENTER> para continuar...\n");
            getchar();

            printf("Simulando o resultado do combate...\n");
            int dadoAtacante, dadoDefensor;
            dadoAtacante = rand() % 6 + 1;
            dadoDefensor = rand() % 6 + 1;
            printf("Dado do Atacante: %d\n", dadoAtacante);
            printf("Dado do Defensor: %d\n", dadoDefensor);
            if (dadoAtacante > dadoDefensor)
            {
                printf("O Atacante venceu o combate!\n");
                territorio[defensor].numeroTropas -= 1;
                if (territorio[defensor].numeroTropas < 0)
                    territorio[defensor].numeroTropas = 0;
            }
            else
            {
                printf("O Defensor venceu o combate!\n");
                territorio[atacante].numeroTropas -= 1;
                if (territorio[atacante].numeroTropas < 0)
                    territorio[atacante].numeroTropas = 0;
            }
            printf("Pressione <ENTER> para continuar...\n");
            getchar();

            for (int i = 0; i < MAX_TERRITORIO; i++)
            {

                printf("%d. ", i + 1);

                printf("%s", territorio[i].nomeTerritorio);
                printf(" (Exercito %s, ", territorio[i].corTerritorio);
                printf("Tropas: %d)", territorio[i].numeroTropas);
                printf("\n");
            }
            break;
        case -1:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }

    } while (atacante != -1);
	
	// --- FIM aqui FUNÇÃO COMBATE ---
	

	// 2. LIBERAR A MEMORIA ALOCADA
	free(territorio);

	return 0;
}

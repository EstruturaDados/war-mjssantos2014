#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// --- constantes globais ---
#define MAX_LIVROS 50
#define TAM_STRING 100

// --- definiçao da estrutura ---
typedef struct
{
	char nome[TAM_STRING];
	char autor[TAM_STRING];
	char editora[TAM_STRING];
	int edicao;
} Livro;

// --- função para limpar o Buffer de entrada ---
void limpabufferentrada()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
		;
}

// --- função principal main ---

int main()
{
	Livro biblioteca[MAX_LIVROS];
	int totalLivros = 0;
	int opcao;

	// --- laço principal do menu ---
	do
	{
		// --- exibe o Menu de opções ---
		printf("==========================================\n");
		printf("          BIBLIOTECA PARTE 1 \n");
		printf("==========================================\n");
		printf("1 - Cadastrar novo livro\n");
		printf("2 - Listar todos os  livros\n");
		printf("0 - sair\n");
		printf("------------------------------------------\n");
		printf("Escolha uma opcao: ");

		// Lê a opçao do usuario
		scanf("%d", &opcao);

		limpabufferentrada(); // limpa o \n deixado pelo scanf

		switch (opcao)
		{
		case 1: 
			printf("--- Cadastro de novo livro ---\n\n");

			if (totalLivros < MAX_LIVROS)
			{
				printf("Digite o nome do livro: ");
				fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);

				printf("Digite o autor: ");
				fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);

				printf("Digite a editora: ");
				fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);

				biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0';
				biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';
				biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0';

				printf("Digite a edicao: ");
				scanf("%d", &biblioteca[totalLivros].edicao);

				limpabufferentrada();

				totalLivros++;

				printf("\nLivro cadastrado com sucesso!\n");
			}
			else
			{
				printf("Biblioteca cheia, nao eh possivel cadastrar mais livros!\n");
			}

			printf("Precione uma tecla para continuar...\n");
			getchar();
			break;

		case 2: 
			printf("--- Lista de livros cadastrados ---\n\n");

			if (totalLivros == 0)
			{
				printf("Nenhum livro cadastrado ainda!\n");
			}
			else
			{
				for (int i = 0; i < totalLivros; i++)
				{
					printf("--------------------------\n");
					printf("LIVRO: %d\n", i + 1);
					printf("Nome: %s\n", biblioteca[i].nome);
					printf("Nome: %s\n", biblioteca[i].autor);
					printf("Nome: %s\n", biblioteca[i].editora);
					printf("Nome: %s\n", biblioteca[i].edicao);
				}

				printf("--------------------------\n");
			}

			printf("Precione uma tecla para continuar...\n");
			getchar();
			break;

		case 0: 
			printf("saindo do sistema...\n");
			break;

		default: 
			printf("\nopcao invalida! Tente novamente.\n");
			printf("Precione uma tecla para continuar...\n");
			getchar();
			break;
		}

	} while (opcao != 0);

	return 0;
}

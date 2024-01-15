#include <stdio.h> //bibl. de comunicaçao com o usuario
#include <stdlib.h> //alocaçao de memoria para o programa
#include <locale.h> //idioma de acordo com a regiao]
#include <string.h> //biblioteca que cuida do string


int registro()
{
	setlocale(LC_ALL, "Portuguese"); // 
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];

	printf("Digite o CPF a ser cadastrado:  ");
	scanf("%s", cpf); // o %s salva a variavel na string
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das strings (copia o cpf pro arquivo)
	
	FILE *file; // FILE é uma funçao; usar para procurar um arquivo "file"
	file = fopen(arquivo, "w"); // w = write >> escrever um novo arquivo (q ja tem o nome do CPF)
	fprintf(file, cpf); // salva o valor da variavel
	fclose(file); // fechar o arquivo
	
	file = fopen(arquivo, "a"); // "a" atualiza uma informaçao no arquivo
	fprintf(file, ","); // coloca virgula entre as variaveis armazenadas
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:  ");
	scanf("%s", nome);
	
	file = fopen (arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // "a" atualiza uma informaçao no arquivo
	fprintf(file, ","); // coloca virgula entre as variaveis armazenadas
	fclose(file);

	printf("Digite o sobrenome a ser cadastrado:  ");
	scanf("%s", sobrenome);
	
	file = fopen (arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // "a" atualiza uma informaçao no arquivo
	fprintf(file, ","); // coloca virgula entre as variaveis armazenadas
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:  ");
	scanf("%s", cargo);
	
	file = fopen (arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a"); // "a" atualiza uma informaçao no arquivo
	fprintf(file, "."); // coloca virgula entre as variaveis armazenadas
	fclose(file);
	

	system("pause");
}

int consulta() 
{
	setlocale(LC_ALL, "Portuguese"); // definindo as linguagens

	char cpf[40];
	char conteudo[200];
	char *token;
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");

	
	if(file == NULL)
	{ 
		printf ("CPF nao localizado... Tente novamente! \n ");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL); //lasso -> buscar ate 200 vezes, parar quando for nulo
	{
		printf("\n Essas sao as informaçoes do usuário: ");
		
		token = strtok(conteudo, ","); // usado para dividir os dados em linhas != na hora de imprimir na tela
		printf("CPF: %s\n", token); //info que aparecerá antes do dado CPF
		
		token = strtok(NULL, ",");
		printf("Nome: %s\n", token); //info que aparecerá antes do dado nome
		
		token = strtok(NULL, ",");
		printf("Sobrenome: %s\n", token); //info que aparecerá antes do dado nome
		
		token = strtok(NULL, ",");
		printf("Cargo: %s\n", token); //info que aparecerá antes do dado sobrenome
		
	}

	printf("\n");
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: \n");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	
	
	printf("\n\t Usuário deletado com sucesso! \n");
	
	system("pause");
	
	if(file == NULL)
	{ 
		printf("O usuário nao se encontra no sistema. \n\n");
		system("pause");
	}
		
	
}


int main()
{
	int opcao=0; // definindo as variáveis
	
	int laco=1;
	
	for(laco=1;laco=1;) //retornar automaticamente ao menu
	{
	
		system("cls"); // respondavel por "limpar" a tela do app
		
	
		setlocale(LC_ALL, "Portuguese"); // definindo as linguagens
	
		printf("\n\t### Catálogo de alunos da EBAC ###\n\n"); // inicio do menu
		printf("\t\t O que deseja fazer?\n\n");
		printf("\t 1 - Cadastrar aluno \n");
		printf("\t 2 - Consultar aluno \n");
		printf("\t 3 - Excluir aluno \n"); 
		printf("\t\n Opção: "); // fim do menu

		scanf("%d", &opcao); // armazenando a escolha do usuario
	
		system("cls");
		
		switch(opcao) 
		{
		
			case 1: 
			registro();
			system("pause");
			break;
			
			case 2: 
			consulta();
			system("pause");
			break;
			
			case 3: 
			deletar();
			system("pause");
			break;
			
		
			default:
			printf("\n\t Sinto muito! Essa opção não está disponível :( \n");
			system("pause");
			break;
		}	
	}	
		
}

	

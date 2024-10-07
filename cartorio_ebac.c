#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //Biblioteca de aloca��o de texto por regi�o
#include <string.h> //Biblioteca responsavel pelas strings

int registro() //Fun��o responsavel por cadastrar usu�rios no sistema
{
	//Inicio da cria��o de variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da cria��o de variaveis
	
	printf("Informe o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsqavel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //O "w" indica a cria��o e escrita de uma nova nota
	fprintf(file, cpf); //Salva o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Seleciona e abre um arquivo existente para escrever
	fprintf(file, ","); //Escreve uma virgula na nota
	fclose(file); //Fecha o arquivo
	
	printf("Informe o Nome a ser cadastrado: "); //Coleta de informa��es do usu�rio
	scanf("%s", nome); //Salva os dados coletados em uma string usando parametro "%s"
	
	file = fopen(arquivo, "a"); //Abre o arquivo em mode de escrita
	fprintf(file, nome); //Salva dados(neste caso o nome) no arquivo
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo em modo de escrita
	fprintf(file, ","); //Escreve uma virgula
	fclose(file); //Fecha o arquivo
	
	printf("Informe o Sobrenome a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s", sobrenome); //Salva os dados coletados em uma string usando parametro "%s"
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file, sobrenome); //Salva dados(neste caso o sobrenome) no arquivo
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo em modo de escrita
	fprintf(file, ","); //Escreve uma virgula
	fclose(file); //Fecha o arquivo
	
	printf("Informe o Cargo a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s", cargo); //Salva os dados coletados em uma string usando parametro "%s"
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file, cargo); //Salva dados(neste caso o cargo) no arquivo
	fclose(file); //Fecha o arquivo
	
	system("pause"); //Pausa o programa 
}

int consulta() //Fun��o responsavel por consultar os usuarios do sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
	//Inicio da cria��o de variaveis
	char cpf[40];
	char conteudo[200];
	//Fim da cria��o de variaveis
	
	printf("Digite o CPF a ser consultado: "); //Coletando dados do usu�rio
	scanf("%s", cpf); //Salva os dados coletados em uma string usando parametro "%s"
	
	FILE *file; //Acessa o local do arquivo
	file = fopen(cpf, "r"); //Abre o arquivo
	
	//Teste de verifica��o pra saber se orquivo existe ou n�o
	if(file == NULL)
	{
		printf("Arquivo n�o localizado no sistema. Tente Novamente...\n"); //Caso n�o exista, Retorna para o usu�rio: 
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Caso exista, copia todo conteudo que esta no arquivo e joga dentro da variavel
	{
		printf("Informa��es do Usu�rio: ");
		printf("%s", conteudo); //Exibe todo conteudo do arquivo para o usu�rio
		printf("\n\n");
	}
	
	system("pause"); //Pausa o programa
	fclose(file); //Fecha o arquivo aberto
}

int deletar() //Fun��o responsavel por deletar usu�rios do sistema
{
	char cpf[40]; //Cria��o de variaveis
	
	printf("Informe o CPF a ser deletado: "); //Pedindo cpf para usuario
	scanf("%s", cpf); //Armazenando cpf
	
	FILE *file; //Abrindo local do banco de dados
	file = fopen(cpf, "r"); //Abrindo arquivo para leitura
	fclose(file); //Fechando arquivo
	
	if(file == NULL) //Se o arquivo for igual a null ou nada
	{
		printf("O usu�rio n�o se encontra no sistema! \n"); //Informe ao usu�rio que:
		system("pause"); //Pausa programa
	}
	else //Se n�o ou Caso contr�rio
	{
		remove(cpf); //Deleta o cpf informado
		printf("Usu�rio deletado com sucesso! \n"); //retorne ao usu�rio que:
		system("pause");
	}
}

int main() //Fun��o principal, menu
{
	int opcao = 0; //Definindo Vari�vel
	int laco = 1;
	
	for(laco = 1; laco = 1;) //La�o responsavel pelo loop do menu
	{
		system("cls"); //Limpa a tela do programa
	
		setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
		
		printf("Copyright � 2024 de Douglas Lima\n\n\n\n");
		
		printf("\t---Cart�rio da EBAC---\n\n"); //Inicio do Menu
		printf("Escolha uma das seguintes op��es: \n\n");
		printf("\t[1] - Registrar Nomes\n");
		printf("\t[2] - Consultar Nomes\n");
		printf("\t[3] - Deletar Nomes\n");
		printf("\t[4] - Sair do Sistema\n");
		printf("Op��o: "); //Fim do Menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
		
		system("cls");
		
		switch(opcao) //Inicio da Sele��o
		{
			case 1:
				registro(); //chama a fun��o de registro
			break;
			
			case 2:
				consulta(); //chama a fun��o de consulta
			break;
			
			case 3:
				deletar(); //chama a fun��o de deletar
			break;
			
			case 4:
				printf("Obrigado por utilizar o sistema!");
				return 0;
			break;
			
			default: //Caso o usuario selecione alguma op��o invalida, retorna:
				printf("Op��o invalida! Tente Novamente...\n");
				system("pause");
			break;
		} //Fim da Sele��o
	}
}

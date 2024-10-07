#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço de memória
#include <locale.h> //Biblioteca de alocação de texto por região
#include <string.h> //Biblioteca responsavel pelas strings

int registro() //Função responsavel por cadastrar usuários no sistema
{
	//Inicio da criação de variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da criação de variaveis
	
	printf("Informe o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsqavel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //O "w" indica a criação e escrita de uma nova nota
	fprintf(file, cpf); //Salva o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Seleciona e abre um arquivo existente para escrever
	fprintf(file, ","); //Escreve uma virgula na nota
	fclose(file); //Fecha o arquivo
	
	printf("Informe o Nome a ser cadastrado: "); //Coleta de informações do usuário
	scanf("%s", nome); //Salva os dados coletados em uma string usando parametro "%s"
	
	file = fopen(arquivo, "a"); //Abre o arquivo em mode de escrita
	fprintf(file, nome); //Salva dados(neste caso o nome) no arquivo
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo em modo de escrita
	fprintf(file, ","); //Escreve uma virgula
	fclose(file); //Fecha o arquivo
	
	printf("Informe o Sobrenome a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s", sobrenome); //Salva os dados coletados em uma string usando parametro "%s"
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file, sobrenome); //Salva dados(neste caso o sobrenome) no arquivo
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo em modo de escrita
	fprintf(file, ","); //Escreve uma virgula
	fclose(file); //Fecha o arquivo
	
	printf("Informe o Cargo a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s", cargo); //Salva os dados coletados em uma string usando parametro "%s"
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file, cargo); //Salva dados(neste caso o cargo) no arquivo
	fclose(file); //Fecha o arquivo
	
	system("pause"); //Pausa o programa 
}

int consulta() //Função responsavel por consultar os usuarios do sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
	//Inicio da criação de variaveis
	char cpf[40];
	char conteudo[200];
	//Fim da criação de variaveis
	
	printf("Digite o CPF a ser consultado: "); //Coletando dados do usuário
	scanf("%s", cpf); //Salva os dados coletados em uma string usando parametro "%s"
	
	FILE *file; //Acessa o local do arquivo
	file = fopen(cpf, "r"); //Abre o arquivo
	
	//Teste de verificação pra saber se orquivo existe ou não
	if(file == NULL)
	{
		printf("Arquivo não localizado no sistema. Tente Novamente...\n"); //Caso não exista, Retorna para o usuário: 
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Caso exista, copia todo conteudo que esta no arquivo e joga dentro da variavel
	{
		printf("Informações do Usuário: ");
		printf("%s", conteudo); //Exibe todo conteudo do arquivo para o usuário
		printf("\n\n");
	}
	
	system("pause"); //Pausa o programa
	fclose(file); //Fecha o arquivo aberto
}

int deletar() //Função responsavel por deletar usuários do sistema
{
	char cpf[40]; //Criação de variaveis
	
	printf("Informe o CPF a ser deletado: "); //Pedindo cpf para usuario
	scanf("%s", cpf); //Armazenando cpf
	
	FILE *file; //Abrindo local do banco de dados
	file = fopen(cpf, "r"); //Abrindo arquivo para leitura
	fclose(file); //Fechando arquivo
	
	if(file == NULL) //Se o arquivo for igual a null ou nada
	{
		printf("O usuário não se encontra no sistema! \n"); //Informe ao usuário que:
		system("pause"); //Pausa programa
	}
	else //Se não ou Caso contrário
	{
		remove(cpf); //Deleta o cpf informado
		printf("Usuário deletado com sucesso! \n"); //retorne ao usuário que:
		system("pause");
	}
}

int main() //Função principal, menu
{
	int opcao = 0; //Definindo Variável
	int laco = 1;
	
	for(laco = 1; laco = 1;) //Laço responsavel pelo loop do menu
	{
		system("cls"); //Limpa a tela do programa
	
		setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
		
		printf("Copyright © 2024 de Douglas Lima\n\n\n\n");
		
		printf("\t---Cartório da EBAC---\n\n"); //Inicio do Menu
		printf("Escolha uma das seguintes opções: \n\n");
		printf("\t[1] - Registrar Nomes\n");
		printf("\t[2] - Consultar Nomes\n");
		printf("\t[3] - Deletar Nomes\n");
		printf("\t[4] - Sair do Sistema\n");
		printf("Opção: "); //Fim do Menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usuário
		
		system("cls");
		
		switch(opcao) //Inicio da Seleção
		{
			case 1:
				registro(); //chama a função de registro
			break;
			
			case 2:
				consulta(); //chama a função de consulta
			break;
			
			case 3:
				deletar(); //chama a função de deletar
			break;
			
			case 4:
				printf("Obrigado por utilizar o sistema!");
				return 0;
			break;
			
			default: //Caso o usuario selecione alguma opção invalida, retorna:
				printf("Opção invalida! Tente Novamente...\n");
				system("pause");
			break;
		} //Fim da Seleção
	}
}

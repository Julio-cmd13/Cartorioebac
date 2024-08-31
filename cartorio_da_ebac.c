#include <stdio.h> // biblioteca de comunica��o com o usuario
#include <stdlib.h> // biblioteca de aloca��o de espa�o em memoria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca responsavel por cuidar das string

int registro() // fun��o responsavel por cadastrar os usu�rios no sistema
{
	// inicio da cria��o de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o de variaveis
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s",cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); // Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // abrindo arquivo
	fprintf(file,"CPF:"); // salvo o valor da variavel
	fclose(file); // fecha o aqruivo
	
	file = fopen(arquivo, "a"); 
	fprintf(file,cpf); 
	fclose(file); 
	
	file = fopen(arquivo, "a");
	fprintf(file,",\t");
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Nome:");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome),
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",\t");
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Sobrenome:");
	fclose(file);
	
    printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome),
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",\t");
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Cargo:");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser encontrado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
	    printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}

	
}


int main()


{
	int opcao=0; // Definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls"); // responsavel por limpar a tela
		
	    setlocale(LC_ALL, "portuguese"); // Definindo linguagem
	
	    printf("### Cart�rio da EBAC ###\n\n"); // Inicio do menu
	    printf("Escolha a op��o desejada no menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("Op��o:"); // Fim do menu
	
	    scanf("%d", &opcao); // Armazenando a escolha do usu�rio
	
	    system("cls");
	    
	    
	    switch(opcao) // inicio de sele��o do menu 
	    {
	    	case 1:
	    	registro(); // chamada de fun��es
		    break;
			
			case 2:	
			consulta();
		    break;
		    
		    case 3:
		    deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� disponivel!\n");
		    system("pause");
		    break;
				
		} // fim da sele��o
		
	}
}
	


	
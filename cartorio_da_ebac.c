#include <stdio.h> // biblioteca de comunicação com o usuario
#include <stdlib.h> // biblioteca de alocação de espaço em memoria
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsavel por cuidar das string

int registro() // função responsavel por cadastrar os usuários no sistema
{
	// inicio da criação de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação de variaveis
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informação do usuário
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
	    printf("Não foi possivel abrir o arquivo, não localizado!.\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}

	
}


int main()
{
	int opcao=0; // Definindo variaveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	setlocale(LC_ALL, "portuguese");
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada,"admin");
	
	if(comparacao == 0)
	{
		system("cls");
		
	    for(laco=1;laco=1;)
		{  
		
		  system("cls"); // responsavel por limpar a tela
		
	      setlocale(LC_ALL, "portuguese"); // Definindo linguagem
	
	      printf("### Cartório da EBAC ###\n\n"); // Inicio do menu
	      printf("Escolha a opção desejada no menu:\n\n");
	      printf("\t1 - Registrar nomes\n");
	      printf("\t2 - Consultar nomes\n");
	      printf("\t3 - Deletar nomes\n\n");
	      printf("\t4 - Sair do sistema\n\n");
	      printf("Opção:"); // Fim do menu
	
	      scanf("%d", &opcao); // Armazenando a escolha do usuário
	
	      system("cls");
	    
	    
	       switch(opcao) // inicio de seleção do menu 
	        {
	    	 case 1:
	    	 registro(); // chamada de funções
		     break;
			
			 case 2:	
			 consulta();
		     break;
		    
		     case 3:
		     deletar();
			 break;
			
			 case 4:
			 printf("Obrigado por utilizar o sistema!\n");
			 return 0;	
			 break;
			
			
			 default:
			 printf("Essa opção não está disponivel!\n");
		     system("pause");
		     break;
		     
			
		     }
		
		} 
		
	}

	else

	    printf("Senha incorreta!");

}


	


	

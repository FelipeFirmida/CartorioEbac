#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável pelas strings

// Fiz um "function prototype" para que o código ficasse mais legível e o "main" ficasse mais próximo do início do código.

int registro(); // Função para registrar usuário (line 65)
int consulta(); // Função para consultar usuário no banco de dados (line 124)
int deletar(); // Função para deletar usuário do banco de dados (line 153)

// App responsável por Registrar, consultar e deletar nomes ("CRUD")
int main()
{
    // Definindo variáveis
    int opcao = 0; 
    int laco = 1;

    for(laco = 1; laco = 1;)
    {

        setlocale(LC_ALL, "Portuguese"); // Definindo linguagem

        system("cls"); // responsável por limpar a tela

        // Menu de escolha de opções
        printf("### Cartório da EBAC ###\n\n"); // inicio do menu
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registrar nomes \n");
        printf("\t2 - Consultar nomes \n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Opção: "); // Fim do menu

        scanf("%d", &opcao); // Armazenando a escolha do usuário

        system("cls");

        // Inicio da seleção
        switch(opcao)
        {
            // Registrar nomes
            case 1:
            registro();
            break;
            
            // Consultar nomes
            case 2:
            consulta();
            break;

            // Deletar nomes
            case 3:
            deletar();
            break;

            // Sair do sistema:
            case 4:
            printf("Obrigado por utilizar o sistema!\n");
            return 0;
            break;


            // Evitar inputs inválidos
            default:
            printf("Essa opção não está disponível.\n");
            system("pause");
            break;
        }   // Fim da seleção    
    }
}

int registro() // Função para registrar usuário
{
    // inicio da criação de variáveis/string
    char arquivo [40];
    char cpf[40];
    char nome[40];
    char sobrenome [40];
    char cargo[40];
    // final da criação de variáveis

    printf("Digite o CPF a ser cadastrado: "); // coletando cpf do usuário
    scanf("%s", cpf); // %s refere-se a strings

    strcpy(arquivo, cpf); // Copia os valores das strings

    FILE *file; // cria o arquivo
    file = fopen(arquivo, "w"); // w = write file
    fprintf(file, cpf); // salva a variável cpf
    fclose(file); // fecha o arquivo

    file = fopen(arquivo, "a"); // append file
    fprintf(file, ","); // adicionar vírgula para separar infos
    fclose(file);

    // Adicionar nome
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    file = fopen(arquivo, "a"); // append file
    fprintf(file, ","); // adicionar vírgula para separar infos
    fclose(file);

    // Adicionar sobrenome
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a"); // append file
    fprintf(file, ","); // adicionar vírgula para separar infos
    fclose(file);

    // Adicionar cargo
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    system("pause");
}

int consulta() // Função para consultar usuário no banco de dados
{
    setlocale(LC_ALL, "Portuguese"); // Definindo linguagem
    
    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r"); // read file
    
    if(file == NULL)
    {
        printf("Não foi possível abrir o arquivo, não localizado!.\n");
    }
    
    
    while(fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas são as informações do usuários: ");
        printf("%s", conteudo);
        printf("\n\n");
        
        system("pause");
    }
}

int deletar() // Função para deletar usuário do banco de dados
{
    char cpf[40];
    // CPF é a chave principal e única, o nome do arquivo de cada usuário.
    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);

    remove(cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if(file == NULL)
    {
        printf("O usuário não se encontra no sistema!\n");
        system("pause");
    }
}

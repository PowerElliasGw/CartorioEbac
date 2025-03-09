#include <stdio.h>  
#include <stdlib.h> 
#include <locale.h> 
#include <string.h> 
#include <ctype.h> // Para verificar se � d�gito

void registro() {
    setlocale(LC_ALL, "Portuguese");
    
    char arquivo[40];  
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    fflush(stdin);
    scanf("%39s", cpf);

    strcpy(arquivo, cpf); 

    FILE *file = fopen(arquivo, "w"); 
    if (file == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return;
    }
    
    fprintf(file, "%s,", cpf); 
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    fflush(stdin);
    scanf("%39s", nome);

    file = fopen(arquivo, "a");  
    if (file != NULL) {
        fprintf(file, "%s,", nome);
        fclose(file);
    }

    printf("Digite o sobrenome a ser cadastrado: ");
    fflush(stdin);
    scanf("%39s", sobrenome);

    file = fopen(arquivo, "a");
    if (file != NULL) {
        fprintf(file, "%s,", sobrenome);
        fclose(file);
    }

    printf("Digite o cargo a ser cadastrado: ");
    fflush(stdin);
    scanf("%39s", cargo);

    file = fopen(arquivo, "a");
    if (file != NULL) {
        fprintf(file, "%s\n", cargo);
        fclose(file);
    }

    printf("Registro salvo com sucesso!\n");
    system("pause");
}

void consulta() {
    setlocale(LC_ALL, "Portuguese");
    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    fflush(stdin);
    scanf("%39s", cpf);

    FILE *file = fopen(cpf, "r");
    if (file == NULL) {
        printf("N�o foi poss�vel abrir o arquivo. O CPF n�o foi encontrado!\n");
        system("pause");
        return;
    }

    printf("\nEssas s�o as informa��es do usu�rio:\n");
    while (fgets(conteudo, 200, file) != NULL) {
        printf("%s", conteudo);
    }
    printf("\n\n");

    fclose(file);
    system("pause");
}

void deletar() {
    char cpf[40];
    printf("Digite o CPF a ser deletado: ");
    fflush(stdin);
    scanf("%39s", cpf);

    if (remove(cpf) == 0) {
        printf("Registro removido com sucesso!\n");
    } else {
        printf("Erro ao remover o arquivo. CPF n�o encontrado!\n");
    }
    system("pause");
}

int main() {
    setlocale(LC_ALL, "Portuguese");  

    char opcao[10]; // Armazenar a op��o como string

    while (1) {  
        system("cls");

        printf("### Cart�rio da EBAC ###\n\n");
        printf("Escolha a op��o desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair\n\n");
        printf("Op��o: ");

        fflush(stdin);
        scanf("%9s", opcao);

        // Verificar se a op��o � um n�mero de 1 a 4
        if (strlen(opcao) == 1 && isdigit(opcao[0])) {
            int escolha = opcao[0] - '0'; // Converte para inteiro

            system("cls");

            switch (escolha) {
                case 1:
                    registro(); 
                    break;
                case 2:
                    consulta();
                    break;
                case 3:
                    deletar();
                    break;
                case 4:
                    printf("Saindo do programa...\n");
                    return 0;
                default:
                    printf("Essa op��o n�o est� dispon�vel!\n");
                    system("pause");
                    break;
            }
        } else {
            printf("Essa op��o n�o est� dispon�vel!\n");
            system("pause");
        }
    }
}


#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //função responsavel por cadastrar os usuarios no sistema
{
    //inicio da criação de variaveis / string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação de variaveis / string

    printf("Digite o CPF a ser cadastrado:\n "); //coletando informações dos usuarios
    scanf("%s", cpf); //%s refere-se a string

    strcpy(arquivo, cpf); //responsavel por copiar os valores dos string

    FILE *file; // cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o "W" significa ESCREVER
    fprintf(file, "\nCPF:");
    fprintf(file,cpf); // salva o valor da variavel
    fclose(file); // fecha o arquivo


        file = fopen(arquivo, "a"); //pedindo para abrir o arquivo e "a" significa ATUALIZAR
        fprintf(file, ".\nNOME:");
        fclose(file);


    printf("Digite o nome a ser cadastrado:\n");
    scanf("%s", nome);

        file =fopen(arquivo, "a");
        fprintf(file,nome);
        fclose(file);

        file = fopen(arquivo, "a");
        fprintf(file, ".\nSOBRENOME:");
        fclose(file);

    printf("Digite o sobrenome a ser cadastrado:\n");
    scanf("%s", sobrenome);

        file =fopen(arquivo, "a");
        fprintf(file,sobrenome);
        fclose(file);

        file =fopen(arquivo, "a");
        fprintf(file, ".\nCARGO:");
        fclose(file);

    printf("Digite o cargo a ser cadastrado:\n");
    scanf("%s", cargo);

        file =fopen(arquivo, "a");
        fprintf(file,cargo);
        fprintf(file, ".\n");
        fclose(file);



    getchar();

}
int consultar()
{
    setlocale (LC_ALL,"Portuguese"); //Definindo a linguagem

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado:\n");
    scanf("%s",cpf);
    getchar();

    FILE *file;
    file = fopen(cpf, "r");


    if(file == NULL)

    {
        printf("\n\nNão foi possivel localizar este CPF!\n\n");

    }


    while(fgets(conteudo, 200, file) !=NULL)
    {
        printf("\nEssas são as informações do usuário:\n");
        printf("%s", conteudo);

    }


    printf("\n\nPressione Enter para continuar...");
    getchar();


}
int deletar()
{

    char cpf[40];

    printf("Digite o CPF do usuário a ser deletado:\n");
    scanf("%s", cpf);

    remove(cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if(file == NULL)
    {
        printf("\nO usuário nao se encontra no sistema!\n\n\n");
        getchar();
    }


    printf("Pressione Enter para continuar...");
    getchar();
}




int main()
{
    int opcao=0; //Definindo variaveis
    int laco=1; // Definindo variável laco

    for(laco=1;laco==1;)
    {


        system("clear");

        setlocale (LC_ALL,"Portuguese"); //Definindo a linguagem

        printf ("\n\n");
        printf ("\tCartório da EBAC\n\n"); //Inicio do menu
        printf ("Escolha a opção desejada do menu:\n\n");
        printf ("\t1 - Registrar nome\n");
        printf ("\t------------------\n");
        printf ("\t2 - Consultar nome\n");
        printf ("\t------------------\n");
        printf ("\t3 - Deletar nome\n");
        printf ("\t------------------\n");
        printf ("\t4 - Sair do sistrema\n");
        printf ("\t------------------\n\n\n");
        printf ("Opção:"); //Fim do menu

        scanf("%d", &opcao); // Lendo a resposta do usúario e armazenando na váriavel opcao

        system("clear"); // responsavel por limpar a tela, (clear) é usado em MAC.


        switch(opcao)
        {
            case 1:
            registro(); //chamada de funções
            break;

            case 2:
            consultar();
            break;

            case 3:
            deletar();
            break;

            case 4:
            printf("Obrigado por acessar o sistema!\n\n");
            return 0;
            break;

            default:
            printf("Esta opção não esta disponivel!");
            printf("Pressione Enter para continuar...\n\n");
            getchar();
            break;


        }



    }

}

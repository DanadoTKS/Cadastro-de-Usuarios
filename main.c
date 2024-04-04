#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_USUARIOS 100
#define TAMANHO_SENHA 12

// Estrutura para usuario
typedef struct
{
    char nome[50];
    char sobrenome[50];
    char email[100];
    char contato[15];
    char senha[TAMANHO_SENHA + 1];
} Usuario;

// Funcao para criacao de senha segura
void gerarSenha(char senha[], int tamanho)
{
    const char caracteres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$^%&*()";
    int i;

    srand(time(NULL));

    for (i = 0; i < tamanho; i++)
    {
        senha[i] = caracteres[rand() % strlen(caracteres)];
    }

    senha[tamanho] = '\0';
}

// Funcao para listar usuarios cadastrados
void listarUsuarios(Usuario usuarios[], int numUsuarios)
{
    int i;

    printf("Usuarios cadastrados: \n");
    for (i = 0; i < numUsuarios; i++)
    {
        printf("Nome: %s %s\n", usuarios[i].nome, usuarios[i].sobrenome);
        printf("Email: %s\n", usuarios[i].email);
        printf("Telefone: %s\n", usuarios[i].contato);
        printf("\n");
    }
}

// Editar laguma informacao
void editarUsuario(Usuario usuarios[], int numUsuarios)
{
    int indice, opcao;

    printf("Digite o numero do usuario que deseja editar: ");
    scanf("%d", &indice);

    if (indice >= 1 && indice <= numUsuarios)
    {

        printf("Digite o nome: ");
        scanf("%s", usuarios[indice - 1].nome);
        printf("Digite o sobrenome: ");
        scanf("%s", usuarios[indice - 1].sobrenome);
        printf("Digite o email: ");
        scanf("%s", usuarios[indice - 1].email);
        printf("Digite o numero de contato: ");
        scanf("%s", usuarios[indice - 1].contato);

        printf("Usuario editado com sucesso");
    }
    else
    {
        printf("Usuario nao encontrado...");
    }
}

// Excleui alguma informacao, email ou contato...
void excluirInformacaoUsuario(Usuario usuarios[], int numUsuarios)
{
    int indice, opcao;

    listarUsuarios(usuarios, numUsuarios);

    printf("Digite o numero do usuario que deseja editar: ");
    scanf("%d", &indice);

    if (indice >= 1 && indice <= numUsuarios)
    {
        printf("Informacoes do usuarios: \n");
        printf("Nome: %s %s\n", usuarios[indice - 1].nome, usuarios[indice - 1].sobrenome);
        printf("Email: %s\n", usuarios[indice - 1].email);
        printf("Telefone: %s\n", usuarios[indice - 1].contato);

        printf("Digite a opcao que deseja excluir: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            strcpy(usuarios[indice - 1].email, "");
            break;

        case 2:
            strcpy(usuarios[indice - 1].contato, "");
            break;

        default:
            printf("Opcao invalida.\n");
            break;
        }

        printf("Informacao excluida com sucesso!");
    }
    else
    {
        printf("Usuario nao encontrado");
    }
}

void gerarNovaSenha(Usuario usuarios[], int numUsuarios)
{
    int indice;

    listarUsuarios(usuarios, numUsuarios);

    printf("Digite o numero do usuarios que deseja gerar uma nova senha: ");
    scanf("%d", &indice);

    if (indice >= 1 && indice <= numUsuarios)
    {
        gerarSenha(usuarios[indice - 1].senha, TAMANHO_SENHA);
        printf("Nova senha gerada com sucesso: %s\n", usuarios[indice - 1].senha);
    }
    else
    {
        printf("Usuario nao encontrado.\n");
    }
}

int main()
{

    Usuario usuarios[MAX_USUARIOS];
    int numUsuarios = 0;
    int opcao;

    do
    {
        printf("\n");
        printf("Menu\n");
        printf("=====================\n");
        printf("1. Cadastrar usuario\n");
        printf("2. Listar usuarios cadastrados\n");
        printf("3. Editar usuario\n");
        printf("4. Excluir informacao\n");
        printf("5. Gerar Nova senha\n");
        printf("6. Sair\n");
        printf("=====================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {
        case 1:
            if (numUsuarios < MAX_USUARIOS)
            {
                printf("Digite o nome: ");
                scanf("%s", usuarios[numUsuarios].nome);
                printf("Digite o sobrenome: ");
                scanf("%s", usuarios[numUsuarios].sobrenome);
                printf("Digite o email: ");
                scanf("%s", usuarios[numUsuarios].email);
                printf("Digite o numero de contato: ");
                scanf("%s", usuarios[numUsuarios].contato);

                gerarSenha(usuarios[numUsuarios].senha, TAMANHO_SENHA);
                printf("Usuario cadastrado com sucesso!\n");
                printf("Senha gerada: %s\n", usuarios[numUsuarios].senha);

                numUsuarios++;
            }
            else
            {
                printf("Limite de usuarios cadastrados atigindos\n");
            }
            break;

        case 2:
            listarUsuarios(usuarios, numUsuarios);
            break;

        case 3:
            editarUsuario(usuarios, numUsuarios);
            break;

        case 4:
            excluirInformacaoUsuario(usuarios, numUsuarios);
            break;

        case 5:
            gerarNovaSenha(usuarios, numUsuarios);
            break;

        case 6:
            printf("Saindo...");
            break;

        default:
            printf("Opcao Invalida. Tente novamente.\n");
            break;
        }
    } while (opcao != 6);

    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>//biblioteca para localiza��o em PT-BR
#include<string.h>
#include<Windows.h>//biblioteca da fun��o Sleep

FILE *Id_Arquivo_Candidatos;
FILE *Id_Arquivo_Eleitores;

struct Candidato{
    int numero_candidato;  //codigo do candidato
    char nome[50]; //informa�oes pessoais
    char sexo[15];
    int idade;
    int flag;// variavel para exclus�o l�gica
};

struct Eleitor{
    int titulo_eleitor; //codigo do eleitor
    char nome[50];  //informa��es pessoais
    char sexo[15];
    int idade;
    int intencao_de_voto; //rela��o com o candidato
    int flag;// variavel para exclus�o l�gica
};

//CRUD Candidato

//Cria��o
void adicionar_candidato(struct Candidato candidato){

    if((Id_Arquivo_Candidatos = fopen("candidatos.dat", "a+b")) == NULL){
        printf("Erro ao abrir arquivo bin�rio dos candidatos para grava��o!\n");
    }

    candidato.flag = 1;

    fwrite(&candidato, sizeof(struct Candidato), 1, Id_Arquivo_Candidatos);

    fclose(Id_Arquivo_Candidatos);
}

//Leitura
void exibir_candidatos(){

    if((Id_Arquivo_Candidatos = fopen("candidatos.dat", "r")) == NULL){
        printf("Erro ao abrir arquivo bin�rio dos candidatos para leitura!\n");
    }

    rewind(Id_Arquivo_Candidatos);

    struct Candidato candidato;

    while(!feof(Id_Arquivo_Candidatos)){
        fread(&candidato, sizeof(struct Candidato), 1, Id_Arquivo_Candidatos);

        if(ferror(Id_Arquivo_Candidatos)){
            printf("Problema na leitura do arquivo bin�rio!\n");
        }
        else if(!feof(Id_Arquivo_Candidatos) && candidato.flag == 1){
            printf("\nNumero do candidato: %d\n", candidato.numero_candidato);
            printf("Nome: %s\n", candidato.nome);
            printf("Sexo: %s\n", candidato.sexo);
            printf("Idade: %d\n", candidato.idade);
        }

    }
    fclose(Id_Arquivo_Candidatos);

}

//Atualiza��o
void atualizar_candidato(struct Candidato candidatoAtualizado){
    if((Id_Arquivo_Candidatos = fopen("candidatos.dat", "r+b")) == NULL){
        printf("Erro ao abrir arquivo bin�rio dos eleitores!\n");
    }

    rewind(Id_Arquivo_Candidatos);

    struct Candidato candidato;


    int i;
    printf("Atualizando");// anima��o de atualiza��o
    for(i = 0; i < 3; i++){
        printf(".");
        Sleep(500); // usa a biblioteca Windows.h
    }

    int cont = 0;

    while(!feof(Id_Arquivo_Candidatos)){
        fread(&candidato, sizeof(struct Candidato), 1, Id_Arquivo_Candidatos);

        if(ferror(Id_Arquivo_Candidatos)){
            printf("\nErro na leitura do arquivo!\n");
        }
        else if((!feof(Id_Arquivo_Candidatos)) && (candidato.numero_candidato == candidatoAtualizado.numero_candidato) && (candidato.flag == 1)){

            fseek(Id_Arquivo_Candidatos, sizeof(struct Candidato)*cont, SEEK_SET);

            candidatoAtualizado.flag = 1;

            fwrite(&candidatoAtualizado, sizeof(struct Candidato), 1, Id_Arquivo_Candidatos);

            fseek(Id_Arquivo_Candidatos, 0, SEEK_END);
        }
        cont++;
    }
    printf("\nCandidato Atualizado!\n");
    fclose(Id_Arquivo_Candidatos);
}

//Exclus�o
void excluir_candidato(int numero_candidato){
    if((Id_Arquivo_Candidatos = fopen("candidatos.dat", "r+b")) == NULL){
        printf("Erro ao abrir arquivo bin�rio dos eleitores!\n");
    }

    struct Candidato candidato;

    rewind(Id_Arquivo_Candidatos);

    int cont = 0;

    int i;
    printf("Procurando");// anima��o de procura
    for(i = 0; i < 3; i++){
        printf(".");
        Sleep(500); // usa a biblioteca Windows.h
    }

    while(!feof(Id_Arquivo_Candidatos)){

        fread(&candidato, sizeof(struct Candidato), 1, Id_Arquivo_Candidatos);

        if(ferror(Id_Arquivo_Candidatos)){
            printf("Erro na leitura do arquivo!\n");
        }else if(!feof(Id_Arquivo_Candidatos) && candidato.flag == 1 && candidato.numero_candidato == numero_candidato){
            candidato.flag = 0;

            fseek(Id_Arquivo_Candidatos, sizeof(struct Candidato) * cont, SEEK_SET);

            fwrite(&candidato, sizeof(struct Candidato), 1, Id_Arquivo_Candidatos);

            fseek(Id_Arquivo_Candidatos, 0, SEEK_END);

            printf("\nCandidato excluido!\n");

            break;
        }
        else if(feof(Id_Arquivo_Candidatos)){
            printf("\nCandidato n�o encontrado!\n");
        }
        cont++;
    }

    fclose(Id_Arquivo_Candidatos);
}

void adicionar_eleitor(struct Eleitor eleitor){

    if((Id_Arquivo_Eleitores = fopen("eleitor.dat", "a+b")) == NULL){
        printf("Erro ao abrir arquivo bin�rio dos eleitores para grava��o!");
    }

    eleitor.flag = 1;

    fwrite(&eleitor, sizeof(struct Eleitor), 1, Id_Arquivo_Eleitores);

    fclose(Id_Arquivo_Eleitores);

}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int opc;
    struct Candidato candidato;
    struct Eleitor eleitor;

    do{//Menu Geral de Candidato e Eleitor
        system("cls");
        printf("0- Sair\n");
        printf("1- Candidato\n");
        printf("2- Eleitor\n");
        scanf("%d", &opc);
        switch(opc){
            case 0:

                break;
            case 1://Menu Candidato
                system("cls");
                printf("0- Voltar\n");
                printf("1- Adicionar Candidato\n");
                printf("2- Exibir Candidatos\n");
                printf("3- Atualizar Candidato\n");
                printf("4- Excluir Candidato\n");
                scanf("%d", &opc );
                switch(opc){
                    case 0:
                        opc = 1;
                        break;
                    case 1:
                        system("cls");
                        fflush(stdin);
                        printf("**Cadastro do Candidato**\n");

                        printf("Digite numero de identifica��o do candidato: ");
                        scanf("%d", &candidato.numero_candidato);
                        fflush(stdin);

                        printf("Digite o nome do candidato: ");
                        fgets(candidato.nome, 50, stdin);
                        candidato.nome[strlen(candidato.nome) - 1] = '\0';
                        fflush(stdin);

                        printf("Digite o sexo do candidato: ");
                        fgets(candidato.sexo, 50, stdin);
                        candidato.sexo[strlen(candidato.sexo) - 1] = '\0';
                        fflush(stdin);

                        printf("Digite a idade do candidato: ");
                        scanf("%d", &candidato.idade);
                        fflush(stdin);

                        adicionar_candidato(candidato);
                        break;
                    case 2:
                        system("cls");
                        exibir_candidatos();
                        system("pause");
                        break;
                    case 3:
                        printf("**Atualiza��o do candidato**\n");

                        printf("Digite numero de identifica��o do candidato a ser alterado: ");
                        scanf("%d", &candidato.numero_candidato);
                        fflush(stdin);

                        printf("Digite o nome do candidato: ");
                        fgets(candidato.nome, 50, stdin);
                        candidato.nome[strlen(candidato.nome) - 1] = '\0';
                        fflush(stdin);

                        printf("Digite o sexo do candidato: ");
                        fgets(candidato.sexo, 50, stdin);
                        candidato.sexo[strlen(candidato.sexo) - 1] = '\0';
                        fflush(stdin);

                        printf("Digite a idade do candidato: ");
                        scanf("%d", &candidato.idade);
                        fflush(stdin);

                        system("cls");
                        atualizar_candidato(candidato);
                        system("pause");
                        break;
                    case 4:
                        system("cls");
                        int numero_candidato;
                        printf("Digite o n�mero do candidato: ");
                        scanf("%d", &numero_candidato);

                        excluir_candidato(numero_candidato);
                        system("pause");
                        break;
                    default:
                        system("cls");
                        printf("Op��o inv�lida!\n\a");
                        system("pause");
                        break;
                }
                break;
            case 2://Menu Eleitor
                system("cls");
                printf("0- Sair\n");
                printf("1- Adicionar eleitor\n");
                printf("2- Exibir eleitor\n");
                printf("3- Atualizar eleitor\n");
                printf("4- Excluir eleitor\n");
                scanf("%d", &opc );

                switch(opc){
                    case 0:
                        break;
                    case 1:
                        system("cls");
                        fflush(stdin);
                        printf("Cadastro do Eleitor\n");

                        printf("Digite o Titulo de eleitor: \n");
                        scanf("%d", &eleitor.titulo_eleitor);
                        fflush(stdin);

                        printf("Digite o nome do eleitor: \n");
                        fgets(eleitor.nome, 50, stdin);
                        eleitor.nome[strlen(eleitor.nome) - 1] = '\0';
                        fflush(stdin);

                        printf("Digite o sexo do candidato: \n");
                        fgets(eleitor.sexo, 50, stdin);
                        eleitor.sexo[strlen(eleitor.sexo) - 1] = '\0';
                        fflush(stdin);

                        printf("Digite a idade: \n");
                        scanf("%d", &eleitor.idade);
                        fflush(stdin);

                        printf("Digite a inten��o de voto do eleitor:\n");
                        scanf("%d", &eleitor.intencao_de_voto);
                        fflush(stdin);

                        adicionar_eleitor(eleitor);
                        break;
                    case 2:
                      //  exibir_eleitor();
                        break;
                    case 3:
                       // atualizar_eleitor();
                        break;
                    case 4:
                       // excluir_eleitor();
                        break;
                    default:
                        system("cls");
                        printf("Op��o inv�lida!\n\a");
                        system("pause");
                        break;
                }
                break;
            default:
                printf("Op��o inv�lida!\n\a");
                system("pause");
                break;

        }



    }while(opc != 0);

    return 0;
}

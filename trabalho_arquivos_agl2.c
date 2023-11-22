#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
FILE *Id_Arquivo;

struct Candidato{
    int numero_candidato;  //codigo do candidato
    char nome[50]; //informaçoes pessoais
    char sexo[15];
    int idade;
    int flag;
};

struct Eleitor{
    int titulor_eleitor; //codigo do eleitor
    char nome[50];  //informações pessoais
    char sexo[15];
    int idade;
    int intencao_de_voto; //relação com o candidato
    int flag;
};

int main(){
    setlocale(LC_ALL, "Portuguese");
    int opc;
    do{
        system("cls");
        printf("0- Sair\n");
        printf("1- Candidato\n");
        printf("2- Eleitor\n");
        scanf("%d", &opc);
        switch(opc){
            case 1:
                system("cls");
                printf("0- Sair\n");
                printf("1- Adicionar Candidato\n");
                printf("2- Exibir Candidatos\n");
                printf("3- Atualizar Candidato\n");
                printf("4- Excluir Candidato\n");
                scanf("%d", &opc );
                switch(opc){
                    case 0:
                        break;
                    case 1:
                        //adicionar_candidato();
                        break;
                    case 2:
                      //  exibir_candidatos();
                        break;
                    case 3:
                       // atualizar_candidato();
                        break;
                    case 4:
                       // excluir_candidato();
                        break;
                    default:
                        system("cls");
                        printf("Opção inválida!\n\a");
                        system("pause");
                        break;
                }
                break;
            case 2:
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
                        //adicionar_eleitor();
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
                        printf("Opção inválida!\n\a");
                        system("pause");
                        break;
                }
                break;
                default:
                    printf("Opção inválida!\n\a");
                    system("pause");
                    break;



        }



    }while(opc != 0);






    return 0;
}

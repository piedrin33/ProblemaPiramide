#include "Piramide.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define debug FALSE



int main()
{
    TPiramide piramide;
    TabelaSomas tabela;
    int Nlinhas,opcao,carregado = FALSE;
    clock_t Ticks[2];
    FILE *fp = fopen("Tempo.txt","a");

    while(TRUE){
        system("clear");
        printf("=======================================================\n");
        printf("|                    Voce deseja :                    |\n");
        printf("|-----------------------------------------------------|\n");
        printf("|                                                     |\n");
        printf("| 1 - Inserir uma nova piramide.                      |\n");
        printf("|                                                     |\n");
        printf("| 2 - Resolucao atraves da PD.                        |\n");
        printf("|                                                     |\n");
        printf("| 3 - Resolucao atraves da forca bruta.               |\n");
        printf("|                                                     |\n");
        printf("| Pressione 0 para encerrar o programa...             |\n");
        printf("=======================================================\n");
        printf("-> Opcao: ");
        scanf("%d",&opcao);
        switch(opcao){
            case 0:
                system("clear");
                fclose(fp);
                printf("==PROGRAMA ENCERRADO==\n");
                exit(EXIT_SUCCESS);

            case 1:
                system("clear");
                if(carregado == TRUE){
                    printf("Voce ja carregou nenhuma piramide, utilize-a para inserir outra !!\n\n");
                    printf("Pressione enter para continuar ...");
                    getchar();
                    getchar();
                    break;
                }
                piramide = recebe_piramide(&Nlinhas);
                tabela = recebe_tabela(piramide,Nlinhas);
                carregado = TRUE;
                break;

            case 2:
                if(carregado == TRUE){

                    #if(debug == TRUE)
                        Ticks[0] = clock();
                    #endif

                    system("clear");
                    printf("A maior soma eh: %d\n",tabela[0][0]);
                    printf("->CAMINHO PERCORRIDO: ");
                    imprime_caminho(piramide,tabela,0,0,Nlinhas);

                    #if(debug == TRUE)
                        Ticks[1] = clock();
                        fprintf(fp,"Pirâmide de tamanho %d Programação Dinâmica -> Tempo Total %lf\n",Nlinhas,(double)(Ticks[1]-Ticks[0])/CLOCKS_PER_SEC);
                    #endif

                    carregado = FALSE;
                    free(tabela);
                    free(piramide);
                    printf("\n\nPressione enter para continuar...");
                    getchar();
                    getchar();
                    break;
                }else{
                    system("clear");
                    printf("Voce nao carregou nenhuma piramide !!\n");
                    printf("Pressione enter para continuar ...");
                    getchar();
                    getchar();
                    break;
                }
            case 3:
                if(carregado == TRUE){

                    #if(debug == TRUE)
                        Ticks[0] = clock();
                    #endif

                    system("clear");
                    printf("A maior soma eh: %d\n",Max(piramide,0,0,Nlinhas));
                    printf("->CAMINHO PERCORRIDO: ");
                    imprime_caminho(piramide,tabela,0,0,Nlinhas);

                    #if(debug == TRUE)
                        Ticks[1] = clock();
                        fprintf(fp,"Pirâmide de tamanho %d Força Bruta -> Tempo Total %lf\n",Nlinhas,(double)(Ticks[1]-Ticks[0])/CLOCKS_PER_SEC);
                    #endif

                    carregado = FALSE;
                    free(tabela);
                    free(piramide);
                    printf("\n\nPressione enter para continuar...");
                    getchar();
                    getchar();
                    break;
                }else{
                    system("clear");
                    printf("Voce nao carregou nenhuma piramide !!\n");
                    printf("Pressione enter para continuar ...");
                    getchar();
                    getchar();
                    break;
                }

            default:
                system("clear");
                printf("Opcao invalida !!!");
                printf("\n\nPressione enter para continuar...");
                getchar();
                getchar();
                break;
        }
    }
    return 0;
}

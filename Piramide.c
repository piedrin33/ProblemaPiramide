#include "Piramide.h"
#include <stdio.h>
#include <stdlib.h>

TPiramide recebe_piramide(int *Nlinhas){

    TPiramide piramide;
    int i,j;
    FILE *fp = NULL;
    char nomeArquivo[50],c;

    do{
        system("clear");
        printf("DIGITE O NOME DO ARQUIVO: ");
        scanf(" %[^\n]",nomeArquivo);
        fp = fopen(nomeArquivo,"r");
        if(fp == NULL){
            system("clear");
            perror("===ERRO AO ABRIR O ARQUIVO===\n");
            printf("\nPressione enter para continuar...");
            getchar();
            getchar();
        }else{
            system("clear");
            printf("Piramide inserida com sucesso !!\n\n");
            printf("Pressione enter para continuar...");
            getchar();
            getchar();
        }
    }while(fp == NULL);
    /*Contando a quantidade de linhas da pirâmide*/
    (*Nlinhas) = 0;
    while((c = fgetc(fp)) != EOF){
        if(c == '\n')
            (*Nlinhas)++;
    }
    fclose(fp);
    /*Alocando linhas da pirâmide*/
    piramide = (TPiramide) malloc ((*Nlinhas) * sizeof(int *));
    if (piramide == NULL) {
        perror("\n*ERRO: Memoria Insuficiente, execute o programa novamente\n");
        exit(EXIT_FAILURE);
    }
    /*Alocando colunas da pirâmide*/
    for (i=0;i<(*Nlinhas);i++) {
        piramide[i] = (int *) malloc((i+1) * sizeof(int));
        if (piramide[i] == NULL) {
            perror("\n*ERRO: Memoria Insuficiente, execute o programa novamente\n");
            exit(EXIT_FAILURE);
        }
    }
    /*Lendo os dados da pirâmide*/
    fp = fopen(nomeArquivo,"r");
    for(i=0;i<(*Nlinhas);i++){
        for(j=0;j<i+1;j++)
            fscanf(fp,"%d",&piramide[i][j]);
    }
    return piramide;

}

TabelaSomas recebe_tabela(TPiramide piramide, int Nlinhas){

    int i,j,maior;
    TabelaSomas tabela;


    /*Alocando colunas da pirâmide*/
    tabela = (TabelaSomas) malloc (Nlinhas * sizeof(int *));
    if (tabela == NULL) {
        perror("\n*ERRO: Memoria Insuficiente, execute o programa novamente\n");
        exit(EXIT_FAILURE);
    }
    /*Alocando colunas da pirâmide*/
    for (i=0;i<Nlinhas;i++) {
        tabela[i] = (int *) malloc((i+1) * sizeof(int));
        if (tabela[i] == NULL) {
            perror("\n*ERRO: Memoria Insuficiente, execute o programa novamente\n");
            exit(EXIT_FAILURE);
        }
    }
    /*Aplicando somas da pirâmide na tabela*/
    for(i=(Nlinhas-1);i>=0;i--){
        for(j=0;j<i+1;j++){
            if(i == (Nlinhas-1)){//se estiver na base
                tabela[i][j] = piramide[i][j];
            }else{
                maior = tabela[i+1][j];
                if(maior < tabela[i+1][j+1])
                    maior = tabela[i+1][j+1];
            }
                tabela[i][j] = maior + piramide[i][j];
        }
    }
    return tabela;
}

void imprime_caminho(TPiramide piramide, TabelaSomas tabela, int i, int j, int Nlinhas){

    if(i == Nlinhas)
        return;

    if(i == 0 && j == 0){//topo
        printf("[%d] ",piramide[i][j]);
        imprime_caminho(piramide,tabela,i+1,j,Nlinhas);
    }else if(tabela[i][j] < tabela[i][j+1]){//filho a direita > filho a esquerda
        printf("[%d] ",piramide[i][j+1]);
        imprime_caminho(piramide,tabela,i+1,j+1,Nlinhas);
    }else{//filho a direita < filho a esquerda
        printf("[%d] ",piramide[i][j]);
        imprime_caminho(piramide,tabela,i+1,j,Nlinhas);
    }
}

int Max(TPiramide piramide, int i, int j, int Nlinhas){

    int a,b;

    if(i == Nlinhas-1)
        return piramide[i][j];
    else{
        a = Max(piramide,i+1,j,Nlinhas);//esquerda
        b = Max(piramide,i+1,j+1,Nlinhas);//direita
        if(a >= b)
            return piramide[i][j] + a;
        else
            return piramide[i][j] + b;
    }
}

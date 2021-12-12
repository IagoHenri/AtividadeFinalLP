

/******************************************************************************
/ PROBLEMA 2: Desenvolver um programa que simule um carrinho de supermercado. *
/ A equipe usará como base duas estruturas: a produto e a carrinho.           *
/                                                                             *
/ Autores:  Iago Henrique de Souza Barbosa                                    *
/           Isabelle Santos Couto                                             *
/           Maysa Fernanda Araújo                                             *
/ Data:     10/12/2021                                                        *
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Funções
void produtos_cadastrados();
void comprar();
void exibir_carrinho();
void finalizar();

//Structs
struct Produto{
    int codigo;
    char descricao[60];
    float precoUnit;
}Lista[100];

struct Carrinho{
    struct Produto produto;
    int numItem, codigoProd, qtd;
    float precoTotal;
}Carrinho[100];

    int qtdCarrinho = 0;

int main(){
    produtos_cadastrados();
    int opc;

    printf("\tSUPERMERCADO MAISIA\n\n");
    printf("1.. Comprar\n");
    printf("2.. Ver carrinho\n");
    printf("3.. Finalizar compras\n");
    printf("9.. Sair\n\n");
    printf("Digite sua opcao: ");
    scanf("%d", &opc);

    switch(opc){
    case 1:
        system("cls");
        comprar();
        break;

    case 2:
        system("cls");
        exibir_carrinho();
        break;

    case 3:
        system("cls");
        finalizar();
        break;

    case 9:
        system("cls");
        printf("\n\n\tObrigado. Volte sempre!\n\n");
        break;

    default:
        system("cls");
        printf("\n\n\tOpcao invalida!\n");
        system("pause");
        system("cls");
        main();
    }

    return 0;
}

//Função com os produtos cadastrados no sistema
void produtos_cadastrados(){
    int i = 0;

    Lista[i].codigo = 1;
    strcpy(Lista[i].descricao, "Arroz 5 Kg");
    Lista[i].precoUnit = 18.95;
    i++;

    Lista[i].codigo = 2;
    strcpy(Lista[i].descricao, "Feijao 1 Kg");
    Lista[i].precoUnit = 6.49;
    i++;

    Lista[i].codigo = 3;
    strcpy(Lista[i].descricao, "Coca-Cola 2 L");
    Lista[i].precoUnit = 7.95;
    i++;

    Lista[i].codigo = 4;
    strcpy(Lista[i].descricao, "Coca-Cola Lata");
    Lista[i].precoUnit = 2.47;
    i++;

    Lista[i].codigo = 5;
    strcpy(Lista[i].descricao, "Macarrao");
    Lista[i].precoUnit = 9.85;
    i++;

    Lista[i].codigo = 6;
    strcpy(Lista[i].descricao, "Tampico 450ml");
    Lista[i].precoUnit = 4.49;
    i++;

    Lista[i].codigo = 7;
    strcpy(Lista[i].descricao, "Bolacha de Sal");
    Lista[i].precoUnit = 6.99;
    i++;

    Lista[i].codigo = 8;
    strcpy(Lista[i].descricao, "Bolacha Choc");
    Lista[i].precoUnit = 7.89;
    i++;

    Lista[i].codigo = 9;
    strcpy(Lista[i].descricao, "Doritos Wasabi");
    Lista[i].precoUnit = 5.29;
    i++;

    Lista[i].codigo = 10;
    strcpy(Lista[i].descricao, "Baconzitos");
    Lista[i].precoUnit = 6.59;
    i++;

    Lista[i].codigo = 11;
    strcpy(Lista[i].descricao, "Iogurte Morango");
    Lista[i].precoUnit = 8.99;
    i++;

    Lista[i].codigo = 12;
    strcpy(Lista[i].descricao, "Sazon Frango");
    Lista[i].precoUnit = 3.89;
    i++;

    Lista[i].codigo = 13;
    strcpy(Lista[i].descricao, "Queijo Prato");
    Lista[i].precoUnit = 7.79;
    i++;

    Lista[i].codigo = 14;
    strcpy(Lista[i].descricao, "Mortadela");
    Lista[i].precoUnit = 6.59;
    i++;

    Lista[i].codigo = 15;
    strcpy(Lista[i].descricao, "Fanta Uva 2L");
    Lista[i].precoUnit = 6.79;
    i++;

    Lista[i].codigo = 16;
    strcpy(Lista[i].descricao, "Fanta Lar. 1L");
    Lista[i].precoUnit = 5.99;
    i++;

    Lista[i].codigo = 17;
    strcpy(Lista[i].descricao, "Pepsi 3L");
    Lista[i].precoUnit = 8.99;
    i++;

    Lista[i].codigo = 18;
    strcpy(Lista[i].descricao, "Detergente");
    Lista[i].precoUnit = 3.89;
    i++;

    Lista[i].codigo = 19;
    strcpy(Lista[i].descricao, "Achocolatado");
    Lista[i].precoUnit = 5.29;
    i++;

    Lista[i].codigo = 20;
    strcpy(Lista[i].descricao, "Cereal Nescau");
    Lista[i].precoUnit = 9.89;
    i++;

    Lista[i].codigo = 21;
    strcpy(Lista[i].descricao, "Sabao em Po");
    Lista[i].precoUnit = 17.80;
    i++;

    Lista[i].codigo = 22;
    strcpy(Lista[i].descricao, "Miojo Frango");
    Lista[i].precoUnit = 2.38;
}

//Função que adiciona um produto ao carrinho
void comprar(){
    int codigoProduto;

    printf("Codigo\tProduto\t\tPreco\n");
    for(int i = 0; i < 22; i++){
        printf("%d\t", Lista[i].codigo);
        printf("%s\t", Lista[i].descricao);
        printf("%.2f\n", Lista[i].precoUnit);
    }

    printf("\nEscolha um produto (digite seu codigo): ");
    scanf("%d", &codigoProduto);

    Carrinho[qtdCarrinho].numItem = qtdCarrinho + 1;

    int tem = 0;

    for(int i = 0; i < 22; i++){
        if (Lista[i].codigo == codigoProduto){
           Carrinho[qtdCarrinho].produto = Lista[i];
        tem = 1;
        }
    }

    if(tem == 1){
        printf("Digite a quantidade desejada: ");
        scanf("%d", &Carrinho[qtdCarrinho].qtd);
        Carrinho[qtdCarrinho].precoTotal = Carrinho[qtdCarrinho].produto.precoUnit * Carrinho[qtdCarrinho].qtd;

        qtdCarrinho++;
    }
    else{
        printf("\n\tO produto nao foi encontrado.\n\n");
    }

    printf("\n");
    system("pause");
    system("cls");
    main();
}

//Função que exibe os produtos já adicionados no carrinho
void exibir_carrinho(){
    if(qtdCarrinho > 0){
        float totalCarrinho = 0;

        printf("Num\tCodigo\tProduto\t\tPreco\tQtd.\tPreco Total\n");

        for(int i = 0; i < qtdCarrinho; i++){
            printf("%d\t", Carrinho[i].numItem);
            printf("%d\t", Carrinho[i].produto.codigo);
            printf("%s\t", Carrinho[i].produto.descricao);
            printf("%.2f\t", Carrinho[i].produto.precoUnit);
            printf("%d\t", Carrinho[i].qtd);
            printf("%.2f\n", Carrinho[i].precoTotal);

            totalCarrinho = totalCarrinho + Carrinho[i].precoTotal;
        }

        printf("\n\tTotal: %.2f", totalCarrinho);
    }
    else{
        printf("\n\n\tNao tem nada aqui :(");
    }

    printf("\n\n");
    system("pause");
    system("cls");
    main();
}

//Função que finaliza a compra e que mostra os produtos e o total a pagar
void finalizar(){
    float totalCarrinho = 0;

    printf("Num\tCodigo\tProduto\t\tPreco\tQtd.\tPreco Total\n");

    for(int i = 0; i < qtdCarrinho; i++){
        printf("%d\t", Carrinho[i].numItem);
        printf("%d\t", Carrinho[i].produto.codigo);
        printf("%s\t", Carrinho[i].produto.descricao);
        printf("%.2f\t", Carrinho[i].produto.precoUnit);
        printf("%d\t", Carrinho[i].qtd);
        printf("%.2f\n", Carrinho[i].precoTotal);

        totalCarrinho = totalCarrinho + Carrinho[i].precoTotal;
    }

    printf("\n\tTotal: %.2f", totalCarrinho);
    printf("\n\n\tObrigado e volte sempre!\n\n");
}

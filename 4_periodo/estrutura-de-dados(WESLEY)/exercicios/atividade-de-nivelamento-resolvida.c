#include <stdio.h>

//criado o tipo de dado produto
typedef struct produto
{
    int codigo;
    char nome [100];
    char marca[100];
    int garantia;
    float preco;
    int quantidade;
} product;

//criado o tipo de dado Loja
typedef struct loja{
    int totalEstoque;
    float totalVendas;
    product *ptrProduto;
} store;

//função responsável por armazenar os produtos
 void adicionarProdutos(product produtos[], int *qtdcadastradas ){
   

   if(*qtdcadastradas==0){
    printf("nenhum produto foi cadastrado até o momento");
   }

   if(*qtdcadastradas<=100){
     (*qtdcadastradas)++;      
     printf("Informe o codigo do produto");
             scanf("%d", &produtos[*qtdcadastradas].codigo);
            do{ 
                for(int i=1;i<qtdcadastradas; i++){
                    if(produtos[*qtdcadastradas].codigo == produtos[*i].codigo){
                        printf("já existe um mesmo código no sistema, digite outro");
                    } while(produto.[*qtdcadastradas].codigo == produto[*i].codigo);
                }
                { 
               printf("Informe o nome do produto");
               scanf("%s", &produtos[*qtdcadastradas].nome);
                printf("Informe a marca do produto");
                scanf("%s", &produtos[*qtdcadastradas].marca);
                printf("Informe o tempo de garantia do produto em meses");
                scanf("%d", &produtos[*qtdcadastradas].garantia);
                printf("Informe o preço do produto");
                scanf("%f", produtos[*qtdcadastradas].preco);
                printf("Informe a quantidade disponivel do produto em estoque");
                scanf("%s", produtos[*qtdcadastradas].quantidade);
                 

    } else {
        printf("limite excedido de cadastro de produtos");
    }

 }



int main(){
  //vetor de produtos com capacidade máxima de armazenamento de 100 produtos    
  product Produtos[100];
  //varíavel responsável por controlar a quantidade cadastradas
  int controledecadastros = 0;
  int opcao;

  do{
    printf("---------------------------");
    printf("sistema de gerenciamento da loja");
    printf("----------------------------");

    printf("1 - adicionar produto");
     printf("2 - listar produtos");
      printf("3 - buscar produtos pelo codigo");
        printf("4 - vender produto");
        printf("5- para sair");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
            adicionarProdutos(Produtos,&controledecadastros);
        }
  } while(opcao!=5);



}
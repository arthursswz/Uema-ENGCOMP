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
}

//função responsável por armazenar os produtos
 void adicionarProdutos(produto produtos[], int *qtdcadastradas ){
   int controledecadastros = 0

   if(controledecadastros <100){}
    do{
        
    controledecadastros++
     printf("Informe o codigo do produto");
             scanf("%s", &produtos.codigo[qtdcadastradas + controledecadastros]);
               printf("Informe o nome do produto");
               scanf("%s", &produtos.nome[qtdcadastradas + controledecadastros]);
                printf("Informe a marca do produto");
                scanf("%s", &produtos.marca[qtdcadastradas + controledecadastros]);
                printf("Informe o tempo de garantia do produto em meses");
                scanf("%s", &produtos.garantia[qtdcadastradas + controledecadastros]);
                printf("Informe o preço do produto");
                scanf("%s", &produtos.preco[qtdcadastradas + controledecadastros]);
                printf("Informe a quantidade disponivel do produto em estoque");
                scanf("%s", &produtos.nome[qtdcadastradas + controledecadastros])

    }while(controledecadastros<=100) 

 }



main(){
  //vetor de produtos com capacidade máxima de armazenamento de 100 produtos    
  product Produtos[100];
  //varíavel responsável por controlar a quantidade cadastradas
  int *qtdcadastradas, controledecadastros = 0;

  qtdcadastradas = Produtos;



}
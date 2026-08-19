1  #include <stdio.h>
  2 
  3  #define MAX_PRODUTOS 100
  4 
  5  typedef struct Produto {
  6      int codigo;
  7      char nome[100];
  8      char marca[100];
  9      int garantia;
 10      float preco;
 11      int quantidade;
 12  } Produto;
 13 
 14  typedef struct Loja {
 15      int totalEstoque;
 16      float totalVendas;
 17      Produto *ptrProduto;
 18  } Loja;
 19 
 20  int buscarIndicePorCodigo(Loja *loja, int totalCadastrados, int codigo) {
 21      for (int i = 0; i < totalCadastrados; i++) {
 22          if (loja->ptrProduto[i].codigo == codigo) {
 23              return i;
 24          }
 25      }
 26      return -1;
 27  }
 28 
 29  void adicionarProduto(Loja *loja, int *totalCadastrados) {
 30      if (*totalCadastrados >= MAX_PRODUTOS) {
 31          printf("Nao ha mais espaco para cadastrar produtos.\n");
 32          return;
 33      }
 34 
 35      int codigo;
 36      printf("\nCodigo do produto: ");
 37      scanf("%d", &codigo);
 38 
 39      if (buscarIndicePorCodigo(loja, *totalCadastrados, codigo) != -1) {
 40          printf("Esse codigo ja esta cadastrado.\n");
 41          return;
 42      }
 43 
 44      int posicao = *totalCadastrados;
 45      loja->ptrProduto[posicao].codigo = codigo;
 46 
 47      printf("Nome do produto: ");
 48      scanf(" %99[^\n]", loja->ptrProduto[posicao].nome);
 49 
 50      printf("Marca: ");
 51      scanf(" %99[^\n]", loja->ptrProduto[posicao].marca);
 52 
 53      printf("Garantia em meses: ");
 54      scanf("%d", &loja->ptrProduto[posicao].garantia);
 55 
 56      printf("Preco: R$ ");
 57      scanf("%f", &loja->ptrProduto[posicao].preco);
 58 
 59      printf("Quantidade em estoque: ");
Estrutura de Dados Basica | Nivelamento em C
Guia de estudo - vetor de structs, ponteiros, funcoes e estoque
 60      scanf("%d", &loja->ptrProduto[posicao].quantidade);
 61 
 62      loja->totalEstoque += loja->ptrProduto[posicao].quantidade;
 63      (*totalCadastrados)++;
 64 
 65      printf("Produto cadastrado com sucesso.\n");
 66  }
 67 
 68  void listarProdutos(Loja *loja, int totalCadastrados) {
 69      if (totalCadastrados == 0) {
 70          printf("\nNenhum produto foi cadastrado.\n");
 71          return;
 72      }
 73 
 74      printf("\n========== PRODUTOS CADASTRADOS ==========\n");
 75 
 76      for (int i = 0; i < totalCadastrados; i++) {
 77          printf("\nProduto %d\n", i + 1);
 78          printf("Codigo: %d\n", loja->ptrProduto[i].codigo);
 79          printf("Nome: %s\n", loja->ptrProduto[i].nome);
 80          printf("Marca: %s\n", loja->ptrProduto[i].marca);
 81          printf("Garantia: %d meses\n", loja->ptrProduto[i].garantia);
 82          printf("Preco: R$ %.2f\n", loja->ptrProduto[i].preco);
 83          printf("Quantidade em estoque: %d\n", loja->ptrProduto[i].quantidade);
 84      }
 85  }
 86 
 87  void buscarProduto(Loja *loja, int totalCadastrados) {
 88      int codigo;
 89      printf("\nDigite o codigo do produto: ");
 90      scanf("%d", &codigo);
 91 
 92      int indice = buscarIndicePorCodigo(loja, totalCadastrados, codigo);
 93 
 94      if (indice == -1) {
 95          printf("Produto nao encontrado.\n");
 96          return;
 97      }
 98 
 99      printf("\nProduto encontrado:\n");
100      printf("Codigo: %d\n", loja->ptrProduto[indice].codigo);
101      printf("Nome: %s\n", loja->ptrProduto[indice].nome);
102      printf("Marca: %s\n", loja->ptrProduto[indice].marca);
103      printf("Garantia: %d meses\n", loja->ptrProduto[indice].garantia);
104      printf("Preco: R$ %.2f\n", loja->ptrProduto[indice].preco);
105      printf("Quantidade em estoque: %d\n", loja->ptrProduto[indice].quantidade);
106  }
107 
108  void venderProduto(Loja *loja, int totalCadastrados) {
109      int codigo;
110      printf("\nCodigo do produto que sera vendido: ");
111      scanf("%d", &codigo);
112 
113      int indice = buscarIndicePorCodigo(loja, totalCadastrados, codigo);
114 
115      if (indice == -1) {
116          printf("Produto nao encontrado.\n");
117          return;
118      }
119 
120      printf("\nProduto: %s\n", loja->ptrProduto[indice].nome);
121      printf("Preco unitario: R$ %.2f\n", loja->ptrProduto[indice].preco);
122      printf("Estoque atual: %d\n", loja->ptrProduto[indice].quantidade);
123 
124      int quantidadeVenda;
125      printf("Quantidade que sera vendida: ");
126      scanf("%d", &quantidadeVenda);
127 
128      if (quantidadeVenda <= 0) {
129          printf("A quantidade precisa ser maior que zero.\n");
130          return;
131      }
132 
133      if (quantidadeVenda > loja->ptrProduto[indice].quantidade) {
134          printf("Quantidade indisponivel em estoque.\n");
135          return;
136      }
137 
138      float valorVenda = loja->ptrProduto[indice].preco * quantidadeVenda;
139 
140      loja->ptrProduto[indice].quantidade -= quantidadeVenda;
141      loja->totalVendas += valorVenda;
Estrutura de Dados Basica | Nivelamento em C
Guia de estudo - vetor de structs, ponteiros, funcoes e estoque
142      loja->totalEstoque -= quantidadeVenda;
143 
144      printf("Venda realizada com sucesso.\n");
145      printf("Valor da venda: R$ %.2f\n", valorVenda);
146  }
147 
148  void gerarRelatorio(Loja *loja, int totalCadastrados) {
149      if (totalCadastrados == 0) {
150          printf("\nNao ha produtos cadastrados para gerar o relatorio.\n");
151          return;
152      }
153 
154      float valorEstoque = 0.0f;
155      int maiorPreco = 0;
156      int menorPreco = 0;
157      int maiorQuantidade = 0;
158      int menorQuantidade = 0;
159 
160      for (int i = 0; i < totalCadastrados; i++) {
161          valorEstoque += loja->ptrProduto[i].preco * loja->ptrProduto[i].quantidade;
162 
163          if (loja->ptrProduto[i].preco > loja->ptrProduto[maiorPreco].preco) {
164              maiorPreco = i;
165          }
166 
167          if (loja->ptrProduto[i].preco < loja->ptrProduto[menorPreco].preco) {
168              menorPreco = i;
169          }
170 
171          if (loja->ptrProduto[i].quantidade > loja->ptrProduto[maiorQuantidade].quantidade) {
172              maiorQuantidade = i;
173          }
174 
175          if (loja->ptrProduto[i].quantidade < loja->ptrProduto[menorQuantidade].quantidade) {
176              menorQuantidade = i;
177          }
178      }
179 
180      printf("\n=============== RELATORIO ===============\n");
181      printf("Produtos cadastrados: %d\n", totalCadastrados);
182      printf("Total de itens em estoque: %d\n", loja->totalEstoque);
183      printf("Valor estimado do estoque: R$ %.2f\n", valorEstoque);
184      printf("Total de vendas realizadas: R$ %.2f\n", loja->totalVendas);
185      printf("Produto com maior preco: %s - R$ %.2f\n",
186             loja->ptrProduto[maiorPreco].nome, loja->ptrProduto[maiorPreco].preco);
187      printf("Produto com menor preco: %s - R$ %.2f\n",
188             loja->ptrProduto[menorPreco].nome, loja->ptrProduto[menorPreco].preco);
189      printf("Produto com maior estoque: %s - %d unidade(s)\n",
190             loja->ptrProduto[maiorQuantidade].nome,
191             loja->ptrProduto[maiorQuantidade].quantidade);
192      printf("Produto com menor estoque: %s - %d unidade(s)\n",
193             loja->ptrProduto[menorQuantidade].nome,
194             loja->ptrProduto[menorQuantidade].quantidade);
195  }
196 
197  int main(void) {
198      Produto produtos[MAX_PRODUTOS];
199      Loja loja;
200      int totalCadastrados = 0;
201      int opcao;
202 
203      loja.totalEstoque = 0;
204      loja.totalVendas = 0.0f;
205      loja.ptrProduto = produtos;
206 
207      do {
208          printf("\n========================================\n");
209          printf(" SISTEMA DE GERENCIAMENTO DA LOJA\n");
210          printf("========================================\n");
211          printf("1 - Adicionar Produto\n");
212          printf("2 - Listar Produtos\n");
213          printf("3 - Buscar Produto pelo Codigo\n");
214          printf("4 - Vender Produto\n");
215          printf("5 - Sair\n");
216          printf("6 - Gerar Relatorio (desafio adicional)\n");
217          printf("Escolha uma opcao: ");
218          scanf("%d", &opcao);
219 
220          switch (opcao) {
221              case 1:
222                  adicionarProduto(&loja, &totalCadastrados);
223                  break;
Estrutura de Dados Basica | Nivelamento em C
Guia de estudo - vetor de structs, ponteiros, funcoes e estoque
224              case 2:
225                  listarProdutos(&loja, totalCadastrados);
226                  break;
227              case 3:
228                  buscarProduto(&loja, totalCadastrados);
229                  break;
230              case 4:
231                  venderProduto(&loja, totalCadastrados);
232                  break;
233              case 5:
234                  printf("Encerrando o programa.\n");
235                  break;
236              case 6:
237                  gerarRelatorio(&loja, totalCadastrados);
238                  break;
239              default:
240                  printf("Opcao invalida.\n");
241          }
242      } while (opcao != 5);
243 
244     return 0;
}